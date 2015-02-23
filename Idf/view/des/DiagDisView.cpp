// diagview.cpp : implementation of the CDiagDisView class
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagDisView.h"

#include "DibDiagramaDis.h"
#include "Clipboard.h"
#include "DiagramaVistasDis.h"

#include "..\des\DibConectDis.h"
#include "..\des\ConectVistasDis.h"


#include "..\..\model\des\DiagDisDoc.h"
#include "..\..\model\des\DiagDis.h"
#include "..\..\model\Conect.h"
#include "..\..\model\BloqueException.h"
#include "..\..\model\DiagramaException.h"


/////////////////////////////////////////////////////////////////////////////
// CDiagDisView

IMPLEMENT_DYNCREATE(CDiagDisView, CBaseView)

BEGIN_MESSAGE_MAP(CDiagDisView, CBaseView)
	//{{AFX_MSG_MAP(CDiagDisView)
	ON_COMMAND(ID_CPOSETIQDIAG, OnCPosEtiqDiag)
	ON_UPDATE_COMMAND_UI(ID_CPOSETIQDIAG, OnUpdateEdicion)
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_INS_BLQFUNC_DLL, OnInsBlqfuncDll)
	ON_COMMAND(ID_INS_BLQFUNC_DIAG, OnInsBlqfuncDiag)
	ON_COMMAND(ID_INS_CONECT, OnInsConect)
	ON_COMMAND(ID_INS_CONECT_RETRO, OnInsConectRetro)
	ON_WM_RBUTTONUP()
	ON_WM_DESTROY()
	ON_COMMAND(ID_CANCELAR_EDIC, OnCancelarEdic)
	ON_UPDATE_COMMAND_UI(ID_CANCELAR_EDIC, OnUpdateCancelarEdic)
	ON_COMMAND(ID_INS_BLQ_RETRO, OnInsBlqRetro)
	ON_COMMAND(ID_MOVERGRUPO, OnMovergrupo)
	ON_COMMAND(ID_SELECC_TODO, OnSeleccTodo)
	ON_COMMAND(ID_ANULARSELECC, OnAnularselecc)
	ON_COMMAND(ID_SELECC_RECT, OnSeleccRect)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_DESELECC_RECT, OnDeseleccRect)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_SELECC_ELIMINAR, OnSeleccEliminar)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_SELECC_ELIMINAR, OnUpdateSeleccEliminar)
	ON_UPDATE_COMMAND_UI(ID_ANULARSELECC, OnUpdateAnularselecc)
	ON_UPDATE_COMMAND_UI(ID_DESELECC_RECT, OnUpdateDeseleccRect)
	ON_COMMAND(ID_PROP_REJILLA, OnPropRejilla)
	ON_COMMAND(ID_VER_TABLADIAG, OnVerTabladiag)
	ON_UPDATE_COMMAND_UI(ID_VER_TABLADIAG, OnUpdateVerTabladiag)
	ON_COMMAND(ID_EJECUTAR_DIAG, OnEjecutarDiag)
	ON_UPDATE_COMMAND_UI(ID_INS_BLQFUNC_DIAG, OnUpdateEdicion)
	ON_UPDATE_COMMAND_UI(ID_INS_BLQFUNC_DLL, OnUpdateEdicion)
	ON_UPDATE_COMMAND_UI(ID_INS_CONECT, OnUpdateEdicion)
	ON_UPDATE_COMMAND_UI(ID_INS_CONECT_RETRO, OnUpdateEdicion)
	ON_UPDATE_COMMAND_UI(ID_INS_BLQ_RETRO, OnUpdateEdicion)
	ON_UPDATE_COMMAND_UI(ID_MOVERGRUPO, OnUpdateEdicion)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CBaseView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CBaseView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagDisView construction/destruction

CDiagDisView::CDiagDisView()
{
	// TODO: add construction code here
	m_capturado = false;
	m_noActualizaPosBloq = false;
}

CDiagDisView::~CDiagDisView()
{
}

CDiagDisDoc* CDiagDisView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDiagDisDoc)));
	return (CDiagDisDoc*)m_pDocument;
}

CDiagDis* CDiagDisView::getDiag()
{
	return (CDiagDis*)CBaseView::getDiag();
}

CDiagramaVistasDis* CDiagDisView::getVistas()
{
	return (CDiagramaVistasDis*)CBaseView::getVistas();
}

CDibDiagramaDis* CDiagDisView::getDibDiagrama()
{
	return (CDibDiagramaDis*)CBaseView::getDibDiagrama();
}

void CDiagDisView::OnInitialUpdate()
{
	CBaseView::OnInitialUpdate();  

}

/////////////////////////////////////////////////////////////////////////////
// CDiagDisView drawing

void CDiagDisView::OnDraw(CDC* pDC)
{
	CBaseView::OnDraw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CDiagDisView diagnostics

#ifdef _DEBUG
void CDiagDisView::AssertValid() const
{
	CBaseView::AssertValid();
}

void CDiagDisView::Dump(CDumpContext& dc) const
{
	CBaseView::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiagDisView message handlers

void CDiagDisView::OnCPosEtiqDiag()
{
	// TODO: Add your command handler code here
    // Necesariamente debe ser NULO el estado al entrar aquí, pero lo comprobamos por si acaso.
	if (getDiag()->m_estadoEdic == NULO)
	{
		getDiag()->m_estadoEdic = CAMBIAETIQDIAG;
		SetCapture();
		m_capturado = true;
		// OnMouseMove se encargará de poner el cursor adecuado.
	}
}

void CDiagDisView::CambiaPosEtiqConect(CConect* con)
{
    // Necesariamente debe ser NULO el estado al entrar aquí, pero lo comprobamos por si acaso.
	CDiagDis* pDiag = getDiag();
	if (pDiag->m_estadoEdic == NULO)
	{
		pDiag->m_estadoEdic = CAMBIAETIQCONECT;
		pDiag->p_conect = con;
		SetCapture();
		m_capturado = true;
		// OnMouseMove se encargará de poner el cursor adecuado.
	}
}


void CDiagDisView::OnUpdateEdicion(CCmdUI* pCmdUI)
{
	// Actualización de estado de los menús de cambio inserción etc.
	// Permite actuar únicamente cuando 
	
	// TODO: Add your command update UI handler code here
	if (getDiag()->m_estadoEdic == NULO)	pCmdUI->Enable( true );
	else  pCmdUI->Enable( false );
}

BOOL CDiagDisView::PtEnDINA4(CPoint& pcc)
{
	// Determina si pcc inicialmente en coordenadas cliente de la vista, está dentro del área visual de la vista.
	// Si lo está determina si además está dentro del DIN A4 (zona no rallada) y si está transforma
	// el punto a dimensiones absolutas reales en mm con dimensiones positivas e independientemente de la escala actual visual. 
	
	CPoint ptemp = pcc;
	CRect r;
	GetClientRect( &r );
	BOOL res = r.PtInRect( ptemp );
	if (res)  // Es válido, el punto está dentro de la vista.
	{
		ptemp = Cliente_A_mm(ptemp);

		if (getDiag()->getVistas()->ValidarXY_A4(ptemp))
		{
		    pcc = ptemp;
			return true;  // Está dentro del área DINA4 (zona no rallada).			
		}
	}			
	return false;  // Sin cambiar pmm (seguirá en coordenadas cliente de la vista).
}


void CDiagDisView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (getDiag()->m_estadoEdic != NULO) CScrollView::OnRButtonUp(nFlags, point);  // Proceso normal	(sin escala). Es necesario llamarse siempre a la base.
	else
	{
		m_noActualizaPosBloq = true;  // Para evitar que en el proceso de escala el impreciso cambio de posición de la ventana por OnMove modifique los valores reales.
		CBaseView::OnRButtonUp(nFlags, point);  // Proceso de la escala y normal
		m_noActualizaPosBloq = false;  
	}
}


void CDiagDisView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// point es en coordenadas cliente respecto a la ventana.
	
    if (NULO == getDiag()->m_estadoEdic)
    {
		m_noActualizaPosBloq = true;  // Para evitar que en el proceso de escala el impreciso cambio de posición de la ventana por OnMove modifique los valores reales.
		CBaseView::OnLButtonUp(nFlags, point);  // Proceso de la escala y normal    
		m_noActualizaPosBloq = false;		
		return;    
    }
     
	CScrollView::OnLButtonUp(nFlags, point);  // Proceso normal	(sin escala). Es necesario llamarse siempre a la base.

    // El ratón estará capturado si se llega aquí:
    
	CDiagDis* pDiag = getDiag();
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	BOOL Release = false;  // Liberar el ratón y finalizar el proceso de edición.
	
	CPoint pmm = point;
	if (PtEnDINA4(pmm))
	{	
		switch (getDiag()->m_estadoEdic)
		{
			case CAMBIAETIQDIAG:
			{
				pDibDiag->m_pInsEtiq = pmm;
				Release = true;	
				break;
			}
			case INSCONECT:
			{
				pDiag->NuevoConectFunc(pmm);
				Release = true;					
				break;
			}
			case INSCONECTRETRO:
			{
				pDiag->NuevoConectRetro(pmm);
				Release = true;					
				break;
			}
			case CAMBIAETIQCONECT:
			{
                pDiag->p_conect->getVistas()->getDibConect()->m_ptoInsEtiq = pmm;
				pDiag->p_conect = NULL;
				Release = true;
				break;
			}		
			case MOVERGRUPO:
			{
                if (PTOINICIAL == getDiag()->m_subEstadoEdic )
                {
                	getDiag()->m_subEstadoEdic = PTOFINAL;
                    pDibDiag->m_ptoIni = pmm;
					Release = false;	// Para reiterar que NO se acaba aquí la edición.                
                }
                else // PTOFINAL
                {
                    pDibDiag->m_ptoFin = pmm;                
                    pDibDiag->MoverGrupoSelecc();
					Release = true;		                
                }
				break;
			}			
		}
	}
	
	if (Release)  // Es necesario ponerse al final pues hace getDiag()->m_estadoEdic = NULO
	{
		getDiag()->m_estadoEdic = NULO;  // Fin del proceso
		ReleaseCapture();	// Libera el ratón.
		m_capturado = false;
		getDiag()->FlagModificado();	// Ha habido un cambio	
		getDiag()->getVistas()->Actualizar();
	}
}

BOOL CDiagDisView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	// OJO, no es llamada si el ratón está capturado
	// por lo que establecemos los cursores también aquí.

	if ((pWnd == this) && (nHitTest == HTCLIENT))
	{
		switch (getDiag()->m_estadoEdic)   // Los casos de edición con captura de ratón probablemente no se llamarán nunca, pero los ponemos por si acaso se pierde la captura.
		{
			case CAMBIAETIQDIAG: 
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_EDICTXT));	
				return true;
			}
			case INSCONECT:
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_INSCONEC));	
				return true;
			}
			case INSCONECTRETRO:
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_INSCONECRETRO));	
				return true;
			}
			case CAMBIAETIQCONECT:
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_EDICTXT));	
				return true;
			}		
			case ASOCIABLQINI:
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_ASOCINI));	
				return true;
			}		
			case ASOCIABLQFIN:
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_ASOCFIN));	
				return true;
			}		
			case MOVERGRUPO:
			{
                if (PTOINICIAL == getDiag()->m_subEstadoEdic )
                {
 					::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVGRUPO_PORIG));	
                }
                else // PTOFINAL
                {
					::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVGRUPO_PDEST));	
                }
				return true;
			}			
			case SELECCGRUPO:
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_RECTSELEC));		
			    return true;
			}
			case DESELECCGRUPO:
			{
				::SetCursor(AfxGetApp()->LoadCursor(IDC_RECTDESELEC));		
			    return true;
			}
		}
    }
    if ((getDiag()->m_estadoEdic != NULO)&&(pWnd != this)) // Fuera de la ventana en edición.
    {
		::SetCursor(AfxGetApp()->LoadCursor(IDC_PROHIBIDO)); 
		return true;			    
    } 

	return CBaseView::OnSetCursor(pWnd, nHitTest, message);  // Cursor asociado a las escalas
}


void CDiagDisView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// En ocasiones pierde el foco no se sabe bien porqué
	// Para que funcione el ajuste forzado del cursor (tecla CTRL) etc.
	// debemos tener el foco del teclado
	if (GetFocus() != this) SetFocus();

    if (m_capturado &&(this != GetCapture())) SetCapture();  // Si la operación se llama a través de la tabla de botones la captura inicial no funciona, por eso la recapturamos. 

	if (this == GetCapture())  // Está capturado el ratón y estamos en edición
	{                          // Cuando el ratón está capturado no se llama a OnSetCursor por lo que el cambio de cursor según el área hemos de hacerlo nosotros
                               // Ponemos los cursores apropiados a cada operación. Sólo operaciones que capturan el ratón
		CRect r;
		GetClientRect( &r );
		BOOL res = r.PtInRect( point );  // si el punto está dentro o fuera del área cliente
 
		if (res) // Dentro del área cliente visual
		{
			switch (getDiag()->m_estadoEdic)   	// Establecimiento de cursores si el ratón está capturado:
			{
				case CAMBIAETIQDIAG:  
				{
					::SetCursor(AfxGetApp()->LoadCursor(IDC_EDICTXT));	
		            break;
		        }
				case INSCONECT:
				{
					::SetCursor(AfxGetApp()->LoadCursor(IDC_INSCONEC));	
					break;
				}
				case INSCONECTRETRO:
				{
					::SetCursor(AfxGetApp()->LoadCursor(IDC_INSCONECRETRO));	
					break;
				}
				case CAMBIAETIQCONECT:
				{
					::SetCursor(AfxGetApp()->LoadCursor(IDC_EDICTXT));	
					break;
				}		
				case MOVERGRUPO:
				{
		            if (PTOINICIAL == getDiag()->m_subEstadoEdic )
		            {
						::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVGRUPO_PORIG));	
						break;
		            }
		            else // PTOFINAL
		            {
						::SetCursor(AfxGetApp()->LoadCursor(IDC_MOVGRUPO_PDEST));	
						break;
		            }
					break;
				}			
				case SELECCGRUPO:
				{
					::SetCursor(AfxGetApp()->LoadCursor(IDC_RECTSELEC));		
                    break;
				}
				case DESELECCGRUPO:
				{
					::SetCursor(AfxGetApp()->LoadCursor(IDC_RECTDESELEC));		
				    break;
				}
			}
		}
		else    // El punto está fuera del área cliente (zona prohibida) la ventana.
		{
			::SetCursor(AfxGetApp()->LoadCursor(IDC_PROHIBIDO));			
		}
	}

	CBaseView::OnMouseMove(nFlags, point);
}


void CDiagDisView::OnActivateView( BOOL bActivate, CView* pActivateView, CView* pDeactiveView )
{
	if ((m_capturado)&&(!GetCapture())) SetCapture();  // Hemos perdido la captura del ratón por cambiar de aplicación, lo restauramos.
 	
 	CBaseView::OnActivateView( bActivate, pActivateView, pDeactiveView );
}

void CDiagDisView::OnInsBlqfuncDll()
{
	// TODO: Add your command handler code here
    CDiagDis* pDiag = getDiag();
	if (pDiag->m_estadoEdic != NULO) return;
	ScrollToPosition( CPoint(0,0) );    

	try
	{
		pDiag->NuevoBloqueDLLFunc(); // Lo define y añade a la lista
	}
	catch(Exception* ex)
	{
		getDiag()->getVistas()->Mensaje(ex);
		delete ex;	
	}
}

void CDiagDisView::OnInsBlqRetro()
{
	// TODO: Add your command handler code here
    CDiagDis* pDiag = getDiag();
	if (pDiag->m_estadoEdic != NULO) return;	
	ScrollToPosition( CPoint(0,0) );  

	try
	{
		pDiag->NuevoBloqueDLLRetro();
	}
	catch(Exception* ex)
	{
		getDiag()->getVistas()->Mensaje(ex);
		delete ex;	
	}
}

void CDiagDisView::OnInsBlqfuncDiag()
{
	// TODO: Add your command handler code here
    CDiagDis* pDiag = getDiag();
	if (pDiag->m_estadoEdic != NULO) return;	
	ScrollToPosition( CPoint(0,0) );  

	try
	{
		pDiag->NuevoBloqueDiag();	
	}
	catch(Exception* ex)
	{
		getDiag()->getVistas()->Mensaje(ex);
		delete ex;	
	}
}

void CDiagDisView::OnInsConect()
{
	// TODO: Add your command handler code here
	
	if (NULO == getDiag()->m_estadoEdic)
	{
		getDiag()->m_estadoEdic = INSCONECT;
		SetCapture();
		m_capturado = true;

		// OnMouseMove se encargará de poner el cursor adecuado.
	}
}

void CDiagDisView::OnInsConectRetro()
{
	// TODO: Add your command handler code here
	if (NULO == getDiag()->m_estadoEdic)
	{
		getDiag()->m_estadoEdic = INSCONECTRETRO;
		SetCapture();
		m_capturado = true;

		// OnMouseMove se encargará de poner el cursor adecuado.
	}
}

void CDiagDisView::OnDestroy()    
{
	CBaseView::OnDestroy();
	
	// TODO: Add your message handler code here

}

void CDiagDisView::OnCancelarEdic()
{
	// TODO: Add your command handler code here
	CDiagDis* pDiag = getDiag();
	pDiag->m_estadoEdic = NULO;
	ReleaseCapture(); // No tiene mucho sentido pero por si acaso, pues el menú sólo es accesible cuando no hay captura de ratón.
	m_capturado = false;			
}

void CDiagDisView::OnUpdateCancelarEdic(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (getDiag()->m_estadoEdic == NULO)	pCmdUI->Enable( false );
	else  pCmdUI->Enable( true );  // Hay un proceso de edición en marcha, puede cancelarse.
}

void CDiagDisView::OnMovergrupo()
{
	// TODO: Add your command handler code here

	if (getDiag()->m_estadoEdic == NULO)
	{
		getDiag()->m_estadoEdic = MOVERGRUPO;
		getDiag()->m_subEstadoEdic = PTOINICIAL;
		SetCapture();
		m_capturado = true;
		// OnMouseMove se encargará de poner el cursor adecuado 
	}
}

void CDiagDisView::OnSeleccTodo()
{                    
	// TODO: Add your command handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	pDibDiag->Seleccionar(true);	
	getVistas()->Actualizar();
}

void CDiagDisView::OnAnularselecc()
{
	// TODO: Add your command handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	pDibDiag->Seleccionar(false);	
	getVistas()->Actualizar();
}

void CDiagDisView::OnUpdateAnularselecc(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	BOOL sel = pDibDiag->ExisteAlgoSeleccionado();
	pCmdUI->Enable( sel );
}


void CDiagDisView::OnSeleccEliminar() 
{
	// TODO: Add your command handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	pDibDiag->EliminarSeleccion();	// Se actualizan las vistas y el doc. dentro
}


void CDiagDisView::OnUpdateSeleccEliminar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	BOOL sel = pDibDiag->ExisteComponenteSeleccionado();
	pCmdUI->Enable( sel );	
}

void CDiagDisView::OnSeleccRect()
{
	// TODO: Add your command handler code here

	if (getDiag()->m_estadoEdic == NULO)
	{
		getDiag()->m_estadoEdic = SELECCGRUPO;
		// SetCapture(); NO capturamos porque sino no funciona el CRectTracker pues necesita capturar.
		// Capturado = true;
	}
}

void CDiagDisView::OnDeseleccRect()
{
	// TODO: Add your command handler code here
	if (getDiag()->m_estadoEdic == NULO)
	{
		getDiag()->m_estadoEdic = DESELECCGRUPO;
		// SetCapture(); NO capturamos porque sino no funciona el CRectTracker pues necesita capturar.
		// Capturado = true;
	}
}


void CDiagDisView::OnUpdateDeseleccRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	BOOL sel = pDibDiag->ExisteAlgoSeleccionado();
	pCmdUI->Enable( sel );
}


void CDiagDisView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if ( (SELECCGRUPO == getDiag()->m_estadoEdic) || (DESELECCGRUPO == getDiag()->m_estadoEdic) )
	{
		CRect rt(point,CSize(10,10));   // Rectángulo inicial
		CRectTracker tracker( rt, CRectTracker::resizeInside );
	    point = rt.BottomRight(); // Equivale a point.x += 10 idem .y	
	    point.x -= 1;  // Para que esté dentro del rectángulo y no exactamente en el borde (necesario).
	    point.y -= 1;  // Idem
	    CPoint p = point;
	    ClientToScreen(&p);
	    SetCursorPos(p.x,p.y);
		
		BOOL Selecc = true; 
		if (SELECCGRUPO == getDiag()->m_estadoEdic)   
		{
			Selecc = true; 
			::SetCursor(AfxGetApp()->LoadCursor(IDC_RECTSELEC));  // Esto es porque creo que captura el ratón en una ventana invisible quizás.		
		}
		else
		{
			Selecc = false; 
			::SetCursor(AfxGetApp()->LoadCursor(IDC_RECTDESELEC));				
		}
	
		tracker.Track(this, point ); 	// Mientras no se levante el botón, al mover el ratón se puede cambiar de tamaño el rectángulo. Captura el ratón posiblemente por una ventana transparente que crea el CRectTracker
	    rt = tracker.m_rect;  // Nuevo tamaño (la posición es la misma).

		if (DESELECCGRUPO == getDiag()->m_estadoEdic) Selecc = false;

		CDibDiagramaDis* pDibDiag = getDibDiagrama();
		pDibDiag->Seleccionar(Selecc, &rt, this);	
	    // Ojo el levantado del botón lo procesa el CRecTracker no la vista, por lo que anulamos aquí el estado de edición.
	    getDiag()->m_estadoEdic = NULO;

		getVistas()->Actualizar();
	}
	
	CBaseView::OnLButtonDown(nFlags, point);
}

void CDiagDisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

    CPoint ptemp;
    GetCursorPos(&ptemp);  // Coordenadas de pantalla
    ScreenToClient(&ptemp); // En coordenadas cliente

	CRect r;
	GetClientRect( &r );
	BOOL res = r.PtInRect( ptemp );  // si el punto está dentro o fuera del área cliente
    
	if (res) 
	{
		CDibDiagramaDis* pDibDiag = getDibDiagrama();		

		if (( 17 == nChar ) && (pDibDiag->m_rejilla.m_forzCoor))  // La tecla 17 es la tecla CONTROL
		{
			ForzarPosicionCursor(ptemp);
		}
	}

	CBaseView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CDiagDisView::ForzarPosicionCursor(CPoint pos)
{
	// Para que los puntos de posición de las cosas puedan caer en puntos exactos de la rejilla coordenada forzada.			    
	// Sin embargo el obligar a que el cursor sólo caiga en puntos de la rejilla hace que el movimiento del ratón sea muy forzado, obligamos por tanto a que caiga en posiciones del DINA4 enteras en mm.
	// Por tanto sólo lo hacemos cuando se pulsa CONTROL y se mueve un poco: el resultado es el que el cursor se sitúa en el punto más cercano.

	pos = Cliente_A_mm(pos);	  // En mm reales y en coordenadas forzadas.
	// Deshacemos para obtener el punto en coordenadas cliente pero que coincida con las posiciones forzadas.

	CDibDiagrama* pdibdiag = getDibDiagrama();

	pos = pdibdiag->Escala(pos, this);  // En coordenadas lógicas.
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.LPtoDP(&pos);

	ClientToScreen(&pos); // En coordenadas de pantalla
	SetCursorPos(pos.x, pos.y);  // Para que se manifieste visualmente que es lo que queremos.
}


void CDiagDisView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	pDibDiag->CopiarSeleccionAPortapapeles(this);
}


void CDiagDisView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	pDibDiag->PegarSeleccionDesdePortapapeles(this);	
}


void CDiagDisView::OnEditCut() 
{
	// TODO: Add your command handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	pDibDiag->CopiarSeleccionAPortapapeles(this);	
	pDibDiag->EliminarSeleccion();
}

void CDiagDisView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CIdfApp* pApp = (CIdfApp *)AfxGetApp();

	if (CClipboard::hayDatos(this)) pCmdUI->Enable( true );
	else pCmdUI->Enable( false );
}


void CDiagDisView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	BOOL sel = pDibDiag->ExisteComponenteSeleccionado();
	pCmdUI->Enable( sel );
}

void CDiagDisView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDibDiagramaDis* pDibDiag = getDibDiagrama();

	BOOL sel = pDibDiag->ExisteComponenteSeleccionado();
	pCmdUI->Enable( sel );	
}

void CDiagDisView::OnPropRejilla() 
{
	// TODO: Add your command handler code here
	CDiagramaVistasDis* pVistas = getVistas();	
	pVistas->PropRejilla();	
}

void CDiagDisView::OnVerTabladiag() 
{
	// TODO: Add your command handler code here
	CDiagramaVistasDis* pVistas = getVistas();

	pVistas->CambiaVerTablaDis();	
}

void CDiagDisView::OnUpdateVerTabladiag(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CDiagramaVistasDis* pVistas = getVistas();

	BOOL res = pVistas->SincronizarEstadoTablaDis();

	pCmdUI->SetCheck( res );	
}

void CDiagDisView::OnEjecutarDiag() 
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

	CGlobal::NuevoDiagSinPrompt(false);

	CGlobal::m_fichero = "";
}


void CDiagDisView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

	m_noActualizaPosBloq = true;	
	CBaseView::OnHScroll(nSBCode, nPos, pScrollBar);
	m_noActualizaPosBloq = false;
}

void CDiagDisView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	m_noActualizaPosBloq = true;	
	CBaseView::OnVScroll(nSBCode, nPos, pScrollBar);
	m_noActualizaPosBloq = false;
}
