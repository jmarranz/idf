// DibConectDis.cpp: implementation of the CDibConectDis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DibConectDis.h"

#include "DlgNudoCon.h"
#include "DiagDisView.h"
#include "ConectorNudoDis.h"

#include "..\DlgBloque.h"
#include "..\DibDiagrama.h"
#include "..\DiagramaVistas.h"


#include "..\..\model\BaseDoc.h"
#include "..\..\model\Conect.h"
#include "..\..\model\des\DiagDis.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDibConectDis::CDibConectDis()
{

}

CDibConectDis::~CDibConectDis()
{

}

void CDibConectDis::Dibujar(CDC* pDC, CBaseView* view)
{
	CDibConect::Dibujar(pDC,view);

	Actualizar(view);
	// Debe estar asegurado que el conector tiene dos nudos (inicial y final)
	CConNudo* pNudoIni = (CConNudo*)m_listaNudos.GetHead();
	CConNudo* pNudoFin = (CConNudo*)m_listaNudos.GetTail();
	
	ActualizaPosFlechaFinal();  // Para que la orientación de la flecha sea la correcta al haber cambios en su tramo.
}


void CDibConectDis::Actualizar()
{
	for (POSITION pos = m_listaNudos.GetHeadPosition(); pos != NULL; )
	{
		CConectorNudoDis* pNudo = (CConectorNudoDis*)m_listaNudos.GetNext(pos);	
		pNudo->Actualizar();	
	}
}


void CDibConectDis::Actualizar(CBaseView* view)
{
	for (POSITION pos = m_listaNudos.GetHeadPosition(); pos != NULL; )
	{
		CConectorNudoDis* pNudo = (CConectorNudoDis*)m_listaNudos.GetNext(pos);	
		pNudo->Actualizar(view);	
	}
}

void CDibConectDis::ActualizarExcepto(CBaseView* view)   // Actualiza TODOS los nudos del conector de la vista dada.
{
	for (POSITION pos = m_listaNudos.GetHeadPosition(); pos != NULL; )
	{
		CConectorNudoDis* pNudo = (CConectorNudoDis*)m_listaNudos.GetNext(pos);	
		pNudo->ActualizarExcepto(view);	
	}
}


void CDibConectDis::ActualizaPosFlechaFinal()
{
	CConNudo* pNudoFin = (CConNudo*)m_listaNudos.GetTail();
    
	getpFlecha()->m_ptoInsFlecha = pNudoFin->m_posNudo;  // Final del conector
	CPoint pini = pNudoFin->p_nudoPrev->m_posNudo;  // pNudoPrev no puede ser nulo, suponemos que hay dos nudos ya definidos.
	CPoint pfin = pNudoFin->m_posNudo;
    m_flecha.m_orienta = CalculaOrientacion(pini,pfin);
}

int CDibConectDis::CalculaOrientacion(CPoint pini, CPoint pfin)
{
    // Vale para el cálculo de la orientación de la flecha pero también para la aproximación por gravedad de un nudo a un bloque.
    int x = pfin.x - pini.x;
    int y = - (pfin.y - pini.y); // Lo ponemos en coordenadas cartesianas para que el extremo de flecha si es hacia arriba sea la y positiva.

    int Orienta = NORTE;
	if ( x >= 0 )
	{	    
    	if ( x >= abs(y) ) Orienta = ESTE;
    	else  
    	{
    		if ( y >= 0 ) Orienta = NORTE; 
            else Orienta = SUR;
        }
	}
	else  // x < 0
	{
	    if ( (-x) >= abs(y) ) Orienta = OESTE;
	    else
	    {
	    	if ( y >= 0 ) Orienta = NORTE;
		    else Orienta = SUR;	    
	    }
	}    
	return Orienta;
}


void CDibConectDis::Destruir()
{

	CDibConect::Destruir();
}


void CDibConectDis::MoverConGravedad(CDiagDisView* view, CDlgBloque* pDlgBloq, CPoint PtoGrav)
{
	// PtoGrav es el punto en el que se pulsó sobre el bloque en coordenadas cliente del diálogo del bloque

	CDiagDis* pDiagDis = p_conect->getDiagDis();
	CConectorNudoDis* pNudo = NULL;
	if (ASOCIABLQINI == pDiagDis->m_estadoEdic)
	{
       	POSITION pos = m_listaNudos.GetHeadPosition();
       	pNudo = (CConectorNudoDis*)m_listaNudos.GetAt( pos );
	}  
	else
	if (ASOCIABLQFIN == pDiagDis->m_estadoEdic)
	{
       	POSITION pos = m_listaNudos.GetTailPosition();
       	pNudo = (CConectorNudoDis*)m_listaNudos.GetAt( pos );
	}  
    else return;

	CDlgNudoCon* pDlgNudo = pNudo->BuscaDialogoNudo(view);       
    
    CRect rBlq;
    pDlgBloq->GetWindowRect(&rBlq);  // Se incluye la barra del título y bordes en coordenadas de pantalla.
    pDlgBloq->ClientToScreen(&PtoGrav); // En coordenadas de pantalla.

	CPoint PIns = rBlq.TopLeft();
    int w = rBlq.Width();
    int h = rBlq.Height();
    CPoint centro = CPoint(  PIns.x + w / 2 , + PIns.y + h / 2  );
    int lado = CalculaOrientacion(centro, PtoGrav);

    switch( lado )
    {
    	case NORTE:
    	{
    	 	PtoGrav = CPoint( rBlq.Width() / 2, 0);
    	    break;
    	}
    	case SUR:
    	{
    	 	PtoGrav = CPoint( rBlq.Width() / 2, rBlq.Height());
    	    break;
    	}
    	case ESTE:
    	{
    	 	PtoGrav = CPoint( rBlq.Width(),  rBlq.Height() /2 );
    	    break;
    	}
    	case OESTE:
    	{
    	 	PtoGrav = CPoint( 0, rBlq.Height() / 2);
    	    break;
    	}
	}
    PtoGrav.x = PtoGrav.x + PIns.x;
    PtoGrav.y = PtoGrav.y + PIns.y;    

    pDlgNudo->ScreenToClient(&PtoGrav);  // Posición en coordenadas cliente del nudo.
    pDlgNudo->MoverNudo(PtoGrav);   // Mueve el nudo a la posición especificada en la vista.
}

void CDibConectDis::Seleccionar(BOOL Seleccionar /*= true*/, CRect * prsel /*= NULL*/, CDiagDisView* view /* = NULL */)
{
	CDibDiagrama* pdibdiag = p_conect->getDiag()->getVistas()->getDibDiagrama();

	POSITION posnudo = m_listaNudos.GetHeadPosition();
	while( posnudo != NULL)
	{
		CConNudo* pNudo = (CConNudo*)m_listaNudos.GetNext( posnudo );
		if (NULL != prsel)  // Si hay rectángulo de selección comprobamos que cae dentro.
		{
			CClientDC dc(view);
			view->OnPrepareDC(&dc);
			CPoint pt = pNudo->m_posNudo;

			pt = pdibdiag->Escala(pt,view); // Lógicas.
			dc.LPtoDP(&pt); // Cliente
			if (prsel->PtInRect(pt))  // Cae dentro cambiamos estado
			{
				pNudo->m_seleccionado = Seleccionar;
			}
		}
		else  // No hay rectángulo de selección, cambiamos estado de todos los nudos (de todo el conector).
		{
			pNudo->m_seleccionado = Seleccionar;
		}
	}
}


BOOL CDibConectDis::EsSeleccionado()
{
	BOOL seleccionado = true; // Inicialmente, si no está seleccionado un nudo se pone a false

	POSITION posnudo = m_listaNudos.GetHeadPosition();
	while( posnudo != NULL)
	{
		CConNudo* pNudo = (CConNudo*)m_listaNudos.GetNext( posnudo );
		if (!pNudo->m_seleccionado) 
		{	
			seleccionado = false; // Algún nudo no seleccionado, el conector NO está seleccionado
			break; // Ya sabemos que no está totalmente seleccionado
		}
	}

	return seleccionado;
}


BOOL CDibConectDis::EsSeleccionadoParcial()
{
	BOOL seleccionado = false; // Inicialmente, si hay algún nudo seleccionado se ponen a true 

	POSITION posnudo = m_listaNudos.GetHeadPosition();
	while( posnudo != NULL)
	{
		CConNudo* pNudo = (CConNudo*)m_listaNudos.GetNext( posnudo );
		if (pNudo->m_seleccionado) 
		{	
			seleccionado = true; // Algún nudo seleccionado, el conector está parcialmente seleccionado
			break; // Ya sabemos que está algún nudo seleccionado
		}
	}

	return seleccionado;
}


void CDibConectDis::MoverGrupoSelecc(const CPoint& desp)
{
	POSITION posnudo = m_listaNudos.GetHeadPosition();		
	while( posnudo != NULL)
	{
		CConNudo* pNudo = (CConNudo*)m_listaNudos.GetNext( posnudo );
		if (pNudo->m_seleccionado)
		{
			CPoint pt = pNudo->m_posNudo; // Temporal.
			pNudo->m_posNudo = CPoint(pt.x + desp.x, pt.y + desp.y);
			if (NULL == pNudo->p_nudoPrev)  // Comienzo del conector. Movemos alla etiqueta también 
			{
			   pt = m_ptoInsEtiq;
			   m_ptoInsEtiq = CPoint(pt.x + desp.x, pt.y + desp.y);
			}
		}
	}
}

void  CDibConectDis::addView(CBaseView* view)
{
	POSITION pos = m_listaNudos.GetHeadPosition();
	while( pos != NULL )
	{
		CConectorNudoDis* pNudo = (CConectorNudoDis*)m_listaNudos.GetNext(pos);	
		pNudo->addView(view);	
	}
}

void  CDibConectDis::removeView(CBaseView* view)
{
	POSITION pos = m_listaNudos.GetHeadPosition();
	while( pos != NULL )
	{
		CConectorNudoDis* pNudo = (CConectorNudoDis*)m_listaNudos.GetNext(pos);	
		pNudo->removeView(view);	
	}
}



