// CPropiedadesBloque.cpp: implementation of the CPropiedadesBloque class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "PropiedadesBloque.h"

#include "PropBloque.h"
#include "PropBloqueInform.h"
#include "DlgPropBloqueConectores.h"
#include "DibBloque.h"
#include "BloqueVistas.h"
#include "DiagramaVistas.h"


#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"

#include "..\Exception.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPropiedadesBloque::CPropiedadesBloque(CBloque* pBlq,UINT pagina)
	: CPropertySheet("Propiedades del Bloque: " + pBlq->getEtiqueta(),NULL,pagina)
{
	p_bloque = pBlq;
}

CPropiedadesBloque::~CPropiedadesBloque()
{
}

int CPropiedadesBloque::DoModal() 
{
	CPropertyPage* propgen = PropGenerales(NULL);
	CPropertyPage* propesp = PropEspecificas(NULL);
	CPropertyPage* propliscon = PropListaConectores(NULL);
	CPropertyPage* propinfo = PropInformacion(NULL);
	
	AddPage(propgen);  // Página 0
	AddPage(propesp);  // 1
	AddPage(propliscon);  // 2
	AddPage(propinfo);   // 3

	BOOL res = CPropertySheet::DoModal();
	if (IDOK == res)  
    {
		PropGenerales(propgen); 
		PropEspecificas(propesp); 
		PropListaConectores(propliscon);
		PropInformacion(propinfo); 

		// ActualizaTodosDialogos();  // Para que los cambios se hagan presentes visualmente.
		CString men = "\n";
		if (!p_bloque->PropiedadesCorrectas(men)) 
			p_bloque->getVistas()->Mensaje(men);

		p_bloque->getDiag()->FlagModificado();	
		p_bloque->getVistas()->Actualizar();
	}

	delete propgen;
	delete propesp;
	delete propliscon;
	delete propinfo;

	return res; 
}

CPropertyPage* CPropiedadesBloque::PropGenerales(CPropertyPage* pdlg)
{
	CDibBloque* pdibBloque = p_bloque->getVistas()->getDibBloque();

	if (pdlg == NULL)
	{	
		CPropBloque* Propgen = new CPropBloque;

		Propgen->setBloque(p_bloque);

		Propgen->m_Etiq = p_bloque->getEtiqueta();

		Propgen->m_Orden = p_bloque->getOrden();  // Yo creo que no sirve para nada

		Propgen->m_id = p_bloque->getId();
		
		Propgen->m_AE = p_bloque->getAE();
		Propgen->m_AS = p_bloque->getAS();
		Propgen->m_estadoUsuario = p_bloque->getEstadoUsr();

		Propgen->m_EstadoInterno = p_bloque->EstadoIntAstring();	

		Propgen->m_SalidaAuto = p_bloque->m_salidaAuto;
		Propgen->m_AutoContMax = p_bloque->m_autoContMax;

		Propgen->m_TipoDibujo = pdibBloque->getTipoDibujoStr();

		Propgen->m_Visible = pdibBloque->m_visible;
		Propgen->m_AnchoLin = pdibBloque->m_anchoLin;

		return Propgen;
	}
	else
    {
		CPropBloque* Propgen = (CPropBloque*)pdlg;

		CDiagBase* pdiag = p_bloque->getDiag();

		p_bloque->setEtiqueta(Propgen->m_Etiq);
	
		try
		{
			p_bloque->setId( Propgen->m_id );
		}
		catch(Exception* ex)
		{
			pdiag->getVistas()->Mensaje(ex);
			delete ex;
		}

		p_bloque->setAE(Propgen->m_AE);
		p_bloque->setAS(Propgen->m_AS);

		p_bloque->CambiaEstado(Propgen->m_estadoUsuario); // Por si se ha cambiado el estado manualmente.	
		// No tocamos el estado interno al ser sólo lectura.

    	p_bloque->m_salidaAuto = Propgen->m_SalidaAuto;
		p_bloque->m_autoContMax = Propgen->m_AutoContMax;	
        
        pdibBloque->setTipoDibujo(Propgen->m_TipoDibujo);

		pdibBloque->m_visible = Propgen->m_Visible;
        pdibBloque->m_anchoLin = Propgen->m_AnchoLin;
		
		return NULL;
	}
}

CPropertyPage* CPropiedadesBloque::PropListaConectores(CPropertyPage* pdlg)
{
	if (pdlg == NULL)
	{	
		CDlgPropBloqueConectores* prop = new CDlgPropBloqueConectores;
		prop->Construir(p_bloque);

		return prop;
	}
	else
    {
		CDlgPropBloqueConectores* prop = (CDlgPropBloqueConectores*)pdlg;

		return NULL;
	}
}

CPropertyPage* CPropiedadesBloque::PropInformacion(CPropertyPage* pdlg)
{
	if (pdlg == NULL)
	{	
		CPropBloqueInform* Prop = new CPropBloqueInform;
		Prop->m_ayuda = p_bloque->getAyuda();

		return Prop;
	}
	else
    {
		CPropBloqueInform* Prop = (CPropBloqueInform*)pdlg;

		p_bloque->setAyuda( Prop->m_ayuda );
		
		return NULL;
	}
}


