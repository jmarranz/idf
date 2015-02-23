//******************************************************************
//
//	Ecuacion_Lineal.cpp
//
//  Implementa las funciones de la clase Ecuacion_Lineal
//
//	Autor: Berta
//	fecha: 3/05/99
//
//  Modifications----->
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"
#include <iostream>
#include "Ecuacion_Lineal.h"

Ecuacion_Lineal::Ecuacion_Lineal (void)
{
};

Ecuacion_Lineal::Ecuacion_Lineal (int orden, int desplazamiento)
{
	SetAtributos(orden, desplazamiento);
};


Ecuacion_Lineal::Ecuacion_Lineal 
	(DMatrizMath<double> A, DVectorMath<double> c) : m_LU (A)
{
	ASSERT( A.GetSize() == c.GetSize());

	m_A = A;
	m_orden = m_A.GetSize();
	m_desplazamiento = m_A.GetDesplazamiento();
	m_c = c;
	
	m_x.SetAtributos(m_orden, m_desplazamiento);
};

Ecuacion_Lineal::Ecuacion_Lineal 
	(DMatrizMath<double> A) : m_LU (A)
{
	m_A = A;
	m_orden = m_A.GetSize();
	m_desplazamiento = m_A.GetDesplazamiento();
	
	m_x.SetAtributos(m_orden, m_desplazamiento);
	factorizar();
};

void Ecuacion_Lineal::SetAtributos (int orden, int desplazamiento)
{
	m_orden = orden;
	m_desplazamiento = desplazamiento;
	m_A.SetAtributos(orden, desplazamiento);
	m_c.SetAtributos(orden, desplazamiento);
	m_x.SetAtributos(orden, desplazamiento);
	m_LU.SetAtributos(orden, desplazamiento);
};

void Ecuacion_Lineal::factorizar (void)
{
	m_LU = m_A;
	m_LU.factorizar();
}

DVectorMath<double>& Ecuacion_Lineal::resolver (DMatrizMath<double> A, DVectorMath<double> c)
{
	ASSERT( A.GetSize() == c.GetSize());
	ASSERT( A.GetDesplazamiento() == c.GetDesplazamiento());

	SetAtributos( c.GetSize(), c.GetDesplazamiento() );
	
	m_A = A;
	m_c = c;

	return resolver();
}

DVectorMath<double>& Ecuacion_Lineal::resolver (void)
{
	//m_LU = m_A;
	//m_LU.factorizar();
	factorizar();
	sustitucion_regresiva();

	return m_x;
}

DVectorMath<double>& Ecuacion_Lineal::resolver (DVectorMath<double> c)
{

	ASSERT( c.GetSize() == m_orden);
	ASSERT( c.GetDesplazamiento() == m_desplazamiento);

	m_c = c;

	sustitucion_regresiva();

	return m_x;
}

void Ecuacion_Lineal::sustitucion_regresiva (void)
{
	int i, j, k;
	DVectorMath<double> temp = m_c;


	for (i= m_desplazamiento + 1;  i < (m_orden + m_desplazamiento); i++){
		for (j= m_desplazamiento;  j < i; j++){
			temp[i] = temp[i] - m_LU[i][j]*temp[j];
		}
	}

	temp[m_orden + m_desplazamiento -1] = 
		temp[m_orden + m_desplazamiento -1] / 
		m_LU[m_orden + m_desplazamiento -1][m_orden + m_desplazamiento -1];

	for (i= m_desplazamiento;  i < (m_orden + m_desplazamiento -1); i++){
		k = m_orden + 2*(m_desplazamiento - 1) - i;
		for (j=k+1; j < (m_orden + m_desplazamiento); j++){
			temp[k] = temp[k] - m_LU[k][j]*temp[j];
		}
		temp[k] = temp[k] / m_LU[k][k];
	}

	for (i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		int indice = m_LU.get_indice_permutacion()[i];
		m_x[indice] = temp[i];
	}

}
