//// bloqbase.cpp


#include "stdafx.h"
#include "IdfDllApp.h"

#include "bloque.h"

#include "com.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////////
//  CBloque


IMPLEMENT_SERIAL(CBloque,CObject,1)

CBloque::CBloque()   // Para creaci�n din�mica y serializaci�n
{
	pBloque=NULL;
}

CBloque::~CBloque()
{
	// Aqu� no se puede llamar a DestDatos de la derivada pues se destruye antes de ejecutarse
	// el destructor de la base. 
	// Es llamada expl�citamente DestObjDatosyAccion la funci�n que inmediatamente hace
	// despu�s un delete al objeto.
}


void CBloque::IniciarInterno()
{

}


// CrearNuevo() es definida debido a que es necesario crear din�micamente el bloque con
// CRuntimeClass por lo que es necesario llamarla expl�citamente en el caso de lectura.

BOOL CBloque::CrearNuevo()
{
	IniciarInterno();

	return true;
}


BOOL CBloque::CrearDeFichero()
{
	return true;
}


BOOL CBloque::IniciarClaseUsuario()
{
 	if (!NuevosObjDatos())
 	{
 	 	return false;  // Funci�n reescrita por el programador
	}

	IniciarDatos();
	return true;
}


void CBloque::DefineBloque(void * pB)
{
	pBloque = pB;
}


void CBloque::Serialize(CArchive& ar) 
{
	CObject::Serialize(ar);  // Llamada al padre para guardar el dato temporal y en general toda la cadena de CObject

	// Serializar aqu� los datos internos de CBloque
	if (ar.IsStoring())
	{
		GuardarFichero(ar);
	}
	else
	{
		LeerFichero(ar);

		CrearDeFichero();   // Inicializa variables no grabables.
	}	
}



// Funciones de utilidad dise�adas para llamarse en Accion y otros por parte del programador de nuevos bloques.

void CBloque::Mensaje(CString& mensaje)
{
	CIdfDllApp* pApp = ObtpApp(); 
	pApp->pBloqueExpMensaje(pBloque, (const char  *)mensaje);	
}

void CBloque::Mensaje(const char* mensaje)
{
	CString stemp = CString(mensaje);
	Mensaje(stemp);
}


BOOL CBloque::Confirmar(CString& mensaje)
{
	CIdfDllApp* pApp = ObtpApp(); 	
	return pApp->pBloqueExpConfirm(pBloque, (const char  *)mensaje);	
}

BOOL CBloque::Confirmar(const char* mensaje)
{
	return Confirmar(CString(mensaje));
}

void CBloque::Consola(CString& mensaje, int origen)
{
	(*ObtpApp()->pBloqueConsola)(pBloque, (const char  *)mensaje, origen);
}

void CBloque::Consola(const char* mensaje, int origen)
{
	Consola((CString&)mensaje, origen);
}

CString CBloque::getEtiqueta()
{
	return (CString)(*ObtpApp()->pBloquegetEtiqueta)(pBloque);
}

CString CBloque::getNombreInterno()
{
	return (CString)(*ObtpApp()->pBloquegetNombreInterno)(pBloque);
}


CWnd* CBloque::getMainWnd()
{
	// Es conveniente hacerlo as� en vez de Attach() si la DLL est� linkada usando las DLLs de las MFCs
	CWnd* win = CWnd::FromHandle(ObtpApp()->HwndProyWinMain);
    return win;
}


BOOL CBloque::EsModoAuto()
{
	BOOL res = (*ObtpApp()->pBloqueEsModoAuto)(pBloque);
	return res;
}



BOOL CBloque::EsInicioModoAuto()
{
	BOOL res = (*ObtpApp()->pBloqueInicioModoAuto)(pBloque);
	return res;
}

void CBloque::CambiaEstado(enum TipoEstado estado)   // El hecho de usar una enumeraci�n asegura que los valores pasados son los previstos (no compilar�a).
{
	(*ObtpApp()->pBloqueCambiaEstado)(pBloque, (int)estado);
}


TipoEstado CBloque::getEstado()
{
	return (TipoEstado)(*ObtpApp()->pBloquegetEstado)(pBloque);	
}


BOOL CBloque::EsNuevo()
{
	return (*ObtpApp()->pBloqueEsNuevo)(pBloque);

}
 

BOOL CBloque::WinSpawn(LPCSTR lpszCmdLine, UINT fuCmdShow)

// lpszCmdLine : camino al ejecutable .	
// fuCmdShow :	 window state of new app. Ej. SW_SHOW	
{
	return (*ObtpApp()->pBloqueWinSpawn)(pBloque, lpszCmdLine, fuCmdShow);
}



BOOL CBloque::RetroanotarEnCascada(const char* EtiqConector)
{
	if (EtiqConector == NULL) EtiqConector = "";
	return (*ObtpApp()->pBloqueRetroanotar)(pBloque,(const char  *)EtiqConector, true);
}


BOOL CBloque::EnviarDatosRetroanotacion(const char* EtiqConector)
{
	if (EtiqConector == NULL) EtiqConector = "";
	return (*ObtpApp()->pBloqueRetroanotar)(pBloque,(const char  *)EtiqConector, false);
}


BOOL CBloque::RecibirDatosRetroanotacion(const char* EtiqConector)
{
	if (EtiqConector == NULL) EtiqConector = "";
	return (*ObtpApp()->pBloqueRecibirRetroanotacion)(pBloque,(const char  *)EtiqConector);
}



// Funciones a implementar por el usuario en una clase derivada.


void CBloque::IniciarDatos()
{
	// Inicializaci�n de las variables por defecto del bloque y datos de los objetos creados (ya existentes).
	// Tambi�n sirve para tomar valores iniciales las variables de entorno que no se guardan a fichero.
	// No crear o destruir objetos en esta funci�n por el usario en su clase derivada.
}


BOOL CBloque::NuevosObjDatos()
{

/* 
  Ha de reescribirse por el programador a fin de crear aqu� los objetos din�micos o reservas de memoria
a�adidos por el dise�ador del objeto de datos y acciones.

  Si se devuelve false no se crear� el diagrama al fallarse en la creaci�n o carga de uno de
sus bloques.

  Es llamada por la funci�n CrearNuevo() que no debe manejar por el usuario.
*/
	return true; // Si el usuario no la redefine no hace nada por defecto.

}


void CBloque::DestObjDatos()
{
/*
  Redefinible por el usuario.
  set aqu� la destrucci�n de los objetos din�micos y liberar la memoria que se hubieran creado en NuevosObjDatos u otros lugares
y momentos (como m�nimo los creados en NuevosObjDatos).
*/
}


void CBloque::GuardarFichero(CArchive& ar)
{
	// El programador debe reescribir esta funci�n y a�adir con ar << y
 	// las conversiones adecuadas (a WORD, BYTE etc) para cada variable
	// de datos del bloque a�adida por el programador para guardar en 	
	// fichero.
	// Ha de hacerse en el mismo orden de lectura de LeerFichero
	
	CString Etiq = getEtiqueta();
	CString s = "Aviso: el bloque \"" + Etiq + "\" no escribe datos a fichero";
	Consola(s, SISTEMA);
}

void CBloque::LeerFichero(CArchive& ar)
{
	// El programador debe reescribir esta funci�n y a�adir con ar >> y
 	// las conversiones adecuadas (a WORD, BYTE etc) para cada variable
	// de datos del bloque a�adida por el programador para leer de
 	// fichero.
	// Ha de hacerse en el mismo orden de lectura de GuardarFichero.
	
	CString Etiq = getEtiqueta();
	CString s = "Aviso: el bloque \""+ Etiq +"\" no lee datos de fichero";
	Consola(s, SISTEMA);	
}


void CBloque::EnError(int TipoError, const char* EtiqPost)
{
	switch(TipoError)
	{
		case RECHAZODATOS :
		{
			CString men = getEtiqueta();
			men = "Aviso: El bloque siguiente: \""+ CString(EtiqPost) + "\" a: \""+ men + "\" ha rechazado los datos enviados.";
			Mensaje(men);
			CambiaEstado(ERRONEO);
		}
	}
}


CString CBloque::Accion()
{
	// Funci�n nula para poder crear objetos de la clase CBloqueFunc  para pruebas.
	// Ha de reescribirse por el programador en bloques derivados
	// accediendo con pDatos a los datos del bloque.
	// Devuelve una cadena que representa la etiqueta del conductor
	// por donde tiene que continuar el flujo en el caso de bloque de
	// decisi�n. Si no es bloque de decisi�n devolver un (CString)"".
	
	CString Etiq = getEtiqueta();
	CString s = "Aviso: el bloque \""+ Etiq +"\" no realiza ninguna acci�n";
	Consola(s, SISTEMA);
	
	return "";
}


CString CBloque::Ayuda()
{
	const char  *nombre;
	(*ObtpApp()->pBloqueAyuda)(pBloque, nombre);	
	return CString(nombre);
}

void CBloque::RedefAyuda(const char* NuevaAyuda)
{
	(*ObtpApp()->pBloqueRedefAyuda)(pBloque, CString(NuevaAyuda));		
}

CString CBloque::getMacro()
{
	const char  *macro;
	(*ObtpApp()->pBloquegetMacro)(pBloque, macro);	
	return CString(macro);
}

void CBloque::RedefMacro(const char* NuevaMacro)
{
	(*ObtpApp()->pBloqueRedefMacro)(pBloque, CString(NuevaMacro));		
}

BOOL CBloque::PropiedadesBloque()
{
	Mensaje((CString)"Este bloque no tiene di�logo de propiedades del usuario");
	return false;
}



