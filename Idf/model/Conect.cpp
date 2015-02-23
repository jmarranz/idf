// Conect.cpp: implementation of the CConect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "Conect.h"

#include "Bloque.h"
#include "DiagBase.h"
#include "ConectModo.h"
#include "ConectInicio.h"
#include "ConectFin.h"
#include "ConectorException.h"

#include "exe\ConectExe.h"
#include "des\ConectDis.h"

#include "dll\ConectInicioDLL.h"
#include "dll\ConectFinDLL.h"


#include "..\view\ConectVistas.h"

#include "..\xmlutil\XMLUtil.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CConect,CComponenteDiag,1)                


CConect::CConect()
{
	p_modo = NULL;
	p_vistas = NULL;

	p_inicio = NULL;
	p_fin = NULL;

	m_estado = NOCIRCULA;
	m_claseDatosComunic = "NULO"; // El objeto nulo de comunicaciones que siempre existe.

}

CConect::~CConect()
{
	delete p_modo;
	delete p_vistas;
	if (p_inicio != NULL) delete p_inicio;
	if (p_fin != NULL) delete p_fin;
}


void CConect::Construir(CDiagBase* diag)
{
	if (!diag->EsDiagDiseno())
		p_modo = new CConectExe();
	else
		p_modo = new CConectDis();
	p_modo->Construir(this);

	CComponenteDiag::Construir(diag);
}

void CConect::CrearNuevo(const Instante& t)
{
}

void CConect::CrearDeFichero()
{
}

void CConect::Destruir()
{
	p_vistas->Destruir();

	if (p_inicio != NULL) p_inicio->Destruir();
	if (p_fin != NULL) p_fin->Destruir();

	delete this;
}


CComponenteDiagVistas* CConect::CrearObjVistas()
{
	return p_modo->CrearObjVistas();
}

EstadosConector CConect::getEstado()
{
	return m_estado;
}

void CConect::setEstado(EstadosConector estado)
{
	m_estado = estado;
}


void CConect::Serialize(CArchive& ar)
{
	CComponenteDiag::Serialize(ar);
	
	if (ar.IsStoring())
	{
		ar << m_claseDatosComunic;
        ar << (int)m_estado;

		CString idBloqueIni;
		if (p_inicio != NULL) idBloqueIni = p_inicio->getBloque()->getId();
		ar << idBloqueIni;

		CString idBloqueFin;
		if (p_fin != NULL) idBloqueFin = p_fin->getBloque()->getId();
		ar << idBloqueFin;

		if (p_inicio != NULL) 
			p_inicio->Serialize(ar);

		if (p_fin != NULL) 
			p_fin->Serialize(ar);
	}
	else
	{
		ar >> m_claseDatosComunic;
	    ar >> (int&)m_estado;

		CString idBloqueIni;
		ar >> idBloqueIni;		
		setInicio(idBloqueIni);

		CString idBloqueFin;
		ar >> idBloqueFin;
		setFin(idBloqueFin);

		CrearDeFichero();
	}

	p_vistas->Serialize(ar);	

	// p_modo->Serialize(ar); // Por ahora no serializa nada
}

void CConect::LeerDatosLDD(DOMElement* conector,DOMTreeWalker* walker)
{
	CComponenteDiag::LeerDatosLDD(conector,walker);

	DOMElement* claseDatosCom = (DOMElement*)walker->nextSibling();
	m_claseDatosComunic = XMLUtil::getTexto(claseDatosCom);

	DOMElement* bloqueAnterior = (DOMElement*)walker->nextSibling();
	CString idBloqueIni = XMLUtil::getTexto(bloqueAnterior);

	setInicio(idBloqueIni);

	DOMElement* bloquePosterior = (DOMElement*)walker->nextSibling();
	CString idBloqueFin = XMLUtil::getTexto(bloquePosterior);

	setFin(idBloqueFin);

	DOMElement* vistas = (DOMElement*)walker->nextSibling();

	p_vistas->LeerDatosLDD(vistas,walker);
}


void CConect::EscribirDatosLDD(DOMElement* conector)
{
	CComponenteDiag::EscribirDatosLDD(conector);

	DOMElement* claseDatosCom = XMLUtil::appendElement(conector,"claseDatosCom");
	XMLUtil::setTexto(claseDatosCom,m_claseDatosComunic);

	DOMElement* bloqueAnterior = XMLUtil::appendElement(conector,"bloqueAnterior");
	XMLUtil::setTexto(bloqueAnterior,p_inicio->getBloque()->getId());

	DOMElement* bloquePosterior = XMLUtil::appendElement(conector,"bloquePosterior");
	XMLUtil::setTexto(bloquePosterior,p_fin->getBloque()->getId());

	DOMElement* vistas = XMLUtil::appendElement(conector,"vistas");

	p_vistas->EscribirDatosLDD(vistas);
}


void CConect::setInicio(CBloque* pblq)
{
	if (p_inicio != NULL) 
	{
		p_inicio->Destruir();
		delete p_inicio;
	}
	if (pblq != NULL)
		p_inicio = (CConectInicio*)CConectExtremo::crear(CON_INICIO,pblq,this);
	else 
		p_inicio = NULL;

	getModo()->ActualizaEstado();
}

void CConect::setInicio(const CString& idBloque)
{
	CBloque* pblq = CConectExtremo::buscarBloque(CON_INICIO,idBloque,this);

	if ((NULL == pblq) && !getDiag()->EsDiagDiseno())
	{
		// ERROR: NO EXISTE conexión a bloque anterior .
		throw new ConectorException(this,"No está definido el bloque inicio [" + idBloque + "]");
	} 
	
	setInicio(pblq);
}

void CConect::setFin(CBloque* pblq)
{
	if (p_fin != NULL) 
	{
		p_fin->Destruir();
		delete p_fin;
	}
	if (pblq != NULL)
		p_fin = (CConectFin*)CConectExtremo::crear(CON_FIN,pblq,this);
	else 
		p_fin = NULL;

	getModo()->ActualizaEstado();
}

void CConect::setFin(const CString& idBloque)
{
	CBloque* pblq = CConectExtremo::buscarBloque(CON_FIN,idBloque,this);

	if ((NULL == pblq) && !getDiag()->EsDiagDiseno())
	{
		// ERROR: NO EXISTE conexión a bloque posterior del diagrama
		throw new ConectorException(this,"No está definido el bloque final [" + idBloque + "]");
	}	
	
	setFin(pblq);
}


BOOL CConect::PropiedadesCorrectas(CString& mensaje)
{
	BOOL OK = CComponenteDiag::PropiedadesCorrectas(mensaje);

	if (p_inicio == NULL)
	{
		OK = false;
		mensaje += "No se ha definido un bloque comienzo\r\n";
	}

	if (p_fin == NULL)
	{
		OK = false;
		mensaje += "No se ha definido un bloque fin\r\n";
	}

	if ( m_claseDatosComunic == "")
	{
		OK = false;
		mensaje += "No se ha espeficicado el nombre de la clase del objeto de comunicación que circula por el conector\r\n";
	}

	return OK;
}




