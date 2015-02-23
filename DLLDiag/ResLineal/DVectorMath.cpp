//******************************************************************
//
//	DVectorMath.cpp
//
//  Contiene las funciones de la clase DVectorMath.
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"
#include "DVectorMath.h"
#include <math.h>


////////////////////////////////////////////////////////////
//
// Constructor y constructor de copia.
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo>::DVectorMath(int orden, int desplazamiento): DVector<typo> (orden,desplazamiento)
{
	*this = 0;
};


template<class typo>
DVectorMath<typo>::DVectorMath(const DVectorMath<typo> &mi_vector)
{
	int orden = mi_vector.GetSize();
	int desplazamiento = mi_vector.GetDesplazamiento();
	SetAtributos(orden, desplazamiento);

	// copia uno a uno todos los elemento de la matriz
	for (int i=desplazamiento ; i< (orden + desplazamiento) ; i++)
	{
		(*this)[i] = mi_vector[i];
	}
};


////////////////////////////////////////////////////////////
//
// Operador de asignación
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> &DVectorMath<typo>::operator=(const DVectorMath<typo> &mi_vector)
{
	int orden = mi_vector.GetSize();
	int desplazamiento = mi_vector.GetDesplazamiento();
	SetAtributos (orden, desplazamiento);

	// copia uno a uno todos los elemento del vector
	for (int i=m_desplazamiento ; i < (m_orden + m_desplazamiento) ; i++)
	{
		(*this)[i] = mi_vector[i];
	}
	
	return *this;
};
/*
template<class typo>
void DVectorMath<typo>::Serialize(CArchive &ar)

//	DVector<typo>::Serialize(ar);

{
	CObject::Serialize(ar);
//	m_vector.Serialize(ar);
	if (ar.IsStoring() )
	{
		ar.WriteCount(m_orden);
//		m_vector.Serialize(ar);
//		ar << m_orden << m_desplazamiento;		
	}
	else
	{
		DWORD nOldSize = ar.ReadCount();
		SetSize(nOldSize);
	}
//		ar >> m_orden >> m_desplazamiento;
	
	Serialize_DVector<typo>(ar, this, m_orden);
}
*/

////////////////////////////////////////////////////////////
//
//  Operador = : asiganar a todas las componentes el valor de un 
//  factor entero.
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> &DVectorMath<typo>::operator=(int factor)
{
	int i;
	for (i=GetDesplazamiento(); i < (GetSize() + GetDesplazamiento()); i++)
	{
		(*this)[i] = factor;
	}
	return *this;
}

////////////////////////////////////////////////////////////
//
// Operador +.
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DVectorMath<typo>::operator+(const DVectorMath<typo> &vector2)
{
	ASSERT( vector2.GetSize() == m_orden );
	ASSERT( vector2.GetDesplazamiento() == m_desplazamiento );

	DVectorMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		temp[i] = (*this)[i] + vector2[i];
	};

	return temp;

};

////////////////////////////////////////////////////////////
//
// Operador -.
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DVectorMath<typo>::operator-(const DVectorMath<typo> &vector2)
{
	ASSERT( vector2.GetSize() == m_orden );
	ASSERT( vector2.GetDesplazamiento() == m_desplazamiento );

	DVectorMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		temp[i] = (*this)[i] - vector2[i];
	};

	return temp;
};

////////////////////////////////////////////////////////////
//
// Operador *:
//
////////////////////////////////////////////////////////////

template<class typo>
typo DVectorMath<typo>::operator*(const DVectorMath<typo> &vector2)
{
	ASSERT( vector2.GetSize() == m_orden );
	ASSERT( vector2.GetDesplazamiento() == m_desplazamiento );

	typo temp = 0;

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		temp += (*this)[i] * vector2[i];
	}

	return temp;

};

////////////////////////////////////////////////////////////
//
// Operador multiplicar factor por vector : *.
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> operator*(typo factor,const DVectorMath<typo> &vector)
{
	int orden = vector.GetSize();
	int desplazamiento = vector.GetDesplazamiento();
	DVectorMath<typo> temp(orden, desplazamiento);

	for (int i= desplazamiento;  i < (orden + desplazamiento); i++){
		temp[i] = factor * vector[i];
	}

	return temp;

}

////////////////////////////////////////////////////////////
//
// Operador multiplicar vector por factor : *.
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DVectorMath<typo>::operator*(typo factor)
{

	DVectorMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		temp[i] = (*this)[i] * factor;
	};

	return temp;

}

////////////////////////////////////////////////////////////
//
// Operador Dividir vector por factor : /.
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DVectorMath<typo>::operator/(typo factor)
{

	DVectorMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		temp[i] = (*this)[i] / factor;
	};

	return temp;

}
////////////////////////////////////////////////////////////
//
// Operador comparación de igualdad : ==.
//
////////////////////////////////////////////////////////////

template<class typo>
BOOL DVectorMath<typo>::operator==(const DVectorMath<typo> &vector2)
{

	BOOL temp;
	temp = ((vector2.GetSize() == m_orden) && (vector2.GetDesplazamiento() == m_desplazamiento));

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++){
		temp = ( ( (*this)[i] == vector2[i] ) && temp );
	}

	return temp;

};


////////////////////////////////////////////////////////////
//
// Operador comparación de no igualdad : !=.
//
////////////////////////////////////////////////////////////

template<class typo>
BOOL DVectorMath<typo>::operator!=(const DVectorMath<typo> &vector2)
{
	return !(*this == vector2);
	
};

////////////////////////////////////////////////////////////
//
// Operador +=: suma el vector que la llama con el vector que se
// le da por parámetros y la almacena en el primero
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DVectorMath<typo>::operator+=(const DVectorMath<typo> &vector2)
{
	ASSERT( vector2.GetSize() == m_orden );
	ASSERT( vector2.GetDesplazamiento() == m_desplazamiento );

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		(*this)[i] += vector2[i];

	};
	return *this;
}

////////////////////////////////////////////////////////////
//
// Operador -=: resta el vector que la llama con el vector que se
// le da por parámetros y la almacena en el primero
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DVectorMath<typo>::operator-=(const DVectorMath<typo> &vector2)
{
	ASSERT( vector2.GetSize() == m_orden );
	ASSERT( vector2.GetDesplazamiento() == m_desplazamiento );

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		(*this)[i] -= vector2[i];
	};
	return *this;
}

////////////////////////////////////////////////////////////
//
// Operador - (unario): Cambia el signo del vector
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorMath<typo> DVectorMath<typo>::operator-(void)
{
	DVectorMath<typo> temp(m_orden, m_desplazamiento);

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		temp[i] = -(*this)[i];
	};

	return temp;

}


////////////////////////////////////////////////////////////
//
// Operador << de salida de flujo.
//
////////////////////////////////////////////////////////////


template<class typo>
std::ostream &operator<<(std::ostream &flujo, DVectorMath<typo> mi_vector)
{
	int desplazamiento = mi_vector.GetDesplazamiento();
	int orden = mi_vector.GetSize();

	for (int i= desplazamiento;  i < (orden + desplazamiento); i++)
	{
		flujo << mi_vector[i] << "\t";
	}
	flujo << "\n";

	return flujo;

}


////////////////////////////////////////////////////////////
//
// función norma : Calcula el cuadrado del módulo del vector
//
////////////////////////////////////////////////////////////

template<class typo>
typo DVectorMath<typo>::norma(void)
{
	typo temp = 0;

	for (int i= m_desplazamiento;  i < (m_orden + m_desplazamiento); i++)
	{
		temp += (*this)[i] * (*this)[i] ;
	};

	return temp;

}

////////////////////////////////////////////////////////////
//
// función modulo : Calcula el módulo del vector
//
////////////////////////////////////////////////////////////

template<class typo>
double DVectorMath<typo>::modulo(void)
{
	return sqrt( (double)norma() );
}


////////////////////////////////////////////////////////////
//
// Instanciaciones de la clase template.
//
////////////////////////////////////////////////////////////

//¡¡¡IMPORTANTE!!!
//Esta instanciación es necesaria para que el compilador tenga 
//constancia de los tipos de datos que van a entrar por el template.
template class DVectorMath<double>;
template class DVectorMath<int>;

// Las funciones amigas, al no ser miembros de la clase, necesitan también instanciación
template DVectorMath<double> operator*(double factor, const DVectorMath<double> &vector);
template DVectorMath<int> operator*(int factor, const DVectorMath<int> &vector);

template std::ostream &operator<< (std::ostream &flujo, DVectorMath<double> );
template std::ostream &operator<< (std::ostream &flujo, DVectorMath<int> );