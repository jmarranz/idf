// DiagramaVistasExe.cpp: implementation of the CDiagramaVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagramaVistasExe.h"

#include "dlglog.h"

#include "DibDiagramaExe.h"

#include "..\..\model\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDiagramaVistasExe::CDiagramaVistasExe()
{
    m_conUsuario = true;
    m_conSistema = true;
	m_mostrarConsola = true;
	m_salvarConsola = true;	

	m_log = NULL;
}

CDiagramaVistasExe::~CDiagramaVistasExe()
{
	if (m_log != NULL) delete m_log;
}

void CDiagramaVistasExe::Construir(CDiagBase* pdiag)
{
	CDiagramaVistas::Construir(pdiag);

	m_log = new CDlgLog(pdiag->getExe());
}

CDibDiagrama* CDiagramaVistasExe::CrearObjDibDiagrama()
{
	return new CDibDiagramaExe();
}

void CDiagramaVistasExe::CrearLog()
{
    m_log->Crear();  // Crear consola.
}

void CDiagramaVistasExe::DestruirLog()
{
	if (m_log)
	{
		m_log->DestroyWindow();
		delete m_log;
		m_log = NULL;
		// Se ha comprobado que al destruir como se destruye la consola
		// después de la ventana del diagrama la consola pasa a ser la activa
		// pero acto seguido se destruye y accidentalmente pasa a ser activa la
		// ventana de otro programa diferente.
		// Por ello hacemos activo el mainframe para evitar esto
		CMDIFrameWnd* pmainframe = (CMDIFrameWnd*)AfxGetMainWnd();
		pmainframe->ActivateFrame(SW_SHOW); // Activa de nuevo y restaura el estado. 	
	}
}

void CDiagramaVistasExe::Serialize(CArchive& ar)
{
	CDiagramaVistas::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_conUsuario << m_conSistema << m_mostrarConsola << m_salvarConsola;    // Guarda el estado de la consola.
	}
	else
	{
		ar >> m_conUsuario >> m_conSistema >> m_mostrarConsola >> m_salvarConsola;
	}

	if (m_log) m_log->Serializar(ar);
}

void CDiagramaVistasExe::ActualizaTituloLog(CString& titulo)
{
	if (m_log) m_log->ActualizaTitulo( "Consola - " + titulo );
}

void CDiagramaVistasExe::Consola(CString& mensaje, int origen)
{
	switch (origen)
	{
		case SISTEMA:
		{
			if (!m_conSistema) return;
			mensaje = "SISTEMA: " + mensaje;	
			break;
		}
		case USUARIO:
		{
			if (!m_conUsuario) return;			
			mensaje = "USUARIO: " + mensaje;	
			break;
		}	
	}

	if (m_log) m_log->Anyadir(mensaje);  // Necesaria comprobación pues en destrucción es posible que algún bloque envíe mensajes
}

void CDiagramaVistasExe::CambiarMostrarConsola()
{
	m_mostrarConsola = !m_mostrarConsola;	

	if (m_mostrarConsola)
	{
		m_log->DestroyWindow();  // Aunque existiera no pasa nada.
		m_log->Crear();			
	}
	else
	{
		if (NULL != EsValidaVentana(m_log))
		{
			m_log->ConsolaSalir();
		}	
    }	

}

void CDiagramaVistasExe::setNombreDiagrama( const char* nombre )
{
	ActualizaTituloLog(CString(nombre));
}

