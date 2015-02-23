// propdiag.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagrama dialog

#ifndef CDLGPROPDIAGRAMA_H
#define CDLGPROPDIAGRAMA_H

//#include "ListaBloques.h"

class CDiagBase;


class CDlgPropDiagrama : public CPropertyPage
{
// Construction
public:
	CDlgPropDiagrama(CWnd* pParent = NULL);	// standard constructor
	
	virtual void Construir(CDiagBase* pd);
    virtual BOOL OnInitDialog();
	
// Dialog Data
	//{{AFX_DATA(CDlgPropDiagrama)
	enum { IDD = IDD_PROP_DIAG };
	CButton	m_CambiaDLLDiag;
	CEdit	m_CtrlDLLDiag;
	CString	m_DLLDiag;
	CString	m_Fecha;
	CString	m_Etiq;
	BOOL	m_UsaDLLDiag;
	CString	m_FichLDD;
	CString	m_FichBin;
	CString	m_DirLibrerias;
	BOOL	m_PosHorizontal;
	//}}AFX_DATA


// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDlgPropDiagrama)
	afx_msg void OnUsadll();
	afx_msg void OnCambiaLdd();
	afx_msg void OnKillfocusDlldiag();
	afx_msg void OnCambiaDlldiag();
	afx_msg void OnKillfocusDirLibrerias();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	CDiagBase* p_diag;
};

#endif

