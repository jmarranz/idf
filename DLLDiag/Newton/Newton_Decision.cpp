// Newton_Decision.cpp: implementation of the Newton_Decision class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_Decision.h"

#include "Newton_SalidaDatos.h"
#include "Newton_ComRetro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


// Clase Newton_Decision


IMPLEMENTAR_BLOQUE_FUNCIONAL(Newton_Decision, CBloqueFunc, 1)

IMPLEMENTAR_COM_ENTRADA(Newton_SalidaDatos, Newton_Decision)
IMPLEMENTAR_COM_ENTRADA(Newton_ComRetro, Newton_Decision)
IMPLEMENTAR_COM_ENTRADA(CComSerial, Newton_Decision)

IMPLEMENTAR_COM_SALIDA(Newton_SalidaDatos, Newton_Decision)
IMPLEMENTAR_COM_SALIDA(CComSerial, Newton_Decision)


void Newton_Decision::IniciarDatos()
{
	x = 0;
	e = 0;
	RecibirDatosRetroanotacion("");  // Recibe el valor de emax en el bloque de retroanotación.
	CambiaEstado(ERRONEO);
}

void Newton_Decision::GuardarFichero(CArchive& ar)
{
    ar << x << e << emax;
}


void Newton_Decision::LeerFichero(CArchive& ar)
{
    ar >> x >> e >> emax;
}

BOOL Newton_Decision::RecibirDatosEntrada(Newton_SalidaDatos* pE)
{
  	x = pE->x;
  	e = pE->e;	
	CambiaEstado(CORRECTO);
	return true;
}

BOOL Newton_Decision::RecibirDatosEntrada(Newton_ComRetro* pE)
{
  	emax = pE->emax;
	CambiaEstado(CORRECTO);
	return true;
}

BOOL Newton_Decision::RecibirDatosEntrada(CComSerial* pE)
{
	CArchive& ar = pE->getArchive();
	if (!pE->EsRetroAnotador())
	{
		ar >> x;
		ar >> e;
	}
	else
	{
		double h; // No nos sirve
		ar >> emax;
		ar >> h;
	}

	CambiaEstado(CORRECTO);
	return true;
}


void Newton_Decision::EnviarDatosSalida(Newton_SalidaDatos* pS)
{
  	pS->x = x;
  	pS->e = e;
}

void Newton_Decision::EnviarDatosSalida(CComSerial* pS)
{
	CArchive& ar = pS->getArchive();
	ar << x;
	ar << e;
}


CString Newton_Decision::Accion()
{
	CString salida;
	if (e < emax)
	{
	 	salida = "SI"; 
		Consola("Alcanzado el resultado de error aceptable: continuación por conductor SI");
	}
    else
    {
     	salida = "NO";
		Consola("Valor actual de error no aceptable: continuación por conductor NO");
	}
	
	return salida;
}

