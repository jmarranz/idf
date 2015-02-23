// InfoClases.cpp: implementation of the CInfoClases class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "InfoClases.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CInfoClaseComponenteDiag::CInfoClaseComponenteDiag(const char* nombreclase, const char* nombreclasebase, const char* verserial)
{
	m_nombreClase = nombreclase;
	m_nombreClaseBase = nombreclasebase;
	m_verSerial = verserial;
}

CInfoClaseComponenteDiag::~CInfoClaseComponenteDiag()
{
}

IMPLEMENT_DYNAMIC(CInfoBloque,CObject)

CInfoBloque::CInfoBloque(const char* nombreclase, const char* nombreclasebase, const char* verserial, int tipo)
	: CInfoClaseComponenteDiag(nombreclase,nombreclasebase,verserial)
{
	m_tipo = tipo; // 0 = ambos tipos, 1 = sólo funcional, 2 = sólo retroanotación
}

CInfoBloque::~CInfoBloque()
{
	DestruirListaComES(m_listaComEntrada);
	DestruirListaComES(m_listaComSalida);
}

void CInfoBloque::DestruirListaComES(CMapStringToOb& lista)
{
	CString claveinutil;
	POSITION pos = lista.GetStartPosition();
	while( pos != NULL )
	{
		CInfoComES* ptr;
		lista.GetNextAssoc(pos,claveinutil,(CObject*&)ptr);
		delete ptr;
	}

	lista.RemoveAll();
}

IMPLEMENT_DYNAMIC(CInfoCom,CObject)

CInfoCom::CInfoCom(const char* nombreclase, const char* nombreclasebase, const char* verserial)
	: CInfoClaseComponenteDiag(nombreclase,nombreclasebase,verserial)
{
}

IMPLEMENT_DYNAMIC(CInfoComES,CObject)

CInfoComES::CInfoComES(const char* nombreclase, const char* nombreclasebloque, int tipo)
{
	m_tipo = tipo; // 0 = entrada, 1 = salida
	m_nombreClase = nombreclase;
	m_nombreClaseBloque = nombreclasebloque;
}


