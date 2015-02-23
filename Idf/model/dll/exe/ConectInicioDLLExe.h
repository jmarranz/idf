// ConectInicioDLLExe.h: interface for the CConectInicioDLLExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTINICIODLLEXE_H__215F4EDC_371C_4DD1_8F3A_CADD3B5DA38E__INCLUDED_)
#define AFX_CONECTINICIODLLEXE_H__215F4EDC_371C_4DD1_8F3A_CADD3B5DA38E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\EXE\ConectInicioExe.h"
#include "ConectExtremoDLLExe.h"


class CBloqueDLL;
class CConectInicioDLL;


class CConectInicioDLLExe : public CConectInicioExe
{
public:
	CConectInicioDLLExe();
	virtual ~CConectInicioDLLExe();
	virtual void Construir(CConectExtremo* ext);

	virtual void ConexyTestBloque();

	virtual CComunicacion* DevolverDatos();

	CConectInicioDLL* getInicio()
	{
		return (CConectInicioDLL*)p_extremo;
	}

protected:
    // Funciones de enlace con el DLL
    void  ( *pDevolverDatosClaseSalida)(void * pBloqueEnDLL,void* pS); 
	void* ( *pCrearObjComSalida)(CConect* pCon);
	void  ( *pDestObjDatosComSalida)(void  *pComSalida);
	BYTE* ( *pSerializarGuardadoObjComSalida)(void* pComSalida,DWORD& len);

public:
	HINSTANCE m_hInsDLLBloque;
};

#endif // !defined(AFX_CONECTINICIODLLEXE_H__215F4EDC_371C_4DD1_8F3A_CADD3B5DA38E__INCLUDED_)
