// DlgMostrar2E.cpp : implementation file
//

#include "stdafx.h"
#include "..\DLLDiag.h"
#include "DlgMostrar2E.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgMostrar2E dialog


DlgMostrar2E::DlgMostrar2E(CWnd* pParent /*=NULL*/)
	: CDialog(DlgMostrar2E::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgMostrar2E)
	m_Etiq_E = _T("");
	m_Etiq_E2 = _T("");
	m_Valor_E = 0.0;
	m_Valor_E2 = 0.0;
	//}}AFX_DATA_INIT
}


void DlgMostrar2E::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgMostrar2E)
	DDX_Text(pDX, IDC_ETIQ_E, m_Etiq_E);
	DDX_Text(pDX, IDC_ETIQ_E2, m_Etiq_E2);
	DDX_Text(pDX, IDC_VALOR_E, m_Valor_E);
	DDX_Text(pDX, IDC_VALOR_E2, m_Valor_E2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgMostrar2E, CDialog)
	//{{AFX_MSG_MAP(DlgMostrar2E)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgMostrar2E message handlers
