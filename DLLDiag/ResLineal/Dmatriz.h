//******************************************************************
//
//	DMatriz.h
//
//  Define la clase matriz template de double o int y las funciones
//  para acceder a los elementos de la matriz.
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************#include "vector.h"

#ifndef DMATRIZ_H
#define DMATRIZ_H

#include "DVector.h"
#include "Utilidades.h"

template<class typo>
class DMatriz : public CObject 
{

private:

	DVector<DVector<typo> > m_matriz;

protected:

	int m_orden;
	int m_desplazamiento;

public:

	DMatriz (int orden = 1, int desplazamiento = 1);
	DMatriz (const DMatriz &mi_matriz);

	DMatriz<typo> &operator=(const DMatriz <typo> &mi_matriz);

	DVector<typo> &operator[](int nIndex);
	DVector<typo> operator[](int nIndex) const;

	DVector<DVector<typo> > &GetMatriz (void);
	
	//Función para introducir un valor de otra manera:
	//  mi_matriz.SetAt(0,1,17);		
	void SetAt (int fila, int columna, typo elemento); 

	typo GetAt (int fila, int columna) const;

	//esta función devuelve un puntero al typo de la posición que se le marca:
	// mi_matriz.ElementAt(1,1) 
	typo &ElementAt (int fila, int columna);

	int GetSize (void) const;

	// Esta función modifica el tamaño de la matriz
	void SetSize (int orden);

	void SetDesplazamiento (int desplazamiento);

	int GetDesplazamiento (void) const;

	void SetAtributos (int orden, int desplazamiento);

	//void Dump(CDumpContext &cd) const;

};


#endif DMATRIZ_H