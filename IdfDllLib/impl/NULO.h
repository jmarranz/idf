// NULO.h: interface for the NULO2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NULO_H__9FF3A3D5_7764_4B82_94EB_04792B438AFF__INCLUDED_)
#define AFX_NULO_H__9FF3A3D5_7764_4B82_94EB_04792B438AFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "com.h"

// El objeto de comunicaciones nulo por defecto.

class NULO : public CCom
{
public:
	DECLARAR_COMUNICACION(NULO)

	virtual void GuardarDatos(CArchive& ar);
	virtual void LeerDatos(CArchive& ar);
};

#endif // !defined(AFX_NULO_H__9FF3A3D5_7764_4B82_94EB_04792B438AFF__INCLUDED_)
