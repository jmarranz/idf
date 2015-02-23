// oleautom.cpp : implementation file
//

#include "stdafx.h"
#include "IdfDllApp.h" 

#include "olevar.h"
#include "oleautom.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif




/////////////////////////////////////////////////////////////////////////////
// COleAutomation

COleAutomation::COleAutomation()
{
	// No hace falta inicializar result porque COleVariantExt se inicia en el constructor
	FuncUltima = "NINGUNA FUNCIÓN LLAMADA";
}


COleAutomation::~COleAutomation()
{
	// No hace falta liberar result porque el tipo COleVariantExt se libera en el destructor.
}


HRESULT COleAutomation::getIDdelNombre(char * nombre, DISPID& dispid)	
{
	LPDISPATCH pdisp = DetachDispatch( );	
	if (!pdisp)
	{
		char st[] = "ERROR: Se ha invocado COleAutomation::getIDdelNombre() sin crear antes una conexión con un objeto OLE";
		AfxGetApp()->DoWaitCursor(-1);
		AfxThrowOleDispatchException( S_FALSE, st);		
	}	
	
	HRESULT hresult = pdisp->GetIDsOfNames(IID_NULL, (OLECHAR * *)&nombre, 1,LOCALE_SYSTEM_DEFAULT, &dispid);
	if (hresult != ResultFromScode(S_OK))
	{
		CString stemp;
		stemp = "ERROR: El método o propiedad: \"" + CString(nombre) + "\" no existe en el objeto OLE conectado";
		AfxGetApp()->DoWaitCursor(-1);
		AfxThrowOleDispatchException( (WORD)GetScode(hresult), (const char *)stemp);		
	}
	AttachDispatch(pdisp);	
	return hresult;
}


COleVariantExt& COleAutomation::LiberarResult()
{
	// Es necesario antes de hacer una llamada OLE (método o propiedad) liberar "result" de un anterior acceso.	
	// El resultado es una variable con vt = VT_EMPTY
	// result.LiberarDatos();
	result.Detach();
	return result;
}


void COleAutomation::ProcesoComun(char * nombre,const VARTYPE& tiposalida)	
{
    // Funcionalidad común a la familia Func() y Proc() para minimizar el código.
    FuncUltima = CString(nombre);
	getIDdelNombre(nombre, dispid); // El resultado es necesariamente S_OK
	LiberarResult(); // Libera los datos de la variable resultado de una llamada anterior a una función.
	result.vt = tiposalida;  // Es necesario en las funciones que no devuelven valor alguno que sea VT_EMPTY, si devuelven valor entonces VARIANT.
}

// Paso de parámetros para cada número de variables argumento.

// Nota: Por razones desconocidas es preciso dar como argumentos de InvokeHelper argumentos de tipo VARIANT (no COleVariantExt) o funciona mal  y escribe fuera de la memoria
// por lo menos por culpa de la variable de resultado.
// No influye en nada en usar COleVariantExt para preparar los argumentos y además el cast es automático (transparente).
// Por razones desconocidas (Invoke no funciona) es necesario hacer cast explícitos a COleVariantExt a (VARIANT) aunque no de error de compilación.


void COleAutomation::PasoParamComun(char * nombre,const VARTYPE& tiposalida) 
{
	AfxGetApp()->DoWaitCursor(1);
	ProcesoComun(nombre,tiposalida);	
	InvokeHelper(dispid, DISPATCH_METHOD, result.vt, (void*)(VARIANT*)&result, NULL);
	AfxGetApp()->DoWaitCursor(-1);
}


Implementa_PasoParamComun(1)
Implementa_PasoParamComun(2)
Implementa_PasoParamComun(3)
Implementa_PasoParamComun(4)
Implementa_PasoParamComun(5)
Implementa_PasoParamComun(6)
Implementa_PasoParamComun(7)
Implementa_PasoParamComun(8)
Implementa_PasoParamComun(9)
Implementa_PasoParamComun(10)
Implementa_PasoParamComun(11)
Implementa_PasoParamComun(12)
Implementa_PasoParamComun(13)
Implementa_PasoParamComun(14)
Implementa_PasoParamComun(15)

 
void COleAutomation::DefPropiedad(char * nombre, const COleVariantExt& var)
{
	DISPID dwDispID;
   	FuncUltima = CString(nombre);	
	getIDdelNombre(nombre, dwDispID);		
	SetProperty( dwDispID, VT_VARIANT, (VARIANT)var );
}

COleVariantExt& COleAutomation::getPropiedad(char * nombre)
{
	DISPID dwDispID;
   	FuncUltima = CString(nombre);	
	getIDdelNombre(nombre, dwDispID);		
	GetProperty( dwDispID, VT_VARIANT, (void*)(VARIANT*)&(VARIANT)result );
	return result;
}	


// Llamadas que devuelven un valor (funciones según el concepto de Visual Basic).


COleVariantExt& COleAutomation::Func(char * nombre)   // Función que devuelve un valor.
{
	PasoParamComun(nombre,VT_VARIANT);
	return result;
}


Implementa_Func(1)
Implementa_Func(2)
Implementa_Func(3)
Implementa_Func(4)
Implementa_Func(5)
Implementa_Func(6)
Implementa_Func(7)
Implementa_Func(8)
Implementa_Func(9)
Implementa_Func(10)
Implementa_Func(11)
Implementa_Func(12)
Implementa_Func(13)
Implementa_Func(14)
Implementa_Func(15)



/*
COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1)
{
	PasoParamComun(nombre,VT_VARIANT,param1);
	return result;
}

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2)
{
	PasoParamComun(nombre,VT_VARIANT,param1,param2);
	return result;
}

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3)
{
	PasoParamComun(nombre,VT_VARIANT,param1,param2,param3);
	return result;
}

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4)
{
	// PasoParamComun(nombre,VT_VARIANT,param1,param2,param3,param4);	
	return result;
}

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5)
{
	// PasoParamComun(nombre,VT_VARIANT,param1,param2,param3,param4,param5);		
	return result;
}

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6)
{
	// PasoParamComun(nombre,VT_VARIANT,param1,param2,param3,param4,param5,param6);	
	return result;
}

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7)
{
	//PasoParamComun(nombre,VT_VARIANT,param1,param2,param3,param4,param5,param6,param7);	
	return result;
}					

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7, const COleVariantExt& param8)
{
	//PasoParamComun(nombre,VT_VARIANT,param1,param2,param3,param4,param5,param6,param7,param8);	
	return result;
}							

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7, const COleVariantExt& param8, const COleVariantExt& param9)
{
	//PasoParamComun(nombre,VT_VARIANT,param1,param2,param3,param4,param5,param6,param7,param8,param9);	
	return result;
}							

COleVariantExt& COleAutomation::Func(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7, const COleVariantExt& param8, const COleVariantExt& param9, const COleVariantExt& param10)
{
	//PasoParamComun(nombre,VT_VARIANT,param1,param2,param3,param4,param5,param6,param7,param8,param9,param10);	
	return result;
}								
*/






// Llamadas que no devuelven valor (procedimientos según notación de Visual Basic).


void COleAutomation::Proc(char * nombre)   // Función que devuelve un valor.
{
	PasoParamComun(nombre,VT_EMPTY);
}




Implementa_Proc(1)
Implementa_Proc(2)
Implementa_Proc(3)
Implementa_Proc(4)
Implementa_Proc(5)
Implementa_Proc(6)
Implementa_Proc(7)
Implementa_Proc(8)
Implementa_Proc(9)
Implementa_Proc(10)
Implementa_Proc(11)
Implementa_Proc(12)
Implementa_Proc(13)
Implementa_Proc(14)
Implementa_Proc(15)





/*
void COleAutomation::Proc(char * nombre, const COleVariantExt& param1)
{
	PasoParamComun(nombre,VT_EMPTY,param1);
}

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2);
}

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3);
}


void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3,param4);	
}

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3,param4,param5);		
}

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3,param4,param5,param6);	
}

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3,param4,param5,param6,param7);	
}					

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7, const COleVariantExt& param8)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3,param4,param5,param6,param7,param8);	
}							

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7, const COleVariantExt& param8, const COleVariantExt& param9)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3,param4,param5,param6,param7,param8,param9);	
}							

void COleAutomation::Proc(char * nombre, const COleVariantExt& param1, const COleVariantExt& param2, const COleVariantExt& param3, const COleVariantExt& param4, const COleVariantExt& param5, const COleVariantExt& param6, \
							const COleVariantExt& param7, const COleVariantExt& param8, const COleVariantExt& param9, const COleVariantExt& param10)
{
	PasoParamComun(nombre,VT_EMPTY,param1,param2,param3,param4,param5,param6,param7,param8,param9,param10);	
}								

*/
	