// DibBloque.cpp: implementation of the CDibBloque class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "DibBloque.h"

#include "DibDiagrama.h"
#include "DiagramaVistas.h"
#include "BaseView.h"
#include "BloqueVistas.h"


#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"

#include "..\xmlutil\XMLUtil.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDibBloque::CDibBloque()
{
	p_vistas = NULL;
	p_bloque = NULL;

	m_dlgBrushNuevo.CreateSolidBrush( AZUL );
	m_dlgBrushIncompleto.CreateSolidBrush( AMARILLO );
	m_dlgBrushErroneo.CreateSolidBrush( MORADO );
	m_dlgBrushCorrecto.CreateSolidBrush( VERDE );

	m_colRec = RGB(0,0,0); 
	m_colInt =  GRIS;   // Sólo para impresión. 
	m_colEtiq = RGB(0,0,0);

	m_rect = CRect( CPoint(10,10), CSize(LONGANCHO, LONGALTO) );	

	m_anchoLin = ANCHOLIN;        // Ancho línea. Sólo impresión.
	m_tipoDibujo = RECTANGULO;      // Tipo de dibujo. 

	m_visible = true;   // 1=Visible  0=Oculto . Defecto 1

}

CDibBloque::~CDibBloque()
{

}

void CDibBloque::Construir(CBloqueVistas* pvistas)
{
	p_vistas = pvistas;
	p_bloque = pvistas->getBloque();
}

void CDibBloque::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);  // Llamada conveniente al padre, aunque en la 1.0 no hace nada.

	if (ar.IsStoring())
	{
		ar << m_visible;
		ar << m_tipoDibujo;
		ar << m_anchoLin; 
        ar << m_colRec << m_colInt << m_colEtiq;

		CPoint p1,p2;
		p1 = m_rect.TopLeft();		
		p2 = m_rect.BottomRight();
		ar << p1 << p2;
	}
	else
	{
		ar >> m_visible;
		ar >> m_tipoDibujo;	
		ar >> m_anchoLin;
        ar >> m_colRec >> m_colInt >> m_colEtiq;

		CPoint p1,p2;
		ar >> p1 >> p2;
        m_rect.SetRect( p1.x, p1.y, p2.x, p2.y );
	}	

	m_flechaAE.Serialize(ar);
	m_flechaAS.Serialize(ar);

}

void CDibBloque::LeerDatosLDD( DOMElement* vistas,DOMTreeWalker* walker )
{
	DOMElement* visible = (DOMElement*)walker->firstChild();
	m_visible = XMLUtil::getBoolean(visible);

	DOMElement* tipoDibujo = (DOMElement*)walker->nextSibling();
	m_tipoDibujo = XMLUtil::getEntero(tipoDibujo);
	if ((m_tipoDibujo <= 0)||(m_tipoDibujo > 3))  m_tipoDibujo = 1; // Rectángulo por defecto ante valor erróneo.

	CPoint pins;

	DOMElement* xPtoInser = (DOMElement*)walker->nextSibling();
	pins.x = XMLUtil::getEntero(xPtoInser);

	DOMElement* yPtoInser = (DOMElement*)walker->nextSibling();
	pins.y = XMLUtil::getEntero(yPtoInser);

	CSize s;

	DOMElement* longAlto = (DOMElement*)walker->nextSibling();
	s.cy = XMLUtil::getEntero(longAlto);

	DOMElement* longAncho = (DOMElement*)walker->nextSibling();
	s.cx = XMLUtil::getEntero(longAncho);


	DOMElement* anchoLin = (DOMElement*)walker->nextSibling();
	m_anchoLin = XMLUtil::getEntero(anchoLin);

	m_rect = CRect( pins, s);

    int ancho = m_rect.Width();
    int h = m_rect.Height();
	CPoint ptoInsFAE = CPoint( pins.x + ancho/2, pins.y + h/8 );
	CPoint ptoInsFAS = CPoint( pins.x + ancho/2, pins.y + h );	

	m_flechaAE.Iniciar(ptoInsFAE, h/8, m_anchoLin,SUR );
    m_flechaAS.Iniciar(ptoInsFAS, h/8, m_anchoLin,SUR );
}

void CDibBloque::EscribirDatosLDD(DOMElement* vistas)
{
	DOMElement* visible = XMLUtil::appendElement(vistas,"visible");
	XMLUtil::setBoolean(visible,m_visible);
	
	DOMElement* tipoDibujo = XMLUtil::appendElement(vistas,"tipoDibujo");
	XMLUtil::setEntero(tipoDibujo,m_tipoDibujo);
	
	DOMElement* xPtoInser = XMLUtil::appendElement(vistas,"xPtoInser");
	XMLUtil::setEntero(xPtoInser,m_rect.TopLeft().x);

	DOMElement* yPtoInser = XMLUtil::appendElement(vistas,"yPtoInser");
	XMLUtil::setEntero(yPtoInser,m_rect.TopLeft().y);

	DOMElement* longAlto = XMLUtil::appendElement(vistas,"longAlto");
	XMLUtil::setEntero(longAlto,m_rect.Height());

	DOMElement* longAncho = XMLUtil::appendElement(vistas,"longAncho");
	XMLUtil::setEntero(longAncho,m_rect.Width());

	DOMElement* anchoLin = XMLUtil::appendElement(vistas,"anchoLin");
	XMLUtil::setEntero(anchoLin,m_anchoLin);
}


BOOL CDibBloque::Dibujar(CDC* pDC, CBaseView* view)
{
	// Dibujado más bien para impresión y OLE, pues en pantalla se ponen encima los diálogos de bloque.
	// Si view == NULL entonces estamos generando una imagen para OLE

	CDiagBase* pdiag = p_bloque->getDiag();
	CDibDiagrama* pdibdiag = pdiag->getVistas()->getDibDiagrama();

	if ((NULL == view)||(view->m_imprimiendo))   // Podríamos usar pDC->IsPrinting() pero Imprimiendo se usa en otros lugares donde no tenemos el pDC
	{
		if (m_visible)
		{
			CPoint pins = m_rect.TopLeft();
			{   // Dibujado bloques, todos los objetos gráficos se destruyen al salir de "}" . Necesario para OLE
				CBrush  brushRect;
				CPen    penRect;
				if (!brushRect.CreateSolidBrush(m_colInt))
					return false;
				if (!penRect.CreatePen(PS_SOLID, m_anchoLin, m_colRec))
					return false;		
		    	CBrush* pOldBrush = pDC->SelectObject( &brushRect );
				CPen* pOldPen = pDC->SelectObject( &penRect );
	
				switch (m_tipoDibujo)
				{
					case 0: break;  // No dibujar 
					case RECTANGULO:   		// Rectángulo
					{	        
						CRect r = pdibdiag->Escala(m_rect, view);
						BOOL res = pDC->Rectangle( r );		
			    		break;
					}
					case ROMBO:   // Rombo
					{
						int x1,x2,y1,y2;

						x1=pins.x;
						y1=pins.y;
						x2=pins.x + m_rect.Width(); 
						y2=pins.y + m_rect.Height();
						int mx = (x1+x2)/2;
						int my = (y1+y2)/2;
						LPPOINT lpPoints = new CPoint[4];          
			
						lpPoints[0] = pdibdiag->Escala(CPoint( mx, y1 ), view);            
						lpPoints[1] = pdibdiag->Escala(CPoint( x2, my ), view);            
						lpPoints[2] = pdibdiag->Escala(CPoint( mx, y2 ), view);
						lpPoints[3] = pdibdiag->Escala(CPoint( x1, my ), view);  
				
						int nCount=4;
	
		            	pDC->Polygon( lpPoints, nCount );
	
						delete []  lpPoints;
							            
	            		// Es equivalente a (salvo que se rellena el área): 
	        		    
						// pDC->MoveTo( mx, y1 );
	            		// pDC->LineTo( x2, my );
	            		// pDC->LineTo( mx, y2 );
	            		// pDC->LineTo( x1, my );             
	            		// pDC->LineTo( mx, y1 );
		            	break;
					}            
					case ELIPSE:  // Círculo o elipse           
	        		{
						CRect r = pdibdiag->Escala(m_rect, view);
		            	CPoint p(r.Width(), r.Height());
	    	    		pDC->RoundRect( r, p );
	        			break;
	        		}
	        		default:   // Dibujamos como un RECTANGULO
	        		{
						CRect r = pdibdiag->Escala(m_rect, view);
						pDC->Rectangle( r );         			
	         			break;  // No dibujar
					}
				}    
			    if (view) pDC->SelectObject( pOldBrush );	 // Si view == NULL es OLE y pDC es un Metafile, no hace falta y si se hace el comportamiento es impredecible.
			    if (view) pDC->SelectObject( pOldPen );	
	        }  // Fin dibujado bloques
            
            {  // Etiqueta del bloque 
            
				pDC->SetBkColor(RGB(255,255,255));
				pDC->SetTextColor( m_colEtiq );
				
				CPoint fontsize = pdibdiag->Escala(CPoint(0, pdibdiag->m_iPtSize), view);
	        	CFont NEAR FuenteEtiq;   // Si es OLE es obligatorio, pues no hay recursos por defecto.
				if (!FuenteEtiq.CreateFont(fontsize.y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, PROOF_QUALITY, 0, pdibdiag->m_nomfont))
					return false; 
				CFont* fvieja = pDC->SelectObject( &FuenteEtiq );
	            
				CPoint p( pins.x, pins.y + m_rect.Height()/4 );
				CSize s( m_rect.Width(), m_rect.Height()/2 );
				CRect r = pdibdiag->Escala(CRect( p, s ), view);

	   			if (view)
	   			{
					pDC->SetTextAlign(TA_NOUPDATECP);	   			 	
	   			 	pDC->DrawText( (LPCSTR)p_bloque->getEtiqueta(), p_bloque->getEtiqueta().GetLength(), r, DT_CENTER | DT_WORDBREAK );
                }
                else 
				{   // Si es METAFILE (OLE) DrawText al parecer es incompatible.
					// Hacemos más pequeño el rectángulo a los lados pues ExtTextOut no centra automáticamente,
					// así parece más centrado (chapucilla visual)
					int wx = r.Width(); // Ancho original (idem del bloque)
					int wxn = wx - wx/4; // Valor nuevo
					p = r.TopLeft();
					p.x = p.x + wx/8;  // Nuevo punto de inserción
					r = CRect(p, CSize(wxn ,r.Height()));
					CPoint pt =  r.TopLeft(); // El punto de inserción ya escalado.
					
					pDC->SetTextAlign(TA_LEFT | TA_TOP | TA_NOUPDATECP);
					pDC->ExtTextOut( pt.x, pt.y, ETO_CLIPPED, &r, (LPCSTR)p_bloque->getEtiqueta(), p_bloque->getEtiqueta().GetLength(), NULL ); 
					//pDC->TextOut(pt.x,pt.y,pBloque->m_Etiq,pBloque->m_Etiq.GetLength());
				}
	 			if (view) pDC->SelectObject(fvieja);  // Si view == NULL es OLE y pDC es un Metafile, no hace falta y si se hace el comportamiento es impredecible.
            }
            // Flechas:
			if (p_bloque->getAE()) m_flechaAE.Dibujar(pDC,view, pdiag, m_colRec, true);
			if (p_bloque->getAS()) m_flechaAS.Dibujar(pDC,view, pdiag, m_colRec, true);
		}
	}
	else
	{
	}
	
	return true;
}

CString CDibBloque::getTipoDibujoStr()
{
	CString stemp;
	switch (m_tipoDibujo)
	{
		case 0:
		{ 
		   	AfxMessageBox("ERROR INTERNO");
		}
		case RECTANGULO:   		// Rectángulo
		{	        
			stemp = "RECTÁNGULO";
	  		break;
		}
		case ROMBO:   // Rombo
		{
            stemp = "ROMBO";
	       	break;
		}            
		case ELIPSE:  // Círculo o elipse           
    	{
			stemp = "ELIPSE";
    		break;
    	}
    	default:
    	{
			stemp = "OTRO"; // Raro que suceda
		}
    }	
	return stemp;
}


BOOL CDibBloque::setTipoDibujo(CString& tipo)
{
	if ("RECTÁNGULO" == tipo) { m_tipoDibujo = RECTANGULO; return true; }
	if ("ROMBO" == tipo) { m_tipoDibujo = ROMBO; return true; }
	if ("ELIPSE" == tipo) { m_tipoDibujo = ELIPSE; return true; }
	return false;
}

