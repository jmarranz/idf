// DibDiagramaDis.cpp: implementation of the CDibDiagramaDis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DibDiagramaDis.h"

#include "DibConectDis.h"
#include "DibBloqueDis.h"
#include "DiagDisView.h"
#include "Clipboard.h"
#include "DiagramaVistasDis.h"


#include "..\des\ConectVistasDis.h"
#include "..\BloqueVistas.h"

#include "..\..\model\des\DiagDis.h"
#include "..\..\model\Conect.h"
#include "..\..\model\Bloque.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDibDiagramaDis::CDibDiagramaDis()
{
	m_rejilla.setDibDiagrama(this);
}

CDibDiagramaDis::~CDibDiagramaDis()
{

}

void CDibDiagramaDis::Serialize(CArchive& ar)
{
	CDibDiagrama::Serialize(ar);

	m_rejilla.Serialize(ar);

	if (ar.IsStoring())
	{

	}
	else
	{
	}
} 

CPoint CDibDiagramaDis::EscalaInversa(CPoint& pto, CBaseView* view)
{
	CPoint p = CDibDiagrama::EscalaInversa(pto, view); // El valor devuelto está en mm reales
	CDiagDis* pdiagdis = p_diag->getDis();
    p = m_rejilla.AdaptarPtoRejilla(p);
    return p;
}

void CDibDiagramaDis::MoverGrupoSelecc()
{
	CPoint desp = CPoint(m_ptoFin.x - m_ptoIni.x, m_ptoFin.y - m_ptoIni.y);
	
	// funcionales
	MoverGrupoSelecc(&p_diag->m_listaConect,desp);
	MoverGrupoSelecc(&p_diag->m_listaBloq,desp);

	// Retroanotación:
	MoverGrupoSelecc(&p_diag->m_listaConectRetro,desp);
	MoverGrupoSelecc(&p_diag->m_listaBloqRetro,desp);

	p_diag->FlagModificado();
	p_diag->getVistas()->Actualizar();
}
 
void CDibDiagramaDis::MoverGrupoSelecc(ListaBloques* plista,const CPoint& desp)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);

		CDibBloqueDis* pDibBloque = blq->getVistas()->getDibBloqueDis();
		if (pDibBloque->EsSeleccionado()) pDibBloque->m_rect += desp;
	}
}

void CDibDiagramaDis::MoverGrupoSelecc(ListaConectores* plista,const CPoint& desp)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con);

		CDibConectDis* pdibCon = con->getVistas()->getDibConect()->getDis();
		pdibCon->MoverGrupoSelecc(desp);
	}
}

void CDibDiagramaDis::Seleccionar(BOOL selec /*= true*/, CRect * prsel /*= NULL*/, CDiagDisView* view /* = NULL */)  
{
    // "prt" viene dado en coordenadas cliente de la vista "view".
	
	// Bloques y conectores funcionales
	Seleccionar(&p_diag->m_listaConect,selec,prsel,view);
	Seleccionar(&p_diag->m_listaBloq,selec,prsel,view);

	// Bloques y conectores de Retroanotación:
	Seleccionar(&p_diag->m_listaConectRetro,selec,prsel,view);
	Seleccionar(&p_diag->m_listaBloqRetro,selec,prsel,view);
}

void CDibDiagramaDis::Seleccionar(ListaBloques* plista,BOOL selec, CRect * prsel, CDiagDisView* view)  
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);
	
		CDibBloqueDis* pDibBloque = blq->getVistas()->getDibBloqueDis();
		pDibBloque->Seleccionar(selec,prsel,view);
	}
}

void CDibDiagramaDis::Seleccionar(ListaConectores* plista,BOOL selec, CRect * prsel, CDiagDisView* view)  
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con);

		CDibConectDis* pDibCon = con->getVistas()->getDibConect()->getDis();
		pDibCon->Seleccionar(selec,prsel,view);
	}
}

void CDibDiagramaDis::EliminarSeleccion()  
{
	CDiagDis* pDiag = p_diag->getDis();

	// Bloques y conectores funcionales
	EliminarSeleccion(&p_diag->m_listaConect);
	EliminarSeleccion(&p_diag->m_listaBloq);

	// Bloques y conectores de Retroanotación:
	EliminarSeleccion(&p_diag->m_listaConectRetro);
	EliminarSeleccion(&p_diag->m_listaBloqRetro);
}

void CDibDiagramaDis::EliminarSeleccion(ListaBloques* plista)  
{
	CDiagDis* pDiag = p_diag->getDis();

	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);

		CDibBloqueDis* pDibBloque = blq->getVistas()->getDibBloqueDis();
		if (pDibBloque->EsSeleccionado())  pDiag->EliminarBloque(blq);
	}
}

void CDibDiagramaDis::EliminarSeleccion(ListaConectores* plista)  
{
	CDiagDis* pDiag = p_diag->getDis();

	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con);

		CDibConectDis* pDibCon = con->getVistas()->getDibConect()->getDis();
		if (pDibCon->EsSeleccionado())  
		{
			pDiag->EliminarConector(con);
			pDiag->getVistas()->Actualizar();
		}
	}
}


BOOL CDibDiagramaDis::ExisteComponenteSeleccionado()
{
	// Conectores funcionales
	if (ExisteComponenteSeleccionado(&p_diag->m_listaConect))
		return true;

	// Bloques funcionales
	if (ExisteComponenteSeleccionado(&p_diag->m_listaBloq))
		return true;

	// Conectores de Retroanotación:
	if (ExisteComponenteSeleccionado(&p_diag->m_listaConectRetro))
		return true;

	// Bloques de retroanotación
	if (ExisteComponenteSeleccionado(&p_diag->m_listaBloqRetro))
		return true;

	return false;  // Nada seleccionado
}

BOOL CDibDiagramaDis::ExisteComponenteSeleccionado(ListaBloques* plista)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);
		
		CDibBloqueDis* pDibBloque = blq->getVistas()->getDibBloqueDis();
		if (pDibBloque->EsSeleccionado())   return true;
	}

	return false;
}

BOOL CDibDiagramaDis::ExisteComponenteSeleccionado(ListaConectores* plista)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con);

		CDibConectDis* pDibCon = con->getVistas()->getDibConect()->getDis();
		if (pDibCon->EsSeleccionado()) return true;
	}

	return false;
}

BOOL CDibDiagramaDis::ExisteAlgoSeleccionado()
{
	// Si hay algún bloque o nudo seleccionado (algo seleccionado)
	// no es necesario que el conector esté selec. completo

	// Conectores funcionales
	if (ExisteAlgoSeleccionado(&p_diag->m_listaConect))
		return true;

	// Bloques funcionales
	if (ExisteAlgoSeleccionado(&p_diag->m_listaBloq))
		return true;

	// Conectores de Retroanotación:
	if (ExisteAlgoSeleccionado(&p_diag->m_listaConectRetro))
		return true;

	// Bloques de retroanotación
	if (ExisteAlgoSeleccionado(&p_diag->m_listaBloqRetro))
		return true;

	return false;  // Nada seleccionado
}

BOOL CDibDiagramaDis::ExisteAlgoSeleccionado(ListaBloques* plista)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);

		CDibBloqueDis* pDibBloque = blq->getVistas()->getDibBloqueDis();
		if (pDibBloque->EsSeleccionado())   return true;
	}

	return false;
}

BOOL CDibDiagramaDis::ExisteAlgoSeleccionado(ListaConectores* plista)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con);

		CDibConectDis* pDibCon = con->getVistas()->getDibConect()->getDis();
		if (pDibCon->EsSeleccionadoParcial()) return true;
	}

	return false;
}

void CDibDiagramaDis::Dibujar(CDC* pDC, CBaseView* view)
{
	m_rejilla.Dibujar(pDC,view);

	CDibDiagrama::Dibujar(pDC,view);
}

void CDibDiagramaDis::CopiarSeleccionAPortapapeles(CWnd* pview)
{
	CClipboard clipbrd(p_diag,pview);
	clipbrd.CopiarSeleccion();
}

void CDibDiagramaDis::PegarSeleccionDesdePortapapeles(CWnd* pview)
{
	CClipboard clipbrd(p_diag,pview);
	clipbrd.PegarSeleccion();
}


