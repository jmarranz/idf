// propcon.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropConect dialog

class CConect;


class CPropConect : public CPropertyPage
{
// Construction
public:
	CPropConect();	// standard constructor
	virtual void setConect(CConect* con);
	virtual BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(CPropConect)
	enum { IDD = IDD_PROP_CONECT };
	CComboBox	m_CtrlClaseCom;
	CEdit	m_CtrlAnchoLin;
	CButton	m_CtrlPBlqFin;
	CButton	m_CtrlPBlqIni;
	CString	m_Etiq;
	CString	m_BlqFin;
	CString	m_BlqIni;
	CString	m_id;
	BOOL	m_Visible;
	CString	m_ClaseCom;
	UINT	m_AlturaFlecha;
	UINT	m_AnchoLin;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CPropConect)
	afx_msg void OnKillfocusEtiq();
	afx_msg void OnPropbloqIni();
	afx_msg void OnPropbloqFin();
	afx_msg void OnKillfocusClaseCom();
	afx_msg void OnListarClases();
	afx_msg void OnGeneracionCodigo();
	afx_msg void OnInspeccionCodigo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	CConect* p_conect;
};
