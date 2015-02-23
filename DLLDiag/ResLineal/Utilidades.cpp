//******************************************************************
//
//	utilidades.cpp
//
//  Contiene funciones generales que puedan necesitarse a lo  
//  de todo el programa.
//	
//	fecha: 04/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"
#include "Utilidades.h"
#include <iostream>

////////////////////////////////////////////////////////////
//
// Función Factorial: Calcula el factorial de n
//
////////////////////////////////////////////////////////////

int factorial (int n)
{

	if (n == 0){
		return 1;
	}
	else{
		return ( n * factorial (n-1) );
	}
}

////////////////////////////////////////////////////////////
//
// Función Combinacion: Calcula la combinacion de n elementos,
//						tomados de p en p
//
////////////////////////////////////////////////////////////

int combinacion (int n, int p)
{
	return ( factorial(n)/(factorial(p)*factorial(n-p)) );
}

////////////////////////////////////////////////////////////
//
// Función ClearScreen: Limpia la pantalla de texto en consola
//
////////////////////////////////////////////////////////////

/*void ClearScreen(void)
{
	//Get display screen information & clear the screen.

	hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );

    DWORD    dummy;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
}*/

double maximo (double a, double b)
{
	if (a>=b)
		return a;
	else
		return b;
}