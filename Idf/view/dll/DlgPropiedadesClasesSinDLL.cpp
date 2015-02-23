// DlgPropiedadesClasesSinDLL.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgPropiedadesClasesSinDLL.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\dll\AnalisisClasesSinDLL.h"

#include "TreeCtrlDiagCodigo.h"
#include "DlgGeneracionCodigoSinDLL.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPropiedadesClasesSinDLL dialog


CDlgPropiedadesClasesSinDLL::CDlgPropiedadesClasesSinDLL(CDiagBase* pDiag,CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPropiedadesClasesSinDLL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPropiedadesClasesSinDLL)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	p_diag = pDiag;

	p_TreeCtrlDiag = NULL;
	p_clasesDiag = NULL;
}

CDlgPropiedadesClasesSinDLL::~CDlgPropiedadesClasesSinDLL()
{
	Destruir();
}

void CDlgPropiedadesClasesSinDLL::Construir()
{
	p_TreeCtrlDiag = new CTreeCtrlDiagCodigo();
	p_clasesDiag = new CAnalisisClasesSinDLL(p_diag);

	p_clasesDiag->Construir();

	p_TreeCtrlDiag->Construir(&m_arbol);

	p_TreeCtrlDiag->InsertarDiagrama(p_clasesDiag);
}

void CDlgPropiedadesClasesSinDLL::Destruir()
{
	delete p_clasesDiag;
	delete p_TreeCtrlDiag;
}


void CDlgPropiedadesClasesSinDLL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropiedadesClasesSinDLL)
	DDX_Control(pDX, IDC_PROP_DLL_ARBOL, m_arbol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPropiedadesClasesSinDLL, CDialog)
	//{{AFX_MSG_MAP(CDlgPropiedadesClasesSinDLL)
	ON_BN_CLICKED(IDC_GENERAR_CODIGO, OnGenerarCodigo)
	ON_NOTIFY(NM_RCLICK, IDC_PROP_DLL_ARBOL, OnRclickPropDllArbol)
	ON_COMMAND(ID_CLASEDLL_GENERAR_CODIGO, OnClasedllGenerarCodigo)
	ON_NOTIFY(NM_DBLCLK, IDC_PROP_DLL_ARBOL, OnDblclkPropDllArbol)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPropiedadesClasesSinDLL message handlers

BOOL CDlgPropiedadesClasesSinDLL::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Construir();
	
	return true;  // return true unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return false
}

void CDlgPropiedadesClasesSinDLL::OnGenerarCodigo() 
{
	// TODO: Add your control notification handler code here
	CDlgGeneracionCodigoSinDLL dlg(p_diag);
	dlg.Analizar();
	dlg.DoModal();	
}

void CDlgPropiedadesClasesSinDLL::OnRclickPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	p_TreeCtrlDiag->MenuPopUp();
	
	*pResult = 0;
}

void CDlgPropiedadesClasesSinDLL::OnClasedllGenerarCodigo() 
{
	// TODO: Add your command handler code here
	p_TreeCtrlDiag->GenerarCodigo();
	
}

void CDlgPropiedadesClasesSinDLL::OnDblclkPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	p_TreeCtrlDiag->GenerarCodigo();
	
	*pResult = 0;
}
