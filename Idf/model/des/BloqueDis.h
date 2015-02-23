// BloqueDis.h: interface for the CBloqueDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEDIS_H__547A01D9_9677_4573_A75C_31B1B04EC583__INCLUDED_)
#define AFX_BLOQUEDIS_H__547A01D9_9677_4573_A75C_31B1B04EC583__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\BloqueModo.h"

class CBloqueDis : public CBloqueModo  
{
	DECLARE_DYNAMIC(CBloqueDis)
public:
	CBloqueDis();
	virtual ~CBloqueDis();

    virtual void CrearNuevo( const Instante& t );
    virtual void CrearDeFichero(); 

	virtual void Serialize(CArchive& ar);

	virtual void ActualizaEstado();  // Sólo en diseño es llamada
	virtual Instante getTiempo();

	virtual TipoEstadoUsuario getEstadoUsr();
	virtual TipoEstadoInterno getEstadoInt();
	virtual void setEstadoUsr(TipoEstadoUsuario estado);
	virtual void setEstadoInt(TipoEstadoInterno estado);
	virtual BOOL EsNuevo();
	virtual BOOL CambiaEstado(TipoEstadoUsuario estado);

protected:
	// Aunque sean de estado se guardan a fichero
	// Se usan en modo diseño y funcional aunque de diferente forma
	TipoEstadoInterno m_estadoInterno;  // Valores NUEVO (=0, por defecto), MODIFICADO (=1)
	TipoEstadoUsuario m_estadoUsuario;  // Valores INCOMPLETO (=1, por defecto), ERRONEO (=2), CORRECTO (=3)

};

#endif // !defined(AFX_BLOQUEDIS_H__547A01D9_9677_4573_A75C_31B1B04EC583__INCLUDED_)
