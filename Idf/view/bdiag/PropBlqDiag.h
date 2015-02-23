// pblqdiag.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropBlqDiag dialog

#ifndef CPROPBLQDIAG_H
#define CPROPBLQDIAG_H

class CBloqueDiag;
class CBloque;


class CPropBlqDiag : public CPropertyPage
{
// Construction
public:
	CPropBlqDiag(CWnd* pParent = NULL);	// standard constructor

	virtual void setBloque(CBloqueDiag* pb);  
	virtual  BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(CPropBlqDiag)
	enum { IDD = IDD_PROP_BLOQUE_DIAG };
	CComboBox	m_ctrlListaBloquesIni;
	CComboBox	m_ctrlListaBloquesFin;
	CComboBox	m_CtrlVerSubDiag;
	CComboBox	m_CtrlTipoFichHijo;
	CButton	m_CtrlPropInicio;
	CButton	m_CtrlPropFin;
	CButton	m_CtrlPropDiagHijo;
	CString	m_Fecha;
	CString	m_EtiqDiagHijo;
	CString	m_FichHijo;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CPropBlqDiag)
	afx_msg void OnKillfocusFichHijo();
	afx_msg void OnCambiaHijo();
	afx_msg void OnPropDiaghijo();
	afx_msg void OnPropInicio();
	afx_msg void OnPropFin();
	afx_msg void OnSelchangeHijotipofich();
	afx_msg void OnSelchangeVentHijo();
	afx_msg void OnSelchangeBloqueInicio();
	afx_msg void OnSelchangeBloqueFin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	int m_mostrarSubDiag;
	BOOL m_esLDD;

	CBloque* p_bloqueIni;
	CBloque* p_bloqueFin;

protected:
	CBloqueDiag* p_bloque;
};


#endif

