// Newton_Resultados.cpp: implementation of the Newton_Resultados class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_Resultados.h"

#include "Newton_SalidaDatos.h"
#include "DlgNewton.h"

#include "Newton_Funcion.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


// Clase Newton_Resultados, clase de muestra de los valores resultantes del bucle, susceptibles de modificarse. Es tambi‚n el di logo de salida de resultados.


IMPLEMENTAR_BLOQUE_FUNCIONAL(Newton_Resultados, CBloqueFunc, 1)

IMPLEMENTAR_COM_ENTRADA(Newton_SalidaDatos, Newton_Resultados)
IMPLEMENTAR_COM_ENTRADA(CComSerial, Newton_Resultados)

IMPLEMENTAR_COM_SALIDA(Newton_SalidaDatos, Newton_Resultados)
IMPLEMENTAR_COM_SALIDA(CComSerial, Newton_Resultados)


void Newton_Resultados::IniciarDatos()
{
	x = 0;
	e = 0;
	CambiaEstado(ERRONEO);
}


void Newton_Resultados::GuardarFichero(CArchive& ar)
{
  	ar << x << e;
}


void Newton_Resultados::LeerFichero(CArchive& ar)
{
  	ar >> x >> e;
}


BOOL Newton_Resultados::RecibirDatosEntrada(Newton_SalidaDatos* pE)
{
  	x = pE->x;
  	e = pE->e;
	CambiaEstado(CORRECTO);
	return true;
}

BOOL Newton_Resultados::RecibirDatosEntrada(CComSerial* pE)
{
	CArchive& ar = pE->getArchive();
	ar >> x;
	ar >> e;

	CambiaEstado(CORRECTO);
	return true;
}

void Newton_Resultados::EnviarDatosSalida(Newton_SalidaDatos* pS)
{
  	pS->x = x;
  	pS->e = e;
}

void Newton_Resultados::EnviarDatosSalida(CComSerial* pS)
{
	CArchive& ar = pS->getArchive();
	ar << x;
	ar << e;
}


CString Newton_Resultados::Accion()
{
  // Muestra el diálogo de muestra de datos y posible modificaci¢n.
  // En modo Auto no muestra dicho diálogo para que la iteración sea continua.
  
//	if (!EsModoAuto())
	{
		CDlgNewton dlg;
		dlg.m_x = x;
		dlg.m_fx = f(x);    
		dlg.m_e = e;
		dlg.Mensaje((CString)"Resultados:");    
		if (dlg.DoModal() == IDOK)
		{
			x = dlg.m_x;
			e = dlg.m_e;
		}	
	}
	return "";
}

