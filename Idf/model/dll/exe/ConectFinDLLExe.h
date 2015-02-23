// ConectFinDLLExe.h: interface for the CConectFinDLLExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTFINDLLEXE_H__85D15D59_069C_4236_9454_D350AC6141CB__INCLUDED_)
#define AFX_CONECTFINDLLEXE_H__85D15D59_069C_4236_9454_D350AC6141CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\EXE\ConectFinExe.h"
#include "ConectExtremoDLLExe.h"

class CBloqueDLL;
class CConectFinDLL;


class CConectFinDLLExe : public CConectFinExe  
{
public:
	CConectFinDLLExe();
	virtual ~CConectFinDLLExe();
	virtual void Construir(CConectExtremo* ext);

	virtual void ConexyTestBloque();

	virtual BOOL AceptarDatos(CComunicacion* pE);

	CConectFinDLL* getFin()
	{
		return (CConectFinDLL*)p_extremo;
	}

protected:
    // Funciones de enlace con el DLL
    BOOL  ( *pAceptarDatosClaseEntrada)(void * pBloqueEnDLL, void* pE); 
	void* ( *pCrearObjComEntrada)(CConect* pCon);
	void  ( *pDestObjDatosComEntrada)(void  *pComEntrada);
	BOOL  ( *pSerializarCargaObjComEntrada)(BYTE* buff,DWORD len,void* pCom);

	HINSTANCE m_hInsDLLBloque;
};

#endif // !defined(AFX_CONECTFINDLLEXE_H__85D15D59_069C_4236_9454_D350AC6141CB__INCLUDED_)
