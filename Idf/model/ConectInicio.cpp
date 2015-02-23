// ConectInicio.cpp: implementation of the CConectInicio class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ConectInicio.h"

#include "Conect.h"
#include "Bloque.h"
#include "ConectModo.h"
#include "DiagBase.h"

#include "BloqueUnidad.h"
#include "bdiag\BloqueDiag.h"

#include "dll\ConectInicioDLL.h"

#include "..\xmlutil\XMLUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectInicio::CConectInicio()
{
}

CConectInicio::~CConectInicio()
{

}

CConectExtremo* CConectInicio::crear(CBloque* pblq, CConect* pcon)
{
	CBloqueUnidad* pblqUnidad = getBloqueUnidad(pblq,FINDIAG);
	if (pblqUnidad->EsBloqueDLL())
	{
		CConectInicioDLL* extCon = new CConectInicioDLL;
		extCon->setBloqueDLL((CBloqueDLL*)pblqUnidad);
		return extCon;
	}

	return NULL;
}


void CConectInicio::setBloque(CBloque* bloq)
{
	// Eliminamos la referencia del anterior bloque asociado
	CConect* pcon = getConect();

	if (p_bloque != NULL) 
	{
		if (!pcon->EsRetroanotador())
			p_bloque->m_listaConectSalida.RemoveKey(pcon->getId());
		else
			p_bloque->m_listaConectSalidaRetro.RemoveKey(pcon->getId());
	}	
	
	p_bloque = bloq;

	if (p_bloque != NULL)
	{
		if (!pcon->EsRetroanotador())
			p_bloque->m_listaConectSalida.SetAt(pcon->getId(),pcon);
		else
			p_bloque->m_listaConectSalidaRetro.SetAt(pcon->getId(),pcon);
	}
}


