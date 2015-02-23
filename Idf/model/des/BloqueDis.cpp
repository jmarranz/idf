// BloqueDis.cpp: implementation of the CBloqueDis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "BloqueDis.h"

#include "..\Bloque.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CBloqueDis,CBloqueModo)


CBloqueDis::CBloqueDis()
{
	m_estadoInterno = NUEVO;
	m_estadoUsuario = INCOMPLETO;
}

CBloqueDis::~CBloqueDis()
{

}

void CBloqueDis::CrearNuevo( const Instante& t )
{
}

void CBloqueDis::CrearDeFichero()
{
	ActualizaEstado();  // Para que tenga el estado y color adecuado el bloque en diseño
}

void CBloqueDis::Serialize(CArchive& ar)
{
	CBloqueModo::Serialize(ar); 
	
	if (ar.IsStoring())
	{
	    ar << (int)m_estadoInterno << (int)m_estadoUsuario;
	}
	else
	{
		ar >> (int&)m_estadoInterno >> (int&)m_estadoUsuario;
	}	
} 


void CBloqueDis::ActualizaEstado()
{
	// Actualizamos el estado del bloque tras análisis de sus datos
	if (NUEVO == m_estadoInterno)  m_estadoInterno = MODIFICADO;
	if (p_bloque->CComponenteDiag::PropiedadesCorrectas())  m_estadoUsuario = CORRECTO;
	else m_estadoUsuario = INCOMPLETO;
}

Instante CBloqueDis::getTiempo()
{
	return Instante();  // Devolvemos la hora actual. Es irrelevante en tiempo de diseño
}

BOOL CBloqueDis::EsNuevo()   // true si nunca ha sido modificado.
{
	if (m_estadoInterno != NUEVO) return false;
	return true;		
}

TipoEstadoUsuario CBloqueDis::getEstadoUsr()
{
	return m_estadoUsuario;
}

TipoEstadoInterno CBloqueDis::getEstadoInt()
{
	return m_estadoInterno;
}

void CBloqueDis::setEstadoUsr(TipoEstadoUsuario estado)
{
	m_estadoUsuario = estado;
}

void CBloqueDis::setEstadoInt(TipoEstadoInterno estado)
{
	m_estadoInterno = estado;
}

BOOL CBloqueDis::CambiaEstado(TipoEstadoUsuario estado)
{  
	m_estadoInterno = MODIFICADO;
	BOOL res = (m_estadoUsuario == estado);
	m_estadoUsuario = estado;
	return res;
}
