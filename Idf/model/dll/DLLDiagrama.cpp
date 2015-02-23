// CDLLDiagrama.cpp: implementation of the CDLLDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DLLDiagrama.h"

#include "..\DiagBase.h"
#include "..\..\Exception.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDLLDiagrama::CDLLDiagrama()
{
	m_hinstDLL = NULL;
	p_iniciarDLLDiagrama = NULL;
	p_liberarDLLDiagrama = NULL;
}


CDLLDiagrama::~CDLLDiagrama()
{
	Descargar();
}


void CDLLDiagrama::Cargar(const CString& path)
{
	m_path = path;

	m_hinstDLL = LoadLibrary(m_path);

	if (m_hinstDLL == NULL)
	{
		CString msg = MensajeErrorNoDLL(m_path);
		throw new Exception(msg);
	}

	char s[256];
	GetModuleFileName(m_hinstDLL, s, 255);  // El nombre exacto del módulo manejado interiormente
	m_path_interno = s;

	p_iniciarDLLDiagrama = (BOOL ( *)(HINSTANCE hInstance,HWND hwin)) GetProcAddress(m_hinstDLL, "IniciarDLLDiagrama");
	if (p_iniciarDLLDiagrama == NULL)
	{
		CString msg = MensajeErrorNoDLLDiag(m_path);
		throw new Exception(msg);	
	}	

	p_liberarDLLDiagrama = (void ( *)()) GetProcAddress(m_hinstDLL, "LiberarDLLDiagrama");
	if (p_liberarDLLDiagrama == NULL)
	{
		CString msg = MensajeErrorNoDLLDiag(m_path);
		throw new Exception(msg);
	}	

	CMDIFrameWnd* pmainfrm = (CMDIFrameWnd*)AfxGetMainWnd();

	HWND hwin = pmainfrm->m_hWnd;  

	BOOL res = (*p_iniciarDLLDiagrama)(CGlobal::m_DLLhinstance, hwin);
	if (!res) 
	{
		CString msg = "No se ha podido iniciar el módulo DLL: " + m_path;
		throw new Exception(msg);
	}
}


void CDLLDiagrama::Descargar()
{
	if (m_hinstDLL != NULL)
	{
		if (p_liberarDLLDiagrama != NULL)
		{
			(*p_liberarDLLDiagrama)();
			p_liberarDLLDiagrama = NULL;
		}

		FreeLibrary(m_hinstDLL);
		m_hinstDLL = NULL;
	}
}

BOOL CDLLDiagrama::Cargado()
{
	return (m_hinstDLL != NULL);
}

HINSTANCE CDLLDiagrama::getHandler()
{
	return m_hinstDLL;
}

CString CDLLDiagrama::MensajeErrorNoDLL(const CString& path)
{
	CString s = "El archivo DLL:\r\n" + path + "\r\n no existe o no es un DLL";
	return s;
}

CString CDLLDiagrama::MensajeErrorNoDLLDiag(const CString& path)
{
	CString s = "El archivo DLL:\r\n" + path + "\r\n no cumple el estándar de módulos de componentes de diagramas";
	return s;
}

