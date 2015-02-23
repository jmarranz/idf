// DlgRetro.h: interface for the CDlgNewtonRetro class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGRETRO_H__9F78B0A8_5AE1_48CF_A02B_647E6AF359B4__INCLUDED_)
#define AFX_DLGRETRO_H__9F78B0A8_5AE1_48CF_A02B_647E6AF359B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgNewtonRetro dialog

class CDlgNewtonRetro : public CDialog
{
// Construction
public:
	CDlgNewtonRetro(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgNewtonRetro)
	enum { IDD = IDD_NEWTONRETRO };
	double	m_emax;
	double	m_h;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Enviarted message map functions
	//{{AFX_MSG(CDlgNewtonRetro)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_DLGRETRO_H__9F78B0A8_5AE1_48CF_A02B_647E6AF359B4__INCLUDED_)
