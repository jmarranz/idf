/////////////////////////////////////////////////////////////////////////////
// Bloque.h

#ifndef CBLOQUE_H
#define CBLOQUE_H

#include "ComponenteDiag.h"
#include "ListaConectores.h"
#include "Instante.h"

class CBaseView;
class CBloqueVistas;
class ListaBloques;
class CConect;
class CBloqueExe;
class CBloqueDis;
class CBloqueModo;
class CComponenteDiagVistas;
class DOMElement;
class DOMTreeWalker;



// Caso de no terminar el diagrama hijo en multidiag:

#define NO_FINAL_AUTO  "##NO_FINAL_AUTO##"

// Valores de EstadoInterno

enum TipoEstadoInterno { NUEVO = 0, MODIFICADO = 1 };

// Valores de  EstadoUsuario

#define N_ESTADOS_USUARIO  3

enum TipoEstadoUsuario { INCOMPLETO	= 1, ERRONEO = 2, CORRECTO = 3  };

#define S_INCOMPLETO "INCOMPLETO"
#define S_ERRONEO    "ERRONEO"
#define S_CORRECTO   "CORRECTO"

// Tipos de error notificados al bloque:

#define 	RECHAZODATOS  	1



class CBloque : public CComponenteDiag
{
	DECLARE_DYNAMIC(CBloque)

// Construction
public:
	CBloque();
	virtual ~CBloque();  // No hace nada
	virtual void Construir(CDiagBase* p);
	virtual void Destruir(); // Destruye datos internos y destruye el propio this (equivale a delete) 

	virtual BOOL esBloque() 
	{ 
		return true; 
	}

	virtual const char* getTipo() = 0;

	virtual CComponenteDiagVistas* CrearObjVistas() = 0;

	CBloqueVistas* getVistas()
	{
		return (CBloqueVistas*)p_vistas;
	}

	CBloqueExe* getExe()
	{
		return (CBloqueExe*)p_modo;
	}

	CBloqueDis* getDis()
	{
		return (CBloqueDis*)p_modo;
	}

	CBloqueModo* getModo()
	{
		return p_modo;
	}

	// Redefinidas en las clases derivadas CBloqueDLL y CBloqueDiag:

    virtual void CrearNuevo( const Instante& t );
    virtual void CrearDeFichero();

	virtual void LeerDatosLDD(DOMElement* bloque,DOMTreeWalker* walker);
	virtual void EscribirDatosLDD(DOMElement* bloque);
	virtual void Serialize(CArchive& ar);	

	virtual BOOL EsBloqueDiag() { return false; };  // Si el objeto fuera un CBloqDiag la derivada devolvería true, si es CBloqueDLL devuelve false.
	virtual BOOL EsBloqueUnidad() { return false; };
	
	virtual BOOL CambiaEstado(TipoEstadoUsuario estado);
	
	virtual Instante getTiempo();

	virtual void CambiaEstado(CString& estado); 
	virtual CString EstadoUsrAstring();
	virtual CString EstadoIntAstring();

	virtual TipoEstadoUsuario getEstadoUsr();
	virtual TipoEstadoInterno getEstadoInt();
	virtual void setEstadoUsr(TipoEstadoUsuario estado);
	virtual void setEstadoInt(TipoEstadoInterno estado);
	virtual BOOL EsNuevo();
	int listaEstadosUsuario(int index,CString& texto);


	virtual BOOL getAE() { return m_ae; };
	virtual BOOL getAS() { return m_as; };
	virtual void setAE(BOOL valor)  { m_ae = valor; };
	virtual void setAS(BOOL valor)  { m_as = valor; };

    virtual POSITION getPrimerConectEntradaPos(BOOL Retroanota);
    virtual CConect* getSigConectEntrada(POSITION& pos, BOOL Retroanota);
    virtual POSITION getPrimerConectSalidaPos(BOOL Retroanota);
    virtual CConect* getSigConectSalida(POSITION& pos, BOOL Retroanota);

	virtual BOOL PropiedadesCorrectas(CString& mensaje);  // Devuelve true si las propiedades obligatorias del bloque están bien definidas

	virtual const char * getFicheroLDD();
	
	virtual BOOL EsMultiDiag();

    virtual CString getOrden();  // Sólo en Multidiagrama


// Variables miembro

protected:
	CBloqueModo* p_modo;

    // Comunes a todas las derivadas:
public:

	// Se guardan a fichero:
	CString m_salidaAuto;  // Etiqueta del conductor de salida de bucle en el caso un proceso automático (para finalizar éste).

	BOOL m_ae;   // Activa Entrada  1=AE 0=PE . Defecto 0. Se lee desde LDD
	BOOL m_as;   // Activa Salida   1=AS 0=PS . Defecto 0. Se lee desde LDD

	UINT m_autoContMax;    // Max. número de ciclos (pasos por el mismo bloque) en modo Auto. Un valor negativo (ej -1) significa ilimitado

    
	// Listas de los conectores que llegan y salen del bloque.
	// Sirven para direccionar más rápido los conectores que por las listas principales del diagrama
	// Son sublistas de las listas principales de CDiagBase con referencias.
	// Los objetos sacados NO destruirlos, su destrucción se hace a través de las listas principales.
	// No se serializan estas listas, se llenan al conectar el diagrama.
	ListaConectores m_listaConectEntrada;  //Lista de los conectores entrantes
    ListaConectores m_listaConectSalida;  //Lista de los conectores salientes

    ListaConectores m_listaConectEntradaRetro;  //Lista de los conectores entrantes de retroanotación.
	ListaConectores m_listaConectSalidaRetro;  //Lista de los conectores salientes de retroanotación
};


#endif
                    