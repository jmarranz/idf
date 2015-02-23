// BloqueDiagVistasExe.h: interface for the CBloqueDiagVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASDIAGEXE_H__060C78AA_219D_4DEC_9537_25B5281BA4CE__INCLUDED_)
#define AFX_BLOQUEVISTASDIAGEXE_H__060C78AA_219D_4DEC_9537_25B5281BA4CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\exe\BloqueVistasExe.h"

class CBloqueDiagVistas;
class CBaseView;


class CBloqueDiagVistasExe : public CBloqueVistasExe
{
public:
	CBloqueDiagVistasExe();
	virtual ~CBloqueDiagVistasExe();

	CBloqueDiagVistas* getVistas()
	{
		return (CBloqueDiagVistas*)p_vistas;
	}

	virtual void PropUsuario(); // Llamada desde el diálogo de propiedades y por CTRL Botón Dcho. 

//	virtual void crearView();
};

#endif // !defined(AFX_BLOQUEVISTASDIAGEXE_H__060C78AA_219D_4DEC_9537_25B5281BA4CE__INCLUDED_)
