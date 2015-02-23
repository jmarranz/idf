// Newton_Actuales.cpp: implementation of the Newton_Actuales class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_Actuales.h"

#include "Newton_SalidaDatos.h"
#include "Newton_SalidaInicio.h"
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

// Clase Newton_Actuales, clase de muestra de los valores actuales de iteraci¢n, susceptibles de modificarse. Es tambi‚n el di logo de salida de resultados.


IMPLEMENTAR_BLOQUE_FUNCIONAL(Newton_Actuales, CBloqueFunc, 1)

IMPLEMENTAR_COM_ENTRADA(Newton_SalidaDatos, Newton_Actuales)
IMPLEMENTAR_COM_ENTRADA(Newton_SalidaInicio, Newton_Actuales)
IMPLEMENTAR_COM_ENTRADA(CComSerial, Newton_Actuales)

IMPLEMENTAR_COM_SALIDA(Newton_SalidaDatos, Newton_Actuales)
IMPLEMENTAR_COM_SALIDA(CComSerial, Newton_Actuales)


void Newton_Actuales::IniciarDatos()
{
	x = 0;
	e = 0;
	CambiaEstado(INCOMPLETO);
}


void Newton_Actuales::GuardarFichero(CArchive& ar)
{
    ar << x << e;
}


void Newton_Actuales::LeerFichero(CArchive& ar)
{
 	ar >> x >> e;
}


BOOL Newton_Actuales::RecibirDatosEntrada(Newton_SalidaDatos* pE)
{
  	x = pE->x;
  	e = pE->e;
	CambiaEstado(CORRECTO);
	return true;
}


BOOL Newton_Actuales::RecibirDatosEntrada(Newton_SalidaInicio* pE)
{
	if (pE->x >= 1000) return false;    // Para probar el rechazo de datos que provoca cambio de estado a ERRONEO por defecto.

  	x = pE->x;
	CambiaEstado(CORRECTO);
	return true;
}

BOOL Newton_Actuales::RecibirDatosEntrada(CComSerial* pE)
{
 	CArchive& ar = pE->getArchive();
	if (pE->getEtiquetaConector() == "NO")
	{
		ar >> x;
		ar >> e;
	}
	else
	{
		ar >> x;
	}
	CambiaEstado(CORRECTO);
	return true;
}


void Newton_Actuales::EnviarDatosSalida(Newton_SalidaDatos* pS)
{
  	pS->x = x;
  	pS->e = e;
	pS->SetCadenaPrueba( "Hola que tal" );
}

void Newton_Actuales::EnviarDatosSalida(CComSerial* pS)
{
 	CArchive& ar = pS->getArchive();
	ar << x;
	ar << e;
}


CString Newton_Actuales::Accion()
{
  // Muestra el diálogo de muestra de datos y posible modificaci¢n.
  // En modo Auto no muestra dicho diálogo para que la iteración sea continua.
  
//	if (!EsModoAuto())
	{
		CWnd* pWin = getMainWnd();
		CDlgNewton dlg(pWin);
	//	dlg.m_men = "Valores actuales:";
		dlg.m_x = x;
		dlg.m_fx = f(x);    
		dlg.m_e = e;    
		dlg.Mensaje((CString)"Valores Actuales:");   
		if (dlg.DoModal() == IDOK)
		{
			x = dlg.m_x;
			e = dlg.m_e;
		}	
	}
	return "";
}
