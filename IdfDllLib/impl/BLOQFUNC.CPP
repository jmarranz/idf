
#include "stdafx.h"

#include "bloqfunc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

 

IMPLEMENT_SERIAL(CBloqueFunc, CBloque, 1)


CBloqueFunc::CBloqueFunc()   // Para creación dinámica y serialización
{
    
}

CBloqueFunc::~CBloqueFunc()
{
	// Aquí no se puede llamar a DestDatos de la derivada pues se destruye antes de ejecutarse
	// el destructor de la base. 
	// Es llamada explícitamente DestObjDatosyAccion la función que inmediatamente hace
	// después un delete al objeto.
}


