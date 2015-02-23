//******************************************************************
//
//	DVectorObj.cpp
//
//  Contiene las funciones de la clase DVectorObj
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"
#include "DVectorObj.h"
#include "DVectorMath.h"


////////////////////////////////////////////////////////////
//
// Constructor
//
////////////////////////////////////////////////////////////

template<class typo>
DVectorObj<typo>::DVectorObj(int orden, int desplazamiento)
{
	m_orden = orden;
	m_desplazamiento = desplazamiento;
	CObArray::SetSize(m_orden);

}


////////////////////////////////////////////////////////////
//
// Función para serializar
//
////////////////////////////////////////////////////////////

template<class typo>
void DVectorObj<typo>::Serialize(CArchive &ar)
{
	CObArray::Serialize(ar);
	if (ar.IsStoring() )
	{
		ar << (WORD)m_orden << (WORD)m_desplazamiento;		
	}
	else
	{
		WORD w1,w2;
		ar >> w1 >> w2;
		m_orden = (int)w1;
		m_desplazamiento = (int)w2;

	}
}



////////////////////////////////////////////////////////////
//
// Funciones GetSize y SetSize
//
////////////////////////////////////////////////////////////

template<class typo>
int DVectorObj<typo>::GetSize (void) const
{
	return m_orden;
}

template<class typo>
void DVectorObj<typo>::SetSize (int orden)
{
	m_orden = orden;
	CObArray::SetSize(m_orden); 
}


////////////////////////////////////////////////////////////
//
// Funciones GetDesplazamientop y SetDesplazamiento
//
////////////////////////////////////////////////////////////

template<class typo>
void DVectorObj<typo>::SetDesplazamiento (int desplazamiento)
{
	m_desplazamiento = desplazamiento;
}

template<class typo>
int DVectorObj<typo>::GetDesplazamiento (void) const
{
	return m_desplazamiento;
}


////////////////////////////////////////////////////////////
//
// Función SetAtributos
//
////////////////////////////////////////////////////////////

template<class typo>
void DVectorObj<typo>::SetAtributos (int orden, int desplazamiento)
{
	m_orden = orden;
	m_desplazamiento = desplazamiento;

	SetDesplazamiento(m_desplazamiento);
	SetSize(m_orden);
}


////////////////////////////////////////////////////////////
//
// Instanciaciones necesarias para esta clase template
//
////////////////////////////////////////////////////////////

template class DVectorObj<Vector_3D*>;
template class DVectorObj<Fuerza*>;
template class DVectorObj<CObject*>;
template class DVectorObj<Ligadura*>;
template class DVectorObj<Masa_Primaria*>;
template class DVectorObj<Vector_3D_Secundario*>;
template class DVectorObj<Elemento*>;
template class DVectorObj<Junta*>;

template class DVectorObj<DVectorMath<double>* >;
template class DVectorObj<DVectorMath<int>* >;

