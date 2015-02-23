// CAnalisisClasesDLL.cpp: implementation of the CAnalisisClasesDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "AnalisisClasesDLL.h"

#include "InfoClases.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAnalisisClasesDLL::CAnalisisClasesDLL(CDiagBase* pdiag)
{
	p_diag = pdiag;
}

CAnalisisClasesDLL::~CAnalisisClasesDLL()
{
	DestruirListaBloques(m_listaBloquesAmbos);
	DestruirListaBloques(m_listaBloquesFunc);
	DestruirListaBloques(m_listaBloquesRetro);

	DestruirListaCom(m_listaCom);

	m_listaBloquesAmbos.RemoveAll();
	m_listaBloquesFunc.RemoveAll();
	m_listaBloquesRetro.RemoveAll();
	m_listaCom.RemoveAll();
}

BOOL CAnalisisClasesDLL::EsClaseComPredefinida(const CString& claseCom)
{
	if ((claseCom == "NULO") || (claseCom == "CComSerial"))
		return true;
	return false;
}

BOOL CAnalisisClasesDLL::EsClaseComNULO(const CString& claseCom)
{
	if (claseCom == "NULO") return true;
	return false;
}


CInfoBloque*  CAnalisisClasesDLL::BuscarBloque(const CString& claseBloque) 
{
	CInfoBloque* pdatos = NULL;

	pdatos = BuscarBloque(claseBloque, 0); // Buscar en funcionales/retroanotación
	if (pdatos != NULL) return pdatos;

	pdatos = BuscarBloque(claseBloque, 1); // Buscar en funcionales
	if (pdatos != NULL) return pdatos;

	pdatos = BuscarBloque(claseBloque, 2); // Buscar en retroanotación
	if (pdatos != NULL) return pdatos;

	return NULL;
}

CInfoBloque*  CAnalisisClasesDLL::BuscarBloque(const CString& claseBloque, int tipo) 
{
	CInfoBloque* pdatos = NULL;
	BOOL res = false;
	switch(tipo)
	{
	case 0: 
			res = m_listaBloquesAmbos.Lookup(claseBloque,(void*&)pdatos);
			break;
	case 1:
			res = m_listaBloquesFunc.Lookup(claseBloque,(void*&)pdatos);
			break;
	case 2:
			res = m_listaBloquesRetro.Lookup(claseBloque,(void*&)pdatos);
			break;
	}

	if (res) return pdatos;

	return NULL;
}

CInfoCom*  CAnalisisClasesDLL::BuscarObjCom(const CString& claseCom)
{
	CInfoCom* pdatos = NULL;
	if (m_listaCom.Lookup(claseCom,(void*&)pdatos))
	{
		return pdatos;
	}

	return NULL;
}




void CAnalisisClasesDLL::ListarBloques( CComboBox* lista, int tipo )
{
	// De la inicialización de la lista etc.
	// se encarga el llamador

	if (!EsValido()) return;

	POSITION pos = PrimerBloquePos( tipo );
	while( pos != NULL)
	{
		CInfoBloque* pdatos = SiguienteBloque(pos, tipo);
		
		lista->AddString(pdatos->m_nombreClase);
	}
}


void CAnalisisClasesDLL::ListarObjCom( CComboBox* lista )
{
	// De la inicialización de la lista etc.
	// se encarga el llamador

	if (!EsValido()) return;

	POSITION pos = PrimerComPos();
	while( pos != NULL)
	{
		CInfoCom* pdatos = SiguienteCom(pos);		

		// También se añade a la lista el objeto NULO
		lista->AddString(pdatos->m_nombreClase);
	}
}

void CAnalisisClasesDLL::DestruirListaBloques(CMapStringToPtr& lista)
{
	CString claveinutil;
	POSITION pos = lista.GetStartPosition();
	while( pos != NULL )
	{
		CInfoBloque* ptr;
		lista.GetNextAssoc(pos,claveinutil,(void*&)ptr);
		delete ptr;
	}
}

void CAnalisisClasesDLL::DestruirListaCom(CMapStringToPtr& lista)
{
	CString claveinutil;
	POSITION pos = lista.GetStartPosition();
	while( pos != NULL )
	{
		CInfoCom* ptr;
		lista.GetNextAssoc(pos,claveinutil,(void*&)ptr);
		delete ptr;
	}
}

POSITION  CAnalisisClasesDLL::PrimerBloquePos(int tipo)
{
	switch(tipo)
	{
	case 0: 
		return m_listaBloquesAmbos.GetStartPosition();
	case 1:
		return m_listaBloquesFunc.GetStartPosition();
	case 2:
		return m_listaBloquesRetro.GetStartPosition();
	}
	
	return NULL;
}

CInfoBloque*  CAnalisisClasesDLL::SiguienteBloque(POSITION& pos, int tipo)
{
	CString claveinutil;
	CInfoBloque* pdatos = NULL;
	switch(tipo)
	{
	case 0: 
		m_listaBloquesAmbos.GetNextAssoc(pos,claveinutil,(void*&)pdatos);
		break;
	case 1:
		m_listaBloquesFunc.GetNextAssoc(pos,claveinutil,(void*&)pdatos);
		break;
	case 2:
		m_listaBloquesRetro.GetNextAssoc(pos,claveinutil,(void*&)pdatos);
		break;
	}
	
	return pdatos;
}

POSITION  CAnalisisClasesDLL::PrimerComPos()
{
	return m_listaCom.GetStartPosition();
}

CInfoCom*  CAnalisisClasesDLL::SiguienteCom(POSITION& pos)
{
	CString claveinutil;
	CInfoCom* pdatos = NULL;
	m_listaCom.GetNextAssoc(pos,claveinutil,(void*&)pdatos);
	return pdatos;
}


POSITION  CAnalisisClasesDLL::PrimerComESPos(CInfoBloque* pInfo,int tipo)
{
	switch(tipo)
	{
	case 0: // Entrada
		return pInfo->m_listaComEntrada.GetStartPosition();
	case 1: // Salida
		return pInfo->m_listaComSalida.GetStartPosition();
	}
	return NULL;
}


CInfoComES*  CAnalisisClasesDLL::SiguienteComES(POSITION& pos,CInfoBloque* pInfo, int tipo)
{
	CString claveinutil;
	CInfoComES* pdatos = NULL;
	switch(tipo)
	{
	case 0: // Entrada
		pInfo->m_listaComEntrada.GetNextAssoc(pos,claveinutil,(CObject*&)pdatos);
		break;
	case 1: // Salida
		pInfo->m_listaComSalida.GetNextAssoc(pos,claveinutil,(CObject*&)pdatos);
		break;
	}	
	
	return pdatos;
}



