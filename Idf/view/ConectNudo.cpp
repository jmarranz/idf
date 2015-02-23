// ConectNudo.cpp: implementation of the CConectNudo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "ConectNudo.h"

#include "BaseView.h"
#include "DibDiagrama.h"
#include "DiagramaVistas.h"

#include "..\model\Conect.h"
#include "..\model\DiagBase.h"
#include "..\model\BaseDoc.h"

#include "..\xmlutil\XMLUtil.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Clase CConNudo

IMPLEMENT_SERIAL(CConNudo,CObject,1)

CConNudo::CConNudo()
{
	p_nudoPrev = NULL;
	p_nudoSig = NULL;

	p_conect = NULL;

	m_posNudo = CPoint(10,10); // Por tomar un valor de partida.

	m_seleccionado = false; 
}

void CConNudo::Construir(CConect* pcon)
{
	p_conect = pcon;
}

void CConNudo::Destruir()
{
}

void CConNudo::CrearNuevo()
{
}


void CConNudo::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_posNudo;
	}
	else
	{
		CBaseDoc* pdoc = (CBaseDoc*)ar.m_pDocument;
		Construir(pdoc->getConectTmp());

		ar >> m_posNudo;
	}
}

void CConNudo::DibujarTramo(CDC* pDC, CBaseView* view,CConNudo* pNudoPrev)
{
	CDibDiagrama* pdibdiag = p_conect->getDiag()->getVistas()->getDibDiagrama();
	
	CPoint pnudo = pdibdiag->Escala(m_posNudo, view); // En lógicas de la vista
	if (pNudoPrev)
	{
		CPoint pprev = pdibdiag->Escala(pNudoPrev->m_posNudo, view);    
    	pDC->MoveTo( pprev );
		pDC->LineTo( pnudo ); 
    }
	if ((view) && (!view->m_imprimiendo) && m_seleccionado)  // Dibujamos sobre la vista el marco de la selección.
	{
		CPoint pins = pnudo;
		pDC->LPtoDP(&pins);  // En coordenadas cliente de la vista.
	
		// El tamaño del rectángulo (toda la ventana incluido el borde) del nudo es fijo: 10x10 puntos de pantalla.
    	// El punto del nudo cae en el centro de la ventana.
	    
	    CRect r( CPoint(pins.x - ANCHONUDO / 2, pins.y - ALTONUDO / 2), CSize(ANCHONUDO, ALTONUDO) ); // En coordenadas cliente.
		CRectTracker RectTrk( r, CRectTracker::dottedLine); 
		RectTrk.Draw(pDC);	
	}
}

void CConNudo::LeerDatosLDD(DOMElement* nudo)
{
	DOMTreeWalker* walker = XMLUtil::crearWalker(nudo);

	DOMElement* xPos = (DOMElement*)walker->firstChild();
	int x = XMLUtil::getEntero(xPos);

	DOMElement* yPos = (DOMElement*)walker->nextSibling();
	int y = XMLUtil::getEntero(yPos);

	m_posNudo = CPoint(x,y);
}

void CConNudo::EscribirDatosLDD(DOMElement* nudo)
{
	DOMElement* xPos = XMLUtil::appendElement(nudo,"xPos");
	XMLUtil::setEntero(xPos,m_posNudo.x);

	DOMElement* yPos = XMLUtil::appendElement(nudo,"yPos");
	XMLUtil::setEntero(yPos,m_posNudo.y);
}

int CConNudo::getTipoNudo()
{
	if (NULL == p_nudoPrev) return NUDO_INICIO;
	else if (NULL == p_nudoSig) return NUDO_FINAL;
	else return NUDO_MEDIO;
}

