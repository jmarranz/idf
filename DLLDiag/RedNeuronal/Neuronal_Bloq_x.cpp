
#include "stdafx.h"

#include "..\DLLDiag.h"

#include "DlgNeuronalX.h"

#include "Neuronal_Com_Dato.h"

#include "Neuronal_Bloq_x.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_x,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: Neuronal_Bloq_x

// Implementación de clases de comunicación de Salida del bloque: Neuronal_Bloq_x
IMPLEMENTAR_COM_SALIDA(Neuronal_Com_Dato,Neuronal_Bloq_x) 
void Neuronal_Bloq_x::EnviarDatosSalida(Neuronal_Com_Dato* pS) 
{ 
	if (pS->getEtiquetaConector() == "x2")
	{
		pS->m_Dato = X2; 
	}
	else if (pS->getEtiquetaConector() == "x1")
	{
		pS->m_Dato = X1; 
	}
	else
	{
		pS->m_Dato = X;
	}
} 

void Neuronal_Bloq_x::IniciarDatos() 
{ 
	X = 0.1;
	X1 = 0;
	X2 = 0;
}

BOOL Neuronal_Bloq_x::NuevosObjDatos() 
{ 
	return true; 
} 

void Neuronal_Bloq_x::DestObjDatos() 
{ 
 
} 

void Neuronal_Bloq_x::GuardarFichero(CArchive& ar) 
{ 
	ar << X << X1 << X2; 
} 
void Neuronal_Bloq_x::LeerFichero(CArchive& ar) 
{ 
	ar >> X >> X1 >> X2;
}

CString Neuronal_Bloq_x::Accion() 
{ 
	X2 = X1;
	X1 = X;
	X = X + 0.1;	

	PropiedadesBloque();

	CambiaEstado(CORRECTO); 

	EnviarDatosRetroanotacion();

	return ""; 
} 

BOOL Neuronal_Bloq_x::PropiedadesBloque() 
{ 
	CString mensaje;
	char snum[20];

	mensaje += "x = ";
	sprintf(snum,"%f",X);
	mensaje += snum;
	mensaje +="\r\n";

	// Mensaje(mensaje);


	CDlgNeuronalX dlg;
	dlg.m_X = X;
	dlg.m_X1 = X1;
	dlg.m_X2 = X2;

	if (dlg.DoModal() == IDOK)
	{
		X = dlg.m_X;
		X1 = dlg.m_X1;
		X2 = dlg.m_X2;
	}
	
	return true; 
} 

