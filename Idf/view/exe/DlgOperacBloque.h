// dlgopebl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COperacBloque dialog

class CBloqueExe;

class COperacBloque : public CDialog
{
// Construction
public:
	COperacBloque(CWnd* pParent = NULL);	// standard constructor

	virtual void setBloque(CBloqueExe* blq);

// Dialog Data
	//{{AFX_DATA(COperacBloque)
	enum { IDD = IDD_OPERAC_BLOQUE };
	CString	m_ConectEtiq;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(COperacBloque)
	afx_msg void OnAceptarDatos();
	afx_msg void OnDevolverDatos();
	afx_msg void OnRetroanota();
	afx_msg void OnEnviarRetroano();
	afx_msg void OnRecibirRetroano();
	afx_msg void OnAccion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	CBloqueExe* p_bloque;
};

