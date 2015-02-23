// Newton_SalidaDatos.cpp: implementation of the Newton_SalidaDatos class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_SalidaDatos.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Clase Com. Newton_SalidaDatos 

IMPLEMENTAR_COMUNICACION(Newton_SalidaDatos, CCom,1)

//IMPLEMENTAR_VARIABLE_COM(Newton_SalidaDatos, double, x)
//IMPLEMENTAR_VARIABLE_COM(Newton_SalidaDatos, double, e)
IMPLEMENTAR_FUNCION_COM(Newton_SalidaDatos, SPrueba, const char*, CadenaPrueba)
