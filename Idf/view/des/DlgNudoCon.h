// nudocon.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgNudoCon dialog

// La ventana de tipo diálogo que representa un nudo de un conector en tiempo de diseño. 


class CDiagDisView;
class CConNudo;
class CDibConectDis;

// Orden de nudos de conector:



class CDlgNudoCon : public CDialog
{
// Construction
public:
	CDlgNudoCon(CWnd* pParent = NULL);	// standard constructor
	virtual BOOL Crear(CDiagDisView* view, CConNudo* connudo);	
	virtual void Actualizar();
	virtual void CentrarCursor();
	virtual void InvalidaEntorno(CDC* pDC);	
	virtual void RedibujarSeleccion();
	virtual void MoverNudo(CPoint point);	


// Dialog Data
	//{{AFX_DATA(CDlgNudoCon)
	enum { IDD = IDD_NUDOCON };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDlgNudoCon)
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEliminarConec();
	afx_msg void OnEliminarnudo();
	afx_msg void OnPropiedades();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnAnyadirnudoant();
	afx_msg void OnAnyadirnudopost();
	afx_msg void OnCambiaposetiq();
	afx_msg void OnAsociarBlqfin();
	afx_msg void OnAsociarBlqini();
	afx_msg void OnIralnudoprev();
	afx_msg void OnIralnudosig();
	afx_msg void OnLiberarRaton();
	afx_msg void OnGravasociarBlqfin();
	afx_msg void OnGravasociarBlqini();
	afx_msg void OnSelecConector();
	afx_msg void OnSelecNudo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

    // Variables
	CDiagDisView* p_view;
	CConNudo* p_nudo;
	CDibConectDis* p_dibConect;

	int m_tipoNudo;    // Si es punto inicial, medio o final del conector.

    BOOL m_mover;  // Controla si está pulsado botón izdo del ratón  para movimiento.

	CPoint m_previaPos;
};
