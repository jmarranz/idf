// Exception.cpp: implementation of the Exception class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "idf.h"
#include "Exception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Exception::Exception()
{

}

Exception::~Exception()
{

}

Exception::Exception(const char* message)
{
	m_message = message;
}

Exception::Exception(const CString& message)
{
	m_message = message;
}

CString Exception::getMessage()
{
	return m_message;
}


