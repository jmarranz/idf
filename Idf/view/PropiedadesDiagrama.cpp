// PropiedadesDiagrama.cpp: implementation of the CPropiedadesDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "PropiedadesDiagrama.h"

#include "DlgPropDiagrama.h"
#include "DlgPropDiagComponentes.h"
#include "DlgPropDiagInform.h"

#include "PropMultiDiag.h"

#include "DiagramaVistas.h"


#include "..\model\DiagBase.h"
#include "..\model\BaseDoc.h"
#include "..\model\bdiag\BloqueDiag.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CPropiedadesDiagrama, CPropertySheet)

CPropiedadesDiagrama::CPropiedadesDiagrama(CDiagBase* pdiag)
	:CPropertySheet("Propiedades del Diagrama: " + pdiag->m_etiqueta, NULL, 0)
{
	p_diag = pdiag;
}

CPropiedadesDiagrama::~CPropiedadesDiagrama()
{

}

int CPropiedadesDiagrama::DoModal()
{
	CPropertyPage* propDiag = PropDiagrama(NULL);
	CPropertyPage* propComponentes = PropComponentes(NULL);
	CPropertyPage* propInformacion = PropInformacion(NULL);
	CPropertyPage* pPropmulti = PropMultiDiag(NULL);

	AddPage(propDiag);
	AddPage(propComponentes);
	AddPage(propInformacion);
	if (pPropmulti) AddPage(pPropmulti);

	BOOL res = CPropertySheet::DoModal();
	if (IDOK == res)  
    {
		PropDiagrama(propDiag);
		PropComponentes(propComponentes);
		PropInformacion(propInformacion);
		if (pPropmulti) PropMultiDiag(pPropmulti);

    	// ActualizarVistas();
		CString men = "\n";
		if (!p_diag->PropiedadesCorrectas(men)) 
			p_diag->getVistas()->Mensaje(men);
		
		p_diag->FlagModificado();		
		p_diag->getVistas()->Actualizar();		
	}	 
	
	delete propDiag;
	delete propComponentes;
	delete propInformacion;
	if (pPropmulti) delete pPropmulti;

	return res;
}

CPropertyPage* CPropiedadesDiagrama::PropDiagrama(CPropertyPage* pdlg)
{
	if (NULL == pdlg)
	{
		CDlgPropDiagrama* Prop = new CDlgPropDiagrama;
		Prop->Construir(p_diag);

		Prop->m_PosHorizontal = p_diag->getVistas()->EsPosHorizontal();

		Prop->m_Etiq = p_diag->m_etiqueta;   
		
		Prop->m_DLLDiag = p_diag->getDLLDiag();

		CBaseDoc* pDoc = p_diag->getDoc();

		CString path = pDoc->GetPathName();
		if ("" == path ) Prop->m_FichBin = pDoc->GetTitle(); 
		else  Prop->m_FichBin = path;
    
		Prop->m_FichLDD = p_diag->m_nombreLDD;

		Prop->m_Fecha = p_diag->CadenaTiempo();    // Sólo lectura.

		Prop->m_DirLibrerias = p_diag->m_dirTrabajo;

		return Prop;
	}
	else
	{
		CDlgPropDiagrama* Prop = (CDlgPropDiagrama*)pdlg;
	
		if (Prop->m_PosHorizontal) p_diag->getVistas()->PonerHorizontal();
		else  p_diag->getVistas()->PonerVertical();

		p_diag->m_etiqueta = Prop->m_Etiq;   
		p_diag->setDLLDiag(Prop->m_DLLDiag);
    	p_diag->m_nombreLDD = Prop->m_FichLDD;
		p_diag->SetDirTrabajo(Prop->m_DirLibrerias,false);  // Si está mal no intenta que el usuario lo ponga bien

		return NULL;
	}
}

CPropertyPage* CPropiedadesDiagrama::PropComponentes(CPropertyPage* pdlg)
{
	if (NULL == pdlg)
	{
		CDlgPropDiagComponentes* Prop = new CDlgPropDiagComponentes;
		Prop->Construir(p_diag);

		return Prop;
	}
	else
	{
		CDlgPropDiagComponentes* Prop = (CDlgPropDiagComponentes*)pdlg;

		return NULL;
	}
}

CPropertyPage* CPropiedadesDiagrama::PropInformacion(CPropertyPage* pdlg)
{
	if (NULL == pdlg)
	{
		CDlgPropDiagInform* Prop = new CDlgPropDiagInform;

		Prop->m_Ayuda = p_diag->getAyuda();

		return Prop;
	}
	else
	{
		CDlgPropDiagInform* Prop = (CDlgPropDiagInform*)pdlg;

		p_diag->setAyuda( Prop->m_Ayuda );

		return NULL;
	}
}


CPropertyPage* CPropiedadesDiagrama::PropMultiDiag(CPropertyPage* pdlg)
{
	if (!p_diag->EsMultiDiag()) return NULL;

	CBloqueDiag* pBloqPadre = p_diag->getBloqPadre();

	if (NULL == pdlg)
	{
		CPropMultiDiag* Prop = new CPropMultiDiag;

		Prop->setDiag(p_diag, pBloqPadre);

		Prop->m_EtiqDiagPadre = pBloqPadre->getDiag()->m_etiqueta;  // Sólo lectura.
		Prop->m_BlqDiagPadre = pBloqPadre->getEtiqueta();

		CBloque* pblqIni = p_diag->getMDiagBloqIni();
		if (pblqIni != NULL)
			Prop->m_BlqIni = pblqIni->getId();  // Sólo lectura

		CBloque* pblqFin = p_diag->getMDiagBloqFin();
		if(pblqFin != NULL)
			Prop->m_BlqFin = pblqFin->getId();  // Sólo lectura

		return Prop;
	}
	else
    {
		// Este diálogo no produce cambios por sí mismo.
		CPropMultiDiag* Prop = (CPropMultiDiag*)pdlg;
		
		return NULL;
	}

}
