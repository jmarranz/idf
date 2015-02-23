// NULO.cpp: implementation of the NULO2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IdfDllApp.h"
#include "NULO.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Implementación objeto nulo de comunicaciones:

IMPLEMENTAR_COMUNICACION(NULO, CCom,1)


void NULO::GuardarDatos(CArchive& ar)
{
}

void NULO::LeerDatos(CArchive& ar)
{
}

