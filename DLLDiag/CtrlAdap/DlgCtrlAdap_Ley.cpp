// DlgCtrlAdap_Ley.cpp : implementation file
//

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgCtrlAdap_Ley.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_Ley dialog


CDlgCtrlAdap_Ley::CDlgCtrlAdap_Ley(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCtrlAdap_Ley::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCtrlAdap_Ley)
	m_Tau = 0.0;
	m_MaxE = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgCtrlAdap_Ley::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCtrlAdap_Ley)
	DDX_Text(pDX, IDC_EDIT_TAU, m_Tau);
	DDX_Text(pDX, IDC_EDIT_ME, m_MaxE);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCtrlAdap_Ley, CDialog)
	//{{AFX_MSG_MAP(CDlgCtrlAdap_Ley)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_Ley message handlers
