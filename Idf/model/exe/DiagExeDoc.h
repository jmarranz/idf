// maindoc.h : interface of the CDiagExeDoc class
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

#ifndef CDIAGEXEDOC
#define CDIAGEXEDOC

#include "DiagExeBaseDoc.h"


class CDiagExeDoc : public CDiagExeBaseDoc
{
protected: // create from serialization only

	DECLARE_DYNCREATE(CDiagExeDoc)

// Attributes
public:
    CDiagExeDoc();
	CDiagExeDoc(CDocTemplate* pTemplate);  // pTemplate es para pruebas de crearlo explícitamente	
	static CLIPFORMAT m_cfPrivate;
	// CSize m_sizeDoc;  Interfiere con el código de CDiagExeBaseDoc
	// CSize& GetDocumentSize();
	BOOL m_bNeedUpdate;

	virtual COleServerItem* OnGetEmbeddedItem(); // Para servidor OLE,

// Operations
public:

	CDiagSrvrItem* GetEmbeddedItem()
		{ return (CDiagSrvrItem*)COleServerDoc::GetEmbeddedItem(); }

// Implementation
public:
	virtual ~CDiagExeDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CDiagExeDoc)
	afx_msg void OnEditCopiardiag();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif

/////////////////////////////////////////////////////////////////////////////
