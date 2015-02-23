#if !defined(AFX_PROPBLQINFORM_H__94ADF374_1018_11D2_87E5_0000C057CDE3__INCLUDED_)
#define AFX_PROPBLQINFORM_H__94ADF374_1018_11D2_87E5_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropBlqInform.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropBloqueInform dialog

class CPropBloqueInform : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropBloqueInform)

// Construction
public:
	CPropBloqueInform();
	~CPropBloqueInform();

// Dialog Data
	//{{AFX_DATA(CPropBloqueInform)
	enum { IDD = IDD_PROP_BLOQUE_INFORM };
	CString	m_ayuda;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPropBloqueInform)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPropBloqueInform)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPBLQINFORM_H__94ADF374_1018_11D2_87E5_0000C057CDE3__INCLUDED_)
