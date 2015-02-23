// tabladis.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "TablaDis.h"

#include "..\MainFrame.h"
#include "DiagramaVistasDis.h"
#include "DiagDisView.h"

#include "..\..\model\des\DiagDis.h"
#include "..\..\model\BaseDoc.h"


/////////////////////////////////////////////////////////////////////////////
// CBotonTabla

CBotonTabla::CBotonTabla()
{
	m_viejoProc = NULL; 	// ¡OBLIGATORIO NULL INICIAL!
}

CBotonTabla::~CBotonTabla()
{
}

BEGIN_MESSAGE_MAP(CBotonTabla, CButton)
	//{{AFX_MSG_MAP(CBotonTabla)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEACTIVATE()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBotonTabla message handlers

WNDPROC* CBotonTabla::GetSuperWndProcAddr( )
{
	// static WNDPROC ViejoProc = NULL;  // ¡OBLIGATORIO NULL INICIAL!
	return &m_viejoProc;
}

void CBotonTabla::OnPaint()
{
	CButton::OnPaint();	 // ¡NECESARIO PARA QUE SE DIBUJEN LOS BOTONES!
	
	//CPaintDC dc(this); // device context for painting
	
	// Por razones muy sutiles, no usamos CPaintDC pues el pintado de un botón es muy especial y lo
	// hace el sistema a través del procedimiento por defecto de mensajes (Default()).
	// Lo que hacemos es dibujar sobre el área hasta que un nuevo PAINT haga efectivo el dibujado.
	
	CClientDC dc(this);
	CDC* pDC = &dc;
	
	// TODO: Add your message handler code here
	// Do not call CButton::OnPaint() for painting messages
    
    CRect Trect;
	GetClientRect( &Trect );  // Rectángulo actual del diálogo en coordenadas de dispositivo.
	int w = Trect.Width();
	int h = Trect.Height();
    
    CDC DCMem; 
	DCMem.CreateCompatibleDC( pDC );
	CBitmap TipoBMP;
 
    TipoBMP.LoadBitmap(m_bitmap);
    CBitmap* pViejoBMP = DCMem.SelectObject( &TipoBMP );
	
	DWORD BitOper = SRCCOPY;  // Dibuja encima independientemente de lo que hubiera
	CString Caption;
	GetWindowText(Caption);
	if (Caption != "") BitOper = SRCAND;  // Para que se mezcle el texto del botón con el dibujo.
	pDC->StretchBlt( w/10, h/10 , (w*8)/10, (h*8)/10 , &DCMem, 0, 0, m_size.cx, m_size.cy, BitOper );
   
    DCMem.SelectObject( pViejoBMP );  // No es OLE nunca, seleccionar el viejo sin miedo.
}

void CBotonTabla::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CButton::OnLButtonUp(nFlags, point);
	// En 16 bits funcionaba bien: ReleaseCapture();
	RedrawWindow();

    CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();  	
	pFrame->m_wndStatusBar.SetWindowText( "" );  
}

void CBotonTabla::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CButton::OnLButtonDown(nFlags, point);
	// En 16 bits funcionaba bien: SetCapture();
	RedrawWindow();	
    CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();  
	pFrame->m_wndStatusBar.SetWindowText( m_ayuda );     

}

int CBotonTabla::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	RedrawWindow();		
	return CButton::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

void CBotonTabla::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
    CRect r;
    GetClientRect(&r);
    if (!r.PtInRect(point)) RedrawWindow();		

	CButton::OnMouseMove(nFlags, point);
}


/////////////////////////////////////////////////////////////////////////////
// CTablaDis dialog

CTablaDis::CTablaDis()
	: CDialogBar()
{
	//{{AFX_DATA_INIT(CTablaDis)
	//}}AFX_DATA_INIT
}

void CTablaDis::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTablaDis)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTablaDis, CDialogBar)
	//{{AFX_MSG_MAP(CTablaDis)
	ON_BN_CLICKED(IDC_INS_BLQ_RETRO, OnInsBlqRetro)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_INS_BLQFUNC_DIAG, OnInsBlqfuncDiag)
	ON_BN_CLICKED(IDC_CPOSETIQDIAG, OnCposetiqdiag)
	ON_BN_CLICKED(IDC_CANCELAR_EDIC, OnCancelarEdic)
	ON_BN_CLICKED(IDC_INS_CONECT, OnInsConect)
	ON_BN_CLICKED(IDC_INS_CONECT_RETRO, OnInsConectRetro)
	ON_BN_CLICKED(IDC_MOVGRUPOSEL, OnMovgruposel)
	ON_BN_CLICKED(IDC_INS_BLQFUNC_DLL, OnInsBlqfuncDll)
	//}}AFX_MSG_MAP

	//Estos comandos son debido a que en un CDialogBar no se
	// activan por defecto los controles.

	ON_UPDATE_COMMAND_UI(IDC_INS_BLQ_RETRO, OnUpdateBoton)
	ON_UPDATE_COMMAND_UI(IDC_INS_BLQFUNC_DIAG, OnUpdateBoton)
	ON_UPDATE_COMMAND_UI(IDC_CPOSETIQDIAG, OnUpdateBoton)
	ON_UPDATE_COMMAND_UI(IDC_CANCELAR_EDIC, OnUpdateBoton)
	ON_UPDATE_COMMAND_UI(IDC_INS_CONECT, OnUpdateBoton)
	ON_UPDATE_COMMAND_UI(IDC_INS_CONECT_RETRO, OnUpdateBoton)
	ON_UPDATE_COMMAND_UI(IDC_MOVGRUPOSEL, OnUpdateBoton)
	ON_UPDATE_COMMAND_UI(IDC_INS_BLQFUNC_DLL, OnUpdateBoton)

END_MESSAGE_MAP()


void CTablaDis::OnUpdateBoton(CCmdUI* pCmdUI)
{
	pCmdUI->Enable();
}



BOOL CTablaDis::Crear(CDiagDis* diag, CString& titulo)
{
	p_diag = diag;

	// Create(IDD,NULL);  La antigua para CDialog
	CFrameWnd* win = (CFrameWnd*)AfxGetMainWnd();
	Create(win,IDD,CBRS_ALIGN_RIGHT,0);

	EnableDocking(CBRS_ALIGN_RIGHT | CBRS_ALIGN_LEFT);
	win->DockControlBar(this);

	OnInitDialog();

    setTitulo(titulo);

    return true;
}



BOOL CTablaDis::OnInitDialog( )
{
	// CDialogBar::OnInitDialog();
	
	CSize s(60,40);  // Todos los bitmap excepto uno.
	CWnd* bbdll;
	
	bbdll = GetDlgItem( IDC_INS_BLQFUNC_DLL );
	BBDLL.SubclassWindow(bbdll->GetSafeHwnd());
    BBDLL.m_bitmap = IDB_BLQFUNC_DLL;
	BBDLL.m_size = CSize(112,75);
	BBDLL.m_ayuda.LoadString(ID_INS_BLQFUNC_DLL);

    
	bbdll = GetDlgItem( IDC_INS_BLQFUNC_DIAG );
	BBDiag.SubclassWindow(bbdll->GetSafeHwnd());
    BBDiag.m_bitmap = IDB_BLQFUNC_DIAG;
	BBDiag.m_size = s;
	BBDiag.m_ayuda.LoadString(ID_INS_BLQFUNC_DIAG);
    	
	bbdll = GetDlgItem( IDC_INS_BLQ_RETRO );	
	BBRetro.SubclassWindow(bbdll->GetSafeHwnd());	
    BBRetro.m_bitmap = IDB_BLQRETRO;
	BBRetro.m_size = s;
	BBRetro.m_ayuda.LoadString(ID_INS_BLQ_RETRO);
	    	
	bbdll = GetDlgItem( IDC_INS_CONECT );	
	BConFunc.SubclassWindow(bbdll->GetSafeHwnd());	
    BConFunc.m_bitmap = IDB_CONFUNC;
	BConFunc.m_size = s;
	BConFunc.m_ayuda.LoadString(ID_INS_CONECT);
	    
	bbdll = GetDlgItem( IDC_INS_CONECT_RETRO );	
	BConRetro.SubclassWindow(bbdll->GetSafeHwnd());	
    BConRetro.m_bitmap = IDB_CONRETRO;
	BConRetro.m_size = s;
	BConRetro.m_ayuda.LoadString(ID_INS_CONECT_RETRO);
    
	bbdll = GetDlgItem( IDC_CPOSETIQDIAG );	
	BDTit.SubclassWindow(bbdll->GetSafeHwnd());	
    BDTit.m_bitmap = IDB_CPOSETIQDIAG;		
	BDTit.m_size = s;
	BDTit.m_ayuda.LoadString(ID_CPOSETIQDIAG);

	bbdll = GetDlgItem( IDC_MOVGRUPOSEL );	
	BDespl.SubclassWindow(bbdll->GetSafeHwnd());	
    BDespl.m_bitmap = IDB_MOVGRUPOSEL;		
	BDespl.m_size = s;
	BDespl.m_ayuda.LoadString(ID_MOVERGRUPO);

	bbdll = GetDlgItem( IDC_CANCELAR_EDIC );	
	BCancel.SubclassWindow(bbdll->GetSafeHwnd());	
    BCancel.m_bitmap = IDB_CANCELAR_EDIC;		
	BCancel.m_size = s;
	BCancel.m_ayuda.LoadString(ID_CANCELAR_EDIC);
		
	return true;
}


void CTablaDis::setTitulo(const char* titulo)
{
    Titulo = titulo;
	// En un CDialogBar está comprobado que no se actualiza automáticamente por esta función solo
	// Ni RedrawWindow ni UpdateWindow tampoco lo hace. Cuando se pega a un lado o se quita, se actualiza entonces.
	SetWindowText(titulo);  
}


/////////////////////////////////////////////////////////////////////////////
// CTablaDis message handlers

void CTablaDis::OnClose()   // Caso de cerrado manual
{
	// TODO: Add your message handler code here and/or call default
	CDiagramaVistasDis* pVistas = p_diag->getVistas();
	pVistas->m_verDlgTablaDis = false;
	
	CDialogBar::OnClose();
}

void CTablaDis::OnInsBlqfuncDll()
{
	// TODO: Add your command handler code here
 	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnInsBlqfuncDll();
}


void CTablaDis::OnInsBlqRetro()
{
	// TODO: Add your control notification handler code here
	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnInsBlqRetro();
}


void CTablaDis::OnInsBlqfuncDiag()
{
	// TODO: Add your control notification handler code here
	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnInsBlqfuncDiag();
}

void CTablaDis::OnCposetiqdiag()
{
	// TODO: Add your control notification handler code here
 	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnCPosEtiqDiag();
}

void CTablaDis::OnCancelarEdic()
{
	// TODO: Add your control notification handler code here
	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnCancelarEdic();
}

void CTablaDis::OnInsConect()
{
	// TODO: Add your control notification handler code here
	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnInsConect();
}

void CTablaDis::OnInsConectRetro()
{
	// TODO: Add your control notification handler code here
	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnInsConectRetro();
}

void CTablaDis::OnMovgruposel()
{
	// TODO: Add your control notification handler code here
	CDiagDisView* pView = ActivarPrimeraVista();

    pView->OnMovergrupo();
}


CDiagDisView* CTablaDis::ActivarPrimeraVista()
{
	// Activa la primera vista del documento

	CObList* views = &p_diag->getVistas()->m_views;
	CDiagDisView* pView = (CDiagDisView*)views->GetHead();

	CFrameWnd* pMainFrame = (CFrameWnd*)AfxGetMainWnd(); // Pues la actual es la tabla de botones.
	pMainFrame->ActivateFrame(SW_SHOW);
	CFrameWnd* pFrame = pView->GetParentFrame( );    
	pFrame->ActivateFrame(SW_SHOW);
	pView->SetActiveWindow( );      

	return pView;
}

