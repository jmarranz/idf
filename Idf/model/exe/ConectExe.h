
// Conect.h   Clase Base Conectores


#ifndef CCONECTEXE_H
#define CCONECTEXE_H

#include "..\ConectModo.h"

class CComunicacion;
class CBloque;
class CDiagExe;
class CDibConect;
class CConectExe;
class CConectVistasExe;
class CConectVistas;


class CConectExe : public CConectModo
{
 	DECLARE_SERIAL(CConectExe)
public:
	CConectExe();
	virtual ~CConectExe();    

    virtual void CrearNuevo( const Instante& t ) {  };
    virtual void CrearDeFichero() {  };

	virtual CComponenteDiagVistas* CrearObjVistas();

	virtual void IniciarExplicito();


	virtual void ActualizaEstado() { };


// Variables:

protected:	


};

#endif

