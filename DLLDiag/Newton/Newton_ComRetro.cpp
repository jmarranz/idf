// Newton_ComRetro.cpp: implementation of the Newton_ComRetro class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_ComRetro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


// Clase Com. Newton_ComRetro

IMPLEMENTAR_COMUNICACION(Newton_ComRetro, CCom,1)

//IMPLEMENTAR_VARIABLE_COM(Newton_ComRetro, double, emax)
//IMPLEMENTAR_VARIABLE_COM(Newton_ComRetro, double, h)

void Newton_ComRetro::GuardarDatos(CArchive& ar)
{
	ar << emax << h;
}

void Newton_ComRetro::LeerDatos(CArchive& ar)
{
	ar >> emax >> h;
}
