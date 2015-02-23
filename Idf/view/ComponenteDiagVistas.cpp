// ComponenteDiagVistas.cpp: implementation of the CComponenteDiagVistas class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ComponenteDiagVistas.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComponenteDiagVistas::CComponenteDiagVistas()
{
	p_comp = NULL;
}

CComponenteDiagVistas::~CComponenteDiagVistas()
{

}

void CComponenteDiagVistas::Construir(CComponenteDiag* comp)
{
	p_comp = comp;
}

void CComponenteDiagVistas::Destruir()
{
}


