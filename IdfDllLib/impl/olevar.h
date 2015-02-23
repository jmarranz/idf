

// olevar.h

#ifndef OLEVAR_H
#define OLEVAR_H

// Definici�n de nuevos tipos de datos para resolver ambiguedades:

// COLE_VARIANT_BOOL Sustituye a VARIANT_BOOL para distinguirlo de "short", por otra parte permite pasar valores BOOL que son en este compilador "const int"

class  COLE_VARIANT_BOOL    
{
public:
 	COLE_VARIANT_BOOL(VARIANT_BOOL arg)
 	{
 		v_bool = arg;
 	};
 	COLE_VARIANT_BOOL(BOOL arg)
 	{
 		v_bool = arg;
 	};

	// En el caso de una asignaci�n (=) se usa el constructor el cual nos vale.
	 
	operator VARIANT_BOOL()  // Para un cast
	{
		return v_bool;
	};   

// Variable miembro.

 	VARIANT_BOOL v_bool;
};



class COLE_SCODE   // Sustituye a SCODE para distinguirlo de "long"
{
public:
 	COLE_SCODE(SCODE arg)
 	{
 		scode = arg;
 	};
	// En el caso de una asignaci�n (=) se usa el constructor el cual nos vale.
	operator SCODE()  // Para un cast
	{
		return scode;
	};   

// Variable miembro.

 	SCODE scode;
};


class COLE_DATE    // Sustituye a DATE para distinguirlo de "double"
{
public:
 	COLE_DATE(DATE arg)
 	{
 		date = arg;
 	};
	// En el caso de una asignaci�n (=) se usa el constructor el cual nos vale.
	operator DATE()   // Para un cast
	{
		return date;
	};   

// Variable miembro.

 	DATE date;
};


// Clase COleVariantExtExt

// Usamos este nombre en vez de COleVariantExt porque esta clase est� implementada desde la versi�n 4 del compilador
// con funcionalidad similar pero no tan completa (creo). La parte "Ext" interpretarla como "Extendida".

// Ampliaci�n de las propiedades y procesos de VARIANT y VARIANTARGS

// Incluye los nuevos tipos de datos definidos antes sustituyendo a los originales de los que se derivan.
// Utilizar los tipos nuevos para evitar ambiguedades.

// Se heredan las mismas variables miembros y se definen los siguientes procedimientos:

// El tipo "int" no est� porque es dependiente del sistema operativo, es necesario hacer un cast expl�cito
// por ej. a "long".
// Si algunos tipos de VARIANT no tienen constructor es porque equivalen a otros ej. VARIANT_BOOL <=> short
// Por norma los tipos b�sicos ANSI C prevalecen en el caso de confusi�n de tipos, se recomienda indicar como
// segundo par�metro el tipo para que la inicializaci�n sea 100% correcta.
// En el caso de ambiguedad son tipos de datos que ocupan la misma imagen de memoria en VARIANT al ser del mismo
// tama�o, por tanto aunque se acceda al dato por diferentes variables miembro el resultado es el mismo pues
// es preciso recordar que VARIANT es una "union". Sin embargo el tipo es fundamental pues la aplicaci�n OLE
// destino acude al miembro vt para saber que miembro leer, si encuentra que el tipo especificado es diferente al
// que espera puede rechazar la comunicaci�n (m�todo o variable) aunque la imagen en memoria del dato sea el esperado. 


// El tipo BSTR es realmente "char  *", es necesario hacer un cast expl�cito ante una cadena de caracteres
// de argumento.



class COleVariantExt : public COleVariant  /* tagVARIANT */
{
public:

/*	
	COleVariantExt();
	virtual ~COleVariantExt();

	// Funciones de utilidad
	 
	virtual void Inicializar();  // Inicializa con VariantInit 
	virtual HRESULT LiberarDatos();   // Hace un VariantClear
	
	// Constructores espec�ficos.

	COleVariantExt(COleVariantExt& arg);  // Para copiar de una forma segura. 
    COleVariantExt(VARIANT& arg);   // Idem anterior.
    
	COleVariantExt( short arg );  // Admite tambi�n VARIANT_BOOL pero "vt" se definir�a mal, usar un cast a COLE_VARIANT_BOOL
	COleVariantExt( COLE_VARIANT_BOOL arg );  // Equivale a VARIANT_BOOL
	COleVariantExt( BOOL arg );  // Equivale a VARIANT_BOOL pero permite directamente el paso de BOOL
	COleVariantExt( long arg );  // Admite tambi�n SCODE pero "vt" se definir�a mal, usar un cast a COLE_SCODE
	COleVariantExt( COLE_SCODE arg );  // Equivale a SCODE
	COleVariantExt( float arg );
	COleVariantExt( double arg );  // Admite tambi�n DATE pero "vt" se definir�a mal, usar un cast a COLE_DATE
	COleVariantExt( COLE_DATE arg );	// Equivale a DATE.
	COleVariantExt( CY arg ); 
	COleVariantExt( BSTR arg );     // BSTR equivale a "char *"
	COleVariantExt( const char * arg );  // Idem BSTR, por comodidad para evitar un cast.
	COleVariantExt( CString& arg );      // Idem BSTR, por comodidad para evitar un cast.
	COleVariantExt( IUnknown * arg );
	COleVariantExt( IDispatch * arg );
	COleVariantExt( short * arg );   // Admite err�neamente VARIANT_BOOL * usar COLE_VARIANT *
	COleVariantExt( COLE_VARIANT_BOOL * arg );  // Equivale a VARIANT_BOOL *
	COleVariantExt( long * arg );   // Admite err�neamente SCODE * usar COLE_SCODE *
	COleVariantExt( COLE_SCODE * arg );  // Equivale a SCODE *	
	COleVariantExt( float * arg );
	COleVariantExt( double * arg );  // Admite err�neamente DATE * usar COLE_DATE *
	COleVariantExt( COLE_DATE * arg );	// Equivale a DATE *.
	COleVariantExt( CY * arg ); 
	COleVariantExt( BSTR * arg );    
	COleVariantExt( IUnknown * * arg ); 
	COleVariantExt( IDispatch * * arg );
	COleVariantExt( SAFEARRAY * arg );
	COleVariantExt( VARIANT * arg );
	COleVariantExt( void * arg );

    // Asignaciones:
    
	COleVariantExt& operator = (COleVariantExt& arg);  // Asignaci�n para copia segura (el operador "=" por defecto har�a una copia de la memoria que es peligrosa).
	COleVariantExt& operator = (VARIANT& arg);  // Idem anterior.

	COleVariantExt& operator = ( short arg );  // Admite tambi�n VARIANT_BOOL pero "vt" se definir�a mal, usar un cast a COLE_VARIANT_BOOL
	COleVariantExt& operator = ( COLE_VARIANT_BOOL arg );  // Equivale a VARIANT_BOOL
	COleVariantExt& operator = ( BOOL arg );  // Equivale a VARIANT_BOOL pero permite BOOL directo.
	COleVariantExt& operator = ( long arg );  // Admite tambi�n SCODE pero "vt" se definir�a mal, usar un cast a COLE_SCODE
	COleVariantExt& operator = ( COLE_SCODE arg );  // Equivale a SCODE
	COleVariantExt& operator = ( float arg );
	COleVariantExt& operator = ( double arg );  // Admite tambi�n DATE pero "vt" se definir�a mal, usar un cast a COLE_DATE
	COleVariantExt& operator = ( COLE_DATE arg );	// Equivale a DATE.
	COleVariantExt& operator = ( CY arg ); 
	COleVariantExt& operator = ( BSTR arg );
	COleVariantExt& operator = ( const char * arg );   // Idem BSTR, por comodidad para evitar un cast.	
	COleVariantExt& operator = ( CString& arg );   // Idem BSTR, por comodidad para evitar un cast.	
	COleVariantExt& operator = ( IUnknown * arg );
	COleVariantExt& operator = ( IDispatch * arg );
	COleVariantExt& operator = ( short * arg );   // Admite err�neamente VARIANT_BOOL * usar COLE_VARIANT *
	COleVariantExt& operator = ( COLE_VARIANT_BOOL * arg );  // Equivale a VARIANT_BOOL *
	COleVariantExt& operator = ( long * arg );   // Admite err�neamente SCODE * usar COLE_SCODE *
	COleVariantExt& operator = ( COLE_SCODE * arg );  // Equivale a SCODE *	
	COleVariantExt& operator = ( float * arg );
	COleVariantExt& operator = ( double * arg );  // Admite err�neamente DATE * usar COLE_DATE *
	COleVariantExt& operator = ( COLE_DATE * arg );	// Equivale a DATE *.
	COleVariantExt& operator = ( CY * arg ); 
	COleVariantExt& operator = ( BSTR * arg );    
	COleVariantExt& operator = ( IUnknown * * arg ); 
	COleVariantExt& operator = ( IDispatch * * arg );
	COleVariantExt& operator = ( SAFEARRAY * arg );
	COleVariantExt& operator = ( VARIANT * arg );
	COleVariantExt& operator = ( void * arg );


	// Cast de conversi�n de datos en salida:
	// No se pueden poner los  en los operadores pero en el modelo LARGE da igual.

	static CString getStrTipo( VARTYPE tipo );
	virtual void TestDatoInterno( VARTYPE tipo ); 	// Testea si el tipo solicitado de salida es el igual al tipo interno, si no coincide emite una aserci�n.
	
	operator short ();  // Admite tambi�n VARIANT_BOOL pero "vt" se definir�a mal, usar un cast a COLE_VARIANT_BOOL
	operator COLE_VARIANT_BOOL ();  // Equivale a VARIANT_BOOL
	operator long ();  // Admite tambi�n SCODE pero "vt" se definir�a mal, usar un cast a COLE_SCODE
	operator COLE_SCODE ();  // Equivale a SCODE
	operator float ();
	operator double ();  // Admite tambi�n DATE pero "vt" se definir�a mal, usar un cast a COLE_DATE
	operator COLE_DATE ();	// Equivale a DATE.
	operator CY (); 
	operator BSTR ();
	operator const char * ();   // Idem BSTR, por comodidad para evitar un cast. No hacemos lo mismo para CString pues no tiene ninguna utilidad al igualar a un CString y da error de ambiguedad.	
	operator IUnknown * ();
	operator IDispatch * ();


	operator short * ();   // Admite err�neamente VARIANT_BOOL * usar COLE_VARIANT *
	operator COLE_VARIANT_BOOL * ();  // Equivale a VARIANT_BOOL *
	operator long * ();   // Admite err�neamente SCODE * usar COLE_SCODE *
	operator COLE_SCODE * ();  // Equivale a SCODE *	
	operator float * ();
	operator double * ();  // Admite err�neamente DATE * usar COLE_DATE *
	operator COLE_DATE * ();	// Equivale a DATE *.
	operator CY * (); 
	operator BSTR * ();
	operator const char * * ();    	    
	operator IUnknown * * (); 
	operator IDispatch * * ();
	operator SAFEARRAY * ();
	operator VARIANT * ();
	operator void * ();


public:

*/  

};


#endif






