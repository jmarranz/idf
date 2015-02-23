// Idf.h : main header file for the IDF application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


#include "global.h"

 
#pragma warning( disable : 4290 ) 


/////////////////////////////////////////////////////////////////////////////
// CIdfApp:
// See idf.cpp for the implementation of this class
//
#include "OleTemplateServerIdf.h"


class CIdfApp : public CWinApp
{
public:

	CIdfApp(const char* pszAppName);   

// Overrides
	virtual BOOL InitInstance();
	virtual int  ExitInstance();

	BOOL CreandoObjetoBase() { return m_server.CreandoObjetoBase(); };

// Implementation
		
	//{{AFX_MSG(CIdfApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Implementation
protected:
	COleTemplateServerIdf m_server; 
	
	// Variables:	 
public:

};

 



