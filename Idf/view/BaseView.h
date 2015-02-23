// BaseView.h : interface of the CBaseView class
//
// Cubre la funcionalidad general de la vista, no tiene nada relacioando con la
// manipulación de objetos OLE embebidos.

// Es usada por la plantilla de funcionalidad del diagrama y por la de diseño como
// clase base de las vistas que usan. 

/////////////////////////////////////////////////////////////////////////////

#ifndef CBASEVIEW
#define CBASEVIEW

class CBaseDoc;
class CDiagramaVistas;
class CDibDiagrama;
class CDiagBase;


class CBaseView : public CScrollView
{
protected: // create from serialization only
	CBaseView();
	DECLARE_DYNCREATE(CBaseView)                      

// Attributes
public:
	
// Operations
public:

// Implementation
public:
	virtual ~CBaseView();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	CBaseDoc* GetDocument();  // Ojo no hacer virtual para que en las derivadas pueda devolver diferente tipo.

	CDiagBase* getDiag();
	CDiagramaVistas* getVistas();
	CDibDiagrama* getDibDiagrama();

	virtual CPoint Cliente_A_mm(CPoint& point);
	virtual CRect Cliente_A_mm(CRect& rect);	


#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void OnInitialUpdate(); // called first time after construct

	// Printing support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint( CDC* pDC, CPrintInfo* pInfo );
	
public:
	// Funciones propias:

	virtual int Redondeo( double num);	
	virtual CSize getDiagSize();
	virtual CPoint EscalaVisual( CPoint& pto);
	virtual CRect EscalaVisual( CRect& rect);		
	virtual CSize EscalaVisual( CSize& size);		

	virtual CPoint EscalaVisualInversa( CPoint& pto);
	virtual CRect EscalaVisualInversa( CRect& rect);		
	virtual CSize EscalaVisualInversa( CSize& size);		


// Generated message map functions
protected:
	//{{AFX_MSG(CBaseView)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnAjustarVentana();
	afx_msg void OnZoomRestaurar();
	afx_msg void OnZoomAcercar();
	afx_msg void OnZoomAlejar();
	afx_msg void OnVerTodo();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnUpdateZoom(CCmdUI* pCmdUI);
	afx_msg void OnAnalizarDll();
	afx_msg void OnClasesUsadasSinDll();
	afx_msg void OnGenerarLdd();
	afx_msg void OnGenerarMetafile();
	afx_msg void OnOperacZoom();
	afx_msg void OnUpdateOperacZoom(CCmdUI* pCmdUI);
	afx_msg void OnPropDiag();
	afx_msg void OnGenerarLddorigen();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

// Variables (no se guardan a fichero):
    BOOL m_imprimiendo;

protected:	
	CDiagBase* p_diag;

	double m_escala;

	static CBrush NEAR m_brHatch;

};

#endif

/////////////////////////////////////////////////////////////////////////////
