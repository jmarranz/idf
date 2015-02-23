//******************************************************************
//
//	DMatriz.cpp
//
//  Contiene las funciones de la clase DMatriz.
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#include "stdafx.h"
#include "DMatriz.h"


////////////////////////////////////////////////////////////
//
// Constructor.
//
////////////////////////////////////////////////////////////

template<class typo>
DMatriz<typo>::DMatriz (int orden, int desplazamiento)
{
	SetAtributos(orden, desplazamiento);
}

////////////////////////////////////////////////////////////
//
//  Constructor copia
//
////////////////////////////////////////////////////////////

template<class typo>
DMatriz<typo>::DMatriz (const DMatriz<typo> &mi_matriz)
{
	int orden = mi_matriz.GetSize();
	int desplazamiento = mi_matriz.GetDesplazamiento(); 
	SetAtributos(orden, desplazamiento);

	// copia uno a uno todos los elemento de la matriz
	for (int i=m_desplazamiento ; i < (m_orden + m_desplazamiento) ; i++)
	{
		for (int j=m_desplazamiento ; j < (m_orden + m_desplazamiento) ; j++)
		{
			(*this)[i][j] = mi_matriz[i][j];
		}
	}
}

////////////////////////////////////////////////////////////
//
//  Serialización de la matriz
//
////////////////////////////////////////////////////////////
/*
template<class typo>
void DMatriz<typo>::Serialize(CArchive &ar)
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
*/

////////////////////////////////////////////////////////////
//
//  Operador =:
//
////////////////////////////////////////////////////////////

template<class typo>
DMatriz<typo> &DMatriz<typo>::operator=(const DMatriz<typo> &mi_matriz)
{
	
	int orden = mi_matriz.GetSize();
	int desplazamiento = mi_matriz.GetDesplazamiento(); 
	SetAtributos(orden, desplazamiento);

	// copia uno a uno todos los elemento de la matriz
	for (int i=m_desplazamiento ; i < (m_orden + m_desplazamiento) ; i++)
	{
		for (int j=m_desplazamiento ; j < (m_orden + m_desplazamiento) ; j++)
		{
			(*this)[i][j] = mi_matriz[i][j];
		}
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
DVector<typo> &DMatriz<typo>::operator[](int indice)
{
	ASSERT( indice >= m_desplazamiento && indice < (m_orden + m_desplazamiento) );
	return m_matriz.ElementAt(indice);
}

template<class typo>
DVector<typo> DMatriz<typo>::operator[](int indice) const
{
	ASSERT( indice >= m_desplazamiento && indice < (m_orden + m_desplazamiento) );
	return m_matriz.GetAt(indice);
}

////////////////////////////////////////////////////////////
//
// Función que devuelve una referencia al "CArray" de la matriz.
// La ventaja que tiene es que al llamarla seguida de dobles corchetes
// [i][j] da directamente acceso al double que tiene esos indices.
//
////////////////////////////////////////////////////////////

template<class typo>
DVector<DVector<typo> > &DMatriz<typo>::GetMatriz (void)
{
	return m_matriz;
}


////////////////////////////////////////////////////////////
//
// Funciones que acceden al elemento de la matriz.No es mas que 
// una alternativa al uso de la anterior función.Pueden devolver
// o bien una copia del double o bien una referencia al double.
//
////////////////////////////////////////////////////////////

template<class typo>
void DMatriz<typo>::SetAt (int fila, int columna, typo elemento)
{
	m_matriz[fila].SetAt(columna, elemento);
}

template<class typo>
typo DMatriz<typo>::GetAt (int fila, int columna) const
{
	return m_matriz.GetAt(fila).GetAt(columna);
}

template<class typo>
typo &DMatriz<typo>::ElementAt (int fila, int columna)
{
	return  m_matriz[fila].ElementAt(columna);
}

template<class typo>
int DMatriz<typo>::GetSize (void) const
{
	return m_orden;
}

template<class typo>
void DMatriz<typo>::SetSize (int orden)
{
	m_orden = orden;
	m_matriz.SetSize(m_orden);
	for (int i=m_desplazamiento; i< (m_orden + m_desplazamiento); i++)
	{
		m_matriz[i].SetSize(m_orden);
	}
}


////////////////////////////////////////////////////////////
//
// Funciones SetDesplazamiento y GetDesplazamiento
//
////////////////////////////////////////////////////////////

template<class typo>
void DMatriz<typo>::SetDesplazamiento (int desplazamiento)
{
	m_desplazamiento = desplazamiento;
	m_matriz.SetDesplazamiento(m_desplazamiento);
	for (int i=m_desplazamiento; i< (m_orden + m_desplazamiento); i++)
	{
		m_matriz[i].SetDesplazamiento(m_desplazamiento);
	}
}

template<class typo>
int DMatriz<typo>::GetDesplazamiento (void) const
{
	return m_desplazamiento;
}


////////////////////////////////////////////////////////////
//
// Función SetAtributos
//
////////////////////////////////////////////////////////////

template<class typo>
void DMatriz<typo>::SetAtributos (int orden, int desplazamiento)
{
	m_orden = orden;
	m_desplazamiento = desplazamiento;

	m_matriz.SetSize(m_orden);
	m_matriz.SetDesplazamiento(m_desplazamiento);

	SetDesplazamiento(m_desplazamiento);
	SetSize(m_orden);
}

/*
template<class typo>
void DMatriz<typo>::Dump(CDumpContext &cd) const
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
// Instanciaciones
//
////////////////////////////////////////////////////////////

//¡¡¡IMPORTANTE!!!
//Esta instanciación es necesaria para que el compilador tenga 
//constancia de los tipos de datos que van a entrar por el template.
template class DMatriz<double>;
template class DMatriz<int>;