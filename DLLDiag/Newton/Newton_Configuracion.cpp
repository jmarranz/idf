// Newton_Configuracion.cpp: implementation of the Newton_Configuracion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_Configuracion.h"

#include "Newton_ComRetro.h"
#include "DlgNewtonRetro.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



// Clase Newton_Configuracion

IMPLEMENTAR_BLOQUE_RETROANOTACION(Newton_Configuracion, CBloqueRetro, 1)

IMPLEMENTAR_COM_ENTRADA(Newton_ComRetro, Newton_Configuracion)
IMPLEMENTAR_COM_ENTRADA(CComSerial, Newton_Configuracion)

IMPLEMENTAR_COM_SALIDA(Newton_ComRetro, Newton_Configuracion)
IMPLEMENTAR_COM_SALIDA(CComSerial, Newton_Configuracion)


void Newton_Configuracion::IniciarDatos()  
{
	emax = 1e-20;
	h = 1e-12; 
	CambiaEstado(CORRECTO);
}

BOOL Newton_Configuracion::NuevosObjDatos()
{
	ejemplo = new CString();
	Consola("Creado objeto ejemplo");
	return true;
}

void Newton_Configuracion::DestObjDatos()
{
	delete ejemplo;
}


void Newton_Configuracion::GuardarFichero(CArchive& ar)	
{
	ar << emax;
}

void Newton_Configuracion::LeerFichero(CArchive& ar)
{
	NuevosObjDatos();
	IniciarDatos();
	ar >> emax;
}

BOOL Newton_Configuracion::PropiedadesBloque()
{
	CDlgNewtonRetro dlg(getMainWnd());
	dlg.m_emax = emax;
	dlg.m_h = h;    
	
	if (IDOK == dlg.DoModal() )
	{
		emax = dlg.m_emax;
		h = dlg.m_h;
		CambiaEstado(CORRECTO);
		return true;
	}
	return false;
}


BOOL Newton_Configuracion::RecibirDatosEntrada(Newton_ComRetro* pE)
{
	emax = pE->emax;
  	h = pE->h;  
  	CambiaEstado(CORRECTO);
	return true;
}

BOOL Newton_Configuracion::RecibirDatosEntrada(CComSerial* pE)
{
	CArchive& ar = pE->getArchive();
	ar >> emax;
	ar >> h;

  	CambiaEstado(CORRECTO);
	return true;
}

void Newton_Configuracion::EnviarDatosSalida(Newton_ComRetro* pS)
{
  	pS->emax = emax;
  	pS->h = h; 
}

void Newton_Configuracion::EnviarDatosSalida(CComSerial* pS)
{
	CArchive& ar = pS->getArchive();
	ar << emax;
	ar << h;
}

