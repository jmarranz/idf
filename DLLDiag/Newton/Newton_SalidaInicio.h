// Newton_SalidaInicio.h: interface for the Newton_SalidaInicio class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_SALIDAINICIO_H__A6631FC7_9FF2_48F4_BE57_60038F846BC7__INCLUDED_)
#define AFX_NEWTON_SALIDAINICIO_H__A6631FC7_9FF2_48F4_BE57_60038F846BC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Clase Newton_SalidaInicio,  Clase de comunicaciones de salida del bloque de inicio al de valores actuales

class Newton_SalidaInicio : public CCom
{
public:
  	DECLARAR_COMUNICACION(Newton_SalidaInicio)

	virtual void GuardarDatos(CArchive& ar); // Util sólo en comunicación entre dos DLLs
	virtual void LeerDatos(CArchive& ar); // Util sólo en comunicación entre dos DLLs

public:
  	//DECLARAR_VARIABLE_COM(x, double) x;
  	
  	double x;
};

#endif // !defined(AFX_NEWTON_SALIDAINICIO_H__A6631FC7_9FF2_48F4_BE57_60038F846BC7__INCLUDED_)
