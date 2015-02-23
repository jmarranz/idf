// DiagramaException.cpp: implementation of the DiagramaException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "DiagramaException.h"

#include "DiagBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DiagramaException::DiagramaException(CDiagBase* pdiag,const char* message)
: Exception(buildMessage(pdiag,message))
{
}

DiagramaException::~DiagramaException()
{

}

CString DiagramaException::buildMessage(CDiagBase* pdiag, const char* message)
{
	CString msg = "Diagrama \"" + pdiag->m_nombreDiag + "\": " + message;
	return msg;
}

