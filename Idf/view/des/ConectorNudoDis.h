// ConectorNudoDis.h: interface for the CConectorNudoDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTORNUDODIS_H__D051BDDA_62CC_42FE_981F_706BEB2AE3FC__INCLUDED_)
#define AFX_CONECTORNUDODIS_H__D051BDDA_62CC_42FE_981F_706BEB2AE3FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ConectNudo.h"

class CDiagDisView;
class CBaseView;
class CDlgNudoCon;


class CConectorNudoDis : public CConNudo  
{
	DECLARE_SERIAL(CConectorNudoDis)
public:
	CConectorNudoDis();
	virtual ~CConectorNudoDis();
	virtual void Destruir();

	virtual void CrearNuevo(); // Crea nuevos diálogos de un nudo en todas las vistas existenetes.	

	virtual void Actualizar();
	virtual void Actualizar(CBaseView* view);
	virtual void ActualizarExcepto(CBaseView* view);

	virtual CDlgNudoCon* BuscaDialogoNudo(CBaseView* view);

    virtual void addView(CBaseView* pView);
    virtual void removeView(CBaseView* pView);

protected:
	CMapPtrToPtr m_views;
};

#endif // !defined(AFX_CONECTORNUDODIS_H__D051BDDA_62CC_42FE_981F_706BEB2AE3FC__INCLUDED_)
