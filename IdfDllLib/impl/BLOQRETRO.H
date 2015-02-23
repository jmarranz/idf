

///////////////////////////////////////////////////////////////////////////
//  CBloqueRetro      Clase para bloque de retroanotación 

#ifndef CBLOQUERETRO_H
#define CBLOQUERETRO_H

#include "bloque.h"


class CBloqueRetro : public CBloque
{
   	DECLARE_SERIAL(CBloqueRetro)

public:

   	CBloqueRetro();
	virtual ~CBloqueRetro();   // Fundamental que sea virtual para que pueda ejecutarse el que defina el usuario.

};

#endif

