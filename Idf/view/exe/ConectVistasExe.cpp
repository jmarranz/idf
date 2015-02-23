// ConectVistasExe.cpp: implementation of the CConectVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "ConectVistasExe.h"

#include "DibConectExe.h"

#include "..\CambiaTxt.h"

#include "..\..\model\Conect.h"
#include "..\..\model\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectVistasExe::CConectVistasExe()
{
}

CConectVistasExe::~CConectVistasExe()
{

}

CDibConect* CConectVistasExe::CrearObjDibConect()
{
	return new CDibConectExe();
}

BOOL CConectVistasExe::NuevaClaseComunic()
{
	CConect* pcon = getConect();

	CCambiaTxt dlg;
    dlg.m_Titulo = "Introduce un nuevo nombre válido de clase de objeto de comunicaciones:";
	dlg.m_Texto = pcon->m_claseDatosComunic;
	if (IDOK == dlg.DoModal())
	{
	    pcon->m_claseDatosComunic = dlg.m_Texto;   
		pcon->getDiag()->FlagModificado();
		return true;			
	}			

	return false;
}

