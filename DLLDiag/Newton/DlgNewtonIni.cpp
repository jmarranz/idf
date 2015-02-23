// DNewtonIni.cpp: implementation of the CDlgNewtonIni class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgNewtonIni.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDlgNewtonIni dialog

CDlgNewtonIni::CDlgNewtonIni(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNewtonIni::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNewtonIni)
	m_emax = 0;
	m_h = 0;
	m_x0 = 0;
	//}}AFX_DATA_INIT
}

void CDlgNewtonIni::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNewtonIni)
	DDX_Text(pDX, IDC_EDITEMAX, m_emax);
	DDV_MinMaxDouble(pDX, m_emax, 0., 1.);
	DDX_Text(pDX, IDC_EDITH, m_h);
	DDV_MinMaxDouble(pDX, m_h, 0., 1.);
	DDX_Text(pDX, IDC_EDITX0, m_x0);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgNewtonIni, CDialog)
	//{{AFX_MSG_MAP(CDlgNewtonIni)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgNewtonIni message handlers

