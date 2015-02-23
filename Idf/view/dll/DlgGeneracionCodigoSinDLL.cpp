// CDlgGeneracionCodigoSinDLL.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgGeneracionCodigoSinDLL.h"

#include "..\..\model\DiagBase.h"

#include "..\..\model\dll\AnalisisClasesSinDLL.h"
#include "..\..\model\dll\GeneracionCodigoDLL.h"

#include "..\..\Exception.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgGeneracionCodigoSinDLL dialog


CDlgGeneracionCodigoSinDLL::CDlgGeneracionCodigoSinDLL(CDiagBase* pdiag, CWnd* pParent /*=NULL*/)
	: CDlgGeneracionCodigoDLL(pdiag,CDlgGeneracionCodigoSinDLL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgGeneracionCodigoSinDLL)
	m_cabeceras = _T("");
	m_implementacion = _T("");
	//}}AFX_DATA_INIT

	p_Analizador = new CAnalisisClasesSinDLL(p_diag);
	p_Analizador->Construir();
}

CDlgGeneracionCodigoSinDLL::~CDlgGeneracionCodigoSinDLL()
{
	delete p_Analizador;
}

void CDlgGeneracionCodigoSinDLL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgGeneracionCodigoSinDLL)
	DDX_Text(pDX, IDC_EDIT_CABECERAS, m_cabeceras);
	DDX_Text(pDX, IDC_EDIT_IMPLEMENTACION, m_implementacion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGeneracionCodigoSinDLL, CDialog)
	//{{AFX_MSG_MAP(CDlgGeneracionCodigoSinDLL)
	ON_BN_CLICKED(IDC_SALVAR_CPP, OnSalvarCpp)
	ON_BN_CLICKED(IDC_SALVAR_H, OnSalvarH)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgGeneracionCodigoSinDLL message handlers

BOOL CDlgGeneracionCodigoSinDLL::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	return true;  // return true unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return false
}

void CDlgGeneracionCodigoSinDLL::SetCabeceras(const CString& codigo)
{
	m_cabeceras = codigo;
}

void CDlgGeneracionCodigoSinDLL::SetImplementacion(const CString& codigo)
{
	m_implementacion = codigo;
}


void CDlgGeneracionCodigoSinDLL::AnalizarBloque(const CString& SClaseBloque)
{
	// TODO: Add your control notification handler code here
	CWaitCursor cursor_espera;

	// Es llamada antes del DoModal, no hace falta el UpdateData()
	// UpdateData(true);

	if (SClaseBloque == "")
	{
		throw new Exception("No se ha definido la clase del bloque buscar");
	}

	CInfoBloque* pdatos = p_Analizador->BuscarBloque(SClaseBloque);
	if (pdatos == NULL)
	{
		throw new Exception("No se ha encontrado el bloque de clase: " + SClaseBloque + " en el diagrama");
	}

	CDlgGeneracionCodigoDLL::AnalizarBloque(pdatos);
}


void CDlgGeneracionCodigoSinDLL::AnalizarObjCom(const CString& SClaseCom)
{
	// TODO: Add your control notification handler code here
	CWaitCursor cursor_espera;

	// Es llamada antes del DoModal, no hace falta el UpdateData()
	// UpdateData(true);

	if (SClaseCom == "")
	{
		throw new Exception("No se ha definido clase de comunicación de datos por el conector");
	}

	CInfoCom* pdatos = p_Analizador->BuscarObjCom(SClaseCom);
	if (pdatos == NULL) // Encontrado 
	{
		throw new Exception("No se ha encontrado la clase de comunicación: " + SClaseCom + " en el diagrama");
	}

	CDlgGeneracionCodigoDLL::AnalizarObjCom(pdatos);
}

void CDlgGeneracionCodigoSinDLL::OnSalvarH() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SalvarTexto(m_cabeceras,CString("Cabeceras"), CString("h"));
}

void CDlgGeneracionCodigoSinDLL::OnSalvarCpp() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SalvarTexto(m_implementacion,CString("Implementación"),CString("cpp"));
}
