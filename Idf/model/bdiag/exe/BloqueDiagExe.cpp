
// BloqueDiagExe.cpp

#include "stdafx.h"
#include "..\..\..\Idf.h"
#include "BloqueDiagExe.h"

#include "..\BloqueDiag.h"
#include "..\..\exe\DiagExe.h"
#include "..\..\exe\DiagExeDoc.h"

#include "..\..\..\view\MainFrame.h"
#include "..\..\..\view\BaseView.h"
#include "..\..\..\view\bdiag\BloqueDiagVistas.h"
#include "..\..\..\view\bdiag\exe\BloqueDiagVistasExe.h"



IMPLEMENT_SERIAL(CBloqueDiagExe,CBloqueExe,1)     // La base CBloque es pura por lo que referimos a la superior CObject

CBloqueDiagExe::CBloqueDiagExe()  // Es llamada por la serialización
{

}


CBloqueDiagExe::~CBloqueDiagExe() 
{

}


void CBloqueDiagExe::CrearNuevo( const Instante& t )
{
	CambiaEstado(getBloque()->getBloqueFin()->getEstadoUsr());
}

 
void CBloqueDiagExe::CrearDeFichero( )
{
	CambiaEstado(getBloque()->getBloqueFin()->getEstadoUsr());
} 
 

void CBloqueDiagExe::IniciarExplicito(const Instante& t)  
{
	CBloqueExe::IniciarExplicito(t);

	CDiagExeBaseDoc* pdocHijo = (CDiagExeBaseDoc*)getBloque()->getSubdiagrama();
	pdocHijo->getDiag()->IniciarExplicito();	
}

void CBloqueDiagExe::IniciarConectores()  
{
	CDiagExe* pDiag = getBloque()->getSubdiagrama()->getDiag()->getExe();
	pDiag->IniciarConectoresExplicito();	
}


CString CBloqueDiagExe::Accion(CBaseView* view)  // Ejecuta en modo Auto todo el diagrama hijo, pero no sigue el padre al ser local al diagrama la variable de modo Auto.
{
	// Preparamos la ventana del diagrama hijo para que sea visible
	// o lo que se haya especificado

	CBloqueDiag* pbloque = getBloque();

	// Nota: se debería llevar este código a una función para despejar

	CBloqueDiagVistas* pvistas = getBloque()->getVistas();

	CBaseView *viewsubdiag = pvistas->getViewSubDiagrama();
	CMDIChildWnd* mdichildsubdiag = (CMDIChildWnd *) viewsubdiag->GetParentFrame( );
	int antMostrarSub = CBloqueDiagVistas::getEstado(mdichildsubdiag);

	CMDIChildWnd* mdichildPadre = (CMDIChildWnd *) view->GetParentFrame( );
	int antMostrarPadre = CBloqueDiagVistas::getEstado(mdichildPadre);

	pvistas->ActivarFrameSubDiagrama(mdichildsubdiag);

	getBloque()->getBloqueFin()->getExe()->m_etiqContinuar = NO_FINAL_AUTO;  // Si no se modifica este valor es que no ha terminado bien el modo Auto en el bloque hijo. NO_FINAL_AUTO es una cadena rara. 

 	getBloque()->getBloqueInicio()->getExe()->ComienzoEjecucionAuto(viewsubdiag);  // Que tome como ventana la propia del diagrama hijo (no la del padre).
	
	CString etiqContinuar = getBloque()->getBloqueFin()->getExe()->m_etiqContinuar; // Si llegó hasta el final EtiqContinuar será diferente a NO_FINAL_AUTO

	if ( NO_FINAL_AUTO == etiqContinuar) 
		getBloque()->getDiagExe()->m_modoAuto = false; 

	// Se restaura la ventana del subdiagrama a su estado original
	mdichildsubdiag->ShowWindow(antMostrarSub);

	// Se recupera la ventana y el documento activo original del diagrama superior al salir del subdiagrama.
	// Restauramos como ventana activa la original:
	mdichildPadre->ActivateFrame(antMostrarPadre); // Activa de nuevo y restaura el estado. 	
	
	return etiqContinuar;   // Así puede decidir por donde continuar. Notar que se define desde el diagrama hijo.
}


void CBloqueDiagExe::EnError(int TipoError, CBloque* bloque)
{
	getBloque()->getBloqueFin()->getExe()->EnError( TipoError, bloque );   // Lo procesa el último bloque del diagrama hijo, pues el error único hasta ahora es el de datos rechazados, y es el último bloque al que se cogen datos por un bloque del padre.
}


BOOL CBloqueDiagExe::CambiaEstado(TipoEstadoUsuario estado)
{
	if (getBloque()->getBloqueFin())  // En tiempo de creación puede dar error sin esta comprobación.
	{
		return getBloque()->getBloqueFin()->CambiaEstado(estado);
	}
	return false;
}

TipoEstadoUsuario CBloqueDiagExe::getEstadoUsr()
{
	return getBloque()->getBloqueFin()->getEstadoUsr();  // Dependerá del último bloque.
}

TipoEstadoInterno CBloqueDiagExe::getEstadoInt()
{
	return getBloque()->getBloqueInicio()->getEstadoInt();   // Dependerá del primer bloque del diag. hijo. Si el primero ha sido modificado es que ha sido tocado
}

void CBloqueDiagExe::setEstadoUsr(TipoEstadoUsuario estado)
{
	getBloque()->getBloqueFin()->setEstadoUsr(estado);
}

void CBloqueDiagExe::setEstadoInt(TipoEstadoInterno estado)
{
	getBloque()->getBloqueInicio()->setEstadoInt(estado);
}

BOOL CBloqueDiagExe::EsNuevo()   // true si nunca ha sido modificado.
{
	return getBloque()->getBloqueFin()->EsNuevo();
}


Instante CBloqueDiagExe::getTiempo()
{
	CDiagExe* pdiag = (CDiagExe*)getBloque()->getSubdiagrama()->getDiag();
	return pdiag->getTiempo();
}

