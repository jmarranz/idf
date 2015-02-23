// DibConect.cpp: implementation of the CDibConect2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "DibConect.h"

#include "ConectNudo.h"
#include "BaseView.h"
#include "DiagramaVistas.h"
#include "ConectVistas.h"
#include "DibDiagrama.h"

#include "exe\ConectorNudoExe.h"
#include "des\ConectorNudoDis.h"


#include "..\model\Conect.h"
#include "..\model\DiagBase.h"
#include "..\model\BaseDoc.h"
#include "..\model\ConectorException.h"

#include "..\xmlutil\XMLUtil.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Clase CDibConect

IMPLEMENT_DYNAMIC(CDibConect, CObject)

CDibConect::CDibConect()  // Los valores por defecto pueden ser útiles por ejemplo en la plantilla de diseño.
{
	p_conect = NULL;
	p_vistas = NULL;

	m_visible	= true;
	
	m_color = RGB(0,0,0);  // NEGRO Por defecto
	m_ancho = ANCHOLIN;

	m_ptoInsEtiq = CPoint(10,10);
}

void CDibConect::Construir(CConectVistas* pvistas)
{
	p_vistas = pvistas;
	p_conect = pvistas->getConect();
}

CDibConect::~CDibConect()
{
	BorraArrPtos();
}

void CDibConect::Destruir()
{
	BorraArrPtos();
}

void CDibConect::LeerDatosLDD(DOMElement* vistas)
{
	DOMTreeWalker* walker = XMLUtil::crearWalker(vistas);

	DOMElement* visible = (DOMElement*)walker->firstChild();
	m_visible = XMLUtil::getBoolean(visible);
	
	DOMElement* anchoLinea = (DOMElement*)walker->nextSibling();
	m_ancho = XMLUtil::getEntero(anchoLinea);

	if (p_conect->EsRetroanotador()) 
		m_ancho = 1; // Obligatorio para que la línea salga de puntos con el estilo PS_DOT

	DOMElement* flecha = (DOMElement*)walker->nextSibling();
	m_flecha.LeerDatosLDD(flecha);

	DOMElement* nudos = (DOMElement*)walker->nextSibling();
	LeerDatosLDDNudos(nudos);

	POSITION pos = m_listaNudos.GetHeadPosition();
	CConNudo* pNudo = (CConNudo*)m_listaNudos.GetNext(pos);	// El comienzo

	int XEtiqIns,YEtiqIns;

	DOMElement* xEtiqIns = (DOMElement*)walker->nextSibling();
	XEtiqIns = XMLUtil::getEntero(xEtiqIns);

	DOMElement* yEtiqIns = (DOMElement*)walker->nextSibling();
	YEtiqIns = XMLUtil::getEntero(yEtiqIns);
	
	if ( p_conect->getEtiqueta() == "" )
	{
		XEtiqIns = pNudo->m_posNudo.x; 
		YEtiqIns = pNudo->m_posNudo.y;  // Por defecto se sitúa el texto en el comienzo del primer tramo, puede añadirse texto a través del diálogo de propiedades del conector.
	}
	
    m_ptoInsEtiq = CPoint(XEtiqIns, YEtiqIns);
   
	DOMElement* rgbCon = (DOMElement*)walker->nextSibling();
	m_color.LeerDatosLDD(rgbCon);
}

void CDibConect::EscribirDatosLDD(DOMElement* vistas)
{
	DOMElement* visible = XMLUtil::appendElement(vistas,"visible");
	XMLUtil::setBoolean(visible,m_visible);
	
	DOMElement* anchoLinea = XMLUtil::appendElement(vistas,"anchoLinea");
	XMLUtil::setEntero(anchoLinea,m_ancho);

	DOMElement* flecha = XMLUtil::appendElement(vistas,"flecha");
	m_flecha.EscribirDatosLDD(flecha);	

	DOMElement* nudos = XMLUtil::appendElement(vistas,"nudos");
	EscribirDatosLDDNudos(nudos);

	DOMElement* xEtiqIns = XMLUtil::appendElement(vistas,"xEtiqIns");
	XMLUtil::setEntero(xEtiqIns,m_ptoInsEtiq.x);

	DOMElement* yEtiqIns = XMLUtil::appendElement(vistas,"yEtiqIns");
	XMLUtil::setEntero(yEtiqIns,m_ptoInsEtiq.y);

	DOMElement* rgbCon = XMLUtil::appendElement(vistas,"rgbCon");
	m_color.EscribirDatosLDD(rgbCon);
}


BOOL CDibConect::LeerDatosLDDNudos(DOMElement* nudos)
{
	DOMTreeWalker* walker = XMLUtil::crearWalker(nudos);

	DOMElement* nudo = (DOMElement*)walker->firstChild();
	while(nudo != NULL)
	{
		CConNudo* pnudo = crearNudo();

		pnudo->LeerDatosLDD(nudo);

		AnyadeNudoFinal( pnudo ); 

		pnudo->CrearNuevo();

		nudo = (DOMElement*)walker->nextSibling();
	}

	return true;
}

BOOL CDibConect::EscribirDatosLDDNudos(DOMElement* nudos)
{
	POSITION pos = m_listaNudos.GetHeadPosition();
	while( pos !=NULL )
	{                                                                                                                  
		CConNudo* pnudo = (CConNudo*)m_listaNudos.GetNext(pos);

		DOMElement* nudo = XMLUtil::appendElement(nudos,"nudo");
		
		pnudo->EscribirDatosLDD(nudo);
	}

	return true;
}

void CDibConect::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_visible;
		ar << m_ptoInsEtiq;
		ar << m_ancho;
		ar << m_color;

		m_listaNudos.Serialize(ar);
 	}
	else
	{
		ar >> m_visible;
		ar >> m_ptoInsEtiq;
		ar >> m_ancho;
		ar >> m_color;

		CBaseDoc* pdoc = (CBaseDoc*)ar.m_pDocument;
		pdoc->setConectTmp(p_conect);

		m_listaNudos.Serialize(ar);

		ReconectarTodosNudos(); //  Enlaza los conectores de los nudos para acceso rápido del anterior y posterior.
	}	

	m_flecha.Serialize(ar);
}


CFlecha* CDibConect::getpFlecha()
{
	return &m_flecha;
}


void CDibConect::Dibujar(CDC* pDC, CBaseView* view)
{
	if (m_visible)
	{
	 	switch (p_conect->getEstado())
	 	{
	 		case NOCIRCULA:
	 		{
	 			m_color = RGB(0,0,0); // Negro
                break;
            }
	 		case CIRCULA:
	 		{
	 			m_color = VERDE; 
                break;
            }            
	 		case FALLIDO:
	 		{
	 			m_color = MORADO; 
                break;
            }
    	}

		if ((NULL == view)||((view)&&(view->m_imprimiendo))) m_color = RGB(0,0,0); // Negro  por impresión o generación de metafichero
		
		CPen penLin;
		int EstiloPen;
		if (p_conect->EsRetroanotador())
		{ 
			EstiloPen = PS_DOT;
			m_ancho = 1; // Para que se pueda dibujar línea de puntos.
		} 
		else  EstiloPen = PS_SOLID;

		if (!penLin.CreatePen(EstiloPen, m_ancho, m_color.getColor())) return;
		CDiagBase* pDiag = p_conect->getDiag();    
		CPen* pOldPen = pDC->SelectObject( &penLin );

		// Falta especificar la fuente.
		CPoint p, p1, p2;

		pDC->SetBkColor(RGB(255,255,255));    
		pDC->SetTextColor( RGB(0,0,0) );   // Siempre negro.
 
		CDibDiagrama* pdibdiag = pDiag->getVistas()->getDibDiagrama();

		CPoint fontsize = pdibdiag->Escala(CPoint(0, pdibdiag->m_iPtSize), view);
		CFont NEAR FuenteEtiq;
		if (!FuenteEtiq.CreateFont(fontsize.y , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, PROOF_QUALITY, 0, pdibdiag->m_nomfont)) return; 
		CFont* fvieja = pDC->SelectObject( &FuenteEtiq );
    		
		p = pdibdiag->Escala( m_ptoInsEtiq, view );

		pDC->SetTextAlign(TA_LEFT | TA_NOUPDATECP);	   			 	
		pDC->TextOut( p.x, p.y , p_conect->getEtiqueta() );
		if (view) pDC->SelectObject( fvieja);  // Si view == NULL es OLE y pDC es un Metafile, no hace falta y si se hace el comportamiento es impredecible.
				
		CConNudo* pNudo = NULL;
		CConNudo* pNudoPrev = NULL;
		POSITION pos = m_listaNudos.GetHeadPosition();
		while( pos !=NULL )
		{                                                                                                                  
			pNudoPrev = pNudo;
			pNudo = (CConNudo*)m_listaNudos.GetNext(pos);
			if (pNudo)
			{
				pNudo->DibujarTramo(pDC,view, pNudoPrev);
			}
		}

		if (view) pDC->SelectObject( pOldPen );  // Si view == NULL es OLE y pDC es un Metafile, no hace falta y si se hace el comportamiento es impredecible.	

		m_flecha.Dibujar( pDC,view, pDiag, m_color.getColor(), true );
    }
}

void CDibConect::ReconectarTodosNudos()
{
	CConNudo* pNudoPrev = NULL;

	POSITION pos = m_listaNudos.GetHeadPosition();
	while( pos != NULL )
	{
		CConNudo* pNudo = (CConNudo*)m_listaNudos.GetNext(pos);
        if (pNudoPrev) pNudoPrev->p_nudoSig = pNudo;
        pNudo->p_nudoPrev = pNudoPrev;
	    pNudoPrev = pNudo;
	}
}


CConNudo* CDibConect::AnyadeNudoMedioAnterior(CConNudo* pNudoSig)
{
    CConNudo* pNudoPrev = pNudoSig->p_nudoPrev; // No hace falta especificar el nudo previo pues lo obtenemos del siguiente
    if (NULL == pNudoPrev)
    {
		throw new ConectorException(p_conect,"No se puede insertar un nudo medio antes del comienzo del conector");
    }

	CPoint pini = pNudoSig->p_nudoPrev->m_posNudo;
	CPoint pfin = pNudoSig->m_posNudo;
    CPoint pt = CPoint((pini.x + pfin.x) / 2 , (pini.y + pfin.y) / 2);  

    POSITION PosSig = getPosNudo(pNudoSig);
    
	CConNudo* pNudo = crearNudo();
	pNudo->m_posNudo = pt;

    Reconectar(pNudoPrev, pNudo, pNudoSig);

	pNudo->CrearNuevo();

    m_listaNudos.InsertBefore(PosSig, (CObject*)pNudo );

	return pNudo;
}	


CConNudo* CDibConect::AnyadeNudoMedioPosterior(CConNudo* pNudoPrev)
{
    CConNudo* pNudoSig = pNudoPrev->p_nudoSig; // No hace falta especificar el nudo siguiente pues lo obtenemos del anterior
    if (NULL == pNudoSig)
    {
		throw new ConectorException(p_conect,"No se puede insertar un nudo medio al final del conector");
    }

	CPoint pini = pNudoPrev->m_posNudo;
	CPoint pfin = pNudoPrev->p_nudoSig->m_posNudo;
    CPoint pt = CPoint((pini.x + pfin.x) / 2 , (pini.y + pfin.y) / 2);  
    
	POSITION PosPrev = getPosNudo(pNudoPrev);
    
	CConNudo* pNudo = crearNudo();
    pNudo->m_posNudo = pt;

    Reconectar(pNudoPrev, pNudo, pNudoSig);

	pNudo->CrearNuevo();

    m_listaNudos.InsertAfter(PosPrev, (CObject*)pNudo );
    
	return pNudo;
}	

void CDibConect::AnyadeNudoFinal(CConNudo* pNudo) 
{
	CConNudo* pNudoUltPrev = NULL; //Por si fuera el primer nudo creado.
	POSITION posultimo = m_listaNudos.GetTailPosition();
	if (NULL != posultimo)
	{
		pNudoUltPrev = (CConNudo*)m_listaNudos.GetAt( posultimo );
    }

    Reconectar(pNudoUltPrev, pNudo, NULL); // Si no hay ningún punto (pNudoUltPrev == NULL) el punto final nuevo será también el primer punto inicio del conector.

    m_listaNudos.AddTail(pNudo);   // pNudo es el nuevo último de la lista, final del conector.

}

CConNudo* CDibConect::AnyadeNudoFinal(CPoint pt) 
{
	CConNudo* pNudo = crearNudo();
    pNudo->m_posNudo = pt;

	AnyadeNudoFinal(pNudo);
	
	pNudo->CrearNuevo();

	return pNudo;
}	

void CDibConect::Reconectar(CConNudo* pNudoPrev,CConNudo* pNudo,CConNudo* pNudoSig)
{
	if (pNudoPrev)
	{
		pNudoPrev->p_nudoSig = pNudo;  // Desconectamos los dos nudos para insertar el nuevo.
	}

	if (pNudoSig)
	{
		pNudoSig->p_nudoPrev = pNudo;  //  Desconectamos ...
	}
	pNudo->p_nudoPrev = pNudoPrev;   // Conectamos el nuevo a los nudos contiguos. Si es NULL se igualará a NULL
	pNudo->p_nudoSig = pNudoSig;     //  Conectamos ...	

}

void CDibConect::EliminarNudo(CConNudo* pNudo) 
{
    POSITION pos = getPosNudo(pNudo);

	CConNudo* pNudoPrev = pNudo->p_nudoPrev;
	CConNudo* pNudoSig = pNudo->p_nudoSig;

    if ((NULL == pNudoPrev)||(NULL == pNudoSig))
    {
		throw new ConectorException(getConect(),"No se puede eliminar un nudo comienzo o final del conector");
    }
	
	pNudoPrev->p_nudoSig = pNudoSig;  // Desconectamos y conectamos al nudo siguiente.
	pNudoSig->p_nudoPrev = pNudoPrev;  //     "                             previo.

	m_listaNudos.RemoveAt(pos);

    pNudo->Destruir();
	delete pNudo;
}

POSITION CDibConect::getPosNudo(CConNudo* pNudo) 
{
	return m_listaNudos.Find(pNudo);
}

CConect* CDibConect::getConect()
{
	return p_conect;
}

void CDibConect::BorraArrPtos()
{
	POSITION pos = m_listaNudos.GetHeadPosition();
	while (pos != NULL)
	{	
		CConNudo* pNudoIter = (CConNudo*)m_listaNudos.GetNext(pos);
        delete pNudoIter;
    }
	m_listaNudos.RemoveAll( );
}

void CDibConect::OffsetConector(int x, int y)
{
	POSITION pos = m_listaNudos.GetHeadPosition();
	while (pos != NULL)
	{	
		CConNudo* pNudoIter = (CConNudo*)m_listaNudos.GetNext(pos);
		pNudoIter->m_posNudo.Offset(x,y);
    }

	m_flecha.m_ptoInsFlecha.Offset(x,y);
}


CConNudo* CDibConect::crearNudo()
{
    CConNudo* pNudo;
	if (!p_conect->getDiag()->EsDiagDiseno())
		pNudo = new CConectorNudoExe();
	else
		pNudo = new CConectorNudoDis();

	pNudo->Construir(p_conect);
	return pNudo;
}

	
