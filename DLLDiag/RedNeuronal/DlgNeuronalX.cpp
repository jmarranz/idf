// DlgNeuronalX.cpp : implementation file
//

#include "stdafx.h"
#include "..\dlldiag.h"
#include "DlgNeuronalX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgNeuronalX dialog


CDlgNeuronalX::CDlgNeuronalX(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNeuronalX::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNeuronalX)
	m_X = 0.0;
	m_X1 = 0.0;
	m_X2 = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgNeuronalX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNeuronalX)
	DDX_Text(pDX, IDC_X, m_X);
	DDX_Text(pDX, IDC_X1, m_X1);
	DDX_Text(pDX, IDC_X2, m_X2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgNeuronalX, CDialog)
	//{{AFX_MSG_MAP(CDlgNeuronalX)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgNeuronalX message handlers
