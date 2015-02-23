// DLLDiag.h : main header file for the DLLDIAG DLL
//

#if !defined(AFX_DLLDIAG_H__E8C2081B_FF6E_11D1_87DC_0000C057CDE3__INCLUDED_)
#define AFX_DLLDIAG_H__E8C2081B_FF6E_11D1_87DC_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// Propio, para depuración
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



/////////////////////////////////////////////////////////////////////////////
// CDLLDiagApp
// See DLLDiag.cpp for the implementation of this class
//


#include "..\IdfDllLib\impl\IdfDllApp.h"



class CDLLDiagApp : public CIdfDllApp
{
public:
	CDLLDiagApp();
	~CDLLDiagApp();

	DECLARAR_DIAGRAMA(CDLLDiagApp)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLLDiagApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDLLDiagApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLDIAG_H__E8C2081B_FF6E_11D1_87DC_0000C057CDE3__INCLUDED_)
