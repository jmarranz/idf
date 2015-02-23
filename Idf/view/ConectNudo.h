// ConectNudo.h: interface for the CConectNudo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTNUDO_H__DECEB8B4_80BF_4A19_A965_A683F6FE3430__INCLUDED_)
#define AFX_CONECTNUDO_H__DECEB8B4_80BF_4A19_A965_A683F6FE3430__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBaseView;
class CConect;
class CConectDis;

// Valores del tamaño del diálogo del nudo (área cliente + borde)

#define ANCHONUDO  10
#define ALTONUDO   10

#define NUDO_INICIO  1
#define NUDO_MEDIO   2
#define NUDO_FINAL   3 


class CConNudo : public CObject
{
	DECLARE_SERIAL(CConNudo)

public:
	CConNudo();
	virtual void Construir(CConect* pcon);
	virtual void Destruir();
	virtual void CrearNuevo();

	virtual void Serialize(CArchive& ar);
	
	virtual void LeerDatosLDD(DOMElement* nudo);
	virtual void EscribirDatosLDD(DOMElement* nudo);

	virtual void DibujarTramo(CDC* pDC, CBaseView* view, CConNudo* pNudoPrev);  // Dibuja desde el tramo del conector desde el nudo anterior al nudo actual.	
	
	CConect* getConect()
	{
		return p_conect;
	}

	CConectDis* getConectDis()
	{
		return (CConectDis*)p_conect;
	}

	virtual int getTipoNudo();


public:
    // Punteros para hacer una lista doblemente enlazada. Una CObList ya lo es pero así accedemos más rápido.
	CConect* p_conect;

	CConNudo* p_nudoPrev;  // Nudo anterior
	CConNudo* p_nudoSig;	  // Nudo posterior
                                                                                                                                       
    CPoint m_posNudo;

	BOOL m_seleccionado;  // Temporal. Para mover, eliminar etc. Sólo en tiempo de diseño (false de otra manera).
};


#endif // !defined(AFX_CONECTNUDO_H__DECEB8B4_80BF_4A19_A965_A683F6FE3430__INCLUDED_)
