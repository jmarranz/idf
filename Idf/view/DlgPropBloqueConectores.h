#if !defined(AFX_DLGPROPBLOQUECONECTORES_H__EBD1B30E_F25F_4E76_B43C_2729AA0618D5__INCLUDED_)
#define AFX_DLGPROPBLOQUECONECTORES_H__EBD1B30E_F25F_4E76_B43C_2729AA0618D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPropBloqueConectores.h : header file
//

#include "TreeCtrlDiagrama.h"

class CBloque;


/////////////////////////////////////////////////////////////////////////////
// CDlgPropBloqueConectores dialog

class CDlgPropBloqueConectores : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPropBloqueConectores)

// Construction
public:
	CDlgPropBloqueConectores();
	~CDlgPropBloqueConectores();

	void Construir(CBloque* pBloque);


// Dialog Data
	//{{AFX_DATA(CDlgPropBloqueConectores)
	enum { IDD = IDD_PROP_BLOQUE_CONECTORES };
	CTreeCtrl	m_Arbol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgPropBloqueConectores)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgPropBloqueConectores)
	virtual BOOL OnInitDialog();
	afx_msg void OnMenuComponenteProp();
	afx_msg void OnRclickBloqueArbol(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkBloqueArbol(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CBloque* p_bloque;

	CTreeCtrlDiagrama m_TreeCtrlDiag;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROPBLOQUECONECTORES_H__EBD1B30E_F25F_4E76_B43C_2729AA0618D5__INCLUDED_)
