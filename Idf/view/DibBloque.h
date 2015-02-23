// DibBloque.h: interface for the CDibBloque class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBBLOQUE_H__28C7F7ED_B6C6_4E85_BA3C_CBAB378D6420__INCLUDED_)
#define AFX_DIBBLOQUE_H__28C7F7ED_B6C6_4E85_BA3C_CBAB378D6420__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Flecha.h"

class CBaseView;
class DOMElement;
class CBloqueVistas;
class CBloque;


// Tipos de dibujo de bloque

#define RECTANGULO  1
#define ROMBO		2
#define ELIPSE	 	3

// Dimensiones por defecto del rect�ngulo de bloques en mm.

#define LONGANCHO  50
#define LONGALTO   25


class CDibBloque : public CObject  
{
public:
	CDibBloque();
	virtual ~CDibBloque();
	void Construir(CBloqueVistas* pvistas);

	virtual void LeerDatosLDD( DOMElement* vistas,DOMTreeWalker* walker );
	virtual void EscribirDatosLDD( DOMElement* vistas );

	virtual void Serialize(CArchive& ar);
	virtual BOOL Dibujar(CDC* pDC, CBaseView* view);

    CString getTipoDibujoStr();
    BOOL setTipoDibujo(CString& tipo);

public:
	CBloque* p_bloque;
	CBloqueVistas* p_vistas;

	// A fichero
	BOOL m_visible;   // 1=Visible  0=Oculto . Defecto 1
	int m_tipoDibujo;      // Tipo de dibujo. 
	int m_anchoLin;        // Ancho l�nea. S�lo impresi�n.

	CRect m_rect;           // Dimensiones y punto de inserci�n del rect�ngulo en mm reales DIN A4.

	CFlecha m_flechaAE; 
	CFlecha m_flechaAS;  

	COLORREF m_colRec;  // Color del rect�ngulo. S�lo impresi�n.
	COLORREF m_colInt;   // Color interior. S�lo impresi�n.
	COLORREF m_colEtiq;  // S�lo impresi�n.
	
	// Temporales (no se guardan a fichero)


	// Variables relacionadas con los di�logos en diferentes vistas asociadas al mismo bloque funcional
	// y que manejar�n los propios di�logos pero que ponemos aqu� para asegurar la unicidad de estado de todos
	// los di�logos asociados a un mismo bloque.
	// Es como si fuera CBloque el documento al que se asocian los di�logos como vistas
	
	CBrush NEAR m_dlgBrushNuevo;
	CBrush NEAR m_dlgBrushIncompleto;
	CBrush NEAR m_dlgBrushErroneo;
	CBrush NEAR m_dlgBrushCorrecto;
};

#endif // !defined(AFX_DIBBLOQUE_H__28C7F7ED_B6C6_4E85_BA3C_CBAB378D6420__INCLUDED_)
