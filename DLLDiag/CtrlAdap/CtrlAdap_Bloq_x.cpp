

#include "stdafx.h"

#include "..\DLLDiag.h"

#include "dlgctrladap_x.h"
#include "CtrlAdap_Com_Var.h"

#include "CtrlAdap_Bloq_x.h"

IMPLEMENTAR_BLOQUE_FUNCIONAL(CtrlAdap_Bloq_x,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: CtrlAdap_Bloq_x

// Implementación de clases de comunicación de Salida del bloque: CtrlAdap_Bloq_x
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Var,CtrlAdap_Bloq_x) 
void CtrlAdap_Bloq_x::EnviarDatosSalida(CtrlAdap_Com_Var* pS) 
{ 
	pS->Var = x; 
	pS->T = T;
} 

void CtrlAdap_Bloq_x::IniciarDatos() 
{ 
	x = 1;
	T = 0.1; // Décimas de segundo
	K = 0;
	CambiaEstado(CORRECTO);
} 
BOOL CtrlAdap_Bloq_x::NuevosObjDatos() 
{ 
	return true; 
} 
void CtrlAdap_Bloq_x::DestObjDatos() 
{ 
 
} 
void CtrlAdap_Bloq_x::GuardarFichero(CArchive& ar) 
{ 
	ar << x << K << T;  
} 
void CtrlAdap_Bloq_x::LeerFichero(CArchive& ar) 
{ 
	ar >> x >> K >> T;  
} 
CString CtrlAdap_Bloq_x::Accion() 
{ 
	K += 1;
	
/*	if (!EsModoAuto())  */
	{
		CDlgCtrlAdapt_x dlg( getMainWnd() );
		dlg.m_x = x;
		dlg.m_T = T;
		dlg.m_K = K;
		if (dlg.DoModal() == IDOK)
		{
			x = dlg.m_x;
			T = dlg.m_T;
			K = dlg.m_K;
		}
	}

	EnviarDatosRetroanotacion("");

	return ""; 
} 
BOOL CtrlAdap_Bloq_x::PropiedadesBloque() 
{ 
/*	if (!EsModoAuto())  */
	{
		CDlgCtrlAdapt_x dlg( getMainWnd() );
		dlg.m_x = x;
		dlg.m_T = T;
		dlg.m_K = K;
		if (dlg.DoModal() == IDOK)
		{
			x = dlg.m_x;
			T = dlg.m_T;
			K = dlg.m_K;
		}
	}
	return true; 
} 
