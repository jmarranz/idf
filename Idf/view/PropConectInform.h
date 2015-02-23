#if !defined(AFX_PROPCONECTINFORM_H__2032C253_1FF9_11D2_87E7_0000C057CDE3__INCLUDED_)
#define AFX_PROPCONECTINFORM_H__2032C253_1FF9_11D2_87E7_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropConectInform.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropConectInform dialog

class CPropConectInform : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropConectInform)

// Construction
public:
	CPropConectInform();
	~CPropConectInform();

// Dialog Data
	//{{AFX_DATA(CPropConectInform)
	enum { IDD = IDD_PROP_CONECT_INFORM };
	CString	m_Ayuda;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPropConectInform)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPropConectInform)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPCONECTINFORM_H__2032C253_1FF9_11D2_87E7_0000C057CDE3__INCLUDED_)
