// DlgNewton.h: interface for the CDlgNewton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGNEWTON_H__0157C59C_55CE_4B2D_A3DF_2B03579FC015__INCLUDED_)
#define AFX_DLGNEWTON_H__0157C59C_55CE_4B2D_A3DF_2B03579FC015__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CDlgNewton dialog

class CDlgNewton : public CDialog
{
// Construction
public:
	CDlgNewton(CWnd* pParent = NULL);	// standard constructor
	BOOL OnInitDialog();
	void Mensaje(CString& men);
// Dialog Data
	//{{AFX_DATA(CDlgNewton)
	enum { IDD = IDD_NEWTON };
	CStatic	m_men;
	double	m_x;
	double	m_fx;
	CString texto;
	double	m_e;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Enviarted message map functions
	//{{AFX_MSG(CDlgNewton)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif // !defined(AFX_DLGNEWTON_H__0157C59C_55CE_4B2D_A3DF_2B03579FC015__INCLUDED_)
