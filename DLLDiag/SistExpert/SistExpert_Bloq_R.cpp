
#include "stdafx.h"


#include "..\DLLDiag.h"

#include "..\CtrlAdap\DlgCtrlAdap_R.h"
#include "..\CtrlAdap\DlgCtrlAdap_Ajuste.h"
#include "..\CtrlAdap\CtrlAdap_Com_Var.h"

#include "SistExpert_Com_Ley_R.h"

#include "SistExpert_Bloq_R.h"


IMPLEMENTAR_BLOQUE_FUNCIONAL(SistExpert_Bloq_R,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: SistExpert_Bloq_R
IMPLEMENTAR_COM_ENTRADA(SistExpert_Com_Ley_R,SistExpert_Bloq_R) 
BOOL SistExpert_Bloq_R::RecibirDatosEntrada(SistExpert_Com_Ley_R* pE) 
{ 
	if (Ajustar) // Permitir ajustar por un bloque externo
	{
		Kr = pE->Kr;
	}

	return true;
} 
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,SistExpert_Bloq_R) 
BOOL SistExpert_Bloq_R::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	e = pE->Var;
	T = pE->T;

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: SistExpert_Bloq_R
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Var,SistExpert_Bloq_R) 
void SistExpert_Bloq_R::EnviarDatosSalida(CtrlAdap_Com_Var* pS) 
{ 
	pS->Var = du;
	pS->T = T; 
} 

void SistExpert_Bloq_R::IniciarDatos() 
{ 
	e = 0;
	du = 0;
	Kr = 10;
	T = 1;

	Ajustar = true;

	CambiaEstado(CORRECTO); 
} 
BOOL SistExpert_Bloq_R::NuevosObjDatos() 
{ 
	return true; 
} 
void SistExpert_Bloq_R::DestObjDatos() 
{ 
 
} 
void SistExpert_Bloq_R::GuardarFichero(CArchive& ar) 
{ 
	ar << e << du << Kr << T << Ajustar; 
} 
void SistExpert_Bloq_R::LeerFichero(CArchive& ar) 
{ 
	ar >> e >> du >> Kr >> T >> Ajustar;  
} 
CString SistExpert_Bloq_R::Accion() 
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
BOOL SistExpert_Bloq_R::PropiedadesBloque() 
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
