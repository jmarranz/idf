// Sist_Expert_Trapecios_Fuzzy.cpp: implementation of the Sist_Expert_Trapecios_Fuzzy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
// #include "..\dlldiag.h"
#include "Sist_Expert_Trapecios_Fuzzy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Trapecio_Fuzzy::Trapecio_Fuzzy()
{
	P1 = 0;
	P2 = 0;
	P3 = 0;
	P4 = 0;
	NivelEncaje = 0;
}

Trapecio_Fuzzy::Trapecio_Fuzzy(Trapecio_Fuzzy& tr)
{
	*this = tr;
}

Trapecio_Fuzzy::Trapecio_Fuzzy(double p1, double p2, double p3, double p4)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
	P4 = p4;

	NivelEncaje = 0;
}

void Trapecio_Fuzzy::operator=(Trapecio_Fuzzy& tr)
{
	P1 = tr.P1; 
	P2 = tr.P2; 
	P3 = tr.P3; 
	P4 = tr.P4; 
	NivelEncaje = tr.GetNivelEncaje();
}

double Trapecio_Fuzzy::Longitud()
{	
	double longitud = P4-P1;
	if (longitud < 0) longitud = -longitud;
	return longitud;
}

void Trapecio_Fuzzy::CalcNivelEncaje(double vp)
{
	// Todos los parámetros deben estar entre -1 y 1 incluido vp

	if ((P1 <= vp) && ( vp <= P4))
	{
		if (vp < P2)
		{
			NivelEncaje = (vp - P1)/(P2 - P1); 
		}
		else if (P3 < vp)
		{
			NivelEncaje = (P4 - vp)/(P4 - P3);
		}
		else NivelEncaje = 1;
	}
	else NivelEncaje = 0;
}

double Trapecio_Fuzzy::CalcNivelConFactorEncaje(double vp) 
{
	// Devuelve el nivel el nivel de encaje de vp no mayor que
	// el nivel de encaje actual alamacenado
	double nivel;

	Trapecio_Fuzzy tr_temp = *this;
	tr_temp.CalcNivelEncaje(vp);
	nivel = tr_temp.GetNivelEncaje();
	if (nivel > NivelEncaje) return NivelEncaje;
	return nivel;
}


double Trapecio_Fuzzy::SumaNiveles(double intervalo)
{
	// Intervalo debe ser 0 < intervalo
	// Si intervalo es mayor que P4-P3 sólo se ejecutará una
	// vez el bucle
	double suma = 0;
	double pos = P1;

	while ( pos <= P4 )
	{
		if (pos < P2)
		{
			suma += (pos-P1)/(P2-P1);
		}
		else if (pos > P3)
		{
			suma += (P4-pos)/(P4-P3);
		}
		else suma += 1;

		pos += intervalo;
	}

	return suma;
}


void Trapecio_Fuzzy::Ajustar(double coef)
{
	// coef debe estar en (-1, 1) y es un valor tanto por uno
	// Tras aplicar la regla el orden de P1, P2, P3, P4 no se altera
	// (fácil de demostrar)

	// El signo de coef nos dice que si es positivo: acercar a 1 y a -1
	// si es negativo acercar a cero.

	if (coef > 0)
	{
		P1 = (Signo(P1)-P1)*coef + P1;
		P2 = (Signo(P2)-P2)*coef + P2;
		P3 = (Signo(P3)-P3)*coef + P3;
		P4 = (Signo(P4)-P4)*coef + P4;		
	}
	else if (coef < 0)
	{
		P1 = P1*(1 + coef);
		P2 = P2*(1 + coef);
		P3 = P3*(1 + coef);
		P4 = P4*(1 + coef);
	}
}

int Trapecio_Fuzzy::Signo(double var)
{
	if (var > 0) return 1;
	if (var < 0) return -1;
	return 0;
}


void Trapecio_Fuzzy::GuardarFichero(CArchive& ar)
{
	ar << P1 << P2 << P3 << P4 << NivelEncaje;
}

void Trapecio_Fuzzy::LeerFichero(CArchive& ar)
{
	ar >> P1 >> P2 >> P3 >> P4 >> NivelEncaje;
}


// Implementación Trapecios_var

void Trapecios_var::CalcNivelEncajes(double var)
{
	for ( int i=0; i < 5; i++)
	{
		Trap[i].CalcNivelEncaje(var);
	}
}

double Trapecios_var::GetNivelEncaje(int tr)
{
	return Trap[tr].GetNivelEncaje();
}

void Trapecios_var::SetNivelEncaje(int tr, double nivel)
{
	Trap[tr].SetNivelEncaje(nivel);
}

double Trapecios_var::CalcCentroGravedad()
{
	// Defuzzyficación por el centro de gravedad de la distribución
	// de posibilidad global

	// getción del intervalo óptimo:
	double intervalo = LongMinTrapecios() / 10; // Puntos de muestreo por trapecio como mínimo

	double denominador = 0;
	double numerador = 0;

	for (int i = 0; i < 5; i++)
	{
		denominador += Trap[i].GetNivelEncaje() * Trap[i].SumaNiveles(intervalo);
	}

	for (double pos = -1; pos <= 1; pos += intervalo)
	{
		numerador += CalcAreaNivel(pos);
	}


	return (numerador / denominador);
}

double Trapecios_var::CalcAreaNivel(double pos)
{
	double maxnivel = 0;
	int numtrapecio = -1;
	for (int i = 0; i < 5; i++)
	{
		double nivelactual;
		nivelactual = Trap[i].CalcNivelConFactorEncaje(pos);
		if (nivelactual > maxnivel)
		{
			maxnivel = nivelactual;
			numtrapecio = i;
		}
	}	
	
	double area = 0;
	if (maxnivel > 0)
	{
		area = pos * maxnivel;
	}

	return area;
}

void Trapecios_var::GuardarFichero(CArchive& ar)
{
	for ( int i=0; i < 5; i++)
	{		
		Trap[i].GuardarFichero(ar);
	}
}

void Trapecios_var::LeerFichero(CArchive& ar)
{
	for ( int i=0; i < 5; i++)
	{		
		Trap[i].GuardarFichero(ar);
	}
}

void Trapecios_var::Ajustar(double coef)
{
	for ( int i=0; i < 5; i++)
	{
		Trap[i].Ajustar(coef);
	}
}

double Trapecios_var::LongMinTrapecios()
{
	double longmin = 1; // Valor que no alcanza ningún trapecio
	for ( int i=0; i < 5; i++)
	{
		double longtr = Trap[i].Longitud();
		if (longtr < longmin) longmin = longtr;
	}
	return longmin;
}

