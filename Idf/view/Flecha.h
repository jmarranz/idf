// Flecha.h: interface for the CFlecha2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLECHA_H__9EA97C8F_9F59_47DB_AE93_8790E267ABCF__INCLUDED_)
#define AFX_FLECHA_H__9EA97C8F_9F59_47DB_AE93_8790E267ABCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBaseView;
class CDiagBase;
class DOMElement;

#define ALTURAFLECHA   5


// Orientación de las flechas (hacia adonde apuntan)

#define NORTE	1
#define ESTE 	2
#define SUR		3
#define OESTE	4


class CFlecha : public CObject
{
 	DECLARE_SERIAL(CFlecha)	
public:
	CFlecha();
	virtual void Iniciar(const CPoint& ptoIns,int altura,int anchoBorde,int orienta);
	virtual void Serialize(CArchive& ar);
	virtual void LeerDatosLDD(DOMElement* flecha);
	virtual void EscribirDatosLDD(DOMElement* flecha);

	virtual void Dibujar(CDC* pDC,CBaseView* view,CDiagBase* pdiag, COLORREF color, BOOL escala = true);	
	
	virtual ~CFlecha();

	// Nota: la flecha es un triangulo isósceles, y PtoIns es el vértice
	// Podemos definir la flecha también como un polígono tipo CRgn,

// Variables:

	CPoint m_ptoInsFlecha;  // Donde se inserta la flecha (pico del triángulo isósceles.
	int m_altFlecha;        // Altura y base del triángulo de la flecha.
	int m_anchoBorde; 
	int m_orienta;  // Orientación flecha (NORTE, SUR etc)

};


#endif // !defined(AFX_FLECHA_H__9EA97C8F_9F59_47DB_AE93_8790E267ABCF__INCLUDED_)
