// mensajel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMensajeLargo dialog

class CMensajeLargo : public CDialog
{
// Construction
public:
	CMensajeLargo(CWnd* pParent = NULL);	// standard constructor

	void Mensaje(const CString& men);

// Dialog Data
	//{{AFX_DATA(CMensajeLargo)
	enum { IDD = IDD_MENSAJE_EXT };
	CString	m_Texto;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CMensajeLargo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
