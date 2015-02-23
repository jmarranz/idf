// BloqueDLLVistasExe.h: interface for the CBloqueDLLVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASDLLEXE_H__39C5EF4C_8278_4D74_A7EB_E305AC7CB199__INCLUDED_)
#define AFX_BLOQUEVISTASDLLEXE_H__39C5EF4C_8278_4D74_A7EB_E305AC7CB199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\exe\BloqueUnidadVistasExe.h"

class CBloqueDLLVistas;


class CBloqueDLLVistasExe : public CBloqueUnidadVistasExe
{
public:
	CBloqueDLLVistasExe();
	virtual ~CBloqueDLLVistasExe();

	CBloqueDLLVistas* getVistas()
	{
		return (CBloqueDLLVistas*)p_vistas;
	}

	virtual void PropUsuario(); // Llamada desde el diálogo de propiedades y por CTRL Botón Dcho. 
	// Llama a una función del DLL para poder mostrar un diálogo de usuario para propiedades específicas
	// definidas por el usuario para el bloque.

	virtual BOOL nuevoNombreClaseEnDLL();
};

#endif // !defined(AFX_BLOQUEVISTASDLLEXE_H__39C5EF4C_8278_4D74_A7EB_E305AC7CB199__INCLUDED_)
