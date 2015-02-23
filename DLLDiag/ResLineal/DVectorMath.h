//******************************************************************
//
//	DVectorMath.h
//
//  Define las operaciones algebraicas de la clase clase vector algebraico
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef DVECTORMATH_H
#define DVECTORMATH_H

#include "DVector.h"

template <class typo>
class DVectorMath : public DVector<typo>
{

public:
	DVectorMath (int orden = 1, int desplazamiento = 1);
	DVectorMath (const DVectorMath &mi_vector);


	// sobrecarga del igual para asignar un valor a todas las posiciones de un vector
	DVectorMath<typo> &operator=(int factor);

	DVectorMath<typo> &operator=(const DVectorMath &mi_vector);

	// operador suma de vectores : +.
	DVectorMath<typo> operator+(const DVectorMath<typo> &vector2);

	// operador resta de vectores : -.
	DVectorMath<typo> operator-(const DVectorMath<typo> &vector2);

	// operador de producto escalar
	typo operator*(const DVectorMath<typo> &vector2);

	// operadores para multiplicar un escalar por un vector.
	friend DVectorMath<typo> operator*(typo factor,const DVectorMath<typo> &vector);
	DVectorMath<typo> operator*(typo factor);

	// operador para dividir un vector por un factor.
	DVectorMath<typo> operator/(typo factor);

	// operadores de comparación.
	BOOL operator==(const DVectorMath &vector2);
	BOOL operator!=(const DVectorMath &vector2);

	// operadores de incremento/decremento
	DVectorMath<typo> operator+=(const DVectorMath<typo> &vector2);
	DVectorMath<typo> operator-=(const DVectorMath<typo> &vector2);

	// operador de signo
	DVectorMath<typo> operator-(void);

	// operador de extraccion: <<
	friend std::ostream &operator<<(std::ostream &flujo, DVectorMath<typo> mi_vector);


	// calcula el cuadrado del módulo de un vector
	typo norma (void);

	// calcula el módulo de un vector
	double modulo (void);

};





#endif DVECTORMATH_H
