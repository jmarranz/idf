

#include "stdafx.h"
#include "..\DLLDiag.h"

#include "CtrlAdap_Com_Var.h"

#include "CtrlAdap_Bloq_Inversor.h"


IMPLEMENTAR_BLOQUE_RETROANOTACION(CtrlAdap_Bloq_Inversor,CBloqueRetro,1) 

// Implementación de clases de comunicación de Entrada del bloque: CtrlAdap_Bloq_Inversor
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Inversor) 
BOOL CtrlAdap_Bloq_Inversor::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	Var = pE->Var;
	T = pE->T;

	EnviarDatosRetroanotacion("");

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: CtrlAdap_Bloq_Inversor
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Inversor) 
void CtrlAdap_Bloq_Inversor::EnviarDatosSalida(CtrlAdap_Com_Var* pS) 
{ 
	pS->Var = -Var;
	pS->T = T;

} 

void CtrlAdap_Bloq_Inversor::IniciarDatos() 
{ 
	Var = 0;
	T = 1;
	CambiaEstado(CORRECTO);
} 
BOOL CtrlAdap_Bloq_Inversor::NuevosObjDatos() 
{ 
	return true; 
} 
void CtrlAdap_Bloq_Inversor::DestObjDatos() 
{ 
 
} 
void CtrlAdap_Bloq_Inversor::GuardarFichero(CArchive& ar) 
{ 
	ar << Var << T; 
} 
void CtrlAdap_Bloq_Inversor::LeerFichero(CArchive& ar) 
{ 
	ar >> Var >> T; 
} 

BOOL CtrlAdap_Bloq_Inversor::PropiedadesBloque() 
{ 
	return true; 
} 
