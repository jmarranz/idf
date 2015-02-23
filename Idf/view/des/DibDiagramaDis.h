// DibDiagramaDis.h: interface for the CDibDiagramaDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBDIAGRAMADIS_H__05C9878D_0BC6_434C_A0A3_DA4016A74F82__INCLUDED_)
#define AFX_DIBDIAGRAMADIS_H__05C9878D_0BC6_434C_A0A3_DA4016A74F82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\DibDiagrama.h"
#include "Rejilla.h"

class ListaBloques;
class ListaConectores;
class CBaseView;
class CDiagDisView;
class CDiagDis;

class CDibDiagramaDis : public CDibDiagrama  
{
public:
	CDibDiagramaDis();
	virtual ~CDibDiagramaDis();

	CDiagDis* getDiag()
	{
		return (CDiagDis*)p_diag;
	}

	virtual void Serialize(CArchive& ar);

	virtual void Dibujar(CDC* pDC, CBaseView* view);

	CPoint EscalaInversa(CPoint& pto, CBaseView* view);


	// Funciones de selección de un grupo de elementos
	virtual void MoverGrupoSelecc();
	virtual void MoverGrupoSelecc(ListaBloques* plista,const CPoint& desp);
	virtual void MoverGrupoSelecc(ListaConectores* plista,const CPoint& desp);


	virtual void Seleccionar(BOOL selec = true, CRect* prsel = NULL, CDiagDisView* view = NULL );   // Seleccionar/Deseleccionar los objetos dentro del rectángulo (si es nulo	se seleccionan todos).
	virtual void Seleccionar(ListaBloques* plista,BOOL selec, CRect * prsel, CDiagDisView* view );
	virtual void Seleccionar(ListaConectores* plista,BOOL selec, CRect * prsel, CDiagDisView* view);
	
	
	virtual void EliminarSeleccion();
	virtual void EliminarSeleccion(ListaBloques* plista);
	virtual void EliminarSeleccion(ListaConectores* plista);

	virtual BOOL ExisteComponenteSeleccionado();  // Comprueba si hay algún conector (completo) o bloque seleccionado
	virtual BOOL ExisteComponenteSeleccionado(ListaBloques* plista);
	virtual BOOL ExisteComponenteSeleccionado(ListaConectores* plista);

	virtual BOOL ExisteAlgoSeleccionado();  // Comprueba si hay algún nudo o bloque seleccionado
	virtual BOOL ExisteAlgoSeleccionado(ListaBloques* plista);
	virtual BOOL ExisteAlgoSeleccionado(ListaConectores* plista);


	// Relacionadas con la copia de elementos desde el portapapeles
	void CopiarSeleccionAPortapapeles(CWnd* pview);
	void PegarSeleccionDesdePortapapeles(CWnd* pview);

public:
	CPoint m_ptoIni;  // Punto temporal (por ejemplo para mover: pto origen)
	CPoint m_ptoFin;  // Idem (ej. pto. destino)

	// Variables que se guardan a fichero:

	CRejilla m_rejilla;
};

#endif // !defined(AFX_DIBDIAGRAMADIS_H__05C9878D_0BC6_434C_A0A3_DA4016A74F82__INCLUDED_)
