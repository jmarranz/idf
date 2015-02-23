// DlgPropBloqueConectores.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "DlgPropBloqueConectores.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPropBloqueConectores property page

IMPLEMENT_DYNCREATE(CDlgPropBloqueConectores, CPropertyPage)

CDlgPropBloqueConectores::CDlgPropBloqueConectores() : CPropertyPage(CDlgPropBloqueConectores::IDD)
{
	//{{AFX_DATA_INIT(CDlgPropBloqueConectores)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	p_bloque = NULL;
}

CDlgPropBloqueConectores::~CDlgPropBloqueConectores()
{
}

void CDlgPropBloqueConectores::Construir(CBloque* pBloque)
{
	p_bloque = pBloque;
}

void CDlgPropBloqueConectores::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropBloqueConectores)
	DDX_Control(pDX, IDC_BLOQUE_ARBOL, m_Arbol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPropBloqueConectores, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgPropBloqueConectores)
	ON_COMMAND(ID_MENU_COMPONENTE_PROP, OnMenuComponenteProp)
	ON_NOTIFY(NM_RCLICK, IDC_BLOQUE_ARBOL, OnRclickBloqueArbol)
	ON_NOTIFY(NM_DBLCLK, IDC_BLOQUE_ARBOL, OnDblclkBloqueArbol)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPropBloqueConectores message handlers

BOOL CDlgPropBloqueConectores::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_TreeCtrlDiag.Construir(&m_Arbol);

	m_TreeCtrlDiag.InsertarBloqueConectores(p_bloque,TVI_ROOT);

	return true;  // return true unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return false
}

void CDlgPropBloqueConectores::OnMenuComponenteProp() 
{
	// TODO: Add your command handler code here
	m_TreeCtrlDiag.Propiedades();
}

void CDlgPropBloqueConectores::OnRclickBloqueArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_TreeCtrlDiag.MenuPopUp();
	
	*pResult = 0;
}

void CDlgPropBloqueConectores::OnDblclkBloqueArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_TreeCtrlDiag.Propiedades();
	
	*pResult = 0;
}
