
#include "stdafx.h"

#include "..\DLLDiag.h"

#include "Neuronal_Com_Dato.h"

#include "Neuronal_Bloq_Sistema.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_Sistema,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_Sistema
IMPLEMENTAR_COM_ENTRADA(Neuronal_Com_Dato,Neuronal_Bloq_Sistema) 
BOOL Neuronal_Bloq_Sistema::RecibirDatosEntrada(Neuronal_Com_Dato* pE) 
{ 
	m_X = pE->m_Dato;

	CambiaEstado(CORRECTO);

	EnviarDatosRetroanotacion();

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_Sistema
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_Sistema) 
void Neuronal_Bloq_Sistema::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	pS->m_Dato = f(m_X);
} 

void Neuronal_Bloq_Sistema::IniciarDatos() 
{ 
	m_X = 0;
} 

BOOL Neuronal_Bloq_Sistema::NuevosObjDatos() 
{ 
	return true; 
} 
void Neuronal_Bloq_Sistema::DestObjDatos() 
{ 
 
} 
void Neuronal_Bloq_Sistema::GuardarFichero(CArchive& ar) 
{ 
	ar << m_X ;
} 

void Neuronal_Bloq_Sistema::LeerFichero(CArchive& ar) 
{ 
	ar >> m_X;
}

/*
CString Neuronal_Bloq_Sistema::Accion() 
{ 
	return ""; 
} 
*/
BOOL Neuronal_Bloq_Sistema::PropiedadesBloque() 
{ 
	CString mensaje;
	char snum[20];

	mensaje += "x = ";
	sprintf(snum,"%f",m_X);
	mensaje += snum;
	mensaje +="\r\n";

	mensaje += "y = ";
	sprintf(snum,"%f",f(m_X));
	mensaje += snum;
	mensaje +="\r\n";

	Mensaje(mensaje);

	return true; 
} 

double Neuronal_Bloq_Sistema::f(double x)
{
	return 10*x*x; // para empezar
}

