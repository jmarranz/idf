// ConectVistas.cpp: implementation of the CConectVistas class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "ConectVistas.h"

#include "DibConect.h"

#include "PropiedadesConector.h"
#include "DiagramaVistas.h"


#include "..\model\Conect.h"
#include "..\model\ConectModo.h"
#include "..\model\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectVistas::CConectVistas()
{
	p_dibCon = NULL;
}

CConectVistas::~CConectVistas()
{
	delete p_dibCon;
}

void CConectVistas::Destruir()
{
	CObList* views = &getConect()->getDiag()->getVistas()->m_views;

	for(POSITION pos = views->GetHeadPosition() ; pos != NULL ; )
	{
		CBaseView* view = (CBaseView*)views->GetNext(pos);
		removeView(view);
	}

	p_dibCon->Destruir();

	CComponenteDiagVistas::Destruir();
}


void  CConectVistas::CrearNuevo()
{
	CObList* views = &getConect()->getDiag()->getVistas()->m_views;

	for(POSITION pos = views->GetHeadPosition(); pos != NULL; )
	{
		CBaseView* view = (CBaseView*)views->GetNext(pos);
		addView(view);
	}
}

void CConectVistas::Construir(CComponenteDiag* comp)
{
	CComponenteDiagVistas::Construir(comp);

	p_dibCon = CrearObjDibConect();
	p_dibCon->Construir( this ); 
}


CDibConect* CConectVistas::getDibConect()
{
	return p_dibCon;
}

void CConectVistas::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	p_dibCon->Serialize(ar);
}

void CConectVistas::LeerDatosLDD(DOMElement* vistas,DOMTreeWalker* walker)
{
	p_dibCon->LeerDatosLDD(vistas);
}

void CConectVistas::EscribirDatosLDD(DOMElement* vistas)
{
	p_dibCon->EscribirDatosLDD(vistas);
}


BOOL CConectVistas::Propiedades()
{
	CPropiedadesConector dlgProp(getConect(),0);

	if (IDOK == dlgProp.DoModal())
	{
		getConect()->getModo()->ActualizaEstado();  
		Actualizar();	
		CDiagBase* pdiag = getConect()->getDiag();

		pdiag->FlagModificado();  // Ha habido cambio de estado, redibujamos	(de nuevo)
		pdiag->getVistas()->Actualizar();
		return true;
	}

	return false;
}

void CConectVistas::Actualizar()
{
	p_dibCon->Actualizar();
}

void CConectVistas::Actualizar(CBaseView* view)
{
	p_dibCon->Actualizar(view);
}

void CConectVistas::ActualizarExcepto(CBaseView* view)
{
	p_dibCon->ActualizarExcepto(view);
}


void CConectVistas::Mensaje(const CString& msg)
{
	CString message = "Conector ["+ getConect()->getId()+"]: "+ msg; 
	getConect()->getDiag()->getVistas()->Mensaje(message);
}


void  CConectVistas::addView(CBaseView* view)
{
	p_dibCon->addView(view);
}

void  CConectVistas::removeView(CBaseView* view)
{
	p_dibCon->removeView(view);
}

