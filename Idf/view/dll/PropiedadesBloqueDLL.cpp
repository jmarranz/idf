// PropiedadesBloqueDLL.cpp: implementation of the CPropiedadesBloqueDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "PropiedadesBloqueDLL.h"

#include "PropBlqDLL.h"
#include "..\DiagramaVistas.h"

#include "..\..\model\dll\BloqueDLL.h"
#include "..\..\model\DiagBase.h"
#include "..\..\model\BloqueException.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPropiedadesBloqueDLL::CPropiedadesBloqueDLL(CBloque* pblq,UINT pagina) 
		: CPropiedadesBloque(pblq,pagina)
{

}

CPropiedadesBloqueDLL::~CPropiedadesBloqueDLL()
{

}

CPropertyPage* CPropiedadesBloqueDLL::PropEspecificas(CPropertyPage* pdlg)	throw (BloqueException)
{
	CBloqueDLL* pblq = (CBloqueDLL*)p_bloque;
	
	if (NULL == pdlg)
	{
		CPropBlqDLL* Prop = new CPropBlqDLL;
		
		Prop->setBloque(pblq);

		Prop->m_UsaDLLDiag = pblq->getUsaDLLDiag();
		Prop->m_DLLBloque = pblq->getDLLBloque();
		Prop->m_ClaseBloque = pblq->m_claseDatosBloque;	

		Instante tins = pblq->getTiempo();
   		Prop->m_Fecha = tins.ConvertirAString();    // Sólo lectura.

		Prop->m_Macro = pblq->getMacro();

		return Prop;
	}
	else
    {
		CPropBlqDLL* Prop = (CPropBlqDLL*)pdlg;

		pblq->setEstadoInt( MODIFICADO );

		try
		{
		if (Prop->m_UsaDLLDiag)
			pblq->setDLLBloque("");
		else 
			pblq->setDLLBloque(Prop->m_DLLBloque);
		}
		catch(Exception* ex)
		{
			pblq->getDiag()->getVistas()->Mensaje(ex);
			delete ex;
		}

		pblq->m_claseDatosBloque = Prop->m_ClaseBloque;
		pblq->setMacro( Prop->m_Macro );

		return NULL;
	}
}
