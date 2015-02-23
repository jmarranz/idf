// BloqueUnidad.h: interface for the CBloqueUnidad class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEUNIDAD_H__034325B8_8592_433D_A2C3_93E2CB2D6639__INCLUDED_)
#define AFX_BLOQUEUNIDAD_H__034325B8_8592_433D_A2C3_93E2CB2D6639__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bloque.h"

class CBloqueUnidad : public CBloque  
{
public:
	CBloqueUnidad();
	virtual ~CBloqueUnidad();

	virtual BOOL EsBloqueUnidad() { return true; };

	virtual BOOL EsBloqueDLL() { return false; }

};

#endif // !defined(AFX_BLOQUEUNIDAD_H__034325B8_8592_433D_A2C3_93E2CB2D6639__INCLUDED_)
