
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

const DWORD CBaseDoc::m_aVerP = 1;  // Versi�n de la plantilla. 
const DWORD CBaseDoc::m_aRevP = 1;  // Revisi�n del idem.

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

	if (IsEmbedded()) // S�lo es �til en modo ejecuci�n
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
	// PuedoCerrarCadena a true, al destruirse el documento destruir� el documento padre consigo
	// y luego el proceso normal tender�a a destruir al padre, luego se destruir�a dos veces
	// cuando la destrucci�n en cadena s�lo ha de producirse cuando se cierra el documento
	// a trav�s de las ventanas

	if (p_bloqPadre != NULL) m_puedoCerrarCadena = true;  

	return true;
}


BOOL CBaseDoc::OnOpenDocument( const char* pszPathName )
{
	// La inicializaci�n si es multidiagrama de par�metros de enlace se hace en Serialize

	if (!COleServerDoc::OnOpenDocument( pszPathName ))  // Llama a DeleteContents y a Serialize que carga el diagrama. No hace falta new pues se crear� din�micamente.
	{
		CString stemp;
		stemp = "ERROR en la creaci�n del diagrama desde el fichero:\r\n" + CString(pszPathName); 
		CGlobal::Mensaje((CString)stemp); 
		return false;
	}    

	getDiag()->setNombreDiagrama(pszPathName);	// Admite pszPathName == NULL

	if (p_bloqPadre != NULL)  m_puedoCerrarCadena = true; // Importante hacerlo al final. Ver OnNewDocument para m�s informaci�n

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
		if (CGlobal::p_bloqPadre != NULL)  // Inicializaci�n si es Multidiagrama (similar a lo que hay en OnNewDocument)
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

		ar >> m_dVerP >> m_dRevP;   // En el futuro se podr� hacer una carga de datos que abarque versiones antiguas a trav�s del chequeo de estos n�meros comunes a todas las versiones.
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
	CGlobal::Mensaje("ERROR: Fichero de formato desconocido o versi�n no manejada");
}

void CBaseDoc::DeleteContents()
{
	COleServerDoc::DeleteContents();	// delete doc-items
	
	// TODO: add additional cleanup before doc-items are deleted
	DestruirDiag();
}

void CBaseDoc::DestruirDiag()
{
	if (p_diag != NULL)  // Por m�s seguridad.
	{
		p_diag->Destruir();  // Destruye bloques, consola etc. Tambi�n el this
 		delete p_diag;
	}
	p_diag = NULL;
}

void CBaseDoc::SalvarModificado(BOOL confirm)
{
	if (confirm)
	{
		// Pide confirmaci�n del fichero (es un SaveAs)
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
	// Al entrar en esta funci�n inevitablemente ha de cerrarse el documento.
	// En multidiagrama esto obliga a cerrar irremediablemente todos los documentos en caso de multidiagrama
    // Si es el padre global EsMultiDiag = false por lo que no se ejecuta ning�n bloque de abajo.

	CMainFrame* pmainfrm = (CMainFrame*)AfxGetMainWnd();
	BOOL cerradoAuto = pmainfrm->m_cerradoAuto;
    
    if ( (p_bloqPadre != NULL) && cerradoAuto )
    {
		// El doc. es un diagrama hijo y se intenta cerrar al cerrar la aplicaci�n.
		// Cuando directamente cerramos el programa a trav�s de cerrar la MainFrame o por el men� Salir,
		// en el proceso de borrado se llama a OnCloseDocument para cada documento de la
		// lista (seguramente primero el �ltimo creado) inevitablemente se haya salvado o no (pide antes salvar antes de cerrar ninguno).
		// De esta manera se podr�a borrar un hijo sin borrar el padre si no redefini�ramos
		// esta funci�n, o bien puede cerrarse dos veces un mismo documento si un doc. cerrado
		// sigue en la lista de docs del mainframe.
        // La soluci�n por eso ha de ser inhibir en este caso la destrucci�n desde el padre pues el sistema
        // va a pasar por todos los objetos documento de la lista y es necesario que existan.
        // Es el �nico caso en el que inhibimos la destrucci�n en cadena pues de eso ya se
        // se encarga el sistema.
        // Se sabe que el sistema o cerrar� todos o ninguno seg�n si se da a CANCELAR en alg�n doc. en el salvado previo al cerrado de todos.
 		// Nota: se sabe que es el destructor de CDocument el que hace la operaci�n de quitar
		// el documento de la lista de CMultiDocTemplate (la destrucci�n implica quitar de la
		// lista). OnCloseDocument hace un "delete this" aunque hay una condici�n para ello.

        if (p_bloqPadre != NULL) p_bloqPadre->p_docHijo = NULL;   // Para evitar que el bloque padre nos intente por ejemplo salvar o cierre otra vez.
	}

	if ((p_bloqPadre != NULL) && m_puedoCerrarCadena && (!cerradoAuto))   // S�lo si es diagrama hijo y se cierra a trav�s del cerrado de la �ltima ventana.
	{
		p_bloqPadre->p_docHijo = NULL; // Para que no nos destruya el padre dos veces, pues podemos ser el iniciador del cerrado.
		CDiagBase* pdiag = p_bloqPadre->getDiag();    
		CBaseDoc* pdoc = (CBaseDoc*)pdiag->getDoc();   // Puntero al documento del padre
		pdoc->SaveModified(); // No nos interesa el resultado.
		pdoc->OnCloseDocument(); // Cierra irremisiblemente el padre y sus hijos (puede no ser el global, a su vez �ste llamar� a su padre).
	}		

	COleServerDoc::OnCloseDocument();	// Si es un doc. padre (global o no) al cerrar los bloques-diagrama cerrar� a los diagramas hijos de estos.
}

BOOL CBaseDoc::OnSaveDocument( const char* pszPathName )
{
	if (!COleServerDoc::OnSaveDocument( pszPathName )) return false;

	if (p_bloqPadre != NULL)  // Si es hijo, informa al padre de que se ha salvado y le pasa el nombre del fichero para que lo guarde.
	{
		// pszPathName puede ser NULL si es un objeto OLE el que se salve. Pero supongo que nunca ocurre con el hijo pues ser�a el padre el que se embebe
		if (pszPathName) p_bloqPadre->setFich( CString( pszPathName ) );
	}	
	getDiag()->setNombreDiagrama(pszPathName);  // Est� preparado para pszPathName == NULL
    return true;
}
