// InfoClases.h: interface for the InfoClases class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFOCLASES_H__DF1AFF84_1A23_401B_A6FA_9728F77B64DE__INCLUDED_)
#define AFX_INFOCLASES_H__DF1AFF84_1A23_401B_A6FA_9728F77B64DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Clases de registro de la informaci�n.
// A trav�s de ellas se declarar�n objetos globales que al crearse
// se registrar�n en las listas de CIdfDllApp
// Sirven para que desde fuera podamos saber qu� clases est�n definidas 
// aunque no sepamos nada del m�dulo.
// No intervienen en nada con el flujo de la informaci�n ni siquiera en
// el enlace din�mico con los objetos. S�lo tienen fines informativos
// Se podr�an quitar sin restar con ello funcionalidad.

// Definimos primero estructuras que nos servir�n para intercambiar datos entre DLLs,

#include "IdfDllApp.h"


class CInfoComponenteDiag : public CObject 
{
};

class CInfoClaseComponenteDiag : public CInfoComponenteDiag 
{
public:
	CInfoClaseComponenteDiag(const char* nombreclase, const char* nombreclasebase, const char* verserial);

public:
	CString NombreClase;
	CString NombreClaseBase;
	CString VerSerial;
};


class CInfoBloque : public CInfoClaseComponenteDiag
{
public:
	CInfoBloque(const char* nombreclase, const char* nombreclasebase, const char* verserial, int tipo);
	int getTipo() { return Tipo; }

protected:
	int Tipo; // 0 = ambos tipos, 1 = s�lo funcional, 2 = s�lo retroanotaci�n
};


class CInfoCom : public CInfoClaseComponenteDiag
{
public:
	CInfoCom(const char* nombreclase, const char* nombreclasebase,const char* verserial);
};


class CInfoComES : public CInfoComponenteDiag
{
public:
	CInfoComES(const char* nombreclase, const char* nombreclasebloque, int tipo);

	int getTipo() { return Tipo; }

public:
	int Tipo; // 0 = entrada, 1 = salida
	CString NombreClase;
	CString NombreClaseBloque;
};


#endif // !defined(AFX_INFOCLASES_H__DF1AFF84_1A23_401B_A6FA_9728F77B64DE__INCLUDED_)
