#if !defined(AFX_DLGCTRLADAP_R_H__0DDC22B4_2B28_11D3_829A_00609796AC40__INCLUDED_)
#define AFX_DLGCTRLADAP_R_H__0DDC22B4_2B28_11D3_829A_00609796AC40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCtrlAdap_R.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_R dialog

class CDlgCtrlAdap_R : public CDialog
{
// Construction
public:
	CDlgCtrlAdap_R(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCtrlAdap_R)
	enum { IDD = IDD_CTRLADAP_R };
	double	m_Kr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCtrlAdap_R)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCtrlAdap_R)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCTRLADAP_R_H__0DDC22B4_2B28_11D3_829A_00609796AC40__INCLUDED_)
