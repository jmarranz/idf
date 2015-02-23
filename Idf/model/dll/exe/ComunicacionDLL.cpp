// ComunicacionDLL.cpp: implementation of the CComunicacionDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\..\idf.h"
#include "ComunicacionDLL.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComunicacionDLL::CComunicacionDLL(void* pcom)
{
	p_comDLL = pcom;
}

CComunicacionDLL::CComunicacionDLL(void* pcom,Instante t)
	: CComunicacion(t)
{
	p_comDLL = pcom;
}

CComunicacionDLL::~CComunicacionDLL()
{

}
