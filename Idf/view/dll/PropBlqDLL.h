// pblqdll.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropBlqDLL dialog

class CBloqueDLL;


class CPropBlqDLL : public CPropertyPage
{
// Construction
public:
	CPropBlqDLL(CWnd* pParent = NULL);	// standard constructor

	virtual void setBloque(CBloqueDLL* pb);  
	virtual BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(CPropBlqDLL)
	enum { IDD = IDD_PROP_BLOQUE_DLL };
	CComboBox	m_CtrlClaseBloque;
	CButton	m_CambiaDLL;
	CButton	m_CtrlPropUsr;
	CEdit	m_CtrlDLLBloque;
	BOOL	m_UsaDLLDiag;
	CString	m_DLLBloque;
	CString	m_Fecha;
	CString	m_Macro;
	CString	m_ClaseBloque;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CPropBlqDLL)
	afx_msg void OnUsadlldiag();
	afx_msg void OnKillfocusDllbloque();
	afx_msg void OnCambiaDll();
	afx_msg void OnPropUsuario();
	afx_msg void OnKillfocusClaseBloque();
	afx_msg void OnListarClases();
	afx_msg void OnGeneracionCodigo();
	afx_msg void OnInspeccionCodigo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	
	CBloqueDLL* p_bloque;

};
