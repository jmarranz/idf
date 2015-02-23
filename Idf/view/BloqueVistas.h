// BloqueVistas.h: interface for the CBloqueVistas class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTAS_H__4E505B16_3B2B_47C9_8AA7_A2715A4F21F8__INCLUDED_)
#define AFX_BLOQUEVISTAS_H__4E505B16_3B2B_47C9_8AA7_A2715A4F21F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComponenteDiagVistas.h"

class CBaseView;
class CDlgBloque;
class CBloque;
class CDibBloque;
class CDibBloqueDis;
class CDibBloqueExe;
class CBloqueVistasModo;
class CBloqueVistasExe;
class CBloqueVistasDis;
class DOMElement;


class CBloqueVistas : public CComponenteDiagVistas  
{
public:
	CBloqueVistas();
	virtual ~CBloqueVistas();
	virtual void Construir(CComponenteDiag* comp);
	virtual void Destruir();

	virtual void CrearNuevo();  // Crea los diálogos del bloque en todas las vistas

	virtual CDibBloque* CrearObjDibBloque();

	CBloque* getBloque()
	{
		return (CBloque*)p_comp;
	}

	CBloqueVistasExe* getExe()
	{
		return (CBloqueVistasExe*)p_modo;
	}

	CBloqueVistasDis* getDis()
	{
		return (CBloqueVistasDis*)p_modo;
	}

	CDibBloque* getDibBloque();

	CDibBloqueDis* getDibBloqueDis()
	{
		return (CDibBloqueDis*)p_dibBloque;
	}

	CDibBloqueExe* getDibBloqueExe()
	{
		return (CDibBloqueExe*)p_dibBloque;
	}

	virtual void LeerDatosLDD( DOMElement* vistas,DOMTreeWalker* walker );
	virtual void EscribirDatosLDD( DOMElement* vistas );
	virtual void Serialize(CArchive& ar);

    virtual void addView(CBaseView* pView);
    virtual void removeView(CBaseView* pView);	

	virtual void Actualizar();
	virtual void Actualizar(CBaseView* view);
	virtual void ActualizarExcepto(CBaseView* view);

	virtual BOOL Propiedades(UINT pagina = 0) = 0;
	virtual void PropUsuario(); // Llamada desde el diálogo de propiedades y por CTRL Botón Dcho. 

	virtual void Mensaje(const CString& msg);

public:

protected:

	CBloqueVistasModo* p_modo;
	CDibBloque* p_dibBloque;

	CMapPtrToPtr m_views;
};

#endif // !defined(AFX_BLOQUEVISTAS_H__4E505B16_3B2B_47C9_8AA7_A2715A4F21F8__INCLUDED_)
