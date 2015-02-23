// PropiedadesConector.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "PropiedadesConector.h"

#include "PropConect.h"
#include "PropConectInform.h"
#include "DibConect.h"
#include "ConectNudo.h"
#include "ConectVistas.h"
#include "DiagramaVistas.h"

#include "dll\DlgPropConectInicioDLL.h"
#include "dll\DlgPropConectFinDLL.h"


#include "..\model\Conect.h"
#include "..\model\ConectModo.h"
#include "..\model\ConectInicio.h"
#include "..\model\ConectFin.h"
#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"


#include "..\Exception.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropiedadesConector

IMPLEMENT_DYNAMIC(CPropiedadesConector, CPropertySheet)

CPropiedadesConector::CPropiedadesConector(CConect* pcon, UINT iSelectPage)
	:CPropertySheet("Propiedades del Conector: " + pcon->getEtiqueta(), NULL, iSelectPage)
{
	p_conect = pcon;
}

CPropiedadesConector::~CPropiedadesConector()
{
}


BEGIN_MESSAGE_MAP(CPropiedadesConector, CPropertySheet)
	//{{AFX_MSG_MAP(CPropiedadesConector)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropiedadesConector message handlers

int CPropiedadesConector::DoModal()
{
	CPropertyPage* propGen = PropGenerales(NULL);
	CPropertyPage* propInicio = PropInicio(NULL);
	CPropertyPage* propFin = PropFin(NULL);
	CPropertyPage* propInfo = PropInformacion(NULL);

	AddPage(propGen);  // Página 0
	if (propInicio != NULL) AddPage(propInicio);  // 1
	if (propFin != NULL)   AddPage(propFin);  // 2
	AddPage(propInfo);  // 3
	
	BOOL res = CPropertySheet::DoModal();
	if (IDOK == res)  
    {
		PropGenerales(propGen);
		PropInicio(propInicio);
		PropFin(propFin);
		PropInformacion(propInfo);

		CString men = "\n";
		if (!p_conect->PropiedadesCorrectas(men)) 
			p_conect->getVistas()->Mensaje(men);		
		
		p_conect->getModo()->ActualizaEstado();

		CDiagBase* pdiag = p_conect->getDiag();
		pdiag->FlagModificado();
		pdiag->getVistas()->Actualizar();
	}

	delete propGen;
	delete propInicio;
	delete propFin;
	delete propInfo;

	return res;
}

CPropertyPage* CPropiedadesConector::PropGenerales(CPropertyPage* pdlg)
{
	CDibConect* pdibcon = p_conect->getVistas()->getDibConect();

	if (pdlg == NULL)
	{	
		CPropConect* Prop = new CPropConect;
		Prop->setConect(p_conect);

		Prop->m_Etiq = p_conect->getEtiqueta();

		CConectExtremo* pconIni = p_conect->getInicio();
		CConectExtremo* pconFin = p_conect->getFin();

		if (pconIni != NULL) Prop->m_BlqIni = pconIni->getBloque()->getEtiqueta();  // Sólo lectura.
		if (pconFin != NULL) Prop->m_BlqFin = pconFin->getBloque()->getEtiqueta();  // Sólo lectura.
		Prop->m_ClaseCom = p_conect->m_claseDatosComunic;
		Prop->m_id = p_conect->getId();
		Prop->m_Visible = pdibcon->m_visible;
		Prop->m_AlturaFlecha = pdibcon->getpFlecha()->m_altFlecha;
		Prop->m_AnchoLin = pdibcon->m_ancho;

		return Prop;
	}
	else
    {
		CPropConect* Prop = (CPropConect*)pdlg;

		if ((p_conect->getEtiqueta() == "") && (Prop->m_Etiq != ""))
		{
			POSITION pos = pdibcon->m_listaNudos.GetHeadPosition();
			CConNudo* pnudo = (CConNudo*)pdibcon->m_listaNudos.GetNext(pos);
			pdibcon->m_ptoInsEtiq = pnudo->m_posNudo; 
		}
		
		p_conect->setEtiqueta(Prop->m_Etiq);
		p_conect->m_claseDatosComunic = Prop->m_ClaseCom;
		
		try
		{
			p_conect->setId( Prop->m_id );
		}
		catch(Exception* ex)
		{
			p_conect->getDiag()->getVistas()->Mensaje(ex);
			delete ex;
		}
		pdibcon->m_visible = Prop->m_Visible;
		pdibcon->getpFlecha()->m_altFlecha = Prop->m_AlturaFlecha;
		pdibcon->m_ancho = Prop->m_AnchoLin;
		
		return NULL;
	}
}

CPropertyPage* CPropiedadesConector::PropInformacion(CPropertyPage* pdlg)
{
	if (pdlg == NULL)
	{	
		CPropConectInform* Prop = new CPropConectInform; 
		Prop->m_Ayuda = p_conect->getAyuda();	

		return Prop;
	}
	else
    {
		CPropConectInform* Prop = (CPropConectInform*)pdlg;
		p_conect->setAyuda( Prop->m_Ayuda );
		
		return NULL;
	}
}


CPropertyPage* CPropiedadesConector::PropInicio(CPropertyPage* pdlg)
{
	if (p_conect->getInicio() == NULL) return NULL;

	if (pdlg == NULL)
	{	
		CDlgPropConectInicioDLL* Prop = new CDlgPropConectInicioDLL; 
		Prop->setExtremo(p_conect->getInicio());
		return Prop;
	}
	else
    {
		CDlgPropConectInicioDLL* Prop = (CDlgPropConectInicioDLL*)pdlg;
		
		return NULL;
	}
}

CPropertyPage* CPropiedadesConector::PropFin(CPropertyPage* pdlg)
{
	if (p_conect->getFin() == NULL) return NULL;

	if (pdlg == NULL)
	{	
		CDlgPropConectFinDLL* Prop = new CDlgPropConectFinDLL; 
		Prop->setExtremo(p_conect->getFin());
		return Prop;
	}
	else
    {
		CDlgPropConectFinDLL* Prop = (CDlgPropConectFinDLL*)pdlg;
		
		return NULL;
	}
}

