#if !defined(AFX_DLGPROPDIAGINFORM_H__5193DC03_10FA_11D2_87E5_0000C057CDE3__INCLUDED_)
#define AFX_DLGPROPDIAGINFORM_H__5193DC03_10FA_11D2_87E5_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgPropDiagInform.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagInform dialog

class CDlgPropDiagInform : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPropDiagInform)

// Construction
public:
	CDlgPropDiagInform();
	~CDlgPropDiagInform();

// Dialog Data
	//{{AFX_DATA(CDlgPropDiagInform)
	enum { IDD = IDD_PROP_DIAG_INFORM };
	CString	m_Ayuda;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgPropDiagInform)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgPropDiagInform)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPDIAGINFORM_H__5193DC03_10FA_11D2_87E5_0000C057CDE3__INCLUDED_)
