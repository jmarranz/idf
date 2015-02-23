// BloqueModo.h: interface for the CBloqueModo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEMODO_H__5F55F5A6_A47D_4630_9391_01BB85C2ACAF__INCLUDED_)
#define AFX_BLOQUEMODO_H__5F55F5A6_A47D_4630_9391_01BB85C2ACAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBloque;
class Instante;
class CBloqueVistas;
enum TipoEstadoUsuario;
enum TipoEstadoInterno;


class CBloqueModo : public CObject  
{
	DECLARE_DYNAMIC(CBloqueModo)
public:
	CBloqueModo();
	virtual ~CBloqueModo();

	virtual void Construir(CBloque* pbloque);
	virtual void Destruir() { };

    virtual void CrearNuevo( const Instante& t ) = 0;
    virtual void CrearDeFichero() = 0;

	virtual void Serialize(CArchive& ar);

	CBloque* getBloque()
	{
		return p_bloque;
	}

	virtual TipoEstadoUsuario getEstadoUsr() = 0;
	virtual TipoEstadoInterno getEstadoInt() = 0;
	virtual void setEstadoUsr(TipoEstadoUsuario estado) = 0;
	virtual void setEstadoInt(TipoEstadoInterno estado) = 0;

	virtual BOOL EsNuevo() = 0;
	virtual BOOL CambiaEstado(TipoEstadoUsuario estado) = 0;

	virtual Instante getTiempo() = 0;

	virtual void ActualizaEstado() = 0;

protected:
	CBloque* p_bloque;
};

#endif // !defined(AFX_BLOQUEMODO_H__5F55F5A6_A47D_4630_9391_01BB85C2ACAF__INCLUDED_)
