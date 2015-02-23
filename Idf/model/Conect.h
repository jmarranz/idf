// Conect.h: interface for the CConect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECT_H__07F34F9B_5C1E_4638_A0C3_941AC1A8BF3B__INCLUDED_)
#define AFX_CONECT_H__07F34F9B_5C1E_4638_A0C3_941AC1A8BF3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComponenteDiag.h"

#include "Instante.h"

class CConectExe;
class CConectDis;
class CDiagBase;
class CBloque;
class CDibConect;
class CConectVistas;
class DOMElement;
class CConectModo;
class CConectInicio;
class CConectFin;
class DOMTreeWalker;


// Estados del conector funcionalmente

typedef enum
 	{ NOCIRCULA, CIRCULA, FALLIDO } EstadosConector;


class CConect : public CComponenteDiag  
{
	DECLARE_SERIAL(CConect)

public:
	friend class CConectVistas;

	CConect();
	virtual ~CConect();
	virtual void Construir(CDiagBase* diag);
    virtual void Destruir();

    virtual void CrearNuevo( const Instante& t );
    virtual void CrearDeFichero();

	virtual BOOL esConector() 
	{ 
		return true; 
	}

	virtual CComponenteDiagVistas* CrearObjVistas();

	virtual void Serialize(CArchive& ar);
	virtual void LeerDatosLDD(DOMElement* conector,DOMTreeWalker* walker);
	virtual void EscribirDatosLDD(DOMElement* conector);	

	CConectVistas* getVistas()
	{
		return (CConectVistas*)p_vistas;
	}

	CConectModo* getModo()
	{
		return p_modo;
	}

	CConectExe* getExe()
	{
		return (CConectExe*)p_modo;
	}

	CConectDis* getDis()
	{
		return (CConectDis*)p_modo;
	}

	CConectInicio* getInicio()
	{
		return (CConectInicio*)p_inicio;
	}

	void setInicio(const CString& idBloque);
	void setInicio(CBloque* pblq);

	CConectFin* getFin()
	{
		return (CConectFin*)p_fin;
	}

	void setFin(const CString& idBloque);
	void setFin(CBloque* pblq);

	virtual EstadosConector getEstado();
	virtual void setEstado(EstadosConector estado);

	virtual BOOL PropiedadesCorrectas(CString& mensaje);  // Devuelve true si las propiedades obligatorias del bloque están bien definidas


protected:  
	CConectModo* p_modo;
	CConectInicio* p_inicio;
	CConectFin* p_fin;

	EstadosConector m_estado;	

public:

	// No se cambian en ejecución una vez inicializadas (salvo en modo diseño):

	CString m_claseDatosComunic;  // En tiempo de creación o carga sirve para definir el objeto de comunicaciones a usar.
};

#endif // !defined(AFX_CONECT_H__07F34F9B_5C1E_4638_A0C3_941AC1A8BF3B__INCLUDED_)
