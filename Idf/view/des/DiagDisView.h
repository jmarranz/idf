
// DiagDisView.h : interface of the CDiagDisView class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef CDIAGDISVIEW
#define CDIAGDISVIEW

#include "..\BaseView.h"

class CDiagDisDoc;
class CConectDis;
class CDiagDis;
class CTablaDis;
class CDiagramaVistasDis;
class CDibDiagramaDis;


class CDiagDisView : public CBaseView
{
	friend class CTablaDis;   // Para que pueda acceder a las funciones protegidas.

protected: // create from serialization only
	CDiagDisView();
	DECLARE_DYNCREATE(CDiagDisView)

	virtual void OnInitialUpdate(); // called first time after construct

// Operations
public:
	CDiagDisDoc* GetDocument();  // No hacer virtual  
// Implementation
public:
	virtual ~CDiagDisView();

	CDiagDis* getDiag();
	CDiagramaVistasDis* getVistas();
	CDibDiagramaDis* getDibDiagrama();
	
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnActivateView( BOOL bActivate, CView* pActivateView, CView* pDeactiveView );
	virtual BOOL PtEnDINA4(CPoint& pcc);
	virtual void CambiaPosEtiqConect(CConect* con);

	virtual void ForzarPosicionCursor(CPoint pos);
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CDiagDisView)
	afx_msg void OnCPosEtiqDiag();
	afx_msg void OnUpdateEdicion(CCmdUI* pCmdUI);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnInsBlqfuncDll();
	afx_msg void OnInsBlqfuncDiag();
	afx_msg void OnInsConect();
	afx_msg void OnInsConectRetro();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnCancelarEdic();
	afx_msg void OnUpdateCancelarEdic(CCmdUI* pCmdUI);
	afx_msg void OnInsBlqRetro();
	afx_msg void OnMovergrupo();
	afx_msg void OnSeleccTodo();
	afx_msg void OnAnularselecc();
	afx_msg void OnSeleccRect();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDeseleccRect();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnSeleccEliminar();
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSeleccEliminar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAnularselecc(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDeseleccRect(CCmdUI* pCmdUI);
	afx_msg void OnPropRejilla();
	afx_msg void OnVerTabladiag();
	afx_msg void OnUpdateVerTabladiag(CCmdUI* pCmdUI);
	afx_msg void OnEjecutarDiag();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// Variables temporales:
	BOOL m_capturado; // El ratón ha sido capturado. La necesitamos porque al cambiar de aplicación el ratón capturado se libera, para saber si volver a capturarlo.

    BOOL m_noActualizaPosBloq; 
    // NoActualizaPosBloq es usada en OnH/VScroll pues en el scroll se llama a OnMove de las ventanas hijas de la vista por ejemplo los bloques, un movimiento falso que no implica cambio de posición relativa,
    // inhibe el ejecutarse CDlgBloq::ActualizaPos() que haría un cálculo erróneo de la posición y tamaño al hacerse en medio del proceso del scroll quizás antes de que la vista se mueva etc.
    // Sólo importa en tiempo de diseño y no vale para nada en funcional.
};

#endif


/////////////////////////////////////////////////////////////////////////////
