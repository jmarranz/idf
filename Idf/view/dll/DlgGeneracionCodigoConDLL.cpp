// CDlgGeneracionCodigoConDLL.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgGeneracionCodigoConDLL.h"

#include "..\DiagramaVistas.h"

#include "..\..\model\DiagBase.h"

#include "..\..\model\dll\AnalisisClasesConDLL.h"
#include "..\..\model\dll\InfoClases.h"

#include "..\..\Exception.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgGeneracionCodigoConDLL dialog


CDlgGeneracionCodigoConDLL::CDlgGeneracionCodigoConDLL(CDiagBase* pdiag, CWnd* pParent /*=NULL*/)
	: CDlgGeneracionCodigoDLL(pdiag,CDlgGeneracionCodigoConDLL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgGeneracionCodigoConDLL)
	m_DLLDiag = _T("");
	m_cabeceras = _T("");
	m_implementacion = _T("");
	//}}AFX_DATA_INIT

	m_DLLDiag = p_diag->FormarPathAbsoluto(p_diag->getDLLDiag());

	p_Analizador = new CAnalisisClasesConDLL(p_diag,m_DLLDiag);
	p_Analizador->Construir();
}

CDlgGeneracionCodigoConDLL::CDlgGeneracionCodigoConDLL(CDiagBase* pdiag,
			const CString& dllDiag, CWnd* pParent /*=NULL*/)
	: CDlgGeneracionCodigoDLL(pdiag,CDlgGeneracionCodigoConDLL::IDD, pParent)
{
	m_DLLDiag = dllDiag;

	p_Analizador = new CAnalisisClasesConDLL(p_diag,m_DLLDiag);

	try
	{
		p_Analizador->Construir();
	}
	catch(Exception* ex)
	{
		p_diag->getVistas()->Mensaje(ex);
		delete ex;
	}
}

CDlgGeneracionCodigoConDLL::~CDlgGeneracionCodigoConDLL()
{
	delete p_Analizador;
}

void CDlgGeneracionCodigoConDLL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgGeneracionCodigoConDLL)
	DDX_Control(pDX, IDC_EDIT_IMPLEMENTACION, m_edit_implementacion);
	DDX_Control(pDX, IDC_EDIT_CABECERAS, m_edit_cabeceras);
	DDX_Text(pDX, IDC_DLLDIAGRAMA, m_DLLDiag);
	DDX_Text(pDX, IDC_EDIT_CABECERAS, m_cabeceras);
	DDX_Text(pDX, IDC_EDIT_IMPLEMENTACION, m_implementacion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGeneracionCodigoConDLL, CDialog)
	//{{AFX_MSG_MAP(CDlgGeneracionCodigoConDLL)
	ON_BN_CLICKED(IDC_SALVAR_H, OnSalvarH)
	ON_BN_CLICKED(IDC_SALVAR_CPP, OnSalvarCpp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgGeneracionCodigoConDLL message handlers

BOOL CDlgGeneracionCodigoConDLL::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//m_edit_cabeceras. SetReadOnly();
	//m_edit_implementacion.SetReadOnly();

	if (!p_Analizador->EsValido()) return false;

	return true;  // return true unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return false
}

void CDlgGeneracionCodigoConDLL::SetCabeceras(const CString& codigo)
{
	m_cabeceras = codigo;
}

void CDlgGeneracionCodigoConDLL::SetImplementacion(const CString& codigo)
{
	m_implementacion = codigo;
}


void CDlgGeneracionCodigoConDLL::AnalizarBloque(const CString& SClaseBloque)
{
	// TODO: Add your control notification handler code here
	if (SClaseBloque == "")
	{
		throw new Exception("No se ha definido la clase del bloque a buscar");
	}

	CInfoBloque* pBloque = p_Analizador->BuscarBloque(SClaseBloque);
	if (pBloque == NULL) 
	{
		throw new Exception("No se ha encontrado la clase de bloque: " + SClaseBloque + " en el módulo:\r\n" + m_DLLDiag);
	}		

	CDlgGeneracionCodigoDLL::AnalizarBloque(pBloque);
}


void CDlgGeneracionCodigoConDLL::AnalizarObjCom(const CString& SClaseCom)
{
	// TODO: Add your control notification handler code here
	if (SClaseCom == "")
	{
		throw new Exception("No se ha definido clase de comunicación de datos por el conector");
	}

	CInfoCom* pCom = p_Analizador->BuscarObjCom(SClaseCom);
	if (pCom == NULL) 
	{
		throw new Exception("No se ha encontrado la clase de comunicación: " + SClaseCom + " en el módulo:\r\n" + m_DLLDiag);
	}		

	CDlgGeneracionCodigoDLL::AnalizarObjCom(pCom);
}



void CDlgGeneracionCodigoConDLL::OnSalvarH() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SalvarTexto(m_cabeceras,CString("Cabeceras"), CString("h"));
}

void CDlgGeneracionCodigoConDLL::OnSalvarCpp() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SalvarTexto(m_implementacion,CString("Implementación"),CString("cpp"));
}


