#if !defined(AFX_CDlgGeneracionCodigoConDLL_H__A1DD8763_56CD_11D2_85F9_0000C05BCDE3__INCLUDED_)
#define AFX_CDlgGeneracionCodigoConDLL_H__A1DD8763_56CD_11D2_85F9_0000C05BCDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CDlgGeneracionCodigoConDLL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgGeneracionCodigoConDLL dialog

#include "DlgGeneracionCodigoDLL.h"



class CDlgGeneracionCodigoConDLL : public CDlgGeneracionCodigoDLL
{
// Construction
public:
	CDlgGeneracionCodigoConDLL(CDiagBase* pdiag,CWnd* pParent = NULL);   // standard constructor
	CDlgGeneracionCodigoConDLL(CDiagBase* pdiag,const CString& dllDiag,CWnd* pParent = NULL);
	~CDlgGeneracionCodigoConDLL();

	virtual void SetCabeceras(const CString& codigo);
	virtual void SetImplementacion(const CString& codigo);

	void AnalizarBloque(const CString& SClaseBloque);
	void AnalizarObjCom(const CString& SClaseCom);

// Dialog Data
	//{{AFX_DATA(CDlgGeneracionCodigoConDLL)
	enum { IDD = IDD_ANALISIS_DLL };
	CEdit	m_edit_implementacion;
	CEdit	m_edit_cabeceras;
	CString	m_DLLDiag;
	CString	m_cabeceras;
	CString	m_implementacion;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgGeneracionCodigoConDLL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgGeneracionCodigoConDLL)
	virtual BOOL OnInitDialog();
	afx_msg void OnSalvarH();
	afx_msg void OnSalvarCpp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDlgGeneracionCodigoConDLL_H__A1DD8763_56CD_11D2_85F9_0000C05BCDE3__INCLUDED_)
