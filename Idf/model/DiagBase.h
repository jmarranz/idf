
// DiagBase.h

// Clase base de los diagramas compartida por las dos plantillas (diseño y funcional).

#ifndef DIAGBASE_H
#define DIAGBASE_H

#include "ListaBloques.h"
#include "ListaConectores.h"
#include "Instante.h"


class CBaseDoc;
class CConect;
class CBloque;
class CDiagramaVistas;
class DOMElement;
class CDiagDis;
class CDiagExe;
class CBloqueDiag;
class ListaComponentes;


// Tipo fichero diagrama:

#define LDD_WILDCARD    "Leng.Desc.Diag. (*.xml)"
#define DEX_WILDCARD    "Diagrama Funcional (*.dex)"
#define DDS_WILDCARD    "Diagrama Diseño (*.dds)"


#define LDD_EXT  "xml"
#define DEX_EXT  "dex"
#define DDS_EXT  "dds"


class CDiagBase : public CObject
{
	DECLARE_DYNAMIC(CDiagBase)
public:
	CDiagBase();
	virtual ~CDiagBase();
	
	virtual void Construir(CBaseDoc* p);  // Especie de constructor alternativo pero que puede ser virtual
	virtual void Destruir();

	CDiagExe* getExe()
	{
		return (CDiagExe*)this;
	}
	
	CDiagDis* getDis()
	{
		return (CDiagDis*)this;
	}

	virtual CDiagramaVistas* CrearObjDiagramaVistas() = 0;
	
	virtual void CrearNuevo();
	virtual void CrearDesdeFichero();

	CBaseDoc* getDoc();   // No virtual 

	CDiagramaVistas* getVistas();

	
	virtual void Serialize(CArchive& ar);


	// Relacionadas con la carga por el LDD
		// Lectura y creación a partir del LDD
	virtual void LeerDatosLDD(DOMDocument* pdoc, const Instante& t);
	virtual void EscribirDatosLDD(DOMDocument* pdoc);

	virtual void LeerDatosLDDBloques(DOMElement* bloques, const Instante& t, BOOL Retroanotacion);
	virtual void EscribirDatosLDDBloques(DOMElement* bloques,ListaBloques* plista);

	virtual void LeerDatosLDDBloque( DOMElement* bloque,const Instante& t,BOOL Retroanotacion);
	virtual void EscribirDatosLDDBloque(DOMElement* bloque, CBloque* pblq);

	virtual void LeerDatosLDDConectores(DOMElement* conectores, BOOL Retroanotacion);
	virtual void EscribirDatosLDDConectores(DOMElement* conectores, ListaConectores* plista);

	virtual void LeerDatosLDDConect(DOMElement* conector,BOOL Retroanotacion);
	virtual void EscribirDatosLDDConector(DOMElement* conector, CConect* pcon);


	virtual CBloque* crearBloque(const char* tipo);
	virtual CBloque* crearBloqueDLL();
	virtual CBloque* crearBloqueDiag();

	virtual void addBloque(CBloque* pblq);

	virtual CConect* crearConector();

	virtual void addConector(CConect* pcon);


	// Escritura en el LDD
	virtual void GenerarLDD(CString& FichGenerado, BOOL EjecNotepad);

	virtual void FlagModificado();

	virtual void BorrarColecFunc();
	virtual void BorrarColecRetro();

	virtual BOOL EsDiagDiseno() = 0;

	virtual BOOL PropiedadesCorrectas(CString& mensaje);  // Devuelve true si las propiedades obligatorias del diagrama están bien definidas
	virtual BOOL PropiedadesCorrectasDiagramaCompleto(CString& mensaje); // Devuelve true si las propiedades obligatorias del diagrama y componentes están bien definidas
	virtual BOOL PropiedadesCorrectasDiagramaCompleto(ListaComponentes* plista,CString& mensaje);

	virtual void AvisoCambioCarga() {  };  // Se define para las derivadas

	virtual void ChequearNombreValido(const CString& FileName); 

	virtual BOOL ExisteClave(const CString& clave);
	virtual BOOL ExisteClave(ListaComponentes* plista,const CString& clave);

	virtual CString getClaveNueva(const CString& raiz);  // Devuelve un nombre de clave no usado por ningún elemento
	virtual BOOL EsNuevaClaveValida(const CString& clave);

	virtual CString& getAyuda();
	virtual void setAyuda( const CString& ayuda );   

	virtual Instante getTiempo();
	virtual CString CadenaTiempo(); 

	virtual void setNombreDiagrama( const char* pszPathName );

	// Para multidiagrama (diagrama hijo)
	virtual BOOL EsMultiDiag();

	virtual BOOL SetDirTrabajo(const char* nomfich, BOOL Reintentar);
	virtual CString FormarPathAbsoluto(const CString& NombreFich);

	virtual CBloqueDiag* getBloqPadre();
	virtual CBloque* getMDiagBloqIni();
	virtual CBloque* getMDiagBloqFin();

	virtual void MemorizarLDDOriginal(CString& FileName);  // Memoriza el LDD original (si existió) con el que fue creado el diagrama funcional.
	virtual BOOL GenerarLDDOriginal();

	virtual void setDLLDiag(const CString& dllDiag);
	virtual CString getDLLDiag();


public:
	// Variables temporales
	CString m_nombreDiag;   // Nombre del fichero del diagrama sin camino: nombre + ext (para títulos etc.). No se guarda a fichero,pues cambia al cargar, guardar etc.

    // Variables que se guardan a fichero por la clase:

	CString m_etiqueta;	

    CString m_dirTrabajo;  // Directorio de trabajo donde se buscan por defecto las librerías DLL. Sirve para que los ficheros se puedan especificar con caminos relativos a este.
	CString m_nombreLDD;   

	CString m_ayuda;

	CString m_memoriaFicheroLDD;  // Memorización del fichero LDD original.

	// Variables que se guardan a fichero pero que es responsable de ello las clases derivadas.

	ListaBloques m_listaBloq;    //Lista de los bloques del diagrama
    ListaConectores m_listaConect;  //Lista de los conectores del diagrama

	ListaBloques m_listaBloqRetro;   // Lista de bloques de retroanotación.
    ListaConectores m_listaConectRetro;  //Lista de los conectores del diagrama de retroanotación.

protected:
	CString m_dllDiag;

	CBaseDoc* p_doc;
	CDiagramaVistas* p_vistas;

};


#endif
