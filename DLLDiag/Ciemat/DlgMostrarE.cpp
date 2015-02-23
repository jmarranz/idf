// DlgMostrarE.cpp : implementation file
//

#include "stdafx.h"
#include "..\DLLDiag.h"
#include "DlgMostrarE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgMostrarE dialog


DlgMostrarE::DlgMostrarE(CWnd* pParent /*=NULL*/)
	: CDialog(DlgMostrarE::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgMostrarE)
	m_Etiq_E = _T("");
	m_Valor_E = 0.0;
	//}}AFX_DATA_INIT
}


void DlgMostrarE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgMostrarE)
	DDX_Text(pDX, IDC_ETIQ_E, m_Etiq_E);
	DDX_Text(pDX, IDC_VALOR_E, m_Valor_E);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgMostrarE, CDialog)
	//{{AFX_MSG_MAP(DlgMostrarE)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgMostrarE message handlers
