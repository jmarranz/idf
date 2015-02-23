
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


BOOL    _Bloque_IniciarDatosBloque( CBloque * pBloque )     // Inicializa el objeto CBloque a trav�s de las funciones de usuario.
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	TRY  // Como hay manejo de memoria es posible que se produzca una aserci�n y no se salga bi�n.
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
	// Accion() es temporal de pila tal que la perdemos si s�lo devolvemos un puntero y no hacemos una copia antes de perder la pila.

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
	//	f.Detach();  No hacer pues la destrucci�n de los objetos se encarga de ello, adem�s da error pues al destruirse ar espera que f est� bien.
		return true;
    }
	CATCH_ALL(e)
	{
        // No cerrar, pues lo har� la aplicaci�n padre.
		return false; // Para indicar que se arroje una excepci�n en la aplicaci�n padre.	
	}
	END_CATCH_ALL
}

void    _Bloque_DestObjBloqueFunc(CBloque * pBloque, BOOL ObjUsuarioCreado)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	if (ObjUsuarioCreado) pBloque->DestObjDatos();  // ObjUsuarioCreado es 0 si hubo un error en la creaci�n del bloque, entonces no se ejecut� la creaci�n de obj. del usuario.
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


