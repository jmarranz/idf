// PropConectInform.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "PropConectInform.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropConectInform property page

IMPLEMENT_DYNCREATE(CPropConectInform, CPropertyPage)

CPropConectInform::CPropConectInform() : CPropertyPage(CPropConectInform::IDD)
{
	//{{AFX_DATA_INIT(CPropConectInform)
	m_Ayuda = _T("");
	//}}AFX_DATA_INIT
}

CPropConectInform::~CPropConectInform()
{
}

void CPropConectInform::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropConectInform)
	DDX_Text(pDX, IDC_TEXTO_AYUDA, m_Ayuda);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropConectInform, CPropertyPage)
	//{{AFX_MSG_MAP(CPropConectInform)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropConectInform message handlers
