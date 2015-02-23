//******************************************************************
//
//	MatrizMath.h
//
//  Define la clases LU con sus atributos y funciones. 
//
//	Autor: Jorge
//	fecha:
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef MATRIZMATH_H
#define MATRIZMATH_H

#include "DMatriz.h"
#include "DVectorMath.h"

template <class typo>
class DMatrizMath : public DMatriz<typo>
{

public:
	DMatrizMath (int orden = 1, int desplazamiento = 1);
	DMatrizMath (const DMatrizMath &mi_matriz);

	void Serialize(CArchive &ar);

	// sobrecarga del operador de extracción
	friend std::ostream &operator<<(std::ostream &flujo, DMatrizMath<typo> mi_matriz);

	//sobrecarga del igual para asignar un valor a todas las posiciones de una matriz
	DMatrizMath<typo> &operator=(int factor);

	// operador suma de matrices : +.
	DMatrizMath<typo> operator+(const DMatrizMath<typo> &matriz2);

	// operador diferencia de matrices : -.
	DMatrizMath<typo> operator-(const DMatrizMath<typo> &matriz2);

	// operador producto de matrices : *.
	DMatrizMath<typo> operator*(const DMatrizMath<typo> &matriz2);

	// operador producto de una matriz por un vector : *.
	DVectorMath<typo> operator*(const DVectorMath<typo> &vector);

	// operador producto de un vector por una matriz: *
	friend DVectorMath<typo> operator*(const DVectorMath<typo> &vector, const DMatrizMath<typo> &matriz);

	// operador producto de un matriz por un factor: *
	DMatrizMath<typo> operator*(typo factor);

	// operador producto de un factor por una matriz: *
	friend DMatrizMath<typo> operator*(typo factor,const DMatrizMath<typo> &matriz);

	// operadores de comparación
	BOOL operator==(const DMatrizMath<typo> &matriz2);
	BOOL operator!=(const DMatrizMath<typo> &matriz2);

	// operadores incremento, +=, y decremento, -=
	DMatrizMath<typo> operator+=(const DMatrizMath<typo> &matriz2);
	DMatrizMath<typo> operator-=(const DMatrizMath<typo> &matriz2);

	// operador de signo
	DMatrizMath<typo> operator-(void);

};


template<class typo>
void AFXAPI Serialize_DVector(CArchive &ar,DVector<typo> *p_vector,int orden);


template<class typo>
void AFXAPI Serialize_DMatriz(CArchive &ar,DMatriz<typo> *p_matriz,int orden)
{
	for (int i = 1; i <= orden ; i++)
	{
		Serialize_DVector<typo>(ar, &(*p_matriz)[i],orden);
	}

	if (ar.IsStoring())
	{
		ar << (WORD)p_matriz->GetDesplazamiento();
	}
	else
	{
		WORD w1;
		ar >> w1;
		p_matriz->SetDesplazamiento((int) w1);
	}
}


#endif MATRIZMATH_H
