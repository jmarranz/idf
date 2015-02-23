// Idf.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Idf.h"

#include "view\MainFrame.h"
#include "view\DiagFrame.h"

#include "view\exe\DiagExeView.h"
#include "view\des\DiagDisView.h"
#include "view\exe\InPlaceFrame.h"
#include "model\exe\DiagExeDoc.h"
#include "model\des\DiagDisDoc.h"

#include "view\des\Clipboard.h"
#include "view\AboutDialog.h"


#include "xmlutil\XMLUtil.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



// Permite ser servidor OLE. El código como 
// servidor se ha tomado a partir del programa generado por el APPWIZARD.


// this is the GUID for OCLIENT documents
static const GUID BASED_CODE clsid = { 0x00021812, 0, 0, { 0xC0, 0, 0, 0, 0, 0, 0, 0x46 } };

/////////////////////////////////////////////////////////////////////////////
// CIdfApp construction

CIdfApp::CIdfApp(const char* pszAppName) : CWinApp(pszAppName)
{
}


BOOL CIdfApp::InitInstance()
{
	// Sólo se puede ejecutar una instancia del programa pues es difícil compartir el DLL
	
	CWinApp::InitInstance();

	// Initialize OLE 2.0 libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return false;
	}

	CGlobal::setDLLInfo(m_hInstance);
            
	XMLUtil::Iniciar();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	
	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Integrador de Diagramas de Flujo"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)
	
                 
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	// Definición del tipo diagrama funcional
	// Con OLE de OCLIENT (cliente) y servidor
	CMultiDocTemplate* pDocTemplateExe = new CMultiDocTemplate(IDR_PROYTYPE,
			RUNTIME_CLASS(CDiagExeDoc),
			RUNTIME_CLASS(CDiagFrame),
			RUNTIME_CLASS(CDiagExeView));			
			
	pDocTemplateExe->SetContainerInfo(IDR_PROYTYPE_CNTR_IP);
	pDocTemplateExe->SetServerInfo(
		IDR_PROYTYPE_SRVR_EMB, IDR_PROYTYPE_SRVR_IP,
		RUNTIME_CLASS(CInPlaceFrame));	
	AddDocTemplate(pDocTemplateExe);

	CGlobal::p_docTemplateExe = pDocTemplateExe;

	// Definición del tipo diseño del diagrama
	CMultiDocTemplate* pDocTemplateDis = new CMultiDocTemplate(IDR_PROY_DISENO,
			RUNTIME_CLASS(CDiagDisDoc),
			RUNTIME_CLASS(CDiagFrame),
			RUNTIME_CLASS(CDiagDisView));			
	AddDocTemplate(pDocTemplateDis);

	CGlobal::p_docTemplateDis = pDocTemplateDis;

	CClipboard::registrar();

	// create main MDI Frame window

	// Creación de la MainFrame	
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return false;
	m_pMainWnd = pMainFrame;

	m_pMainWnd->DragAcceptFiles();

	// enable file manager drag/drop and DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes();	
	

	// Connect the COleTemplateServer to the document template.
	//  The COleTemplateServer creates new documents on behalf
	//  of requesting OLE containers by using information
	//  specified in the document template.
	m_server.ConnectTemplate(clsid, pDocTemplateExe, false);

	// Register all OLE server factories as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleTemplateServer::RegisterAll();
		// Note: MDI applications register all server objects without regard
		//  to the /Embedding or /Automation on the command line.
	
	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Check to see if launched as OLE server
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Application was run with /Embedding or /Automation.  Don't show the
		//  main window in this case.
		return true;
	}

	// When a server application is launched stand-alone, it is a good idea
	//  to update the system registry in case it has been damaged.
	m_server.UpdateRegistry(OAT_INPLACE_SERVER);
	COleObjectFactory::UpdateRegistryAll();

	if (m_nCmdShow == SW_SHOWDEFAULT) // Cuando se lanza desde un .bat, si no corregimos no se muestra la ventana
		m_nCmdShow = SW_SHOWMAXIMIZED;

	m_nCmdShow = SW_SHOWMAXIMIZED; 


	// The main window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();	

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return false;

	return true;	
}


/////////////////////////////////////////////////////////////////////////////
// CIdfApp

BEGIN_MESSAGE_MAP(CIdfApp, CWinApp)
	//{{AFX_MSG_MAP(CIdfApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
	// Global help commands
	ON_COMMAND(ID_HELP_INDEX, CWinApp::OnHelpIndex)
	ON_COMMAND(ID_HELP_USING, CWinApp::OnHelpUsing)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CWinApp::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CWinApp::OnHelpIndex)
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// The one and only CIdfApp object

CIdfApp theApp("Idf"); 

/////////////////////////////////////////////////////////////////////////////

int CIdfApp::ExitInstance()
{
	// En alguna ocasión la salida del programa es bestia pero al menos pasa por aquí, liberamos los DLLs cargados.

	XMLUtil::Liberar();
	
	return CWinApp::ExitInstance();
}




// App command to run the dialog
void CIdfApp::OnAppAbout()
{
	CAboutDialog aboutDlg;
	aboutDlg.DoModal();
}


