#if !defined(AFX_DLGPROPIEDADESDLL_H__020BC1D9_8F95_4418_A272_4368A3993B2B__INCLUDED_)
#define AFX_DLGPROPIEDADESDLL_H__020BC1D9_8F95_4418_A272_4368A3993B2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPropiedadesDLL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPropiedadesClasesConDLL dialog

class CDiagBase;
class CTreeCtrlDiagCodigo;
class CAnalisisClasesConDLL;


class CDlgPropiedadesClasesConDLL : public CDialog
{
// Construction
public:
	CDlgPropiedadesClasesConDLL(CDiagBase* pDiag,CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPropiedadesClasesConDLL();

	void Construir();
	void Destruir();


// Dialog Data
	//{{AFX_DATA(CDlgPropiedadesClasesConDLL)
	enum { IDD = IDD_PROP_CLASES_CON_DLL };
	CTreeCtrl	m_arbol;
	CString	m_DLLDiag;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPropiedadesClasesConDLL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPropiedadesClasesConDLL)
	afx_msg void OnCambiaDll();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusDlldiagrama();
	afx_msg void OnGenerarCodigo();
	afx_msg void OnRclickPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClasedllGenerarCodigo();
	afx_msg void OnDblclkPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CDiagBase* p_diag;
	CAnalisisClasesConDLL* p_clasesDiag;

	CTreeCtrlDiagCodigo* p_TreeCtrlDiag;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROPIEDADESDLL_H__020BC1D9_8F95_4418_A272_4368A3993B2B__INCLUDED_)
