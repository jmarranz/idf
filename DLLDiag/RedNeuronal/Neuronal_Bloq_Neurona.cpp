
#include "stdafx.h"

#include "..\DLLDiag.h"

#include <afxtempl.h>

#include <math.h>


#include "Neuronal_Com_Dato.h"
#include "Neuronal_Bloq_Neurona.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_Neurona,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_Neurona
IMPLEMENTAR_COM_ENTRADA(Neuronal_Com_Dato,Neuronal_Bloq_Neurona) 
BOOL Neuronal_Bloq_Neurona::RecibirDatosEntrada(Neuronal_Com_Dato* pE) 
{ 
	m_Entradas[pE->getNombreInternoConector()] = pE->m_Dato;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_Neurona
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_Neurona) 
void Neuronal_Bloq_Neurona::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	if (pS->getEtiquetaConector() == "dg/de")
		pS->m_Dato = dg(m_Entrada);
	else 
		pS->m_Dato = m_Activacion;
}

void Neuronal_Bloq_Neurona::IniciarDatos() 
{ 
	IniciarFuncion();

	m_Entradas.RemoveAll();
	m_Entrada = 0;
	m_Activacion = 0;
}

BOOL Neuronal_Bloq_Neurona::NuevosObjDatos() 
{ 
	return true; 
} 
void Neuronal_Bloq_Neurona::DestObjDatos() 
{ 
 
} 
void Neuronal_Bloq_Neurona::GuardarFichero(CArchive& ar) 
{ 
	m_Entradas.Serialize(ar);
	ar << m_Entrada << m_Activacion; 
} 

void Neuronal_Bloq_Neurona::LeerFichero(CArchive& ar) 
{ 
	m_Entradas.Serialize(ar);
	ar >> m_Entrada >> m_Activacion;

	IniciarFuncion();
} 

CString Neuronal_Bloq_Neurona::Accion() 
{ 
	m_Entrada = 0;

	POSITION pos = m_Entradas.GetStartPosition();
	while(pos != NULL)
	{
		CString nombre;
		double valor;
		m_Entradas.GetNextAssoc(pos,nombre,valor);
		m_Entrada += valor;
	}

	m_Activacion = g(m_Entrada);

	CambiaEstado(CORRECTO); 

	EnviarDatosRetroanotacion();

	return ""; 
}

BOOL Neuronal_Bloq_Neurona::PropiedadesBloque() 
{ 
	CString mensaje;
	char snum[20];

	mensaje += "e = ";
	sprintf(snum,"%f",m_Entrada);
	mensaje += snum;
	mensaje +="\r\n";

	mensaje += "a = ";
	sprintf(snum,"%f",m_Activacion);
	mensaje += snum;
	mensaje +="\r\n";
	
	Mensaje(mensaje);

	return true; 
} 

void Neuronal_Bloq_Neurona::IniciarFuncion() 
{ 
	CString tipofunc = getMacro();
	if (tipofunc.Find("FUNCION_IDENTIDAD") != -1)
	{
		g = identidad;
		dg = identidad_derivada;
	}
	else if (tipofunc.Find("FUNCION_SIGMOIDEA") != -1)
	{
		g = sigmoidea;
		dg = sigmoidea_derivada;
	}
	else if (tipofunc.Find("FUNCION_RAMPA") != -1)
	{
		g = rampa;
		dg = rampa_derivada;
	}
	else if (tipofunc.Find("FUNCION_LINEAL") != -1)
	{
		g = lineal;
		dg = lineal_derivada;
	}
	else
	{
		g = sigmoidea;
		dg = sigmoidea_derivada;
	}
}

double Neuronal_Bloq_Neurona::sigmoidea(double x)
{
	// return (2/(1 + exp(-x)) - 1); // sigmoidea simétrica 
	return (1/(1 + exp(-x)));
}

double Neuronal_Bloq_Neurona::sigmoidea_derivada(double x)
{
	// g' = g*(1-g)
	return sigmoidea(x)*(1 - sigmoidea(x));
}

double Neuronal_Bloq_Neurona::identidad(double x)
{
	return x;
}

double Neuronal_Bloq_Neurona::identidad_derivada(double x)
{
	return 1;
}

double Neuronal_Bloq_Neurona::rampa(double x)
{
	if (x < 0) return 0;
	return x / 2;
}

double Neuronal_Bloq_Neurona::rampa_derivada(double x)
{
	if (x < 0) return 0;
	return 1.0 / 2;
}

double Neuronal_Bloq_Neurona::lineal(double x)
{
	return x / 2; // amortiguada
}

double Neuronal_Bloq_Neurona::lineal_derivada(double x)
{
	return 1.0 / 2;
}
