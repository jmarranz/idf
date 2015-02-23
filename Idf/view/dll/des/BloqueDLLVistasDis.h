// BloqueDLLVistasDis.h: interface for the CBloqueDLLVistasDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASDLLDIS_H__39C5EF4C_8278_4D74_A7EB_E305AC7CB199__INCLUDED_)
#define AFX_BLOQUEVISTASDLLDIS_H__39C5EF4C_8278_4D74_A7EB_E305AC7CB199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\des\BloqueUnidadVistasDis.h"

class CBloqueDLLVistas;


class CBloqueDLLVistasDis : public CBloqueUnidadVistasDis
{
public:
	CBloqueDLLVistasDis();
	virtual ~CBloqueDLLVistasDis();

	CBloqueDLLVistas* getVistas()
	{
		return (CBloqueDLLVistas*)p_vistas;
	}

	virtual void PropUsuario() { ASSERT(false);  };
	virtual void DlgOperaciones() { ASSERT(false); };


};

#endif // !defined(AFX_BLOQUEVISTASDLLDIS_H__39C5EF4C_8278_4D74_A7EB_E305AC7CB199__INCLUDED_)
