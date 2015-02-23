// DlgOperacBRetro.cpp: implementation of the COperacBRetro class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "DlgOperacBRetro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "..\..\model\exe\BloqueExe.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


COperacBRetro::COperacBRetro(CWnd* pParent /*=NULL*/)
	: CDialog(COperacBRetro::IDD, pParent)
{
	//{{AFX_DATA_INIT(COperacBRetro)
	m_ConectEtiq = _T("");
	//}}AFX_DATA_INIT

	p_bloque = NULL;
}

void COperacBRetro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COperacBRetro)
	DDX_Text(pDX, IDC_CONECTOR_ETIQ, m_ConectEtiq);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COperacBRetro, CDialog)
	//{{AFX_MSG_MAP(COperacBRetro)
	ON_BN_CLICKED(IDC_RETROANOTA, OnRetroanota)
	ON_BN_CLICKED(IDC_ENVIAR_RETROANO, OnEnviarRetroano)
	ON_BN_CLICKED(IDC_RECIBIR_RETROANO, OnRecibirRetroano)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// COperacBRetro message handlers

void COperacBRetro::setBloque(CBloqueExe* blq)
{
	p_bloque = blq;
}

void COperacBRetro::OnRetroanota()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	p_bloque->Retroanotar(m_ConectEtiq, true);

	EndDialog(IDOK);
}


void COperacBRetro::OnEnviarRetroano() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	p_bloque->Retroanotar(m_ConectEtiq, false);

	EndDialog(IDOK);	
}

void COperacBRetro::OnRecibirRetroano() 
{
	// TODO: Add your control notification handler code here
	UpdateData();	
	p_bloque->RecibirRetroanotacion(m_ConectEtiq);
	
	EndDialog(IDOK);	
}
