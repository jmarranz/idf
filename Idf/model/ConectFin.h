// ConectFin.h: interface for the CConectFin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTFIN_H__2EA72651_3996_4ADD_ABD7_7F984CDB1A7D__INCLUDED_)
#define AFX_CONECTFIN_H__2EA72651_3996_4ADD_ABD7_7F984CDB1A7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ConectExtremo.h"

class CConectFinExe;
class CConectFinDis;


class CConectFin : public CConectExtremo  
{
public:
	CConectFin();
	virtual ~CConectFin();

	static CConectExtremo* crear(CBloque* pblq, CConect* pcon);

	virtual BOOL EsFin() { return true; }

	CConectFinExe* getExe()
	{
		return (CConectFinExe*)p_modo;
	}

	CConectFinDis* getDis()
	{
		return (CConectFinDis*)p_modo;
	}

	virtual void setBloque(CBloque* bloq);

};

#endif // !defined(AFX_CONECTFIN_H__2EA72651_3996_4ADD_ABD7_7F984CDB1A7D__INCLUDED_)
