//******************************************************************
//
//	LU.cpp
//
//  Implementa las funciones de la clase LU. 
//
//	Autor: Berta
//	fecha: 27/04/99
//
//  Modifications----->
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"

#include "LU.h"

//template<class tipo>
double LU::m_epsilon = EPSILON_LU;

LU::LU (void)
{
};

//template<class tipo>
LU::LU (int orden, int desplazamiento)
{
	SetAtributos(orden, desplazamiento);
};


//template<class tipo>
LU::LU (DMatrizMath<double> A)
{
	m_LU = A;
	m_orden = m_LU.GetSize();
	m_desplazamiento = m_LU.GetDesplazamiento();
	//m_indice_permutacion.SetSize(m_orden);
	m_indice_permutacion.SetAtributos(m_orden, m_desplazamiento);
};

//template<class tipo>
void LU::SetAtributos (int orden, int desplazamiento)
{
	m_orden = orden;
	m_desplazamiento = desplazamiento;
	m_LU.SetAtributos(m_orden, m_desplazamiento);
	m_indice_permutacion.SetAtributos(m_orden, m_desplazamiento);
};

DVector<double> &LU::operator[](int indice)
{
	return m_LU[indice];
}

DVector<double> LU::operator[](int indice) const
{
	return m_LU[indice];
}

//template<class tipo>
void LU::factorizar(void)
{
	int i, j, k;

	iniciar_indice_permutacion();

	int indice_pivote;
	double pivote;

	for (i=m_desplazamiento;  i < (m_orden + m_desplazamiento -1); i++){
		pivote = fabs(m_LU[i][i]);
		indice_pivote = i;
		// selecciona el pivote de mayor valor absoluto de la columna
		for (j=i+1;  j < (m_orden + m_desplazamiento); j++){
			if (fabs(m_LU[i][j]) > pivote){
				pivote = fabs(m_LU[i][j]);
				indice_pivote = j;
			}
		}

		// ASSERT( pivote >= m_epsilon );

		if (pivote < m_epsilon){

			std::cout << "pivote nulo" << std::endl;
			throw;
		}

		double temp;

		if (indice_pivote != i){
			k = m_indice_permutacion[i];
			m_indice_permutacion[i] = m_indice_permutacion[indice_pivote];
			m_indice_permutacion[indice_pivote] = k;
			for (j=m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){
				temp = m_LU[j][i];
				m_LU[j][i] = m_LU[j][indice_pivote];
				m_LU[j][indice_pivote] = temp;
			}
		}

		for (j=i+1;  j < (m_orden + m_desplazamiento); j++){
			m_LU[j][i] = m_LU[j][i]/m_LU[i][i];
			for (k=i+1;  k < (m_orden + m_desplazamiento); k++){
				m_LU[j][k]-=m_LU[j][i]*m_LU[i][k];
			}
		}
	}
};

DMatrizMath <double> LU::get_LU (void)
{
	return m_LU;
};

void LU::set_LU (DMatrizMath <double> A)
{
	m_LU = A;	
}

void LU::iniciar_indice_permutacion (void)
{
	for (int i=m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		m_indice_permutacion[i] = i;
	}
};

DVectorMath <int> LU::get_indice_permutacion (void)
{
	return m_indice_permutacion;
};

LU &LU::operator=(const DMatrizMath<double> &mi_matriz)
{
	m_LU = mi_matriz;
	m_orden = m_LU.GetSize();
	m_desplazamiento = m_LU.GetDesplazamiento();
	//m_indice_permutacion.SetSize(m_orden);
	m_indice_permutacion.SetAtributos(m_orden, m_desplazamiento);
	
	return *this;
};

/*DMatrizMath<double> &LU::operator=(const LU &mi_matriz_LU)
{
	return m_LU;
}*/
