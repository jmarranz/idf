// DibConectDis.h: interface for the CDibConectDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBCONECTDIS_H__38C74394_1C23_439F_80A2_65FC4025AFF5__INCLUDED_)
#define AFX_DIBCONECTDIS_H__38C74394_1C23_439F_80A2_65FC4025AFF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\DibConect.h"

class CDiagDisView;
class CConNudo;
class CDlgNudoCon;
class CDlgBloque;


class CDibConectDis : public CDibConect  
{
public:
	CDibConectDis();
	virtual ~CDibConectDis();

	virtual void Destruir();

	virtual void Dibujar(CDC* pDC, CBaseView* view);	


	virtual void Actualizar(); // Actualiza todos los diálogos de todos los nudos del conector en todas las vistas.
	virtual void Actualizar(CBaseView* view); // Actualiza todos los diálogos de nudos del conector de la vista dada.  
	virtual void ActualizarExcepto(CBaseView* view);

	virtual void ActualizaPosFlechaFinal();

	virtual int CalculaOrientacion(CPoint pini, CPoint pfin);

	virtual void MoverConGravedad(CDiagDisView* view, CDlgBloque* pDlgBloq, CPoint PtoGrav);
	virtual void MoverGrupoSelecc(const CPoint& desp);

	virtual void Seleccionar(BOOL Seleccionar = true, CRect * prsel = NULL, CDiagDisView* view = NULL);
	virtual BOOL EsSeleccionado();
	virtual BOOL EsSeleccionadoParcial();

    virtual void addView(CBaseView* pView);
    virtual void removeView(CBaseView* pView);

protected:
};

#endif // !defined(AFX_DIBCONECTDIS_H__38C74394_1C23_439F_80A2_65FC4025AFF5__INCLUDED_)
