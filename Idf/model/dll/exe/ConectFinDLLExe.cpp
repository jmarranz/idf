// ConectFinDLLExe.cpp: implementation of the CConectFinDLLExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\..\idf.h"
#include "ConectFinDLLExe.h"

#include "..\ConectFinDLL.h"

#include "..\ConectInicioDLL.h"

#include "ComunicacionDLL.h"
#include "BloqueDLLExe.h"
#include "..\BloqueDLL.h"

#include "..\..\DiagBase.h"
#include "..\..\ConectFin.h"
#include "..\..\ConectInicio.h"
#include "..\..\Conect.h"
#include "..\..\Bloque.h"

#include "..\..\exe\ConectInicioExe.h"

#include "..\..\bdiag\BloqueDiag.h"
#include "..\..\bdiag\exe\BloqueDiagExe.h"

#include "..\..\ConectorException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectFinDLLExe::CConectFinDLLExe()
{
}

CConectFinDLLExe::~CConectFinDLLExe()
{

}

void CConectFinDLLExe::Construir(CConectExtremo* ext)
{
	CConectFinExe::Construir(ext);

	ConexyTestBloque();
}


void CConectFinDLLExe::ConexyTestBloque()
{
	CConect* pcon = getFin()->getConect();
	CBloqueDLL* pblqDLL = getFin()->getBloqueDLL();
	
	CDiagBase* pdiag = pcon->getDiag();

	m_hInsDLLBloque = pblqDLL->getExe()->getHinstDLL();

	CString dllBloque = pblqDLL->getDLLBloque();


	BOOL OK = false;

	while (!OK)
	{
		CString STemp;
		BOOL ( *pTestClaseCom)();
	
		// Conexiones con el bloque al final del conector

		STemp = "Com_CrearObjCom" + pcon->m_claseDatosComunic;  
		pCrearObjComEntrada = (void* ( *)(CConect* pCon)) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pCrearObjComEntrada == NULL) 
		{
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque); 
			throw new ConectorException(pcon,msg);
		}

		// Funcion para destruir objetos de comunicación. no depende del tipo de objeto
		pDestObjDatosComEntrada = (void ( *)( void  *pComEntrada )) GetProcAddress(m_hInsDLLBloque, "Com_DestObjDatosCom");
		if (pDestObjDatosComEntrada == NULL)
    	{
			// Este error no depende de macros, es debido a que no es un DLL de componentes de diagrama
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque);
			throw new ConectorException(pcon,msg);
		}


		// Test de si existe el objeto de entrada y si es válido en el DLL del bloque final

		STemp = "Com_TestObjCom" + pcon->m_claseDatosComunic;
		pTestClaseCom = (BOOL ( *)()) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pTestClaseCom == NULL)
		{
			CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
			continue;
		}
		else if (!(*pTestClaseCom)())  // Siempre es true pero por si cambia la implementación
		{
			CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
			continue;
    	}

		// Test de si admite el bloque fin el objeto de entrada del inicial 
		CString tipo= "entrada";

		BOOL ( *pTestClaseEntrada)(void * pBloqueEnDLL);

		STemp = "TestEntrada" + pblqDLL->m_claseDatosBloque + pcon->m_claseDatosComunic;
		pTestClaseEntrada = (BOOL ( *)(void * pBloqueEnDLL)) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pTestClaseEntrada == NULL)
		{
			CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
			continue;
		}
		else
		{
			BOOL res = (*pTestClaseEntrada)(pblqDLL->getExe()->p_bloqueEnDLL);
			if (!res)
			{
				CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
				continue;
    		}
		}

		STemp = "AceptarDatos" + pblqDLL->m_claseDatosBloque  + pcon->m_claseDatosComunic;  
		pAceptarDatosClaseEntrada = (BOOL ( *)(void * pBloqueEnDLL, void  *pE)) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pAceptarDatosClaseEntrada == NULL)  
		{
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque);  // MUY RARO 
			throw new ConectorException(pcon,msg);
		}		

		// Por si los bloques comunicados están en DLLs diferentes
		
		// Funcion para serializar guardando objetos de comunicación. no depende del tipo de objeto
		pSerializarCargaObjComEntrada = (BOOL  ( *)(BYTE* buff,DWORD len,void* pCom)) GetProcAddress(m_hInsDLLBloque ,"Com_SerializarCargaObjCom" );
		if (pSerializarCargaObjComEntrada == NULL)
    	{
			// Este error no depende de macros, es debido a que no es un DLL de componentes de diagrama
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque);  // MUY RARO 
			throw new ConectorException(pcon,msg);
		}			
    	
    	OK = true;
	}

}



BOOL CConectFinDLLExe::AceptarDatos(CComunicacion* pE)
{
	// Ha de estar el objeto local en el mismo DLL que el bloque
	// Si el objeto está en otro DLL será el remoto de otra forma NULL
	// (*con->pAceptarDatosClaseEntrada)() Llama a la función adecuada de recepción del tipo de datos de salida del bloque anterior. 	

	CComunicacionDLL* pComDLL = (CComunicacionDLL*)pE;

	CBloqueDLL* pblqDLL = getFin()->getBloqueDLL();
	CConect* pcon = getFin()->getConect();

	CConectInicioDLL* conInicio = (CConectInicioDLL*)pcon->getInicio();

	if (conInicio->getBloqueDLL()->getExe()->getHinstDLL() != m_hInsDLLBloque)
	{
		void* pComDLLFin = (*pCrearObjComEntrada)(pcon);
		if (pComDLLFin == NULL)   // MUY RARO
		{
			pcon->setEstado(FALLIDO);
			CString stemp = "¡No se ha podido generar datos de comunicación!";
			pblqDLL->getExe()->Consola(stemp); 		
			return false;
		}

		BOOL res = (*pSerializarCargaObjComEntrada)(pComDLL->m_buff,pComDLL->m_len,pComDLLFin);

		if (res == NULL)
		{
			CString s = "ERROR: En la serialización del objeto de comunicación entre DLLs, probablemente la clase de comunicaciones del bloque destino es diferente a la clase de comunicaciones del bloque origen a través del conector [" + pcon->getId() + "]";
			AfxMessageBox(s); 
			return false; // Es muy posible que caiga en otro sitio
		}
			
		pComDLL->setObjComDLL(pComDLLFin);
	}

	BOOL res = true;
	if (pblqDLL->getExe()->RegistrarDatos(pE))
	{
		void* pEDLL = pComDLL->getObjComDLL();
		res = (*pAceptarDatosClaseEntrada)(pblqDLL->getExe()->p_bloqueEnDLL,pEDLL);
	}
	else res = false;

	if (res)
	{
		pcon->setEstado(CIRCULA);

		CString stemp = "Datos aceptados a través del conector ";
		stemp += "[" + pcon->getId() + "] de etiqueta \"" + pcon->getEtiqueta() + "\"";
		pblqDLL->getExe()->Consola(stemp);
	}
	else
	{
		pcon->setEstado(FALLIDO);

		CString stemp = "Datos ¡rechazados! a través del conector ";
		stemp += "[" + pcon->getId() + "] de etiqueta \"" + pcon->getEtiqueta() + "\"";
		pblqDLL->getExe()->Consola(stemp);
	}

	(*pDestObjDatosComEntrada)(pComDLL->getObjComDLL());  
	delete pComDLL;

	return res;
}

 
