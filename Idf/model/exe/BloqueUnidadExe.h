// BloqueUnidadExe.h: interface for the CBloqueUnidadExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEUNIDADEXE_H__978F8257_32DA_489E_AD90_3607BE9BB757__INCLUDED_)
#define AFX_BLOQUEUNIDADEXE_H__978F8257_32DA_489E_AD90_3607BE9BB757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Instante.h"
#include "BloqueExe.h"

enum TipoEstadoUsuario;
enum TipoEstadoInterno;


class CBloqueUnidadExe : public CBloqueExe  
{
public:
	CBloqueUnidadExe();
	virtual ~CBloqueUnidadExe();

	virtual void CrearNuevo( const Instante& t );

	virtual void Serialize(CArchive& ar);

	virtual void IniciarExplicito(const Instante& t);

	virtual BOOL CambiaEstado(TipoEstadoUsuario estado);

	virtual TipoEstadoUsuario getEstadoUsr();
	virtual TipoEstadoInterno getEstadoInt();
	virtual void setEstadoUsr(TipoEstadoUsuario estado);
	virtual void setEstadoInt(TipoEstadoInterno estado);	
	virtual BOOL EsNuevo();

	Instante getTiempo();  // Devuelve el tiempo actual

	BOOL CompTiempo(const Instante& t); 

	BOOL ConfirmReescribir();

	BOOL RegistrarDatos(CComunicacion* pCom);

protected:
// Variables que se guardan a fichero:
	Instante m_instante; // Última modificación de los datos del bloque en ejecución

	// Aunque sean de estado se guardan a fichero
	// Se usan en modo diseño y funcional aunque de diferente forma
	TipoEstadoInterno m_estadoInterno;  // Valores NUEVO (=0, por defecto), MODIFICADO (=1)
	TipoEstadoUsuario m_estadoUsuario;  // Valores INCOMPLETO (=1, por defecto), ERRONEO (=2), CORRECTO (=3)
};

#endif // !defined(AFX_BLOQUEUNIDADEXE_H__978F8257_32DA_489E_AD90_3607BE9BB757__INCLUDED_)
