// BloqueDLLVistas.h: interface for the CBloqueDLLVistas class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASDLL_H__52FFB98A_85E0_4479_8CD3_42436C30A4D6__INCLUDED_)
#define AFX_BLOQUEVISTASDLL_H__52FFB98A_85E0_4479_8CD3_42436C30A4D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\BloqueUnidadVistas.h"

class CBloqueDLL;
class CBloqueDLLVistasExe;
class CBloqueDLLVistasDis;
class CComponenteDiag;


class CBloqueDLLVistas : public CBloqueUnidadVistas  
{
public:
	CBloqueDLLVistas();
	virtual ~CBloqueDLLVistas();
	virtual void Construir(CComponenteDiag* comp);

	CBloqueDLL* getBloque()
	{
		return (CBloqueDLL*)p_comp;
	}

	CBloqueDLLVistasExe* getExe()
	{
		return (CBloqueDLLVistasExe*)p_modo;
	}

	CBloqueDLLVistasDis* getDis()
	{
		return (CBloqueDLLVistasDis*)p_modo;
	}

	virtual BOOL Propiedades(UINT pagina = 0);
};

#endif // !defined(AFX_BLOQUEVISTASDLL_H__52FFB98A_85E0_4479_8CD3_42436C30A4D6__INCLUDED_)
