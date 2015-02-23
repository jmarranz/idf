
#include "stdafx.h"

#include "..\DLLDiag.h"

#include <afxtempl.h>

#include "Neuronal_Com_Dato.h"

#include "Neuronal_Bloq_Suma.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_Suma,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_Suma
IMPLEMENTAR_COM_ENTRADA(Neuronal_Com_Dato,Neuronal_Bloq_Suma) 
BOOL Neuronal_Bloq_Suma::RecibirDatosEntrada(Neuronal_Com_Dato* pE) 
{ 
	m_Entradas[pE->getNombreInternoConector()] = pE->m_Dato;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_Suma
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_Suma) 
void Neuronal_Bloq_Suma::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	pS->m_Dato = m_Suma;
} 

void Neuronal_Bloq_Suma::IniciarDatos() 
{ 
	m_Entradas.RemoveAll();
	m_Suma = 0;
}

BOOL Neuronal_Bloq_Suma::NuevosObjDatos() 
{ 
	return true; 
} 

void Neuronal_Bloq_Suma::DestObjDatos() 
{ 
 
} 

void Neuronal_Bloq_Suma::GuardarFichero(CArchive& ar) 
{ 
	m_Entradas.Serialize(ar);
	ar << m_Suma; 
} 
void Neuronal_Bloq_Suma::LeerFichero(CArchive& ar) 
{ 
	m_Entradas.Serialize(ar);
	ar >> m_Suma;  
}

CString Neuronal_Bloq_Suma::Accion() 
{ 
	m_Suma = 0;

	POSITION pos = m_Entradas.GetStartPosition();
	while(pos != NULL)
	{
		CString nombre;
		double valor;
		m_Entradas.GetNextAssoc(pos,nombre,valor);
		m_Suma += valor;
	}

	CambiaEstado(CORRECTO); 

	return ""; 
} 

BOOL Neuronal_Bloq_Suma::PropiedadesBloque() 
{ 
	return true; 
} 
