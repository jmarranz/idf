// Newton_Calculo.cpp: implementation of the Newton_Calculo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_Calculo.h"

#include "Newton_SalidaDatos.h"
#include "Newton_ComRetro.h"
#include "Newton_Funcion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


// Implementación de Newton_Calculo, clase de cálculo de una iteración.


IMPLEMENTAR_BLOQUE_FUNCIONAL(Newton_Calculo, CBloqueFunc, 1)

IMPLEMENTAR_COM_ENTRADA(Newton_SalidaDatos, Newton_Calculo)
IMPLEMENTAR_COM_ENTRADA(Newton_ComRetro, Newton_Calculo)
IMPLEMENTAR_COM_ENTRADA(CComSerial, Newton_Calculo)


IMPLEMENTAR_COM_SALIDA(Newton_SalidaDatos, Newton_Calculo)
IMPLEMENTAR_COM_SALIDA(CComSerial, Newton_Calculo)



void Newton_Calculo::IniciarDatos()
{
	// No iniciamos h ni e, pues los esperamos por retroanotación.
	// h = 1e-12;
	// e = 0;
	x = 0;

	// CambiaEstado(ERRONEO);
}

void Newton_Calculo::GuardarFichero(CArchive& ar)
{
    ar << x << x2 << e << h;
}


void Newton_Calculo::LeerFichero(CArchive& ar)
{
    ar >> x >> x2 >> e >> h;
}


BOOL Newton_Calculo::RecibirDatosEntrada(Newton_SalidaDatos* pE)
{
	x = pE->x;
  	e = pE->e;
	CString stemp = pE->GetCadenaPrueba();
	// AfxMessageBox(stemp);
	CambiaEstado(CORRECTO);
	return true;
}

BOOL Newton_Calculo::RecibirDatosEntrada(Newton_ComRetro* pE)
{
  	h = pE->h;
	CambiaEstado(CORRECTO);
	return true;
}

BOOL Newton_Calculo::RecibirDatosEntrada(CComSerial* pE)
{
	CArchive& ar = pE->getArchive();
	if (!pE->EsRetroAnotador())
	{
		ar >> x;
		ar >> e;
	}
	else
	{
		double emax; // No nos sirve
		ar >> emax;
		ar >> h;
	}

	CambiaEstado(CORRECTO);
	return true;
}


void Newton_Calculo::EnviarDatosSalida(Newton_SalidaDatos* pS)
{
  	pS->x = x;
  	pS->e = e;
}

void Newton_Calculo::EnviarDatosSalida(CComSerial* pS)
{
	CArchive& ar = pS->getArchive();
	ar << x;
	ar << e;
}


CString Newton_Calculo::Accion()
{
	x2 = x - f(x) / fd(x, h) ;
	if (x2 > x) e = x2 - x;
    else e = x - x2;
    x=x2;
	return "";
}
