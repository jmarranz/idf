// DlgOperacBRetro.h: interface for the COperacBRetro class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGOPERACBRETRO_H__B1B110AA_147F_4339_933E_F8D73ECA1D00__INCLUDED_)
#define AFX_DLGOPERACBRETRO_H__B1B110AA_147F_4339_933E_F8D73ECA1D00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COperacBRetro dialog


class CBloqueExe;


class COperacBRetro : public CDialog
{
// Construction
public:
	COperacBRetro(CWnd* pParent = NULL);	// standard constructor

	virtual void setBloque(CBloqueExe* blq);

// Dialog Data
	//{{AFX_DATA(COperacBRetro)
	enum { IDD = IDD_OPERAC_BRETRO };
	CString	m_ConectEtiq;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(COperacBRetro)
	afx_msg void OnRetroanota();
	afx_msg void OnEnviarRetroano();
	afx_msg void OnRecibirRetroano();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	CBloqueExe* p_bloque;
};


#endif // !defined(AFX_DLGOPERACBRETRO_H__B1B110AA_147F_4339_933E_F8D73ECA1D00__INCLUDED_)
