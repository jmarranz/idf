// IdfDllApp.cpp: implementation of the CIdfDllApp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IdfDllApp.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInfoDiagrama* CIdfDllApp::p_InfoDiagrama;


CInfoDiagrama* CIdfDllApp::getInfoDiagrama()
{
	if (p_InfoDiagrama == NULL)
		p_InfoDiagrama = new CInfoDiagrama();
	return p_InfoDiagrama;
}


CIdfDllApp::CIdfDllApp()
{
	ContIniciado = 0;
	DLLIdfCargado = false;
}

CIdfDllApp::~CIdfDllApp()
{
	if (p_InfoDiagrama != NULL) delete p_InfoDiagrama;
}


BOOL CIdfDllApp::IniciarDLL(HINSTANCE hInstance, HWND hwin) 
{
	if (ContIniciado) 
	{	
		ContIniciado++;  // Incrementamos el número de cargas
		return true;  // Ya iniciado
	}
	
	ContIniciado++; 

	TRACE("Diagrama en DLL cargándose\n");
	
	HwndProyWinMain = hwin;

	if (!CargayEnlazaDLLIdf(hInstance)) return false;
	
	return true;
}

void CIdfDllApp::LiberarDLL() 
{
	ContIniciado--;  // Decrementamos el número de cargas
	if (0 == ContIniciado)  // El DLL está siendo liberado
	{
		// Es preciso desconectar el objeto de la ventana principal de Idf.dll pues al destruirse el objeto destruiría la ventana antes de que lo hiciera Idf.dll dando un Assert.
		// Lo hacemos independientemente de si existe o no la ventana (caso de salida anormal), pues el Attach
		// son enlaces de rutinas etc (algo más que el handle).

//		ProyWinMain.Detach();
			
		// Asegura por si acaso una única liberación de PROY.DLL cuando se baja el DLL.
		if (DLLIdfCargado) // Si fue cargado y si todavía existe la ventana de DLL activo, pues la liberación de PROY.DLL si murió el programa anormalmente puede ser peligrosa.
		{
			//FreeLibrary(hinstDLLIdf);
			DLLIdfCargado = false;
		}
	}
}

BOOL CIdfDllApp::EnlazaDLLIdf()
{
	if (!EnlazaDLLIdfBloque()) return false;
	if (!EnlazaDLLIdfConector()) return false;

	return true;
}

BOOL CIdfDllApp::EnlazaDLLIdfBloque()
{
	// Enlazar aquí las funciones exportadas de PROY.DLL

	// Bloque

	pBloquegetEtiqueta = (const char * ( *)(void * pBloque)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_getEtiqueta");  
    if (pBloquegetEtiqueta == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}

	pBloquegetNombreInterno = (const char * ( *)(void * pBloque)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_getNombreInterno");  
    if (pBloquegetNombreInterno == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}

	pBloqueCambiaEstado = (void ( *)(void * pBloque, int estado))  GetProcAddress(m_hinstDLLIdf, "BloqueDLL_CambiaEstado");
    if (pBloqueCambiaEstado == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}	

	pBloquegetEstado = (int ( *)(void * bloque)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_getEstado");
    if (pBloquegetEstado == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}	    

	pBloqueEsNuevo = (BOOL ( *)(void * bloque)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_EsNuevo");
    if (pBloqueEsNuevo == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}	   

	pBloqueEsModoAuto = (BOOL ( *)(void * pBloque))  GetProcAddress(m_hinstDLLIdf, "BloqueDLL_EsModoAuto");
    if (pBloqueEsModoAuto == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}	

	pBloqueInicioModoAuto = (BOOL ( *)(void * pBloque))  GetProcAddress(m_hinstDLLIdf, "BloqueDLL_InicioModoAuto");
    if (pBloqueInicioModoAuto == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}	

	pBloqueExpMensaje = (void ( *)(void * pBloque, const char  * mensaje))  GetProcAddress(m_hinstDLLIdf, "BloqueDLL_ExpMensaje");
    if (pBloqueExpMensaje == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}

	pBloqueExpConfirm = (BOOL ( *)(void * pBloque, const char  * mensaje))  GetProcAddress(m_hinstDLLIdf, "BloqueDLL_ExpConfirm");
    if (pBloqueExpConfirm == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}

	pBloqueWinSpawn = (BOOL ( *)(void * pBloque, LPCSTR lpszCmdLine, UINT fuCmdShow)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_ExpWinSpawn");
    if (pBloqueWinSpawn == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}

	pBloqueConsola = (void ( *)(void * bloque, const char  * mensaje, int origen)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_Consola");
    if (pBloqueConsola == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}

	pBloqueRetroanotar = (BOOL ( *)(void * bloque, const char  * EtiqConector, BOOL EnviarCascadaRetro))  GetProcAddress(m_hinstDLLIdf, "BloqueDLL_Retroanotar");
	if (pBloqueRetroanotar == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}

	pBloqueRecibirRetroanotacion = (BOOL ( *)(void * bloque, const char  * EtiqConector)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_RecibirRetroanotacion"); 
	if (pBloqueRecibirRetroanotacion == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}
	
	pBloqueAyuda = (void ( *)(void  *bloque, const char *& texto)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_Ayuda");
    if (pBloqueAyuda == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}
	   
	pBloqueRedefAyuda = (void ( *)(void  *bloque, const char * ayuda)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_RedefAyuda");
    if (pBloqueRedefAyuda == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}  	

	pBloquegetMacro = (void ( *)(void  *bloque, const char *& macro)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_getMacro");
    if (pBloquegetMacro == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}
	   
	pBloqueRedefMacro = (void ( *)(void  *bloque, const char * macro)) GetProcAddress(m_hinstDLLIdf, "BloqueDLL_RedefMacro");
    if (pBloqueRedefMacro == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}  		
	
	return true;
}


BOOL CIdfDllApp::EnlazaDLLIdfConector()
{
	// Conector
	pConectorGetNombreInterno = (const char* ( *)(void* pCon)) GetProcAddress(m_hinstDLLIdf, "ConectorDLL_GetNombreInterno");
    if (pConectorGetNombreInterno == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}  		

	pConectorGetEtiqueta = (const char* ( *)(void* pCon)) GetProcAddress(m_hinstDLLIdf, "ConectorDLL_GetEtiqueta");
    if (pConectorGetEtiqueta == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}  

	pConectorEsRetroAnotador = (BOOL ( *)(void* pCon)) GetProcAddress(m_hinstDLLIdf, "ConectorDLL_EsRetroAnotador");
    if (pConectorEsRetroAnotador == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}  

	pConectorMensaje = (void (*)(void * pCon, const char  * mensaje)) GetProcAddress(m_hinstDLLIdf, "ConectorDLL_Mensaje");
    if (pConectorMensaje == NULL)
    {
		ErrorEnlaceDLL();
		return false;
	}  

	return true;
}


void CIdfDllApp::ErrorEnlaceDLL()
{
	CString s = "ERROR INESPERADO en el enlace dinámico del DLL principal:\n" + DLLIdf;
	AfxMessageBox( s );
}


BOOL CIdfDllApp::CargayEnlazaDLLIdf(HINSTANCE hInstance)
{

/*
 Es posible que DLLIdfCargado sea true.
 Esto es normal, no es error, por ejemplo cuando un nuevo documento ha sido cargado o varios bloques
se especificó el mismo DLL (incluyendo o no el DLL diagrama).
 Se ha demostrado que InitInstance y ExitInstance en un DLL sólo se ejecutan una sola vez
por lo que en ExitInstance no se liberaría cada carga de Idf.dll si lo cargáramos varias veces
, por eso obligamos a que sólo se cargue Idf.dll una vez pues es suficiente, el último que libere 
el DLL del bloque o diagrama es el que ejecuta ExitInstance y es el que liberará Idf.dll

  El DLL diagrama o bloque se cargará varias veces pero esto no tiene que ver con que Idf.dll se
cargue una sola vez.
*/

	if (DLLIdfCargado) return true;

	SetErrorMode(SEM_NOOPENFILEERRORBOX);
	m_hinstDLLIdf = hInstance;

	if (m_hinstDLLIdf != NULL)
	{
		DLLIdfCargado = true;
		if (!EnlazaDLLIdf()) // Enlaza dinámicamente las funciones de PROY.DLL
		{
	    	//FreeLibrary(hinstDLLIdf);
			return false;		
		}
	}
	else
	{
		CString s = "ERROR INESPERADO en la carga del DLL principal: %s, posiblemente ha sido movido o borrado de su posición de carga: \n" + DLLIdf;
		AfxMessageBox( s );
		// Posiblemente aquí se deba dar una solución al problema de la carga: pedir que se ponga el DLL accesible o cambio de nombre.  
		// Otra opción es no hacer nada devolver false y la función que llamó que decida qué hacer.
		// Es rarísimo de todas formas este error pues la carga del DLL y su paso del path de Idf es continuo,
		// quizás pueda darse el error ante varias cargas del mismo DLL.
		
		DLLIdfCargado = false;
		return false;  // Anomalía en la carga: es decir ha habido un error.
	}
	

	return true;
}




CIdfDllApp* ObtpApp()
{
	/* Ponemos AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
	porque se ha comprobado que si la DLL es linkada como MFC dinámica
	(utiliza las DLLs de las MFC) resulta que el objeto aplicación 
	de la DLL que devuelve AfxGetApp() no el local de la DLL sino el
	del ejecutable EjecProy. Se debe poner a la entrada de cualquier
	función exportada sin embargo existen objetos globales de 
	descripción de clases que se crean
	y acceden al objeto CIdfDllApp antes de llamarse a cualquier DLL
	de las mias */
 
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	return (CIdfDllApp*)AfxGetApp();
}


