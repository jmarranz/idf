// ListaConectores.h: interface for the ListaConectores class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTACONECTORES_H__F3247953_3389_4DE8_8BF2_A523A28B03D1__INCLUDED_)
#define AFX_LISTACONECTORES_H__F3247953_3389_4DE8_8BF2_A523A28B03D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ListaComponentes.h"

class CConect;


class ListaConectores : public ListaComponentes
{
public:
	ListaConectores( int nBlockSize = 10 );
	virtual ~ListaConectores();

	// Redefinidas 
	void SetAt( LPCTSTR key, CConect* con );
	BOOL Lookup( LPCTSTR key, CConect*& con ) const;
	void GetNextAssoc( POSITION& rNextPosition, CString& rKey, CConect*& con ) const;

	// Propias
	CConect* BuscaPorClave(const CString& clave);

};

#endif // !defined(AFX_LISTABLOQUES_H__F3247953_3389_4DE8_8BF2_A523A28B03D1__INCLUDED_)
