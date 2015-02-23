

//////   bloqbase.h


#ifndef CBLOQBASE_H
#define CBLOQBASE_H


// Valores de EstadoInterno

#define 	NUEVO 		0
#define		MODIFICADO  1

// Valores de  EstadoUsuario
/*
#define     INCOMPLETO	1
#define     ERRONEO 	2	
#define		CORRECTO 	3
*/

#define 	RECHAZODATOS	1

// Valores salida por consola
#define     SISTEMA 	1
#define 	USUARIO		2


///////////////////////////////////////////////////////////////////////////
//  CBloque      Clase base para bloque funcional y para retroanotación. No se utiliza directamente

enum TipoEstado {INCOMPLETO =1 , ERRONEO = 2, CORRECTO = 3};  

class CCom;


class CBloque : public CObject
{
    DECLARE_SERIAL(CBloque)
	
public:

// Quitar la variable y toda referencia a la condición de contener objeto de
// datos

    CBloque();
	virtual ~CBloque();   // Fundamental que sea virtual para que pueda ejecutarse el que defina el usuario.

	void IniciarInterno();	
	BOOL CrearNuevo();
	BOOL CrearDeFichero();
	BOOL IniciarClaseUsuario();

	void DefineBloque(void * pB);	

	virtual void Serialize(CArchive& ar);

	// Funciones a redefinir totalmente por el usuario.

	virtual void IniciarDatos();	  // Inicia los datos de todas las variables y objetos. 
	virtual BOOL NuevosObjDatos();	  // Crear objetos dinámicos de datos
	virtual void DestObjDatos();	  // Destruye los objetos dinámicos creados en NuevosObjDatos o en otros lugares.

	virtual void GuardarFichero(CArchive& ar);
	virtual void LeerFichero(CArchive& ar);

	virtual CString Accion();  		 // Ejecución directa normal. Puede ser virtual pura. Redefinida por el usuario en la clase derivada

	virtual BOOL PropiedadesBloque();
	virtual void EnError(int TipoError, const char* EtiqPost);

	// Funciones de consulta, utilidad o registro utilizables por el usuario en Accion y otras:

	// Funciones de consulta: devuelven una información sin hacer ninguna acción lateral.

	CString Ayuda();   // Devuelve una cadena con información sobre el bloque 
	CString getMacro();   // Devuelve una cadena con información sobre un posible lenguaje de macros de programación del bloque.  

	BOOL EsModoAuto();  		// Devuelve un valor booleano de si está ejecutándose en modo Auto el bloque (por ejemplo para no mostrar diálogos). Pensada para ser llamada por Accion en los bloques del usuario 
	BOOL EsInicioModoAuto(); 	// Devuelve un valor booleano de si es iniciador este bloque del proceso automático. Pensada para ser llamada por Accion en los bloques del usuario
 	CWnd* getMainWnd();          // Devuelve un puntero a la ventana principal de Idf.dll para poder asociar diálogos hijo modales a ella.    
	CString getEtiqueta();   // Devuelve la etiqueta que visualiza el bloque.
	CString getNombreInterno(); // Devuelve el nombre interno del bloque
	TipoEstado getEstado();    // Devuelve el estado actual del bloque.
	BOOL EsNuevo();  // Devuelve el estado interno (true si es nuevo) del bloque.

    // Funciones de registro: modifican algo en los parámetros internos del bloque.
	
	void RedefAyuda(const char* NuevaAyuda);   // Guardar cambios en la ayuda desde el diálogo de propiedades.
	void RedefMacro(const char* NuevaMacro);   // Guardar cambios en la macro desde el diálogo de propiedades.
	void CambiaEstado(enum TipoEstado estado);  // Cambia a los diferentes estados posibles del bloque. Deja de ser nuevo.

	// Funciones de utilidad.
	
	BOOL WinSpawn(LPCSTR lpszCmdLine, UINT fuCmdShow = SW_SHOW); // Lanza una aplicación y espera a que termine.

	void Consola(CString& mensaje, int origen = USUARIO);   // Mensajes en la consola por el usuario.
	void Consola(const char* mensaje, int origen = USUARIO); // Idem pero const char*
	void Mensaje(CString& mensaje);
	void Mensaje(const char* mensaje);
	BOOL Confirmar(const char* mensaje);
	BOOL Confirmar(CString& mensaje);  

	BOOL RetroanotarEnCascada(const char* EtiqConector = NULL);
	BOOL EnviarDatosRetroanotacion(const char* EtiqConector = NULL);
	BOOL RecibirDatosRetroanotacion(const char* EtiqConector = NULL);

	// Uso interno
private:

// Variables que se guardan a fichero y accesibles por el usuario


	// Variables internas.
private:
	void * pBloque;  // Acceso al objeto CBloque bloque padre en PROY.DLL.

};


#endif



