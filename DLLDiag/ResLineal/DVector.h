//******************************************************************
//
//	DVector.h
//
//  Define la clase vector algebraico template de double o int y las funciones
//  para acceder a los elementos de la matriz.
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef DVECTOR_H
#define DVECTOR_H

#include "Utilidades.h"

template<class typo>
class DVector : public CObject 
{
// ponemos atributos protegidos en lugar de privados para que las clases
// derivadas puedan acceder a ellos.

private:

	CArray<typo,typo> m_vector;

protected:

	int m_orden;
	int m_desplazamiento;

public:

	DVector (int orden = 1, int desplazamiento = 1);
	DVector (const DVector &mi_vector);
	virtual void Serialize(CArchive &ar);

	// operador de asignación: =
	DVector<typo> &operator=(const DVector <typo> &mi_vector);

	// operador para acceder a un elemento por su índice: []
	typo operator[](int nIndex) const;
	typo &operator[](int nIndex);
	//void Copy (int inicio, int fin, DVector<typo> &destino);

	//Función para acceder al vector
	CArray<typo,typo> &GetVector (void);
	
	//Función para introducir un valor de otra manera:
	//  mi_vector.SetAt(1,17);		
	void SetAt(int indice, typo elemento);

	typo GetAt (int indice) const;

	//esta función devuelve un puntero al typo de la posición que se le marca:
	// mi_vector.ElementAt(1) 
	typo &ElementAt (int indice);

	// Esta función devuelve el tamaño del vector
	int GetSize (void) const;

	// Esta función modifica el tamaño del vector
	void SetSize (int orden);

	void SetDesplazamiento (int desplazamiento);

	int GetDesplazamiento (void) const;

	void SetAtributos (int orden, int desplazamiento);

	//	void Dump(CDumpContext &cd) const;
};


template<class typo>
void AFXAPI Serialize_DVector(CArchive &ar,DVector<typo> *p_vector,int orden)
{
//	p_vector->GetVector().
	SerializeElements(ar, p_vector->GetVector().GetData(),orden);
	if (ar.IsStoring())
	{
		ar << (WORD)p_vector->GetDesplazamiento();
	}
	else
	{
		WORD w1;
		ar >> w1;
		p_vector->SetDesplazamiento((int) w1);
	}
}


#endif DVECTOR_H
