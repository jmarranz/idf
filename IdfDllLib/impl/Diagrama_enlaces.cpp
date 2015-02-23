
// DiagramaDllApi.cpp

// Implementaci�n de las funciones exportadas del DLL

#include "stdafx.h"
#include "IdfDllApp.h"

#include "Diagrama_enlaces.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/* No es probable que se utilicen, ver traceapi.h

BOOL   FilterDllMsg(LPMSG lpMsg)
{
	return AfxGetApp()->PreTranslateMessage(lpMsg);
}

void   ProcessDllIdle()
{
	// flush it all at once
	long lCount = 0;
	while (AfxGetApp()->OnIdle(lCount))
		lCount++;
}

*/


// Enlazadas con CDiag

BOOL     _IniciarDLLDiagrama(HINSTANCE hInstance, HWND hwin)
{
	// No confundir esta iniciaci�n con el Initinstance de CWinApp del DLL
	// De esta manera podemos iniciar el DLL pasando par�metros del DLL padre, cosa que
	// no podemos hacer en Initinstance. IDF.DLL tras lanzar este DLL deber� ejecutar
	// IniciarDLLDiagrama despu�s antes de hacer nada.
	// En la implementaci�n actual s�lo carga y enlaza din�micamente PROY.DLL para
	// comunicarse con �l bidireccionalmente.  

	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));
    
    CIdfDllApp* app = ObtpApp();

	return app->IniciarDLL(hInstance,hwin);
}


void    _LiberarDLLDiagrama()
{
	// No confundir esta iniciaci�n con el ExitInstance de CWinApp del DLL
    
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

    CIdfDllApp* app = ObtpApp();
	app->LiberarDLL();
}





