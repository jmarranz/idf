#if !defined(AFX_DLGPARAMENTRADAIRRADEXT_H__7A499FC3_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
#define AFX_DLGPARAMENTRADAIRRADEXT_H__7A499FC3_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// dlgparamentradairradext.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgParamEntradaIrradExt dialog

class DlgParamEntradaIrradExt : public CDialog
{
// Construction
public:
	DlgParamEntradaIrradExt(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgParamEntradaIrradExt)
	enum { IDD = IDD_CIEMAT_PARAMIRRADEXT };
	double	m_Cw;
	double	m_L;
	double	m_DFinm_b;
	double	m_DFinm_g;
	double	m_DFaire_b;
	double	m_DFaire_g;
	double	m_DFgr_b;
	double	m_DFgr_g;
	double	m_tb;
	double	m_Fb_b;
	double	m_Fb_g;
	double	m_Ofinm;
	double	m_Oforilla;
	double	m_Wpiel;
	double	m_d;
	double	m_Ca;
	double	m_Ofaire_ext;
	double	m_Ofaire_int;
	double	m_Cso;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgParamEntradaIrradExt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgParamEntradaIrradExt)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPARAMENTRADAIRRADEXT_H__7A499FC3_5CF7_11D2_87F7_0000C057CDE3__INCLUDED_)
