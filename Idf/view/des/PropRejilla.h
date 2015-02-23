// propreji.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropRejilla dialog

class CPropRejilla : public CDialog
{
// Construction
public:
	CPropRejilla(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPropRejilla)
	enum { IDD = IDD_PROP_REJILLA };
	BOOL	m_ForzCoor;
	UINT	m_IncX;
	UINT	m_IncY;
	BOOL	m_VerRejilla;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CPropRejilla)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
