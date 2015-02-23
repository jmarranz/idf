// dlgopebl.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgOperacBloque.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\Bloque.h"
#include "..\..\model\exe\BloqueExe.h"

#include "..\DiagramaVistas.h"


/////////////////////////////////////////////////////////////////////////////
// COperacBloque dialog


COperacBloque::COperacBloque(CWnd* pParent /*=NULL*/)
	: CDialog(COperacBloque::IDD, pParent)
{
	//{{AFX_DATA_INIT(COperacBloque)
	m_ConectEtiq = "";
	//}}AFX_DATA_INIT

	p_bloque = NULL;
}

void COperacBloque::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COperacBloque)
	DDX_Text(pDX, IDC_CONECTOR_ETIQ, m_ConectEtiq);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COperacBloque, CDialog)
	//{{AFX_MSG_MAP(COperacBloque)
	ON_BN_CLICKED(IDC_ACEPTAR_DATOS, OnAceptarDatos)
	ON_BN_CLICKED(IDC_DEVOLVER_DATOS, OnDevolverDatos)
	ON_BN_CLICKED(IDC_RETROANOTA, OnRetroanota)
	ON_BN_CLICKED(IDC_ENVIAR_RETROANO, OnEnviarRetroano)
	ON_BN_CLICKED(IDC_RECIBIR_RETROANO, OnRecibirRetroano)
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// COperacBloque message handlers


void COperacBloque::setBloque(CBloqueExe* blq)
{
	p_bloque = blq;
}


void COperacBloque::OnAceptarDatos()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	p_bloque->ProcesarEntradaDeDatos(NULL,m_ConectEtiq);
  	p_bloque->getBloque()->getDiag()->getVistas()->Actualizar();

	EndDialog(IDOK);
}

void COperacBloque::OnDevolverDatos()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	p_bloque->ProcesarSalidaDeDatos(NULL, m_ConectEtiq);
   	p_bloque->getBloque()->getDiag()->getVistas()->Actualizar();

	EndDialog(IDOK);
}

void COperacBloque::OnAccion()
{
	// TODO: Add your control notification handler code here
	p_bloque->ComienzoEjecucion(NULL);

	EndDialog(IDOK);
}
 
void COperacBloque::OnRetroanota()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	p_bloque->Retroanotar(m_ConectEtiq, true);

	EndDialog(IDOK);
}


void COperacBloque::OnEnviarRetroano()
{
	// TODO: Add your control notification handler code here
	UpdateData();	
	p_bloque->Retroanotar(m_ConectEtiq, false);
	
	EndDialog(IDOK);
}

void COperacBloque::OnRecibirRetroano()
{
	// TODO: Add your control notification handler code here
	UpdateData();	
	p_bloque->RecibirRetroanotacion(m_ConectEtiq);
	
	EndDialog(IDOK);
}

