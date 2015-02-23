// DlgRetro.cpp: implementation of the CDlgNewtonRetro class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgNewtonRetro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDlgNewtonRetro dialog


CDlgNewtonRetro::CDlgNewtonRetro(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNewtonRetro::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNewtonRetro)
	m_emax = 0;
	m_h = 0;
	//}}AFX_DATA_INIT
}

void CDlgNewtonRetro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNewtonRetro)
	DDX_Text(pDX, IDC_EDITEMAX, m_emax);
	DDV_MinMaxDouble(pDX, m_emax, 0., 1.);
	DDX_Text(pDX, IDC_EDITH, m_h);
	DDV_MinMaxDouble(pDX, m_h, 0., 1.);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgNewtonRetro, CDialog)
	//{{AFX_MSG_MAP(CDlgNewtonRetro)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgNewtonRetro message handlers
