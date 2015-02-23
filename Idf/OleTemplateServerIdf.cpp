// OleTemplateServerIdf.cpp : implementation file
//

#include "stdafx.h"

#include "OleTemplateServerIdf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleTemplateServerIdf


COleTemplateServerIdf::COleTemplateServerIdf()
{
	Creando = false;
}

COleTemplateServerIdf::~COleTemplateServerIdf()
{
}


CCmdTarget* COleTemplateServerIdf::OnCreateObject()
{
	Creando = true;  // Ver en el .h las notas
	CCmdTarget* ptarget = COleTemplateServer::OnCreateObject();
	Creando = false;
	return ptarget;
}


BEGIN_MESSAGE_MAP(COleTemplateServerIdf, COleTemplateServer)
	//{{AFX_MSG_MAP(COleTemplateServerIdf)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleTemplateServerIdf message handlers
