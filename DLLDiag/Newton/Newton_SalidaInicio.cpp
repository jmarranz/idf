// Newton_SalidaInicio.cpp: implementation of the Newton_SalidaInicio class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_SalidaInicio.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



// Clase Com. Newton_SalidaInicio

IMPLEMENTAR_COMUNICACION(Newton_SalidaInicio, CCom,1)

//IMPLEMENTAR_VARIABLE_COM(Newton_SalidaInicio, double, x)

void Newton_SalidaInicio::GuardarDatos(CArchive& ar)
{
	ar << x;
}

void Newton_SalidaInicio::LeerDatos(CArchive& ar)
{
	ar >> x;
}
