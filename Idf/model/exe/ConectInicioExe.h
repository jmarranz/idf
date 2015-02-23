// ConectInicioExe.h: interface for the CConectInicioExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTINICIOEXE_H__40F0F27D_A2D3_45A6_84C0_CDCD4EA254AC__INCLUDED_)
#define AFX_CONECTINICIOEXE_H__40F0F27D_A2D3_45A6_84C0_CDCD4EA254AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ConectExtremoExe.h"

class CConectInicio;
class CComunicacion;


class CConectInicioExe : public CConectExtremoExe
{
public:
	CConectInicioExe();
	virtual ~CConectInicioExe();

	CConectInicio* getInicio()
	{
		return (CConectInicio*)p_extremo;
	}

	virtual CComunicacion* DevolverDatos() = 0;	
};

#endif // !defined(AFX_CONECTINICIOEXE_H__40F0F27D_A2D3_45A6_84C0_CDCD4EA254AC__INCLUDED_)
