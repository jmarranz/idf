
#include "stdafx.h"

#include "..\DLLDiag.h"

#include "Neuronal_Com_Dato.h"

#include "Neuronal_Bloq_Inversion.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_Inversion,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_Inversion
IMPLEMENTAR_COM_ENTRADA(Neuronal_Com_Dato,Neuronal_Bloq_Inversion) 
BOOL Neuronal_Bloq_Inversion::RecibirDatosEntrada(Neuronal_Com_Dato* pE) 
{ 
	m_Entrada = pE->m_Dato;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_Inversion
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_Inversion) 
void Neuronal_Bloq_Inversion::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	pS->m_Dato = - m_Entrada;
} 

void Neuronal_Bloq_Inversion::IniciarDatos() 
{ 
	m_Entrada = 0;
} 

BOOL Neuronal_Bloq_Inversion::NuevosObjDatos() 
{ 
	return true; 
} 
void Neuronal_Bloq_Inversion::DestObjDatos() 
{ 
 
} 
void Neuronal_Bloq_Inversion::GuardarFichero(CArchive& ar) 
{ 
	ar << m_Entrada; 
} 
void Neuronal_Bloq_Inversion::LeerFichero(CArchive& ar) 
{ 
	ar >> m_Entrada;
} 

CString Neuronal_Bloq_Inversion::Accion() 
{ 
	// No hacemos nada, cambiamos el signo en la salida
	CambiaEstado(CORRECTO);
	return ""; 
} 

BOOL Neuronal_Bloq_Inversion::PropiedadesBloque() 
{ 
	return true; 
} 
