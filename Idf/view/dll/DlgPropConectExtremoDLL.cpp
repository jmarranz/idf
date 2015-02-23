// DlgPropConectExtremoDLL.cpp: implementation of the CDlgPropConectExtremoDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "DlgPropConectExtremoDLL.h"

#include "DlgGeneracionCodigoSinDLL.h"
#include "DlgGeneracionCodigoConDLL.h"

#include "..\DiagramaVistas.h"

#include "..\..\model\Conect.h"
#include "..\..\model\ConectExtremo.h"
#include "..\..\model\DiagBase.h"
#include "..\..\model\dll\AnalisisClasesConDLL.h"

#include "..\..\Exception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CDlgPropConectExtremoDLL,CPropertyPage)


CDlgPropConectExtremoDLL::CDlgPropConectExtremoDLL(UINT nIDTemplate)
	: CPropertyPage(nIDTemplate)
{
	p_extremo = NULL;
}

CDlgPropConectExtremoDLL::~CDlgPropConectExtremoDLL()
{

}

void CDlgPropConectExtremoDLL::setExtremo(CConectExtremo* extremo)
{
	p_extremo = extremo;
}


void CDlgPropConectExtremoDLL::killFocusClaseCom()
{
	CString stemp = getClaseCom(); // Antes del cambio
	UpdateData(true);  // Carga de los cambios.    
	if (getClaseCom() != stemp)  // Se ha cambiado el valor.
	{
		p_extremo->getConect()->getDiag()->AvisoCambioCarga();			
	}
}

void CDlgPropConectExtremoDLL::listarClases()
{
	CWaitCursor cursor_espera;

	UpdateData(true); // Por si acaso es necesario para m_CtrlClaseCom

	CConect* pcon = p_extremo->getConect();

	CString DLLListaCom; // Temporal
	if (!pcon->getDiag()->getVistas()->getNuevoNombreDLL(DLLListaCom)) return;
	
	CAnalisisClasesConDLL Analizador(pcon->getDiag(),DLLListaCom);
	try
	{
		Analizador.Construir();
	}
	catch(Exception* ex)
	{
		pcon->getDiag()->getVistas()->Mensaje(ex);
		delete ex;
		return;
	}

	getListaClaseCom()->ResetContent();
	Analizador.ListarObjCom(getListaClaseCom());

	UpdateData(false);	
}

void CDlgPropConectExtremoDLL::generacionCodigo()
{
	UpdateData(true); // Para actualizar m_ClaseCom 

	CConect* pcon = p_extremo->getConect();

	CDlgGeneracionCodigoSinDLL dlg(pcon->getDiag());

	try
	{
		dlg.AnalizarObjCom(getClaseCom());
		dlg.DoModal();
	}
	catch(Exception* ex)
	{
		pcon->getDiag()->getVistas()->Mensaje(ex);
		delete ex;
		return;
	}
}

void CDlgPropConectExtremoDLL::inspeccionCodigo()
{
	UpdateData(true); // Para actualizar m_ClaseCom 

	CConect* pcon = p_extremo->getConect();

	CString DLLDiag; // Temporal
	if (!pcon->getDiag()->getVistas()->getNuevoNombreDLL(DLLDiag)) return;
	
	CDlgGeneracionCodigoConDLL dlg(pcon->getDiag(),DLLDiag);
	try
	{
		dlg.AnalizarObjCom(getClaseCom());
		dlg.DoModal();
	}
	catch(Exception* ex)
	{
		pcon->getDiag()->getVistas()->Mensaje(ex);
		delete ex;
		return;
	}
}

