//******************************************************************
//
//	DVector.h
//
//  Define la clase flujos_ES, para salida de datos
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef FLUJOS_ES_H
#define FLUJOS_ES_H

#include <iostream>
#include "Utilidades.h"

//enum tipo_flujo {CONSOLA,FICHERO,DEBUGGER};

/*
class flujo
{
public :
	CDumpContext dc_consola;
	CDumpContext dc_fichero;
	enum tipo_flujo tipo;

	flujo(tipo_flujo tipo,int nivel_detalle);
};
*/

class flujo
{
	//enum tipo_flujo tipo;
	CStdioFile f_consola;
	CFile mi_fichero;

public :
	CDumpContext dc_consola;
	CDumpContext dc_fichero;

	//flujo(tipo_flujo tipo,int nivel_detalle, CString nombre_fichero = "fichero_dump.txt");//Constructor
	flujo(int nivel_detalle = 0, CString nombre_fichero = "fichero_dump.txt");//Constructor
	~flujo (void);

	void set_nivel_detalle (int nivel_detalle);
};


#endif FLUJOS_ES_H