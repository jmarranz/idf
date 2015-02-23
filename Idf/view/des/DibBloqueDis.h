// DibBloqueDis.h: interface for the CDibBloqueDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBBLOQUEDIS_H__236E5235_6F75_4AC3_9541_7D53FF484EFA__INCLUDED_)
#define AFX_DIBBLOQUEDIS_H__236E5235_6F75_4AC3_9541_7D53FF484EFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\DibBloque.h"

class CDibBloqueDis : public CDibBloque  
{
public:
	CDibBloqueDis();
	virtual ~CDibBloqueDis();

	virtual BOOL Dibujar(CDC* pDC, CBaseView* view);

	void Seleccionar(BOOL Seleccionar = true, CRect * prsel = NULL, CBaseView* view = NULL);
	BOOL EsSeleccionado();

public:
    BOOL m_seleccionado; // Para el proceso del diseño del diagrama. Indica que el bloque está seleccionado (para borrar, mover etc.)

};

#endif // !defined(AFX_DIBBLOQUEDIS_H__236E5235_6F75_4AC3_9541_7D53FF484EFA__INCLUDED_)
