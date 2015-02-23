// DlgPropDiagComponentes.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "DlgPropDiagComponentes.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagComponentes property page

IMPLEMENT_DYNCREATE(CDlgPropDiagComponentes, CPropertyPage)

CDlgPropDiagComponentes::CDlgPropDiagComponentes() : CPropertyPage(CDlgPropDiagComponentes::IDD)
{
	//{{AFX_DATA_INIT(CDlgPropDiagComponentes)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	p_diag = NULL;
}

CDlgPropDiagComponentes::~CDlgPropDiagComponentes()
{
}

void CDlgPropDiagComponentes::Construir(CDiagBase* pDiag)
{
	p_diag = pDiag;
}


void CDlgPropDiagComponentes::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropDiagComponentes)
	DDX_Control(pDX, IDC_DIAG_ARBOL, m_Arbol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPropDiagComponentes, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgPropDiagComponentes)
	ON_NOTIFY(NM_RCLICK, IDC_DIAG_ARBOL, OnRclickDiagArbol)
	ON_COMMAND(ID_MENU_COMPONENTE_PROP, OnMenuComponenteProp)
	ON_NOTIFY(NM_DBLCLK, IDC_DIAG_ARBOL, OnDblclkDiagArbol)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagComponentes message handlers

BOOL CDlgPropDiagComponentes::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_TreeCtrlDiag.Construir(&m_Arbol);

	m_TreeCtrlDiag.InsertarDiagrama(p_diag);
	
	return true;  // return true unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return false
}


void CDlgPropDiagComponentes::OnMenuComponenteProp() 
{
	// TODO: Add your command handler code here
	m_TreeCtrlDiag.Propiedades();

}

void CDlgPropDiagComponentes::OnRclickDiagArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_TreeCtrlDiag.MenuPopUp();
	
	*pResult = 0;
}

void CDlgPropDiagComponentes::OnDblclkDiagArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_TreeCtrlDiag.Propiedades();
	
	*pResult = 0;
}
