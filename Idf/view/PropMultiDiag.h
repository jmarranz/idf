// propmult.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropMultiDiag dialog

class CDiagBase;
class CBloqueDiag;


class CPropMultiDiag : public CPropertyPage
{
// Construction
public:
	CPropMultiDiag(CWnd* pParent = NULL);	// standard constructor

	virtual void setDiag(CDiagBase* pd, CBloqueDiag* pblqpadre);


// Dialog Data
	//{{AFX_DATA(CPropMultiDiag)
	enum { IDD = IDD_MULTIDIAG };
	CString	m_EtiqDiagPadre;
	CString	m_BlqIni;
	CString	m_BlqFin;
	CString	m_BlqDiagPadre;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CPropMultiDiag)
	afx_msg void OnPropDiagpadre();
	afx_msg void OnPropFin();
	afx_msg void OnPropInicio();
	afx_msg void OnPropBloquediag();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	
	CDiagBase* p_diag;
	CBloqueDiag* p_blqDiagPadre;
};

