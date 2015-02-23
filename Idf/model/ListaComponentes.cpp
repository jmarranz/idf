// ListaComponentes.cpp: implementation of the CListaComponentes class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "ListaComponentes.h"

#include "ComponenteDiag.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ListaComponentes::ListaComponentes(int nBlockSize) : m_lista(nBlockSize)
{

}

ListaComponentes::~ListaComponentes()
{

}

int ListaComponentes::GetCount( ) const
{
	return m_lista.GetCount();
}

POSITION ListaComponentes::GetStartPosition( ) const
{
	return m_lista.GetStartPosition();
}

BOOL ListaComponentes::IsEmpty( ) const
{
	return m_lista.IsEmpty();
}

void ListaComponentes::RemoveAll( )
{
	m_lista.RemoveAll();
}

void ListaComponentes::RemoveKey( LPCTSTR key )
{
	m_lista.RemoveKey( key );
}

void ListaComponentes::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	m_lista.Serialize(ar);
} 

void ListaComponentes::Destruir()
{
	for( POSITION pos = m_lista.GetStartPosition( ); pos != NULL ; )
	{
		CComponenteDiag* comp;
		CString clave;
		m_lista.GetNextAssoc( pos,clave,(CObject*&)comp);
    	comp->Destruir();
	} 
	m_lista.RemoveAll();
}

CComponenteDiag* ListaComponentes::BuscaPorEtiq(CString& etiq)
{
    // Devuelve el bloque cuya etiqueta de diálogo sea la especificada.
	for( POSITION pos = m_lista.GetStartPosition( );pos != NULL ; )
	{
		CComponenteDiag* comp;
		CString clave;
		m_lista.GetNextAssoc( pos,clave,(CObject*&)comp);
		if (comp->getEtiqueta() == etiq) return comp;
	}     

	return NULL;
}

void ListaComponentes::GetNextAssoc( POSITION& rNextPosition, CString& rKey, CComponenteDiag*& comp ) const
{
	m_lista.GetNextAssoc(rNextPosition,rKey,(CObject*&)comp);
}

void ListaComponentes::SetAt( LPCTSTR key, CComponenteDiag* comp )
{
	m_lista.SetAt(key,comp);
}

BOOL ListaComponentes::Lookup( LPCTSTR key, CComponenteDiag*& comp ) const
{
	return m_lista.Lookup(key,(CObject*&)comp);
}

