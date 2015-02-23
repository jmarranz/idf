// Newton_Funcion.cpp: implementation of the Newton_Funcion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\dlldiag.h"
#include "Newton_Funcion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

double f(double x)
{
    double res;
    res = x*x - 3*x;
    return  res;
}

double fd(double x, double h)
{
    double res;
    res = (f(x+h)-f(x))/h;
	return res;
}

