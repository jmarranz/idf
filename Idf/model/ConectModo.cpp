// ConectModo.cpp: implementation of the CConectModo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ConectModo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC(CConectModo,CObject)


CConectModo::CConectModo()
{
	p_conect = NULL;
}

CConectModo::~CConectModo()
{

}

void CConectModo::Construir(CConect* pcon)
{
	p_conect = pcon;
}


