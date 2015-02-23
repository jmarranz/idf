// ConectInicioDLL.cpp: implementation of the CConectInicioDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "ConectInicioDLL.h"

#include "..\Conect.h"
#include "..\DiagBase.h"
#include "exe\ConectInicioDLLExe.h"
#include "des\ConectInicioDLLDis.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectInicioDLL::CConectInicioDLL()
{
	p_bloqueDLL = NULL;
}

CConectInicioDLL::~CConectInicioDLL()
{

}

void CConectInicioDLL::Construir(CConect* con,CBloque* pblq)
{
	CConectInicio::Construir(con,pblq);

	if (!getConect()->getDiag()->EsDiagDiseno())
		p_modo = new CConectInicioDLLExe();
	else
		p_modo = new CConectInicioDLLDis();

	p_modo->Construir(this);
}

