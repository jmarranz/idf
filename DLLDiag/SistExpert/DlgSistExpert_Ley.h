#if !defined(AFX_DLGSISTEXPERT_LEY_H__A90E5CB1_38F8_11D3_82B8_00609796AC40__INCLUDED_)
#define AFX_DLGSISTEXPERT_LEY_H__A90E5CB1_38F8_11D3_82B8_00609796AC40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSistExpert_Ley.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgSistExpert_Ley dialog

class DlgSistExpert_Ley : public CDialog
{
// Construction
public:
	DlgSistExpert_Ley(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSistExpert_Ley)
	enum { IDD = IDD_SISTEXPERT_LEY };
	double	m_MaxE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSistExpert_Ley)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgSistExpert_Ley)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSISTEXPERT_LEY_H__A90E5CB1_38F8_11D3_82B8_00609796AC40__INCLUDED_)
