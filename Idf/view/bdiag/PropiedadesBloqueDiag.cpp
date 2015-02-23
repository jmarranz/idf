// PropiedadesBloqueDiag.cpp: implementation of the CPropiedadesBloqueDiag class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "PropiedadesBloqueDiag.h"

#include "BloqueDiagVistas.h"

#include "PropBlqDiag.h"

#include "..\..\model\bdiag\BloqueDiag.h"
#include "..\..\model\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPropiedadesBloqueDiag::CPropiedadesBloqueDiag(CBloque* pblq,UINT pagina) 
		: CPropiedadesBloque(pblq,pagina)
{

}

CPropiedadesBloqueDiag::~CPropiedadesBloqueDiag()
{

}



CPropertyPage* CPropiedadesBloqueDiag::PropEspecificas(CPropertyPage* pdlg) throw (BloqueException)
{
	CBloqueDiag* pblq = (CBloqueDiag*)p_bloque;

	if (NULL == pdlg)
	{
		CPropBlqDiag* Prop = new CPropBlqDiag;

		Prop->setBloque(pblq);

   		Prop->m_EtiqDiagHijo = pblq->getEtiqDiagHijo();

		Prop->m_esLDD = pblq->m_esLDD;
		Prop->m_FichHijo = pblq->m_fichDiag; 

		Prop->p_bloqueIni = pblq->getBloque(INICIODIAG);  
		Prop->p_bloqueFin = pblq->getBloque(FINDIAG); 
		
		Instante tins = pblq->getTiempo();
		Prop->m_Fecha = tins.ConvertirAString();      // Sólo lectura.

		return Prop;
	}
	else
    {
		CPropBlqDiag* Prop = (CPropBlqDiag*)pdlg;

		pblq->m_esLDD = Prop->m_esLDD;		
		pblq->m_fichDiag = Prop->m_FichHijo; 
		
		pblq->setBloque(INICIODIAG,Prop->p_bloqueIni);  
		pblq->setBloque(FINDIAG,Prop->p_bloqueFin); 

		pblq->getVistas()->setMostrarHijo(Prop->m_mostrarSubDiag);

		return NULL;
	}
}

