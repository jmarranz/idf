// propdiag.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "DlgPropDiagrama.h"

#include "..\model\DiagBase.h"

#include "DiagramaVistas.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagrama dialog


CDlgPropDiagrama::CDlgPropDiagrama(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CDlgPropDiagrama::IDD)
{
	//{{AFX_DATA_INIT(CDlgPropDiagrama)
	m_DLLDiag = "";
	m_Fecha = "";
	m_Etiq = "";
	m_UsaDLLDiag = false;
	m_FichLDD = "";
	m_FichBin = "";
	m_DirLibrerias = _T("");
	m_PosHorizontal = false;
	//}}AFX_DATA_INIT
}

void CDlgPropDiagrama::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPropDiagrama)
	DDX_Control(pDX, IDC_CAMBIA_DLLDIAG, m_CambiaDLLDiag);
	DDX_Control(pDX, IDC_DLLDIAG, m_CtrlDLLDiag);
	DDX_Text(pDX, IDC_DLLDIAG, m_DLLDiag);
	DDX_Text(pDX, IDC_FECHA, m_Fecha);
	DDX_Text(pDX, IDC_TITULO, m_Etiq);
	DDX_Check(pDX, IDC_USADLL, m_UsaDLLDiag);
	DDX_Text(pDX, IDC_FICHLDD, m_FichLDD);
	DDX_Text(pDX, IDC_FICHBIN, m_FichBin);
	DDX_Text(pDX, IDC_DIR_LIBRERIAS, m_DirLibrerias);
	DDX_Check(pDX, IDC_POSHORIZONTAL, m_PosHorizontal);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgPropDiagrama, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgPropDiagrama)
	ON_BN_CLICKED(IDC_USADLL, OnUsadll)
	ON_BN_CLICKED(IDC_CAMBIA_LDD, OnCambiaLdd)
	ON_EN_KILLFOCUS(IDC_DLLDIAG, OnKillfocusDlldiag)
	ON_BN_CLICKED(IDC_CAMBIA_DLLDIAG, OnCambiaDlldiag)
	ON_EN_KILLFOCUS(IDC_DIR_LIBRERIAS, OnKillfocusDirLibrerias)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgPropDiagrama message handlers


void CDlgPropDiagrama::Construir(CDiagBase* pd)
{
	p_diag = pd;
} 


BOOL CDlgPropDiagrama::OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    
	if (!m_UsaDLLDiag)
	{
		m_CtrlDLLDiag.EnableWindow( false );
		m_CambiaDLLDiag.EnableWindow( false );
	}
	
	UpdateData(false);

	return true;
}



void CDlgPropDiagrama::OnUsadll()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);  // Actualizar datos.
	if (m_UsaDLLDiag)
	{
		m_CtrlDLLDiag.EnableWindow( true );	
		m_CambiaDLLDiag.EnableWindow( true );	
	}
	else
	{
		m_CtrlDLLDiag.EnableWindow( false );
		m_CambiaDLLDiag.EnableWindow( false );
	}
	p_diag->AvisoCambioCarga();	 // Se ha cambiado el valor que sólo se nota en el arranque.
}

void CDlgPropDiagrama::OnCambiaDlldiag()
{
	// TODO: Add your control notification handler code here
	if (p_diag->getVistas()->getNuevoNombreDLL(m_DLLDiag))
    {
		UpdateData(false); 	// llevar al diálogo el cambio	
    	p_diag->AvisoCambioCarga();
    }		
}


void CDlgPropDiagrama::OnKillfocusDlldiag()
{
	// TODO: Add your control notification handler code here
	CString stemp = m_DLLDiag; // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if (m_DLLDiag != stemp)  // Se ha cambiado el valor.
	{
		p_diag->AvisoCambioCarga();			
	}	
}


void CDlgPropDiagrama::OnCambiaLdd()
{
	// TODO: Add your control notification handler code here
	if (p_diag->getVistas()->getNuevoNombreFichero( true, m_FichLDD, (CString)LDD_WILDCARD,(CString)LDD_EXT ))
    {
		UpdateData(false); 	// llevar al diálogo el cambio	
    }	
}


void CDlgPropDiagrama::OnKillfocusDirLibrerias() 
{
	// TODO: Add your control notification handler code here
	CString stemp = m_DirLibrerias; // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if (m_DirLibrerias != stemp)  // Se ha cambiado el valor.
	{
		p_diag->AvisoCambioCarga();			
	}
}

