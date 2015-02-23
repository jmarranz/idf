

#include "stdafx.h"
#include "..\DLLDiag.h"

#include <math.h>


#include "DlgCtrlAdap_Ley.h"

#include "CtrlAdap_Com_Var.h"
#include "CtrlAdap_Com_Estim_Ley.h"
#include "CtrlAdap_Com_Ley_R.h"

#include "CtrlAdap_BloqRet_Ley.h"


IMPLEMENTAR_BLOQUE_RETROANOTACION(CtrlAdap_BloqRet_Ley,CBloqueRetro,1) 

// Implementación de clases de comunicación de Entrada del bloque: CtrlAdap_BloqRet_Ley
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,CtrlAdap_BloqRet_Ley) 
BOOL CtrlAdap_BloqRet_Ley::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	if (pE->getNombreInternoConector() == "Con_Yk_Ley")
	{
		Yk1 = Yk;
		Yk = pE->Var;
		T = pE->T;
	}
	else if (pE->getNombreInternoConector() == "Con_Xk")
	{
		// X no debe cambiar en al menos tres intervalos
		X = pE->Var;
		T = pE->T;
	}
	else if (pE->getNombreInternoConector() == "Con_RetEk")
	{
		Ek2 = Ek1;
		Ek1 = Ek;
		Ek = pE->Var;
		T = pE->T;

		if (EstimacionValida)
		{
			if (CalcularRegulador())
			{	
				RegValido = true;
				EnviarDatosRetroanotacion("");
			}
			else
			{
				RegValido = false;
			}
		}
	}

	return true;
} 
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Estim_Ley,CtrlAdap_BloqRet_Ley) 
BOOL CtrlAdap_BloqRet_Ley::RecibirDatosEntrada(CtrlAdap_Com_Estim_Ley* pE) 
{ 
	a1 = pE->a1 + pE->a2;
	a2 = -(pE->a1 + 2*pE->a2);
	a3 = pE->a2;

	EstimacionValida = true;

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: CtrlAdap_BloqRet_Ley
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Ley_R,CtrlAdap_BloqRet_Ley) 
void CtrlAdap_BloqRet_Ley::EnviarDatosSalida(CtrlAdap_Com_Ley_R* pS) 
{ 
	if (RegValido)  // Pueden pasar varios ciclos hasta que se calcule un primer regulador válido
	{
		pS->Kr = Kr;
	}
	else pS->Kr = -1;  // No vale
} 

void CtrlAdap_BloqRet_Ley::IniciarDatos() 
{ 
	RegValido = false;
	EstimacionValida = false;

	X = 7; // 7 metros de altura. Referencia inicial
	Ek2=0;
	Ek1=0;
	Ek=0;
	T = 1;
	Yk1 = 7;
	Yk= 7;
	
	Tau = 3; // Tres segundos 
	MaxE = 1; // 1% máximo error en reg. permanente
	a1 = a2 = a3 = 0;
	Kr = 1;  // No vale para nada

	CambiaEstado(CORRECTO); 
} 
BOOL CtrlAdap_BloqRet_Ley::NuevosObjDatos() 
{ 
	return true; 
} 
void CtrlAdap_BloqRet_Ley::DestObjDatos() 
{ 
 
} 
void CtrlAdap_BloqRet_Ley::GuardarFichero(CArchive& ar) 
{ 
	ar << T << X << Ek << Ek1 << Ek2 << Yk << Yk1;
	ar << a1 << a2 << a3 << Tau << Kr << RegValido << EstimacionValida;
} 
void CtrlAdap_BloqRet_Ley::LeerFichero(CArchive& ar) 
{ 
	ar >> T >> X >> Ek >> Ek1 >> Ek2 >> Yk >> Yk1;
	ar >> a1 >> a2 >> a3 >> Tau >> Kr >> RegValido >> EstimacionValida;
} 
BOOL CtrlAdap_BloqRet_Ley::PropiedadesBloque() 
{ 
	CDlgCtrlAdap_Ley dlg( getMainWnd() );
	dlg.m_Tau = Tau;
	dlg.m_MaxE = MaxE;

	if (dlg.DoModal() == IDOK)
	{
		Tau = dlg.m_Tau;
		MaxE = dlg.m_MaxE;
	}

	return true; 
} 

BOOL CtrlAdap_BloqRet_Ley::CalcularRegulador() 
{
	double Ekp = 100*Ek/X; // Porcentual
	if (Ekp < 0) Ekp = -Ekp;  // En valor absoluto
	if (Ekp <= MaxE) return true; // Reg permanente. Todo queda como está
	
//	double Krtemp=((a1+a2+a3)*X-(a1*Ek+a2*Ek1+a3*Ek2)*exp(-T/Tau))/Ek;

	// Ley más estable
	double Krtemp=(a1*(X-Ek*exp(-T/Tau)) + a2*Yk + a3*Yk1)/Ek;

	if (Krtemp < 0) 
	{
		AfxMessageBox("FALLO: No se puede aplicar la Ley de Control.\nGanancia negativa del regulador");
		return false;
	}
	else
	{	
		Kr = Krtemp;
		
		CString Mensaje;
		Mensaje.Format("%f",Kr);
		Mensaje = "Nuevo Kr=" + Mensaje;
		AfxMessageBox(Mensaje);
	}

	return true;
}

