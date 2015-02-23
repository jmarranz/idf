// ComponenteDiagVistas.h: interface for the CComponenteDiagVistas class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTEDIAGVISTAS_H__B515E532_EB95_4E38_9A65_B5B795C8E0B2__INCLUDED_)
#define AFX_COMPONENTEDIAGVISTAS_H__B515E532_EB95_4E38_9A65_B5B795C8E0B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBaseView;
class DOMElement;
class DOMTreeWalker;
class CComponenteDiag;


class CComponenteDiagVistas : public CObject  
{
public:
	CComponenteDiagVistas();
	virtual ~CComponenteDiagVistas();
	virtual void Construir(CComponenteDiag* comp);
	virtual void Destruir();

    virtual void addView(CBaseView* pView) = 0;
    virtual void removeView(CBaseView* pView) = 0;	

	virtual void Actualizar() = 0;
	virtual void Actualizar(CBaseView* view) = 0;
	virtual void ActualizarExcepto(CBaseView* view) = 0;

	virtual void LeerDatosLDD( DOMElement* vistas,DOMTreeWalker* walker ) = 0;
	virtual void EscribirDatosLDD( DOMElement* vistas ) = 0;

protected:
	CComponenteDiag* p_comp;
};

#endif // !defined(AFX_COMPONENTEDIAGVISTAS_H__B515E532_EB95_4E38_9A65_B5B795C8E0B2__INCLUDED_)
