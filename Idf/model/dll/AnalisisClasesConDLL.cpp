// CAnalisisClasesConDLL.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "AnalisisClasesConDLL.h"

#include "..\DiagBase.h"

#include "InfoClases.h"

#include "..\..\Exception.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnalisisClasesConDLL dialog


CAnalisisClasesConDLL::CAnalisisClasesConDLL(CDiagBase* pdiag,const CString& DLLDiag)
	: CAnalisisClasesDLL(pdiag)
{
	CString nombreDLLAbs = p_diag->FormarPathAbsoluto(DLLDiag);
	m_DLLDiag = nombreDLLAbs;
}

CAnalisisClasesConDLL::~CAnalisisClasesConDLL()
{
	m_DLLDiagrama.Descargar();
}


BOOL CAnalisisClasesConDLL::EsValido() 
{
	return m_DLLDiagrama.Cargado();
}

void CAnalisisClasesConDLL::Construir()
{
	try
	{
		m_DLLDiagrama.Cargar(m_DLLDiag);
	}
	catch(Exception* ex)
	{
		m_DLLDiagrama.Descargar();
		throw ex;
	}

	// Enlazar
	HINSTANCE hIns = m_DLLDiagrama.getHandler();

	pPrimerBloquePos = (POSITION (*)(int tipo)) GetProcAddress(hIns,"PrimerBloquePos");
	pSiguienteBloque = (void (*)(POSITION& pos,int tipo, const char*& clase,const char*& claseBase,const char*& verSerial)) GetProcAddress(hIns,"SiguienteBloque");

	pPrimerComPos = (POSITION (*)()) GetProcAddress(hIns,"PrimerComPos");
	pSiguienteCom = (void (*)(POSITION& pos,const char*& clase,const char*& claseBase,const char*& verSerial)) GetProcAddress(hIns,"SiguienteCom");

	pBuscarComES = (BOOL (*)(const char* clave,int tipo,const char*& clase,const char*& claseBloque)) GetProcAddress(hIns,"BuscarComES");


	EnlazarConectores();
	EnlazarBloques(m_listaBloquesAmbos,0);
	EnlazarBloques(m_listaBloquesFunc, 1);
	EnlazarBloques(m_listaBloquesRetro,2);
}

void CAnalisisClasesConDLL::EnlazarConectores()
{
	// Es necesario tener hecha la lista de clases de comunicación entre bloque
	// antes de formar la lista de bloques

	for(POSITION pos = (*pPrimerComPos)(); pos != NULL ; )
	{
		const char* clase;
		const char* clasebase;
		const char* verserial;

		(*pSiguienteCom)(pos,clase,clasebase,verserial);

		CString clave = clase;
		CInfoCom* pdatos = new CInfoCom(clase,clasebase,verserial);
		m_listaCom.SetAt(clave, pdatos);
	}
}

void CAnalisisClasesConDLL::EnlazarBloques(CMapStringToPtr& lista,int tipo)
{
	for(POSITION pos = (*pPrimerBloquePos)(tipo) ; pos != NULL ; )
	{
		const char* clase;
		const char* clasebase;
		const char* verserial;

		(*pSiguienteBloque)(pos,tipo,clase,clasebase,verserial);

		CString clave = clase;
		CInfoBloque* pdatos = new CInfoBloque(clase,clasebase,verserial,tipo);
		lista.SetAt(clave,pdatos);

		// Añadimos las clases de entrada y salida nuevas que maneje este bloque
		// a partir de los conectores asociados al mismo en ES
		
		// Entrada
		EnlazaListaComES(pdatos,0);
		// Salida 
		EnlazaListaComES(pdatos,1);
	}
}

void CAnalisisClasesConDLL::EnlazaListaComES(CInfoBloque* pdatos,int tipo)
{
	for( POSITION poscon = PrimerComPos() ; poscon != NULL ; )
	{
		CInfoCom* pDatosCom = SiguienteCom(poscon);
		CString clave = pdatos->m_nombreClase + "_" + pDatosCom->m_nombreClase;

		const char* clase;
		const char* claseBloque;

		if ((*pBuscarComES)(clave,tipo,clase,claseBloque))
		{
			CInfoComES* pDatosComES = new CInfoComES(clase,claseBloque,tipo);
			if (tipo == 0) // Entrada
			{
				pdatos->m_listaComEntrada.SetAt(clase,pDatosComES);
			}
			else
			{
				pdatos->m_listaComSalida.SetAt(clase,pDatosComES);
			}
		}
	}
}

