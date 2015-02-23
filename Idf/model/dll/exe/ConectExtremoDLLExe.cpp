// ConectExtremoDLLExe.cpp: implementation of the CConectExtremoDLLExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\..\idf.h"
#include "ConectExtremoDLLExe.h"

#include "..\..\Conect.h"
#include "..\..\DiagBase.h"
#include "..\..\bdiag\BloqueDiag.h"

#include "..\BloqueDLL.h"

#include "..\..\ConectorException.h"

#include "..\..\..\view\exe\ConectVistasExe.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectExtremoDLLExe::CConectExtremoDLLExe()
{

}

CConectExtremoDLLExe::~CConectExtremoDLLExe()
{

}

CString CConectExtremoDLLExe::MensajeErrorTestConex(CConect* pcon,CBloqueDLL* pBloque,const CString& entra_sale)
{
	CString stemp;
	stemp = "ERROR TEST DE CONECTIVIDAD: La clase de objeto de comunicación \"";
	stemp += pcon->m_claseDatosComunic;
	stemp += "\" que circula por el conector ";
	stemp += " enlazando en ";
	stemp += entra_sale;
	stemp += " del bloque [";
	stemp += pBloque->getId();
	stemp += "] no está entre las clases de ";
	stemp += entra_sale;		
	stemp += " del bloque, definido en el módulo DLL: \r\n";
	stemp += pBloque->getDLLBloque();

	return stemp;
}

CString CConectExtremoDLLExe::MensajeErrorTestConex(CConect* pcon,const CString& DLLNombre)
{
	CString stemp;
	stemp = "ERROR TEST DE CONECTIVIDAD: La clase de objeto de comunicación \"";
	stemp += pcon->m_claseDatosComunic;
	stemp += "\" que circula por el conector [";
	stemp += pcon->getId();
	stemp += "] no está definido entre las clases de comunicación del módulo DLL: \r\n";
	stemp += DLLNombre;

	return stemp;
}



void CConectExtremoDLLExe::errorTestConexion(CConect* pcon,const CString& dllBloque)
{
	CString stemp = MensajeErrorTestConex(pcon,dllBloque);
	pcon->getVistas()->Mensaje(stemp);

	if (!pcon->getVistas()->getExe()->NuevaClaseComunic()) 
		throw new ConectorException(pcon,"Debe especificarse una clase de comunicación");
}
