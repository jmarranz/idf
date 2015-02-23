// DlgPropiedadesDLL.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgPropiedadesClasesConDLL.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\dll\AnalisisClasesConDLL.h"

#include "..\..\Exception.h"

#include "TreeCtrlDiagCodigo.h"
#include "DlgGeneracionCodigoConDLL.h"

#include "..\DiagramaVistas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPropiedadesClasesConDLL dialog


CDlgPropiedadesClasesConDLL::CDlgPropiedadesClasesConDLL(CDiagBase* pDiag,CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPropiedadesClasesConDLL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPropiedadesClasesConDLL)
	m_DLLDiag = _T("");
	//}}AFX_DATA_INIT

	p_diag = pDiag;
	m_DLLDiag = p_diag->FormarPathAbsoluto(p_diag->getDLLDiag());

	p_TreeCtrlDiag = NULL;
	p_clasesDiag = NULL;
}

CDlgPropiedadesClasesConDLL::~CDlgPropiedadesClasesConDLL()
{
	Destruir();
}

void CDlgPropiedadesClasesConDLL::Construir()
{
	p_TreeCtrlDiag = new CTreeCtrlDiagCodigo();
	p_clasesDiag = new CAnalisisClasesConDLL(p_diag,m_DLLDiag);

	try
	{
		p_clasesDiag->Construir();
	}
	catch(Exception* ex)
	{
		p_diag->getVistas()->Mensaje(ex);
		delete ex;
		return;
	}

	p_TreeCtrlDiag->Construir(&m_arbol);

	p_TreeCtrlDiag->InsertarDiagrama(p_clasesDiag);
}

void CDlgPropiedadesClasesConDLL::Destruir()
{
	delete p_clasesDiag;
	delete p_TreeCtrlDiag;
}

void CDlgPropiedadesClasesConDLL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropiedadesClasesConDLL)
	DDX_Control(pDX, IDC_PROP_DLL_ARBOL, m_arbol);
	DDX_Text(pDX, IDC_DLLDIAGRAMA, m_DLLDiag);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPropiedadesClasesConDLL, CDialog)
	//{{AFX_MSG_MAP(CDlgPropiedadesClasesConDLL)
	ON_BN_CLICKED(IDC_CAMBIA_DLL, OnCambiaDll)
	ON_EN_KILLFOCUS(IDC_DLLDIAGRAMA, OnKillfocusDlldiagrama)
	ON_BN_CLICKED(IDC_GENERAR_CODIGO, OnGenerarCodigo)
	ON_NOTIFY(NM_RCLICK, IDC_PROP_DLL_ARBOL, OnRclickPropDllArbol)
	ON_COMMAND(ID_CLASEDLL_GENERAR_CODIGO, OnClasedllGenerarCodigo)
	ON_NOTIFY(NM_DBLCLK, IDC_PROP_DLL_ARBOL, OnDblclkPropDllArbol)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPropiedadesClasesConDLL message handlers

void CDlgPropiedadesClasesConDLL::OnCambiaDll() 
{
	// TODO: Add your control notification handler code here
	if (p_diag->getVistas()->getNuevoNombreDLL(m_DLLDiag))
    {
		UpdateData(false); 	// llevar al diálogo el cambio	

		m_arbol.DeleteAllItems();

		Destruir();
		Construir();
    }	
}

BOOL CDlgPropiedadesClasesConDLL::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Construir();
	
	return true;  // return true unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return false
}


void CDlgPropiedadesClasesConDLL::OnKillfocusDlldiagrama() 
{
	// TODO: Add your control notification handler code here
	CString dllAnterior = m_DLLDiag;
	UpdateData(true);

	if (dllAnterior != m_DLLDiag)
	{
		m_arbol.DeleteAllItems();

		Destruir();
		Construir();
	}
}

void CDlgPropiedadesClasesConDLL::OnGenerarCodigo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	CDlgGeneracionCodigoConDLL dlg(p_diag,m_DLLDiag);
	dlg.Analizar();
	dlg.DoModal();
}

void CDlgPropiedadesClasesConDLL::OnRclickPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	p_TreeCtrlDiag->MenuPopUp();

	*pResult = 0;
}

void CDlgPropiedadesClasesConDLL::OnClasedllGenerarCodigo() 
{
	// TODO: Add your command handler code here
	p_TreeCtrlDiag->GenerarCodigo();
}

void CDlgPropiedadesClasesConDLL::OnDblclkPropDllArbol(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	p_TreeCtrlDiag->GenerarCodigo();
	
	*pResult = 0;
}
