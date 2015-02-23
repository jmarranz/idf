#if !defined(AFX_DLGMOSTRARE_H__7A499FC5_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
#define AFX_DLGMOSTRARE_H__7A499FC5_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgMostrarE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgMostrarE dialog

class DlgMostrarE : public CDialog
{
// Construction
public:
	DlgMostrarE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgMostrarE)
	enum { IDD = IDD_CIEMAT_VER_E };
	CString	m_Etiq_E;
	double	m_Valor_E;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgMostrarE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgMostrarE)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMOSTRARE_H__7A499FC5_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
