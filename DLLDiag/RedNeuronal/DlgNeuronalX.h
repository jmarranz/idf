#if !defined(AFX_DLGNEURONALX_H__F45B7286_C8BD_47C3_9A22_70101CC8B789__INCLUDED_)
#define AFX_DLGNEURONALX_H__F45B7286_C8BD_47C3_9A22_70101CC8B789__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgNeuronalX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgNeuronalX dialog

class CDlgNeuronalX : public CDialog
{
// Construction
public:
	CDlgNeuronalX(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgNeuronalX)
	enum { IDD = IDD_NEURONAL_X };
	double	m_X;
	double	m_X1;
	double	m_X2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgNeuronalX)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgNeuronalX)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGNEURONALX_H__F45B7286_C8BD_47C3_9A22_70101CC8B789__INCLUDED_)
