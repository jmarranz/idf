// BloqueDiagVistasExe.cpp: implementation of the CBloqueDiagVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\..\Idf.h"
#include "BloqueDiagVistasExe.h"

#include "..\..\BloqueVistas.h"
#include "..\..\bdiag\BloqueDiagVistas.h"
#include "..\..\DiagramaVistas.h"


#include "..\..\DiagFrame.h"
#include "..\..\exe\DiagExeView.h"


#include "..\..\..\model\exe\DiagExe.h"
#include "..\..\..\model\exe\DiagExeDoc.h"
#include "..\..\..\model\bdiag\BloqueDiag.h"
#include "..\..\..\model\bdiag\exe\BloqueDiagExe.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueDiagVistasExe::CBloqueDiagVistasExe()
{

}

CBloqueDiagVistasExe::~CBloqueDiagVistasExe()
{

}

void CBloqueDiagVistasExe::PropUsuario()
{
  // En un bloque diagrama muestra las propiedades del diagrama hijo asociado al bloque.
	CBloqueDiag* pblq = getVistas()->getBloque();

	CDiagBase* pDiag = pblq->getSubdiagrama()->getDiag();
	pDiag->getVistas()->Propiedades();

	//crearView();
}

/*
void CBloqueDiagVistasExe::crearView()
{
	REVISAR

	CBloqueDiag* pblq = getVistas()->getBloque();
	CDiagBase* pdiag = pblq->getSubdiagrama()->getDiag();
	
	CRuntimeClass* prtc = RUNTIME_CLASS(CDiagFrame);
	CDiagFrame* vista = (CDiagFrame*)prtc->CreateObject();

	CCreateContext ctx;
	ctx.m_pNewViewClass = RUNTIME_CLASS(CDiagExeView);
	ctx.m_pCurrentDoc = pdiag->getDoc();
	ctx.m_pNewDocTemplate = pdiag->getDoc()->GetDocTemplate();
	ctx.m_pLastView = NULL;
	ctx.m_pCurrentFrame = (CMDIFrameWnd*)AfxGetMainWnd();

	
	vista->Create(NULL,"Prueba",WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CRect(0,0,500,500),(CMDIFrameWnd*)AfxGetMainWnd(),&ctx);
	vista->InitialUpdateFrame(pdiag->getDoc(),true);
}
*/

