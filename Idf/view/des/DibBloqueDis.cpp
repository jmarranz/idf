// DibBloqueDis.cpp: implementation of the CDibBloqueDis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DibBloqueDis.h"

#include "..\BaseView.h"
#include "..\DiagramaVistas.h"
#include "..\DibDiagrama.h"

#include "..\..\model\Bloque.h"
#include "..\..\model\DiagBase.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDibBloqueDis::CDibBloqueDis()
{
	m_seleccionado = false;
}

CDibBloqueDis::~CDibBloqueDis()
{

}

BOOL CDibBloqueDis::Dibujar(CDC* pDC, CBaseView* view)
{
	if ((NULL == view)||(view->m_imprimiendo))   // Podríamos usar pDC->IsPrinting() pero Imprimiendo se usa en otros lugares donde no tenemos el pDC
	{
		// Nada por ahora
	}
	else
	{
		if (m_seleccionado)  
		{	
			CDiagBase* pdiag = p_bloque->getDiag();
			CDibDiagrama* pdibdiag = pdiag->getVistas()->getDibDiagrama();

			CRect r = m_rect;
			r = pdibdiag->Escala( r, view );
			pDC->LPtoDP( r );
			CRectTracker RectTrk( r, CRectTracker::dottedLine); 
			RectTrk.Draw(pDC);	
		}
	}
	
	return CDibBloque::Dibujar(pDC,view);
}

void CDibBloqueDis::Seleccionar(BOOL Seleccionar /*= true*/, CRect * prsel /*= NULL*/, CBaseView* view /* = NULL */)
{
	if (NULL != prsel)
	{		
		CClientDC dc(view);
		view->OnPrepareDC(&dc);

		CDibDiagrama* pdibdiag = p_bloque->getDiag()->getVistas()->getDibDiagrama();

		CRect rtemp = pdibdiag->Escala(m_rect, view);  // En lógicas
		dc.LPtoDP(rtemp);  // En cliente.
		CRect rtempInter; 
		rtempInter.IntersectRect( &rtemp, prsel );
		if (rtempInter != rtemp) return; // Si no es igual es que rtemp (el bloque) está parte o todo él fuera del rectángulo de selección prsel, no seleccionamos.
	}
	m_seleccionado = Seleccionar;
}

BOOL CDibBloqueDis::EsSeleccionado() 
{ 
	return m_seleccionado; 
}

