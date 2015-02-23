// DiagramaVistasDis.cpp: implementation of the CDiagramaVistasDis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagramaVistasDis.h"

#include "DibDiagramaDis.h"
#include "PropRejilla.h"
#include "TablaDis.h"

#include "..\..\model\des\DiagDis.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDiagramaVistasDis::CDiagramaVistasDis()
{
	p_dlgTabla = NULL;
	m_verDlgTablaDis = true;
}

CDiagramaVistasDis::~CDiagramaVistasDis()
{
	DestruirTablaDis(); 
}

CDibDiagrama* CDiagramaVistasDis::CrearObjDibDiagrama()
{
	return new CDibDiagramaDis();
}


void CDiagramaVistasDis::PropRejilla()
{
	CDibDiagramaDis* pDibDiag = getDibDiagrama();		

	CRejilla* pRejilla = &pDibDiag->m_rejilla;
	
	CPropRejilla Prop;

	Prop.m_ForzCoor = pRejilla->m_forzCoor;
	Prop.m_VerRejilla = pRejilla->m_verRejilla;

	Prop.m_IncX = pRejilla->m_incX;
	Prop.m_IncY = pRejilla->m_incY;
	
	if (IDOK == Prop.DoModal())  
    {
		pRejilla->m_forzCoor = Prop.m_ForzCoor;
		pRejilla->m_verRejilla = Prop.m_VerRejilla;
		pRejilla->m_incX = Prop.m_IncX;		
		pRejilla->m_incY = Prop.m_IncY;

		CDiagDis* pdiag = p_diag->getDis();
		pdiag->FlagModificado();
		pdiag->getVistas()->Actualizar();		
	}	 
}

void CDiagramaVistasDis::CrearTablaDis(CString& titulo)
{
	p_dlgTabla = new CTablaDis();	
    p_dlgTabla->Crear(p_diag->getDis(), titulo);
	m_verDlgTablaDis = true;
}

void CDiagramaVistasDis::DestruirTablaDis()
{
	if (p_dlgTabla) delete p_dlgTabla;
	p_dlgTabla = NULL;
	m_verDlgTablaDis = false;
}

void CDiagramaVistasDis::setNombreDiagrama( const char* nombre )
{
	if (p_dlgTabla) p_dlgTabla->setTitulo(nombre);    // Actualiza
}

void CDiagramaVistasDis::CambiaVerTablaDis()
{
	m_verDlgTablaDis = !m_verDlgTablaDis;	

	if (m_verDlgTablaDis)
	{
		DestruirTablaDis();  // Cortamos por lo sano.
		CrearTablaDis(p_diag->m_nombreDiag);
	}
	else
	{
		DestruirTablaDis();
    }
}


BOOL CDiagramaVistasDis::SincronizarEstadoTablaDis()
{
	CWnd* pwin = p_dlgTabla; 
	if (pwin) // No está destruido el objeto pero es posible que la ventana se haya cerrado
	{
		if (!EsValidaVentana(pwin))  m_verDlgTablaDis = false;
	}
	return m_verDlgTablaDis;
}

