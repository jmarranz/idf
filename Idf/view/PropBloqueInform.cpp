// PropBlqInform.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "PropBloqueInform.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropBloqueInform property page

IMPLEMENT_DYNCREATE(CPropBloqueInform, CPropertyPage)

CPropBloqueInform::CPropBloqueInform() : CPropertyPage(CPropBloqueInform::IDD)
{
	//{{AFX_DATA_INIT(CPropBloqueInform)
	m_ayuda = _T("");
	//}}AFX_DATA_INIT
}

CPropBloqueInform::~CPropBloqueInform()
{
}

void CPropBloqueInform::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropBloqueInform)
	DDX_Text(pDX, IDC_AYUDA, m_ayuda);
	DDV_MaxChars(pDX, m_ayuda, 32700);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropBloqueInform, CPropertyPage)
	//{{AFX_MSG_MAP(CPropBloqueInform)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropBloqueInform message handlers
