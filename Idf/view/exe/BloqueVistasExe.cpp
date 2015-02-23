// BloqueVistasExe.cpp: implementation of the CBloqueVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "BloqueVistasExe.h"

#include "DlgOperacBloque.h"
#include "DlgOperacBRetro.h"
#include "DibDiagramaExe.h"

#include "..\BloqueVistas.h"
#include "..\exe\DiagramaVistasExe.h"


#include "..\..\model\exe\DiagExe.h"
#include "..\..\model\Bloque.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueVistasExe::CBloqueVistasExe()
{

}

CBloqueVistasExe::~CBloqueVistasExe()
{

}


void CBloqueVistasExe::DlgOperaciones()
{
	CBloque* pblq = getVistas()->getBloque();
	if (!pblq->EsRetroanotador())
	{
		COperacBloque Operac;
		Operac.setBloque(pblq->getExe());
		Operac.DoModal();
	}
	else
	{
		COperacBRetro Operac;
		Operac.setBloque(pblq->getExe());
		Operac.DoModal();
	}
}

void CBloqueVistasExe::CentrarBloque(CBaseView* view)
{
	CDibDiagramaExe* pdibdiag = getVistas()->getBloque()->getDiagExe()->getVistas()->getDibDiagrama();
	pdibdiag->CentrarBloque(getVistas()->getBloque(),view);
}

