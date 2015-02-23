//******************************************************************
//
//	DVector.cpp
//
//  Contiene las funciones de la clase DVector.
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"
#include "DVector.h"

////////////////////////////////////////////////////////////
//
// Constructor.
//
////////////////////////////////////////////////////////////

template<class typo>
DVector<typo>::DVector (int orden, int desplazamiento)
{
	
	SetAtributos(orden, desplazamiento);
}

////////////////////////////////////////////////////////////
//
//  Constructor copia
//
////////////////////////////////////////////////////////////

template<class typo>
DVector<typo>::DVector (const DVector<typo> &mi_vector)
{
	int orden = mi_vector.GetSize();
	int desplazamiento = mi_vector.GetDesplazamiento();
	SetAtributos(orden, desplazamiento);

	// copia uno a uno todos los elemento de la matriz
	for (int i=m_desplazamiento ; i< (m_orden + m_desplazamiento) ; i++)
	{
		(*this)[i] = mi_vector[i];
	}
}


////////////////////////////////////////////////////////////
//
// Función serializar.
//
////////////////////////////////////////////////////////////

template<class typo>

void DVector<typo>::Serialize(CArchive &ar)
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


////////////////////////////////////////////////////////////
//
//  Operador = 
//
////////////////////////////////////////////////////////////

template<class typo>
DVector<typo> &DVector<typo>::operator=(const DVector<typo> &mi_vector)
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


////////////////////////////////////////////////////////////
//
// Operador [] para poder llamar a los elementos de la matriz
// mediante dos índices, pues este operador devuelve un
// CArray, y a continuación puede llamarse al operador [] del
// CArray, pudiendo así emplearse los dos seguidos: [][]
//
////////////////////////////////////////////////////////////

template<class typo>
typo &DVector<typo>::operator[](int indice)
{
	ASSERT( indice >= m_desplazamiento && indice < (m_orden + m_desplazamiento) );
	return m_vector.ElementAt(indice - m_desplazamiento);
}

template<class typo>
typo DVector<typo>::operator[](int indice) const
{
	ASSERT( indice >= m_desplazamiento && indice < (m_orden + m_desplazamiento) );
	return m_vector.GetAt(indice - m_desplazamiento);
}

// Copia en destino los elementos del vector apuntado por this que están
// comprendidos entre los índices inicio y fin
/*template<class typo>
void DVector<typo>::Copy
	(int inicio, int fin, DVector<typo> &destino)
{
	
	//int orden = (fin - inicio) + 1;
	//int desplazamiento = m_desplazamiento;

	int orden = destino.GetSize();
	int desplazamiento = destino.GetDesplazamiento();

	int indice = inicio;
	for (int i=desplazamiento ; i< (orden + desplazamiento) ; i++)
	{
		destino[i] = (*this)[indice];
		indice++;
	}

}*/

////////////////////////////////////////////////////////////
//
// Función que devuelve una referencia al "CArray" de la matriz.
// La ventaja que tiene es que al llamarla seguida de dobles corchetes
// [i][j] da directamente acceso al double que tiene esos indices.
//
////////////////////////////////////////////////////////////

template<class typo>
CArray<typo,typo> &DVector<typo>::GetVector (void)
{
	return m_vector;
}

/*
template<class typo>
CArray<typo,typo> *DVector<typo>::GetData (void)
{
	return &m_vector;
}
*/
/*
CObject **DVector::GetData(void)
{
	return m_vector.GetData();
}
*/

////////////////////////////////////////////////////////////
//
// Funciones que acceden al elemento de la matriz.No es mas que 
// una alternativa al uso de la anterior función.Pueden devolver
// o bien una copia del double o bien una referencia al double.
//
////////////////////////////////////////////////////////////


template<class typo>
void DVector<typo>::SetAt (int indice, typo elemento)
{
	m_vector.SetAt(indice - m_desplazamiento, elemento);
}

template<class typo>
typo DVector<typo>::GetAt (int indice) const
{
	return m_vector.GetAt(indice - m_desplazamiento);
}

template<class typo>
typo &DVector<typo>::ElementAt (int indice)
{
	return  m_vector.ElementAt(indice - m_desplazamiento);
}

template<class typo>
int DVector<typo>::GetSize (void) const
{
	return m_orden;
}

template<class typo>
void DVector<typo>::SetSize (int orden)
{
	m_orden = orden;
	m_vector.SetSize(orden);
}
//******************************************************
template<class typo>
void DVector<typo>::SetDesplazamiento (int desplazamiento)
{
	m_desplazamiento = desplazamiento;
}

template<class typo>
int DVector<typo>::GetDesplazamiento (void) const
{
	return m_desplazamiento;
}

template<class typo>
void DVector<typo>::SetAtributos (int orden, int desplazamiento)
{
	m_orden = orden;
	m_desplazamiento = desplazamiento;

	SetDesplazamiento(m_desplazamiento);
	SetSize(m_orden);
}
//********************************************************
/*
template<class typo>
void Dmatriz<typo>::Dump(CDumpContext &cd) const
{
	ASSERT_VALID (this);
	
	dc << "-un(a) " << GetRuntimeClass()->m_lpszClassName << " ";
	if (dc.GetDepth() > 1)
	{
		dc << " en (" << (void*)this << ") ";
	}
	dc << "de orden " << m_orden ;

	if (dc.GetDepth() > 0)
	{
		for (int i=0 ; i < m_orden; i++)
		{
			for (int j=0 ; j < m_orden ; j++)
			{
				dc << "\t[" << i << ',' << j << "] = " << m_matriz (i,j);
			};
			dc << "\n";
		}
	}

	dc << "\n";
}
*/


////////////////////////////////////////////////////////////
//
// Instanciaciones.
//
////////////////////////////////////////////////////////////

//¡¡¡IMPORTANTE!!!
//Esta instanciación es necesaria para que el compilador tenga 
//constancia de los tipos de datos que van a entrar por el template.
template class DVector<double>;
template class DVector<int>;
//template class DVector<Vector_3D>;

template class DVector<DVector<double> >;
template class DVector<DVector<int> >;
//template class DVector<DVector<Vector_3D> >;