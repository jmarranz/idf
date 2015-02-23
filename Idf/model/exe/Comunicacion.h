// Comunicacion.h: interface for the CComunicacion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMUNICACION_H__82F2D144_C713_4288_99A9_F0C715AEF7E2__INCLUDED_)
#define AFX_COMUNICACION_H__82F2D144_C713_4288_99A9_F0C715AEF7E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Instante.h"


class CComunicacion : public CObject  
{
public:
	CComunicacion();
	CComunicacion(Instante t);
	virtual ~CComunicacion();

	Instante getInstante() { return m_Instante; }

private:
	Instante   m_Instante;  // Instante de la emisión del objeto
};

#endif // !defined(AFX_COMUNICACION_H__82F2D144_C713_4288_99A9_F0C715AEF7E2__INCLUDED_)
