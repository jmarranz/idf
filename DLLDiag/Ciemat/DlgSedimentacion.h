#if !defined(AFX_DLGSEDIMENTACION_H__7A499FC7_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
#define AFX_DLGSEDIMENTACION_H__7A499FC7_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSedimentacion.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgSedimentacion dialog

class DlgSedimentacion : public CDialog
{
// Construction
public:
	DlgSedimentacion(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSedimentacion)
	enum { IDD = IDD_CIEMAT_SEDIMENTACION };
	double	m_Csedim_fondo;
	double	m_Csedim_susp;
	double	m_Ssedim;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSedimentacion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgSedimentacion)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSEDIMENTACION_H__7A499FC7_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
