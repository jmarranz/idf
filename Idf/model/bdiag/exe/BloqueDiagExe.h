 
// bloqdiag.h

// Derivada de CBloque, da capacidad a éste de manejar bloques que encapsulan un diagrama
// para diagramas multidiagrama.

#ifndef CBLOQUEDIAG
#define CBLOQUEDIAG


#include "..\..\exe\BloqueExe.h"


class CDiagExeBaseDoc;
class CDiagExeDoc;
class CBaseView;
class Instante;
class CBloqueVistas;
class CBloqueDiag;


enum TipoEstadoInterno;
enum TipoEstadoUsuario;


class CBloqueDiagExe : public CBloqueExe
{
	DECLARE_SERIAL(CBloqueDiagExe)

// Construction
public:
	CBloqueDiagExe();
	virtual ~CBloqueDiagExe();  // No hace nada
  
	CBloqueDiag* getBloque()
	{
		return (CBloqueDiag*)p_bloque;
	}

    // Redefinidas de CBloqueDiag:
    
    virtual void CrearNuevo(const Instante& t );
    virtual void CrearDeFichero();

	virtual BOOL IniciarDatosBloque() { return true; };
	virtual void IniciarExplicito(const Instante& t); 
	virtual void IniciarConectores(); 

	virtual CString Accion(CBaseView* view);

	virtual BOOL CambiaEstado(TipoEstadoUsuario estado);	
	virtual TipoEstadoUsuario getEstadoUsr();
	virtual TipoEstadoInterno getEstadoInt();	
	virtual void setEstadoUsr(TipoEstadoUsuario estado);
	virtual void setEstadoInt(TipoEstadoInterno estado);
	virtual BOOL EsNuevo();

	
	virtual void EnError(int TipoError, CBloque* bloque);    

	virtual Instante getTiempo();


// Exclusivas de CBloqueDiag:

public:  

	
	// Variables:
public:	

};


#endif

