
#include "stdafx.h"

#include "bloqfunc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

 

IMPLEMENT_SERIAL(CBloqueFunc, CBloque, 1)


CBloqueFunc::CBloqueFunc()   // Para creaci�n din�mica y serializaci�n
{
    
}

CBloqueFunc::~CBloqueFunc()
{
	// Aqu� no se puede llamar a DestDatos de la derivada pues se destruye antes de ejecutarse
	// el destructor de la base. 
	// Es llamada expl�citamente DestObjDatosyAccion la funci�n que inmediatamente hace
	// despu�s un delete al objeto.
}


