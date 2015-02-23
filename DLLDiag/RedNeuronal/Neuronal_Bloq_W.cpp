
#include "stdafx.h"

#include "..\DLLDiag.h"

#include "Neuronal_Com_Dato.h"

#include "Neuronal_Bloq_W.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_W,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_W
IMPLEMENTAR_COM_ENTRADA(Neuronal_Com_Dato,Neuronal_Bloq_W) 
BOOL Neuronal_Bloq_W::RecibirDatosEntrada(Neuronal_Com_Dato* pE) 
{ 
	BOOL result = false;
	if (pE->getEtiquetaConector() == "dW")
	{
		m_W = m_W + pE->m_Dato;
		result = true;
	}
	else
	{
		m_Activacion = pE->m_Dato;
		result = true;
	}

	if (result)
	{
		CambiaEstado(CORRECTO);
		EnviarDatosRetroanotacion();
	}

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_W
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_W) 
void Neuronal_Bloq_W::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	if (pS->getEtiquetaConector() == "W")
		pS->m_Dato = m_W;
	else
		pS->m_Dato = m_W * m_Activacion;
} 

void Neuronal_Bloq_W::IniciarDatos() 
{ 
	static BOOL random_iniciado = false;
	if (!random_iniciado)
	{
		srand( (unsigned)time( NULL ) );
		random_iniciado = true;
	}

	m_Activacion = 0;
	m_W = 1; // (double)(2.0 * rand() / RAND_MAX - 1); // Aleatorio inicialmente entre -1 y 1
} 

BOOL Neuronal_Bloq_W::NuevosObjDatos() 
{ 
	return true; 
} 

void Neuronal_Bloq_W::DestObjDatos() 
{ 
 
} 

void Neuronal_Bloq_W::GuardarFichero(CArchive& ar) 
{ 
	ar << m_Activacion << m_W;
} 

void Neuronal_Bloq_W::LeerFichero(CArchive& ar) 
{ 
	ar >> m_Activacion >> m_W;
} 

/*
CString Neuronal_Bloq_W::Accion() 
{ 
	return ""; 
} 
*/

BOOL Neuronal_Bloq_W::PropiedadesBloque() 
{ 
	CString mensaje;
	char snum[20];

	mensaje += "W = ";
	sprintf(snum,"%f",m_W);
	mensaje += snum;
	mensaje +="\r\n";

	Mensaje(mensaje);

	return true; 
} 
