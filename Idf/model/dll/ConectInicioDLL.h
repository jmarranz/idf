// ConectInicioDLL.h: interface for the CConectInicioDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTINICIODLL_H__EA1077CA_5F4D_4E0B_A048_520E4991E0AD__INCLUDED_)
#define AFX_CONECTINICIODLL_H__EA1077CA_5F4D_4E0B_A048_520E4991E0AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ConectInicio.h"

class CConectInicioDLLExe;
class CConectInicioDLLDis;
class CBloqueDLL;


class CConectInicioDLL : public CConectInicio  
{
public:
	CConectInicioDLL();
	virtual ~CConectInicioDLL();
	virtual void Construir(CConect* con,CBloque* pblq);

	CConectInicioDLLExe* getExe()
	{
		return (CConectInicioDLLExe*)p_modo;
	}

	CConectInicioDLLDis* getDis()
	{
		return (CConectInicioDLLDis*)p_modo;
	}

	CBloqueDLL* getBloqueDLL()
	{
		return p_bloqueDLL;
	}

	void setBloqueDLL(CBloqueDLL* pblq)
	{
		p_bloqueDLL = pblq;
	}

protected:
	CBloqueDLL* p_bloqueDLL;
};

#endif // !defined(AFX_CONECTINICIODLL_H__EA1077CA_5F4D_4E0B_A048_520E4991E0AD__INCLUDED_)
