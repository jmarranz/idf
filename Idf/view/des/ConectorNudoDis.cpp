// ConectorNudoDis.cpp: implementation of the CConectorNudoDis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "ConectorNudoDis.h"

#include "DlgNudoCon.h"
#include "DiagDisView.h"

#include "..\DiagramaVistas.h"

#include "..\..\model\Conect.h"
#include "..\..\model\DiagBase.h"
#include "..\..\model\BaseDoc.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CConectorNudoDis,CConNudo,1)


CConectorNudoDis::CConectorNudoDis()
{

}

CConectorNudoDis::~CConectorNudoDis()
{

}

void CConectorNudoDis::CrearNuevo()
{
	CObList* views = &p_conect->getDiag()->getVistas()->m_views;

	for(POSITION pos = views->GetHeadPosition(); pos != NULL; )
	{
		CBaseView* view = (CBaseView*)views->GetNext(pos);
		addView(view);
	}
        
}

void CConectorNudoDis::Destruir()
{
	for(POSITION pos = m_views.GetStartPosition() ; pos != NULL ; )
	{
		CDlgNudoCon* pdlg;
		CBaseView* view;
		m_views.GetNextAssoc(pos,(void*&)view,(void*&)pdlg); 
		pdlg->DestroyWindow();
		delete pdlg;
	}

	m_views.RemoveAll();

	CConNudo::Destruir();
}


void CConectorNudoDis::Actualizar()   // Actualiza TODOS los nudos del conector de TODAS las vistas.
{
	for(POSITION pos = m_views.GetStartPosition() ; pos != NULL ; )
	{
		CDlgNudoCon* pdlg;
		CBaseView* view;
		m_views.GetNextAssoc(pos,(void*&)view,(void*&)pdlg); 
		pdlg->Actualizar();
	}
}

void CConectorNudoDis::Actualizar(CBaseView* view)   // Actualiza TODOS los nudos del conector de la vista dada.
{
	CDlgNudoCon* pdlg;
	if (m_views.Lookup( view, (void*&) pdlg ))
	{
		pdlg->Actualizar();
	}
}

void CConectorNudoDis::ActualizarExcepto(CBaseView* view) 
{
	for(POSITION pos = m_views.GetStartPosition() ; pos != NULL ; )
	{
		CDlgNudoCon* pdlg;
		CBaseView* viewCurr;
		m_views.GetNextAssoc(pos,(void*&)viewCurr,(void*&)pdlg); 
		if (view != viewCurr) pdlg->Actualizar();
	}
}


CDlgNudoCon* CConectorNudoDis::BuscaDialogoNudo(CBaseView* view)
{
	CDlgNudoCon* pdlg;
	if (m_views.Lookup( view, (void*&) pdlg ))
	{
		return pdlg;
	}

	return NULL;
}

void  CConectorNudoDis::addView(CBaseView* view)
{
	CDlgNudoCon* pDlg = new CDlgNudoCon();
	pDlg->Crear((CDiagDisView*)view, this);

	m_views.SetAt(view, pDlg );
}

void  CConectorNudoDis::removeView(CBaseView* view)
{
	CDlgNudoCon* pdlg;
	m_views.Lookup( view, (void*&) pdlg );

	pdlg->DestroyWindow();
	delete pdlg;
	
    m_views.RemoveKey(view);
}

