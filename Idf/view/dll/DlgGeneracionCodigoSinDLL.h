#if !defined(AFX_CDlgGeneracionCodigoSinDLL_H__60B27A93_5AD3_11D2_891B_00609769F95C__INCLUDED_)
#define AFX_CDlgGeneracionCodigoSinDLL_H__60B27A93_5AD3_11D2_891B_00609769F95C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CDlgGeneracionCodigoSinDLL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgGeneracionCodigoSinDLL dialog


#include "DlgGeneracionCodigoDLL.h"


class CDlgGeneracionCodigoSinDLL : public CDlgGeneracionCodigoDLL
{
// Construction
public:
	CDlgGeneracionCodigoSinDLL(CDiagBase* pdiag,CWnd* pParent = NULL);   // standard constructor
	~CDlgGeneracionCodigoSinDLL();

	virtual void SetCabeceras(const CString& codigo);
	virtual void SetImplementacion(const CString& codigo);

	void AnalizarBloque(const CString& SClaseBloque);
	void AnalizarObjCom(const CString& SClaseCom);


// Dialog Data
	//{{AFX_DATA(CDlgGeneracionCodigoSinDLL)
	enum { IDD = IDD_ANALISIS_CLASE };
	CString	m_cabeceras;
	CString	m_implementacion;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgGeneracionCodigoSinDLL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgGeneracionCodigoSinDLL)
	afx_msg void OnSalvarCpp();
	afx_msg void OnSalvarH();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDlgGeneracionCodigoSinDLL_H__60B27A93_5AD3_11D2_891B_00609769F95C__INCLUDED_)
