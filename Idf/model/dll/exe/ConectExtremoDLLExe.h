// ConectExtremoDLLExe.h: interface for the CConectExtremoDLLExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTEXTREMODLLEXE_H__38D1192C_C8DF_47D0_9758_F6D5E84A8141__INCLUDED_)
#define AFX_CONECTEXTREMODLLEXE_H__38D1192C_C8DF_47D0_9758_F6D5E84A8141__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CConect;
class CBloque;
class CBloqueDLL;
enum OrdenBloqueDiag;


class CConectExtremoDLLExe
{
public:
	CConectExtremoDLLExe();
	virtual ~CConectExtremoDLLExe();

	static CString MensajeErrorTestConex(CConect* pcon,CBloqueDLL* pBloque,const CString& entra_sale);
	static CString MensajeErrorTestConex(CConect* pcon,const CString& DLLNombre);

	static void errorTestConexion(CConect* pcon,const CString& dllBloque);

};

#endif // !defined(AFX_CONECTEXTREMODLLEXE_H__38D1192C_C8DF_47D0_9758_F6D5E84A8141__INCLUDED_)
