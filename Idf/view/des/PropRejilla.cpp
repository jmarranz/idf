// propreji.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "PropRejilla.h"


/////////////////////////////////////////////////////////////////////////////
// CPropRejilla dialog


CPropRejilla::CPropRejilla(CWnd* pParent /*=NULL*/)
	: CDialog(CPropRejilla::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropRejilla)
	m_ForzCoor = false;
	m_IncX = 0;
	m_IncY = 0;
	m_VerRejilla = false;
	//}}AFX_DATA_INIT
}

void CPropRejilla::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropRejilla)
	DDX_Check(pDX, IDC_FORZCOOR, m_ForzCoor);
	DDX_Text(pDX, IDC_INCX, m_IncX);
	DDV_MinMaxUInt(pDX, m_IncX, 1, 210);
	DDX_Text(pDX, IDC_INCY, m_IncY);
	DDV_MinMaxUInt(pDX, m_IncY, 1, 297);
	DDX_Check(pDX, IDC_VERREJILLA, m_VerRejilla);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropRejilla, CDialog)
	//{{AFX_MSG_MAP(CPropRejilla)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPropRejilla message handlers
