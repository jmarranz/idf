// DibDiagramaExe.cpp: implementation of the CDibDiagramaExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DibDiagramaExe.h"

#include "DiagExeView.h"
#include "..\BloqueVistas.h"
#include "..\DibBloque.h"

#include "..\..\model\exe\DiagExe.h"
#include "..\..\model\Bloque.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDibDiagramaExe::CDibDiagramaExe()
{

}

CDibDiagramaExe::~CDibDiagramaExe()
{

}

void CDibDiagramaExe::Dibujar(CDC* pDC, CBaseView* view)
{
	CDibDiagrama::Dibujar(pDC, view);

	// Dibujar recuadro del último ejecutado:
	if ((view)&&(!view->m_imprimiendo))  // Sólo útil en pantalla.
	{	
		CDiagExe* pdiag = p_diag->getExe();
		if (pdiag->p_bloqUltimo)
		{
			CRect r	= pdiag->p_bloqUltimo->getVistas()->getDibBloque()->m_rect;
			r = Escala( r, view );
			pDC->LPtoDP( r );
			CDiagExeView* viewExe = (CDiagExeView*)view;
			viewExe->m_rectTrk.m_rect = r;
			viewExe->m_rectTrk.Draw(pDC);	
		}
	}
}

void CDibDiagramaExe::CentrarBloque(CBloque* pbloque,CBaseView* view)
{
	if (!view) return;  // Pues ha podido llamarse indirectamente a través del diálogo de propiedades.
	
	if (m_scrollAuto)
	{
		CClientDC dc(view);
		view->OnPrepareDC(&dc);
	
		CRect TempRect;
		view->GetClientRect(TempRect);	
		dc.DPtoLP(TempRect);
    	CPoint pins = pbloque->getVistas()->getDibBloque()->m_rect.TopLeft();		

		CPoint p = Escala(pins, view);
		CPoint p2(p.x-TempRect.Width()/2 , p.y-TempRect.Height()/2);
		view->ScrollToPosition( p2 );

		// view->RedrawWindow();
	}
}
