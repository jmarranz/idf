// ListaBloques.h: interface for the ListaBloques class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTABLOQUES_H__F3247953_3389_4DE8_8BF2_A523A28B03D1__INCLUDED_)
#define AFX_LISTABLOQUES_H__F3247953_3389_4DE8_8BF2_A523A28B03D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ListaComponentes.h"

class CBloque;


class ListaBloques : public ListaComponentes  
{
public:
	ListaBloques( int nBlockSize = 10 );
	virtual ~ListaBloques();

	// Redefinidas
	void SetAt( LPCTSTR key, CBloque* blq );
	BOOL Lookup( LPCTSTR key, CBloque*& blq ) const;
	void GetNextAssoc( POSITION& rNextPosition, CString& rKey, CBloque*& blq ) const;

	// Propias
    CBloque* BuscaPorClave(const CString& clave); 

};

#endif // !defined(AFX_LISTABLOQUES_H__F3247953_3389_4DE8_8BF2_A523A28B03D1__INCLUDED_)
