// DlgNewton.cpp: implementation of the CDlgNewton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgNewton.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// CDlgNewton dialog

CDlgNewton::CDlgNewton(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNewton::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNewton)
	m_x = 0;
	m_fx = 0;
	m_e = 0;
	//}}AFX_DATA_INIT
}

void CDlgNewton::Mensaje(CString& men)
{
	texto = men;
}

BOOL CDlgNewton::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetDlgItemText( IDC_TEXTOMEN, (LPCSTR)texto );	
	return true;
}



void CDlgNewton::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNewton)
	DDX_Control(pDX, IDC_TEXTOMEN, m_men);
	DDX_Text(pDX, IDC_EDITX, m_x);
	DDX_Text(pDX, IDC_EDITFX, m_fx);
	DDX_Text(pDX, IDC_EDITERROR, m_e);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgNewton, CDialog)
	//{{AFX_MSG_MAP(CDlgNewton)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgNewton message handlers
