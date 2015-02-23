
#include "stdafx.h"
#include "Bloque_enlaces.h"

#include "IdfDllApp.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Enlazadas con CBloqueDLL

	
BOOL    _Bloque_setNuevo(CBloque * pBloque)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	if (!pBloque->CrearNuevo())
	{
	    delete pBloque;
		return false;
    }
	return true;
}


BOOL    _Bloque_IniciarDatosBloque( CBloque * pBloque )     // Inicializa el objeto CBloque a través de las funciones de usuario.
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	TRY  // Como hay manejo de memoria es posible que se produzca una aserción y no se salga bién.
	{
    	return pBloque->IniciarClaseUsuario();
	}
	CATCH_ALL(e)
	{
		return false;
	}		
    END_CATCH_ALL
}


void     _Bloque_DefineBloque(CBloque * pBloque, void * bloque)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	pBloque->DefineBloque(bloque);
}


const char*   _Bloque_Accion(CBloque * pBloque)
{
	static CString temp; // Es necesario que haya una cadena temporal pues la cadena que devuelve
	// Accion() es temporal de pila tal que la perdemos si sólo devolvemos un puntero y no hacemos una copia antes de perder la pila.

	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	temp = pBloque->Accion();
	return (const char *)temp;
}


BOOL     _Bloque_Serializar(CBloque * pBloque, LPSTREAM stream, UINT modo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	TRY
	{
		COleStreamFile f(stream);
		CArchive ar(&f, modo);			
		pBloque->Serialize(ar);
		ar.Flush();
		f.Flush();
	//	f.Detach();  No hacer pues la destrucción de los objetos se encarga de ello, además da error pues al destruirse ar espera que f esté bien.
		return true;
    }
	CATCH_ALL(e)
	{
        // No cerrar, pues lo hará la aplicación padre.
		return false; // Para indicar que se arroje una excepción en la aplicación padre.	
	}
	END_CATCH_ALL
}

void    _Bloque_DestObjBloqueFunc(CBloque * pBloque, BOOL ObjUsuarioCreado)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	if (ObjUsuarioCreado) pBloque->DestObjDatos();  // ObjUsuarioCreado es 0 si hubo un error en la creación del bloque, entonces no se ejecutó la creación de obj. del usuario.
	delete pBloque;
}


void     _Bloque_IniciarExplicito(CBloque * pBloque)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	pBloque->IniciarInterno( );
	pBloque->IniciarDatos();
}


void    _Bloque_EnError(CBloque * pBloque, int TipoError, const char * EtiqPost)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	pBloque->EnError(TipoError, CString(EtiqPost));	
}


BOOL    _Bloque_PropUsuario(CBloque  *pBloque)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	return pBloque->PropiedadesBloque();
}


