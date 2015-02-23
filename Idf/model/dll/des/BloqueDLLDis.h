 
// bdlldis.h

#ifndef CBLOQUEDLLDIS
#define CBLOQUEDLLDIS

// Clase bloque funcional basado en DLL orientada al diseño,
// Derivada de CBloqueDLL

// Redefine la funcionalidad de CBloqueDLL no admitida en diseño.

#include "..\..\des\BloqueUnidadDis.h"

class CDiagDis;
class CBaseView;
class CBloqueDLL;
class DOMElement;

class CBloqueDLLDis : public CBloqueUnidadDis
{
	DECLARE_SERIAL(CBloqueDLLDis)

// Construction
public:
	CBloqueDLLDis();
	virtual ~CBloqueDLLDis();  // No hace nada

	CBloqueDLL* getBloque()
	{
		return (CBloqueDLL*)p_bloque;
	}

public:
	// Variables:

};

#endif
