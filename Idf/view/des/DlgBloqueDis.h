// dlgbdis.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBloqueDis dialog

#ifndef CDLGBLOQUEDIS
#define CDLGBLOQUEDIS

#include "..\DlgBloque.h"

class CDiagDisView;


class CDlgBloqueDis : public CDlgBloque   // El diálogo para el diseño del diagrama.
{
// Construction
public:
	CDlgBloqueDis(CWnd* pParent = NULL);	// standard constructor
	virtual BOOL Crear(CBaseView* view, CBloqueVistas* pvistas);
	virtual void RedibujarSeleccion(CRect* prviejo = NULL);
	virtual void ActualizaEtiq();
	virtual void MoverEtiqueta(CRect& rect);

	void MoverBloque(const CPoint& nuevapos);
	void ResizeBloque();
	void ActualizarBloque(const CRect& nuevo);

	void EsquinaCursor();

	virtual void cargarMenu(CPoint point);

// Dialog Data
	//{{AFX_DATA(CDlgBloqueDis)
	enum { IDD = IDD_BLOQUEDIS };
	CStatic	m_CtrlEtiq;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDlgBloqueDis)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSelecBloque();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPropGen();
	afx_msg void OnPropEspec();
	afx_msg void OnPropInform();
	afx_msg void OnPropListaconect();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEliminarBloque();
	afx_msg void OnCargarSubdiagrama();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

    BOOL m_inicializado;  // Evita el proceso de OnMove y OnSize en el proceso de creación.

    BOOL m_mover;  // Controla si está pulsado botón izdo del ratón  para movimiento.

	// Variables para recordar el último cambio y evitar hacer algo si no haya realmente un verdadero cambio, pues a veces Windows (XP) genera mensajes aunque no pase nada
	int m_cx;
	int m_cy;

	CPoint m_previaPos;
};

#endif
