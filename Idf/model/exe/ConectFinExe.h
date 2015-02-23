// ConectFinExe.h: interface for the CConectFinExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTFINEXE_H__69CB4192_1129_4A4D_84B8_369784BF59BF__INCLUDED_)
#define AFX_CONECTFINEXE_H__69CB4192_1129_4A4D_84B8_369784BF59BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ConectExtremoExe.h"

class CConectFin;
class CComunicacion;


class CConectFinExe : public CConectExtremoExe
{
public:
	CConectFinExe();
	virtual ~CConectFinExe();

	CConectFin* getFin()
	{
		return (CConectFin*)p_extremo;
	}

	virtual BOOL AceptarDatos(CComunicacion* pE) = 0;
};

#endif // !defined(AFX_CONECTFINEXE_H__69CB4192_1129_4A4D_84B8_369784BF59BF__INCLUDED_)
