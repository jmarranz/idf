// propbloq.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropBloque dialog

class CBloque;

class CPropBloque : public CPropertyPage
{
// Construction
public:
	CPropBloque(CWnd* pParent = NULL);	// standard constructor

	virtual void setBloque(CBloque* pb);    
	
	virtual BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(CPropBloque)
	enum { IDD = IDD_PROP_BLOQUE };
	CEdit	m_CtrlOrden;
	CButton	m_CtrlOperac;
	CEdit	m_CtrlEstadoInt;
	CComboBox	m_CtrlEstadoUsr;
	CEdit	m_CtrlAutoContMax;
	CEdit	m_CtrlSalidaAuto;
	CButton	m_CtrlAS;
	CButton	m_CtrlAE;
	BOOL	m_AE;
	BOOL	m_AS;
	CString	m_Etiq;
	CString	m_EstadoInterno;
	CString	m_id;
	CString	m_SalidaAuto;
	CString	m_TipoDibujo;
	BOOL	m_Visible;
	int		m_AnchoLin;
	CString	m_Orden;
	int		m_AutoContMax;
	CString	m_tipoBloque;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CPropBloque)
	afx_msg void OnOperaciones();
	afx_msg void OnSelchangeEstadousuario();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	enum TipoEstadoUsuario m_estadoUsuario;

	CBloque* p_bloque;
};

