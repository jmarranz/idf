#if !defined(AFX_DLGCTRLADAP_X_H__0DDC22B3_2B28_11D3_829A_00609796AC40__INCLUDED_)
#define AFX_DLGCTRLADAP_X_H__0DDC22B3_2B28_11D3_829A_00609796AC40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgctrladap_x.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdapt_x dialog

class CDlgCtrlAdapt_x : public CDialog
{
// Construction
public:
	CDlgCtrlAdapt_x(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCtrlAdapt_x)
	enum { IDD = IDD_CTRLADAP_X };
	int		m_K;
	double	m_T;
	double	m_x;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCtrlAdapt_x)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCtrlAdapt_x)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCTRLADAP_X_H__0DDC22B3_2B28_11D3_829A_00609796AC40__INCLUDED_)
