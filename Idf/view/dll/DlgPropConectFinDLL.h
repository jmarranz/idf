#if !defined(AFX_DLGPROPCONECTFINDLL_H__40CB8D01_22B0_40AA_8D9C_C08628A5FFDC__INCLUDED_)
#define AFX_DLGPROPCONECTFINDLL_H__40CB8D01_22B0_40AA_8D9C_C08628A5FFDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPropConectFinDLL.h : header file
//

#include "DlgPropConectExtremoDLL.h"


/////////////////////////////////////////////////////////////////////////////
// CDlgPropConectFinDLL dialog

class CDlgPropConectFinDLL : public CDlgPropConectExtremoDLL
{
	DECLARE_DYNCREATE(CDlgPropConectFinDLL)

// Construction
public:
	CDlgPropConectFinDLL();
	~CDlgPropConectFinDLL();

	virtual CString getClaseCom();
	virtual void setClaseCom(const CString& claseCom);
	virtual CComboBox* getListaClaseCom();

// Dialog Data
	//{{AFX_DATA(CDlgPropConectFinDLL)
	enum { IDD = IDD_PROP_CONECT_FIN_DLL };
	CComboBox	m_CtrlClaseCom;
	CString	m_ClaseCom;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgPropConectFinDLL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgPropConectFinDLL)
	afx_msg void OnKillfocusClaseCom();
	afx_msg void OnListarClases();
	afx_msg void OnInspeccionCodigo();
	afx_msg void OnGeneracionCodigo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROPCONECTFINDLL_H__40CB8D01_22B0_40AA_8D9C_C08628A5FFDC__INCLUDED_)
