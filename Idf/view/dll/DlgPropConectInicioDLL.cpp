// DlgPropConectInicioDLL.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\idf.h"
#include "DlgPropConectInicioDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPropConectInicioDLL property page

IMPLEMENT_DYNCREATE(CDlgPropConectInicioDLL, CDlgPropConectExtremoDLL)

CDlgPropConectInicioDLL::CDlgPropConectInicioDLL() : CDlgPropConectExtremoDLL(CDlgPropConectInicioDLL::IDD)
{
	//{{AFX_DATA_INIT(CDlgPropConectInicioDLL)
	m_ClaseCom = _T("");
	//}}AFX_DATA_INIT
}

CDlgPropConectInicioDLL::~CDlgPropConectInicioDLL()
{
}

void CDlgPropConectInicioDLL::DoDataExchange(CDataExchange* pDX)
{
	CDlgPropConectExtremoDLL::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropConectInicioDLL)
	DDX_Control(pDX, IDC_CLASE_COM, m_CtrlClaseCom);
	DDX_CBString(pDX, IDC_CLASE_COM, m_ClaseCom);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPropConectInicioDLL, CDlgPropConectExtremoDLL)
	//{{AFX_MSG_MAP(CDlgPropConectInicioDLL)
	ON_CBN_KILLFOCUS(IDC_CLASE_COM, OnKillfocusClaseCom)
	ON_BN_CLICKED(IDC_LISTAR_CLASES, OnListarClases)
	ON_BN_CLICKED(IDC_INSPECCION_CODIGO, OnInspeccionCodigo)
	ON_BN_CLICKED(IDC_GENERACION_CODIGO, OnGeneracionCodigo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPropConectInicioDLL message handlers


CString CDlgPropConectInicioDLL::getClaseCom()
{
	return m_ClaseCom;
}

void CDlgPropConectInicioDLL::setClaseCom(const CString& claseCom)
{
	m_ClaseCom = claseCom;
}

CComboBox* CDlgPropConectInicioDLL::getListaClaseCom()
{
	return &m_CtrlClaseCom;
}


void CDlgPropConectInicioDLL::OnKillfocusClaseCom() 
{
	// TODO: Add your control notification handler code here
	killFocusClaseCom();
}

void CDlgPropConectInicioDLL::OnListarClases() 
{
	// TODO: Add your control notification handler code here
	listarClases();	
}

void CDlgPropConectInicioDLL::OnInspeccionCodigo() 
{
	// TODO: Add your control notification handler code here
	inspeccionCodigo();
}

void CDlgPropConectInicioDLL::OnGeneracionCodigo() 
{
	// TODO: Add your control notification handler code here
	generacionCodigo();
}
