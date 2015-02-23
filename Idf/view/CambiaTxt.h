// cambiatx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCambiaTxt dialog

class CCambiaTxt : public CDialog
{
// Construction
public:
	CCambiaTxt(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCambiaTxt)
	enum { IDD = IDD_NUEVOTXT };
	CString	m_Texto;
	CString	m_Titulo;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CCambiaTxt)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
