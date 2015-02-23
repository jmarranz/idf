
// CCom.h

// Declaración de la clase CCom: base de los objetos de comunicaciones y la base de CBloque.

#ifndef CCOM_H
#define CCOM_H

#include "macros.h"


class CCom : public CObject
{
	DECLARE_SERIAL(CCom)
public:
	CCom();
	~CCom();

	// Internas
	BOOL CrearDeFichero();

	void DefineConector(void * pCon) { p_Conector = pCon; };

	virtual void Serialize(CArchive& ar); // Util sólo en comunicación entre dos DLLs

	virtual void PrepararParaRecibirDatos() { };
	virtual void PostRecibirDatos() { };
	virtual void PrepararParaDevolverDatos() { };
	virtual void PostDevolverDatos() { };


	// Llamables por el usuario
	void Mensaje(const char* mensaje);

	CString getEtiquetaConector();
	CString getNombreInternoConector();	
	BOOL EsRetroAnotador();	

	// Redefinible por el usuario.
	virtual void GuardarDatos(CArchive& ar); // Util sólo en comunicación entre dos DLLs
	virtual void LeerDatos(CArchive& ar); // Util sólo en comunicación entre dos DLLs
	
private:
	void* p_Conector; // Conector el programa principal
};



#endif


