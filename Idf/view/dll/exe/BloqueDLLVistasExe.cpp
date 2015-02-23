// BloqueDLLVistasExe.cpp: implementation of the CBloqueDLLVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\..\Idf.h"
#include "BloqueDLLVistasExe.h"

#include "..\BloqueDLLVistas.h"
#include "..\..\CambiaTxt.h"

#include "..\..\BloqueVistas.h"

#include "..\..\..\model\dll\BloqueDLL.h"
#include "..\..\..\model\dll\exe\BloqueDLLExe.h"

#include "..\..\..\model\DiagBase.h"
#include "..\..\..\model\Bloque.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueDLLVistasExe::CBloqueDLLVistasExe()
{

}

CBloqueDLLVistasExe::~CBloqueDLLVistasExe()
{

}

void CBloqueDLLVistasExe::PropUsuario()
{
	CBloqueDLLExe* pblq = getVistas()->getBloque()->getExe();

	pblq->getBloque()->getDiag()->FlagModificado();	

	if (NUEVO == pblq->m_estadoInterno)
	{
		pblq->CambiaEstado(INCOMPLETO);
	}     	

	BOOL res = (*pblq->pPropUsuario)(pblq->p_bloqueEnDLL);
	if (res) pblq->m_instante.Iniciar();  // Registra que la última modificación ha sido hecha en este intante.
}

BOOL CBloqueDLLVistasExe::nuevoNombreClaseEnDLL()
{
    CBloqueDLL* pbloque = getVistas()->getBloque();
	CDiagBase* pdiag = pbloque->getDiag();

	CCambiaTxt dlg;
    dlg.m_Titulo = "Introduce un nuevo nombre válido de clase de bloque";
	dlg.m_Texto = pbloque->m_claseDatosBloque;
	if (IDOK == dlg.DoModal())
	{
		pbloque->m_claseDatosBloque = dlg.m_Texto;
		pdiag->FlagModificado();
		return true;
	}

	return false;
}

