#if !defined(AFX_OLETEMPLATESERVERPROY_H__FFAF6013_214B_11D2_87E7_0000C057CDE3__INCLUDED_)
#define AFX_OLETEMPLATESERVERPROY_H__FFAF6013_214B_11D2_87E7_0000C057CDE3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OleTemplateServerIdf.h : header file
//


// Por razones desconocidas, en OLE OnNewDocument() es llamada
// dos veces cuando se crea un nuevo objeto embebido
// y una cuando se carga a partir de un objeto OLE ya serializado
// El caso es que aunque después se destruye el documento sin
// problemas, hay una creación inútil (para nosotros, quizás el sistema necesite crear el documento aunque sea de forma temporal)
// lo que conlleva pedir al usuario introducir un LDD a través del diálogo
// Detectamos esta situación y devolvemos true pues necesario que la creación del documento sea correcta.
// pero evitando que salga el diálogo de pedir el LDD y la carga de DLLs etc.
// El proceso de borrado por DeleteContents es seguro aunque no se haya creado el diagrama esté vacío.
// Se crea la vista que usa pDiag por lo que hay que crear el objeto diagrama

// Detectamos que estamos en este caso gracias a que se llama en esta creación inútil para el usuario
// a OnCreateObject::OnCreateObject(), poniendo un flag sabemos cuando el sistema está creando
// un objeto documento que probablemente sirve de contenedor para todos los objetos OLE (COleServerItem)
// que se insertan en otras aplicaciones. Probablemente DeleteContents() borra el contenido
// del documento pero no los COleServerItem



/////////////////////////////////////////////////////////////////////////////
// COleTemplateServerIdf command target

class COleTemplateServerIdf : public COleTemplateServer
{
public:
	COleTemplateServerIdf();           // protected constructor used by dynamic creation
	virtual ~COleTemplateServerIdf();

// Attributes
public:

	BOOL CreandoObjetoBase() { return Creando; };

	BOOL Creando;

// Operations
public:
	virtual CCmdTarget* OnCreateObject();  // Crea un documento CMainDoc

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleTemplateServerIdf)
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COleTemplateServerIdf)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLETEMPLATESERVERPROY_H__FFAF6013_214B_11D2_87E7_0000C057CDE3__INCLUDED_)
