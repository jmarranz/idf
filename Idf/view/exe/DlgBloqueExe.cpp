// dlgbloq.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgBloqueExe.h"

#include "..\BloqueVistas.h"
#include "..\exe\BloqueVistasExe.h"

#include "..\..\model\Bloque.h"
#include "..\..\model\exe\BloqueExe.h"


/////////////////////////////////////////////////////////////////////////////
// CDlgBloqueExe dialog


CDlgBloqueExe::CDlgBloqueExe( CWnd* pParent /*=NULL*/)    
	: CDlgBloque(CDlgBloqueExe::IDD, pParent) 
{
	//{{AFX_DATA_INIT(CDlgBloqueExe)
	m_Etiq = "";
	//}}AFX_DATA_INIT

}

void CDlgBloqueExe::DoDataExchange(CDataExchange* pDX)
{
	CDlgBloque::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBloqueExe)
	DDX_Control(pDX, IDC_ETIQ, m_CtrlEtiq);
	DDX_Text(pDX, IDC_ETIQ, m_Etiq);
	DDV_MaxChars(pDX, m_Etiq, 32000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgBloqueExe, CDialog)
	//{{AFX_MSG_MAP(CDlgBloqueExe)
	ON_WM_LBUTTONUP()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_RBUTTONUP()
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_OPERACIONES, OnOperaciones)
	ON_COMMAND(ID_PROP_DLL, OnPropDll)
	ON_COMMAND(ID_PROP_GEN, OnPropGen)
	ON_COMMAND(ID_PROP_ESPEC, OnPropEspec)
	ON_COMMAND(ID_PROP_INFORM, OnPropInform)
	ON_COMMAND(ID_PROP_LISTACONECT, OnPropListaconect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgBloqueExe message handlers
                     
BOOL CDlgBloqueExe::Crear(CBaseView* view,CBloqueVistas* pvistas)
{
	return CDlgBloque::Crear(view, pvistas,IDD);
}             

BOOL CDlgBloqueExe::OnInitDialog( )
{
	CBloque* pbloque = p_vistas->getBloque();
    m_Etiq = pbloque->getEtiqueta();

    CDlgBloque::OnInitDialog();

	return true;
}

void CDlgBloqueExe::ActualizaEtiq()
{
	CBloque* pbloque = p_vistas->getBloque();

    SetDlgItemText( IDC_ETIQ, pbloque->getEtiqueta() );  // Actualiza el texto de la etiqueta.
}

void CDlgBloqueExe::MoverEtiqueta(CRect& rect)
{
	m_CtrlEtiq.MoveWindow(rect);
}

void CDlgBloqueExe::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDlgBloque::OnLButtonUp(nFlags, point);

	CBloque* pbloque = p_vistas->getBloque();
    
	if (nFlags & MK_CONTROL) pbloque->getExe()->ComienzoEjecucionAuto(p_view);  // Ejecución Auto empezando por el bloque.
	else pbloque->getExe()->ComienzoEjecucion(p_view);  // Ejecución del bloque o si es diseño asociación al conductor
}

void CDlgBloqueExe::OnPaint()
{ 
	CDlgBloque::OnPaint();
}

HBRUSH CDlgBloqueExe::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return CDlgBloque::OnCtlColor(pDC,pWnd,nCtlColor);
}

void CDlgBloqueExe::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDlgBloque::OnRButtonUp(nFlags, point);
}

BOOL CDlgBloqueExe::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	return CDlgBloque::OnSetCursor(pWnd, nHitTest, message); // Para cuando está en el borde etc.
}

void CDlgBloqueExe::OnOperaciones()
{
	// TODO: Add your command handler code here
	p_vistas->getExe()->DlgOperaciones();	
}

void CDlgBloqueExe::OnPropDll()
{
	// TODO: Add your command handler code here
	p_vistas->PropUsuario();
}


void CDlgBloqueExe::OnPropGen()
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(0);		
}


void CDlgBloqueExe::OnPropEspec() 
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(1);	
}

void CDlgBloqueExe::OnPropListaconect() 
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(2);	
}

void CDlgBloqueExe::OnPropInform() 
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(3);	
}

void CDlgBloqueExe::cargarMenu(CPoint point)
{
	CBloque* pbloque = p_vistas->getBloque();

	CMenu bar;
	if (bar.LoadMenu(IDR_MENU_BLOQUE_FUNC_DCHO))
	{
		CMenu& popup = *bar.GetSubMenu(0);
		ASSERT(popup.m_hMenu != NULL);

		ClientToScreen(&point);
		popup.TrackPopupMenu(TPM_RIGHTBUTTON,point.x, point.y, this );
			// AfxGetMainWnd()); // route commands through main window
	}
}


