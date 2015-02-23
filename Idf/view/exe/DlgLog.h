// dlglog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLog dialog

class CDiagExe;
class CDiagramaVistasExe;


class CDlgLog : public CDialog
{
// Construction
public:
	CDlgLog(CDiagExe* diag,CWnd* pParent = NULL);	// standard constructor
	virtual BOOL Crear();
	virtual void ActualizaTitulo(const char* titulo);
    virtual void Anyadir( CString mensaje);
	virtual void BorrarTexto();
	virtual void Serializar(CArchive& ar);
	virtual void ConsolaSalir();

	BOOL SalvarTextoLista(CString& NombreFichero);
	int getTextoSelec(CString& texto, BOOL borrar = false);
	void CopiarEnPortapapeles(CWnd* pWnd,CString& texto);


// Dialog Data
	//{{AFX_DATA(CDlgLog)
	enum { IDD = IDD_LOGDIAG };
	CListBox	m_CtrlLista;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDlgLog)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnConsolaCopiar();
	afx_msg void OnConsolaCortar();
	afx_msg void OnConsolaLimpiar();
	afx_msg void OnConsolaSalida();
	afx_msg void OnConsolaSalva();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CDiagExe* p_diag;
	CDiagramaVistasExe* p_vistas;

    int m_contador;
};
