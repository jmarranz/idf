// dcancel.h : header file
//

class CDiagExe;

/////////////////////////////////////////////////////////////////////////////
// CDlgCancelAuto dialog

class CDlgCancelAuto : public CDialog
{
// Construction
public:
	CDlgCancelAuto(CWnd* pParent = NULL);	// standard constructor
	BOOL Crear(CDiagExe* diag);

// Dialog Data
	//{{AFX_DATA(CDlgCancelAuto)
	enum { IDD = IDD_CANCEL_AUTO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDlgCancelAuto)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	CDiagExe* p_diag;

};
