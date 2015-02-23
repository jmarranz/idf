// cambiatx.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "CambiaTxt.h"


/////////////////////////////////////////////////////////////////////////////
// CCambiaTxt dialog


CCambiaTxt::CCambiaTxt(CWnd* pParent /*=NULL*/)
	: CDialog(CCambiaTxt::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCambiaTxt)
	m_Texto = "";
	m_Titulo = "";
	//}}AFX_DATA_INIT
}

void CCambiaTxt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCambiaTxt)
	DDX_Text(pDX, IDC_TEXTO, m_Texto);
	DDX_Text(pDX, IDC_TITULO, m_Titulo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCambiaTxt, CDialog)
	//{{AFX_MSG_MAP(CCambiaTxt)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCambiaTxt message handlers
