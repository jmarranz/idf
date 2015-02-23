// ConectInicioDis.h: interface for the CConectInicioDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTINICIODIS_H__8807038A_93B9_44DA_934B_BABF098DDB1A__INCLUDED_)
#define AFX_CONECTINICIODIS_H__8807038A_93B9_44DA_934B_BABF098DDB1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ConectExtremoDis.h"

class CConectInicio;


class CConectInicioDis : public CConectExtremoDis
{
public:
	CConectInicioDis();
	virtual ~CConectInicioDis();
};

#endif // !defined(AFX_CONECTINICIODIS_H__8807038A_93B9_44DA_934B_BABF098DDB1A__INCLUDED_)
