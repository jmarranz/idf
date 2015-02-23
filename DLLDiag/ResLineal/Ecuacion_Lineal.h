//******************************************************************
//
//	Ecuacion_Lineal.h
//
//  Define la clases LU con sus atributos y funciones. 
//
//	Autor: Berta
//	fecha: 3/05/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef ECUACION_LINEAL_H
#define ECUACION_LINEAL_H

#include "DMatrizMath.h"
#include "DVectorMath.h"
#include "LU.h"

class Ecuacion_Lineal
{
	int m_orden;
	int m_desplazamiento;
	DMatrizMath<double> m_A;
	DVectorMath<double> m_x;
	DVectorMath<double> m_c;
	LU m_LU;

public:

	Ecuacion_Lineal (void);
	Ecuacion_Lineal (int orden, int desplazamiento = 1);
	Ecuacion_Lineal (DMatrizMath<double> A, DVectorMath<double> c);
	// Este constructor resulta útil cuando queremos resolver sistemas de
	// ecuaciones con la misma matriz de coeficientes pero distintos términos
	// independientes.
	Ecuacion_Lineal (DMatrizMath<double> A);
	void SetAtributos (int orden, int desplazamiento);
	void factorizar (void);
	DVectorMath<double>& resolver (DMatrizMath<double> A, DVectorMath<double> c);
	DVectorMath<double>& resolver (void);
	// esta función se utiliza para resolver diferentes sistemas que comparten
	// la misma matriz de coeficientes, pero con distinto término independiente.
	DVectorMath<double>& resolver (DVectorMath<double> c);
	void sustitucion_regresiva (void);

};

#endif ECUACION_LINEAL_H