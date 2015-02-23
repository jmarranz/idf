// DlgPropConectFinDLL.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\idf.h"
#include "DlgPropConectFinDLL.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPropConectFinDLL property page

IMPLEMENT_DYNCREATE(CDlgPropConectFinDLL, CDlgPropConectExtremoDLL)

CDlgPropConectFinDLL::CDlgPropConectFinDLL() : CDlgPropConectExtremoDLL(CDlgPropConectFinDLL::IDD)
{
	//{{AFX_DATA_INIT(CDlgPropConectFinDLL)
	m_ClaseCom = _T("");
	//}}AFX_DATA_INIT
}

CDlgPropConectFinDLL::~CDlgPropConectFinDLL()
{
}

void CDlgPropConectFinDLL::DoDataExchange(CDataExchange* pDX)
{
	CDlgPropConectExtremoDLL::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropConectFinDLL)
	DDX_Control(pDX, IDC_CLASE_COM, m_CtrlClaseCom);
	DDX_CBString(pDX, IDC_CLASE_COM, m_ClaseCom);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPropConectFinDLL, CDlgPropConectExtremoDLL)
	//{{AFX_MSG_MAP(CDlgPropConectFinDLL)
	ON_CBN_KILLFOCUS(IDC_CLASE_COM, OnKillfocusClaseCom)
	ON_BN_CLICKED(IDC_LISTAR_CLASES, OnListarClases)
	ON_BN_CLICKED(IDC_INSPECCION_CODIGO, OnInspeccionCodigo)
	ON_BN_CLICKED(IDC_GENERACION_CODIGO, OnGeneracionCodigo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPropConectFinDLL message handlers

CString CDlgPropConectFinDLL::getClaseCom()
{
	return m_ClaseCom;
}

void CDlgPropConectFinDLL::setClaseCom(const CString& claseCom)
{
	m_ClaseCom = claseCom;
}

CComboBox* CDlgPropConectFinDLL::getListaClaseCom()
{
	return &m_CtrlClaseCom;
}

void CDlgPropConectFinDLL::OnKillfocusClaseCom() 
{
	// TODO: Add your control notification handler code here
	killFocusClaseCom();
}

void CDlgPropConectFinDLL::OnListarClases() 
{
	// TODO: Add your control notification handler code here
	listarClases();	
}

void CDlgPropConectFinDLL::OnInspeccionCodigo() 
{
	// TODO: Add your control notification handler code here
	inspeccionCodigo();
}

void CDlgPropConectFinDLL::OnGeneracionCodigo() 
{
	// TODO: Add your control notification handler code here
	generacionCodigo();
}
