
// olevar.cpp

#include "stdafx.h"
#include "IdfDllApp.h"

#include "olevar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/*


COleVariantExt::COleVariantExt()
{
	VariantInit(this);   
}

COleVariantExt::~COleVariantExt()
{
	VariantClear(this);
}


void COleVariantExt::Inicializar()
{
	VariantInit(this);  
}


HRESULT COleVariantExt::LiberarDatos()
{
	return 	VariantClear(this);		
}


// Constructores para cada tipo de datos.

COleVariantExt::COleVariantExt(COleVariantExt& arg)
{
	VariantInit(this);
	*this = arg;
}

COleVariantExt::COleVariantExt(VARIANT& arg)
{
	VariantInit(this);
	*this = arg;
}



COleVariantExt::COleVariantExt( short arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( COLE_VARIANT_BOOL arg ) 
{
	VariantInit(this);   	
	*this = arg;
}

COleVariantExt::COleVariantExt( BOOL arg ) 
{
	VariantInit(this);   	
	*this = arg;
}

COleVariantExt::COleVariantExt( long arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( COLE_SCODE arg )
{
	VariantInit(this);   	
	*this = arg;
}


COleVariantExt::COleVariantExt( float arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( double arg )
{
	VariantInit(this);
	*this = arg;
}

COleVariantExt::COleVariantExt( COLE_DATE arg )
{	
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( CY arg ) 
{
	VariantInit(this);   
	*this = arg;
}


COleVariantExt::COleVariantExt( BSTR arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( IUnknown * arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( IDispatch * arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( short * arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( COLE_VARIANT_BOOL * arg )
{
	VariantInit(this);   	
	*this = arg;
}

COleVariantExt::COleVariantExt( long * arg )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( COLE_SCODE * arg )
{
	VariantInit(this);   	
	*this = arg;
}

COleVariantExt::COleVariantExt( float * arg  )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( double * arg  ) 
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( COLE_DATE * arg  ) 
{
	VariantInit(this);   	
	*this = arg;
}

COleVariantExt::COleVariantExt( CY * arg  ) 
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( BSTR * arg  ) 
{
	VariantInit(this);
	*this = arg;
}	

COleVariantExt::COleVariantExt( const char * arg  ) 
{
	VariantInit(this);
	*this = (BSTR)arg;
}	

COleVariantExt::COleVariantExt( CString& arg ) 
{
	VariantInit(this);
	*this = arg;
}

COleVariantExt::COleVariantExt( IUnknown * * arg  ) 
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( IDispatch * * arg  )
{
	VariantInit(this);   
	*this = arg;
}

COleVariantExt::COleVariantExt( SAFEARRAY * arg  )
{
	VariantInit(this);   
	*this = arg;
}


COleVariantExt::COleVariantExt( VARIANT * arg  )
{
	VariantInit(this);   
	*this = arg;
}


COleVariantExt::COleVariantExt( void * arg )
{
	VariantInit(this);   
	*this = arg;
}


// Operadores de asignación:


COleVariantExt& COleVariantExt::operator = (COleVariantExt& arg)
{
	VariantCopy(this, &arg);
	return *this;
}


COleVariantExt& COleVariantExt::operator = (VARIANT& arg)
{
	VariantCopy(this, &arg);
	return *this;
}


COleVariantExt& COleVariantExt::operator = ( short arg )
{
	VariantClear(this);   
	vt = VT_I2;   
    iVal = arg; 
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( COLE_VARIANT_BOOL arg ) 
{
	VariantClear(this);   	
	vt = VT_BOOL;
	BOOL = arg;		
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( BOOL arg ) 
{
	VariantClear(this);   	
	vt = VT_BOOL;
	v_bool = arg;		
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( long arg )
{
	VariantClear(this);   
	vt = VT_I4;	 
	lVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( COLE_SCODE arg )
{
	VariantClear(this);   	
	vt = VT_ERROR;
	scode = arg;	
	return *this;
}


COleVariantExt& COleVariantExt::operator = ( float arg )
{
	VariantClear(this);   
	vt = VT_R4;	 
	fltVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( double arg )
{
	VariantClear(this);
	vt = VT_R8;   
	dblVal = arg;  
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( COLE_DATE arg )
{	
	VariantClear(this);   
	vt = VT_DATE;
	date = arg;	
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( CY arg ) 
{
	VariantClear(this);   
	vt = VT_CY;
	cyVal = arg; 
	return *this;
}


COleVariantExt& COleVariantExt::operator = ( BSTR arg )
{
	VariantClear(this);   
	vt = VT_BSTR;		
	bstrVal = SysAllocString(arg); // Es obligatorio que apunte a una copia de la string.
	return *this;

}

COleVariantExt& COleVariantExt::operator = ( const char * arg )
{
	VariantClear(this);   
	vt = VT_BSTR;		
	bstrVal = SysAllocString(arg); // Es obligatorio que apunte a una copia de la string.
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( CString& arg )
{
	VariantClear(this);
	vt = VT_BSTR;		
	bstrVal = SysAllocString((const char *)arg); // Es obligatorio que apunte a una copia de la string.
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( IUnknown * arg )
{
	VariantClear(this);   
	vt = VT_UNKNOWN;		
	punkVal = arg;  
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( IDispatch * arg )
{
	VariantClear(this);   
	vt = VT_DISPATCH;
	pdispVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( short * arg )
{
	VariantClear(this);   
	vt = VT_BYREF|VT_I2;
	piVal = arg; 
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( COLE_VARIANT_BOOL * arg )
{
	VariantClear(this);   	
	vt = VT_BYREF|VT_BOOL;
	pbool = (VARIANT_BOOL *)arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( long * arg )
{
	VariantClear(this);   
	vt = VT_BYREF|VT_I4;
	plVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( COLE_SCODE * arg )
{
	VariantClear(this);   	
	vt = VT_BYREF|VT_ERROR;
	pscode = (SCODE *)arg; 
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( float * arg  )
{
	VariantClear(this);   
	vt = VT_BYREF|VT_R4;
	pfltVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( double * arg  ) 
{
	VariantClear(this);   
	vt = VT_BYREF|VT_R8; 
	pdblVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( COLE_DATE * arg  ) 
{
	VariantClear(this);   	
	vt = VT_BYREF|VT_DATE; 
	pdate = (DATE *)arg; 
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( CY * arg  ) 
{
	VariantClear(this);   
	vt = VT_BYREF|VT_CY;	
	pcyVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( BSTR * arg  ) 
{
	VariantClear(this);
	vt = VT_BYREF|VT_BSTR;   
	pbstrVal = arg;
	return *this;
}	

COleVariantExt& COleVariantExt::operator = ( IUnknown * * arg  ) 
{
	VariantClear(this);   
	vt = VT_BYREF|VT_UNKNOWN ;	
	ppunkVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( IDispatch * * arg  )
{
	VariantClear(this);   
	vt = VT_BYREF|VT_DISPATCH;
	ppdispVal = arg;
	return *this;
}

COleVariantExt& COleVariantExt::operator = ( SAFEARRAY * arg  )
{
	VariantClear(this);   
	vt = VT_ARRAY;
	parray = arg;
	return *this;
}


COleVariantExt& COleVariantExt::operator = ( VARIANT * arg  )
{
	VariantClear(this);   
	vt = VT_BYREF|VT_VARIANT;
	pvarVal = arg;
	return *this;
}


COleVariantExt& COleVariantExt::operator = ( void * arg )
{
	VariantClear(this);   
	byref = arg;
	return *this;
}


CString COleVariantExt::getStrTipo( VARTYPE tipo )
{
	CString s;
	
	switch (tipo)
	{
	case VT_I2:
		s = "short";
		break;
	case VT_I4:
		s = "long";		
		break;
	case VT_R4:
		s = "float";		
		break;
	case VT_R8:
		s = "double";		
		break;
	case VT_DATE:
		s = "DATE";		
		break;
	case VT_CY:
		s = "CY";		
		break;
	case VT_BSTR:
		s = "char *";		
		break;
	case VT_DISPATCH:
		break;
	case VT_ERROR:
		s = "SCODE";			
		break;
	case VT_BOOL:
		s = "COLE_VARIANT_BOOL";			
		break;
	case VT_VARIANT:
		s = "VARIANT";			
		break;
	case VT_UNKNOWN:
		s = "IUnknown *";			
		break;

	case VT_I2|VT_BYREF:
		s = "short *";			
		break;
	case VT_I4|VT_BYREF:
		s = "long *";			
		break;
	case VT_R4|VT_BYREF:
		s = "float *";			
		break;
	case VT_R8|VT_BYREF:
		s = "double *";			
		break;
	case VT_DATE|VT_BYREF:
		s = "DATE *";			
		break;
	case VT_CY|VT_BYREF:
		s = "CY *";			
		break;
	case VT_BSTR|VT_BYREF:
		s = "char * *";			
		break;
	case VT_DISPATCH|VT_BYREF:
		s = "IDispatch * *";			
		break;
	case VT_ERROR|VT_BYREF:
		s = "SCODE *";			
		break;
	case VT_BOOL|VT_BYREF:
		s = "COLE_VARIANT_BOOL *";			
		break;
	case VT_VARIANT|VT_BYREF:
		s = "VARIANT *";			
		break;
	case VT_UNKNOWN|VT_BYREF:
		s = "IUnknown * *";			
		break;

	default:
		s = "¡DESCONOCIDO!";  // desconocido tipo
		break;
	}
	return s;
}


void COleVariantExt::TestDatoInterno( VARTYPE tipo ) 
{
	if ( vt != tipo )
	{
		CString stemp = "El tipo de datos \"" + getStrTipo(tipo) + "\" solicitado, no coincide con el almacenado internamente \"" + getStrTipo(vt) + "\" en la clase COleVariantExt"; 
		AfxThrowOleDispatchException( S_FALSE, (const char *)stemp);		
	}
}


// Cast de salida de datos.

COleVariantExt::operator short ()
{
	TestDatoInterno( VT_I2 );
    return iVal; 
}

COleVariantExt::operator COLE_VARIANT_BOOL ()
{
	TestDatoInterno( VT_BOOL );
    return v_bool; 
}

COleVariantExt::operator long ()
{
	TestDatoInterno( VT_I4 );
    return lVal; 
}

COleVariantExt::operator COLE_SCODE ()
{
	TestDatoInterno( VT_ERROR );
    return scode; 
}

COleVariantExt::operator float ()
{
	TestDatoInterno( VT_R4 );
    return fltVal; 
}

COleVariantExt::operator double ()
{
	TestDatoInterno( VT_R8 );
    return dblVal; 
}

COleVariantExt::operator COLE_DATE ()
{
	TestDatoInterno( VT_DATE );
    return date; 
}

COleVariantExt::operator CY ()
{
	TestDatoInterno( VT_CY );
    return cyVal; 
}

COleVariantExt::operator BSTR ()
{
	TestDatoInterno( VT_BSTR );
    return bstrVal; 
}

COleVariantExt::operator const char * ()
{
	TestDatoInterno( VT_BSTR );
    return bstrVal; 
}


COleVariantExt::operator IUnknown * ()
{
	TestDatoInterno( VT_UNKNOWN );
    return punkVal; 
}

COleVariantExt::operator IDispatch *  ()
{
	TestDatoInterno( VT_DISPATCH );
    return pdispVal; 
}




COleVariantExt::operator short * ()
{
	TestDatoInterno( VT_BYREF|VT_I2 );
    return piVal; 
}

COleVariantExt::operator COLE_VARIANT_BOOL * ()
{
	TestDatoInterno( VT_BYREF|VT_BOOL );
    return (COLE_VARIANT_BOOL *)pv_bool; 
}

COleVariantExt::operator long * ()
{
	TestDatoInterno( VT_BYREF|VT_I4 );
    return plVal; 
}

COleVariantExt::operator COLE_SCODE * ()
{
	TestDatoInterno( VT_BYREF|VT_ERROR );
    return (COLE_SCODE *)pscode; 
}

COleVariantExt::operator float * ()
{
	TestDatoInterno( VT_BYREF|VT_R4 );
    return pfltVal; 
}

COleVariantExt::operator double * ()
{
	TestDatoInterno( VT_BYREF|VT_R8 );
    return pdblVal; 
}

COleVariantExt::operator COLE_DATE * ()
{
	TestDatoInterno( VT_BYREF|VT_DATE );
    return (COLE_DATE *)pdate; 
}


COleVariantExt::operator CY * ()
{
	TestDatoInterno( VT_BYREF|VT_CY );
    return pcyVal; 
}

COleVariantExt::operator BSTR * ()
{
	TestDatoInterno( VT_BYREF|VT_BSTR );
    return pbstrVal; 
}

COleVariantExt::operator const char * *()
{
	TestDatoInterno( VT_BYREF|VT_BSTR );
    return (const char * *)pbstrVal; 
}

COleVariantExt::operator IUnknown * * ()
{
	TestDatoInterno( VT_BYREF|VT_UNKNOWN );
    return ppunkVal; 
}

COleVariantExt::operator IDispatch * * ()
{
	TestDatoInterno( VT_BYREF|VT_DISPATCH );
    return ppdispVal; 
}

COleVariantExt::operator SAFEARRAY * ()
{
	TestDatoInterno( VT_ARRAY );
    return parray; 
}

COleVariantExt::operator VARIANT * ()
{
	TestDatoInterno( VT_BYREF|VT_VARIANT );
    return pvarVal; 
}


COleVariantExt::operator void * ()
{
    return byref; 
}



*/

