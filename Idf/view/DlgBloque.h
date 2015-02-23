// DlgBloque.h: interface for the CDlgBloque class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGBLOQUE_H__E129707D_4EA2_49C1_90B9_B26C619DB3EA__INCLUDED_)
#define AFX_DLGBLOQUE_H__E129707D_4EA2_49C1_90B9_B26C619DB3EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Flecha.h"

class CBaseView;
class CBloque;
class CBloqueVistas;


class CDlgBloque : public CDialog  
{
public:
	CDlgBloque(UINT nIDTemplate,CWnd* pParent = NULL);
	virtual ~CDlgBloque();

	virtual BOOL Crear(CBaseView* view,CBloqueVistas* pvistas) = 0;
	virtual BOOL Crear(CBaseView* view,CBloqueVistas* pvistas,UINT recurso);

	virtual void Actualizar();  // Actualiza los cambios hechos en el diálogo (texto, posición etc.) a partir de los datos de CBloque en la pantalla.
	virtual void Recolocar();  // Recalcula la posición y tamaño de los controles ante un cambio de tamaño y/o posición.
	virtual void ActualizaEtiq() = 0;
	virtual void MoverEtiqueta(CRect& rect) = 0;
	virtual void SetCursorTipoBloque();

	virtual void OnPaint();
	virtual HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

	virtual void OnPropGen();
	virtual void OnPropEspec();
	virtual void OnPropInform();
	virtual void OnPropListaconect();

	virtual void cargarMenu(CPoint point) = 0;

public:
	// Ojo, las variables conviene ponerlas en CBloque para que todos los diálogos
	// asociados a un mismo bloque tengan el mismo comportamiento.
	// Sólo definir las variables necesarias para manejar el diálogo en aspectos exclusivos de la instancia.

	CBaseView* p_view;  // Vista padre que contiene el diálogo. Se inicializa en Crear()
	CBloqueVistas* p_vistas; 
	CFlecha m_flechaAE;
	CFlecha m_flechaAS;
};

#endif // !defined(AFX_DLGBLOQUE_H__E129707D_4EA2_49C1_90B9_B26C619DB3EA__INCLUDED_)
