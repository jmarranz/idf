// Rejilla.cpp: implementation of the CRejilla class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "Rejilla.h"

#include "DibDiagramaDis.h"
#include "..\BaseView.h"
#include "..\DiagramaVistas.h"

#include "..\..\model\BaseDoc.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRejilla::CRejilla()
{
	p_dibDiag = NULL;

    m_forzCoor = true; // Forzar coordenadas a la rejilla
    m_verRejilla = true; // Ver rejilla.
	m_incX = 5;  // Rejilla inc. de X	en mm
	m_incY = 5;  // Rejilla inc. de Y	en mm
}

CRejilla::~CRejilla()
{

}

void CRejilla::setDibDiagrama(CDibDiagramaDis* pdigDiag)
{
	p_dibDiag = pdigDiag;
}

void CRejilla::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_forzCoor << m_verRejilla;
		ar << m_incX << m_incY;	
   	}
	else
	{
		ar >> m_forzCoor >> m_verRejilla;
		ar >> m_incX >> m_incY;	
	}
} 

CPoint CRejilla::AdaptarPtoRejilla(const CPoint& pto)
{
    // Calcula el pto más cercano al dado en las coordenadas impuestas por la rejilla. El pto argumento ha de estar en mm reales del DINA4
	CPoint p = pto;
	CPoint pmin;
	pmin.x = (p.x / m_incX) * m_incX;  // Es división entera, cortando el decimal.
	pmin.y = (p.y / m_incY) * m_incY;  //      "

	// Calculo de la distancia mínima por mínimos cuadrados.
	unsigned dxm = pmin.x - p.x;
	unsigned dym = pmin.y - p.y;
    unsigned dx = dxm;
    unsigned dy = dym;
	unsigned D1 = dx*dx + dy*dy;

	dx = dxm + m_incX;
	dy = dym;
	unsigned D2 = dx*dx + dy*dy;

	dx = dxm;
	dy = dym + m_incY;
	unsigned D3 = dx*dx + dy*dy;

	dx = dxm + m_incX;
	dy = dym + m_incY;
	unsigned D4 = dx*dx + dy*dy;

	unsigned res1 = min(D1,D2);
    unsigned res2 = min(D3,D4);
    unsigned res = min(res1,res2);
    
    if (res == D1) p = pmin;
    else
    if (res == D2) p = CPoint(pmin.x + m_incX, pmin.y);
    else
    if (res == D3) p = CPoint(pmin.x       , pmin.y + m_incY);
    else
    if (res == D4) p = CPoint(pmin.x + m_incX, pmin.y + m_incY);
	
	return p;
}

void CRejilla::Dibujar(CDC* pDC, CBaseView* view)
{
	if (!pDC->IsPrinting())
	{	
		CSize size = p_dibDiag->getVistas()->getDiagSize();
		int size_x = size.cx / 10;
		int size_y = size.cy / 10;

		// Rellenamos el área con una malla para situar bien los objetos.
		if (m_verRejilla)
		{
			// Optimizamos el dibujado, que no se iteren y dibujen puntos que no están en el área de invalidación.
			CRect r;  // En coordenadas de dispositivo (cliente).
			pDC->GetClipBox( &r );  // Area invalidada en coordenadas lógicas.
			int iini = 0; 
			int jini = 0;
			int ifin = size_x; 
			int jfin = size_y;

			if (!r.IsRectNull())
			{
				r = p_dibDiag->CDibDiagrama::EscalaInversa(r,view); // En mm reales.
				iini = (r.TopLeft().x / m_incX) * m_incX;  // Es división entera.
				jini = (r.TopLeft().y / m_incY) * m_incY;  // Idem
				ifin = (r.BottomRight().x / m_incX) * m_incX;
				jfin = (r.BottomRight().y / m_incY) * m_incY;
			}
			else
			{
				r = CRect(0,0,size_x,size_y);
			}
			
			for ( int i = iini; (i <= size_x)&&(i <= ifin) ; i += m_incX )
			{
				for ( int j = jini ; (j <= size_y)&&(j <= jfin) ; j += m_incY )
				{
					CPoint p(i,j); 
					if (r.PtInRect(p))	// Por más seguridad, seguramente puede quitarse.
					{
						p = p_dibDiag->Escala(p, view);
						pDC->SetPixel( p.x, p.y, RGB(0,0,0) );
					}
				}
			}
		}
	}
}
