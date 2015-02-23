// CListaComponentes.h: interface for the CListaComponentes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CListaComponentes_H__5F5C2AA7_FAB5_4CBD_95F0_5E1353FF3ED6__INCLUDED_)
#define AFX_CListaComponentes_H__5F5C2AA7_FAB5_4CBD_95F0_5E1353FF3ED6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CComponenteDiag;


class ListaComponentes : public CObject  
{
public:
	ListaComponentes(int nBlockSize = 10);
	virtual ~ListaComponentes();
	virtual void Destruir();

	int GetCount( ) const;
	POSITION GetStartPosition( ) const;
	BOOL IsEmpty( ) const;
	void RemoveAll( );	
	void RemoveKey(LPCTSTR key);
	void Serialize(CArchive& ar);

	void SetAt( LPCTSTR key, CComponenteDiag* comp );
	BOOL Lookup( LPCTSTR key, CComponenteDiag*& comp ) const;

	void GetNextAssoc( POSITION& rNextPosition, CString& rKey, CComponenteDiag*& comp ) const;

	CComponenteDiag* BuscaPorEtiq(CString& etiq);

protected:
	CMapStringToOb m_lista;
};

#endif // !defined(AFX_CListaComponentes_H__5F5C2AA7_FAB5_4CBD_95F0_5E1353FF3ED6__INCLUDED_)
