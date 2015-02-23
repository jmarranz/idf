// ConectExtremoModo.cpp: implementation of the CConectExtremoModo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ConectExtremoModo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectExtremoModo::CConectExtremoModo()
{
	p_extremo = NULL;
}

CConectExtremoModo::~CConectExtremoModo()
{

}

void CConectExtremoModo::Construir(CConectExtremo* ext)
{
	p_extremo = ext;
}

