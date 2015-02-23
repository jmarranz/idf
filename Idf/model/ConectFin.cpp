// ConectFin.cpp: implementation of the CConectFin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ConectFin.h"

#include "Conect.h"
#include "Bloque.h"
#include "ConectModo.h"
#include "DiagBase.h"

#include "BloqueUnidad.h"
#include "bdiag\BloqueDiag.h"

#include "dll\ConectFinDLL.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectFin::CConectFin()
{
}

CConectFin::~CConectFin()
{

}

CConectExtremo* CConectFin::crear(CBloque* pblq, CConect* pcon)
{
	CBloqueUnidad* pblqUnidad = getBloqueUnidad(pblq,FINDIAG);
	if (pblqUnidad->EsBloqueDLL())
	{
		CConectFinDLL* extCon = new CConectFinDLL;
		extCon->setBloqueDLL((CBloqueDLL*)pblqUnidad);
		return extCon;
	}

	return NULL;
}

void CConectFin::setBloque(CBloque* bloq)
{
	CConect* pcon = getConect();

	if (p_bloque != NULL) 
	{
		if (!pcon->EsRetroanotador())
			p_bloque->m_listaConectEntrada.RemoveKey( pcon->getId() ); // Por si ya estuviera insertado (asociación redundante)
		else
			p_bloque->m_listaConectEntradaRetro.RemoveKey( pcon->getId() ); // Por si ya estuviera insertado (asociación redundante)
	}

	p_bloque = bloq;

	if (p_bloque != NULL)
	{
		if (!pcon->EsRetroanotador())
			p_bloque->m_listaConectEntrada.SetAt(pcon->getId(),pcon);
		else
			p_bloque->m_listaConectEntradaRetro.SetAt(pcon->getId(),pcon);
	}

	// pcon->getModo()->ActualizaEstado();
}
