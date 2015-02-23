#if !defined(AFX_DLGPROPCONECTINICIODLL_H__729F20B6_2F1A_41F3_8987_CF85127EA38D__INCLUDED_)
#define AFX_DLGPROPCONECTINICIODLL_H__729F20B6_2F1A_41F3_8987_CF85127EA38D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPropConectInicioDLL.h : header file
//

#include "DlgPropConectExtremoDLL.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgPropConectInicioDLL dialog

class CDlgPropConectInicioDLL : public CDlgPropConectExtremoDLL
{
	DECLARE_DYNCREATE(CDlgPropConectInicioDLL)

// Construction
public:
	CDlgPropConectInicioDLL();
	~CDlgPropConectInicioDLL();

	virtual CString getClaseCom();
	virtual void setClaseCom(const CString& claseCom);
	virtual CComboBox* getListaClaseCom();

// Dialog Data
	//{{AFX_DATA(CDlgPropConectInicioDLL)
	enum { IDD = IDD_PROP_CONECT_INICIO_DLL };
	CComboBox	m_CtrlClaseCom;
	CString	m_ClaseCom;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgPropConectInicioDLL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgPropConectInicioDLL)
	afx_msg void OnKillfocusClaseCom();
	afx_msg void OnListarClases();
	afx_msg void OnInspeccionCodigo();
	afx_msg void OnGeneracionCodigo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROPCONECTINICIODLL_H__729F20B6_2F1A_41F3_8987_CF85127EA38D__INCLUDED_)
