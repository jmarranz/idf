
#include "stdafx.h"

#include "bloqretro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



IMPLEMENT_SERIAL(CBloqueRetro,CBloque,1)


CBloqueRetro::CBloqueRetro()   // Para creación dinámica y serialización
{
     
}

CBloqueRetro::~CBloqueRetro()
{
	// Aquí no se puede llamar a DestDatos de la derivada pues se destruye antes de ejecutarse
	// el destructor de la base. 
	// Es llamada explícitamente DestObjDatosyAccion la función que inmediatamente hace
	// después un delete al objeto.
}





