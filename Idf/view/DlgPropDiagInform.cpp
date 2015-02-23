// DlgPropDiagInform.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "DlgPropDiagInform.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagInform property page

IMPLEMENT_DYNCREATE(CDlgPropDiagInform, CPropertyPage)

CDlgPropDiagInform::CDlgPropDiagInform() : CPropertyPage(CDlgPropDiagInform::IDD)
{
	//{{AFX_DATA_INIT(CDlgPropDiagInform)
	m_Ayuda = _T("");
	//}}AFX_DATA_INIT
}

CDlgPropDiagInform::~CDlgPropDiagInform()
{
}

void CDlgPropDiagInform::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropDiagInform)
	DDX_Text(pDX, IDC_AYUDA, m_Ayuda);
	DDV_MaxChars(pDX, m_Ayuda, 32700);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPropDiagInform, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgPropDiagInform)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagInform message handlers
