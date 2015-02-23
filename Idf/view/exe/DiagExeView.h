
// DiagExeView.h : interface of the CDiagExeView class

// Código original del OCLIENT

#ifndef DIAGEXEVIEW_H
#define DIAGEXEVIEW_H

#include "..\BaseView.h"

class CDiagExeDoc;
class CDiagExe;
class CDiagramaVistasExe;
class CDibDiagramaExe;


class CDiagExeView : public CBaseView
{
protected: // create from serialization only
	CDiagExeView();
	DECLARE_DYNCREATE(CDiagExeView)

// Attributes
public:
	CDiagExe* getDiag();
	CDiagramaVistasExe* getVistas();
	CDibDiagramaExe* getDibDiagrama();

	CDiagExeDoc* GetDocument()  // Ojo no hacer virtual para que en las derivadas pueda devolver diferente tipo.
	{
		return (CDiagExeDoc*) m_pDocument;
	};
	

// Operations
public:

	// Funciones de conversión de coordenadas usadas por los objetos OLE embebidos.
	void ClientToDoc(CRect &rc);
	void DocToClient(CRect &rc);
	void ClientToDoc(CPoint &pt);
	void DocToClient(CPoint &pt);
	void ClientToDoc(CSize &sz);
	void DocToClient(CSize &sz);

// Implementation
protected:
	static CLIPFORMAT m_cfObjectDescriptor;

	BOOL GetObjectInfo(COleDataObject* pDataObject,
		CSize* pSize, CSize* pOffset);

public:
	virtual ~CDiagExeView();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	virtual void OnInitialUpdate();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Printing support
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);


// Generated message map functions
protected:
	//{{AFX_MSG(CDiagExeView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnConsolaMostrar();
	afx_msg void OnConsolaMostrarSistema();
	afx_msg void OnConsolaMostrarUsuario();
	afx_msg void OnConsolaSalvarConDiagrama();
	afx_msg void OnInicializarDiagrama();
	afx_msg void OnIniciarConect();
	afx_msg void OnScrollAuto();
	afx_msg void OnUpdateConsolaMostrar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateConsolaMostrarSistema(CCmdUI* pCmdUI);
	afx_msg void OnUpdateConsolaMostrarUsuario(CCmdUI* pCmdUI);
	afx_msg void OnUpdateConsolaSalvarConDiagrama(CCmdUI* pCmdUI);
	afx_msg void OnUpdateScrollAuto(CCmdUI* pCmdUI);
	afx_msg void OnEditarDiag();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	CRectTracker m_rectTrk;   // Para el bloque último ejecutado.

};
#endif
