
// enlaces.cpp


#include "stdafx.h"
#include "..\..\..\Idf.h"
#include "BloqueDLL_enlaces.h"

#include "..\..\exe\DiagExe.h"

#include "..\BloqueDLL.h"
#include "..\exe\BloqueDLLExe.h"

#include "..\WinSpawn.h"

#include "..\..\..\view\DiagramaVistas.h"
#include "..\..\..\view\dll\BloqueDLLVistas.h"
                     

// EXPORTACIONES HACIA LOS DLL DE DIAGRAMAS Y BLOQUES PARA COMUNICACIÓN BIDIRECCIONAL

// Se ha quitado el  para que se especifique obligatoriamente en ENLACES.H la
// cabecera (esa sí con ), pues con el  se podría olvidar la cabecera y no se
// avisa y de verdad no se exportaría sin el "extern" de la cabecera.

// Hacia Bloque

const char *  BloqueDLL_getEtiqueta(CBloqueDLL* bloque)
{
	return	bloque->getEtiqueta();
}


const char *  BloqueDLL_getNombreInterno(CBloqueDLL* bloque)  
{
	return bloque->getId();
}

	
void    BloqueDLL_CambiaEstado(CBloqueDLL* bloque, int estado)
{
    bloque->CambiaEstado((TipoEstadoUsuario)estado);
}


int     BloqueDLL_getEstado(CBloqueDLL* bloque)
{
    return bloque->getEstadoUsr();	
}

BOOL    BloqueDLL_EsNuevo(CBloqueDLL* bloque)
{
	return bloque->EsNuevo();
}

BOOL    BloqueDLL_EsModoAuto(CBloqueDLL* bloque)
{
	CDiagExe* pdiag = bloque->getDiagExe();
	return pdiag->m_modoAuto;
}

BOOL   BloqueDLL_InicioModoAuto(CBloqueDLL* bloque)
{
	return bloque->getExe()->m_inicioAuto;
}


void    BloqueDLL_ExpMensaje(CBloqueDLL* bloque, const char* mensaje)
{
	bloque->getVistas()->Mensaje((CString)mensaje);	
}


BOOL    BloqueDLL_ExpConfirm(CBloqueDLL* bloque, const char  * mensaje)
{
	if (bloque)
	{
		CDiagBase* pDiag = bloque->getDiag();	
		return pDiag->getVistas()->Confirm((CString)mensaje);
	}
	else return CGlobal::Confirm((CString)mensaje);
}


BOOL    BloqueDLL_ExpWinSpawn(CBloqueDLL* bloque, LPCSTR lpszCmdLine, UINT fuCmdShow)
{
	return CWinSpawn::launch(lpszCmdLine,fuCmdShow,true);
}


void    BloqueDLL_Consola(CBloqueDLL* bloque, const char* mensaje, int origen)
{
	CString StrMensaje = mensaje;
	bloque->getExe()->Consola(StrMensaje, origen);
}


BOOL    BloqueDLL_Retroanotar(CBloqueDLL* bloque, const char* EtiqConector, BOOL EnviarCascadaRetro)
{
	return bloque->getExe()->Retroanotar((CString)EtiqConector, EnviarCascadaRetro);
}

BOOL    BloqueDLL_RecibirRetroanotacion(CBloqueDLL* bloque, const char* EtiqConector)
{
	return bloque->getExe()->RecibirRetroanotacion((CString)EtiqConector);
}

void    BloqueDLL_Ayuda(CBloqueDLL* bloque, const char *& texto)
{
    texto = (const char *)bloque->getAyuda();	
}   

void    BloqueDLL_RedefAyuda(CBloqueDLL* bloque, const char * ayuda)
{
	bloque->setAyuda(ayuda);	
}


void    BloqueDLL_getMacro(CBloqueDLL* bloque, const char *& macro)
{
    macro = (const char *)bloque->getMacro();	
}	

void    BloqueDLL_RedefMacro(CBloqueDLL* bloque, const char * macro)
{
	bloque->setMacro(macro);	
}

