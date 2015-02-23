// DiagramaException.h: interface for the DiagramaException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIAGRAMAEXCEPTION_H__A68C2AC5_7C08_49CA_89E3_F7A94FA5BE0B__INCLUDED_)
#define AFX_DIAGRAMAEXCEPTION_H__A68C2AC5_7C08_49CA_89E3_F7A94FA5BE0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Exception.h"


class DiagramaException : public Exception  
{
public:
	DiagramaException(CDiagBase* pdiag,const char* message);
	virtual ~DiagramaException();

	static CString buildMessage(CDiagBase* pdiag, const char* message);

protected:

};

#endif // !defined(AFX_DIAGRAMAEXCEPTION_H__A68C2AC5_7C08_49CA_89E3_F7A94FA5BE0B__INCLUDED_)
