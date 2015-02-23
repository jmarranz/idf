
// conecdis.h

#ifndef CCONECTDIS
#define CCONECTDIS

#include "..\ConectModo.h"


class CDiagDis;
class CDiagDisView;
class CDlgNudoCon;
class CDlgBloque;
class CConNudo;
class CConectVistasDis;
class CConectVistas;
class CBloque;


class CConectDis : public CConectModo
{
	DECLARE_SERIAL(CConectDis)

public:
	CConectDis();                                                
	virtual ~CConectDis(); 

    virtual void CrearNuevo( const Instante& t );
    virtual void CrearDeFichero();

	virtual CComponenteDiagVistas* CrearObjVistas();

	virtual void ActualizaEstado(); 	

	// Exclusivas:

	virtual void AsociarBloque(CDiagDisView* view, CBloque* blq, CDlgBloque* dlgblq, CPoint point);
	
public:
    BOOL m_gravedad;     // Temporal, para mover un nudo por gravedad.
};

#endif


