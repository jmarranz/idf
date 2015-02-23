// BloqueVistas.cpp: implementation of the CBloqueVistas class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "BloqueVistas.h"


#include "DibBloque.h"
#include "DiagramaVistas.h"
#include "BloqueVistasModo.h"

#include "exe\DlgBloqueExe.h"
#include "exe\DibBloqueExe.h"
#include "des\DibBloqueDis.h"
#include "des\DlgBloqueDis.h"


#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueVistas::CBloqueVistas()
{
	p_modo = NULL;
	p_dibBloque = NULL;
}

CBloqueVistas::~CBloqueVistas()
{
	delete p_modo;
	delete p_dibBloque;
}

void CBloqueVistas::Construir(CComponenteDiag* comp)
{
	CComponenteDiagVistas::Construir(comp);

	p_dibBloque = CrearObjDibBloque();
	p_dibBloque->Construir(this);
}

void CBloqueVistas::Destruir()
{
	for(POSITION pos = m_views.GetStartPosition() ; pos != NULL ; )
	{
		CDlgBloque* pdlg;
		CBaseView* view;
		m_views.GetNextAssoc(pos,(void*&)view,(void*&)pdlg); 
		pdlg->DestroyWindow();
		delete pdlg;
	}

	m_views.RemoveAll();

	CComponenteDiagVistas::Destruir();
}

void  CBloqueVistas::CrearNuevo()
{
	CObList* views = &getBloque()->getDiag()->getVistas()->m_views;

	for(POSITION pos = views->GetHeadPosition(); pos != NULL; )
	{
		CBaseView* view = (CBaseView*)views->GetNext(pos);
		addView(view);
	}
}

CDibBloque* CBloqueVistas::CrearObjDibBloque()
{
	if (!getBloque()->EsModoDiseno()) return new CDibBloqueExe();
	else return new CDibBloqueDis();
}


CDibBloque* CBloqueVistas::getDibBloque()
{
	return p_dibBloque;
}

void CBloqueVistas::LeerDatosLDD( DOMElement* vistas,DOMTreeWalker* walker )
{
	p_dibBloque->LeerDatosLDD(vistas,walker);
}

void CBloqueVistas::EscribirDatosLDD(DOMElement* vistas)
{
	p_dibBloque->EscribirDatosLDD(vistas);
}

void CBloqueVistas::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);  // Llamada conveniente al padre, aunque en la 1.0 no hace nada.

	p_dibBloque->Serialize(ar);
}

void  CBloqueVistas::addView(CBaseView* view)
{
	CDlgBloque* pDlg; 
	if (!getBloque()->getDiag()->EsDiagDiseno())
	{
		pDlg = new CDlgBloqueExe();	
	}
	else
    {
		pDlg = new CDlgBloqueDis();	    
    }

	pDlg->Crear(view,this);
    	
	m_views.SetAt(view, pDlg );
}

void  CBloqueVistas::removeView(CBaseView* view)
{
	CDlgBloque* pdlg;
	m_views.Lookup( view, (void*&) pdlg );

	pdlg->DestroyWindow();
	delete pdlg;			
    m_views.RemoveKey(view);
}


void CBloqueVistas::Actualizar()     // Sólo actualiza el de la vista que cambia.
{
	for(POSITION pos = m_views.GetStartPosition() ; pos != NULL ; )
	{
		CDlgBloque* pdlg;
		CBaseView* view;
		m_views.GetNextAssoc(pos,(void*&)view,(void*&)pdlg); 
		pdlg->Actualizar();
	}
}

void CBloqueVistas::Actualizar(CBaseView* view)     // Sólo actualiza el de la vista que cambia.
{
	CDlgBloque* pdlg;
	if (m_views.Lookup( view, (void*&) pdlg ))
	{
		pdlg->Actualizar();
	}
}

void CBloqueVistas::ActualizarExcepto(CBaseView* view)     // Sólo actualiza el de la vista que cambia.
{
	for(POSITION pos = m_views.GetStartPosition() ; pos != NULL ; )
	{
		CDlgBloque* pdlg;
		CBaseView* viewCurr;
		m_views.GetNextAssoc(pos,(void*&)viewCurr,(void*&)pdlg); 
		if (view != viewCurr) pdlg->Actualizar();
	}
}


void CBloqueVistas::PropUsuario()
{
	p_modo->PropUsuario();
}

void CBloqueVistas::Mensaje(const CString& msg)
{
	CString message = "Bloque [" + getBloque()->getId() + "]: "+ msg; 
	getBloque()->getDiag()->getVistas()->Mensaje(message);
}



