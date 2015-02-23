// DibConectExe.h: interface for the CDibConectExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBCONECTEXE_H__BD851068_54A4_4CFE_9578_EFBBA6AD7A31__INCLUDED_)
#define AFX_DIBCONECTEXE_H__BD851068_54A4_4CFE_9578_EFBBA6AD7A31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\DibConect.h"

class CDibConectExe : public CDibConect  
{
public:
	CDibConectExe();
	virtual ~CDibConectExe();

	virtual void Actualizar();
	virtual void Actualizar(CBaseView* view);
	virtual void ActualizarExcepto(CBaseView* view);

    virtual void addView(CBaseView* pView);
    virtual void removeView(CBaseView* pView);
};

#endif // !defined(AFX_DIBCONECTEXE_H__BD851068_54A4_4CFE_9578_EFBBA6AD7A31__INCLUDED_)
