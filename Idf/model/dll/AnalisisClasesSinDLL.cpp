// CAnalisisClasesSinDLL.cpp: implementation of the CAnalisisClasesSinDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "AnalisisClasesSinDLL.h"

#include "..\DiagBase.h"
#include "..\Conect.h"
#include "InfoClases.h"
#include "BloqueDLL.h"

#include "..\..\view\ConectVistas.h"
#include "..\..\view\dll\BloqueDLLVistas.h"
          

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAnalisisClasesSinDLL::CAnalisisClasesSinDLL(CDiagBase* pdiag)
	: CAnalisisClasesDLL(pdiag)
{
}

CAnalisisClasesSinDLL::~CAnalisisClasesSinDLL()
{

}

void CAnalisisClasesSinDLL::Construir()
{
	// Es necesario tener hecha la lista de clases de comunicación entre bloque
	// antes de formar la lista de bloques

	// Conectores funcionales
	EnlazarConectores(false);

	// Conectores de retroanotación
	EnlazarConectores(true);

	// No se generarán bloques mixtos (func/retro).

	// Funcionales
	EnlazarBloques(m_listaBloquesFunc,false);

	// Retroanotacion
	EnlazarBloques(m_listaBloquesRetro,true);
}

void CAnalisisClasesSinDLL::EnlazarConectores(BOOL retro)
{
	static const char* VerSerial = "1";
	static const char* NombreClaseCom = "CCom";

	ListaConectores* plista;
	if (!retro) plista = &p_diag->m_listaConect;
	else plista = &p_diag->m_listaConectRetro;

	// Es necesario tener hecha la lista de clases de comunicación entre bloque
	// antes de formar la lista de bloques

	for(POSITION pos = plista->GetStartPosition() ; pos != NULL ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con); 
		CString claseCom = con->m_claseDatosComunic;
		if (claseCom == "") 
		{	
			CString s = "No tiene clase de comunicación en DLL definida";
			con->getVistas()->Mensaje(s);
			continue;
		}

		CInfoCom* pdatos = NULL;
		if (!m_listaCom.Lookup(claseCom,(void*&)pdatos))
		{
			// Añadimos la nueva clase a la lista
			pdatos = new CInfoCom(con->m_claseDatosComunic,NombreClaseCom,VerSerial);
			m_listaCom.SetAt(claseCom, pdatos);
		}
	}
}

void CAnalisisClasesSinDLL::EnlazarBloques(CMapStringToPtr& lista,BOOL retro)
{
	static const char* VerSerial = "1";
	
	CString NombreClaseBase;
	ListaBloques* plista;
	int tipo;

	if (!retro) 
	{
		NombreClaseBase = "CBloqueFunc";
		plista = &p_diag->m_listaBloq;
		tipo = 1;
	}
	else
	{
		NombreClaseBase = "CBloqueRetro";
		plista = &p_diag->m_listaBloqRetro;
		tipo = 2;
	}


	for(POSITION pos = plista->GetStartPosition() ; pos != NULL ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq); 		
		
		if (!blq->EsBloqueUnidad()) continue;

		CBloqueUnidad* pblqUnidad = (CBloqueUnidad*) blq;
		if (!pblqUnidad->EsBloqueDLL()) continue;

		CBloqueDLL* blqdll = (CBloqueDLL*)pblqUnidad;
		CString clave = blqdll->m_claseDatosBloque;
		if (clave == "") 
		{	
			CString s = "No tiene clase en DLL definida";
			blqdll->getVistas()->Mensaje(s);			
			
			continue;
		}

		CInfoBloque* pdatos = NULL;
		if (!lista.Lookup(clave,(void*&)pdatos))
		{
			// Añadimos la nueva clase a la lista
			pdatos = new CInfoBloque(blqdll->m_claseDatosBloque,NombreClaseBase,VerSerial,tipo);
			lista.SetAt(clave, pdatos);
		}
		// Añadimos las clases de entrada y salida nuevas que maneje este bloque
		// a partir de los conectores asociados al mismo en ES
		
		// Entrada Funcionales
		EnlazaListaComES(pdatos,blqdll,0 ,false);
		// Entrada Retroanotación
		EnlazaListaComES(pdatos,blqdll,0 ,true);
		// Salida Funcionales
		EnlazaListaComES(pdatos,blqdll,1 ,false);
		// Salida Retroanotación
		EnlazaListaComES(pdatos,blqdll,1 ,true);
	}
}


void CAnalisisClasesSinDLL::EnlazaListaComES(CInfoBloque* pdatos,CBloqueDLL* blqdll,int tipo,BOOL Retroanotacion)
{
	if (tipo == 0) // Entrada
	{
		// Conectores de Entrada al bloque
		for( POSITION poscon = blqdll->getPrimerConectEntradaPos(Retroanotacion) ; poscon != NULL ; )
		{
			CConect* con = blqdll->getSigConectEntrada(poscon,Retroanotacion); 		
			EnlazaComES(pdatos->m_listaComEntrada,blqdll->m_claseDatosBloque,con->m_claseDatosComunic,tipo,Retroanotacion);
		}
	}
	else
	{
		// Conectores de Salida del bloque
		for( POSITION poscon = blqdll->getPrimerConectSalidaPos(Retroanotacion) ; poscon != NULL ; )
		{
			CConect* con = blqdll->getSigConectSalida(poscon,Retroanotacion); 		
			EnlazaComES(pdatos->m_listaComSalida,blqdll->m_claseDatosBloque,con->m_claseDatosComunic,tipo,Retroanotacion);
		}
	}

}

void CAnalisisClasesSinDLL::EnlazaComES(CMapStringToOb& lista,const CString& claseBloque,const CString& claseCom,int tipo,BOOL Retroanotacion)
{
	if (claseCom == "")  return;
	CString clave = claseCom;
	CInfoComES* pdatos = NULL;
	if (!lista.Lookup(clave,(CObject*&)pdatos))
	{
		// Añadimos la nueva clase a la lista
		pdatos = new CInfoComES(claseCom,claseBloque,tipo);
		lista.SetAt(clave, pdatos);
	}
}

