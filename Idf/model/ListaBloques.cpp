// ListaBloques.cpp: implementation of the ListaBloques class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "ListaBloques.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Bloque.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



ListaBloques::ListaBloques( int nBlockSize  ) : ListaComponentes(nBlockSize)
{

}


ListaBloques::~ListaBloques()
{

}

void ListaBloques::SetAt( LPCTSTR key, CBloque* blq )
{
	m_lista.SetAt(key,blq);
}

BOOL ListaBloques::Lookup( LPCTSTR key, CBloque*& blq ) const
{
	return m_lista.Lookup(key,(CObject*&)blq);
}

void ListaBloques::GetNextAssoc( POSITION& rNextPosition, CString& rKey, CBloque*& blq ) const
{
	m_lista.GetNextAssoc(rNextPosition,rKey,(CObject*&)blq);
}


CBloque* ListaBloques::BuscaPorClave(const CString& clave)
{
	CBloque* blq;
	if (m_lista.Lookup(clave,(CObject*&)blq))
		return blq;

	return NULL;
}


