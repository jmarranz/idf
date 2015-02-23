#if !defined(AFX_DLGCTRLADAP_AJUSTE_H__A90E5CB4_38F8_11D3_82B8_00609796AC40__INCLUDED_)
#define AFX_DLGCTRLADAP_AJUSTE_H__A90E5CB4_38F8_11D3_82B8_00609796AC40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCtrlAdap_Ajuste.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_Ajuste dialog

class CDlgCtrlAdap_Ajuste : public CDialog
{
// Construction
public:
	CDlgCtrlAdap_Ajuste(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCtrlAdap_Ajuste)
	enum { IDD = IDD_CTRLADAP_AJUSTE };
	BOOL	m_Ajuste;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCtrlAdap_Ajuste)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCtrlAdap_Ajuste)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCTRLADAP_AJUSTE_H__A90E5CB4_38F8_11D3_82B8_00609796AC40__INCLUDED_)
