// DlgSistExpert_Ley.cpp : implementation file
//

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgSistExpert_Ley.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSistExpert_Ley dialog


DlgSistExpert_Ley::DlgSistExpert_Ley(CWnd* pParent /*=NULL*/)
	: CDialog(DlgSistExpert_Ley::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgSistExpert_Ley)
	m_MaxE = 0.0;
	//}}AFX_DATA_INIT
}


void DlgSistExpert_Ley::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSistExpert_Ley)
	DDX_Text(pDX, IDC_EDIT_ME, m_MaxE);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSistExpert_Ley, CDialog)
	//{{AFX_MSG_MAP(DlgSistExpert_Ley)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSistExpert_Ley message handlers
