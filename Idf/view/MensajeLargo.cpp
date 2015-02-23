// mensajel.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "MensajeLargo.h"


/////////////////////////////////////////////////////////////////////////////
// CMensajeLargo dialog


CMensajeLargo::CMensajeLargo(CWnd* pParent /*=NULL*/)
	: CDialog(CMensajeLargo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMensajeLargo)
	m_Texto = "";
	//}}AFX_DATA_INIT
}

void CMensajeLargo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMensajeLargo)
	DDX_Text(pDX, IDC_TEXTO, m_Texto);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMensajeLargo, CDialog)
	//{{AFX_MSG_MAP(CMensajeLargo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMensajeLargo message handlers

void CMensajeLargo::Mensaje(const CString& men)
{
	m_Texto	= men;
}

