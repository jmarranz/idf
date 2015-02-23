// ConectVistasDis.h: interface for the CConectVistasDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTVISTASDIS_H__66DB39DF_3E94_4068_8F4E_1FE8581D996E__INCLUDED_)
#define AFX_CONECTVISTASDIS_H__66DB39DF_3E94_4068_8F4E_1FE8581D996E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ConectVistas.h"

class CConectDis;
class CDibConectDis;


class CConectVistasDis : public CConectVistas  
{
public:
	CConectVistasDis();
	virtual ~CConectVistasDis();

	CDibConectDis* getDibConect()
	{
		return (CDibConectDis*)p_dibCon;
	}

	virtual CDibConect* CrearObjDibConect();
};

#endif // !defined(AFX_CONECTVISTASDIS_H__66DB39DF_3E94_4068_8F4E_1FE8581D996E__INCLUDED_)
