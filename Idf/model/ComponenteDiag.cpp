// ComponenteDiag.cpp: implementation of the CComponenteDiag class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "ComponenteDiag.h"

#include "DiagBase.h"
#include "BaseDoc.h"
#include "ComponenteDiagException.h"

#include "..\view\ComponenteDiagVistas.h"

#include "..\xmlutil\XMLUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CComponenteDiag,CObject)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComponenteDiag::CComponenteDiag()
{
	p_diag = NULL;
	m_retroanotador = false;

	m_id = "";  
	m_etiqueta = "";
	m_ayuda = "Escribir aquí la ayuda asociada a la funcionalidad, se salvará junto al diagrama";
}

CComponenteDiag::~CComponenteDiag()
{

}

void CComponenteDiag::Construir(CDiagBase* p )
{
	p_diag = p;

	p_vistas = CrearObjVistas();
	p_vistas->Construir(this);
}

void CComponenteDiag::Destruir()
{
	p_vistas->Destruir();
}


void CComponenteDiag::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);  // Llamada conveniente al padre, aunque en la 1.0 no hace nada.
	
	if (ar.IsStoring())
	{
		ar << m_id;
		ar << m_retroanotador;
		ar << m_etiqueta;
		ar << m_ayuda;
	}
	else
	{
		CBaseDoc* pdoc = (CBaseDoc*)ar.m_pDocument;
		Construir(pdoc->getDiag());

		ar >> m_id;	
		ar >> m_retroanotador;
        ar >> m_etiqueta;		
		ar >> m_ayuda;
	}	
} 

BOOL CComponenteDiag::EsModoDiseno()
{
	return p_diag->EsDiagDiseno();
}

void CComponenteDiag::LeerDatosLDD( DOMElement* componente,DOMTreeWalker* walker)
{
	m_id = XMLUtil::getAttrTexto(componente,"id");

	DOMElement* etiqueta = (DOMElement*)walker->firstChild();
	m_etiqueta = XMLUtil::getTexto(etiqueta);

	DOMElement* ayuda = (DOMElement*)walker->nextSibling();
	m_ayuda = XMLUtil::getTexto(ayuda);
}

void CComponenteDiag::EscribirDatosLDD(DOMElement* componente)
{
	XMLUtil::setAttrTexto(componente,"id",getId());

	DOMElement* etiqueta = XMLUtil::appendElement(componente,"etiqueta");
	XMLUtil::setTexto(etiqueta,m_etiqueta);

	DOMElement* ayuda = XMLUtil::appendElement(componente,"ayuda");
	XMLUtil::setTexto(ayuda,m_ayuda);
}

const CString& CComponenteDiag::getId()   //No usar CString como retorno pues necesitamos el puntero a la cadena en memoria para acceder por un DLL
{
	return m_id;
}

void CComponenteDiag::setId(const CString& id)
{
	if (id == "") 
	{
		throw new ComponenteDiagException(this,"El nombre interno especificado no puede ser nulo");
	}
	if ((id != m_id) && !p_diag->EsNuevaClaveValida(id))
	{
		throw new ComponenteDiagException(this,"El nombre interno especificado está siendo usado por otro componente");
	}
	
	m_id = id;
}


const CString& CComponenteDiag::getEtiqueta()   //No usar CString como retorno pues necesitamos el puntero a la cadena en memoria para acceder por un DLL
{
	return m_etiqueta;
}

void CComponenteDiag::setEtiqueta(const CString& etiq)
{
	m_etiqueta = etiq;
}

const CString& CComponenteDiag::getAyuda()
{
	return m_ayuda; 
}

void CComponenteDiag::setAyuda( const CString& ayuda )
{
	m_ayuda = ayuda;
}   

BOOL CComponenteDiag::PropiedadesCorrectas() 
{
	CString inutil;
	return PropiedadesCorrectas(inutil);
}

BOOL CComponenteDiag::PropiedadesCorrectas(CString& mensaje)
{
	// Sólo es llamada tras modificar las propiedades del conector
	// a través de los diálogos de propiedades
	// Analiza los campos que 
	// son obligatorios de especificar para que funcione el diagrama.
	// Si todos los campos son correctamente definidos entonces	devuelve true
	// En el argumento "mensaje" pasado se escribe aquellos fallos que se han encontrado.

	BOOL OK = true;

	if ( m_id == "") // Seguramente no ocurrirá nunca
	{
		OK = false;
		mensaje += "No se ha especificado un nombre interno\r\n";
	}

	return OK;
}

