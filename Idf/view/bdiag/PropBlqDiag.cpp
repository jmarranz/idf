// pblqdiag.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "PropBlqDiag.h"

#include "..\DiagramaVistas.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\BaseDoc.h"
#include "..\..\model\bdiag\BloqueDiag.h"

#include "BloqueDiagVistas.h"


/////////////////////////////////////////////////////////////////////////////
// CPropBlqDiag dialog


CPropBlqDiag::CPropBlqDiag(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPropBlqDiag::IDD)
{
	//{{AFX_DATA_INIT(CPropBlqDiag)
	m_Fecha = "";
	m_EtiqDiagHijo = "";
	m_FichHijo = "";
	//}}AFX_DATA_INIT

	p_bloque = NULL;
	p_bloqueIni = NULL;
	p_bloqueFin = NULL;
}

void CPropBlqDiag::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropBlqDiag)
	DDX_Control(pDX, IDC_BLOQUE_INICIO, m_ctrlListaBloquesIni);
	DDX_Control(pDX, IDC_BLOQUE_FIN, m_ctrlListaBloquesFin);
	DDX_Control(pDX, IDC_VENT_HIJO, m_CtrlVerSubDiag);
	DDX_Control(pDX, IDC_HIJOTIPOFICH, m_CtrlTipoFichHijo);
	DDX_Control(pDX, IDC_PROP_INICIO, m_CtrlPropInicio);
	DDX_Control(pDX, IDC_PROP_FIN, m_CtrlPropFin);
	DDX_Control(pDX, IDC_PROP_DIAGHIJO, m_CtrlPropDiagHijo);
	DDX_Text(pDX, IDC_FECHA, m_Fecha);
	DDX_Text(pDX, IDC_DIAG_HIJO, m_EtiqDiagHijo);
	DDX_Text(pDX, IDC_FICH_HIJO, m_FichHijo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropBlqDiag, CPropertyPage)
	//{{AFX_MSG_MAP(CPropBlqDiag)
	ON_EN_KILLFOCUS(IDC_FICH_HIJO, OnKillfocusFichHijo)
	ON_BN_CLICKED(IDC_CAMBIA_HIJO, OnCambiaHijo)
	ON_BN_CLICKED(IDC_PROP_DIAGHIJO, OnPropDiaghijo)
	ON_BN_CLICKED(IDC_PROP_INICIO, OnPropInicio)
	ON_BN_CLICKED(IDC_PROP_FIN, OnPropFin)
	ON_CBN_SELCHANGE(IDC_HIJOTIPOFICH, OnSelchangeHijotipofich)
	ON_CBN_SELCHANGE(IDC_VENT_HIJO, OnSelchangeVentHijo)
	ON_CBN_SELCHANGE(IDC_BLOQUE_INICIO, OnSelchangeBloqueInicio)
	ON_CBN_SELCHANGE(IDC_BLOQUE_FIN, OnSelchangeBloqueFin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPropBlqDiag message handlers

 
void CPropBlqDiag::setBloque(CBloqueDiag* pb)
{
	p_bloque = pb;
}    

BOOL CPropBlqDiag::OnInitDialog( )
{
	CPropertyPage::OnInitDialog( );
	
	m_CtrlTipoFichHijo.InsertString(0,LDD_WILDCARD);
	m_CtrlTipoFichHijo.SetItemData (0,true);

	if (!p_bloque->getDiag()->EsDiagDiseno())
		m_CtrlTipoFichHijo.InsertString(1,DEX_WILDCARD);
	else 
		m_CtrlTipoFichHijo.InsertString(1,DDS_WILDCARD);

	m_CtrlTipoFichHijo.SetItemData (1,false);

	if (m_esLDD)
		m_CtrlTipoFichHijo.SetCurSel(0);	
	else
		m_CtrlTipoFichHijo.SetCurSel(1);

	ListaBloques* lista = &p_bloque->getSubdiagrama()->getDiag()->m_listaBloq;
	int i = 0;
	for(POSITION pos = lista->GetStartPosition(); pos !=NULL; i++)
	{
		CBloque* blq;
		CString id;
		lista->GetNextAssoc(pos,id,blq);

		m_ctrlListaBloquesIni.InsertString(i,blq->getId());
		m_ctrlListaBloquesIni.SetItemDataPtr(i,blq);

		m_ctrlListaBloquesFin.InsertString(i,blq->getId());
		m_ctrlListaBloquesFin.SetItemDataPtr(i,blq);

		if (blq == p_bloqueIni)
			m_ctrlListaBloquesIni.SetCurSel(i);

		if (blq == p_bloqueFin)
			m_ctrlListaBloquesFin.SetCurSel(i);
	}

	CBloqueDiagVistas* pvistas = p_bloque->getVistas();

	m_mostrarSubDiag = pvistas->getMostrarHijo();
	for(i = 0; i <= N_ESTADOS_VENTANA - 1; i++)
	{
		CString texto;
		int valor = pvistas->listaMostrarHijo(i,texto);

		m_CtrlVerSubDiag.InsertString(i,texto);
		m_CtrlVerSubDiag.SetItemData (i,valor);
		
		if (m_mostrarSubDiag == valor)
			m_CtrlVerSubDiag.SetCurSel(i);
	}

	return true;
}


void CPropBlqDiag::OnKillfocusFichHijo()
{
	// TODO: Add your control notification handler code here
	CString stemp = m_FichHijo; // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if (m_FichHijo != stemp)  // Se ha cambiado el valor.
	{
		p_bloque->getDiag()->AvisoCambioCarga();			
	}	
}


void CPropBlqDiag::OnCambiaHijo()
{
	// TODO: Add your control notification handler code here
	
	UpdateData(true); // Cargar valores actuales.
	
	CDiagBase* pdiag = p_bloque->getDiag();
    BOOL res; 
    if ( m_esLDD)
	{	
		res = pdiag->getVistas()->getNuevoNombreFichero( true, m_FichHijo, (CString)LDD_WILDCARD,(CString)LDD_EXT);
    }
	else
	{
		if (!pdiag->EsDiagDiseno())
			res = pdiag->getVistas()->getNuevoNombreFichero( true, m_FichHijo, (CString)DEX_WILDCARD,(CString)DEX_EXT);
		else 
			res = pdiag->getVistas()->getNuevoNombreFichero( true, m_FichHijo, (CString)DDS_WILDCARD,(CString)DDS_EXT);
    }

	if (res)
    {
		UpdateData(false); 	// llevar al diálogo el cambio	
		pdiag->AvisoCambioCarga();
    }	
}

void CPropBlqDiag::OnPropDiaghijo()
{
	// TODO: Add your control notification handler code here
	if (p_bloque->getSubdiagrama() != NULL)
	{
		CDiagBase* pDiagHijo = p_bloque->getSubdiagrama()->getDiag();
		pDiagHijo->getVistas()->Propiedades();

		m_EtiqDiagHijo = pDiagHijo->m_etiqueta;   // Por si hubiera cambiado.

		UpdateData( false ); // Actualiza diálogo.
	}
}

void CPropBlqDiag::OnPropInicio()
{
	// TODO: Add your control notification handler code here
	if (p_bloqueIni != NULL)
	{
		p_bloqueIni->getVistas()->Propiedades();
	}
}

void CPropBlqDiag::OnPropFin()
{
	// TODO: Add your control notification handler code here
	if (p_bloqueFin != NULL)
	{
		p_bloqueFin->getVistas()->Propiedades();
	}
}

void CPropBlqDiag::OnSelchangeHijotipofich()
{
	// TODO: Add your control notification handler code here
	int selected = m_CtrlTipoFichHijo.GetCurSel();
	BOOL antiguoValor = m_esLDD;
	m_esLDD = m_CtrlTipoFichHijo.GetItemData(selected);
	
	if (antiguoValor != m_esLDD)
	{
		// Se ha cambiado el valor y es válido el nuevo.	
		p_bloque->getDiag()->AvisoCambioCarga();
	}
}

void CPropBlqDiag::OnSelchangeVentHijo()
{
	// TODO: Add your control notification handler code here

	int selected = m_CtrlVerSubDiag.GetCurSel();
	m_mostrarSubDiag = m_CtrlVerSubDiag.GetItemData(selected);
}


void CPropBlqDiag::OnSelchangeBloqueInicio() 
{
	// TODO: Add your control notification handler code here
	int selected = m_ctrlListaBloquesIni.GetCurSel();
	if (CB_ERR == selected) return;
	p_bloqueIni = (CBloque*)m_ctrlListaBloquesIni.GetItemDataPtr(selected);
}

void CPropBlqDiag::OnSelchangeBloqueFin() 
{
	// TODO: Add your control notification handler code here
	int selected = m_ctrlListaBloquesFin.GetCurSel();
	if (CB_ERR == selected) return;
	p_bloqueFin = (CBloque*)m_ctrlListaBloquesFin.GetItemDataPtr(selected);
}
