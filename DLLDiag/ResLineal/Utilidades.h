//******************************************************************
//
//	utilidades.h
//
//  Define una serie de MACROS que se van a utilizar a lo largo 
//  de todo el programa.Son en particular los nombres de las 
//	componentes en los distintos tipos de vectores.
//
//	fecha: 04/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <afx.h>
#include <afxtempl.h>
#include <afxcoll.h>
#include <math.h>
#include <iostream>

#define X 1
#define Y 2
#define Z 3

#define I 1
#define J 2
#define K 3
#define L 4

#define XI 1
#define ETA 2
#define ZETA 3 

////////////////////////////////////////////////////////////
//
// Funciones globales
//
////////////////////////////////////////////////////////////

int factorial (int n);
int combinacion (int n, int p);

double maximo (double a, double b);

#endif UTILIDADES_H