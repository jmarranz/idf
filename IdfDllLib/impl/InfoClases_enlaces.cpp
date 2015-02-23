
// InfoClases_enlaces.cpp

// Implementación de las funciones exportadas del DLL

#include "stdafx.h"
#include "IdfDllApp.h"

#include "InfoClases_enlaces.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Enlazadas con CDiag


POSITION    _PrimerBloquePos(int tipo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	CInfoDiagrama* pInfoDiag = CIdfDllApp::p_InfoDiagrama;
	switch(tipo)
	{
	case 0: 
		return pInfoDiag->ListaBloquesAmbos.GetStartPosition();
	case 1:
		return pInfoDiag->ListaBloquesFunc.GetStartPosition();
	case 2:
		return pInfoDiag->ListaBloquesRetro.GetStartPosition();
	}
	return NULL;
}

void    _SiguienteBloque(POSITION& pos,int tipo, const char*& clase,const char*& claseBase,const char*& verSerial)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	CInfoDiagrama* pInfoDiag = CIdfDllApp::p_InfoDiagrama;
	CInfoBloque* datosBloque = NULL;
	CString claveInutil;
	switch(tipo)
	{
	case 0: 
		pInfoDiag->ListaBloquesAmbos.GetNextAssoc(pos,claveInutil,(void*&)datosBloque);
		break;
	case 1:
		pInfoDiag->ListaBloquesFunc.GetNextAssoc(pos,claveInutil,(void*&)datosBloque);
		break;
	case 2:
		pInfoDiag->ListaBloquesRetro.GetNextAssoc(pos,claveInutil,(void*&)datosBloque);
		break;
	}
	clase = datosBloque->NombreClase;
	claseBase = datosBloque->NombreClaseBase;
	verSerial = datosBloque->VerSerial;
}

POSITION    _PrimerComPos()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	CInfoDiagrama* pInfoDiag = CIdfDllApp::p_InfoDiagrama;
	return pInfoDiag->ListaCom.GetStartPosition();
}


void    _SiguienteCom(POSITION& pos,const char*& clase,const char*& claseBase,const char*& verSerial)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	CInfoDiagrama* pInfoDiag = CIdfDllApp::p_InfoDiagrama;

	CInfoCom* datosCom = NULL;
	CString claveInutil;
	pInfoDiag->ListaCom.GetNextAssoc(pos,claveInutil,(void*&)datosCom);

	clase = datosCom->NombreClase;
	claseBase = datosCom->NombreClaseBase;
	verSerial = datosCom->VerSerial;
}

BOOL _BuscarComES(const char* clave,int tipo,const char*& clase,const char*& claseBloque)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	CInfoDiagrama* pInfoDiag = CIdfDllApp::p_InfoDiagrama;

	CInfoComES* datosComES = NULL;
	BOOL res = false;
	switch(tipo)
	{
	case 0: // Entrada
		res = pInfoDiag->ListaComEntrada.Lookup(clave,(void*&)datosComES);
		break;
	case 1: // Salida
		res = pInfoDiag->ListaComSalida.Lookup(clave,(void*&)datosComES);
		break;
	}	

	if (res)
	{
		clase = datosComES->NombreClase;
		claseBloque = datosComES->NombreClaseBloque;
		return true;
	}

	return false;
}


