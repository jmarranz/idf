
// BaseDoc.h

// Clase documento base de las clases documento de las dos plantillas (funcional y de diseño).
// Aunque la plantilla de diseño no usa OLE nos vemos obligados de partir de COleServerDoc para la
// plantilla funcional.

#ifndef CBASEDOC_H
#define CBASEDOC_H

typedef struct {
    DWORD   key;
    HANDLE  hmf;
    RECT    bbox;
    WORD    inch;
    DWORD   reserved;
    WORD    checksum;
} METAFILEHEADER;


class CBaseView;
class CDiagBase;
class CBloqueDiag;


class CBaseDoc : public COleServerDoc
{
protected: // create from serialization only
	DECLARE_DYNAMIC(CBaseDoc)

public:
	CBaseDoc();
	virtual ~CBaseDoc();

	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument( const char* pszPathName );	
	
	virtual CDiagBase* CrearObjDiag() = 0;

	CDiagBase* getDiag()	// No hacerla virtual para poder devolver el tipo adecuado en las derivadas.
	{
    	return p_diag;
	};

	void setConectTmp(CConect* pcon)
	{
		p_conectTmp = pcon;
	}

	CConect* getConectTmp()
	{
		return p_conectTmp;
	}


	virtual COleServerItem* OnGetEmbeddedItem(); // Llamada por el sistema, necesaria para crear la clase. No hace nada en este nivel. Sólo en clases derivadas (es virtual)
	virtual void Serialize(CArchive& ar);	// overridden for document i/o
	virtual	void DeleteContents();	
	virtual void DestruirDiag();
	
	virtual void ErrorFichDesc();

	virtual void SalvarModificado(BOOL confirm);

	virtual void OnCloseDocument();
	virtual BOOL OnSaveDocument( const char* pszPathName );

	// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// Variables que NO se guardan a fichero

    // Variables que se guardan a fichero:
private:
	CString m_programa;  // Nombre del programa que se graba a fichero con el diagrama.

public:
	// Variables temporales:
	CDiagBase* p_diag;  // Diagrama asociado al documento
	CBloqueDiag* p_bloqPadre;  // Apunta al bloque padre en caso de multiagrama. 
	CConect* p_conectTmp; // Temporal

	BOOL m_puedoCerrarCadena; // Controla en multidiagrama (hijo) cuando es seguro cerrar en cadena (cerrar al padre)

	DWORD m_dVerP;  // Versión de la plantilla con la que se hizo el fichero (documento) cargado o creado.
	DWORD m_dRevP;  // Revisión del idem.

	static const DWORD m_aVerP;  // Versión actual de la plantilla .
	static const DWORD m_aRevP;  // Revisión del idem.

};

#endif
