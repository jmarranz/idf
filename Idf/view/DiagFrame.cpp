// FrameDiag.cpp : implementation file
//

#include "stdafx.h"
#include "..\Idf.h"
#include "DiagFrame.h"


/////////////////////////////////////////////////////////////////////////////
// CDiagFrame

IMPLEMENT_DYNCREATE(CDiagFrame, CMDIChildWnd)

CDiagFrame::CDiagFrame()
{
}

CDiagFrame::~CDiagFrame()
{
}

BOOL CDiagFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,		// TODO: adjust the number of rows, columns
		CSize(80, 100),	// TODO: adjust the minimum pane size
		pContext);
}

BEGIN_MESSAGE_MAP(CDiagFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CDiagFrame)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagFrame message handlers


void CDiagFrame::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CMDIChildWnd::OnClose();  // No sabemos si es la última ventana del documento.
}

