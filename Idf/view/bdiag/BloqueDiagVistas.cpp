// BloqueDiagVistas.cpp: implementation of the CBloqueDiagVistas class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "BloqueDiagVistas.h"

#include "PropiedadesBloqueDiag.h"

#include "..\BaseView.h"
#include "..\DiagramaVistas.h"


#include "exe\BloqueDiagVistasExe.h"
#include "des\BloqueDiagVistasDis.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\BaseDoc.h"
#include "..\..\model\BloqueModo.h"
#include "..\..\model\bdiag\BloqueDiag.h"

#include "..\..\xmlutil\XMLUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueDiagVistas::CBloqueDiagVistas()
{
	m_mostrarHijo = M_ACTIVAR;
}

CBloqueDiagVistas::~CBloqueDiagVistas()
{

}

void CBloqueDiagVistas::Construir(CComponenteDiag* comp)
{
	CBloqueVistas::Construir(comp);

	if (!comp->EsModoDiseno())
		p_modo = new CBloqueDiagVistasExe();
	else 
		p_modo = new CBloqueDiagVistasDis();

	p_modo->Construir(this);
}

BOOL CBloqueDiagVistas::Propiedades(UINT pagina /* = 0 */)
{
	CPropiedadesBloqueDiag dlgProp(getBloque(),pagina);

	BOOL res = (IDOK == dlgProp.DoModal());
	if (res) 
	{
		getBloque()->getModo()->ActualizaEstado();  
		Actualizar();	
	}
	return res;
}

void CBloqueDiagVistas::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	
		ar << m_mostrarHijo;
	}
	else
	{
		ar >> m_mostrarHijo;
	}

	CBloqueVistas::Serialize(ar);  
}

void CBloqueDiagVistas::LeerDatosLDD(DOMElement* vistas,DOMTreeWalker* walker)
{
	CBloqueVistas::LeerDatosLDD(vistas,walker);

	DOMElement* mostrarSubdiagrama = (DOMElement*)walker->nextSibling();
	m_mostrarHijo = XMLUtil::getEntero(mostrarSubdiagrama);
} 	


void CBloqueDiagVistas::EscribirDatosLDD(DOMElement* vistas)
{
    CBloqueVistas::EscribirDatosLDD( vistas );

	DOMElement* mostrarSubdiagrama = XMLUtil::appendElement(vistas,"mostrarSubdiagrama");
	XMLUtil::setEntero(mostrarSubdiagrama,m_mostrarHijo);
}


void CBloqueDiagVistas::setMostrarHijo(int mostrar)
{
	m_mostrarHijo = mostrar;
}

int CBloqueDiagVistas::getMostrarHijo()
{
	return m_mostrarHijo;
}

int CBloqueDiagVistas::listaMostrarHijo(int index,CString& texto)
{
	switch(index)
	{
		case 0: texto = S_NO_ACTIVAR; return M_NO_ACTIVAR;
		case 1: texto = S_MAXIMIZAR; return M_MAXIMIZAR;
		case 2: texto = S_ACTIVAR; return M_ACTIVAR;
		case 3: texto = S_MINIMIZAR; return M_MINIMIZAR;
	}

	return -1; // MAL 
}


int CBloqueDiagVistas::getEstado(CMDIChildWnd* frame)
{
	if (frame->IsIconic()) return SW_MINIMIZE; 
	else if (frame->IsZoomed()) return SW_MAXIMIZE;
	else return SW_RESTORE; 
}

CMDIChildWnd* CBloqueDiagVistas::getFrameSubDiagrama()
{
	CView *viewsubdiag = getViewSubDiagrama();
	return (CMDIChildWnd *) viewsubdiag->GetParentFrame( );
}

CBaseView* CBloqueDiagVistas::getViewSubDiagrama()
{
	CDiagramaVistas* pvistas = getBloque()->getBloqueFin()->getDiag()->getVistas();
	return (CBaseView*)pvistas->m_views.GetHead();
}

void CBloqueDiagVistas::ActivarFrameSubDiagrama(CMDIChildWnd* frame)
{
	int mostrarHijo = getMostrarHijo(); 
	switch(mostrarHijo)
	{
	case M_MAXIMIZAR: 
	case M_ACTIVAR: frame->ActivateFrame( mostrarHijo ); break;
	case M_MINIMIZAR: 
	case M_NO_ACTIVAR: frame->ShowWindow( mostrarHijo ); 
	}
}

