// ConectorNudoExe.h: interface for the CConectorNudoExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTORNUDOEXE_H__5ECB255C_FC5E_417E_8D6C_AE7A1B007761__INCLUDED_)
#define AFX_CONECTORNUDOEXE_H__5ECB255C_FC5E_417E_8D6C_AE7A1B007761__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ConectNudo.h"

class CConectorNudoExe : public CConNudo  
{
	DECLARE_SERIAL(CConectorNudoExe)
public:
	CConectorNudoExe();
	virtual ~CConectorNudoExe();

};

#endif // !defined(AFX_CONECTORNUDOEXE_H__5ECB255C_FC5E_417E_8D6C_AE7A1B007761__INCLUDED_)
