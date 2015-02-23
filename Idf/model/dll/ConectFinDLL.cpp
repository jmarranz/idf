// ConectFinDLL.cpp: implementation of the CConectFinDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "ConectFinDLL.h"

#include "..\Conect.h"
#include "..\DiagBase.h"
#include "exe\ConectFinDLLExe.h"
#include "des\ConectFinDLLDis.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectFinDLL::CConectFinDLL()
{
	p_bloqueDLL = NULL;
}

CConectFinDLL::~CConectFinDLL()
{

}

void CConectFinDLL::Construir(CConect* con,CBloque* pblq)
{
	CConectFin::Construir(con,pblq);

	if (!getConect()->getDiag()->EsDiagDiseno())
		p_modo = new CConectFinDLLExe();
	else
		p_modo = new CConectFinDLLDis();

	p_modo->Construir(this);
}
