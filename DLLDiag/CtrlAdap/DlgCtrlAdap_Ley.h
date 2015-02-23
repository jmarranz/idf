#if !defined(AFX_DLGCTRLADAP_LEY_H__AE7802C3_2D61_11D3_829B_00609796AC40__INCLUDED_)
#define AFX_DLGCTRLADAP_LEY_H__AE7802C3_2D61_11D3_829B_00609796AC40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCtrlAdap_Ley.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_Ley dialog

class CDlgCtrlAdap_Ley : public CDialog
{
// Construction
public:
	CDlgCtrlAdap_Ley(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCtrlAdap_Ley)
	enum { IDD = IDD_CTRLADAP_LEY };
	double	m_Tau;
	double	m_MaxE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCtrlAdap_Ley)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCtrlAdap_Ley)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCTRLADAP_LEY_H__AE7802C3_2D61_11D3_829B_00609796AC40__INCLUDED_)
