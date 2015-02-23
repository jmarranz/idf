// ConectInicioDLLExe.cpp: implementation of the CConectInicioDLLExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\..\idf.h"
#include "ConectInicioDLLExe.h"

#include "..\ConectInicioDLL.h"
#include "..\ConectFinDLL.h"

#include "ConectFinDLLExe.h"

#include "ComunicacionDLL.h"
#include "BloqueDLLExe.h"
#include "..\BloqueDLL.h"

#include "..\..\DiagBase.h"
#include "..\..\ConectFin.h"
#include "..\..\ConectInicio.h"
#include "..\..\Conect.h"
#include "..\..\Bloque.h"

#include "..\..\exe\ConectFinExe.h"

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

CConectInicioDLLExe::CConectInicioDLLExe()
{
}

CConectInicioDLLExe::~CConectInicioDLLExe()
{

}

void CConectInicioDLLExe::Construir(CConectExtremo* ext)
{
	CConectInicioExe::Construir(ext);

	ConexyTestBloque();
}

void CConectInicioDLLExe::ConexyTestBloque()
{
	// Hacemos las llamadas a getBloqueDLL() porque los bloques
	// inicial y final pueden ser bloques diagrama.
	// A través de ellas obtenemos los verdaderos CBloqueDLLExe con los
	// que enlazamos

	CConect* pcon = getInicio()->getConect();
	CBloqueDLL* pblqDLL = getInicio()->getBloqueDLL();

	CDiagBase* pdiag = pcon->getDiag();

	m_hInsDLLBloque = pblqDLL->getExe()->getHinstDLL();

	CString dllBloque = pblqDLL->getDLLBloque();


	BOOL OK = false;

	while (!OK)
	{
		CString STemp;
		BOOL ( *pTestClaseCom)();

		// Conexiones con el objeto en el inicio del conector
	
		STemp = "Com_CrearObjCom" + pcon->m_claseDatosComunic;  
		pCrearObjComSalida = (void* ( *)(CConect* pCon)) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pCrearObjComSalida == NULL) 
		{
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque); 
			throw new ConectorException(pcon,msg);
		}
		
		// Funcion para destruir objetos de comunicación. no depende del tipo de objeto
		pDestObjDatosComSalida = (void ( *)( void  *pComSalida )) GetProcAddress(m_hInsDLLBloque ,"Com_DestObjDatosCom" );
		if (pDestObjDatosComSalida == NULL)
    	{
			// Este error no depende de macros, es debido a que no es un DLL de componentes de diagrama
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque); 
			throw new ConectorException(pcon,msg);
		}

		// Test de si existe el objeto de salida y si es válido en el DLL del bloque origen
		STemp = "Com_TestObjCom" + pcon->m_claseDatosComunic;
		pTestClaseCom = (BOOL ( *)()) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pTestClaseCom == NULL)
		{
			CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
			continue;
		}
		else if (!(*pTestClaseCom)()) // Siempre es true pero por si acaso cambia la implementación
		{
			CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
			continue;
    	}

		// Test de si admite el bloque inicio el objeto de salida especificado en el LDD del conector.
		CString tipo= "salida";

		BOOL ( *pTestClaseSalida)(void * pBloqueEnDLL);

		STemp = "TestSalida" + pblqDLL->m_claseDatosBloque + pcon->m_claseDatosComunic;
		pTestClaseSalida = (BOOL ( *)(void * pBloqueEnDLL)) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pTestClaseSalida == NULL)
		{
			CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
			continue;
		}
		else
		{
			BOOL res = (*pTestClaseSalida)(pblqDLL->getExe()->p_bloqueEnDLL);
			if (!res)
			{
				CConectExtremoDLLExe::errorTestConexion(pcon,dllBloque);
				continue;
    		}
		}

		STemp = "DevolverDatos" + pblqDLL->m_claseDatosBloque + pcon->m_claseDatosComunic;  
		pDevolverDatosClaseSalida = (void ( *)(void * pBloqueEnDLL,void* pS)) GetProcAddress(m_hInsDLLBloque, STemp);
    	if (pDevolverDatosClaseSalida == NULL)  
		{
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque); // MUY RARO
			throw new ConectorException(pcon,msg);
		}		
		
	
		// Por si los bloques comunicados están en DLLs diferentes

		// Necesario objeto receptor remoto para comunicación entre bloques
		// en diferentes DLLs

		// Funcion para serializar guardando objetos de comunicación. no depende del tipo de objeto
		pSerializarGuardadoObjComSalida = (BYTE*  ( *)(void* pComSalida, DWORD& len)) GetProcAddress(m_hInsDLLBloque ,"Com_SerializarGuardadoObjCom" );
		if (pSerializarGuardadoObjComSalida == NULL)
    	{
			// Este error no depende de macros, es debido a que no es un DLL de componentes de diagrama
			CString msg = CDLLDiagrama::MensajeErrorNoDLLDiag(dllBloque); 
			throw new ConectorException(pcon,msg);
		}
    	
    	OK = true;
	}

}

CComunicacion* CConectInicioDLLExe::DevolverDatos()
{
	CConect* pcon = getInicio()->getConect();
	CBloqueDLL* pblqDLL = getInicio()->getBloqueDLL();


	CString stemp = "Generando datos de comunicación por el conector ";
	stemp += "[" + pcon->getId() + "] de etiqueta \"" + pcon->getEtiqueta() + "\"";
	pblqDLL->getExe()->Consola(stemp);  // El CBloqueDLLExe verdadero que de verdad emite

	void * pS = (*pCrearObjComSalida)(pcon);
	if (pS == NULL)   
	{
		pcon->setEstado(FALLIDO);
		CString stemp = "¡No se ha podido generar datos de salida!";
		pblqDLL->getExe()->Consola(stemp); 		
		return NULL;
	}

	(*pDevolverDatosClaseSalida)(pblqDLL->getExe()->p_bloqueEnDLL,pS);    // Llama a la función adecuada de generación del tipo de datos de salida del bloque anterior. 

	CComunicacionDLL* pComDLL = new CComunicacionDLL(pS,pblqDLL->getTiempo());

	CConectFinDLL* conFin = (CConectFinDLL*)pcon->getFin();

	if (m_hInsDLLBloque != conFin->getBloqueDLL()->getExe()->getHinstDLL())
	{
		void* pComDLLIni = pComDLL->getObjComDLL();

		pComDLL->m_buff = (*pSerializarGuardadoObjComSalida)(pComDLLIni,pComDLL->m_len);

		(*pDestObjDatosComSalida)(pComDLLIni); 	
		pComDLL->setObjComDLL(NULL);
	}
	
	return pComDLL;
}

