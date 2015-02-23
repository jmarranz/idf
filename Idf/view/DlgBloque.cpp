// DlgBloque.cpp: implementation of the CDlgBloque2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "DlgBloque.h"

#include "BloqueVistas.h"
#include "DibBloque.h"
#include "DibDiagrama.h"
#include "DiagramaVistas.h"
#include "BaseView.h"

#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDlgBloque::CDlgBloque(UINT nIDTemplate,CWnd* pParent /*=NULL*/)
	: CDialog(nIDTemplate,pParent)
{
	p_view = NULL;
	p_vistas = NULL;
}

CDlgBloque::~CDlgBloque()
{

}

BOOL CDlgBloque::Crear(CBaseView* view, CBloqueVistas* pvistas,UINT recurso)
{
	p_view = view;
	p_vistas = pvistas;

	if (!CDialog::Create(recurso, view)) return false; // Muy raro

	BringWindowToTop();

	Actualizar();  // Posiciona el diálogo correctamente a partir de los valores de posición de CBloque.

	return true;
}              

void CDlgBloque::Actualizar()
{
	if (p_vistas->getDibBloque()->m_visible)  ShowWindow(SW_SHOW);
	else  ShowWindow(SW_HIDE);
	ActualizaEtiq();		
	Recolocar(); 
	RedrawWindow();
}

void CDlgBloque::Recolocar()  // Sitúa en pantalla el bloque a partir de los valores reales.
{
	CPoint point;
	CRect Trect;
	CDibBloque* pdibBloque = p_vistas->getDibBloque();

    CPoint pins = pdibBloque->m_rect.TopLeft();    

	CDibDiagrama* pdibdiag = p_vistas->getBloque()->getDiag()->getVistas()->getDibDiagrama();
    
	point = pdibdiag->Escala(pins, p_view);
	Trect = pdibdiag->Escala(pdibBloque->m_rect, p_view);

	CClientDC dc(p_view);
	p_view->OnPrepareDC(&dc);

	dc.LPtoDP(&point);
	dc.LPtoDP(&Trect);

	MoveWindow(point.x, point.y, Trect.Width(), Trect.Height());  // Ojo, llama a OnMove y OnSize seguramente, cuidado con las llamadas recursivas.

	// Como puede haber cambiado la escala actualizamos el tamaño y posición de la
	// etiqueta del bloque.

	// Actualiza la posición y tamaño del control de la etiqueta: 
	GetClientRect( &Trect );  // Rectángulo actual del área cliente del diálogo en coordenadas de dispositivo.

	// CRect RTexto( CPoint(Trect.Width()/8, Trect.Height()/8), CSize((Trect.Width()*3)/4, Trect.Height()/2)); 
	// Recordar que hay que dejar sitio de h/8 a la flecha de AE.
	CRect RTexto( Trect.Width()/20, Trect.Height()/8, (Trect.Width()*19)/20, Trect.Height()/2); 

	MoverEtiqueta(RTexto);
}

void CDlgBloque::OnPaint()
{
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages

	CPaintDC dc(this); // device context for painting. Necesario si se ejecuta OnPaint pues si no está se cuelga al no procesar el mensaje o algo así.
    
    CPaintDC* pDC = &dc;

    CRect Trect;
	GetClientRect( &Trect );  // Rectángulo actual del diálogo en coordenadas de dispositivo.
	int w = Trect.Width();
	int h = Trect.Height();

    // Dibujado de las flechas AE y AS:
    
	int ancho = 2;  // Un ancho apropiado a las unidades del diálogo.
					// El ancho para impresión de CBloque es muy gordo para pintar en un diálogo (bueno para CView).

	CBloque* pbloque = p_vistas->getBloque();
	CDibBloque* pdibBloque = p_vistas->getDibBloque();

	if (pbloque->getAE()) 
	{
		CPoint pAE = CPoint( w/2, h/8 );

		m_flechaAE.Iniciar(pAE,h/8,ancho,SUR);
		m_flechaAE.Dibujar(pDC,p_view,pbloque->getDiag(), pdibBloque->m_colRec, false );
	}
	if (pbloque->getAS()) 
	{
		CPoint pAS = CPoint( w/2 , h );

		m_flechaAS.Iniciar(pAS,h/8,ancho,SUR);
		m_flechaAS.Dibujar(pDC,p_view,pbloque->getDiag(), pdibBloque->m_colRec, false );
	}

	// Dibujado del bitmap del tipo de bloque:

    UINT tipodibujo;

	switch (pdibBloque->m_tipoDibujo)
	{
		case 0:
		{ 
		   	tipodibujo = RECTANGULO;  // Es raro que suceda.
		}
		case RECTANGULO:   		// Rectángulo
		{	        
	        tipodibujo = IDB_RECTANG;
	  		break;
		}
		case ROMBO:   // Rombo
		{
            tipodibujo = IDB_ROMBO;
	       	break;
		}            
		case ELIPSE:  // Círculo o elipse           
    	{
    	    tipodibujo = IDB_CIRCULO;
    		break;
    	}
    	default:
    	{
            tipodibujo = IDB_RECTANG;  // Raro que suceda
		}
    }


    CDC DCMem; 
	DCMem.CreateCompatibleDC( &dc );
	CBitmap TipoBMP;
 
    TipoBMP.LoadBitmap(tipodibujo);
    CBitmap* pViejoBMP = DCMem.SelectObject( &TipoBMP );
	
	// No debe ocultar la fecha de AS 
	// dc.StretchBlt( 0, (h*5)/8 , (w*3)/8, (h*3)/8 , &DCMem, 0, 0, 60, 40, SRCAND );
	dc.StretchBlt( 0, h/2 , (w*3)/8, h/2 , &DCMem, 0, 0, 60, 40, SRCAND );
	
    DCMem.SelectObject( pViejoBMP );  // No es OLE nunca, seleccionar el viejo sin miedo.
}


HBRUSH CDlgBloque::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	// TODO: Add your message handler code here and/or call default
	
	if ((nCtlColor == CTLCOLOR_DLG)||(nCtlColor == CTLCOLOR_STATIC))
	{
		CDibBloque* pdibBloque = p_vistas->getDibBloque();
		CBloque* pbloque = p_vistas->getBloque();

		if (pbloque->EsNuevo())
		{
			pDC->SetBkColor(AZUL);  // Para el fondo de la etiqueta.
			return (HBRUSH)pdibBloque->m_dlgBrushNuevo.GetSafeHandle();
        }
        
        switch (pbloque->getEstadoUsr())
        {
        	case INCOMPLETO: 
        	{
        		pDC->SetBkColor(AMARILLO);  // Para el fondo de la etiqueta.
        		return (HBRUSH)pdibBloque->m_dlgBrushIncompleto.GetSafeHandle();
        	}
       		case ERRONEO: 
        	{
        		pDC->SetBkColor(MORADO);  // Para el fondo de la etiqueta.
        		return (HBRUSH)pdibBloque->m_dlgBrushErroneo.GetSafeHandle();
        	}        	
       		case CORRECTO: 
        	{
        		pDC->SetBkColor(VERDE);  // Para el fondo de la etiqueta.
        		return (HBRUSH)pdibBloque->m_dlgBrushCorrecto.GetSafeHandle();
        	}        	
        }
        pDC->SetBkColor(AMARILLO);  // Para el fondo de la etiqueta.
		return (HBRUSH)pdibBloque->m_dlgBrushIncompleto.GetSafeHandle();
	}
	
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);   // Color por defecto en cualquier caso
}


void CDlgBloque::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnRButtonUp(nFlags, point);

	if (nFlags & MK_CONTROL) p_vistas->PropUsuario(); // Si es modo diseño da un mensaje de operación incorrecta
	else
	{
		cargarMenu(point);
	}
}

BOOL CDlgBloque::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	if ((pWnd == this) && (nHitTest == HTCLIENT))
	{
		SetCursorTipoBloque();
		return true;
	}

	// BORRAR
	if ((pWnd == this) && (nHitTest == HTCAPTION))  // Sólo hay barra de la ventana en tiempo de diseño.
	{
		::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVER));
		return true;
	}
	
	return CDialog::OnSetCursor(pWnd, nHitTest, message); // Para cuando está en el borde etc.
}

void CDlgBloque::SetCursorTipoBloque()
{
	UINT cursor;

	CBloque* pbloque = p_vistas->getBloque();
	if (pbloque->EsRetroanotador()) cursor = IDC_BLQRETRO;
	else cursor = IDC_BLQFUNC;
	
	::SetCursor(AfxGetApp()->LoadCursor(cursor));
}


void CDlgBloque::OnPropGen()
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(0);		
}


void CDlgBloque::OnPropEspec() 
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(1);	
}

void CDlgBloque::OnPropListaconect() 
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(2);	
}

void CDlgBloque::OnPropInform() 
{
	// TODO: Add your command handler code here
	p_vistas->Propiedades(3);	
}


