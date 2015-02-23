
// basedoc.cpp

#include "stdafx.h"
#include "..\Idf.h"
#include "BaseDoc.h"

#include "DiagBase.h"
#include "bdiag\BloqueDiag.h"

#include "..\Exception.h"

#include "..\view\BaseView.h"
#include "..\view\MainFrame.h"
#include "..\view\DiagramaVistas.h"


BEGIN_MESSAGE_MAP(CBaseDoc, CDocument)
	//{{AFX_MSG_MAP(CBaseDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

IMPLEMENT_DYNAMIC(CBaseDoc, COleServerDoc)

const DWORD CBaseDoc::m_aVerP = 1;  // Versión de la plantilla. 
const DWORD CBaseDoc::m_aRevP = 1;  // Revisión del idem.

CBaseDoc::CBaseDoc()
{
	// TODO: add one-time construction code here

	p_bloqPadre = NULL;
	p_diag = NULL;
	p_conectTmp	= NULL;

	m_puedoCerrarCadena = false;

	m_programa = "IDF Diagrama";
}

CBaseDoc::~CBaseDoc()
{
	DestruirDiag(); // Por si acaso
}

BOOL CBaseDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return false;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	if (IsEmbedded()) // Sólo es útil en modo ejecución
	{
		// Ver las notas de OleTemplateServerIdf.h
		CIdfApp* pApp = (CIdfApp*)AfxGetApp();
		if (pApp->CreandoObjetoBase()) return true;
	}

	p_diag = CrearObjDiag();
	
	try
	{
		p_diag->CrearNuevo();
	}
	catch(Exception* ex)
	{
		getDiag()->getVistas()->Mensaje(ex);
		DestruirDiag();

		delete ex;
		return false;
    }
		
	// Hacemos al final PuedoCerrarCadena=true, porque si algo falla y se sale por false con 
	// PuedoCerrarCadena a true, al destruirse el documento destruirá el documento padre consigo
	// y luego el proceso normal tendería a destruir al padre, luego se destruiría dos veces
	// cuando la destrucción en cadena sólo ha de producirse cuando se cierra el documento
	// a través de las ventanas

	if (p_bloqPadre != NULL) m_puedoCerrarCadena = true;  

	return true;
}


BOOL CBaseDoc::OnOpenDocument( const char* pszPathName )
{
	// La inicialización si es multidiagrama de parámetros de enlace se hace en Serialize

	if (!COleServerDoc::OnOpenDocument( pszPathName ))  // Llama a DeleteContents y a Serialize que carga el diagrama. No hace falta new pues se creará dinámicamente.
	{
		CString stemp;
		stemp = "ERROR en la creación del diagrama desde el fichero:\r\n" + CString(pszPathName); 
		CGlobal::Mensaje((CString)stemp); 
		return false;
	}    

	getDiag()->setNombreDiagrama(pszPathName);	// Admite pszPathName == NULL

	if (p_bloqPadre != NULL)  m_puedoCerrarCadena = true; // Importante hacerlo al final. Ver OnNewDocument para más información

	return true;
}

COleServerItem* CBaseDoc::OnGetEmbeddedItem()
{
	return NULL;
}

void CBaseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_programa;		

		ar << m_aVerP << m_aRevP;		
	}
	else
	{
		if (CGlobal::p_bloqPadre != NULL)  // Inicialización si es Multidiagrama (similar a lo que hay en OnNewDocument)
		{
			p_bloqPadre = CGlobal::p_bloqPadre;
		}
		
		CString tempProg;
		ar >> tempProg;
	    if (tempProg != m_programa)
	    {
			ErrorFichDesc();
			AfxThrowArchiveException(CArchiveException::badIndex);            
	    }

		ar >> m_dVerP >> m_dRevP;   // En el futuro se podrá hacer una carga de datos que abarque versiones antiguas a través del chequeo de estos números comunes a todas las versiones.
	    if ((m_dVerP != m_aVerP)&&(m_dRevP != m_aRevP)) 
	    {
			ErrorFichDesc();
			AfxThrowArchiveException(CArchiveException::badIndex);    
	    }
	}
	// Calling the base class COleServerDoc enables serialization
	//  of the container document's COleClientItem objects.
    COleServerDoc::Serialize(ar);
}


void CBaseDoc::ErrorFichDesc()
{
	CGlobal::Mensaje("ERROR: Fichero de formato desconocido o versión no manejada");
}

void CBaseDoc::DeleteContents()
{
	COleServerDoc::DeleteContents();	// delete doc-items
	
	// TODO: add additional cleanup before doc-items are deleted
	DestruirDiag();
}

void CBaseDoc::DestruirDiag()
{
	if (p_diag != NULL)  // Por más seguridad.
	{
		p_diag->Destruir();  // Destruye bloques, consola etc. También el this
 		delete p_diag;
	}
	p_diag = NULL;
}

void CBaseDoc::SalvarModificado(BOOL confirm)
{
	if (confirm)
	{
		// Pide confirmación del fichero (es un SaveAs)
		SaveModified();
	}
	else 
	{
		// Si no se ha salvado nunca se pide archivo
		// si ya ha sido salvado no pregunta
		OnFileSave();
	}
}

void CBaseDoc::OnCloseDocument( )  
{
	// Al entrar en esta función inevitablemente ha de cerrarse el documento.
	// En multidiagrama esto obliga a cerrar irremediablemente todos los documentos en caso de multidiagrama
    // Si es el padre global EsMultiDiag = false por lo que no se ejecuta ningún bloque de abajo.

	CMainFrame* pmainfrm = (CMainFrame*)AfxGetMainWnd();
	BOOL cerradoAuto = pmainfrm->m_cerradoAuto;
    
    if ( (p_bloqPadre != NULL) && cerradoAuto )
    {
		// El doc. es un diagrama hijo y se intenta cerrar al cerrar la aplicación.
		// Cuando directamente cerramos el programa a través de cerrar la MainFrame o por el menú Salir,
		// en el proceso de borrado se llama a OnCloseDocument para cada documento de la
		// lista (seguramente primero el último creado) inevitablemente se haya salvado o no (pide antes salvar antes de cerrar ninguno).
		// De esta manera se podría borrar un hijo sin borrar el padre si no redefiniéramos
		// esta función, o bien puede cerrarse dos veces un mismo documento si un doc. cerrado
		// sigue en la lista de docs del mainframe.
        // La solución por eso ha de ser inhibir en este caso la destrucción desde el padre pues el sistema
        // va a pasar por todos los objetos documento de la lista y es necesario que existan.
        // Es el único caso en el que inhibimos la destrucción en cadena pues de eso ya se
        // se encarga el sistema.
        // Se sabe que el sistema o cerrará todos o ninguno según si se da a CANCELAR en algún doc. en el salvado previo al cerrado de todos.
 		// Nota: se sabe que es el destructor de CDocument el que hace la operación de quitar
		// el documento de la lista de CMultiDocTemplate (la destrucción implica quitar de la
		// lista). OnCloseDocument hace un "delete this" aunque hay una condición para ello.

        if (p_bloqPadre != NULL) p_bloqPadre->p_docHijo = NULL;   // Para evitar que el bloque padre nos intente por ejemplo salvar o cierre otra vez.
	}

	if ((p_bloqPadre != NULL) && m_puedoCerrarCadena && (!cerradoAuto))   // Sólo si es diagrama hijo y se cierra a través del cerrado de la última ventana.
	{
		p_bloqPadre->p_docHijo = NULL; // Para que no nos destruya el padre dos veces, pues podemos ser el iniciador del cerrado.
		CDiagBase* pdiag = p_bloqPadre->getDiag();    
		CBaseDoc* pdoc = (CBaseDoc*)pdiag->getDoc();   // Puntero al documento del padre
		pdoc->SaveModified(); // No nos interesa el resultado.
		pdoc->OnCloseDocument(); // Cierra irremisiblemente el padre y sus hijos (puede no ser el global, a su vez éste llamará a su padre).
	}		

	COleServerDoc::OnCloseDocument();	// Si es un doc. padre (global o no) al cerrar los bloques-diagrama cerrará a los diagramas hijos de estos.
}

BOOL CBaseDoc::OnSaveDocument( const char* pszPathName )
{
	if (!COleServerDoc::OnSaveDocument( pszPathName )) return false;

	if (p_bloqPadre != NULL)  // Si es hijo, informa al padre de que se ha salvado y le pasa el nombre del fichero para que lo guarde.
	{
		// pszPathName puede ser NULL si es un objeto OLE el que se salve. Pero supongo que nunca ocurre con el hijo pues sería el padre el que se embebe
		if (pszPathName) p_bloqPadre->setFich( CString( pszPathName ) );
	}	
	getDiag()->setNombreDiagrama(pszPathName);  // Está preparado para pszPathName == NULL
    return true;
}
