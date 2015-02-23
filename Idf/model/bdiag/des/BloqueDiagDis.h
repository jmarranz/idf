 
// bdiagdis.h

// Clase bloque funcional basado en DLL orientada al diseño,

#ifndef CBLOQUEDIAGDIS_H
#define CBLOQUEDIAGDIS_H

#include "..\..\des\BloqueDis.h"

class CDiagDis;
class CBaseView;
enum TipoEstadoUsuario;
enum TipoEstadoInterno;


class CBloqueDiagDis : public CBloqueDis
{
	DECLARE_SERIAL(CBloqueDiagDis)

// Construction
public:
	CBloqueDiagDis();
	virtual ~CBloqueDiagDis();  // No hace nada

	CBloqueDiag* getBloque()
	{
		return (CBloqueDiag*)p_bloque;
	}
};

#endif
