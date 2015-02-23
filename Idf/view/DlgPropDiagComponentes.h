#if !defined(AFX_DLGPROPDIAGCOMPONENTES_H__79A7C0E0_A206_4BCD_A5D3_65FC7ED5607D__INCLUDED_)
#define AFX_DLGPROPDIAGCOMPONENTES_H__79A7C0E0_A206_4BCD_A5D3_65FC7ED5607D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPropDiagComponentes.h : header file
//

#include "TreeCtrlDiagrama.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagComponentes dialog

class CDlgPropDiagComponentes : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPropDiagComponentes)

// Construction
public:
	CDlgPropDiagComponentes();
	~CDlgPropDiagComponentes();

	void Construir(CDiagBase* pDiag);



// Dialog Data
	//{{AFX_DATA(CDlgPropDiagComponentes)
	enum { IDD = IDD_PROP_DIAG_COMPONENTES };
	CTreeCtrl	m_Arbol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgPropDiagComponentes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgPropDiagComponentes)
	virtual BOOL OnInitDialog();
	afx_msg void OnRclickDiagArbol(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuComponenteProp();
	afx_msg void OnDblclkDiagArbol(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CDiagBase* p_diag;
	
	CTreeCtrlDiagrama m_TreeCtrlDiag;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROPDIAGCOMPONENTES_H__79A7C0E0_A206_4BCD_A5D3_65FC7ED5607D__INCLUDED_)
