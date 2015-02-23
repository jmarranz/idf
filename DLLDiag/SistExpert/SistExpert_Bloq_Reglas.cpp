
#include "stdafx.h"

#include "..\DLLDiag.h"

#include "..\CtrlAdap\CtrlAdap_Com_Var.h"
#include "..\CtrlAdap\DlgCtrlAdap_Ajuste.h"

#include "SistExpert_Com_Ley_R.h"
#include "SistExpert_Com_Coefs.h"


#include "SistExpert_Bloq_Reglas.h"




IMPLEMENTAR_BLOQUE_RETROANOTACION(SistExpert_Bloq_Reglas,CBloqueRetro,1) 

// Implementación de clases de comunicación de Entrada del bloque: SistExpert_Bloq_Reglas
IMPLEMENTAR_COM_ENTRADA(SistExpert_Com_Coefs,SistExpert_Bloq_Reglas) 
BOOL SistExpert_Bloq_Reglas::RecibirDatosEntrada(SistExpert_Com_Coefs* pE) 
{ 
	if (Ajustar) // Permitir ajustar por un bloque externo
	{
		double ce = pE->ce;
		double cde = pE->ce;
		double cdu = pE->ce;

		if (ce != 0)  trs_e.Ajustar(ce);
		if (cde != 0) trs_de.Ajustar(cde);
		if (cdu != 0) trs_du.Ajustar(cdu);
	}	
	return true;
} 

IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,SistExpert_Bloq_Reglas) 
BOOL SistExpert_Bloq_Reglas::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	if (pE->getNombreInternoConector() == "Con_X_R")
	{
		X = pE->Var;
	}
	else if (pE->getNombreInternoConector() == "Con_Uk")
	{
		Uk1 = Uk;
		Uk = pE->Var;
	}
	else if (pE->getNombreInternoConector() == "Con_E_R")
	{
		Ek1 = Ek; 
		Ek = pE->Var;

		Calc_Kr();
		EnviarDatosRetroanotacion("");
	}	

	T = pE->T;

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: SistExpert_Bloq_Reglas
IMPLEMENTAR_COM_SALIDA(SistExpert_Com_Ley_R,SistExpert_Bloq_Reglas) 
void SistExpert_Bloq_Reglas::EnviarDatosSalida(SistExpert_Com_Ley_R* pS) 
{ 
	pS->Kr = Kr; 
} 

void SistExpert_Bloq_Reglas::IniciarDatos() 
{ 
	Ajustar = true;

	// Entradas
	X = 1;
	Ek = 0;
	Ek1 = 0;
	T = 1;
	// Salidas
	Kr = 1; 

	// Internos
	Uk1=10;
	Uk=10;

	//     e   de    dKr
	reglas[MN][MN] = MN;
	reglas[N] [MN] = MN;
	reglas[Z] [MN] = Z;
	reglas[P] [MN] = P;
	reglas[MP][MN] = MP;

	reglas[MN][N] = MN;
	reglas[N] [N] = MN;
	reglas[Z] [N] = Z;
	reglas[P] [N] = P;
	reglas[MP][N] = MP;

	reglas[MN][Z] = MN;
	reglas[N] [Z] = N;
	reglas[Z] [Z] = Z;
	reglas[P] [Z] = P;
	reglas[MP][Z] = MP;

	reglas[MN][P] = MN;
	reglas[N] [P] = N;
	reglas[Z] [P] = Z;
	reglas[P] [P] = MP;
	reglas[MP][P] = MP;

	reglas[MN][MP] = MN;
	reglas[N] [MP] = N;
	reglas[Z] [MP] = Z;
	reglas[P] [MP] = MP;
	reglas[MP][MP] = MP;

	trs_e.Trap[MN]= Trapecio_Fuzzy(-1  ,-1  ,-0.3,-0.2);
	trs_e.Trap[N]=  Trapecio_Fuzzy(-0.3,-0.2,-0.1, 0  ); 
	trs_e.Trap[Z]=  Trapecio_Fuzzy(-0.1,   0, 0  , 0.1); 
	trs_e.Trap[P]=  Trapecio_Fuzzy(   0, 0.1, 0.2, 0.3); 
	trs_e.Trap[MP]= Trapecio_Fuzzy( 0.2, 0.3, 1  , 1  ); 

	trs_de.Trap[MN]= Trapecio_Fuzzy(-1   ,-1   ,-0.15,-0.1);
	trs_de.Trap[N]=  Trapecio_Fuzzy(-0.15,-0.1 ,-0.05, 0 ); 
	trs_de.Trap[Z]=  Trapecio_Fuzzy(-0.05, 0   , 0   , 0.05); 
	trs_de.Trap[P]=  Trapecio_Fuzzy( 0   , 0.05, 0.10, 0.15); 
	trs_de.Trap[MP]= Trapecio_Fuzzy( 0.10, 0.15, 1   , 1  ); 

	// Trapecio igual al de e.
	trs_du.Trap[MN]= Trapecio_Fuzzy(-1  ,-1  ,-0.3,-0.2);
	trs_du.Trap[N]=  Trapecio_Fuzzy(-0.3,-0.2,-0.1, 0  ); 
	trs_du.Trap[Z]=  Trapecio_Fuzzy(-0.1,   0, 0  , 0.1); 
	trs_du.Trap[P]=  Trapecio_Fuzzy(   0, 0.1, 0.2, 0.3); 
	trs_du.Trap[MP]= Trapecio_Fuzzy( 0.2, 0.3, 1  , 1  ); 

	CambiaEstado(CORRECTO); 
} 


BOOL SistExpert_Bloq_Reglas::NuevosObjDatos() 
{ 
	return true; 
} 
void SistExpert_Bloq_Reglas::DestObjDatos() 
{ 
 
} 
void SistExpert_Bloq_Reglas::GuardarFichero(CArchive& ar) 
{ 
	ar << X << Ek << Ek1 << T << Kr << Uk << Uk1 << Ajustar;

	for (int i=0; i < 5; i++)
	{
		for (int j=0; j < 5; j++)
		{
			ar << (int)reglas[i][j];
		}
	}

	trs_e.GuardarFichero(ar);	
	trs_de.GuardarFichero(ar);
	trs_du.GuardarFichero(ar);
} 

void SistExpert_Bloq_Reglas::LeerFichero(CArchive& ar) 
{ 
	ar >> X >> Ek >> Ek1 >> T >> Kr >> Uk >> Uk1 >> Ajustar;  

	for (int i=0; i < 5; i++)
	{
		for (int j=0; j < 5; j++)
		{
			ar >> (int&)reglas[i][j];
		}
	}

	trs_e.LeerFichero(ar);	
	trs_de.LeerFichero(ar);
	trs_du.LeerFichero(ar);

} 

BOOL SistExpert_Bloq_Reglas::PropiedadesBloque() 
{ 
	CDlgCtrlAdap_Ajuste dlgPreg( getMainWnd() );
	dlgPreg.m_Ajuste = Ajustar;
	if (dlgPreg.DoModal() == IDOK)
	{
		Ajustar = dlgPreg.m_Ajuste;
	}	

	return true; 
} 


BOOL SistExpert_Bloq_Reglas::Calc_Kr()
{
	double ep = Ek/X;
	if (ep > 1) ep = 1;
	else if (ep < -1) ep = -1;

	double dep = 0;
	if (0 == Ek1) // Ocurre la primera vez por lo menos
	{
		if (Ek > 0) dep = 1;
		else if (Ek < 0) dep = -1;
		else dep = 0;
	}
	else
	{
		dep = (Ek-Ek1)/Ek1;
		if (dep > 1) dep = 1;
		else if (dep < -1) dep = -1;
	}

	trs_e.CalcNivelEncajes(ep);
	trs_de.CalcNivelEncajes(dep);

	double res_encajes[5][5];

	for (int i=0; i < 5; i++)
	{
		for (int j=0; j < 5; j++)
		{
			res_encajes[i][j]=__min(trs_e.GetNivelEncaje(i),trs_de.GetNivelEncaje(j));
		}
	}

	// Tomando los máximos para cada regla de dKr para quitar duplicidades:
	// y dejando los resultados en el manejador fuzzy de dKr.
	for (int i=0; i < 5; i++)
	{	
		trs_du.SetNivelEncaje(i,0); // Inicializando (por si acaso)
	}

	for (int i=0; i < 5; i++)
	{
		for (int j=0; j < 5; j++)
		{
			enum_valdifuso regla = reglas[i][j];
			if (trs_du.GetNivelEncaje(regla) < res_encajes[i][j]) 
			{
				trs_du.SetNivelEncaje(regla, res_encajes[i][j]);
			}
		}
	}


	double pdu = trs_du.CalcCentroGravedad();

	// Si Uk = 0 el sistema de control deja de funcionar, esto está bien si pdu < 0 pues Uk no puede ser negativo.
	// Pero si pdu > 0 debería poder recuperarse el control, sin embargo 
	// Uk=0 lo dejaría clavado en cero, de ahí que hacemos que
	// Uk tome un valor de arranque no nulo
	
	double Ukest = (1 + pdu) * Uk;  // Nueva acción de control estimada

	if ((Ukest == 0)&&(pdu > 0)) Ukest = 10; // El valor inicial

	CString Mensaje;
	Mensaje.Format("%f",pdu);
	Mensaje = "pdu=" + Mensaje;
	AfxMessageBox(Mensaje);

	double Krtemp = (Ukest - Uk1)/Ek; // Ganacia necesaria

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



