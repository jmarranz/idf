// BloqueUnidadExe.cpp: implementation of the CBloqueUnidadExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "BloqueUnidadExe.h"

#include "DiagExe.h"
#include "Comunicacion.h"

#include "..\Bloque.h"
#include "..\bdiag\BloqueDiag.h"


#include "..\..\view\BloqueVistas.h"
#include "..\..\view\bdiag\BloqueDiagVistas.h"
#include "..\..\view\DiagramaVistas.h"
     


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueUnidadExe::CBloqueUnidadExe()
{
	m_estadoInterno = NUEVO;
	m_estadoUsuario = INCOMPLETO;
}

CBloqueUnidadExe::~CBloqueUnidadExe()
{

}

void CBloqueUnidadExe::CrearNuevo( const Instante& t )  
{
	// Variables que se guardan a fichero pero no se leen del LDD:	
	m_instante.set(t);
}

void CBloqueUnidadExe::Serialize(CArchive& ar)
{
	CBloqueExe::Serialize(ar);

	m_instante.Serialize(ar);

	if (ar.IsStoring())
	{
	    ar << (int)m_estadoInterno << (int)m_estadoUsuario;
	}
	else
	{
		ar >> (int&)m_estadoInterno >> (int&)m_estadoUsuario;
	}	

} 

void CBloqueUnidadExe::IniciarExplicito(const Instante& t)  
{
	CBloqueExe::IniciarExplicito(t);

	// Se ejecuta a través de menú por el usuario, inicializa las variables a sus valores por defecto.

	m_estadoInterno = NUEVO;
	m_estadoUsuario = INCOMPLETO;
	
	// Supone que todos los objetos y DLL necesarios han sido creados y enlazados correctamente.
	// Llama en cadena al objeto CBloqueFunc asociado al bloque en el DLL.

	m_instante.set(t);
}


BOOL CBloqueUnidadExe::CambiaEstado(TipoEstadoUsuario estado)
{
	BOOL res = false;

	CBloque* pbloque = getBloque();
	
	if ( m_estadoUsuario != estado)
	{
		m_estadoUsuario = estado;
		m_estadoInterno = MODIFICADO;
		CString stemp("Cambio de estado a: ");
		stemp = stemp + pbloque->EstadoUsrAstring();
		Consola(stemp);		
		res = true;
	}
	
	if (NUEVO == m_estadoInterno)
	{
		m_estadoInterno = MODIFICADO;
		Consola("Estado: INCOMPLETO (modificado por primera vez)");
		res = true;
	}

	if (res)
	{
		if (pbloque->EsMultiDiag())   // Notar que puede cambiarse el estado desde el hijo influyendo sobre el padre indirectamente, por eso la actualización se hace desde el hijo.
		{
			CDiagExe* pdiag = pbloque->getDiagExe();

			// El que decide el estado del bloque padre es el bloque final, hemos de elegir
			if (pbloque == pdiag->getMDiagBloqFin())
			{
	 			CBloqueDiag* bloquePadre = pdiag->getBloqPadre();
				bloquePadre->getVistas()->Actualizar();
	 		}
		}

		m_instante.Iniciar();
		pbloque->getVistas()->Actualizar();
	}
	return res;
}


Instante CBloqueUnidadExe::getTiempo()
{
	return m_instante;
}


BOOL CBloqueUnidadExe::CompTiempo(const Instante& t)
{
 // El tiempo externo es más reciente (actual) que el local. Incluimos el "=" pues 
 // la cuenta es en segundos y en modo automático se pasa de un bloque a otro antes
 // de que pase un segundo, es para evitar interrupciones del diálogo de confirmación de sobreescritura.
    if ( m_instante.Compara( t ) <= 0 ) return true; 
    return false;
}


BOOL CBloqueUnidadExe::RegistrarDatos(CComunicacion* pCom)
{
	if (pCom == NULL) return false;
	Instante t = pCom->getInstante(); // Si es un objeto receptor espejo accederá al remoto 
	if (!CompTiempo(t)) 
	{
		if ( !ConfirmReescribir() ) return false;
	}
	m_instante.set(t);
	return true;
}	


BOOL CBloqueUnidadExe::ConfirmReescribir()
{
	// Diálogo para confirmación de sustitución de los datos actuales por otros más antiguos.
	// true si hay confirmación de escritura.
	CBloque* pbloque = getBloque();

	CString stemp = "¿ Sobreescribir con datos más antiguos en: " + pbloque->getEtiqueta() + " ?";
	BOOL res = pbloque->getDiag()->getVistas()->Confirm(stemp);

	if (res) stemp += ": SI";
	else stemp += ": NO";
	Consola( stemp, SISTEMA );  // También por la consola la respuesta
	return res;
}


TipoEstadoUsuario CBloqueUnidadExe::getEstadoUsr()
{
	return m_estadoUsuario;
}

TipoEstadoInterno CBloqueUnidadExe::getEstadoInt()
{
	return m_estadoInterno;
}

void CBloqueUnidadExe::setEstadoUsr(TipoEstadoUsuario estado)
{
	m_estadoUsuario = estado;
}

void CBloqueUnidadExe::setEstadoInt(TipoEstadoInterno estado)
{
	m_estadoInterno = estado;
}

BOOL CBloqueUnidadExe::EsNuevo()   // true si nunca ha sido modificado.
{
	if (m_estadoInterno != NUEVO) return false;
	return true;		
}

