// dcancel.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgCancelAuto.h"

#include "..\..\model\exe\DiagExe.h" 


/////////////////////////////////////////////////////////////////////////////
// CDlgCancelAuto dialog


CDlgCancelAuto::CDlgCancelAuto(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCancelAuto::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCancelAuto)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	p_diag = NULL;
}

void CDlgCancelAuto::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCancelAuto)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgCancelAuto, CDialog)
	//{{AFX_MSG_MAP(CDlgCancelAuto)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgCancelAuto message handlers

void CDlgCancelAuto::OnCancel()
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();

	p_diag->m_modoAuto = false;
}


BOOL CDlgCancelAuto::Crear(CDiagExe* diag)
{
	p_diag = diag;
	BOOL res = Create(IDD);
	CString stemp = "Cancelar Modo Auto: " + p_diag->m_nombreDiag;
    SetWindowText((LPCSTR) stemp);
	return res;
}

