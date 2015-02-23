// ConectInicio.h: interface for the CConectInicio class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTINICIO_H__92E8433B_2A9C_4D97_8892_008D91DB6E52__INCLUDED_)
#define AFX_CONECTINICIO_H__92E8433B_2A9C_4D97_8892_008D91DB6E52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ConectExtremo.h"

class CConectInicioExe;
class CConectInicioDis;
class CBloque;


class CConectInicio : public CConectExtremo  
{
public:
	CConectInicio();
	virtual ~CConectInicio();

	static CConectExtremo* crear(CBloque* pblq, CConect* pcon);

	virtual BOOL EsInicio() { return true; }

	CConectInicioExe* getExe()
	{
		return (CConectInicioExe*)p_modo;
	}

	CConectInicioDis* getDis()
	{
		return (CConectInicioDis*)p_modo;
	}

	virtual void setBloque(CBloque* bloq);

};

#endif // !defined(AFX_CONECTINICIO_H__92E8433B_2A9C_4D97_8892_008D91DB6E52__INCLUDED_)
