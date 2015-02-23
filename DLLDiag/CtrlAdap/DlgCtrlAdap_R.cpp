// DlgCtrlAdap_R.cpp : implementation file
//

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgCtrlAdap_R.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_R dialog


CDlgCtrlAdap_R::CDlgCtrlAdap_R(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCtrlAdap_R::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCtrlAdap_R)
	m_Kr = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgCtrlAdap_R::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCtrlAdap_R)
	DDX_Text(pDX, IDC_EDIT_KR, m_Kr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCtrlAdap_R, CDialog)
	//{{AFX_MSG_MAP(CDlgCtrlAdap_R)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdap_R message handlers
