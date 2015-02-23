

#include "stdafx.h"

#include "..\DLLDiag.h"

#include "DlgCtrlAdap_R.h"
#include "DlgCtrlAdap_Ajuste.h"

#include "CtrlAdap_Com_Ley_R.h"
#include "CtrlAdap_Com_Var.h"

#include "CtrlAdap_Bloq_Regulador.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(CtrlAdap_Bloq_Regulador,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: CtrlAdap_Bloq_Regulador
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Ley_R,CtrlAdap_Bloq_Regulador) 
BOOL CtrlAdap_Bloq_Regulador::RecibirDatosEntrada(CtrlAdap_Com_Ley_R* pE) 
{ 
	if (Ajustar) // Permitir ajustar por un bloque externo
	{
		if (pE->Kr > 0) Kr = pE->Kr;
		// En otro caso no es válido conservar el valor actual
	}

	return true;
} 
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Regulador) 
BOOL CtrlAdap_Bloq_Regulador::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	e = pE->Var;
	T = pE->T;

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: CtrlAdap_Bloq_Regulador
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Var,CtrlAdap_Bloq_Regulador) 
void CtrlAdap_Bloq_Regulador::EnviarDatosSalida(CtrlAdap_Com_Var* pS) 
{ 
	pS->Var = du;
	pS->T = T;
} 

void CtrlAdap_Bloq_Regulador::IniciarDatos() 
{ 
	e = 0;
	du = 0;
	Kr = 10;
	T = 1;

	Ajustar = true;

	CambiaEstado(CORRECTO);
} 
BOOL CtrlAdap_Bloq_Regulador::NuevosObjDatos() 
{ 
	return true; 
} 
void CtrlAdap_Bloq_Regulador::DestObjDatos() 
{ 
 
} 
void CtrlAdap_Bloq_Regulador::GuardarFichero(CArchive& ar) 
{ 
	ar << e << du << Kr << T << Ajustar;
} 
void CtrlAdap_Bloq_Regulador::LeerFichero(CArchive& ar) 
{ 
	ar >> e >> du >> Kr >> T >> Ajustar; 
} 
CString CtrlAdap_Bloq_Regulador::Accion() 
{ 
	/*	if (!EsModoAuto())  */
	{
		CDlgCtrlAdap_R dlg( getMainWnd() );
		dlg.m_Kr = Kr;

		if (dlg.DoModal() == IDOK)
		{
			Kr = dlg.m_Kr;
		}
	}

	du = Kr * e;

	CString Mensaje;
	Mensaje.Format("%f",du);
	Mensaje = "du(k)=" + Mensaje;
	AfxMessageBox(Mensaje);

	return ""; 
} 
BOOL CtrlAdap_Bloq_Regulador::PropiedadesBloque() 
{ 
	CDlgCtrlAdap_Ajuste dlgPreg( getMainWnd() );
	dlgPreg.m_Ajuste = Ajustar;
	if (dlgPreg.DoModal() == IDOK)
	{
		Ajustar = dlgPreg.m_Ajuste;
	}	

	/*	if (!EsModoAuto())  */
	{
		CDlgCtrlAdap_R dlg( getMainWnd() );
		dlg.m_Kr = Kr;

		if (dlg.DoModal() == IDOK)
		{
			Kr = dlg.m_Kr;
		}
	}

	return true; 
} 
