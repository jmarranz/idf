// tabladis.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CBotonTabla window

class CBotonTabla : public CButton
{
// Construction
public:
	CBotonTabla();

// Attributes
public:

// Operations
public:

// Implementation
public:
	virtual ~CBotonTabla();
	virtual WNDPROC* GetSuperWndProcAddr( );

protected:
	// Generated message map functions
	//{{AFX_MSG(CBotonTabla)
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


	WNDPROC m_viejoProc;
public:
	UINT m_bitmap;
    CSize m_size;
	CString m_ayuda;
};

/////////////////////////////////////////////////////////////////////////////


// Notas CTabladis:  Originalmente derivaba de CDialog y de hecho
// la mayor parte del código se hizo de acuerdo con CDialog
// Posteriormente se derivó de CDialogBar para aprovechar las prestaciones
// de las ventanas dockables.
// Ello implicó que OnInitDialog se llame explícitamente pero no a
// a través de un mensaje, sirviendo para conectar los botones a los objetos botón.
// Igulamente se han puesto explícitamente macros ON_UPDATE_COMMAND_UI para que los controles
// de los botones se activen ya que un CDialogBar no activa por defecto sus controles
// (como si fuera un menú) y al ser botones no tienen macros ON_COMMAND (que sí activarían el control
// al igual que un item de un menú).


/////////////////////////////////////////////////////////////////////////////
// CTablaDis dialog

class CDiagDis;
class CDiagDisView;


class CTablaDis : public CDialogBar
{
// Construction
public:
	CTablaDis();	// standard constructor
    virtual BOOL Crear(CDiagDis* diag, CString& titulo);
	virtual BOOL OnInitDialog();	
	virtual void setTitulo(const char* titulo);
	virtual CDiagDisView* ActivarPrimeraVista();
	
// Dialog Data
	//{{AFX_DATA(CTablaDis)
	enum { IDD = IDD_TABLADISENO };
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CTablaDis)
	afx_msg void OnInsBlqRetro();
	afx_msg void OnClose();
	afx_msg void OnInsBlqfuncDiag();
	afx_msg void OnCposetiqdiag();
	afx_msg void OnCancelarEdic();
	afx_msg void OnInsConect();
	afx_msg void OnInsConectRetro();
	afx_msg void OnMovgruposel();
	afx_msg void OnInsBlqfuncDll();
	//}}AFX_MSG

	afx_msg void OnUpdateBoton(CCmdUI* pCmdUI);  // Ver el .cpp
		
	DECLARE_MESSAGE_MAP()


public:
	CDiagDis* p_diag;
	CString Titulo;

	CBotonTabla BBDLL;
	CBotonTabla BBDiag;
	CBotonTabla BBRetro;
	CBotonTabla BConFunc;
	CBotonTabla BConRetro;
	CBotonTabla BDTit;
	CBotonTabla	BDespl;
	CBotonTabla BCancel;
	
};


