
#include "stdafx.h"

#include "..\DLLDiag.h"

#include <afxtempl.h>

#include "Neuronal_Com_Dato.h"

#include "Neuronal_Bloq_dW.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_dW,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_dWSalida
IMPLEMENTAR_COM_ENTRADA(Neuronal_Com_Dato,Neuronal_Bloq_dW) 
BOOL Neuronal_Bloq_dW::RecibirDatosEntrada(Neuronal_Com_Dato* pE) 
{ 
	BOOL result = true;
	if (pE->getEtiquetaConector() == "dg/de")
	{
		m_dg = pE->m_Dato;
		result = true;
	}
	else if (pE->getEtiquetaConector() == "Err")
	{
		m_Err[pE->getNombreInternoConector()] = pE->m_Dato;
		result = true;
	}
	else if (pE->getEtiquetaConector() == "W")
	{
		m_W = pE->m_Dato;
		result = true;
	}
	else if (pE->getEtiquetaConector() == "a")	
	{
		m_A = pE->m_Dato;
		result = true;
	}

	if (result) 
	{	
		CambiaEstado(CORRECTO);

		if (pE->getEtiquetaConector() == "Err")
			EnviarDatosRetroanotacion();

		return true;
	}

	return false;
} 

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_dWSalida
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_dW) 
void Neuronal_Bloq_dW::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	double errorSuma = 0;

	POSITION pos = m_Err.GetStartPosition();
	while(pos != NULL)
	{
		CString nombre;
		double valor;
		m_Err.GetNextAssoc(pos,nombre,valor);
		errorSuma += valor;
	}

	if (pS->getEtiquetaConector() == "dW")
	{
		double dW = m_Alfa * m_A * m_dg * errorSuma;
		pS->m_Dato = dW;
	}
	else if (pS->getEtiquetaConector() == "Err")
	{
		double Err = m_W * m_dg * errorSuma;
		pS->m_Dato = Err;
	}
}

void Neuronal_Bloq_dW::IniciarDatos() 
{ 
	m_Alfa = 3; // Velocidad de aprendizaje
	m_dg = 0;
	m_Err.RemoveAll();
	m_W = 0;
	m_A = 0;
} 

BOOL Neuronal_Bloq_dW::NuevosObjDatos() 
{ 
	return true; 
} 
void Neuronal_Bloq_dW::DestObjDatos() 
{ 
 
} 
void Neuronal_Bloq_dW::GuardarFichero(CArchive& ar) 
{ 
	m_Err.Serialize(ar);
	ar << m_Alfa << m_dg << m_W << m_A;
}

void Neuronal_Bloq_dW::LeerFichero(CArchive& ar) 
{ 
	m_Err.Serialize(ar);
	ar >> m_Alfa >> m_dg >> m_W >> m_A;
} 

/*
CString Neuronal_Bloq_dW::Accion() 
{ 
	return ""; 
} 
*/

BOOL Neuronal_Bloq_dW::PropiedadesBloque() 
{ 
	CString mensaje;
	char snum[20];

	mensaje += "alfa = ";
	sprintf(snum,"%f",m_Alfa);
	mensaje += snum;
	mensaje +="\r\n";

	mensaje += "dg/de = ";
	sprintf(snum,"%f",m_dg);
	mensaje += snum;
	mensaje +="\r\n";

	double errorSuma = 0;

	POSITION pos = m_Err.GetStartPosition();
	while(pos != NULL)
	{
		CString nombre;
		double valor;
		m_Err.GetNextAssoc(pos,nombre,valor);
		errorSuma += valor;
	}

	mensaje += "Err (ent) = ";
	sprintf(snum,"%f",errorSuma);
	mensaje += snum;
	mensaje +="\r\n";

	mensaje += "a = ";
	sprintf(snum,"%f",m_A);
	mensaje += snum;
	mensaje +="\r\n";

	mensaje += "W = ";
	sprintf(snum,"%f",m_W);
	mensaje += snum;
	mensaje +="\r\n";


	Mensaje(mensaje);

	return true; 
} 
