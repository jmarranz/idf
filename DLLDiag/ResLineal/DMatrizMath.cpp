//******************************************************************
//
//	DMatrizMath.cpp
//
//  Contiene las funciones de la clase DMatrizMath.
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"
#include "DMatrizMath.h"


////////////////////////////////////////////////////////////
//
// Constructor y constructor copia.
//
////////////////////////////////////////////////////////////

template <class typo>
DMatrizMath<typo>::DMatrizMath (int orden, int desplazamiento) : DMatriz<typo>(orden,desplazamiento)
{
}

template <class typo>
DMatrizMath<typo>::DMatrizMath (const DMatrizMath &mi_matriz)
{
	int orden = mi_matriz.GetSize();
	int desplazamiento = mi_matriz.GetDesplazamiento(); 
	SetAtributos(orden, desplazamiento);

	// copia uno a uno todos los elemento de la matriz
	for (int i=m_desplazamiento ; i < (m_orden + m_desplazamiento) ; i++)
	{
		for (int j=m_desplazamiento ; j < (m_orden + m_desplazamiento) ; j++)
		{
			SetAt(i,j,mi_matriz.GetAt(i,j));
		}
	}
}


////////////////////////////////////////////////////////////
//
// Operador = de asiganción a todas las componentes el valor de
// un factor entero
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> &DMatrizMath<typo>::operator=(int factor)
{
	for (int i=GetDesplazamiento(); i < (GetSize()+ GetDesplazamiento()); i++)
	{
		for (int j=GetDesplazamiento(); j < (GetSize() + GetDesplazamiento()); j++)
		{
			SetAt(i,j,factor);
		}
	}
	return *this;
}

////////////////////////////////////////////////////////////
//
// Operador <<.
//
////////////////////////////////////////////////////////////

template<class typo>
std::ostream &operator<<(std::ostream &flujo, DMatrizMath<typo> mi_matriz)
{
	int desplazamiento = mi_matriz.GetDesplazamiento();
	int orden = mi_matriz.GetSize();

	for (int i= desplazamiento;  i < (orden + desplazamiento); i++)
	{
		for (int j= desplazamiento;  j < (orden + desplazamiento); j++)
		{
			flujo << mi_matriz[i][j] << "\t";
		}

		flujo << "\n";
	}
	flujo << "\n";

	return flujo;

}

////////////////////////////////////////////////////////////
//
// Operador +.
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> DMatrizMath<typo>::operator+(const DMatrizMath<typo> &matriz2)
{
	ASSERT( matriz2.GetSize() == m_orden );
	ASSERT( matriz2.GetDesplazamiento() == m_desplazamiento );

	DMatrizMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){

			temp[i][j] = (*this)[i][j] + matriz2[i][j];
		}
	}

	return temp;

};

////////////////////////////////////////////////////////////
//
// Operador -.
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> DMatrizMath<typo>::operator-(const DMatrizMath<typo> &matriz2)
{
	ASSERT( matriz2.GetSize() == m_orden );
	ASSERT( matriz2.GetDesplazamiento() == m_desplazamiento );

	DMatrizMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){
		
			temp[i][j] = (*this)[i][j] - matriz2[i][j];
		}
	}

	return temp;

};

////////////////////////////////////////////////////////////
//
// Operador *: producto de dos matrices
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> DMatrizMath<typo>::operator*(const DMatrizMath<typo> &matriz2)
{
	ASSERT( matriz2.GetSize() == m_orden );
	ASSERT( matriz2.GetDesplazamiento() == m_desplazamiento );

	DMatrizMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){

			temp[i][j] = 0;

			for (int k= m_desplazamiento;  k < (m_orden + m_desplazamiento); k++){
		
				temp[i][j] += (*this)[i][k] * matriz2[k][j];
			}
		}
	}

	return temp;

};

////////////////////////////////////////////////////////////
//
// Operador *: producto de una matriz por un vector
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DMatrizMath<typo>::operator*(const DVectorMath<typo> &vector)
{
	ASSERT( vector.GetSize() == m_orden );
	ASSERT( vector.GetDesplazamiento() == m_desplazamiento );

	DVectorMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		
		temp[i] = 0;
		
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){
		
			temp[i] += (*this)[i][j] * vector[j];

		}
	}

	return temp;

};

////////////////////////////////////////////////////////////
//
// Operador *: producto de un vector por una matriz
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> operator*(const DVectorMath<typo> &vector, const DMatrizMath<typo> &matriz)
{

	ASSERT( vector.GetSize() == matriz.GetSize() );
	ASSERT( vector.GetDesplazamiento() == matriz.GetDesplazamiento() );

	int desplazamiento = matriz.GetDesplazamiento();
	int orden = matriz.GetSize();

	DVectorMath<typo> temp(orden, desplazamiento);

	for (int i= desplazamiento;  i < (orden + desplazamiento); i++){
		
		temp[i] = 0;
		
		for (int j= desplazamiento;  j < (orden + desplazamiento); j++){
		
			temp[i] += vector[j] * matriz[j][i] ;

		}
	}

	return temp;

};

////////////////////////////////////////////////////////////
//
// Operador multiplicar matriz por factor : *.
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> DMatrizMath<typo>::operator*(typo factor)
{

	DMatrizMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){

			temp[i][j] = (*this)[i][j] * factor;
		}
	}


	return temp;

}

////////////////////////////////////////////////////////////
//
// Operador multiplicar factor por una matriz : *.
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> operator*(typo factor,const DMatrizMath<typo> &matriz)
{
	int orden = matriz.GetSize();
	int desplazamiento = matriz.GetDesplazamiento();
	DMatrizMath<typo> temp(orden, desplazamiento);

	for (int i= desplazamiento;  i < (orden + desplazamiento); i++){
		for (int j= desplazamiento;  j < (orden + desplazamiento); j++){
			temp[i][j] = factor * matriz[i][j];
		}
	}

	return temp;

}

////////////////////////////////////////////////////////////
//
// Operador comparación de igualdad : ==.
//
////////////////////////////////////////////////////////////

template<class typo>
BOOL DMatrizMath<typo>::operator==(const DMatrizMath<typo> &matriz2)
{

	BOOL temp;
	temp = ((matriz2.GetSize() == m_orden) && (matriz2.GetDesplazamiento() == m_desplazamiento));

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){

			temp = ( ( (*this)[i][j]==matriz2[i][j]) && temp );
		}
	}

	return temp;

};


////////////////////////////////////////////////////////////
//
// Operador comparación de no igualdad : !=.
//
////////////////////////////////////////////////////////////

template<class typo>
BOOL DMatrizMath<typo>::operator!=(const DMatrizMath<typo> &matriz2)
{
	return !(*this == matriz2);
	
};

////////////////////////////////////////////////////////////
//
// Operador +=: suma la matriz que la llama con la matriz que se
// le pasa por parámetros y la almacena en la primera de ellas
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> DMatrizMath<typo>::operator+=(const DMatrizMath<typo> &matriz2)
{
	ASSERT( matriz2.GetSize() == m_orden );
	ASSERT( matriz2.GetDesplazamiento() == m_desplazamiento );

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){
		
			(*this)[i][j] += matriz2[i][j];
		}
	}

	return *this;
}

////////////////////////////////////////////////////////////
//
// Operador -=: resta la matriz que la llama con la matriz que se
// le pasa por parámetros y la almacena en la primera de ellas
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> DMatrizMath<typo>::operator-=(const DMatrizMath<typo> &matriz2)
{
	ASSERT( matriz2.GetSize() == m_orden );
	ASSERT( matriz2.GetDesplazamiento() == m_desplazamiento );

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){
		
			(*this)[i][j] -= matriz2[i][j];
		}
	}

	return *this;
}

////////////////////////////////////////////////////////////
//
// Operador - (unario): Cambia el signo del vector
//
////////////////////////////////////////////////////////////

template<class typo>
DMatrizMath<typo> DMatrizMath<typo>::operator-(void)
{
	DMatrizMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		for (int j= m_desplazamiento;  j < (m_orden + m_desplazamiento); j++){
			
			temp[i][j] = -(*this)[i][j];
		}
	}

	return temp;

}

////////////////////////////////////////////////////////////
//
// Serialize
//
////////////////////////////////////////////////////////////

template<class typo>
void DMatrizMath<typo>::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring() )
	{
		ar.WriteCount(m_orden);
	}
	else
	{
		DWORD nOldSize = ar.ReadCount();
		SetSize(nOldSize);
	}

	
	Serialize_DMatriz<typo>(ar, this, m_orden);
}



////////////////////////////////////////////////////////////
//
// Instanciaciones
//
////////////////////////////////////////////////////////////

//¡¡¡IMPORTANTE!!!
//Esta instanciación es necesaria para que el compilador tenga 
//constancia de los tipos de datos que van a entrar por el template.
template class DMatrizMath<double>;
template class DMatrizMath<int>;

// Las funciones amigas, al no ser miembros de la clase, necesitan también instanciación
template DMatrizMath<double> operator*(double factor, const DMatrizMath<double> &matriz);
template DMatrizMath<int> operator*(int factor, const DMatrizMath<int> &matriz);

template DVectorMath<double> operator*(const DVectorMath<double> &vector, const DMatrizMath<double> &matriz);
template DVectorMath<int> operator*(const DVectorMath<int> &vector, const DMatrizMath<int> &matriz);

template std::ostream &operator<< (std::ostream &flujo, DMatrizMath<double> );
template std::ostream &operator<< (std::ostream &flujo, DMatrizMath<int> );

