// ConectInicioDLLDis.h: interface for the CConectInicioDLLDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTINICIODLLDIS_H__BE89810D_8D71_4C9B_BBB5_86ADF8350DEA__INCLUDED_)
#define AFX_CONECTINICIODLLDIS_H__BE89810D_8D71_4C9B_BBB5_86ADF8350DEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\DES\ConectInicioDis.h"
#include "ConectExtremoDLLDis.h"

class CConectInicioDLLDis : public CConectInicioDis, CConectExtremoDLLDis
{
public:
	CConectInicioDLLDis();
	virtual ~CConectInicioDLLDis();

};

#endif // !defined(AFX_CONECTINICIODLLDIS_H__BE89810D_8D71_4C9B_BBB5_86ADF8350DEA__INCLUDED_)
