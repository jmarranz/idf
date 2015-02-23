//******************************************************************
//
//	DVectorObj.h
//
//  Define la clase vector de punteros a objeto
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef DVECTOROBJ_H
#define DVECTOROBJ_H

#include "Utilidades.h"

class Ligadura;
class Masa_Primaria;
class Fuerza;
class Vector_3D;
class Vector_3D_Secundario;
class Elemento;
class Junta;

template<class TYPE>
class DVectorObj : public CObArray
{
	int m_desplazamiento;
	int m_orden;
public:

	DVectorObj(int orden = 1, int desplazamiento = 1);

	void SetSize (int orden);

	int GetSize (void) const;

	void SetDesplazamiento (int desplazamiento);

	int GetDesplazamiento (void) const;

	void SetAtributos (int orden, int desplazamiento);

	// Accessing elements
	TYPE GetAt(int indice) const
		{ return (TYPE)CObArray::GetAt(indice - m_desplazamiento); }
	TYPE& ElementAt(int indice)
		{ return (TYPE&)CObArray::ElementAt(indice - m_desplazamiento); }
	void SetAt(int indice, TYPE ptr)
		{ CObArray::SetAt(indice - m_desplazamiento,(CObject*)ptr); }

	// Potentially growing the array
	void SetAtGrow(int indice, TYPE newElement)
	   { CObArray::SetAtGrow(indice - m_desplazamiento,(CObject*) newElement); }
	int Add(TYPE newElement)
	   { return CObArray::Add((CObject*)newElement); }
	int Append(const DVectorObj<TYPE>& src)
	   { return (CObArray::Append(src)) + m_desplazamiento; }
	void Copy(const DVectorObj<TYPE>& src)
		{ 
			m_orden = src.m_orden;
			m_desplazamiento = src.m_desplazamiento;
			CObArray::Copy(src); 
		}

	// Operations that move elements around
	void InsertAt(int indice, TYPE newElement, int nCount = 1)
		{ CObArray::InsertAt(indice - m_desplazamiento,(CObject*) newElement, nCount); }
	void InsertAt(int nStartIndex, DVectorObj<TYPE>* pNewArray)
	   { CObArray::InsertAt(nStartIndex - m_desplazamiento, pNewArray); }

	// overloaded operator helpers
	TYPE operator[](int indice) const
		{ return (TYPE)CObArray::operator[](indice - m_desplazamiento); }
	TYPE& operator[](int indice)
		{ return (TYPE&)CObArray::operator[](indice - m_desplazamiento); }
	void Serialize(CArchive &ar);
};



#endif DVECTOROBJ_H
