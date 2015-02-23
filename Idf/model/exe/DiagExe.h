// DiagExe.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// Clase CDiagExe del diagrama para la plantilla funcional.

#ifndef CDIAGEXE
#define CDIAGEXE

class CConectExe;
class CConect;
class CBloque;
class CDiagExeBaseDoc;
class CDiagExeDoc;
class CBaseView;
class CBloqueDLLRetroanoExe;
class CDiagramaVistasExe;


#include "..\DiagBase.h"  // Para no tener que incluir repetidamente en cada cpp


class CDiagExe : public CDiagBase
{
	DECLARE_SERIAL(CDiagExe)
public:	

	CDiagExe();	
	virtual ~CDiagExe();
	virtual void Destruir();

	CDiagramaVistasExe* getVistas()
	{
		return (CDiagramaVistasExe*)p_vistas;
	}

	virtual void CrearNuevo();
	virtual void CrearDesdeFichero();

	virtual void IniciarExplicito();

	virtual CDiagramaVistas* CrearObjDiagramaVistas();

	virtual BOOL EsDiagDiseno() { return false; };
	
	virtual void Serialize(CArchive& ar);
 
//	virtual void RecolocarDlgBloques(CBaseView* view);


	virtual void IniciarBloquesExplicito();
	virtual void IniciarBloquesExplicito(ListaBloques* plista,const Instante& t);

	virtual void IniciarConectoresExplicito();
	virtual void IniciarConectoresExplicito(ListaConectores* plista);

	virtual BOOL IniciarDatosBloques();
	virtual BOOL IniciarDatosBloques(ListaBloques* plista);


	virtual CPoint CambiaSigno(CPoint& pto) const;
	virtual CRect  CambiaSigno(CRect& rect) const;	

	virtual void Consola(CString& mensaje, int origen = SISTEMA);


	virtual void ComienzoEjecucionAuto(CBloque* pBlqStart,CBaseView* view);


	virtual void AvisoCambioCarga();  // Avisa que el cambio en una propiedad dada s�lo se manifiesta tras guardar y cargar de nuevo de fichero.

public:


// Variables con valores temporales o cambiantes.

	CBloque* p_bloqUltimo;  // Apunta al �ltimo bloque que recibi� datos (normalmente ser� el siguiente a ejecutar) o el �ltimo ejecutado si no hubo comunicaci�n. Lo usa el CRectTracker

    BOOL m_modoAuto;  // Controla que el diagrama se ejecuta en modo Auto.

// Variables que se guardan a fichero 
	
};


#endif
