// propmult.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "PropMultiDiag.h"

#include "bdiag\BloqueDiagVistas.h"
#include "DiagramaVistas.h"

#include "..\model\DiagBase.h"
#include "..\model\bdiag\BloqueDiag.h"

/////////////////////////////////////////////////////////////////////////////
// CPropMultiDiag dialog


CPropMultiDiag::CPropMultiDiag(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CPropMultiDiag::IDD)
{
	//{{AFX_DATA_INIT(CPropMultiDiag)
	m_EtiqDiagPadre = "";
	m_BlqIni = "";
	m_BlqFin = "";
	m_BlqDiagPadre = _T("");
	//}}AFX_DATA_INIT
}

void CPropMultiDiag::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropMultiDiag)
	DDX_Text(pDX, IDC_DIAG_PADRE, m_EtiqDiagPadre);
	DDX_Text(pDX, IDC_BLOQUE_INICIO, m_BlqIni);
	DDX_Text(pDX, IDC_BLOQUE_FIN, m_BlqFin);
	DDX_Text(pDX, IDC_BLOQUE_DIAGRAMA, m_BlqDiagPadre);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropMultiDiag, CPropertyPage)
	//{{AFX_MSG_MAP(CPropMultiDiag)
	ON_BN_CLICKED(IDC_PROP_DIAGPADRE, OnPropDiagpadre)
	ON_BN_CLICKED(IDC_PROP_FIN, OnPropFin)
	ON_BN_CLICKED(IDC_PROP_INICIO, OnPropInicio)
	ON_BN_CLICKED(IDC_PROP_BLOQUEDIAG, OnPropBloquediag)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPropMultiDiag message handlers


void CPropMultiDiag::setDiag(CDiagBase* pd, CBloqueDiag* pblqpadre)
{
	p_diag = pd;
	p_blqDiagPadre = pblqpadre;
} 

void CPropMultiDiag::OnPropDiagpadre()
{
	// TODO: Add your control notification handler code here
	CDiagBase* pDiagPadre = p_blqDiagPadre->getDiag();
	pDiagPadre->getVistas()->Propiedades();

	m_EtiqDiagPadre = pDiagPadre->m_etiqueta;   // Por si hubiera cambiado.
	UpdateData( false ); // Actualiza diálogo. 
}

void CPropMultiDiag::OnPropFin()
{
	// TODO: Add your control notification handler code here
	CBloque* bloqfin = p_diag->getMDiagBloqFin();
	if (bloqfin != NULL)
	{
		bloqfin->getVistas()->Propiedades();
		m_BlqFin = bloqfin->getId();   // Por si hubiera cambiado.
		UpdateData( false ); // Actualiza diálogo. 	
	}
}

void CPropMultiDiag::OnPropInicio()
{
	// TODO: Add your control notification handler code here
	CBloque* bloqini = p_diag->getMDiagBloqIni();	
	if (bloqini != NULL)
	{
		bloqini->getVistas()->Propiedades();
		m_BlqIni = bloqini->getId();   // Por si hubiera cambiado.
		UpdateData( false ); // Actualiza diálogo. 		
	}
}


void CPropMultiDiag::OnPropBloquediag() 
{
	// TODO: Add your control notification handler code here
	p_blqDiagPadre->getVistas()->Propiedades();
	m_BlqDiagPadre = p_blqDiagPadre->getEtiqueta(); // Por si hubiera cambiado
	UpdateData( false ); // Actualiza diálogo
}
