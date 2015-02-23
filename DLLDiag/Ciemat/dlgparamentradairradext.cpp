// dlgparamentradairradext.cpp : implementation file
//

#include "stdafx.h"
#include "..\DLLDiag.h"
#include "dlgparamentradairradext.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgParamEntradaIrradExt dialog


DlgParamEntradaIrradExt::DlgParamEntradaIrradExt(CWnd* pParent /*=NULL*/)
	: CDialog(DlgParamEntradaIrradExt::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgParamEntradaIrradExt)
	m_Cw = 0.0;
	m_L = 0.0;
	m_DFinm_b = 0.0;
	m_DFinm_g = 0.0;
	m_DFaire_b = 0.0;
	m_DFaire_g = 0.0;
	m_DFgr_b = 0.0;
	m_DFgr_g = 0.0;
	m_tb = 0.0;
	m_Fb_b = 0.0;
	m_Fb_g = 0.0;
	m_Ofinm = 0.0;
	m_Oforilla = 0.0;
	m_Wpiel = 0.0;
	m_d = 0.0;
	m_Ca = 0.0;
	m_Ofaire_ext = 0.0;
	m_Ofaire_int = 0.0;
	m_Cso = 0.0;
	//}}AFX_DATA_INIT
}


void DlgParamEntradaIrradExt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgParamEntradaIrradExt)
	DDX_Text(pDX, IDC_CONC_AGUA, m_Cw);
	DDX_Text(pDX, IDC_DESINTEGRACION, m_L);
	DDX_Text(pDX, IDC_DF_AGUA_BETA, m_DFinm_b);
	DDX_Text(pDX, IDC_DF_AGUA_GAMMA, m_DFinm_g);
	DDX_Text(pDX, IDC_DF_AIRE_BETA, m_DFaire_b);
	DDX_Text(pDX, IDC_DF_AIRE_GAMMA, m_DFaire_g);
	DDX_Text(pDX, IDC_DF_SUELO_BETA, m_DFgr_b);
	DDX_Text(pDX, IDC_DF_SUELO_GAMMA, m_DFgr_g);
	DDX_Text(pDX, IDC_DURACION_VERTIDO, m_tb);
	DDX_Text(pDX, IDC_FBLINDAJE_BETA, m_Fb_b);
	DDX_Text(pDX, IDC_FBLINDAJE_GAMMA, m_Fb_g);
	DDX_Text(pDX, IDC_FOCUPACION_AGUA, m_Ofinm);
	DDX_Text(pDX, IDC_FOCUPACION_ORILLA, m_Oforilla);
	DDX_Text(pDX, IDC_FPOND_PIEL, m_Wpiel);
	DDX_Text(pDX, IDC_TASA_ATMOSFERA, m_d);
	DDX_Text(pDX, IDC_CONC_AIRE, m_Ca);
	DDX_Text(pDX, IDC_FOCUPACION_EXT, m_Ofaire_ext);
	DDX_Text(pDX, IDC_FOCUPACION_INT, m_Ofaire_int);
	DDX_Text(pDX, IDC_CONC_ORILLA, m_Cso);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgParamEntradaIrradExt, CDialog)
	//{{AFX_MSG_MAP(DlgParamEntradaIrradExt)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgParamEntradaIrradExt message handlers
