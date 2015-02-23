// Newton_Entrada.cpp: implementation of the Newton_Entrada class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_Entrada.h"

#include "Newton_SalidaDatos.h"
#include "Newton_SalidaInicio.h"
#include "Newton_ComRetro.h"
#include "DlgNewtonIni.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


// Implementación de Newton_Entrada

IMPLEMENTAR_BLOQUE_FUNCIONAL(Newton_Entrada, CBloqueFunc, 1)


IMPLEMENTAR_COM_SALIDA(Newton_SalidaInicio, Newton_Entrada)
IMPLEMENTAR_COM_SALIDA(Newton_ComRetro, Newton_Entrada)
IMPLEMENTAR_COM_SALIDA(CComSerial, Newton_Entrada)



Newton_Entrada::Newton_Entrada()
{

}


// Implementamos en esta clase en la que se puede modificar los valores estáticos
// el salvado y carga de dichos valores aunque sean comunes a todas las clases derivadas
// del tipo base. Notar que no se hizo en el tipo base pues conllevar¡a a Recibirrse
// m£ltiples veces probablemente para cada bloque derivado.


Newton_Entrada::~Newton_Entrada()
{
    // Para ver el orden del comportamiento respecto al destructor de CBloqueFunc
}


void Newton_Entrada::IniciarDatos()
{
	h = 1e-12;
	emax = 1e-30;
	x0 = 0;
	RedefAyuda((CString)"Entrada de datos");
	CambiaEstado(CORRECTO);  // Para poder retroanotar.
	RetroanotarEnCascada("");   // Enviar emax a los bloques que lo necesiten (ej. Decision)
}


BOOL Newton_Entrada::NuevosObjDatos()
{
	ejemplo = new CFontDialog;  // Para probar si la creación/destrucción se hace en el orden correcto
	Consola("Creado objeto ejemplo");
	TRACE("Creado objeto ejemplo\n");
	return true;
}


void Newton_Entrada::DestObjDatos()
{
	Consola("Destruido objeto ejemplo");
	TRACE("Destruido objeto ejemplo\n");
	delete ejemplo;
}


void Newton_Entrada::GuardarFichero(CArchive& ar)
{
    ar << emax << h << x0;
}

void Newton_Entrada::LeerFichero(CArchive& ar)
{
	NuevosObjDatos();
    ar >> emax >> h >> x0;
	// RetroanotarEnCascada("");   // Enviar emax y h a los bloques que lo necesiten (ej. Decision)
}


CString Newton_Entrada::Accion()
{
  // Diálogo de entrada de variables: emax, h, x0
    
   // int j = 0;
   // int i = 1/j;  // Provocación de error fatal.

  	//char* p = 0;
  	//*p = 0;     // Provocación de error fatal.

	BOOL res = EsNuevo();
	TipoEstado estado = getEstado();

	CDlgNewtonIni dlg(getMainWnd());  // En este ejemplo no asociamos a la ventana principal. Al parecer de esta forma no funciona el diálogo de cancelar modo Auto
	dlg.m_x0 = x0;
	dlg.m_emax = emax;    
    dlg.m_h = h;
	
	if (dlg.DoModal() == IDOK)
	{
		x0 = dlg.m_x0;
		emax = dlg.m_emax;
		h = dlg.m_h;
		CambiaEstado(CORRECTO);
		RetroanotarEnCascada("");   // Enviar emax a los bloques que lo necesiten (ej. Decision)
	}
	return "";
}


void Newton_Entrada::EnviarDatosSalida(Newton_ComRetro* pS)
{
   // No está diseñada para aceptar datos. No hacer nada para no provocar un error.
  	pS->emax = emax;   // No asignamos a nadie
	pS->h = h;
}

void Newton_Entrada::EnviarDatosSalida(Newton_SalidaInicio* pS)
{
  	pS->x = x0;
}

void Newton_Entrada::EnviarDatosSalida(CComSerial* pS)
{
	CArchive& ar = pS->getArchive();
	if (!pS->EsRetroAnotador())
	{
		ar << x0;
	}
	else
	{
		ar << emax;
		ar << h;
	}
}



BOOL Newton_Entrada::PropiedadesBloque()
{
		    
	// Diálogo de propiedades
	
	CDlgNewtonIni dlg(getMainWnd());
	dlg.m_x0 = x0;
	dlg.m_emax = emax;    
    dlg.m_h = h;
	
	if (IDOK == dlg.DoModal() )
	{
		x0 = dlg.m_x0;
		emax = dlg.m_emax;
		h = dlg.m_h;
		CambiaEstado(CORRECTO);
		RetroanotarEnCascada("");   // Enviar emax a los bloques que lo necesiten (ej. Decision)
		return true;
	}
	
	return false;
}
