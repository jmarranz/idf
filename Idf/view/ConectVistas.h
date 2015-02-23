// ConectVistas.h: interface for the CConectVistas class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTVISTAS_H__72B9B179_B509_4322_BEB5_B10182F3379E__INCLUDED_)
#define AFX_CONECTVISTAS_H__72B9B179_B509_4322_BEB5_B10182F3379E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ComponenteDiagVistas.h"

class CConect;
class CDibConect;
class CBaseView;
class CConectVistasDis;
class CConectVistasExe;


class CConectVistas : public CComponenteDiagVistas  
{
public:
	CConectVistas();
	virtual ~CConectVistas();
	virtual void Construir(CComponenteDiag* comp);

	virtual void Destruir();

	virtual void CrearNuevo();

	CConect* getConect()
	{
		return (CConect*)p_comp;
	}

	CDibConect* getDibConect();

	CConectVistasExe* getExe()
	{
		return (CConectVistasExe*)this;
	}

	CConectVistasDis* getDis()
	{
		return (CConectVistasDis*)this;
	}

	virtual CDibConect* CrearObjDibConect() = 0;

	virtual void LeerDatosLDD(DOMElement* vistas,DOMTreeWalker* walker);
	virtual void EscribirDatosLDD(DOMElement* vistas);	

	virtual void Serialize(CArchive& ar);

	virtual void Actualizar();
	virtual void Actualizar(CBaseView* view);
	virtual void ActualizarExcepto(CBaseView* view);

	virtual BOOL Propiedades();

	virtual void Mensaje(const CString& msg);

    virtual void addView(CBaseView* pView);
    virtual void removeView(CBaseView* pView);	 


protected:
    CDibConect* p_dibCon; 
};

#endif // !defined(AFX_CONECTVISTAS_H__72B9B179_B509_4322_BEB5_B10182F3379E__INCLUDED_)
