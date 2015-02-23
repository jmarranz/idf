// dlgctrladap_x.cpp : implementation file
//

#include "stdafx.h"
#include "..\dlldiag.h"

#include "dlgctrladap_x.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdapt_x dialog


CDlgCtrlAdapt_x::CDlgCtrlAdapt_x(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCtrlAdapt_x::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCtrlAdapt_x)
	m_K = 0;
	m_T = 0.0;
	m_x = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgCtrlAdapt_x::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCtrlAdapt_x)
	DDX_Text(pDX, IDC_EDIT_K, m_K);
	DDX_Text(pDX, IDC_EDIT_T, m_T);
	DDX_Text(pDX, IDC_EDIT_X, m_x);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCtrlAdapt_x, CDialog)
	//{{AFX_MSG_MAP(CDlgCtrlAdapt_x)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCtrlAdapt_x message handlers
