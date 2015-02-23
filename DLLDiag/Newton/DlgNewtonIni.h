// DNewtonIni.h: interface for the CDlgNewtonIni class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DNEWTONINI_H__17CDD2E1_0CFE_4ACC_AF56_1476CACFCC08__INCLUDED_)
#define AFX_DNEWTONINI_H__17CDD2E1_0CFE_4ACC_AF56_1476CACFCC08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgNewtonIni dialog

class CDlgNewtonIni : public CDialog
{
// Construction
public:
	CDlgNewtonIni(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgNewtonIni)
	enum { IDD = IDD_NEWTONINI };
	double	m_emax;
	double	m_h;
	double	m_x0;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Enviarted message map functions
	//{{AFX_MSG(CDlgNewtonIni)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#endif // !defined(AFX_DNEWTONINI_H__17CDD2E1_0CFE_4ACC_AF56_1476CACFCC08__INCLUDED_)
