

#include "stdafx.h"
#include "..\DLLDiag.h"

#include "CtrlAdap_Com_Var.h"

#include "CtrlAdap_Bloq_Plus.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(CtrlAdap_Bloq_Plus,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: CtrlAdap_Bloq_Plus
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Plus) 
BOOL CtrlAdap_Bloq_Plus::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	if (pE->getNombreInternoConector() == "Con_X")
	{
		X = pE->Var;
	}
	else if (pE->getNombreInternoConector() == "Con_Yn")
	{
		Yn = pE->Var;
	}	

	T = pE->T;

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: CtrlAdap_Bloq_Plus
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Plus) 
void CtrlAdap_Bloq_Plus::EnviarDatosSalida(CtrlAdap_Com_Var* pS) 
{ 
	pS->Var = E;
	pS->T = T;
} 

void CtrlAdap_Bloq_Plus::IniciarDatos() 
{ 
	X= 0;
	Yn=0;
	T = 1; 
	E = 0;
	CambiaEstado(CORRECTO);
} 
BOOL CtrlAdap_Bloq_Plus::NuevosObjDatos() 
{ 
	return true; 
} 
void CtrlAdap_Bloq_Plus::DestObjDatos() 
{ 
 
} 
void CtrlAdap_Bloq_Plus::GuardarFichero(CArchive& ar) 
{ 
	ar << E << X << Yn << T;  
} 
void CtrlAdap_Bloq_Plus::LeerFichero(CArchive& ar) 
{ 
	ar >> E >> X >> Yn >> T;  
} 
CString CtrlAdap_Bloq_Plus::Accion() 
{ 
	E = X + Yn;

	CString Mensaje;
	Mensaje.Format("%f",E);
	Mensaje = "e(k)=" + Mensaje;
	AfxMessageBox(Mensaje);

	EnviarDatosRetroanotacion("");

	return ""; 
} 
BOOL CtrlAdap_Bloq_Plus::PropiedadesBloque() 
{ 
	return true; 
} 
