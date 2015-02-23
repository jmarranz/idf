// srvritem.cpp : implementation of the CDiagSrvrItem class
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagSrvrItem.h"

#include "..\..\model\exe\DiagExeDoc.h"
#include "..\..\model\exe\DiagExe.h"

#include "..\exe\DiagramaVistasExe.h"
#include "..\exe\DibDiagramaExe.h"


/////////////////////////////////////////////////////////////////////////////
// CDiagSrvrItem implementation

IMPLEMENT_DYNAMIC(CDiagSrvrItem, COleServerItem)

CDiagSrvrItem::CDiagSrvrItem(CDiagExeDoc* pContainerDoc)
	: COleServerItem(pContainerDoc, true)
{
	// TODO: add one-time construction code here
	//  (eg, adding additional clipboard formats to the item's data source)
}

CDiagSrvrItem::~CDiagSrvrItem()
{
	// TODO: add cleanup code here
}

void CDiagSrvrItem::Serialize(CArchive& ar)
{
	// CDiagSrvrItem::Serialize will be called by the framework if
	//  the item is copied to the clipboard.  This can happen automatically
	//  through the OLE callback OnGetClipboardData.  A good default for
	//  the embedded item is simply to delegate to the document's Serialize
	//  function.  If you support links, then you will want to serialize
	//  just a portion of the document.

//  if (!IsLinkedItem())    // Manejamos todos los tipos.
//	{
		CDiagExeDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->Serialize(ar);
//	}
}

BOOL CDiagSrvrItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// Es llamada indirectamente por la aplicación cliente OLE

	// Most applications, like this one, only handle drawing the content
	//  aspect of the item.  If you wish to support other aspects, such
	//  as DVASPECT_THUMBNAIL (by overriding OnDrawEx), then this
	//  implementation of OnGetExtent should be modified to handle the
	//  additional aspect(s).

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// CDiagSrvrItem::OnGetExtent is called to get the extent in
	//  HIMETRIC units of the entire item.  The default implementation
	//  here simply returns a hard-coded number of units.

	// determine extent based on screen dc
	rSize = CSize(0, 0);

	CClientDC dc(NULL);
	dc.SetMapMode(MM_LOMETRIC);
	CDiagExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	rSize = pDoc->getDiag()->getVistas()->getDiagSize();
	dc.LPtoHIMETRIC(&rSize); // convert pixels to HIMETRIC

	// rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC units

	return true;
}

BOOL CDiagSrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
	CDiagExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: set mapping mode and extent
	//  (The extent is usually the same as the size returned from OnGetExtent)
	rSize = pDoc->getDiag()->getVistas()->getDiagSize();
	pDC->SetMapMode(MM_ANISOTROPIC);   // MM_LOMETRIC da problemas, hacemos una pirula para OLE.
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(rSize);     // Creo que no hace nada con MM_LOMETRIC
	pDC->SetViewportExt(rSize);  // Note: only affects the m_hAttribDC . Creo que no hace nada con MM_LOMETRIC

	pDC->LPtoHIMETRIC(&rSize);   // convert pixels to HIMETRIC. 

	// TODO: add drawing code here.  Optionally, fill in the HIMETRIC extent.
	//  All drawing takes place in the metafile device context (pDC).

	// TODO: also draw embedded CDiagCntrItem objects.

	// OJO: no olvidar crear y seleccionar todos los recursor (pen, brush, font etc.) necesarios
	// para las funciones de dibujo, pues un Metafile no tienen ninguno seleccionado por defecto
	// de otra manera da lugar a resultados inesperados (no sigue dibujando bien).
	// No es necesario hacer SelectObject del recurso antiguo en metafiles.	
	pDoc->getDiag()->getVistas()->getDibDiagrama()->Dibujar(pDC, NULL); 

	return true;
}


BOOL CDiagSrvrItem::IsBlank()
{
	// Por defecto son blancos, dando un aviso al serializar.
    return false;  
}


/////////////////////////////////////////////////////////////////////////////
// CDiagSrvrItem diagnostics

#ifdef _DEBUG
void CDiagSrvrItem::AssertValid() const
{
	COleServerItem::AssertValid();
}

void CDiagSrvrItem::Dump(CDumpContext& dc) const
{
	COleServerItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////

