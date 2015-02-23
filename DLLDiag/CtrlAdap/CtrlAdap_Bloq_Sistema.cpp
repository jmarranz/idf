

#include "stdafx.h"

#include <math.h>

#include "..\DLLDiag.h"


#include "CtrlAdap_Com_Var.h"

#include "CtrlAdap_Bloq_Sistema.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(CtrlAdap_Bloq_Sistema,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: CtrlAdap_Bloq_Sistema
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Sistema) 
BOOL CtrlAdap_Bloq_Sistema::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	Uk1 = Uk;
	Uk = Uk + pE->Var;  // pE->Var es dUk
	if (Uk < 0) Uk = 0; // No puede ser menor que cero
	T = pE->T;

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: CtrlAdap_Bloq_Sistema
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Sistema) 
void CtrlAdap_Bloq_Sistema::EnviarDatosSalida(CtrlAdap_Com_Var* pS) 
{ 
	if (pS->getNombreInternoConector() == "Con_Uk")
	{
		pS->Var = Uk;
	}
	else if (pS->getNombreInternoConector() == "Con_A_Uk")
	{
		pS->Var = Uk;
	}
	else
	{
		pS->Var = Yk;
	}
	
	pS->T = T;
} 

void CtrlAdap_Bloq_Sistema::IniciarDatos() 
{ 
	// Datos del modelo del sistema:

	c1 = 3.14159/3; // PI*tan(30)^2 
	a = 3*c1; // Por poner algo proporcional al área superior para h=1m
	c2 = a * sqrt(2 * 9.81); // g = 9.81

	// Valores iniciales

	Yk = 7;  //  h = 7 metros de altura valor inicial
	Yk1 = 7;  // Da igual será sobrescrito en el primer cálculo
	Uk = c2*sqrt(Yk);  // Valor necesario para que el sistema sea estable inicialmente (el agua que entra igual al que sale)
	Uk1 = Uk;
	
	T = 1;
	
	CambiaEstado(CORRECTO); 
} 
 
BOOL CtrlAdap_Bloq_Sistema::NuevosObjDatos() 
{ 
	return true; 
} 
void CtrlAdap_Bloq_Sistema::DestObjDatos() 
{ 
 
} 
void CtrlAdap_Bloq_Sistema::GuardarFichero(CArchive& ar) 
{ 
	ar << Uk << Uk1 << Yk << Yk1 << T; 
} 
void CtrlAdap_Bloq_Sistema::LeerFichero(CArchive& ar) 
{ 
	ar >> Uk >> Uk1 >> Yk >> Yk1 >> T;  
} 
CString CtrlAdap_Bloq_Sistema::Accion() 
{ 
	Yk1 = Yk; // Un nuevo pulso

	Yk = Yk1 + (T/c1)*(-c2*sqrt(Yk1) + Uk)/(Yk1*Yk1);

	CString Mensaje;
	Mensaje.Format("%f",Uk);
	Mensaje = "Uk=" + Mensaje;
	AfxMessageBox(Mensaje);

	// CString Mensaje;
	Mensaje.Format("%f",Yk);
	Mensaje = "y(k)=" + Mensaje;
	AfxMessageBox(Mensaje);

	EnviarDatosRetroanotacion("");
	
	return ""; 
} 
BOOL CtrlAdap_Bloq_Sistema::PropiedadesBloque() 
{ 
	return true; 
} 


