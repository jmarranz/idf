// ConectModo.h: interface for the CConectModo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTMODO_H__E0EC29D1_90C6_4DBF_9F5A_89D92785E614__INCLUDED_)
#define AFX_CONECTMODO_H__E0EC29D1_90C6_4DBF_9F5A_89D92785E614__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Instante.h"

class CConect;
class CConectVistas;
class CComponenteDiagVistas;


class CConectModo : public CObject  
{
	DECLARE_DYNAMIC(CConectModo)
public:
	CConectModo();
	virtual ~CConectModo();
	virtual void Construir(CConect* pcon);

    virtual void CrearNuevo( const Instante& t ) = 0;
    virtual void CrearDeFichero() = 0;

	CConect* getConect()
	{
		return p_conect;
	}

	virtual CComponenteDiagVistas* CrearObjVistas() = 0;

	virtual void ActualizaEstado() = 0;

protected:
	CConect* p_conect;
};

#endif // !defined(AFX_CONECTMODO_H__E0EC29D1_90C6_4DBF_9F5A_89D92785E614__INCLUDED_)
