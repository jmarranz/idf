// ConectorException.cpp: implementation of the ConectorException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ConectorException.h"

#include "Conect.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ConectorException::ConectorException(CConect* pconect,const char* message)
: ComponenteDiagException(pconect,message)
{

}

ConectorException::~ConectorException()
{

}
