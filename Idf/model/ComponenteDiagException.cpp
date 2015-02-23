// ComponenteDiagException.cpp: implementation of the ComponenteDiagException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "ComponenteDiagException.h"

#include "ComponenteDiag.h"
#include "DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponenteDiagException::ComponenteDiagException(CComponenteDiag* pcomp,const char* message)
: Exception(buildMessage(pcomp,message))
{
}

ComponenteDiagException::~ComponenteDiagException()
{

}

CString ComponenteDiagException::buildMessage(CComponenteDiag* pcomp, const char* message)
{
	CString msg;
	if (pcomp->getDiag()->m_nombreDiag != "")
	{
		msg = pcomp->getDiag()->m_nombreDiag + ": ";
	}
	
	CString tipo;
	if (pcomp->esBloque()) tipo = "Bloque";
	else if (pcomp->esConector()) tipo = "Conector";

	msg += tipo + " [" + pcomp->getId() + "]: " + message;
	return msg;
}

