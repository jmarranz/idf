#if !defined(AFX_DLGRESIRRADEXTERNA_H__7A499FC4_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
#define AFX_DLGRESIRRADEXTERNA_H__7A499FC4_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgResIrradExterna.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgResIrradExterna dialog

class DlgResIrradExterna : public CDialog
{
// Construction
public:
	DlgResIrradExterna(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgResIrradExterna)
	enum { IDD = IDD_CIEMAT_RESIRRAD_EXTERNA };
	double	m_Eext_aire;
	double	m_Eext_inm_total;
	double	m_Eext_orilla;
	double	m_Eext_suelo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgResIrradExterna)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgResIrradExterna)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRESIRRADEXTERNA_H__7A499FC4_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
