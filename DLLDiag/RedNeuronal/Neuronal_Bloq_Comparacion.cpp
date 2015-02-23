
#include "stdafx.h"

#include "..\DLLDiag.h"

#include "Neuronal_Com_Dato.h"

#include "Neuronal_Bloq_Comparacion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_Comparacion,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_Comparacion
IMPLEMENTAR_COM_ENTRADA(Neuronal_Com_Dato,Neuronal_Bloq_Comparacion) 
BOOL Neuronal_Bloq_Comparacion::RecibirDatosEntrada(Neuronal_Com_Dato* pE) 
{ 
	m_Entrada = pE->m_Dato;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_Comparacion
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_Comparacion) 
void Neuronal_Bloq_Comparacion::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	pS->m_Dato = m_Entrada;
}

void Neuronal_Bloq_Comparacion::IniciarDatos() 
{ 
	m_Entrada = 1;
	m_Referencia = 0.01;
} 
BOOL Neuronal_Bloq_Comparacion::NuevosObjDatos() 
{ 
	return true; 
} 
void Neuronal_Bloq_Comparacion::DestObjDatos() 
{ 
 
} 
void Neuronal_Bloq_Comparacion::GuardarFichero(CArchive& ar) 
{ 
	ar << m_Entrada << m_Referencia;
} 

void Neuronal_Bloq_Comparacion::LeerFichero(CArchive& ar) 
{ 
	ar >> m_Entrada >> m_Referencia;
}

CString Neuronal_Bloq_Comparacion::Accion() 
{ 
	CString result;

	PropiedadesBloque();

	CambiaEstado(CORRECTO);

	double err = m_Entrada;
	if (err < 0) err = -err;

	if (err < m_Referencia) result = "SI";
	else 
	{	
		BOOL res = Confirmar("¿Retropropagar?");
		if (res)
		{
			result = "NO";
			EnviarDatosRetroanotacion();
		}
		else result = "SI";
	}

	return result; 
}

BOOL Neuronal_Bloq_Comparacion::PropiedadesBloque() 
{ 
	char mensaje[300];
	sprintf(mensaje,"Err = %f",m_Entrada);
	Mensaje(mensaje);

	return true; 
} 

