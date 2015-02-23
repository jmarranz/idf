// ConectVistasExe.h: interface for the CConectVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTVISTASEXE_H__3B2B7D72_0805_4691_9267_60741DA89C0F__INCLUDED_)
#define AFX_CONECTVISTASEXE_H__3B2B7D72_0805_4691_9267_60741DA89C0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ConectVistas.h"

class CConectExe;
class CDibConectExe;


class CConectVistasExe : public CConectVistas  
{
public:
	CConectVistasExe();
	virtual ~CConectVistasExe();

	CDibConectExe* getDibConect()
	{
		return (CDibConectExe*)p_dibCon;
	}

	virtual CDibConect* CrearObjDibConect();

	virtual BOOL NuevaClaseComunic();

};

#endif // !defined(AFX_CONECTVISTASEXE_H__3B2B7D72_0805_4691_9267_60741DA89C0F__INCLUDED_)
