// Flecha.cpp: implementation of the CFlecha2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "Flecha.h"

#include "DibDiagrama.h"
#include "DiagramaVistas.h"

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

// Clase CFlecha


IMPLEMENT_SERIAL(CFlecha, CObject,1)

CFlecha::CFlecha()
{
	m_orienta = SUR;

	m_ptoInsFlecha = CPoint(10,10);
	m_altFlecha = ALTURAFLECHA;
}

CFlecha::~CFlecha()
{

}

void  CFlecha::Iniciar(const CPoint& ptoIns,int altura,int anchoBorde,int orienta )
{
	m_ptoInsFlecha = ptoIns;
	m_altFlecha = altura;
	m_anchoBorde = anchoBorde;
	m_orienta = orienta;
}


void CFlecha::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_orienta;
		ar << m_ptoInsFlecha;
		ar << m_altFlecha;
		ar << m_anchoBorde;
	}
	else
	{
		ar >> m_orienta;
		ar >> m_ptoInsFlecha;
		ar >> m_altFlecha;
		ar >> m_anchoBorde;
	}	
}

void CFlecha::Dibujar(CDC* pDC,CBaseView* view, CDiagBase* pdiag, COLORREF color, BOOL escala)
{
	// El ancho de CPen tiene poco sentido en un triángulo relleno, sin embargo debe ser un valor sensato, pues se rellena lo de dentro de los trazos.

	CPen    penFlecha;
	CBrush  brushFlecha;

	if (!penFlecha.CreatePen(PS_SOLID, m_anchoBorde, RGB(0,0,0)))  return;  // Siempre negro el borde de la flecha
	if (!brushFlecha.CreateSolidBrush(color)) return;    
    CPen* pOldPen = pDC->SelectObject( &penFlecha );
    CBrush* pOldBrush = pDC->SelectObject( &brushFlecha );

	int dx2,dy2,dx3,dy3;
	switch(m_orienta)	  // a es la altura del triángulo isósceles.
	{
		case NORTE:
		{ 
			dx2 = - m_altFlecha/2; 
			dy2 = m_altFlecha; 
			dx3 = - dx2; 
			dy3 = dy2;
			break;
		}
		case ESTE:
		{ 
			dx2 = - m_altFlecha; 
			dy2 = - m_altFlecha/2; 
			dx3 = dx2; 
			dy3 = - dy2;
			break;
		}
		case SUR:
		{ 
			dx2 = m_altFlecha/2;
			dy2 = - m_altFlecha; 
			dx3 = - dx2; 
			dy3 = dy2;
			break;
		}
		case OESTE:
		{ 
			dx2 = m_altFlecha; 
			dy2 = m_altFlecha/2;
			dx3 = dx2; 	
			dy3 = - dy2;
			break;
		}
		default:  // Idem NORTE por defecto
		{
			dx2 = - m_altFlecha/2;
			dy2 = m_altFlecha;
			dx3 = - dx2; 
			dy3 = dy2;
			break;
		}
    }
	CPoint p2, p3;
	CPoint p = m_ptoInsFlecha;   // Pues se dibuja sobre el área del papel.

	p2.x = p.x + dx2;
	p2.y = p.y + dy2;
	p3.x = p.x + dx3;
	p3.y = p.y + dy3;
    
    if (escala)
    {
		CDibDiagrama* pdibdiag = pdiag->getVistas()->getDibDiagrama();

		p2 = pdibdiag->Escala(p2, view);
    	p =  pdibdiag->Escala(p, view);
    	p3 = pdibdiag->Escala(p3, view);
	}
//	pDC->MoveTo( p2 );	
//	pDC->LineTo( p );
//	pDC->LineTo( p3 );
 
	LPPOINT lpPoints = new CPoint[3];          
		
	lpPoints[0] = p2;            
	lpPoints[1] = p;            
	lpPoints[2] = p3;
			
	int nCount=3;

   	pDC->Polygon( lpPoints, nCount );

	delete []  lpPoints;

	if (view) pDC->SelectObject( pOldPen );	// Si view == NULL es OLE y pDC es un Metafile, no hace falta y si se hace el comportamiento es impredecible.
	if (view) pDC->SelectObject( pOldBrush );
}

void CFlecha::LeerDatosLDD(DOMElement* flecha)
{
	DOMTreeWalker* walker = XMLUtil::crearWalker(flecha);

	int XFlechaIns,YFlechaIns;

	DOMElement* xFlechaPos = (DOMElement*)walker->firstChild();
	XFlechaIns = XMLUtil::getEntero(xFlechaPos);

	DOMElement* yFlechaPos = (DOMElement*)walker->nextSibling();
	YFlechaIns = XMLUtil::getEntero(yFlechaPos);

    m_ptoInsFlecha = CPoint(XFlechaIns,YFlechaIns);

	DOMElement* orientacion = (DOMElement*)walker->nextSibling();
	m_orienta = XMLUtil::getEntero(orientacion);

	DOMElement* altura = (DOMElement*)walker->nextSibling();
	m_altFlecha = XMLUtil::getEntero(altura);

	DOMElement* anchoBorde = (DOMElement*)walker->nextSibling();
	m_anchoBorde = XMLUtil::getEntero(anchoBorde);
}

void CFlecha::EscribirDatosLDD(DOMElement* flecha)
{
	DOMElement* xFlechaPos = XMLUtil::appendElement(flecha,"xFlechaPos");
	XMLUtil::setEntero(xFlechaPos,m_ptoInsFlecha.x);

	DOMElement* yFlechaPos = XMLUtil::appendElement(flecha,"yFlechaPos");
	XMLUtil::setEntero(yFlechaPos,m_ptoInsFlecha.y);
	
	DOMElement* orientacion = XMLUtil::appendElement(flecha,"orientacion");
	XMLUtil::setEntero(orientacion,m_orienta);

	DOMElement* altura = XMLUtil::appendElement(flecha,"altura");
	XMLUtil::setEntero(altura,m_altFlecha);

	DOMElement* anchoBorde = XMLUtil::appendElement(flecha,"anchoBorde");
	XMLUtil::setEntero(anchoBorde,m_anchoBorde);
}
