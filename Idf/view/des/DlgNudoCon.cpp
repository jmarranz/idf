// nudocon.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgNudoCon.h"


#include "ConectorNudoDis.h"
#include "DiagramaVistasDis.h"
#include "DiagDisView.h"
#include "DibConectDis.h"

#include "..\des\ConectVistasDis.h"
#include "..\DibDiagrama.h"


#include "..\..\model\Conect.h" 
#include "..\..\model\BaseDoc.h"
#include "..\..\model\des\DiagDis.h"
#include "..\..\model\des\ConectDis.h"

#include "..\..\Exception.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgNudoCon dialog


CDlgNudoCon::CDlgNudoCon(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNudoCon::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNudoCon)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_mover = false;

	p_view = NULL;
	p_nudo = NULL;
	p_dibConect = NULL;
}

void CDlgNudoCon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNudoCon)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgNudoCon, CDialog)
	//{{AFX_MSG_MAP(CDlgNudoCon)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ELIMINAR_CONEC, OnEliminarConec)
	ON_COMMAND(ID_ELIMINARNUDO, OnEliminarnudo)
	ON_COMMAND(ID_PROPIEDADES, OnPropiedades)
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_ANYADIRNUDOANT, OnAnyadirnudoant)
	ON_COMMAND(ID_ANYADIRNUDOPOST, OnAnyadirnudopost)
	ON_COMMAND(ID_CAMBIAPOSETIQ, OnCambiaposetiq)
	ON_COMMAND(ID_ASOCIAR_BLQFIN, OnAsociarBlqfin)
	ON_COMMAND(ID_ASOCIAR_BLQINI, OnAsociarBlqini)
	ON_COMMAND(ID_IRALNUDOPREV, OnIralnudoprev)
	ON_COMMAND(ID_IRALNUDOSIG, OnIralnudosig)
	ON_COMMAND(ID_LIBERAR_RATON, OnLiberarRaton)
	ON_COMMAND(ID_GRAVASOCIAR_BLQFIN, OnGravasociarBlqfin)
	ON_COMMAND(ID_GRAVASOCIAR_BLQINI, OnGravasociarBlqini)
	ON_COMMAND(ID_SELEC_CONECTOR, OnSelecConector)
	ON_COMMAND(ID_SELEC_NUDO, OnSelecNudo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgNudoCon message handlers


BOOL CDlgNudoCon::Crear(CDiagDisView* view, CConNudo* connudo)
{
	p_view = view;
	p_nudo = connudo;
	p_dibConect = p_nudo->getConect()->getVistas()->getDibConect()->getDis();

	m_tipoNudo = p_nudo->getTipoNudo();
	
	Create(IDD, view);

	//BringWindowToTop();

    // No funciona yo creo debido a que la ventana no tiene título.
//	LONG estilo = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
//	estilo = estilo | WS_EX_TOPMOST;
//	SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE, estilo);

    Actualizar();
	return true;
}

void CDlgNudoCon::Actualizar()
{
	CPoint pins = p_nudo->m_posNudo;

	CConect* pconect = p_nudo->getConect();
	CDibDiagrama* pdibdiag = pconect->getDiag()->getVistas()->getDibDiagrama();

    pins = pdibdiag->Escala(pins,p_view);

	CClientDC dc(p_view);
	p_view->OnPrepareDC(&dc);

	dc.LPtoDP(&pins);  // En coordenadas cliente de la vista.
	
	// El tamaño del rectángulo (toda la ventana incluido el borde) del nudo es fijo: 10x10 puntos de pantalla.
    // El punto del nudo cae en el centro de la ventana.
	MoveWindow(pins.x - ANCHONUDO / 2, pins.y - ALTONUDO / 2, ANCHONUDO, ALTONUDO);  // Ojo, llama a OnMove y OnSize seguramente, cuidado con las llamadas recursivas.
	BringWindowToTop();
	RedrawWindow();
}


void CDlgNudoCon::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CMenu bar;
	if (bar.LoadMenu(IDR_MENU_CONEC_DCHO)) 
	{
		CMenu& popup = *bar.GetSubMenu(0);
		ASSERT(popup.m_hMenu != NULL);

		switch(m_tipoNudo)
		{
			case NUDO_INICIO:
		    {
				// Ha de hacerse aquí porque en los menús popup no se ruta el mensaje de actualización del menú.
				popup.EnableMenuItem( ID_IRALNUDOPREV, MF_GRAYED );		    
				popup.EnableMenuItem( ID_GRAVASOCIAR_BLQFIN, MF_GRAYED );		    
				popup.EnableMenuItem( ID_ANYADIRNUDOANT, MF_GRAYED );		    
		        break;
		    }
		    case NUDO_FINAL:
		    {
				popup.EnableMenuItem( ID_IRALNUDOSIG, MF_GRAYED );		    
				popup.EnableMenuItem( ID_GRAVASOCIAR_BLQINI, MF_GRAYED );		    
				popup.EnableMenuItem( ID_ANYADIRNUDOPOST, MF_GRAYED );					    
		        break;
		    }
			default:    // No es ni inicio ni final
			{
				popup.EnableMenuItem( ID_GRAVASOCIAR_BLQINI, MF_GRAYED );				
				popup.EnableMenuItem( ID_GRAVASOCIAR_BLQFIN, MF_GRAYED );				
			}
		}		
		if ((NUDO_INICIO == m_tipoNudo)||(NUDO_FINAL == m_tipoNudo))
		{
			popup.EnableMenuItem( ID_ELIMINARNUDO, MF_GRAYED );		    
		}

		ClientToScreen(&point);
		popup.TrackPopupMenu(TPM_RIGHTBUTTON, point.x, point.y, this );
			// AfxGetMainWnd()); // route commands through main window
	}
	
	CDialog::OnRButtonUp(nFlags, point);
}

void CDlgNudoCon::OnEliminarConec()
{
	// TODO: Add your command handler code here
	CConect* pconect = p_nudo->getConect();
	CDiagDis* pDiag = pconect->getDiagDis();
	pDiag->EliminarConector(pconect);
	pDiag->getVistas()->Actualizar();
}

void CDlgNudoCon::OnEliminarnudo()
{
	// TODO: Add your command handler code here
	try
	{
		p_dibConect->EliminarNudo(p_nudo);	
	}
	catch(Exception* ex)
	{
		CConect* pconect = p_nudo->getConect();
		CDiagDis* pDiag = pconect->getDiagDis();
		pDiag->getVistas()->Mensaje(ex);
		delete ex;
	}
}

void CDlgNudoCon::OnPropiedades()
{
	// TODO: Add your command handler code here
	CConect* pconect = p_nudo->getConect();
	pconect->getVistas()->Propiedades();	
}

BOOL CDlgNudoCon::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	if ((pWnd == this) && (nHitTest == HTCLIENT))
	{
		if (m_mover) ::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVER));
		else   ::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return true;
	}
	// Está el cursor en el borde, llevamos el cursor al centro (cierta gravedad):
	if (!m_mover) CentrarCursor();

	return CDialog::OnSetCursor(pWnd, nHitTest, message);  // Flecha normal, caso de estar en el borde.
}

void CDlgNudoCon::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_previaPos != point)
	{
		m_previaPos = point;
		if (MK_LBUTTON & nFlags)
		{
			m_mover = true;
			MoverNudo(point); 
		} 
		else CentrarCursor(); 	// Llevamos el cursor al medio de la ventana, con una cierta gravedad.
	}

	CDialog::OnMouseMove(nFlags, point); 
}

void CDlgNudoCon::MoverNudo(CPoint point)
{
	// point en coordenadas cliente del diálogo del nudo.
	CPoint ptemp = point;
    ClientToScreen(&ptemp);
    p_view->ScreenToClient(&ptemp);
    if (p_view->PtEnDINA4(ptemp))
    {
		int nROP;
		CClientDC dc(p_view);
		p_view->OnPrepareDC(&dc);
		nROP = dc.GetROP2();   // Para restaurar luego

		CConNudo* pNudoPrev = p_nudo->p_nudoPrev;            

        dc.SetROP2(R2_NOTXORPEN);
		p_nudo->DibujarTramo(&dc,p_view,pNudoPrev);
		if (pNudoPrev) pNudoPrev->DibujarTramo(&dc,p_view,p_nudo);  // Borra el conector en su posición antigua dibujando de nuevo (el resultado es siempre el color 1111... = blanco).
        dc.SetROP2(nROP);  // Restauramos el antiguo (no se si hace falta).
            
        InvalidaEntorno(&dc);  // Invalida la zona afectada del conector en su posición antigua

        p_nudo->m_posNudo = ptemp;  // Actualizamos la nueva posición      

        if (NUDO_FINAL == m_tipoNudo) p_dibConect->ActualizaPosFlechaFinal();
           
        dc.SetROP2(R2_NOTXORPEN);
		p_nudo->DibujarTramo(&dc,p_view,pNudoPrev);
		if (pNudoPrev) pNudoPrev->DibujarTramo(&dc,p_view,p_nudo);  // Dibuja en la nueva posición (se supone que hay blanco abajo)           
        dc.SetROP2(nROP);  // Restauramos el antiguo (no se si hace falta).

        InvalidaEntorno(&dc);  // Invalida la zona afectada del conector en su posición nueva.

        p_view->UpdateWindow();  //Envía un WM_PAINT que redibuja las zonas invalidadas

        Actualizar(); // Situar el diálogo en la posición del cursor.
	}
}



void CDlgNudoCon::InvalidaEntorno(CDC* pDC)
{
	CConect* pconect = p_nudo->getConect();
	CDibDiagrama* pdibdiag = pconect->getDiag()->getVistas()->getDibDiagrama();

    if (p_nudo->p_nudoPrev)
    {
		CPoint pprev;
     	CPoint psig;    
    	pprev = pdibdiag->Escala(p_nudo->p_nudoPrev->m_posNudo,p_view);
    	psig = pdibdiag->Escala(p_nudo->m_posNudo,p_view);
     	pDC->LPtoDP(&pprev); // En coordenadas cliente;
     	pDC->LPtoDP(&psig); // En coordenadas cliente;
    	
    	CRect zona(pprev.x,pprev.y,psig.x,psig.y);
        zona.NormalizeRect( );
        CPoint altflecha(p_dibConect->getpFlecha()->m_altFlecha,0);
        CPoint pexceso = pdibdiag->Escala(altflecha,p_view); // Que el exceso sea al menos la altura de la flecha.
     	pDC->LPtoDP(&pexceso); // En coordenadas cliente;        
        int ex = pexceso.x + 10;
        zona.InflateRect(ex, ex); // Para borrar los restos que pudiera dejar la flecha fuera del rectángulo etc.       
		p_view->InvalidateRect(zona);  // Marca la zona para redibujar posteriormente
    }

    if (p_nudo->p_nudoSig)
    {
    	CPoint pprev;
     	CPoint psig;        

    	pprev = pdibdiag->Escala(p_nudo->m_posNudo,p_view);
    	psig = pdibdiag->Escala(p_nudo->p_nudoSig->m_posNudo,p_view);     	
     	pDC->LPtoDP(&pprev); // En coordenadas cliente;     	
    	pDC->LPtoDP(&psig); // En coordenadas cliente;    
    	
    	CRect zona(pprev.x,pprev.y,psig.x,psig.y);
        zona.NormalizeRect( );
        CPoint altflecha(p_dibConect->getpFlecha()->m_altFlecha,0);
        CPoint pexceso = pdibdiag->Escala(altflecha,p_view); // Que el exceso sea al menos la altura de la flecha.
     	pDC->LPtoDP(&pexceso); // En coordenadas cliente;        
        int ex = pexceso.x + 10;;
        zona.InflateRect(ex, ex); // Para borrar los restos que pudiera dejar la flecha fuera del rectángulo etc.       
 		p_view->InvalidateRect(zona);  // Marca la zona para redibujar posteriormente
    }
}

void CDlgNudoCon::CentrarCursor()
{
    CRect rtemp;
    GetClientRect(&rtemp);
    
    // No hacemos CPoint ptemp(ANCHONUDO / 2, ALTONUDO / 2);  porque al parecer el borde también se incluye en el MoveWindow luego no es el área cliente exactamente que es menor.
    CPoint ptemp( rtemp.Width() / 2, rtemp.Height() / 2 );
    ClientToScreen(&ptemp);  // En coordenadas de pantalla.
    SetCursorPos(ptemp.x,ptemp.y);  // Sitúa el cursor en el centro del diálogo.
}


void CDlgNudoCon::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// MOVER = true;  // Inicio del movimiento
	SetCapture();
	::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVER));	
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgNudoCon::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_mover)  // Se ha movido y por tanto modificado
	{	
		// MoverNudo(point); 	// Para ajuste fino
		m_mover = false; // Fin del movimiento
		CConect* pconect = p_nudo->getConect();
		pconect->getDiag()->FlagModificado(); //Actualizar todas las vistas  y marcar como modificado
		pconect->getDiag()->getVistas()->Actualizar();
	}

	ReleaseCapture();
	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));  // Restaurar el cursor.

	if (nFlags & MK_CONTROL)   // Para selección del nudo.
	{
		p_nudo->m_seleccionado = !p_nudo->m_seleccionado; 
        
		RedibujarSeleccion();
	}

	CDialog::OnLButtonUp(nFlags, point);
}
                       
                       
void CDlgNudoCon::OnAnyadirnudoant()
{
	// TODO: Add your command handler code here
	p_dibConect->AnyadeNudoMedioAnterior(p_nudo);

	CDiagBase* pdiag = p_nudo->getConect()->getDiag();
	pdiag->FlagModificado();
	pdiag->getVistas()->Actualizar();
}

void CDlgNudoCon::OnAnyadirnudopost()
{
	// TODO: Add your command handler code here
	p_dibConect->AnyadeNudoMedioPosterior(p_nudo);

	CDiagBase* pdiag = p_nudo->getConect()->getDiag();
	pdiag->FlagModificado();
	pdiag->getVistas()->Actualizar();
}


void CDlgNudoCon::OnCambiaposetiq()
{
	// TODO: Add your command handler code here
	CConect* pconect = p_nudo->getConect();
	p_view->CambiaPosEtiqConect(pconect);	
}

void CDlgNudoCon::OnAsociarBlqfin()
{
	// TODO: Add your command handler code here
	CConect* pconect = p_nudo->getConect();
	CDiagDis* pDiag = pconect->getDiagDis();
	try
	{
		pDiag->comienzoAsociarBloqueFin(pconect); 	
	}
	catch(Exception* ex)
	{
		pDiag->getVistas()->Mensaje(ex);
		delete ex;
	}
}

void CDlgNudoCon::OnAsociarBlqini()
{
	// TODO: Add your command handler code here
	CConect* pconect = p_nudo->getConect();
	CDiagDis* pDiag = pconect->getDiagDis();
	
	try
	{
		pDiag->comienzoAsociarBloqueIni(pconect); 
	}
	catch(Exception* ex)
	{
		pDiag->getVistas()->Mensaje(ex);
		delete ex;
	}	
}

void CDlgNudoCon::OnIralnudoprev()
{
	// TODO: Add your command handler code here

	CConectorNudoDis* pnudoDis = (CConectorNudoDis*)p_nudo->p_nudoPrev;
	CDlgNudoCon* pDlg =	pnudoDis->BuscaDialogoNudo(p_view);
	if (pDlg)
	{
		pDlg->CentrarCursor(); // Sitúa el cursor en el centro del diálogo del nudo.
	    pDlg->SetCapture();  // Captura el ratón.
	} 
}

void CDlgNudoCon::OnIralnudosig()
{
	// TODO: Add your command handler code here
	CConectorNudoDis* pnudoDis = (CConectorNudoDis*)p_nudo->p_nudoSig;
	CDlgNudoCon* pDlg =	pnudoDis->BuscaDialogoNudo(p_view);
	if (pDlg)
	{
		pDlg->CentrarCursor(); // Sitúa el cursor en el centro del diálogo del nudo.
	    pDlg->SetCapture();  // Captura el ratón.
	} 
}

void CDlgNudoCon::OnLiberarRaton()
{
	// TODO: Add your command handler code here
	ReleaseCapture();	
}

void CDlgNudoCon::OnGravasociarBlqfin()
{
	// TODO: Add your command handler code here
	CConect* pconect = p_nudo->getConect();
	pconect->getDis()->m_gravedad = true;
	OnAsociarBlqfin();
}

void CDlgNudoCon::OnGravasociarBlqini()
{
	// TODO: Add your command handler code here
	CConect* pconect = p_nudo->getConect();
	pconect->getDis()->m_gravedad = true;	
	OnAsociarBlqini(); 
}


void CDlgNudoCon::RedibujarSeleccion()
{
   // Dibujado eficiente del rectángulo de selección invalidando la zona afectada.
	// Para todas las vistas
	CConect* pconect = p_nudo->getConect();

	CDiagBase* pdiag = pconect->getDiag(); 
	CDibDiagrama* pdibdiag = pdiag->getVistas()->getDibDiagrama();

	CObList* views = &pdiag->getVistas()->m_views;

	for ( POSITION pos = views->GetHeadPosition() ; pos != NULL ; )
	{
		CDiagDisView* view = (CDiagDisView*)views->GetNext( pos );		
		CClientDC dc(view);
		view->OnPrepareDC(&dc);
		CPoint pins = p_nudo->m_posNudo;
	
		pins = pdibdiag->Escala( pins, view );
		dc.LPtoDP( &pins );
		CRect r( CPoint(pins.x - ANCHONUDO / 2, pins.y - ALTONUDO / 2), CSize(ANCHONUDO, ALTONUDO) ); // En coordenadas cliente.
		r.InflateRect(10,10);  // Para que el borde se redibuje bien.
		view->RedrawWindow(&r);
	}
}

void CDlgNudoCon::OnSelecConector() 
{
	// TODO: Add your command handler code here
	BOOL sel = p_dibConect->EsSeleccionado();
	p_dibConect->Seleccionar(!sel);

	CConect* pconect = p_nudo->getConect();

	pconect->getDiag()->getVistas()->Actualizar();
}

void CDlgNudoCon::OnSelecNudo() 
{
	// TODO: Add your command handler code here

	p_nudo->m_seleccionado = !p_nudo->m_seleccionado;
	RedibujarSeleccion();
}
