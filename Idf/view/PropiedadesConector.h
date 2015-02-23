#if !defined(AFX_PROPIEDADESCONECTOR_H__5CE5DF0F_E540_43E7_B74E_C26CA1AAF169__INCLUDED_)
#define AFX_PROPIEDADESCONECTOR_H__5CE5DF0F_E540_43E7_B74E_C26CA1AAF169__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropiedadesConector.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropiedadesConector
class CConect;
class CConectExtremo;

class CPropiedadesConector : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropiedadesConector)

// Construction
public:
	CPropiedadesConector(CConect* pcon, UINT iSelectPage = 0);

	virtual CPropertyPage* PropGenerales(CPropertyPage* pdlg);
	virtual CPropertyPage* PropInicio(CPropertyPage* pdlg);
	virtual CPropertyPage* PropFin(CPropertyPage* pdlg);
	virtual CPropertyPage* PropInformacion(CPropertyPage* pdlg);


	virtual int DoModal(); 

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropiedadesConector)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropiedadesConector();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPropiedadesConector)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CConect* p_conect;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPIEDADESCONECTOR_H__5CE5DF0F_E540_43E7_B74E_C26CA1AAF169__INCLUDED_)
