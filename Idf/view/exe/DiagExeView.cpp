
// oleview.cpp : implementation of the CDiagExeView class


// Fichero original obtenido del ejemplo OCLIENT de Visual C++ 1.5

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagExeView.h"

#include "DiagramaVistasExe.h"
#include "DibDiagramaExe.h"

#include "..\..\model\DiagramaException.h"

#include "..\..\model\exe\DiagExe.h"
#include "..\..\model\exe\DiagExeDoc.h"

///////////////////////////////////////////////////////////////////////////
// CDiagExeView

CLIPFORMAT CDiagExeView::m_cfObjectDescriptor=NULL;

IMPLEMENT_DYNCREATE(CDiagExeView, CBaseView)

BEGIN_MESSAGE_MAP(CDiagExeView, CBaseView)
	//{{AFX_MSG_MAP(CDiagExeView)
	ON_WM_CHAR()
	ON_COMMAND(ID_CONSOLA_MOSTRAR, OnConsolaMostrar)
	ON_COMMAND(ID_CONSOLA_MOSTRAR_SISTEMA, OnConsolaMostrarSistema)
	ON_COMMAND(ID_CONSOLA_MOSTRAR_USUARIO, OnConsolaMostrarUsuario)
	ON_COMMAND(ID_CONSOLA_SALVAR_CON_DIAGRAMA, OnConsolaSalvarConDiagrama)
	ON_COMMAND(ID_INICIALIZAR_DIAGRAMA, OnInicializarDiagrama)
	ON_COMMAND(ID_INICIAR_CONECT, OnIniciarConect)
	ON_COMMAND(ID_SCROLL_AUTO, OnScrollAuto)
	ON_UPDATE_COMMAND_UI(ID_CONSOLA_MOSTRAR, OnUpdateConsolaMostrar)
	ON_UPDATE_COMMAND_UI(ID_CONSOLA_MOSTRAR_SISTEMA, OnUpdateConsolaMostrarSistema)
	ON_UPDATE_COMMAND_UI(ID_CONSOLA_MOSTRAR_USUARIO, OnUpdateConsolaMostrarUsuario)
	ON_UPDATE_COMMAND_UI(ID_CONSOLA_SALVAR_CON_DIAGRAMA, OnUpdateConsolaSalvarConDiagrama)
	ON_UPDATE_COMMAND_UI(ID_SCROLL_AUTO, OnUpdateScrollAuto)
	ON_COMMAND(ID_EDITAR_DIAG, OnEditarDiag)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CBaseView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CBaseView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagExeView construction/destruction

CDiagExeView::CDiagExeView()  
	: m_rectTrk ( CRect( CPoint(0,0), CSize(100,100)), CRectTracker::dottedLine) 
{
	if (m_cfObjectDescriptor == NULL)
		m_cfObjectDescriptor = (CLIPFORMAT)::RegisterClipboardFormat("Object Descriptor");
}

CDiagExeView::~CDiagExeView()
{
}

CDiagExe* CDiagExeView::getDiag()
{
	return (CDiagExe*)CBaseView::getDiag();
}

CDiagramaVistasExe* CDiagExeView::getVistas()
{
	return (CDiagramaVistasExe*)CBaseView::getVistas();
}

CDibDiagramaExe* CDiagExeView::getDibDiagrama()
{
	return (CDibDiagramaExe*)CBaseView::getDibDiagrama();
}

void CDiagExeView::OnInitialUpdate()
{
	CBaseView::OnInitialUpdate();

	// We can't pass MM_ANISOTROPIC to SetScrollSizes so we have to convert to MM_TEXT
/* Interfiere con mi código

	CSize size = GetDocument()->GetDocumentSize();
	CClientDC dc(NULL);
	size.cx = MulDiv(size.cx, dc.GetDeviceCaps(LOGPIXELSX), 100);
	size.cy = MulDiv(size.cy, dc.GetDeviceCaps(LOGPIXELSY), 100);
	SetScrollSizes(MM_TEXT, size);
*/
}

/////////////////////////////////////////////////////////////////////////////
// CDiagExeView drawing

void CDiagExeView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	CBaseView::OnPrepareDC(pDC, pInfo);

/* Interfiere con mi código y además SetViewportExt y SetWindowExt no hacen nada en MM_LOMETRIC o MM_HIMETRIC

	// set up a reasonable default context
	pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	pDC->SetBkColor(::GetSysColor(COLOR_WINDOW));

	// LOENGLISH units are based on physical inches
	// We want logical inches so we have to do it differently
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportExt(
		pDC->GetDeviceCaps(LOGPIXELSX), pDC->GetDeviceCaps(LOGPIXELSY));
	pDC->SetWindowExt(100,-100);
*/
}

/////////////////////////////////////////////////////////////////////////////
// CDiagExeView printing

BOOL CDiagExeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


/////////////////////////////////////////////////////////////////////////////
// CDiagExeView diagnostics

#ifdef _DEBUG
void CDiagExeView::AssertValid() const
{
	CBaseView::AssertValid();
}

void CDiagExeView::Dump(CDumpContext& dc) const
{
	CBaseView::Dump(dc);
}

#endif //_DEBUG


void CDiagExeView::DocToClient(CRect& rect)
{
	rect = EscalaVisual(rect);
	
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.LPtoDP(&rect); // convert logical rect to device rect
	rect.NormalizeRect();
}

void CDiagExeView::ClientToDoc(CRect& rect)
{
	rect = EscalaVisualInversa(rect);

	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&rect); // convert device rect to logical rect
}

void CDiagExeView::DocToClient(CSize& size)
{
	size = EscalaVisual(size);
	
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.LPtoDP(&size); // convert logical size to device size
	size.cx = abs(size.cx);
	size.cy = abs(size.cy);
}

void CDiagExeView::ClientToDoc(CSize& size)
{
	size = EscalaVisualInversa(size);
	
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&size); // convert device rect to logical rect
	size.cx = abs(size.cx);
	size.cy = abs(size.cy);
}

void CDiagExeView::DocToClient(CPoint& point)
{
	point = EscalaVisual(point);
	
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.LPtoDP(&point); // convert logical point to device point
}

void CDiagExeView::ClientToDoc(CPoint& point)
{
	point = EscalaVisualInversa(point);

	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point); // convert device point to logical point
}


void CDiagExeView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	MessageBeep(0);     // to test for proper focus transfer

	CBaseView::OnChar(nChar, nRepCnt, nFlags);
}


BOOL CDiagExeView::GetObjectInfo(COleDataObject* pDataObject,
	CSize* pSize, CSize* pOffset)
{
	ASSERT(pSize != NULL);

	// get object descriptor data
	HGLOBAL hObjDesc = pDataObject->GetGlobalData(m_cfObjectDescriptor);
	if (hObjDesc == NULL)
	{
		if (pOffset != NULL)
			*pOffset = CSize(0, 0); // fill in defaults instead
		*pSize = CSize(0, 0);
		return false;
	}
	ASSERT(hObjDesc != NULL);

	// otherwise, got CF_OBJECTDESCRIPTOR ok.  Lock it down and extract size.
	LPOBJECTDESCRIPTOR pObjDesc = (LPOBJECTDESCRIPTOR)GlobalLock(hObjDesc);
	ASSERT(pObjDesc != NULL);
	pSize->cx = (int)pObjDesc->sizel.cx;
	pSize->cy = (int)pObjDesc->sizel.cy;
	if (pOffset != NULL)
	{
		pOffset->cx = (int)pObjDesc->pointl.x;
		pOffset->cy = (int)pObjDesc->pointl.y;
	}
	GlobalUnlock(hObjDesc);
	GlobalFree(hObjDesc);

	// successfully retrieved pSize & pOffset info
	return true;
}

void CDiagExeView::OnConsolaMostrar() 
{
	// TODO: Add your command handler code here
	CDiagramaVistasExe* pVistas = getVistas();
	pVistas->CambiarMostrarConsola();
}

void CDiagExeView::OnConsolaMostrarSistema() 
{
	// TODO: Add your command handler code here
	CDiagramaVistasExe* pVistas = getVistas();
	pVistas->m_conSistema = !pVistas->m_conSistema;		
}

void CDiagExeView::OnConsolaMostrarUsuario() 
{
	// TODO: Add your command handler code here
	CDiagramaVistasExe* pVistas = getVistas();
	pVistas->m_conUsuario = !pVistas->m_conUsuario;	
}

void CDiagExeView::OnConsolaSalvarConDiagrama() 
{
	// TODO: Add your command handler code here
	CDiagramaVistasExe* pVistas = getVistas();
	pVistas->m_salvarConsola = !pVistas->m_salvarConsola;	
}

void CDiagExeView::OnInicializarDiagrama() 
{
	// TODO: Add your command handler code here
	getDiag()->IniciarExplicito();	
}

void CDiagExeView::OnIniciarConect() 
{
	// TODO: Add your command handler code here
	CDiagExe* pdiag = getDiag();
	pdiag->IniciarConectoresExplicito();    // Inicia la cadena de llamadas para iniciar todo el diagrama.
}

void CDiagExeView::OnScrollAuto() 
{
	// TODO: Add your command handler code here
	CDibDiagrama* pdibdiag = getVistas()->getDibDiagrama();

	pdibdiag->m_scrollAuto = !pdibdiag->m_scrollAuto;	
}

void CDiagExeView::OnUpdateConsolaMostrarUsuario(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CDiagramaVistasExe* pVistas = getVistas();
	pCmdUI->SetCheck( pVistas->m_conUsuario );
}


void CDiagExeView::OnUpdateConsolaMostrar(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CDiagramaVistasExe* pVistas = getVistas();
	pCmdUI->SetCheck( pVistas->m_mostrarConsola );
}

void CDiagExeView::OnUpdateConsolaSalvarConDiagrama(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDiagramaVistasExe* pVistas = getVistas();

	pCmdUI->SetCheck( pVistas->m_salvarConsola );	
}

void CDiagExeView::OnUpdateScrollAuto(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CDibDiagrama* pdibdiag = getVistas()->getDibDiagrama();

	pCmdUI->SetCheck( pdibdiag->m_scrollAuto );		
}

void CDiagExeView::OnUpdateConsolaMostrarSistema(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CDiagramaVistasExe* pVistas = getVistas();
	pCmdUI->SetCheck( pVistas->m_conSistema );
}


void CDiagExeView::OnEditarDiag() 
{
	// TODO: Add your command handler code here
	CString fichGenerado;
	try
	{
		getDiag()->GenerarLDD(fichGenerado,false); 
	}
	catch(Exception* ex)
	{
		getDiag()->getVistas()->Mensaje(ex);
		delete ex;
		getDiag()->getVistas()->Mensaje("No puede generarse el archivo XML");
		return;
	}

	// Ejecutar 
	CGlobal::m_fichero = fichGenerado; // FichGenerado será de path absoluto
	CGlobal::m_esLDD = true;

	CGlobal::NuevoDiagSinPrompt(true);

	CGlobal::m_fichero = "";	
}
