

#include "stdafx.h"

#include "..\DLLDiag.h"

#include "DlgSistExpert_Ley.h"

#include "..\CtrlAdap\CtrlAdap_Com_Var.h"
#include "SistExpert_Com_Ley_R.h"
#include "SistExpert_Com_Coefs.h"

#include "SistExpert_Bloq_Aprend.h"


IMPLEMENTAR_BLOQUE_RETROANOTACION(SistExpert_Bloq_Aprend,CBloqueRetro,1) 

// Implementación de clases de comunicación de Entrada del bloque: SistExpert_Bloq_Aprend
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,SistExpert_Bloq_Aprend) 
BOOL SistExpert_Bloq_Aprend::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	if (pE->getNombreInternoConector() == "Con_A_Uk")
	{
		Uk3 = Uk2;
		Uk2 = Uk1;
		Uk1 = pE->Var;
	}
	if (pE->getNombreInternoConector() == "Con_X_A")
	{
		X = pE->Var;
	}
	else if (pE->getNombreInternoConector() == "Con_E_A")
	{
		Ek1 = Ek;
		Ek = pE->Var;

		dEk1 = dEk;
		dEk = Ek-Ek1;

		AjustarReglas();
	}

	T = pE->T;

	return true;
} 


// Implementación de clases de comunicación de Salida del bloque: SistExpert_Bloq_Aprend
IMPLEMENTAR_COM_SALIDA(SistExpert_Com_Coefs,SistExpert_Bloq_Aprend) 
void SistExpert_Bloq_Aprend::EnviarDatosSalida(SistExpert_Com_Coefs* pS) 
{ 
	pS->ce = ce;
	pS->cde = cde;
	pS->cdu = cdu;
} 

void SistExpert_Bloq_Aprend::IniciarDatos() 
{ 
	X = 1;
	Ek1 = 0;
	Ek = 0;
	dEk1 = 0;
	dEk = 0;
	T = 1;
	Uk3 = 10;
	Uk2 = 10;
	Uk1 = 10;

	ce = 0;
	cde = 0;
	cdu = 0;

	MaxE = 1; // 1 % de error permitido

	CambiaEstado(CORRECTO); 
} 
BOOL SistExpert_Bloq_Aprend::NuevosObjDatos() 
{ 
	return true; 
} 
void SistExpert_Bloq_Aprend::DestObjDatos() 
{ 
 
} 
void SistExpert_Bloq_Aprend::GuardarFichero(CArchive& ar) 
{ 
	ar << X << Ek1 << Ek << dEk1 << dEk << T << Uk1 << Uk2 << Uk3 << MaxE;
	ar << ce << cde << cdu;
} 
void SistExpert_Bloq_Aprend::LeerFichero(CArchive& ar) 
{ 
	ar >> X >> dEk1 >> Ek >> dEk1 >> dEk >> T >> Uk1 >> Uk2 >> Uk3 >> MaxE;
	ar >> ce >> cde >> cdu;	
} 
BOOL SistExpert_Bloq_Aprend::PropiedadesBloque() 
{ 
	DlgSistExpert_Ley dlg( getMainWnd() );
	dlg.m_MaxE = MaxE;

	if (dlg.DoModal() == IDOK)
	{
		MaxE = dlg.m_MaxE;
	}

	return true; 
} 

BOOL SistExpert_Bloq_Aprend::AjustarReglas()
{
	if (0 == Uk1) return false; // No hay nada que hacer

	double pEmax = MaxE/100; // en tanto por uno
	double pEkabs = Ek/X; 
	if (pEkabs < 0) pEkabs = -pEkabs; // tanto por uno en valor absoluto

	if (pEkabs > pEmax)
	{	
		BOOL ajuste = false;
		ce = 0;
		cde = 0;
		cdu = 0;

		ajuste = Ajuste_E(); 
		ajuste = Ajuste_dE();
		ajuste = Ajuste_dU();

		if (ajuste)
		{
			CString Mensaje;
			Mensaje.Format("(%f,%f,%f)",ce,cde,cdu);
			Mensaje = "(ce,cde,cdu)=" + Mensaje;
			AfxMessageBox(Mensaje);

			EnviarDatosRetroanotacion("");
			ce = 0;
			cde = 0;
			cdu = 0;
			return true;
		}
	}
	return false;
}


BOOL SistExpert_Bloq_Aprend::Ajuste_E() 
{
	// Fracasos de regulación de E

	BOOL ajustar = false;
	BOOL relajar = false;

	if ((Ek1 > 0)&&(Ek > Ek1)) 
	{
		ajustar = true;
	}
	else if ((Ek1 < 0)&&(Ek < Ek1)) 
	{
		ajustar = true;
	}
	else if ((Ek1 > 0)&&(Ek < 0)) 
	{
		relajar = true;
	}
	else if ((Ek1 < 0)&&(Ek > 0)) 
	{
		relajar = true;
	}

	if (ajustar)
	{
		ce = -0.3; // 30 % en tanto por 1
		return true;
	}
	else if (relajar)
	{
		ce = 0.3; // 30 % en tanto por 1
		return true;
	}
	return false;
}

BOOL SistExpert_Bloq_Aprend::Ajuste_dE() 
{
	// Fracasos de regulación de dE

	BOOL ajustar = false;
	BOOL relajar = false;

	if ((Ek1 < 0)&&(dEk1 > 0)&&(dEk < dEk1)) 
	{
		ajustar = true;
	}
	else if ((Ek1 > 0)&&(dEk1 < 0)&&(dEk > dEk1)) 
	{
		ajustar = true;
	}
	else if ((Ek1 < 0)&&(dEk1 > 0)&&(Ek > 0)&&(dEk < 0)) 
	{
		relajar = true;
	}
	else if ((Ek1 > 0)&&(dEk1 < 0)&&(Ek < 0)&&(dEk > 0))
	{
		relajar = true;
	}

	if (ajustar)
	{
		cde = -0.3; // 30 % en tanto por 1
		return true;
	}
	else if (relajar)
	{
		cde = 0.3; // 30 % en tanto por 1
		return true;
	}
	return false;
}

BOOL SistExpert_Bloq_Aprend::Ajuste_dU() 
{
	// Ajuste fuerte o débil de dU según el acierto
	// o fracaso de la regulación
	// Se aplicará según el error máximo permitido
	
	BOOL ajustar = false;
	BOOL relajar = false;

	double dUk2 = Uk2-Uk3;
	double dUk1 = Uk1-Uk2;

	if ((Ek1 < 0)&&(dUk2 > 0)&&(dUk1 < dUk2)) 
	{
		// Fracaso: nos hemos quedado cortos: más fuerte
		ajustar = true;
	}
	else if ((Ek1 > 0)&&(dUk2 < 0)&&(dUk1 > dUk2)) 
	{
		// Fracaso: nos hemos quedado cortos: más fuerte
		ajustar = true;
	}
	else if ((Ek1 > 0)&&(dUk1 > 0)&&(Ek < 0))
	{
		// Fracaso nos hemos pasado, demasiado fuerte, relajamos
		relajar = true;
	}
	else if ((Ek1 < 0)&&(dUk1 < 0)&&(Ek > 0))
	{
		// Fracaso nos hemos pasado, demasiado fuerte, relajamos
		relajar = true;
	}

	if (ajustar)
	{
		cdu = -0.3; // 30 % en tanto por 1
		return true;
	}
	else if (relajar)
	{
		cdu = 0.3; // 30 % en tanto por 1
		return true;
	}
	
	return false;
}

