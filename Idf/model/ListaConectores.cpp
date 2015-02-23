// ListaConectores.cpp: implementation of the ListaConectores class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "ListaConectores.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Conect.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


ListaConectores::ListaConectores( int nBlockSize  ) : ListaComponentes(nBlockSize)
{

}


ListaConectores::~ListaConectores()
{

}

void ListaConectores::SetAt( LPCTSTR key, CConect* con )
{
	m_lista.SetAt(key,con);
}

BOOL ListaConectores::Lookup( LPCTSTR key, CConect*& con ) const
{
	return m_lista.Lookup(key,(CObject*&)con);
}

void ListaConectores::GetNextAssoc( POSITION& rNextPosition, CString& rKey, CConect*& con ) const
{
	m_lista.GetNextAssoc(rNextPosition,rKey,(CObject*&)con);
}


CConect* ListaConectores::BuscaPorClave(const CString& clave)
{
	CConect* con;
	if (m_lista.Lookup(clave,(CObject*&)con))
		return con;

	return NULL;
}


