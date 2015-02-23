// WinSpawn.cpp: implementation of the CWinSpawn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "WinSpawn.h"

#include "..\Bloque.h"
#include "..\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWinSpawn::CWinSpawn()
{

}

CWinSpawn::~CWinSpawn()
{

}

BOOL CWinSpawn::launch(LPCSTR lpszCmdLine, UINT fuCmdShow,BOOL MODO_DEBUG)

// lpszCmdLine : camino al ejecutable .	
// fuCmdShow :	 window state of new app. Ej. SW_SHOW	
{
	STARTUPINFO Stupinfo;
	PROCESS_INFORMATION ProcessInfo;

	GetStartupInfo( &Stupinfo );  // Valores por defecto del propio proceso padre.
	
	Stupinfo.dwFlags = STARTF_USESHOWWINDOW;  // Para que casi todos los parámetros sean por defecto.
	Stupinfo.wShowWindow =  SW_SHOW;
	BOOL res = CreateProcess(NULL , (char*)lpszCmdLine, NULL, NULL, false, CREATE_DEFAULT_ERROR_MODE | CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS , 
		NULL, NULL, &Stupinfo, &ProcessInfo );

	if (!res)
 	{
 		CString s = "ERROR WinSpawn: No se ha creado el proceso correctamente";
		CGlobal::Mensaje(s);
 		return false;
	}

	WaitForInputIdle( ProcessInfo.hProcess, INFINITE);  // Esperar a que se inicialice del todo

	if (MODO_DEBUG)
	{
		CString szMsg = "Proceso hijo lanzado, esperando finalización.\r\n Comando:\r\n" + CString(lpszCmdLine);
		CGlobal::Mensaje(szMsg);
	}
 
	PROGRAMAINFO ProgInfo;
	ProgInfo.ProcessInfo = ProcessInfo;

	getVentanaProceso(&ProgInfo);  // getemos la 
	
	while ( IsAppRunning(&ProgInfo) )
	{
	    MSG msg;

	    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))  // Procesa mensajes y conmuta a otras aplicaciones. Ejemplo tomado de Windows SDK.
		{
	        TranslateMessage(&msg); /* translates virtual key codes    */
    	    DispatchMessage(&msg);  /* dispatches message to window    */
	   	}			
	}

   	if (MODO_DEBUG)
   	{
   		CString szMsg = "Proceso hijo ha TERMINADO, salida del proceso de espera";
 		CGlobal::Mensaje(szMsg);
	}

	return true;
} 

// Funciones asociadas a WinSpawn


void CWinSpawn::getVentanaProceso(PROGRAMAINFO* pInfo)
{ 
	pInfo->hWnd = NULL;
 
     EnumWindows(&EnumWndProc, (LPARAM)pInfo);

	 // El resultado es pInfo con hWnd inicializado
} 


// The enumeration procedure, which tests for a window with the correct instance, is shown here:
// Tomada de documentación técnica de Microsoft modificada.

BOOL CALLBACK CWinSpawn::EnumWndProc(HWND hWnd, LPARAM lParam)
{
    PROGRAMAINFO* lpInfo;

    lpInfo = (PROGRAMAINFO*) lParam;

	DWORD dwProcessId; 
	DWORD dwThreadId = GetWindowThreadProcessId(hWnd,&dwProcessId);
	
	if ( (dwThreadId == lpInfo->ProcessInfo.dwThreadId) &&
		 (dwProcessId == lpInfo->ProcessInfo.dwProcessId)   )
	{
		lpInfo->hWnd = hWnd;

		return false;  // Encontrada, parar de iterar.
    }

    return true;
}


// Tomada de documentación técnica de Microsoft modificada.
	
BOOL CWinSpawn::IsAppRunning(PROGRAMAINFO* pInfo)   
{
	
	DWORD dwProcessId; 
	DWORD dwThreadId = GetWindowThreadProcessId(pInfo->hWnd,&dwProcessId);
	
	if ( (dwThreadId != pInfo->ProcessInfo.dwThreadId) ||
		 (dwProcessId != pInfo->ProcessInfo.dwProcessId)   )
	{
		return false;  // Proceso finalizado.
    }	

    return true;
}	

