     

///////////////////////////////////////////////////////////////////////////
//  CBloqueFunc      Clase para bloque funcional 
#ifndef CBLOQUEFUNC_H
#define CBLOQUEFUNC_H

#include "bloque.h"


class CBloqueFunc : public CBloque
{
     
    DECLARE_SERIAL(CBloqueFunc)

public:

	CBloqueFunc();
	virtual ~CBloqueFunc();
	// Fundamental que sea virtual para que pueda ejecutarse el que defina el usuario.

};


#endif

