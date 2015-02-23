#if !defined(AFX_DLGMOSTRAR2E_H__7A499FC6_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
#define AFX_DLGMOSTRAR2E_H__7A499FC6_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgMostrar2E.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgMostrar2E dialog

class DlgMostrar2E : public CDialog
{
// Construction
public:
	DlgMostrar2E(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgMostrar2E)
	enum { IDD = IDD_CIEMAT_VER_2E };
	CString	m_Etiq_E;
	CString	m_Etiq_E2;
	double	m_Valor_E;
	double	m_Valor_E2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgMostrar2E)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgMostrar2E)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMOSTRAR2E_H__7A499FC6_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
