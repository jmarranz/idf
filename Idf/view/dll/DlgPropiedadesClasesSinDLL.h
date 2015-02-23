#if !defined(AFX_DLGPROPIEDADESCLASESSINDLL_H__4E11BD24_3FF9_44F6_99F1_896A0881C249__INCLUDED_)
#define AFX_DLGPROPIEDADESCLASESSINDLL_H__4E11BD24_3FF9_44F6_99F1_896A0881C249__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPropiedadesClasesSinDLL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPropiedadesClasesSinDLL dialog

class CDiagBase;
class CTreeCtrlDiagCodigo;
class CAnalisisClasesSinDLL;


class CDlgPropiedadesClasesSinDLL : public CDialog
{
// Construction
public:
	CDlgPropiedadesClasesSinDLL(CDiagBase* pDiag,CWnd* pParent = NULL);   // standard constructor
	~CDlgPropiedadesClasesSinDLL();

	void Construir();
	void Destruir();

// Dialog Data
	//{{AFX_DATA(CDlgPropiedadesClasesSinDLL)
	enum { IDD = IDD_PROP_CLASES_SIN_DLL };
	CTreeCtrl	m_arbol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPropiedadesClasesSinDLL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPropiedadesClasesSinDLL)
	virtual BOOL OnInitDialog();
	afx_msg void OnGenerarCodigo();
	afx_msg void OnRclickPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClasedllGenerarCodigo();
	afx_msg void OnDblclkPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CDiagBase* p_diag;
	CAnalisisClasesSinDLL* p_clasesDiag;

	CTreeCtrlDiagCodigo* p_TreeCtrlDiag;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROPIEDADESCLASESSINDLL_H__4E11BD24_3FF9_44F6_99F1_896A0881C249__INCLUDED_)
