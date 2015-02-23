// maindoc.cpp : implementation of the CDiagExeDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and Microsoft
// QuickHelp and/or WinHelp documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Fichero original obtenido del ejemplo OCLIENT de Visual C++ 1.5

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagExeDoc.h"

#include "DiagExe.h"

#include "..\..\view\exe\DiagSrvrItem.h"
#include "..\..\view\exe\DiagExeView.h"
#include "..\..\view\DiagramaVistas.h"


// private clipboard format
CLIPFORMAT CDiagExeDoc::m_cfPrivate = NULL;

/////////////////////////////////////////////////////////////////////////////
// CDiagExeDoc

IMPLEMENT_DYNCREATE(CDiagExeDoc, CDiagExeBaseDoc)

BEGIN_MESSAGE_MAP(CDiagExeDoc, CDiagExeBaseDoc)
	//{{AFX_MSG_MAP(CDiagExeDoc)
	ON_COMMAND(ID_EDIT_COPIARDIAG, OnEditCopiardiag)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, OnEditLinks)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, OnUpdateObjectVerbMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CHANGE_ICON, OnUpdateEditChangeIcon)
	ON_COMMAND(ID_OLE_EDIT_CHANGE_ICON, OnEditChangeIcon)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagExeDoc construction/destruction

CDiagExeDoc::CDiagExeDoc()
{
	// For most containers, using compound files is a good idea.
	EnableCompoundFile();
	
	AfxOleLockApp();

	m_bNeedUpdate = true;
	if (m_cfPrivate == NULL)
		m_cfPrivate = (CLIPFORMAT)::RegisterClipboardFormat("Integrador de Diagramas de Flujo - Clipboard");
}


CDiagExeDoc::CDiagExeDoc(CDocTemplate* pTemplate) // : m_sizeDoc(800,1050) // document size is 8x10.5  Interfiere con el código de CDiagExeBaseDoc
{
	// For most containers, using compound files is a good idea.
	EnableCompoundFile();

	AfxOleLockApp();

	if (pTemplate) m_pDocTemplate = pTemplate; 

	m_bNeedUpdate = true;
	if (m_cfPrivate == NULL)
		m_cfPrivate = (CLIPFORMAT)::RegisterClipboardFormat("Integrador de Diagramas de Flujo - Clipboard");
}

CDiagExeDoc::~CDiagExeDoc()
{
	AfxOleUnlockApp();
}


/////////////////////////////////////////////////////////////////////////////
// CDiagExeDoc serialization

void CDiagExeDoc::Serialize(CArchive& ar)
{
	ar.m_pDocument = this;   // Se puede utilizar en otros puntos del programa. 
	
	// serialize the rest of the document (OLE items)
	CDiagExeBaseDoc::Serialize(ar);    // Llamar antes por el tema de cargar el número de versión lo primero de todo.

// NOTE: New easier to use serialization model -- even for OLE objects!
	WORD wMagic = 0x0DAF;
	if (ar.IsStoring())
	{
		/*  Hay elementos OLE servidor que yo no controlo que son blancos por defecto, por lo que pasar de ellos y no mostrar aviso ni posible error.
		if (HasBlankItems())
		{ 
			if (AfxMessageBox(IDP_SAVEINCOMPLETE, MB_YESNO|MB_ICONQUESTION) != IDYES)
			{
				TRACE("Aborting save -- incomplete items found!\n");
				AfxThrowArchiveException(CArchiveException::generic);
			}
		}
		*/
		ar << wMagic;
	}
	else
	{
		WORD w;
		ar >> w;

		if (w != wMagic)
		{
			TRACE("invalid magic number at start of file\n");
			AfxThrowArchiveException(CArchiveException::generic);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDiagExeDoc commands


/////////////////////////////////////////////////////////////////////////////
// CDiagExeDoc diagnostics

#ifdef _DEBUG
void CDiagExeDoc::AssertValid() const
{
	CDiagExeBaseDoc::AssertValid();
}

void CDiagExeDoc::Dump(CDumpContext& dc) const
{
	CDiagExeBaseDoc::Dump(dc);
}
#endif //_DEBUG


void CDiagExeDoc::OnEditCopiardiag()
{
	// TODO: Add your command handler code here
	ASSERT_VALID(this);

	CDiagSrvrItem* pItem = (CDiagSrvrItem*)OnGetEmbeddedItem();        

	pItem->CopyToClipboard(true);
	
	// delete pItem;
}



COleServerItem* CDiagExeDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CDiagSrvrItem* pItem = new CDiagSrvrItem((CDiagExeDoc*)this);
	ASSERT_VALID(pItem);
	return pItem;
}

 
