// BaseView.cpp : implementation of the CBaseView class
//

#include "stdafx.h"
#include "..\Idf.h"
#include "BaseView.h"

#include "DiagramaVistas.h"
#include "DibDiagrama.h"

#include "..\model\DiagBase.h"
#include "..\model\BaseDoc.h"
#include "..\model\DiagramaException.h"

/////////////////////////////////////////////////////////////////////////////
// CBaseView

IMPLEMENT_DYNCREATE(CBaseView, CScrollView)

BEGIN_MESSAGE_MAP(CBaseView, CScrollView)
	//{{AFX_MSG_MAP(CBaseView)
	ON_WM_LBUTTONUP()
	ON_WM_DESTROY()
	ON_COMMAND(ID_AJUSTAR_VENTANA, OnAjustarVentana)
	ON_COMMAND(ID_ZOOM_RESTAURAR, OnZoomRestaurar)
	ON_COMMAND(ID_ZOOM_ACERCAR, OnZoomAcercar)
	ON_COMMAND(ID_ZOOM_ALEJAR, OnZoomAlejar)
	ON_COMMAND(ID_VER_TODO, OnVerTodo)
	ON_WM_RBUTTONUP()
	ON_WM_SETCURSOR()
	ON_UPDATE_COMMAND_UI(ID_ZOOM_ACERCAR, OnUpdateZoom)
	ON_COMMAND(ID_ANALIZAR_DLL, OnAnalizarDll)
	ON_COMMAND(ID_CLASES_USADAS_SIN_DLL, OnClasesUsadasSinDll)
	ON_COMMAND(ID_GENERAR_LDD, OnGenerarLdd)
	ON_COMMAND(ID_GENERAR_METAFILE, OnGenerarMetafile)
	ON_COMMAND(ID_OPERAC_ZOOM, OnOperacZoom)
	ON_UPDATE_COMMAND_UI(ID_OPERAC_ZOOM, OnUpdateOperacZoom)
	ON_COMMAND(ID_PROP_DIAG, OnPropDiag)
	ON_COMMAND(ID_GENERAR_LDDORIGEN, OnGenerarLddorigen)
	ON_WM_PAINT()
	ON_UPDATE_COMMAND_UI(ID_ZOOM_ALEJAR, OnUpdateZoom)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_RESTAURAR, OnUpdateZoom)
	ON_UPDATE_COMMAND_UI(ID_VER_TODO, OnUpdateZoom)
	ON_UPDATE_COMMAND_UI(ID_AJUSTAR_VENTANA, OnUpdateZoom)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseView construction/destruction


CBrush NEAR CBaseView::m_brHatch;

CBaseView::CBaseView()  
{
	// TODO: add construction code here
	if (m_brHatch.m_hObject == NULL)
		m_brHatch.CreateHatchBrush(HS_DIAGCROSS, RGB(0,0,0));
	
	m_escala = 1.0;
    m_imprimiendo = false;
	p_diag = NULL;
}

CBaseView::~CBaseView()
{
}

CBaseDoc* CBaseView::GetDocument()  // Ojo no hacer virtual para que en las derivadas pueda devolver diferente tipo.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDoc)));
	return (CBaseDoc*) m_pDocument;
}

CDiagramaVistas* CBaseView::getVistas()
{
	if (p_diag == NULL) return NULL;
	return p_diag->getVistas();
}

CDibDiagrama* CBaseView::getDibDiagrama()
{
	if (getVistas() == NULL) return NULL;
	return getVistas()->getDibDiagrama();
}

CDiagBase* CBaseView::getDiag()
{
	return p_diag;
}

/////////////////////////////////////////////////////////////////////////////
// CBaseView drawing

void CBaseView::OnDraw(CDC* pDC)
{

	// TODO: add draw code for native data here
	// TODO: also draw all OLE items in the document
		
    // Código propio desde aquí:

	if (!pDC->IsPrinting())   // Rellena el área visual fuera del DIN A4 con un patrón rallado. Copiado y modificado del ejemplo OLECLIENT
	{
		m_brHatch.UnrealizeObject();
		CPoint point(0, 0);
		pDC->LPtoDP(&point);
		pDC->SetBrushOrg(point.x % 8, point.y % 8);

		CRect rcClip;
		GetClientRect(&rcClip);
		OnPrepareDC(pDC);
		pDC->DPtoLP(&rcClip); // convert device point to logical point
		
		CSize docSize = getDiagSize();
		if (rcClip.right > docSize.cx)
		{
			CRect rcFill(rcClip);
			rcFill.left = max(rcFill.left,docSize.cx);
			pDC->FillRect(rcFill,&m_brHatch);
		}
		if (rcClip.bottom < -docSize.cy)
		{
			CRect rcFill(rcClip);
			rcFill.top = min(rcFill.top,-docSize.cy);
			pDC->FillRect(rcFill,&m_brHatch);
		}
	}

	CDibDiagrama* pdibDiag = getDibDiagrama();	

	pdibDiag->Dibujar(pDC, this);
}


/////////////////////////////////////////////////////////////////////////////
// CBaseView printing

BOOL CBaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CBaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}


void CBaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}
                 
/////////////////////////////////////////////////////////////////////////////
// CBaseView diagnostics

#ifdef _DEBUG
void CBaseView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBaseView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}


#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseView message handlers


void CBaseView::OnInitialUpdate()
{
	// TODO: remove this code when final selection model code is written

	// Código propio desde aquí:

	p_diag = GetDocument()->getDiag();

	CMDIChildWnd* frame = (CMDIChildWnd *) GetParentFrame( );
	frame->ShowWindow(SW_SHOWMAXIMIZED);

	
	SetScrollSizes( MM_LOMETRIC, getDiagSize() );	
    
    // Creamos los diálogos de bloques en la vista.
    
	getVistas()->addView(this);	

	CScrollView::OnInitialUpdate();  // Llamamos al final para que SetScrollSizes tenga ya efecto.
}


void CBaseView::OnDestroy()
{
	CScrollView::OnDestroy();
	
	// TODO: Add your message handler code here
	
	CDiagramaVistas* pvistas = getVistas();
	if (pvistas != NULL) pvistas->removeView(this);
}


int CBaseView::Redondeo(double num)
{
	// Convierte a entero pero al valor más cercano en valor absoluto 	
	int res;
    BOOL negativo = false;
	BOOL cero = false;
	if (num < 0) 
	{                                                                                                                                                                                  
		negativo = true;
		num = - num;  // Paso a positivo
    }
    if ( 0 == num ) cero = true;
    
 	res = ((num - (double)(int)num)>(double)0.5)?((int)(num)+1):(int)num;  
	if ((!cero)&&( 0 == res )) res = 1;   // Si no era cero antes de hacer el redondeo y al redondear se hace cero, redondeamos a 1 pues puede haber errores de división por cero etc.
	if (negativo) res = - res;  // El resultado ha de ser negativo
	return res; 
}


CSize CBaseView::getDiagSize()
{
	return EscalaVisual(getVistas()->getDiagSize());
} 

CPoint CBaseView::EscalaVisual(CPoint& pto)
{
	// Aplica una escala sólo para modificar como se visualiza en pantalla. 	

    CPoint p;
    if (!m_imprimiendo)
    {            
 		if (m_escala != 1.0)	
			p = CPoint( Redondeo(((double)pto.x) * m_escala) , Redondeo(((double)pto.y) * m_escala));
		else 
			p = pto;
	}
	else p = pto;

	return p;
}


CRect CBaseView::EscalaVisual( CRect& rect )
{
	CRect r;
	CPoint p1, p2;
	p1 = EscalaVisual(rect.TopLeft());
	p2 = EscalaVisual(rect.BottomRight());
	r = CRect(p1.x, p1.y, p2.x, p2.y);
	return r;
}


CSize CBaseView::EscalaVisual( CSize& size )
{
	CPoint p( size.cx, size.cy );
	p = EscalaVisual( p );
	CSize Tsize = CSize( p.x , p.y );
    return Tsize;
}

CPoint CBaseView::EscalaVisualInversa( CPoint& pto )
{
	// Obtiene el valor de pantalla sin escalar. 	

    CPoint p;
    if (!m_imprimiendo)
    {            
 		if (m_escala != 1.0)	
			p = CPoint( Redondeo(((double)pto.x) / m_escala) , Redondeo(((double)pto.y) / m_escala));
		else 
			p = pto;
	}
	else p = pto;

	return p;
}

CRect CBaseView::EscalaVisualInversa( CRect& rect)
{
	CRect r;
	CPoint p1, p2;
	p1 = EscalaVisualInversa(rect.TopLeft());
	p2 = EscalaVisualInversa(rect.BottomRight());
	r = CRect(p1.x, p1.y, p2.x, p2.y);
	return r;
}

CSize CBaseView::EscalaVisualInversa( CSize& size)
{
	CPoint p( size.cx, size.cy );
	p = EscalaVisualInversa( p );
	CSize Tsize = CSize( p.x , p.y );
    return Tsize;
}

void CBaseView::OnPrint( CDC* pDC, CPrintInfo* pInfo )
{
 	m_imprimiendo = true;
 	CScrollView::OnPrint(pDC, pInfo);
 	m_imprimiendo = false;	
}


void CBaseView::OnAjustarVentana()
{
	// TODO: Add your command handler code here

	ResizeParentToFit();
}


void CBaseView::OnZoomRestaurar()
{
	// TODO: Add your command handler code here
    m_escala = 1;
	SetScrollSizes( MM_LOMETRIC, getDiagSize() );		
	
	getDiag()->getVistas()->Actualizar(this);
}


void CBaseView::OnZoomAcercar()
{
	// TODO: Add your command handler code here
	m_escala += 0.2;
	CSize size = getDiagSize();
	SetScrollSizes( MM_LOMETRIC, size );  // Define el nuevo dimensionado del scroll para que abarque las nuevas dimensiones. 

	getVistas()->Actualizar(this);
}


void CBaseView::OnZoomAlejar()
{
	// TODO: Add your command handler code here
	m_escala -= 0.2;
    if (m_escala <= 0) m_escala += 0.2;  // Restauramos, no se puede más 
    CSize size = getDiagSize();
	SetScrollSizes( MM_LOMETRIC, size );   // Define el nuevo dimensionado del scroll para que abarque las nuevas dimensiones.  

	getVistas()->Actualizar(this);
}

             
void CBaseView::OnVerTodo()     // Ajusta la escala del diagrama para que se vea entero en la ventana actual.
{
	// TODO: Add your command handler code here
	m_escala = 1;
	CRect rect;
	GetWindowRect(rect);  // Coordenadas de pantalla.
    CSize size = getVistas()->getDiagSize(); // El DIN A4 en coordenadas lógicas sin escala visual

	CClientDC dc(this);
	OnPrepareDC(&dc);
    dc.DPtoLP(rect);

	CSize sven(rect.Width(),-rect.Height()); 
    double relx = (double)sven.cx /(double)size.cx;
    double rely = (double)sven.cy /(double)size.cy;  // En ambos se obtienen valores positivos aunque sean negativos, al dividir.
	m_escala = min( relx, rely );  // Valor necesario de la escala para que ajuste dentro el diagrama.
    
	size = getDiagSize();
    SetScrollSizes( MM_LOMETRIC, size );   // Define el nuevo dimensionado del scroll para que abarque las nuevas dimensiones.  
	
	getVistas()->Actualizar(this);	
}


void CBaseView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CScrollView::OnLButtonUp(nFlags, point);
	
	// Por el hecho de pasar por aquí es que hemos pulsado el área de la ventana sin bloque.	

	if (nFlags == MK_CONTROL) int kk=0; // Por ahora no hacer nada.
	else
	{
		CDibDiagrama* pdibdiag = getDibDiagrama();

		if (pdibdiag->m_operZoom) OnZoomAcercar();
    }
}


void CBaseView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CScrollView::OnRButtonUp(nFlags, point);

	if (nFlags == MK_CONTROL) int kk=0; // Por ahora no hacer nada.
	else
	{
		CDibDiagrama* pdibdiag = getDibDiagrama();
		if (pdibdiag->m_operZoom) OnZoomAlejar();
	}
}


BOOL CBaseView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	if ((pWnd == this) && (nHitTest == HTCLIENT))
	{
		CDibDiagrama* pdibdiag = getVistas()->getDibDiagrama();

		if (pdibdiag->m_operZoom)
		{
			::SetCursor(AfxGetApp()->LoadCursor(IDC_AREAZOOM));
			return true;
		}
    }

	return CScrollView::OnSetCursor(pWnd, nHitTest, message);  // Pone el cursor de flecha habitual
}

void CBaseView::OnUpdateZoom(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CDibDiagrama* pdibdiag = getDibDiagrama();

	pCmdUI->Enable( pdibdiag->m_operZoom );		
}

CPoint CBaseView::Cliente_A_mm(CPoint& point)
{
	// Devuelve un punto de coordenadas cliente de la ventana a mm en DINA4 con dimensiones positivas.
	CPoint pMM = point;
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&pMM); 

	return pMM = getDibDiagrama()->EscalaInversa(pMM, this); 
}

CRect CBaseView::Cliente_A_mm(CRect& rect)
{
	CPoint p1, p2;
	p1 = Cliente_A_mm(rect.TopLeft());
	p2 = Cliente_A_mm(rect.BottomRight());
	CRect r(p1.x, p1.y, p2.x, p2.y);
	return r;
}


void CBaseView::OnAnalizarDll() 
{
	// TODO: Add your command handler code here
	getVistas()->AnalizarDll();
}

void CBaseView::OnClasesUsadasSinDll() 
{
	// TODO: Add your command handler code here
	getVistas()->GenerarCodigoDiagrama();	
}

void CBaseView::OnGenerarLdd() 
{
	// TODO: Add your command handler code here
	CString Fichres;
	try
	{
		getDiag()->GenerarLDD(Fichres,true);
	}
	catch(Exception* ex)
	{
		getDiag()->getVistas()->Mensaje(ex);
		delete ex;
		getVistas()->Mensaje("No puede generarse el archivo XML");
	}
}

void CBaseView::OnGenerarMetafile() 
{
	// TODO: Add your command handler code here
	getDibDiagrama()->GenerarMetafile();
}

void CBaseView::OnOperacZoom() 
{
	// TODO: Add your command handler code here
	CDibDiagrama* pdibdiag = getDibDiagrama();
	pdibdiag->m_operZoom	= !pdibdiag->m_operZoom;	
}

void CBaseView::OnUpdateOperacZoom(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDibDiagrama* pdibdiag = getDibDiagrama();
	pCmdUI->SetCheck( pdibdiag->m_operZoom );	
}

void CBaseView::OnPropDiag() 
{
	// TODO: Add your command handler code here
	getVistas()->Propiedades();		
}


void CBaseView::OnGenerarLddorigen() 
{
	// TODO: Add your command handler code here
	getDiag()->GenerarLDDOriginal();	
}

void CBaseView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	/* Esta función es debida a que CWnd::UpdateWindow() no llama 
	a OnDraw(), OnDraw() llamada por CDocument::UpdateAllViews()
	pero este método no es paropiado si queremos no depender del
	documento 
	*/

	OnDraw(&dc);

	// Do not call CScrollView::OnPaint() for painting messages
}
