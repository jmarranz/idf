// CAnalisisClasesSinDLL.h: interface for the CAnalisisClasesSinDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAnalisisClasesSinDLL_H__97C1FCBC_3E8C_4D0B_9D9E_D3B3302E644B__INCLUDED_)
#define AFX_CAnalisisClasesSinDLL_H__97C1FCBC_3E8C_4D0B_9D9E_D3B3302E644B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AnalisisClasesDLL.h"

class CConect;
class CBloqueDLL;


class CAnalisisClasesSinDLL : public CAnalisisClasesDLL  
{
public:
	CAnalisisClasesSinDLL(CDiagBase* pdiag);
	virtual ~CAnalisisClasesSinDLL();

	virtual void Construir();

	virtual BOOL ConDLL() { return false; }

	void EnlazarConectores(BOOL retro);
	void EnlazarBloques(CMapStringToPtr& lista,BOOL retro);

	void EnlazaListaComES(CInfoBloque* pdatos,CBloqueDLL* blqdll,int tipo,BOOL Retroanotacion);
	void EnlazaComES(CMapStringToOb& lista,const CString& claseBloque,const CString& claseCom,int tipo,BOOL Retroanotacion);
};

#endif // !defined(AFX_CAnalisisClasesSinDLL_H__97C1FCBC_3E8C_4D0B_9D9E_D3B3302E644B__INCLUDED_)
