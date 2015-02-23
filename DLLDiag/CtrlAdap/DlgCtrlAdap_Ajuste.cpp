// DlgCtrlAdap_Ajuste.cpp : implementation file
//

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgCtrlAdap_Ajuste.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_Ajuste dialog


CDlgCtrlAdap_Ajuste::CDlgCtrlAdap_Ajuste(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCtrlAdap_Ajuste::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCtrlAdap_Ajuste)
	m_Ajuste = false;
	//}}AFX_DATA_INIT
}


void CDlgCtrlAdap_Ajuste::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCtrlAdap_Ajuste)
	DDX_Check(pDX, IDC_AJUSTE, m_Ajuste);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCtrlAdap_Ajuste, CDialog)
	//{{AFX_MSG_MAP(CDlgCtrlAdap_Ajuste)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_Ajuste message handlers
