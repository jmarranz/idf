
/////////////////////////////////////////////////////////////////////////////
// bloqdll.h

#ifndef CBLOQUEDLLEXE
#define CBLOQUEDLLEXE

#include "..\..\exe\BloqueUnidadExe.h"
#include "..\DLLDiagrama.h"

class CBaseView;
class CComunicacion;
class CBloqueDLL;



class CBloqueDLLExe : public CBloqueUnidadExe
{
	friend class CBloqueDLLVistasExe;

	DECLARE_SERIAL(CBloqueDLLExe)

// Construction
public:
	CBloqueDLLExe();
	virtual ~CBloqueDLLExe();  // No hace nada
	virtual void Destruir(); // Importante, libera el objeto pDatos en memoria.

	CBloqueDLL* getBloque()
	{
		return (CBloqueDLL*)p_bloque;
	}

	// Redefinidas de CBloque:

    virtual void CrearNuevo( const Instante& t );
    virtual void CrearDeFichero();
 
	virtual void Serialize(CArchive& ar);	
	virtual void SerializarDLL(CArchive& ar);

	virtual BOOL IniciarDatosBloque();   // Inicializa el objeto CBloqueFunc definido por el usuario en el DLL a través de sus funciones estándar.
	virtual void IniciarExplicito(const Instante& t);  // Llamada a través de menú para reiniciar los datos de un diagrama ya creado.


	virtual void EnError(int TipoError, CBloque* bloque);    
	
	virtual HINSTANCE getHinstDLL();
	

	// Sólo definidas en CBloqueDLLExe

private: // De uso interno 

	virtual CString Accion(CBaseView* view);
	
	virtual void CargayEnlazadoDLLBloque();
	virtual void CargaDLLBloque();
	virtual void EnlazadoDLLBloque();
	virtual void DescargaDLLBloque();  

	virtual CString ErrorEnlaceDLL();
	virtual void CrearObjBloqueEnDLL();
    virtual void CrearNuevoObjBloqueEnDLL();
	virtual void DestObjBloqueFunc();



protected:
	BOOL ( *psetNuevoBloqueEnDLL)(void * pBloqueEnDLL);
	void ( *pDefineBloque)(void * pBloqueEnDLL,CBloqueDLL* bloque);
	const char  * ( *pAccion)(void  *pBloqueEnDLL);
	BOOL ( *pSerializar)(void  *pBloqueEnDLL, LPSTREAM stream, UINT modo);  // Con CArchive  & ar nunca llegó a funcionar correctamente aunque se acercaba, además rompía bastante la independencia del compilador.
	void ( *pDestObjBloqueFunc)(void * pBloqueEnDLL, BOOL ObjUsuarioCreado);   
	void ( *pIniciarExplicito)(void  *pBloqueEnDLL);
	BOOL ( *pIniciarDatosBloque)(void  *pBloqueEnDLL);	
	void ( *pEnError)(void  *pBloqueEnDLL, int TipoError, const char * EtiqPost);
	BOOL ( *pPropUsuario)(void  *pBloqueEnDLL);

// Variables miembro

		
// Variables temporales de control de creación etc. no guardables a fichero.
public:
	void  * p_bloqueEnDLL;   // Puntero al objeto CBloqueFunc o CBloqueRetro del DLL	    

protected:  	// (Estas sólo las puede usar un objeto tipo CBloqueDLLExe o derivado)

	CDLLDiagrama m_DLLDiagrama;
	
	BOOL m_objDatosCreado;   // Se ha creado el objeto CBloqueFunc en el DLL
    BOOL m_objUsuarioCreado;  // Se han creado los objetos dinámicos del usuario en el DLL
	
};

#endif

