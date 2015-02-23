// DibConect.h: interface for the CDibConect2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBCONECT_H__DD51DB5A_ABCB_4BA2_B103_5F773EE7C1B6__INCLUDED_)
#define AFX_DIBCONECT_H__DD51DB5A_ABCB_4BA2_B103_5F773EE7C1B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//class CDibConect; Clase con los elementos de dibujo del conector

#include "Flecha.h"
#include "Rgb.h"

class CBaseView;
class CConNudo;
class CConect;
class CConectVistas;
class CDibConectDis;
class CDibConectExe;
class DOMElement;



class CDibConect : public CObject
{
 	DECLARE_DYNAMIC(CDibConect)	
public:
	CDibConect();
	virtual	~CDibConect();
	virtual void Destruir();

	void Construir(CConectVistas* pvistas);
	CConect* getConect();

	CDibConectDis* getDis()
	{
		return (CDibConectDis*)this;
	}

	CDibConectExe* getExe()
	{
		return (CDibConectExe*)this;
	}

	virtual void Serialize(CArchive& ar);

	virtual void LeerDatosLDD(DOMElement* vistas);
	virtual void EscribirDatosLDD(DOMElement* vistas);	

	virtual BOOL LeerDatosLDDNudos(DOMElement* nudos);
	virtual BOOL EscribirDatosLDDNudos(DOMElement* nudos);


	virtual CFlecha* getpFlecha();	
	
	virtual void Dibujar(CDC* pDC, CBaseView* view);	
	
	virtual CConNudo* AnyadeNudoMedioPosterior(CConNudo* pNudoPrev);
	virtual CConNudo* AnyadeNudoMedioAnterior(CConNudo* pNudoPost);
	virtual CConNudo* AnyadeNudoFinal(CPoint pt);
	virtual void AnyadeNudoFinal(CConNudo* pNudo);

	virtual void EliminarNudo(CConNudo* pNudo);

	virtual CConNudo* crearNudo();

	virtual void Reconectar(CConNudo* pNudoPrev,CConNudo* pNudo,CConNudo* pNudoSig);
	virtual void ReconectarTodosNudos();
	
	virtual POSITION getPosNudo(CConNudo* pNudo);
	
	virtual void BorraArrPtos();
	
	virtual void OffsetConector(int x, int y);

	virtual void Actualizar() = 0;
	virtual void Actualizar(CBaseView* view) = 0;
	virtual void ActualizarExcepto(CBaseView* view) = 0;


    virtual void addView(CBaseView* pView) = 0;
    virtual void removeView(CBaseView* pView) = 0;

// Variables:
public:
	CObList m_listaNudos;  // Lista de nudos del conector. El orden de la lista es el orden de los nudos que la forman, el inicial es el comienzo del conector.
    CFlecha m_flecha;

	
	CPoint m_ptoInsEtiq;
	CRgb m_color;
	int m_ancho;
	
	BOOL m_visible;

protected:
	CConectVistas* p_vistas;
	CConect* p_conect;

};



#endif // !defined(AFX_DIBCONECT_H__DD51DB5A_ABCB_4BA2_B103_5F773EE7C1B6__INCLUDED_)
