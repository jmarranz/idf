// GeneracionCodigoDLL.cpp: implementation of the CGeneracionCodigoDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "GeneracionCodigoDLL.h"

#include "..\DiagBase.h"

#include "AnalisisClasesDLL.h"

#include "InfoClases.h"

#include "..\..\Exception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeneracionCodigoDLL::CGeneracionCodigoDLL(CAnalisisClasesDLL* pClasesDiag)
{
	p_clasesDiag = pClasesDiag;
}

CGeneracionCodigoDLL::~CGeneracionCodigoDLL()
{

}


void CGeneracionCodigoDLL::GenerarCodigoBloqueCabecera(CInfoBloque* pdatos)
{
	CString NombreClase = pdatos->m_nombreClase;
	m_cabeceras += "class " + NombreClase + " : public " + pdatos->m_nombreClaseBase + "\r\n";  
	m_cabeceras += "{ \r\n";
	m_cabeceras += "public: \r\n";

	int tipo = pdatos->getTipo();
	switch (tipo)
	{
	case 0:
		m_cabeceras +=      "\tDECLARAR_BLOQUE(";
		m_implementacion += "\r\nIMPLEMENTAR_BLOQUE(";
		break;
	case 1:
		m_cabeceras +=      "\tDECLARAR_BLOQUE_FUNCIONAL(";
		m_implementacion += "\r\nIMPLEMENTAR_BLOQUE_FUNCIONAL(";
		break;
	case 2:
		m_cabeceras +=      "\tDECLARAR_BLOQUE_RETROANOTACION(";
		m_implementacion += "\r\nIMPLEMENTAR_BLOQUE_RETROANOTACION(";
		break;
	}
	m_cabeceras +=      NombreClase + ") \r\n";
	m_implementacion += NombreClase + "," + pdatos->m_nombreClaseBase + "," + pdatos->m_verSerial + ") \r\n";
}

void CGeneracionCodigoDLL::GenerarCodigoBloqueCuerpo(CInfoBloque* pdatos)
{
	CString NombreClase = pdatos->m_nombreClase;

	m_cabeceras += "\r\n\t// Funciones estándar a implementar\r\n";
	m_implementacion += "\r\n";

	m_cabeceras += "\tvirtual void IniciarDatos(); \r\n";
	m_implementacion += "void " + NombreClase + "::IniciarDatos() \r\n{ \r\n \r\n} \r\n";

	m_cabeceras += "\tvirtual BOOL NuevosObjDatos(); \r\n";
	m_implementacion += "BOOL " + NombreClase + "::NuevosObjDatos() \r\n{ \r\n\treturn true; \r\n} \r\n";

	m_cabeceras += "\tvirtual void DestObjDatos(); \r\n";
	m_implementacion += "void " + NombreClase + "::DestObjDatos() \r\n{ \r\n \r\n} \r\n";

	m_cabeceras += "\tvirtual void GuardarFichero(CArchive& ar); \r\n";
	m_implementacion += "void " + NombreClase + "::GuardarFichero(CArchive& ar) \r\n{ \r\n \r\n} \r\n";

	m_cabeceras += "\tvirtual void LeerFichero(CArchive& ar); \r\n";
	m_implementacion += "void " + NombreClase + "::LeerFichero(CArchive& ar) \r\n{ \r\n \r\n} \r\n";

	int tipo = pdatos->getTipo();

	if (tipo == 1)  // Es funcional
	{
	m_cabeceras += "\tvirtual CString Accion(); \r\n";
	m_implementacion += "CString " + NombreClase + "::Accion() \r\n{ \r\n\treturn \"\"; \r\n} \r\n";
	}

	m_cabeceras += "\tvirtual BOOL PropiedadesBloque(); \r\n";
	m_implementacion += "BOOL " + NombreClase + "::PropiedadesBloque() \r\n{ \r\n\treturn true; \r\n} \r\n";

	m_cabeceras += "}; \r\n\r\n";
}


void CGeneracionCodigoDLL::GenerarCodigoObjComCabecera(CInfoCom* pdatos)
{
	m_cabeceras += "\r\nclass " + pdatos->m_nombreClase + " : public " + pdatos->m_nombreClaseBase + "\r\n";  
	m_cabeceras += "{ \r\n";
	m_cabeceras += "public: \r\n";
	m_cabeceras += "\tDECLARAR_COMUNICACION(" + pdatos->m_nombreClase + ") \r\n";

	m_implementacion += "\r\nIMPLEMENTAR_COMUNICACION(";
	m_implementacion += pdatos->m_nombreClase + "," + pdatos->m_nombreClaseBase + "," + pdatos->m_verSerial + ") \r\n";


	m_cabeceras += "\tvirtual void GuardarDatos(CArchive& ar); \r\n";
	m_implementacion += "void " + pdatos->m_nombreClase + "::GuardarDatos(CArchive& ar) \r\n{ \r\n \r\n} \r\n";

	m_cabeceras += "\tvirtual void LeerDatos(CArchive& ar); \r\n";
	m_implementacion += "void " + pdatos->m_nombreClase + "::LeerDatos(CArchive& ar) \r\n{ \r\n \r\n} \r\n";
}

void CGeneracionCodigoDLL::GenerarCodigoObjComCuerpo(CInfoCom* pdatos)
{
	// Sólo es la terminación
	m_cabeceras += "}; \r\n\r\n";
}


void CGeneracionCodigoDLL::GenerarCodigoObjComES(CInfoComES* pdatos)
{
	if (CAnalisisClasesDLL::EsClaseComNULO(pdatos->m_nombreClase))
	{
		throw new Exception("La clase de comunicación " + pdatos->m_nombreClase + " es la clase nula y no necesita declararse");
	}	

	CString NombreClase = pdatos->m_nombreClase;
	CString NombreClaseBloque = pdatos->m_nombreClaseBloque;
	
	int tipo = pdatos->getTipo();
	switch(tipo)
	{
	case 0:
		m_cabeceras += "\tDECLARAR_COM_ENTRADA(";
		m_implementacion += "IMPLEMENTAR_COM_ENTRADA(";
		break;
	case 1:
		m_cabeceras += "\tDECLARAR_COM_SALIDA(";
		m_implementacion += "IMPLEMENTAR_COM_SALIDA(";				
		break;
	}

	m_cabeceras += NombreClase + ") \r\n";
	m_implementacion += NombreClase + "," + NombreClaseBloque + ") \r\n";

	switch(tipo)
	{
	case 0:
		m_cabeceras += "\tvirtual  BOOL RecibirDatosEntrada(" + NombreClase + "* pE); \r\n";
		m_implementacion += "BOOL " + NombreClaseBloque + "::RecibirDatosEntrada(" + NombreClase + "* pE) \r\n{ \r\n\t return true;\r\n} \r\n";
		break;
	case 1:
		m_cabeceras += "\tvirtual  void EnviarDatosSalida(" + NombreClase + "* pS); \r\n";
		m_implementacion += "void " + NombreClaseBloque + "::EnviarDatosSalida(" + NombreClase + "* pS) \r\n{ \r\n \r\n} \r\n";
		break;
	}
}


void CGeneracionCodigoDLL::GenerarCodigo() 
{
	// TODO: Add your control notification handler code here

	// Iterar 

	// Inicializamos las cadenas, borrando el contenido previo.

	m_cabeceras = "\r\n";
	m_implementacion = "\r\n";

	GenerarCodigoListaObjetosCom();

	m_cabeceras += "\r\n// Clases de Bloques Funcionales/Retroanotación: \r\n";
	m_implementacion += "\r\n// Clases de Bloques Funcionales/Retroanotación: \r\n";

	GenerarCodigoListaBloques( 0 );

	m_cabeceras += "\r\n// Clases de Bloques Funcionales: \r\n";  	
	m_implementacion += "\r\n// Clases de Bloques Funcionales: \r\n";  	

	GenerarCodigoListaBloques( 1 );

	m_cabeceras += "\r\n// Clases de Bloques de Retroanotación: \r\n";
	m_implementacion += "\r\n// Clases de Bloques de Retroanotación: \r\n";

	GenerarCodigoListaBloques( 2 );

}

void  CGeneracionCodigoDLL::GenerarCodigoListaBloques(int tipo) 
{
	POSITION pos = p_clasesDiag->PrimerBloquePos( tipo );
	while( pos != NULL)
	{
		CInfoBloque* pdatos = p_clasesDiag->SiguienteBloque(pos,tipo);
		GenerarCodigoBloque(pdatos);
	}
}


void  CGeneracionCodigoDLL::GenerarCodigoBloque(CInfoBloque* pdatos) 
{
	GenerarCodigoBloqueCabecera(pdatos);
	
	// Obj. Entrada
	GenerarCodigoListaObjetosComES( pdatos, 0 );

	// Obj. Salida
	GenerarCodigoListaObjetosComES( pdatos, 1 );

	GenerarCodigoBloqueCuerpo(pdatos);
}


void  CGeneracionCodigoDLL::GenerarCodigoListaObjetosCom() 
{
	m_cabeceras += "\r\n// Clases de comunicación entre bloques: \r\n";
	m_implementacion += "\r\n// Clases de comunicación entre bloques: \r\n";
	
	for(POSITION pos = p_clasesDiag->PrimerComPos(); pos != NULL; )
	{
		CInfoCom* pdatos = p_clasesDiag->SiguienteCom(pos);		

		try
		{
			GenerarCodigoObjCom(pdatos);
		}
		catch(Exception* ex)
		{
			ex; // para el evitar el warning
		}
	}
}

void  CGeneracionCodigoDLL::GenerarCodigoObjCom(CInfoCom* pdatos) 
{
	if (CAnalisisClasesDLL::EsClaseComPredefinida(pdatos->m_nombreClase))
	{
		throw new Exception("La clase de comunicación " + pdatos->m_nombreClase + " es predefinida y no necesita código");
	}

	GenerarCodigoObjComCabecera(pdatos);
			
	GenerarCodigoObjComCuerpo(pdatos);
}


void  CGeneracionCodigoDLL::GenerarCodigoListaObjetosComES(CInfoBloque* pdatos, int tipo) 
{
	CString stipo;
	if (tipo) stipo = "Salida"; 
	else stipo = "Entrada";

	m_cabeceras +=      "\r\n\t// Declaración de clases de comunicación de " + stipo + " : \r\n";
	m_implementacion += "\r\n// Implementación de clases de comunicación de " + stipo + " del bloque: " + pdatos->m_nombreClase + "\r\n";

	POSITION pos = p_clasesDiag->PrimerComESPos(pdatos, tipo );
	while( pos != NULL)
	{
		CInfoComES* pDatosCom = p_clasesDiag->SiguienteComES(pos,pdatos,tipo);
		try
		{
			GenerarCodigoObjComES(pDatosCom);	
		}
		catch(Exception* ex)
		{
			ex; // para el evitar el warning
		}
	}
}
