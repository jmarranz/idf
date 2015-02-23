// DibDiagrama.h: interface for the CDibDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBDIAGRAMA_H__C4DB113D_06C6_41EF_8452_54A7026241D8__INCLUDED_)
#define AFX_DIBDIAGRAMA_H__C4DB113D_06C6_41EF_8452_54A7026241D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Rgb.h"

class CDiagBase;
class CBaseView;
class DOMElement;
class ListaBloques;
class ListaConectores;
class CDiagramaVistas;

// Fuente para textos dibujados (TAMFONTDIAG se da en mm reales)

#define 	TAMFONTDIAG 	3
#define		FONTDIAG		"Arial"


class CDibDiagrama : public CObject  
{
	DECLARE_SERIAL(CDibDiagrama)
public:
	CDibDiagrama();
	virtual ~CDibDiagrama();

	void Construir(CDiagramaVistas* pvistas);

	CDiagBase* getDiag()
	{
		return p_diag;
	}

	CDiagramaVistas* getVistas()
	{
		return p_vistas;
	}

	virtual void LeerDatosLDD(DOMElement* vistas);
	virtual void EscribirDatosLDD(DOMElement* vistas);

	virtual void Serialize(CArchive& ar);

	virtual void Dibujar(CDC* pDC, CBaseView* view);
	virtual void Dibujar(ListaBloques* plista,CDC* pDC, CBaseView* view);
	virtual void Dibujar(ListaConectores* plista,CDC* pDC, CBaseView* view);

	virtual CRect Escala(CRect& rect, CBaseView* view );
	virtual CPoint Escala(CPoint& pto, CBaseView* view);

	virtual CRect EscalaInversa(CRect& rect, CBaseView* view );
	virtual CPoint EscalaInversa(CPoint& pto, CBaseView* view);

	virtual void GenerarMetafile();

public:
    // Variables de valor fijo. 

	int m_iPtSize;   // Común a todos los diagramas al ser valores de partida.
	CString m_nomfont;   // Idem

	// A fichero

	CPoint m_pInsEtiq;  // Pto de inserción etiqueta del diagrama
	CRgb m_colEtiq;
	
    BOOL m_scrollAuto;  // Habilita/deshabilita el movimiento auto. (scroll) de la ventana. Se guarda a fichero.
	BOOL m_operZoom;  // Permitir operaciones de Zoom (acercar, alejar etc.)


protected:
	CDiagramaVistas* p_vistas;
	CDiagBase* p_diag;
};

#endif // !defined(AFX_DIBDIAGRAMA_H__C4DB113D_06C6_41EF_8452_54A7026241D8__INCLUDED_)
