// ConectFinDLL.h: interface for the CConectFinDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTFINDLL_H__EEA4BCF3_BB18_43D9_86E9_CAF07298DEDC__INCLUDED_)
#define AFX_CONECTFINDLL_H__EEA4BCF3_BB18_43D9_86E9_CAF07298DEDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ConectFin.h"

class CConectFinDLLExe;
class CConectFinDLLDis;
class CBloqueDLL;

class CConectFinDLL : public CConectFin  
{
public:
	CConectFinDLL();
	virtual ~CConectFinDLL();
	virtual void Construir(CConect* con,CBloque* pblq);

	CConectFinDLLExe* getExe()
	{
		return (CConectFinDLLExe*)p_modo;
	}

	CConectFinDLLDis* getDis()
	{
		return (CConectFinDLLDis*)p_modo;
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

#endif // !defined(AFX_CONECTFINDLL_H__EEA4BCF3_BB18_43D9_86E9_CAF07298DEDC__INCLUDED_)
