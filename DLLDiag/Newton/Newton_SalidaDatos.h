// Newton_SalidaDatos.h: interface for the Newton_SalidaDatos class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_SALIDADATOS_H__BA287CC9_241A_4298_8FB4_345C175171B3__INCLUDED_)
#define AFX_NEWTON_SALIDADATOS_H__BA287CC9_241A_4298_8FB4_345C175171B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Clase Newton_SalidaDatos,  Clase de comunicaciones de salida de todos los bloques del diagrama

class Newton_SalidaDatos : public CCom
{
public:
  	DECLARAR_COMUNICACION(Newton_SalidaDatos)

public:  	
  	//DECLARAR_VARIABLE_COM(x, double) x;
  	//DECLARAR_VARIABLE_COM(e, double) e;

  	DECLARAR_FUNCION_COM(SPrueba, const char*, CadenaPrueba)

public:
  	double x;
  	double e;

private:
	CString SPrueba;
};


#endif // !defined(AFX_NEWTON_SALIDADATOS_H__BA287CC9_241A_4298_8FB4_345C175171B3__INCLUDED_)
