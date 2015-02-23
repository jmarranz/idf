// ComponenteDiagException.h: interface for the ComponenteDiagException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTEDIAGEXCEPTION_H__C3BFC4B4_4DCE_422E_BC39_41784790D2BC__INCLUDED_)
#define AFX_COMPONENTEDIAGEXCEPTION_H__C3BFC4B4_4DCE_422E_BC39_41784790D2BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Exception.h"

class CComponenteDiag;

class ComponenteDiagException : public Exception  
{
public:
	ComponenteDiagException(CComponenteDiag* pcomp,const char* message);
	virtual ~ComponenteDiagException();

protected:
	static CString buildMessage(CComponenteDiag* pcomp,const char* message);
};

#endif // !defined(AFX_COMPONENTEDIAGEXCEPTION_H__C3BFC4B4_4DCE_422E_BC39_41784790D2BC__INCLUDED_)
