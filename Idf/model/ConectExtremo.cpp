// ConectExtremo.cpp: implementation of the CConectExtremo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ConectExtremo.h"

#include "Bloque.h"
#include "Conect.h"
#include "DiagBase.h"

#include "ConectExtremoModo.h"

#include "ConectInicio.h"
#include "ConectFin.h"

#include "BloqueException.h"

#include "bdiag\BloqueDiag.h"

#include "..\xmlutil\XMLUtil.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectExtremo::CConectExtremo()
{
	p_bloque = NULL;

	p_conect = NULL;
	p_modo = NULL;
}

CConectExtremo::~CConectExtremo()
{
	delete p_modo;
}

void CConectExtremo::Construir(CConect* con,CBloque* pblq)
{
	p_conect = con;
	setBloque(pblq);
}

void CConectExtremo::Destruir()
{
}

CConectExtremo* CConectExtremo::crear(ExtremoConector extremo, const CString& idBloque, CConect* pcon)
{
	CBloque* pblq = buscarBloque(extremo,idBloque,pcon);
	if (pblq == NULL) return NULL;
	
	return crear(extremo,pblq,pcon);
}


CConectExtremo* CConectExtremo::crear(ExtremoConector extremo, CBloque* pblq, CConect* pcon)
{
	CConectExtremo* pext;

	if (extremo == CON_INICIO)
		pext = CConectInicio::crear(pblq,pcon);
	else
		pext = CConectFin::crear(pblq,pcon);

	if (pext == NULL) return NULL;

	pext->Construir(pcon,pblq);
	return pext;
}

CBloque* CConectExtremo::buscarBloque(ExtremoConector extremo, const CString& idBloque,CConect* pcon)
{
	CDiagBase* pdiag = pcon->getDiag();

	CBloque* pblq = pdiag->m_listaBloq.BuscaPorClave(idBloque);  // Buscamos en los funcionales
	if ((NULL == pblq) && pcon->EsRetroanotador())
		pblq = pdiag->m_listaBloqRetro.BuscaPorClave(idBloque);  // Buscamos en los de retroanotación

	return pblq;
}


CBloque* CConectExtremo::getBloque()
{
	return p_bloque;
}


CString CConectExtremo::getClaveBloque()
{
	return p_bloque->getId();
}

void CConectExtremo::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
	}
	else
	{
	}

	// p_modo->Serialize(ar); // Por ahora no serializa nada
}


CBloqueUnidad* CConectExtremo::getBloqueUnidad(CBloque* pbloque,OrdenBloqueDiag tipo)
{
	if (pbloque->EsBloqueDiag())
	{
		CBloqueDiag* pblqDiag = (CBloqueDiag*)pbloque;
		CBloque* pblqSub = pblqDiag->getBloque(tipo);
		if (pblqSub == NULL)
		{
			throw new BloqueException(pblqDiag,"No conectado a subdiagrama");
		}
		return getBloqueUnidad(pblqSub,tipo);
	}
	else  // Es BloqueUnidad
	{
		CBloqueUnidad* pblqUnidad = (CBloqueUnidad*)pbloque;
		return pblqUnidad;
	}
}


