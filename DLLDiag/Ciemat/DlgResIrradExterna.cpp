// DlgResIrradExterna.cpp : implementation file
//

#include "stdafx.h"
#include "..\DLLDiag.h"
#include "DlgResIrradExterna.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgResIrradExterna dialog


DlgResIrradExterna::DlgResIrradExterna(CWnd* pParent /*=NULL*/)
	: CDialog(DlgResIrradExterna::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgResIrradExterna)
	m_Eext_aire = 0.0;
	m_Eext_inm_total = 0.0;
	m_Eext_orilla = 0.0;
	m_Eext_suelo = 0.0;
	//}}AFX_DATA_INIT
}


void DlgResIrradExterna::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgResIrradExterna)
	DDX_Text(pDX, IDC_INMERSION_AIRE, m_Eext_aire);
	DDX_Text(pDX, IDC_INMERSION_BANO, m_Eext_inm_total);
	DDX_Text(pDX, IDC_IRRADIACION_ORILLA, m_Eext_orilla);
	DDX_Text(pDX, IDC_IRRADIACION_SUELO, m_Eext_suelo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgResIrradExterna, CDialog)
	//{{AFX_MSG_MAP(DlgResIrradExterna)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgResIrradExterna message handlers
