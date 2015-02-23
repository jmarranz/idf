// dlgbdis.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgBloqueDis.h"

#include "DiagDisView.h"
#include "DibBloqueDis.h"

#include "..\BloqueVistas.h"
#include "..\des\DibDiagramaDis.h"
#include "..\des\DiagramaVistasDis.h"

#include "..\..\model\Bloque.h"
#include "..\..\model\BaseDoc.h"
#include "..\..\model\Conect.h"

#include "..\..\model\des\DiagDis.h"
#include "..\..\model\des\ConectDis.h"

#include "..\..\model\bdiag\BloqueDiag.h"

#include "..\..\Exception.h"



/////////////////////////////////////////////////////////////////////////////
// CDlgBloqueDis dialog


CDlgBloqueDis::CDlgBloqueDis(CWnd* pParent /*=NULL*/)
	: CDlgBloque(CDlgBloqueDis::IDD,pParent)
{
	//{{AFX_DATA_INIT(CDlgBloqueDis)
	//}}AFX_DATA_INIT
	
	m_inicializado = false;
	m_mover = false;

	int m_cx = -1;
	int m_cy = -1;

	m_previaPos = CPoint(-1,-1);
}

void CDlgBloqueDis::DoDataExchange(CDataExchange* pDX)
{
	CDlgBloque::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBloqueDis)
	DDX_Control(pDX, IDC_ETIQ, m_CtrlEtiq);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgBloqueDis, CDlgBloque)
	//{{AFX_MSG_MAP(CDlgBloqueDis)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SIZE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_SELEC_BLOQUE, OnSelecBloque)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_RBUTTONUP()
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_PROP_GEN, OnPropGen)
	ON_COMMAND(ID_PROP_ESPEC, OnPropEspec)
	ON_COMMAND(ID_PROP_INFORM, OnPropInform)
	ON_COMMAND(ID_PROP_LISTACONECT, OnPropListaconect)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_ELIMINAR_BLOQUE, OnEliminarBloque)
	ON_COMMAND(ID_CARGAR_SUBDIAGRAMA, OnCargarSubdiagrama)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgBloqueDis message handlers

BOOL CDlgBloqueDis::Crear(CBaseView* view, CBloqueVistas* pvistas)
{
    m_inicializado = false;	
	CDlgBloque::Crear(view, pvistas,IDD);
    m_inicializado = true;  // Ahora OnSize y OnMove pueden actuar
	return true;
}                             

void CDlgBloqueDis::MoverBloque(const CPoint& nuevapos)
{
	CPoint ptemp = nuevapos;
    ClientToScreen(&ptemp);
    p_view->ScreenToClient(&ptemp);
	ptemp = p_view->Cliente_A_mm(ptemp);   // Nueva posición en mm reales DINA4

	CRect rviejo = p_vistas->getDibBloque()->m_rect;
	CRect nuevo = rviejo;
	CPoint offset = ptemp - rviejo.TopLeft();
	nuevo += offset;

	ActualizarBloque(nuevo);
}

void CDlgBloqueDis::ResizeBloque()
{
    CDiagDisView* viewDis = (CDiagDisView*)p_view;

	if (!m_inicializado || viewDis->m_noActualizaPosBloq)  return; // Sólo funciona en modo de diseño y ya posicionado a partir de los datos de CBloque.

    CRect nuevo;
	GetWindowRect( &nuevo );  // Rectángulo actual del diálogo incluida barra de título en coordenadas de pantalla. No usar GetClientRect que excluye la barra de título.
    
	p_view->ScreenToClient(&nuevo);  // En coordenadas cliente de la vista.
	nuevo = p_view->Cliente_A_mm(nuevo);   // Nueva posición y tamaño en mm reales DINA4

	ActualizarBloque(nuevo);
}

void CDlgBloqueDis::ActualizarBloque(const CRect& nuevo)
{
	CDibBloqueDis* pDibBloque = p_vistas->getDibBloqueDis();

	CRect rviejo = pDibBloque->m_rect;
	if (nuevo == rviejo) return;

	CBloque* pbloque = p_vistas->getBloque();
	CDiagBase* pdiag = pbloque->getDiag();

	if (!pdiag->getVistas()->ValidarRect_A4(nuevo))
		return; // No cabe

	pDibBloque->m_rect = nuevo;

    if (pDibBloque->EsSeleccionado())   // Redibujamos de forma eficiente la vista para que el rectángulo de selección se actualice y se borre el antiguo.
    {
		RedibujarSeleccion(&rviejo);
	}

	p_vistas->Actualizar();  // Actualiza todos los diálogos del mismo objeto bloque de todas las ventanas, el semáforo evitará reentrada.
	
	pdiag->FlagModificado(); 
}


void CDlgBloqueDis::OnSize(UINT nType, int cx, int cy)
{
	CDlgBloque::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if ((m_cx != cx) || (m_cy != cy))
	{
		ResizeBloque();
		m_cx = cx;
		m_cy = cy;
	}
}

void CDlgBloqueDis::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	p_vistas->Propiedades();	

	CDlgBloque::OnLButtonDblClk(nFlags, point);
}

void CDlgBloqueDis::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CDlgBloque::OnLButtonUp(nFlags, point);  // No llamamos a la base CDlgBloque porque sólo es para el caso funcional

	ReleaseCapture();

	CDiagDisView* view = (CDiagDisView*)p_view;

	CBloque* pbloque = p_vistas->getBloque();
	CDiagDis* pdiag = pbloque->getDiagDis();

	if ((ASOCIABLQINI == pdiag->m_estadoEdic)||(ASOCIABLQFIN == pdiag->m_estadoEdic))
	{
		try
		{
			pdiag->p_conect->getDis()->AsociarBloque(view,pbloque,this, point);
			pdiag->getVistas()->Mensaje("Asociación conector-bloque correcta"); 
		}
		catch(Exception* ex)
		{
			pdiag->getVistas()->Mensaje(ex);
			delete ex;
			return;
		}
	}
	else if (nFlags & MK_CONTROL)
	{
		CDibBloqueDis* pDibBloque = p_vistas->getDibBloqueDis();

		pDibBloque->m_seleccionado = !pDibBloque->m_seleccionado; 
        // Redibujado eficiente de la vista para que se dibuje o borre el rectángulo de selección
		RedibujarSeleccion();
	}
	else if (m_mover)
	{
		m_mover = false;
		SetCursorTipoBloque();
	}
	else
	{
		p_vistas->Propiedades();
	}
}

void CDlgBloqueDis::RedibujarSeleccion(CRect* prviejo /* = NULL */)
{
   // Dibujado eficiente del rectángulo de selección invalidando la zona afectada.
	// Para todas las vistas
	CDibBloqueDis* pdibBloque = p_vistas->getDibBloqueDis();

	CBloque* pbloque = p_vistas->getBloque();
	CDiagDis* pdiag = pbloque->getDiagDis();
	
	CDibDiagrama* pdibDiag = pdiag->getVistas()->getDibDiagrama();

	CObList* views = &pdiag->getVistas()->m_views;
	for(POSITION pos = views->GetHeadPosition(); pos != NULL; )
	{
		CDiagDisView* view = (CDiagDisView*)views->GetNext(pos);
   		CClientDC dc(view);
    	view->OnPrepareDC(&dc);
		CRect r;
		if (prviejo)  r.UnionRect(prviejo, &(pdibBloque->m_rect)); // Para el caso de movimiento de un bloque seleccionado, para que no deje residuos se hace el rectángulo más grande
		else r = pdibBloque->m_rect;
		r = pdibDiag->Escala( r, view );
		dc.LPtoDP( r );
		r.InflateRect(10,10);  // Para que el borde se redibuje bien.
		view->RedrawWindow(&r);
	}
}

void CDlgBloqueDis::OnSelecBloque() 
{
	// TODO: Add your command handler code here
	CDibBloqueDis* pDibBloque = p_vistas->getDibBloqueDis();
	
	BOOL sel = pDibBloque->EsSeleccionado();
	pDibBloque->Seleccionar(!sel);
	RedibujarSeleccion();
}

void CDlgBloqueDis::ActualizaEtiq()
{
	CBloque* pbloque = p_vistas->getBloque();
    SetDlgItemText( IDC_ETIQ, pbloque->getEtiqueta() );  // Actualiza el texto de la etiqueta.
}

void CDlgBloqueDis::MoverEtiqueta(CRect& rect)
{
	m_CtrlEtiq.MoveWindow(rect);
}

HBRUSH CDlgBloqueDis::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDlgBloque::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgBloqueDis::OnPaint() 
{
	CDlgBloque::OnPaint();

}

void CDlgBloqueDis::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDlgBloque::OnRButtonUp(nFlags, point);
}


BOOL CDlgBloqueDis::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	return CDlgBloque::OnSetCursor(pWnd, nHitTest, message);
}

void CDlgBloqueDis::OnPropGen() 
{
	// TODO: Add your command handler code here
	CDlgBloque::OnPropGen();
}

void CDlgBloqueDis::OnPropEspec() 
{
	// TODO: Add your command handler code here
	CDlgBloque::OnPropEspec();	
}

void CDlgBloqueDis::OnPropInform() 
{
	// TODO: Add your command handler code here
	CDlgBloque::OnPropInform();	
}

void CDlgBloqueDis::OnPropListaconect() 
{
	// TODO: Add your command handler code here
	CDlgBloque::OnPropListaconect();	
}

void CDlgBloqueDis::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();
	::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVER));

	CDlgBloque::OnLButtonDown(nFlags, point);
}

void CDlgBloqueDis::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_previaPos != point)
	{
		m_previaPos = point;
		if (MK_LBUTTON & nFlags)
		{
			if (!m_mover) 	
			{
				EsquinaCursor(); 	// Llevamos el cursor a la esquina de la ventana, con una cierta gravedad.
				m_mover = true;
			}

			MoverBloque(point); 
		} 
		//else if (m_Mover) m_Mover = false;
	}

	CDlgBloque::OnMouseMove(nFlags, point);
}

void CDlgBloqueDis::EsquinaCursor()
{
    CRect rtemp;
    GetClientRect(&rtemp);
    
    CPoint ptemp = rtemp.TopLeft();
    ClientToScreen(&ptemp);  // En coordenadas de pantalla.
    SetCursorPos(ptemp.x,ptemp.y);  // Sitúa el cursor en el centro del diálogo.
}

void CDlgBloqueDis::OnEliminarBloque() 
{
	// TODO: Add your command handler code here
	CBloque* pbloque = p_vistas->getBloque();
	CDiagDis* pdiag = pbloque->getDiagDis();

	pdiag->EliminarBloque(pbloque);
}

void CDlgBloqueDis::cargarMenu(CPoint point)
{
	CBloque* pbloque = p_vistas->getBloque();

	CMenu bar;
	if (bar.LoadMenu(IDR_MENU_BLOQUE_DIS_DCHO))
	{
		CMenu& popup = *bar.GetSubMenu(0);
		ASSERT(popup.m_hMenu != NULL);

		if (!pbloque->EsBloqueDiag())
		{
			// Ha de hacerse aquí porque en los menús popup no se ruta el mensaje de actualización del menú.
			popup.RemoveMenu(ID_CARGAR_SUBDIAGRAMA,MF_BYCOMMAND);
		}

		ClientToScreen(&point);
		popup.TrackPopupMenu(TPM_RIGHTBUTTON,point.x, point.y, this );
			// AfxGetMainWnd()); // route commands through main window
	}
}

void CDlgBloqueDis::OnCargarSubdiagrama() 
{
	// TODO: Add your command handler code here
	CBloque* pbloque = p_vistas->getBloque();
	if (pbloque->EsBloqueDiag())
	{
		CBloqueDiag* pblqDiag = (CBloqueDiag*)pbloque;
		CString mensaje = "\n";
		if (pblqDiag->PropiedadesCorrectas(mensaje))
			pblqDiag->CargaSubdiagrama();
		else
			pbloque->getVistas()->Mensaje(mensaje);
	}

}
