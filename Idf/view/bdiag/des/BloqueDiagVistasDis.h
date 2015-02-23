// BloqueDiagVistasDis.h: interface for the CBloqueDiagVistasDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASDIAGDIS_H__060C78AA_219D_4DEC_9537_25B5281BA4CE__INCLUDED_)
#define AFX_BLOQUEVISTASDIAGDIS_H__060C78AA_219D_4DEC_9537_25B5281BA4CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\des\BloqueVistasDis.h"

class CBloqueDiagVistas;

class CBloqueDiagVistasDis : public CBloqueVistasDis
{
public:
	CBloqueDiagVistasDis();
	virtual ~CBloqueDiagVistasDis();

	CBloqueDiagVistas* getVistas()
	{
		return (CBloqueDiagVistas*)p_vistas;
	}

};

#endif // !defined(AFX_BLOQUEVISTASDIAGDIS_H__060C78AA_219D_4DEC_9537_25B5281BA4CE__INCLUDED_)
