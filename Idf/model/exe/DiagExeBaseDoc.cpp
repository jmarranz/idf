// proydoc.cpp : implementation of the CDiagExeBaseDoc class
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagExeBaseDoc.h"

#include "DiagExe.h"
#include "..\bdiag\BloqueDiag.h"
#include "..\bdiag\exe\BloqueDiagExe.h"

#include "..\..\view\MainFrame.h"
#include "..\..\view\exe\DiagSrvrItem.h"

#include "..\..\Exception.h"


/////////////////////////////////////////////////////////////////////////////
// CDiagExeBaseDoc

IMPLEMENT_DYNCREATE(CDiagExeBaseDoc, CBaseDoc)

BEGIN_MESSAGE_MAP(CDiagExeBaseDoc, CBaseDoc)
	//{{AFX_MSG_MAP(CDiagExeBaseDoc)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, CBaseDoc::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, CBaseDoc::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, CBaseDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, CBaseDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, CBaseDoc::OnUpdateObjectVerbMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, CBaseDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, CBaseDoc::OnEditConvert)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagExeBaseDoc construction/destruction

CDiagExeBaseDoc::CDiagExeBaseDoc()
{
	// TODO: add one-time construction code here
}

CDiagExeBaseDoc::~CDiagExeBaseDoc()
{
}


/////////////////////////////////////////////////////////////////////////////
// CDiagExeBaseDoc serialization

void CDiagExeBaseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		CBaseDoc::Serialize(ar);

		p_diag->Serialize(ar);
	}
	else
	{
		// TODO: add loading code here

		try
		{
			CBaseDoc::Serialize(ar);

			p_diag = CrearObjDiag();
			p_diag->Serialize(ar);  // Aquí dentro también se producen aserciones
		}		
		catch(Exception* ex)
		{		
			DestruirDiag();  // Idem que se hace en DeleteContents pero es necesario hacerlo aquí explícitamente, pues no se llama en fallo de carga.
            throw ex;  // Llama a la del sistema que se encargará de cerrar el fichero.
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CDiagExeBaseDoc diagnostics

#ifdef _DEBUG
void CDiagExeBaseDoc::AssertValid() const
{
	CBaseDoc::AssertValid();
}

void CDiagExeBaseDoc::Dump(CDumpContext& dc) const
{
	CBaseDoc::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiagExeBaseDoc commands

CDiagBase* CDiagExeBaseDoc::CrearObjDiag()
{
	// En el futuro se podría crear dinámicamente el tipo de clase diagrama con CreateObject, de ahi el utilizar un puntero y hacer new.
    CDiagBase* pdiag = new CDiagExe();
	pdiag->Construir(this);
	return pdiag;
}


 


