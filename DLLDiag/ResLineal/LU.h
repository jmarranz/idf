//******************************************************************
//
//	LU.h
//
//  Define la clases LU con sus atributos y funciones. 
//
//	Autor: Berta
//	fecha: 27/04/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef LU_H
#define LU_H

#include "DMatrizMath.h"
#include "DVectorMath.h"
#include "definiciones.h"
#include "utilidades.h"

//template<class tipo>
class LU
{
	static double m_epsilon;
	int m_orden;
	int m_desplazamiento;
	DMatrizMath<double> m_LU;
	DVectorMath<int> m_indice_permutacion;

public:

	LU (void);
	LU (int orden, int desplazamiento = 1);
	LU (DMatrizMath<double> A);
	void SetAtributos (int orden, int desplazamiento);
	DVector<double> &operator[](int indice);
	DVector<double> operator[](int indice) const;
	void factorizar(void);
	DMatrizMath <double> get_LU (void);
	void set_LU (DMatrizMath <double> A);
	void iniciar_indice_permutacion (void);
	DVectorMath <int> get_indice_permutacion (void);

	LU &operator=(const DMatrizMath<double> &mi_matriz);
	//DMatrizMath<double> &operator=(const LU &mi_matriz_LU);
};

#endif LU_H