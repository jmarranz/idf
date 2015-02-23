// pblqdll.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "PropBlqDLL.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\dll\BloqueDLL.h"
#include "..\..\model\dll\AnalisisClasesConDLL.h"

#include "BloqueDLLVistas.h"

#include "DlgGeneracionCodigoSinDLL.h"
#include "DlgGeneracionCodigoConDLL.h"

#include "..\DiagramaVistas.h"

#include "..\..\Exception.h"


/////////////////////////////////////////////////////////////////////////////
// CPropBlqDLL dialog


CPropBlqDLL::CPropBlqDLL(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPropBlqDLL::IDD)
{
	//{{AFX_DATA_INIT(CPropBlqDLL)
	m_UsaDLLDiag = false;
	m_DLLBloque = "";
	m_Fecha = "";
	m_Macro = "";
	m_ClaseBloque = _T("");
	//}}AFX_DATA_INIT

	p_bloque = NULL;
}

void CPropBlqDLL::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropBlqDLL)
	DDX_Control(pDX, IDC_CLASE_BLOQUE, m_CtrlClaseBloque);
	DDX_Control(pDX, IDC_CAMBIA_DLL, m_CambiaDLL);
	DDX_Control(pDX, IDC_PROP_USUARIO, m_CtrlPropUsr);
	DDX_Control(pDX, IDC_DLLBLOQUE, m_CtrlDLLBloque);
	DDX_Check(pDX, IDC_USADLLDIAG, m_UsaDLLDiag);
	DDX_Text(pDX, IDC_DLLBLOQUE, m_DLLBloque);
	DDX_Text(pDX, IDC_FECHA, m_Fecha);
	DDX_Text(pDX, IDC_MACRO, m_Macro);
	DDV_MaxChars(pDX, m_Macro, 32760);
	DDX_CBString(pDX, IDC_CLASE_BLOQUE, m_ClaseBloque);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropBlqDLL, CPropertyPage)
	//{{AFX_MSG_MAP(CPropBlqDLL)
	ON_BN_CLICKED(IDC_USADLLDIAG, OnUsadlldiag)
	ON_EN_KILLFOCUS(IDC_DLLBLOQUE, OnKillfocusDllbloque)
	ON_BN_CLICKED(IDC_CAMBIA_DLL, OnCambiaDll)
	ON_BN_CLICKED(IDC_PROP_USUARIO, OnPropUsuario)
	ON_CBN_KILLFOCUS(IDC_CLASE_BLOQUE, OnKillfocusClaseBloque)
	ON_BN_CLICKED(IDC_LISTAR_CLASES, OnListarClases)
	ON_BN_CLICKED(IDC_GENERACION_CODIGO, OnGeneracionCodigo)
	ON_BN_CLICKED(IDC_INSPECCION_CODIGO, OnInspeccionCodigo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPropBlqDLL message handlers

void CPropBlqDLL::setBloque(CBloqueDLL* pb)
{
	p_bloque = pb;
}    


BOOL CPropBlqDLL::OnInitDialog()
{
    CPropertyPage::OnInitDialog();

	if (m_UsaDLLDiag)
	{
		m_CtrlDLLBloque.EnableWindow( false );   // Desactivar el control del DLLBloque
		m_CambiaDLL.EnableWindow( false );   // Desactivar el control de cambiar el DLLBloque
	}
	if (p_bloque->getDiag()->EsDiagDiseno()) m_CtrlPropUsr.EnableWindow( false ); // No tenemos acceso a DLLs en diseño.
	
	return true;
}


void CPropBlqDLL::OnUsadlldiag()
{
	// TODO: Add your control notification handler code here
	
	UpdateData(true);  // Actualizar datos.
	if (m_UsaDLLDiag)
	{
		m_CtrlDLLBloque.EnableWindow( false );	
		m_CambiaDLL.EnableWindow( false );
	}
	else
	{
		m_CtrlDLLBloque.EnableWindow( true );
		m_CambiaDLL.EnableWindow( true );	
	}
	p_bloque->getDiag()->AvisoCambioCarga();	 // Se ha cambiado el valor
}


void CPropBlqDLL::OnKillfocusDllbloque()
{
	// TODO: Add your control notification handler code here
	CString stemp = m_DLLBloque; // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if (m_DLLBloque != stemp)  // Se ha cambiado el valor.
	{
		p_bloque->getDiag()->AvisoCambioCarga();			
	}
}

void CPropBlqDLL::OnCambiaDll()
{
	// TODO: Add your control notification handler code here
					
	CDiagBase* pdiag = p_bloque->getDiag();
	if (pdiag->getVistas()->getNuevoNombreDLL(m_DLLBloque))
    {
		UpdateData(false); 	// llevar al diálogo el cambio	
		pdiag->AvisoCambioCarga();
    }
}


void CPropBlqDLL::OnKillfocusClaseBloque()
{
	// TODO: Add your control notification handler code here
	CString stemp = m_ClaseBloque; // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if (m_ClaseBloque != stemp)  // Se ha cambiado el valor.
	{
		p_bloque->getDiag()->AvisoCambioCarga();	
	}
}


void CPropBlqDLL::OnPropUsuario()
{
	// TODO: Add your control notification handler code here
	p_bloque->getVistas()->PropUsuario();	 // Llama al DLL
}


void CPropBlqDLL::OnListarClases() 
{
	// TODO: Add your control notification handler code here
	CWaitCursor cursor_espera;

	UpdateData(true); // Traer el m_DLLBloque del diálogo

	CAnalisisClasesConDLL Analizador(p_bloque->getDiag(),m_DLLBloque);

	try
	{
		Analizador.Construir();
	}
	catch(Exception* ex)
	{
		p_bloque->getDiag()->getVistas()->Mensaje(ex);
		delete ex;
		return;
	}

	m_CtrlClaseBloque.ResetContent();
	Analizador.ListarBloques(&m_CtrlClaseBloque, 0);  // Funcionales/Retroanotadores
	if (!p_bloque->EsRetroanotador())
		 Analizador.ListarBloques(&m_CtrlClaseBloque, 1);  // Sólo Funcionales
	else 
		 Analizador.ListarBloques(&m_CtrlClaseBloque, 2);  // Sólo Retroanotadores

	UpdateData(false);
}


void CPropBlqDLL::OnGeneracionCodigo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true); // Para actualizar m_ClaseBloque
	CDlgGeneracionCodigoSinDLL dlg(p_bloque->getDiag());
	
	try
	{
		dlg.AnalizarBloque(m_ClaseBloque);
		dlg.DoModal();
	}
	catch(Exception* ex)
	{
		p_bloque->getDiag()->getVistas()->Mensaje(ex);		
		delete ex;
	}
}

void CPropBlqDLL::OnInspeccionCodigo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true); // Para actualizar m_ClaseBloque y m_DLLBloque 
	CDlgGeneracionCodigoConDLL dlg(p_bloque->getDiag(),m_DLLBloque);
	try
	{
		dlg.AnalizarBloque(m_ClaseBloque);
		dlg.DoModal();
	}
	catch(Exception* ex)
	{
		p_bloque->getDiag()->getVistas()->Mensaje(ex);		
		delete ex;
	}
}

