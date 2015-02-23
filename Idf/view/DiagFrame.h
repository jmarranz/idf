// DiagFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDiagFrame frame with splitter

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif



class CDiagFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CDiagFrame)
protected:
	CDiagFrame();			// protected constructor used by dynamic creation

// Attributes
protected:
	CSplitterWnd	m_wndSplitter;
public:

// Operations
public:

// Implementation
public:
	virtual ~CDiagFrame();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

	// Generated message map functions
	//{{AFX_MSG(CDiagFrame)
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
