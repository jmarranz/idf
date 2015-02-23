// propbloq.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "PropBloque.h"

#include "BloqueVistas.h"
#include "exe\BloqueVistasExe.h"

#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"


/////////////////////////////////////////////////////////////////////////////
// CPropBloque dialog


CPropBloque::CPropBloque(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPropBloque::IDD)
{
	//{{AFX_DATA_INIT(CPropBloque)
	m_AE = false;
	m_AS = false;
	m_Etiq = "";
	m_EstadoInterno = "";
	m_id = "";
	m_SalidaAuto = "";
	m_TipoDibujo = "";
	m_Visible = false;
	m_AnchoLin = 0;
	m_Orden = "";
	m_AutoContMax = 0;
	m_tipoBloque = _T("");
	//}}AFX_DATA_INIT
}

void CPropBloque::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropBloque)
	DDX_Control(pDX, IDC_ORDEN_BLOQUE, m_CtrlOrden);
	DDX_Control(pDX, IDC_OPERACIONES, m_CtrlOperac);
	DDX_Control(pDX, IDC_ESTADOINTERNO, m_CtrlEstadoInt);
	DDX_Control(pDX, IDC_ESTADOUSUARIO, m_CtrlEstadoUsr);
	DDX_Control(pDX, IDC_MAXITER_AUTO, m_CtrlAutoContMax);
	DDX_Control(pDX, IDC_SALIDA_AUTO, m_CtrlSalidaAuto);
	DDX_Control(pDX, IDC_ACTIVO_SALIDA, m_CtrlAS);
	DDX_Control(pDX, IDC_ACTIVO_ENTRADA, m_CtrlAE);
	DDX_Check(pDX, IDC_ACTIVO_ENTRADA, m_AE);
	DDX_Check(pDX, IDC_ACTIVO_SALIDA, m_AS);
	DDX_Text(pDX, IDC_ETIQUETA, m_Etiq);
	DDX_Text(pDX, IDC_ESTADOINTERNO, m_EstadoInterno);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_SALIDA_AUTO, m_SalidaAuto);
	DDX_CBString(pDX, IDC_TIPO_DIBUJO, m_TipoDibujo);
	DDX_Check(pDX, IDC_VISIBLE, m_Visible);
	DDX_Text(pDX, IDC_GROSOR, m_AnchoLin);
	DDX_Text(pDX, IDC_ORDEN_BLOQUE, m_Orden);
	DDX_Text(pDX, IDC_MAXITER_AUTO, m_AutoContMax);
	DDX_Text(pDX, IDC_TIPO_BLOQUE, m_tipoBloque);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropBloque, CPropertyPage)
	//{{AFX_MSG_MAP(CPropBloque)
	ON_BN_CLICKED(IDC_OPERACIONES, OnOperaciones)
	ON_CBN_SELCHANGE(IDC_ESTADOUSUARIO, OnSelchangeEstadousuario)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPropBloque message handlers

BOOL CPropBloque::OnInitDialog( )
{
	CPropertyPage::OnInitDialog();

	if (p_bloque->EsRetroanotador())
	{
		m_CtrlOrden.EnableWindow( false ); 
		m_CtrlAE.EnableWindow( false ); 
		m_CtrlAS.EnableWindow( false );	
		m_CtrlSalidaAuto.EnableWindow( false );	
	    m_CtrlAutoContMax.EnableWindow( false );	
	}

	if (p_bloque->EsBloqueDiag())
    {                       
		m_tipoBloque = "Bloque Diagrama";
    }
    else  // Es bloque unidad, por ahora basado en DLL (el único)
    {   
		if (p_bloque->EsRetroanotador())
		{
			m_tipoBloque = "Bloque Retroanotador basado en DLL";
		}		
		else  // Es un bloque funcional en DLL
	    {
			m_tipoBloque = "Bloque basado en DLL";
    	}
    }
	
    if ( ! p_bloque->getDiag()->EsMultiDiag())
    {
        m_CtrlOrden.EnableWindow(false);  // No tiene sentido     
    }
        
    if (p_bloque->getDiag()->EsDiagDiseno())
    {
        m_CtrlOrden.EnableWindow(false);  // No tiene sentido 
		m_CtrlOperac.EnableWindow(false);  // Idem
		// m_CtrlEstadoInt.EnableWindow(false); // Para distinguir entre nuevo o modificadas propiedades.		    
		m_CtrlEstadoUsr.EnableWindow(false);    
    }

	for(int i = 0; i <= N_ESTADOS_USUARIO - 1; i++)
	{
		CString texto;
		int valor = p_bloque->listaEstadosUsuario(i,texto);

		m_CtrlEstadoUsr.InsertString(i,texto);
		m_CtrlEstadoUsr.SetItemData (i,valor);
		
		if (m_estadoUsuario == valor)
			m_CtrlEstadoUsr.SetCurSel(i);
	}

	UpdateData(false);

	return true;
}

void CPropBloque::setBloque(CBloque* pb)
{
	p_bloque = pb;
}    

void CPropBloque::OnOperaciones()
{
	// TODO: Add your control notification handler code here
	p_bloque->getVistas()->getExe()->DlgOperaciones();	
}

void CPropBloque::OnSelchangeEstadousuario() 
{
	// TODO: Add your control notification handler code here
	int selected = m_CtrlEstadoUsr.GetCurSel();
	m_estadoUsuario = (TipoEstadoUsuario)m_CtrlEstadoUsr.GetItemData(selected);
}

