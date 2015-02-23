// WinSpawn.h: interface for the CWinSpawn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINSPAWN_H__AC164B2B_0A54_485D_A858_468D5638A2FD__INCLUDED_)
#define AFX_WINSPAWN_H__AC164B2B_0A54_485D_A858_468D5638A2FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBloque;

typedef struct  {
		HWND hWnd;  // Handle de la ventana principal
		PROCESS_INFORMATION ProcessInfo;
	} PROGRAMAINFO;


class CWinSpawn  
{
public:
	CWinSpawn();
	virtual ~CWinSpawn();

	static BOOL launch(LPCSTR lpszCmdLine, UINT fuCmdShow, BOOL MODO_DEBUG = false);

	static void getVentanaProceso(PROGRAMAINFO* pInfo);

	static BOOL CALLBACK EnumWndProc(HWND hWnd, LPARAM lParam);

	static BOOL IsAppRunning(PROGRAMAINFO* pInfo);
};

#endif // !defined(AFX_WINSPAWN_H__AC164B2B_0A54_485D_A858_468D5638A2FD__INCLUDED_)
