// DiagramaVistasExe.h: interface for the CDiagramaVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIAGRAMAVISTASEXE_H__CF11BA05_A61B_4011_89BA_ABFCD1B78B74__INCLUDED_)
#define AFX_DIAGRAMAVISTASEXE_H__CF11BA05_A61B_4011_89BA_ABFCD1B78B74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\DiagramaVistas.h"

class CDlgLog;
class CDibDiagramaExe;


class CDiagramaVistasExe : public CDiagramaVistas  
{
public:
	CDiagramaVistasExe();
	virtual ~CDiagramaVistasExe();

	CDibDiagramaExe* getDibDiagrama()
	{
		return (CDibDiagramaExe*)p_dibDiagrama;
	}

	virtual void Construir(CDiagBase* pdiag);
	virtual void Serialize(CArchive& ar);

	virtual CDibDiagrama* CrearObjDibDiagrama();

	void CrearLog();
	void DestruirLog();
	void ActualizaTituloLog(CString& titulo);
	virtual void Consola(CString& mensaje, int origen = SISTEMA);
	void CambiarMostrarConsola();

	virtual void setNombreDiagrama( const char* nombre );

// Diálogo consola:
public:	
	CDlgLog* m_log;       // Diálogo de la consola.

    // Variables relacionadas con la consola (las de estado se guardan a fichero).

    BOOL m_conSistema;  // Mostrar los mensajes del sistema.
	BOOL m_conUsuario;  // Mostrar los mensajes del usuario.
    BOOL m_mostrarConsola;  // Mostrar diálogo de consola.
	BOOL m_salvarConsola; // Se salva la consola a fichero cuando se guarde el diagrama si es true
};

#endif // !defined(AFX_DIAGRAMAVISTASEXE_H__CF11BA05_A61B_4011_89BA_ABFCD1B78B74__INCLUDED_)
