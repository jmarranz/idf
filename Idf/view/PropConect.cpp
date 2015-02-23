// propcon.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "PropConect.h"

#include "BloqueVistas.h"
#include "dll\DlgGeneracionCodigoSinDLL.h"
#include "dll\DlgGeneracionCodigoConDLL.h"

#include "..\model\Conect.h"
#include "..\model\ConectInicio.h"
#include "..\model\ConectFin.h"
#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"
#include "..\model\dll\AnalisisClasesConDLL.h"

#include "..\Exception.h"

#include "DiagramaVistas.h"
#include "ConectVistas.h"


/////////////////////////////////////////////////////////////////////////////
// CPropConect dialog


CPropConect::CPropConect()
	: CPropertyPage(CPropConect::IDD)
{
	//{{AFX_DATA_INIT(CPropConect)
	m_Etiq = "";
	m_BlqFin = "";
	m_BlqIni = "";
	m_id = "";
	m_Visible = false;
	m_ClaseCom = _T("");
	m_AlturaFlecha = 0;
	m_AnchoLin = 0;
	//}}AFX_DATA_INIT
}

void CPropConect::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropConect)
	DDX_Control(pDX, IDC_CLASE_COM, m_CtrlClaseCom);
	DDX_Control(pDX, IDC_GROSOR, m_CtrlAnchoLin);
	DDX_Control(pDX, IDC_PROPBLOQ_FIN, m_CtrlPBlqFin);
	DDX_Control(pDX, IDC_PROPBLOQ_INI, m_CtrlPBlqIni);
	DDX_Text(pDX, IDC_ETIQ, m_Etiq);
	DDX_Text(pDX, IDC_BLOQUE_FIN, m_BlqFin);
	DDX_Text(pDX, IDC_BLOQUE_INICIAL, m_BlqIni);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Check(pDX, IDC_VISIBLE, m_Visible);
	DDX_CBString(pDX, IDC_CLASE_COM, m_ClaseCom);
	DDX_Text(pDX, IDC_ALTURAFLECHA, m_AlturaFlecha);
	DDX_Text(pDX, IDC_GROSOR, m_AnchoLin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropConect, CPropertyPage)
	//{{AFX_MSG_MAP(CPropConect)
	ON_EN_KILLFOCUS(IDC_ETIQ, OnKillfocusEtiq)
	ON_BN_CLICKED(IDC_PROPBLOQ_INI, OnPropbloqIni)
	ON_BN_CLICKED(IDC_PROPBLOQ_FIN, OnPropbloqFin)
	ON_CBN_KILLFOCUS(IDC_CLASE_COM, OnKillfocusClaseCom)
	ON_BN_CLICKED(IDC_LISTAR_CLASES, OnListarClases)
	ON_BN_CLICKED(IDC_GENERACION_CODIGO, OnGeneracionCodigo)
	ON_BN_CLICKED(IDC_INSPECCION_CODIGO, OnInspeccionCodigo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPropConect message handlers

void CPropConect::setConect(CConect* con)
{
	p_conect = con;
}

BOOL CPropConect::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	if (NULL == p_conect->getInicio())  m_CtrlPBlqIni.EnableWindow(false);
	if (NULL == p_conect->getFin())  m_CtrlPBlqFin.EnableWindow(false);
	if (p_conect->EsRetroanotador())
	{
		m_CtrlAnchoLin.EnableWindow(false);  // Ha de ser siempre 1 no se puede cambiar, para que salga línea de puntos.
	}
	return true;
}

void CPropConect::OnKillfocusClaseCom()
{
	// TODO: Add your control notification handler code here
	CString stemp = m_ClaseCom; // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if (m_ClaseCom != stemp)  // Se ha cambiado el valor.
	{
		p_conect->getDiag()->AvisoCambioCarga();			
	}		
}

void CPropConect::OnKillfocusEtiq()
{
	// TODO: Add your control notification handler code here
	CString stemp = m_Etiq; // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if ((p_conect->getEtiqueta() == "")&&(m_Etiq != stemp))  // Se ha cambiado el valor.
	{
		CString stemp;
		stemp = "Originalmente no existía etiqueta, el nuevo texto se situará";
		stemp += " en el comienzo del primer tramo del conector. Puede no ser visible";

		p_conect->getVistas()->Mensaje(stemp);			
	}		
}

void CPropConect::OnPropbloqIni()
{
	// TODO: Add your control notification handler code here
	CBloque* blq = p_conect->getInicio()->getBloque();
	if (blq) blq->getVistas()->Propiedades();	
}

void CPropConect::OnPropbloqFin()
{
	// TODO: Add your control notification handler code here
	CBloque* blq = p_conect->getFin()->getBloque();
	if (blq) blq->getVistas()->Propiedades();		
}

void CPropConect::OnListarClases() 
{
	// TODO: Add your control notification handler code here
	CWaitCursor cursor_espera;

	UpdateData(true); // Por si acaso es necesario para m_CtrlClaseCom

	CDiagBase* pdiag = p_conect->getDiag();
	CString DLLListaCom; // Temporal
	if (!pdiag->getVistas()->getNuevoNombreDLL(DLLListaCom)) return;
	
	CAnalisisClasesConDLL Analizador(pdiag,DLLListaCom);
	try
	{
		Analizador.Construir();
	}
	catch(Exception* ex)
	{
		pdiag->getVistas()->Mensaje(ex);
		delete ex;
		return;
	}

	m_CtrlClaseCom.ResetContent();
	Analizador.ListarObjCom(&m_CtrlClaseCom);

	UpdateData(false);	
}

void CPropConect::OnGeneracionCodigo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true); // Para actualizar m_ClaseCom 

	CDlgGeneracionCodigoSinDLL dlg(p_conect->getDiag());
	
	try
	{
		dlg.AnalizarObjCom(m_ClaseCom);
		dlg.DoModal();
	}
	catch(Exception* ex)
	{
		p_conect->getDiag()->getVistas()->Mensaje(ex);		
		delete ex;
	}
}

void CPropConect::OnInspeccionCodigo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true); // Para actualizar m_ClaseCom 

	CDiagBase* pdiag = p_conect->getDiag();
	CString DLLDiag; // Temporal
	if (!pdiag->getVistas()->getNuevoNombreDLL(DLLDiag)) return;
	
	CDlgGeneracionCodigoConDLL dlg(pdiag,DLLDiag);
	
	try
	{
		dlg.AnalizarObjCom(m_ClaseCom);
		dlg.DoModal();
	}
	catch(Exception* ex)
	{
		pdiag->getVistas()->Mensaje(ex);
		delete ex;
	}
}
