// ConectorException.h: interface for the ConectorException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTOREXCEPTION_H__94569701_1EDD_499E_BC96_4CA1B61A6EB6__INCLUDED_)
#define AFX_CONECTOREXCEPTION_H__94569701_1EDD_499E_BC96_4CA1B61A6EB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComponenteDiagException.h"

class CConect;

class ConectorException : public ComponenteDiagException  
{
public:
	ConectorException(CConect* pconect,const char* message);
	virtual ~ConectorException();

};

#endif // !defined(AFX_CONECTOREXCEPTION_H__94569701_1EDD_499E_BC96_4CA1B61A6EB6__INCLUDED_)
