// IdfDllApp.h: interface for the CIdfDllApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IDFDLLAPP_H__88E308CE_7827_4A8A_ABFD_936693AF9AC6__INCLUDED_)
#define AFX_IDFDLLAPP_H__88E308CE_7827_4A8A_ABFD_936693AF9AC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Declaración más resumida y a la vieja usanza (como era en 16 bits)

#define  _export  __declspec(dllexport)

#include "InfoClases.h"

#include "Bloque_enlaces.h"
#include "Com_enlaces.h"
#include "Diagrama_enlaces.h"
#include "InfoClases_enlaces.h"
#include "InfoDiagrama.h"

#include "Com.h"
#include "NULO.h"
#include "ComSerial.h"

#include "bloque.h"
#include "bloqfunc.h"
#include "bloqretro.h"

#include "olevar.h"
#include "oleautom.h"


class CIdfDllApp : public CWinApp  
{
public:
	CIdfDllApp();
	virtual ~CIdfDllApp();

	static CInfoDiagrama* getInfoDiagrama();

public:
	
	virtual	BOOL IniciarDLL(HINSTANCE hInstance, HWND hwin);
	virtual void LiberarDLL();

	virtual BOOL CargayEnlazaDLLIdf(HINSTANCE hInstance);
	virtual BOOL EnlazaDLLIdf();
	virtual BOOL EnlazaDLLIdfBloque();
	virtual BOOL EnlazaDLLIdfConector();


	virtual void ErrorEnlaceDLL();
	

	// Punteros de acceso a la API exportada de PROY.DLL:
	
	// Sobre el Bloque
	const char * ( *pBloquegetEtiqueta)(void * pBloque);
	const char * ( *pBloquegetNombreInterno)(void  * pBloque);
	void ( *pBloqueCambiaEstado)(void * pBloque, int estado);
	int  ( *pBloquegetEstado)(void * bloque);
	BOOL ( *pBloqueEsNuevo)(void * bloque);
	BOOL ( *pBloqueEsModoAuto)(void * pBloque);
	BOOL ( *pBloqueInicioModoAuto)(void * pBloque);
	void ( *pBloqueExpMensaje)(void * pBloque, const char  * mensaje);
	BOOL ( *pBloqueExpConfirm)(void * pBloque, const char  * mensaje);
    BOOL ( *pBloqueWinSpawn)(void * pBloque, LPCSTR lpszCmdLine, UINT fuCmdShow);
	void ( *pBloqueConsola)(void * bloque, const char  * mensaje, int origen);
	BOOL ( *pBloqueRetroanotar)(void * bloque, const char  * EtiqConector, BOOL EnviarCascadaRetro);
	BOOL ( *pBloqueRecibirRetroanotacion)(void * bloque, const char  * EtiqConector);
	
	void ( *pBloqueAyuda)(void  *bloque, const char *& texto);	
	void ( *pBloqueRedefAyuda)(void  *bloque, const char * ayuda);
	void ( *pBloquegetMacro)(void  *bloque, const char *& macro);	
	void ( *pBloqueRedefMacro)(void  *bloque, const char * macro);

	// Sobre el conector

//	time_t (*pGetInstante)(CCom  * pCom);
	const char* (*pConectorGetNombreInterno)(void* pCon);
	const char* (*pConectorGetEtiqueta)(void* pCon);
	BOOL (*pConectorEsRetroAnotador)(void* pCon);
	void (*pConectorMensaje)(void * pCon, const char  * mensaje);

protected:
	int ContIniciado;  // Indica si ha sido inicializado ya por Idf y cuantas veces.
	CString DLLIdf;
	HINSTANCE m_hinstDLLIdf;
	BOOL DLLIdfCargado;

public:
	static CInfoDiagrama* p_InfoDiagrama;

	HWND HwndProyWinMain;  // Se conectará a la ventana principal de Idf.dll para que los diálogos de usuario puedan tener ventana padre y evitar la reentrada al diagrama.

};


CIdfDllApp* ObtpApp();  // Para ahorrarnos algo de escritura de código.



/* Notas sobre CWinApp::InitInstance() y ExitInstance()
   por si se utilizaran.

  InitInstance()
  	 Sólo se ejecuta una sola vez si es el mismo ejecutable el que
	 hace LoadLibrary, pero si es un ejecutable diferente (ej. BajaDLL)
	 se llama como si no fuera cargado nunca.

  ExitInstance()
     Sólo se ejecuta una sola vez al bajarse el DLL si es el mismo ejecutable el que
	 hace FreeLibrary, pero si es un ejecutable diferente (ej. BajaDLL)
	 se llama como si se fuera a bajar el DLL, por lo que 
	 hay que detectar cuando de verdad se está bajando.
*/


#endif // !defined(AFX_IDFDLLAPP_H__88E308CE_7827_4A8A_ABFD_936693AF9AC6__INCLUDED_)
