// DlgSedimentacion.cpp : implementation file
//

#include "stdafx.h"
#include "..\DLLDiag.h"
#include "DlgSedimentacion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSedimentacion dialog


DlgSedimentacion::DlgSedimentacion(CWnd* pParent /*=NULL*/)
	: CDialog(DlgSedimentacion::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgSedimentacion)
	m_Csedim_fondo = 0.0;
	m_Csedim_susp = 0.0;
	m_Ssedim = 0.0;
	//}}AFX_DATA_INIT
}


void DlgSedimentacion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSedimentacion)
	DDX_Text(pDX, IDC_SEDIM_FONDO, m_Csedim_fondo);
	DDX_Text(pDX, IDC_SEDIM_SUSP, m_Csedim_susp);
	DDX_Text(pDX, IDC_SEDIM_S, m_Ssedim);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSedimentacion, CDialog)
	//{{AFX_MSG_MAP(DlgSedimentacion)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSedimentacion message handlers
