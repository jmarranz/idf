// BloqueDiag.cpp: implementation of the CBloqueDiag class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "BloqueDiag.h"

#include "..\BloqueException.h"

#include "..\DiagBase.h"
#include "..\BaseDoc.h"
#include "..\BloqueUnidad.h"

#include "..\DiagramaException.h"

#include "exe\BloqueDiagExe.h"
#include "des\BloqueDiagDis.h"

#include "..\..\view\MainFrame.h"
#include "..\..\view\bdiag\BloqueDiagVistas.h"
#include "..\..\view\DiagramaVistas.h"

#include "..\..\xmlutil\XMLUtil.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CString CBloqueDiag::S_TIPO_DIAG = "diag";

IMPLEMENT_SERIAL(CBloqueDiag,CBloque,1)

CBloqueDiag::CBloqueDiag()
{	
	p_docHijo = NULL;
	p_bloqIni = NULL;
	p_bloqFin = NULL;

	m_esLDD = true;
}

CBloqueDiag::~CBloqueDiag()
{
	
}

void CBloqueDiag::Construir(CDiagBase* p)
{
	if (!p->EsDiagDiseno()) p_modo = new CBloqueDiagExe;
	else p_modo = new CBloqueDiagDis;

	p_modo->Construir(this);

	CBloque::Construir(p);
}

CComponenteDiagVistas* CBloqueDiag::CrearObjVistas()
{
	return new CBloqueDiagVistas();
}


void CBloqueDiag::LeerDatosLDD(DOMElement* bloque,DOMTreeWalker* walker)
{
	CBloque::LeerDatosLDD(bloque,walker);

	DOMElement* archivo = (DOMElement*)walker->nextSibling();
	m_fichDiag = XMLUtil::getTexto(archivo);

	m_esLDD = true;

	DOMElement* bloqueHijoIni = (DOMElement*)walker->nextSibling();
	m_bloqIni = XMLUtil::getTexto(bloqueHijoIni);

	DOMElement* bloqueHijoFin = (DOMElement*)walker->nextSibling();
	m_bloqFin = XMLUtil::getTexto(bloqueHijoFin);
	
	getModo()->ActualizaEstado();
} 	


void CBloqueDiag::EscribirDatosLDD(DOMElement* bloque)
{
    CBloque::EscribirDatosLDD( bloque );

	CString subDiagFichXML;
	try
	{
		p_docHijo->getDiag()->GenerarLDD(subDiagFichXML,true);
	}
	catch(Exception* ex)
	{
		getDiag()->getVistas()->Mensaje(ex);
		delete ex;
		throw new BloqueException(this,"No puede generarse el archivo XML");
	}

	DOMElement* archivo = XMLUtil::appendElement(bloque,"archivo");
	XMLUtil::setTexto(archivo,subDiagFichXML);

	DOMElement* bloqueHijoIni = XMLUtil::appendElement(bloque,"bloqueHijoIni");
	XMLUtil::setTexto(bloqueHijoIni,getClaveBloque(INICIODIAG));

	DOMElement* bloqueHijoFin = XMLUtil::appendElement(bloque,"bloqueHijoFin");
	XMLUtil::setTexto(bloqueHijoFin,getClaveBloque(FINDIAG));
}

void CBloqueDiag::Serialize(CArchive& ar)
{
	CBloque::Serialize(ar);  
	 
	if (ar.IsStoring())
	{	
		// Guarda los hijos de este diagrama.
        if (p_docHijo != NULL)  // recordar que puede ser un caso de proceso de destrucción aleatoria como al cerrar la aplicación.
        {
        	p_docHijo->SalvarModificado(false);    // Llama a OnFileSave() . Puede influir en EsLDD y FichDiag esta llamada (actualizaría)
		}   

		ar << m_esLDD;
		ar << m_fichDiag;
		ar << getClaveBloque(INICIODIAG);
		ar << getClaveBloque(FINDIAG);

		p_modo->Serialize(ar);
	}
	else
	{
		ar >> m_esLDD;
		ar >> m_fichDiag;	
		ar >> m_bloqIni;
		ar >> m_bloqFin;			

		p_modo->Serialize(ar);

		CrearDeFichero();
	}
}


CBloque* CBloqueDiag::getBloque(OrdenBloqueDiag tipo)
{
	if (tipo == INICIODIAG) return p_bloqIni;
	else return p_bloqFin;
}

CString CBloqueDiag::getClaveBloque(OrdenBloqueDiag tipo)
{
	if (tipo == INICIODIAG) 
	{
		if (p_bloqIni == NULL) return "";
		return p_bloqIni->getId();
	}
	else 
	{
		if (p_bloqFin == NULL) return "";
		return p_bloqFin->getId();
	}
}

void CBloqueDiag::setFich( CString& fich )
{
	m_fichDiag = fich;
	m_esLDD = false;
}

BOOL CBloqueDiag::PropiedadesCorrectas(CString& mensaje)
{
	// Redefinida de CBloque
	// En este nivel verificamos las variables que son específicas de CBloqueDiag
	// Devuelve false si hay algo mal y si todo está bien el valor devuelto del nivel superior

	BOOL OK = CBloque::PropiedadesCorrectas(mensaje);

	if ( m_fichDiag == "")
	{
		OK = false;
		mensaje += "No se ha definido el fichero del subdiagrama\r\n";
	}
	if ( getClaveBloque(INICIODIAG) == "")
	{
		OK = false;
		mensaje += "No se ha definido el nombre interno del bloque inicial del subdiagrama\r\n";
	}
	if ( getClaveBloque(FINDIAG) == "")
	{
		OK = false;
		mensaje += "No se ha definido el nombre interno del bloque final del subdiagrama\r\n";
	}	

	return OK;
}

void CBloqueDiag::setBloque(OrdenBloqueDiag tipo,CBloque* blq)
{
	if (INICIODIAG == tipo)
	{
		p_bloqIni = blq;
	}
	else
	{
		p_bloqFin = blq;
	}
}

void CBloqueDiag::setBloque(OrdenBloqueDiag tipo,const CString& idBloque)
{
	CDiagBase* psubDiag = p_docHijo->getDiag();

	CBloque* pblq = psubDiag->m_listaBloq.BuscaPorClave(idBloque); // Siempre bloques funcionales

	if (NULL == pblq)    // ERROR
	{
		CString stemp = "Enlazando con subdiagrama: el bloque [" + idBloque + "] no está definido en el subdiagrama";
		throw new BloqueException(this,stemp);
	}

	setBloque(tipo,pblq);

}

void CBloqueDiag::ConectarSubdiagrama()
{
	try
	{
		setBloque(INICIODIAG,m_bloqIni);
	}
	catch(Exception* ex)
	{
		if (!getDiag()->EsDiagDiseno())
			throw ex;
		else
			delete ex;
	}

	try
	{
		setBloque(FINDIAG,m_bloqFin);
	}
	catch(Exception* ex)
	{
		if (!getDiag()->EsDiagDiseno())
			throw ex;
		else
			delete ex;
	}
}

void CBloqueDiag::CrearNuevo( const Instante& t )
{
	ASSERT(m_esLDD); // Debe ser true

	CargaSubdiagrama();

	CBloque::CrearNuevo(t);
}

 
void CBloqueDiag::CrearDeFichero( )
{
	CargaSubdiagrama(); 

	CBloque::CrearDeFichero();
} 

void CBloqueDiag::CargaSubdiagrama( )
{
	CGlobal::p_bloqPadre = this; // El bloque papá cargador del diagrama nuevo.

	if (m_esLDD)
	{
		p_docHijo = (CBaseDoc*)CGlobal::NuevoDiagSinPrompt(getDiag()->EsDiagDiseno());
	}
	else
	{
		p_docHijo = (CBaseDoc*)CGlobal::AbrirDiagSinPrompt( getDiag()->FormarPathAbsoluto(m_fichDiag), getDiag()->EsDiagDiseno());
	}

	CGlobal::p_bloqPadre = NULL;   // Ya lo ha leido el nuevo diag.	

	if (p_docHijo == NULL) 
		throw new BloqueException(this,"No se ha podido crear el subdiagrama");  // Creación fallida.

	try
	{
		ConectarSubdiagrama();
	}
	catch(Exception* ex)
	{
		CerrarSubdiagrama(false);
		throw ex;
	}
}

void CBloqueDiag::CerrarSubdiagrama(BOOL cerradoAuto)
{
	if ((p_docHijo != NULL) && (!cerradoAuto))  // Si es CerradoAuto es el cerrado de la aplicación el responsable del cerrado de los docs. hijos.
	{
		p_docHijo->p_bloqPadre = NULL;		
		p_docHijo->SalvarModificado(true);   // Oportunidad para salvar a fichero.
		p_docHijo->OnCloseDocument();  // Destruye el documento irrevocablemente. Es posible que destruya el objeto por sí mismo.
		p_docHijo = NULL;
	}
}

void CBloqueDiag::Destruir()
{
	CMainFrame* pmainfrm = (CMainFrame*)AfxGetMainWnd();
	BOOL cerradoAuto = pmainfrm->m_cerradoAuto;

	CerrarSubdiagrama(cerradoAuto);

	CBloque::Destruir();
}

CString CBloqueDiag::getEtiqDiagHijo()
{
    if (p_docHijo != NULL) 
	{
		CDiagBase* pDiagHijo = p_docHijo->getDiag();
		return pDiagHijo->m_etiqueta;  // Sólo lectura.
	}
	else return "";
}

