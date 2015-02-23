
// wordp.cpp

#include "stdafx.h"

#include <stdio.h>

#include "..\DLLDiag.h"

#include "wordp.h"


/*


// Clase Word_Iniciales 

IMPLEMENTAR_COMUNICACION(Word_ComIniciales, CCom)

// Clase Word_Salidas

IMPLEMENTAR_COMUNICACION(Word_ComSalidas, CCom)


// Implementación de Word_Entrada

IMPLEMENTAR_BLOQUE_FUNCIONAL(Word_Entrada, CBloqueFunc, 1)

IMPLEMENTAR_COM_ENTRADA(Word_ComIniciales, Word_Entrada)
IMPLEMENTAR_COM_SALIDA(Word_ComIniciales, Word_Entrada)


Word_Entrada::Word_Entrada()
{
}

Word_Entrada::~Word_Entrada()
{
}


void Word_Entrada::IniciarDatos()
{
	base = 0;
	altura = 0;
	RedefAyuda((CString)"Entrada de datos");
	CambiaEstado(CORRECTO);  // Para poder retroanotar.
}


BOOL Word_Entrada::NuevosObjDatos()
{
	ejemplo = new CFontDialog;  // Para probar si la creación/destrucción se hace en el orden correcto
	Consola("Creado objeto ejemplo");
	TRACE("Creado objeto ejemplo\n");
	return true;
}


void Word_Entrada::DestObjDatos()
{
	Consola("Destruido objeto ejemplo");
	TRACE("Destruido objeto ejemplo\n");
	delete ejemplo;
}


void Word_Entrada::RecibirrFichero(CArchive& ar)
{
    ar << base << altura;
}

void Word_Entrada::LeerFichero(CArchive& ar)
{
	NuevosObjDatos();
    ar >> base >> altura;
}


CString Word_Entrada::Accion()
{
	
	
	COleAutomation OLEWord;  
    
    TRY
    {	
		if (!OLEWord.CreateDispatch( "Word.Basic" ))  // Ejecuta Word si es necesario aunque oculto.
		{   
			//Mensaje((CString)"Fallido enlace OLE con Word");
		    AfxThrowOleDispatchException( (WORD)0, "Fallido enlace OLE con Word");    	
		}

        OLEWord.Proc("ApMostrar");  // Si no se ejecutó Word antes, entonces está oculto, este comando lo saca a la luz.
        
		if (!AccionOLEItem("Wordp1", OLEIVERB_OPEN))  
		{  // No está embebido en el documento o no tiene este nombre.
		
			// Iteramos por la lista de ventanas abiertas para ver si ya ha sido cargada.
			int numVent;
			numVent = (short)OLEWord.Func("ContarVentanas");
			BOOL res = false;
			for (long i = 1; i<=numVent; i++)
			{
				CString	nombre = (const char*)OLEWord.Func("NombreVentana",(long) i);
			    nombre.MakeUpper();	
			    if (nombre.Find("WORDP1.DOC") >= 0)
			    { 
			    	res = true; break;
			    }  // El fichero ya ha sido cargado de alguna forma (a mano, por OLE, por el propio programa etc.)
			} 
			
			if (res) OLEWord.Proc("ListaVentana",(long) i);// Así aseguramos que es la ventana activa, para recibir los comandos de WordBasic.		
			else
			{		
	        	// No ha sido cargado el documento, se carga y se pone activo.
	        	// Si ya estuviera abierto, es también forma de hacerlo activo (recargarlo), pero no es aconsejable si fue cargado a través de un objeto OLE embebido o linkado,
	        	// pues supone que el fichero ha sido cargado (y bloqueado) por una aplicación diferente y hace una copia y se hace un lio.
	        	OLEWord.Proc("ArchivoAbrir","T:\\JOSEMA\\PROYECTO\\PROYDL~1\\DLLDIAG\\WORDP1.DOC");  
			}
		}		
		
		// Para obtener el contenido de una marca que engloba una celda, no usaremos "getMarcador" pues nos devuelve el contenido de la fila entera y además caracteres de formato de la tabla. 
		
		OLEWord.Proc("EdiciónIrA", "BASE");  // Esta acción selecciona toda la celda al caer sobre ella.

		OLEWord.Proc("Insertar","");	// Es una forma de pasar de la selección de toda la celda a la selección de sólo el contenido textual.	Eludimos los caracteres de formato.

		CString Sbase = (const char*)OLEWord.Func("Selección");  // Devuelve el texto seleccionado (el contenido de la celda).		
		
		// char * Sbase = OLEWord.Func("getMarcador","BASE");   // getemos el texto asociado al marcador 

		OLEWord.Proc("EdiciónIrA", "ALTURA");  // Esta acción selecciona toda la celda al caer sobre ella.

		OLEWord.Proc("Insertar","");	// Es una forma de pasar de la selección de toda la celda a la selección de sólo el contenido textual.	Eludimos los caracteres de formato.

		CString Saltura = (const char*)OLEWord.Func("Selección");  // Devuelve el texto seleccionado (el contenido de la celda).		

		// char * Saltura = OLEWord.Func("getMarcador","ALTURA");   // getemos el texto asociado al marcador 

		OLEWord.Proc("EdiciónIrA", "FECHA");  // Esta acción selecciona toda la celda de la fecha al caer sobre ella. No podemos directamente insertar la fecha, no es lo mismo la celda seleccionada que el texto del mismo.

		OLEWord.Proc("Insertar","");	// Es una forma de pasar de la selección de toda la celda a la selección de sólo el contenido textual.	

		OLEWord.Proc("InsertarFechaHora","dddd, d 'de' MMMM 'de' aaaa, H.mm",(short) 0);	// Funciona cuando es texto lo que sustituye, pero no funcionaría si lo seleccionado fuera la celda completa.		
        
        OLEWord.Proc("ArchivoRecibirr");

		OLEWord.ReleaseDispatch();

		// Mostramos los resultados después para que no haya ninguna parada tal que el usuario pudiera cambiar el documento activo.
		CString stemp = "Base del triángulo: " + Sbase;
		Mensaje( stemp );		
		stemp = "Altura del triángulo: " + Saltura;
		Mensaje( stemp );		
		
		base = atof( (const char *)Sbase );
		altura = atof( (const char *)Saltura );

	}
	CATCH_ALL(e)
	{
		OLEWord.ReleaseDispatch();	
		COleDispatchException* et = (COleDispatchException*)e;
		CString stemp = "Excepción OLE utilizando " + et->m_strSource + " en la función " + OLEWord.FuncUltima + "\nDescripción: " + et->m_strDescription;
		Mensaje(stemp);
	}
	END_CATCH_ALL;
		
 	return (CString)"";
}



BOOL Word_Entrada::RecibirDatosEntrada(const Word_ComIniciales* pE)
{
	if ((pE->base <0)||(pE->altura <0)) return false;
	base = pE->base;
	altura = pE->altura;

	CambiaEstado(CORRECTO);
	return true;
}



void Word_Entrada::EnviarDatosSalida(Word_ComIniciales* pS)
{
	pS->base = base;
	pS->altura = altura;
}


BOOL Word_Entrada::PropUsuario()
{
	CBloqueFunc::PropUsuario();
	return false; // No actualizar el registro tiempo.
}


// Implementación de Word_Calculo

IMPLEMENTAR_BLOQUE_FUNCIONAL(Word_Calculo, CBloqueFunc, 1)

IMPLEMENTAR_COM_ENTRADA(Word_ComIniciales, Word_Calculo)
IMPLEMENTAR_COM_SALIDA(Word_ComSalidas, Word_Calculo)


Word_Calculo::Word_Calculo()
{
}

Word_Calculo::~Word_Calculo()
{
}


void Word_Calculo::IniciarDatos()
{
	base = 0;
	altura = 0;
	area = 0;
	RedefAyuda((CString)"Cálculo del área");
	CambiaEstado(CORRECTO);  // Para poder retroanotar.
}


BOOL Word_Calculo::NuevosObjDatos()
{
	ejemplo = new CFontDialog;  // Para probar si la creación/destrucción se hace en el orden correcto
	Consola("Creado objeto ejemplo");
	TRACE("Creado objeto ejemplo\n");
	return true;
}


void Word_Calculo::DestObjDatos()
{
	Consola("Destruido objeto ejemplo");
	TRACE("Destruido objeto ejemplo\n");
	delete ejemplo;
}


void Word_Calculo::RecibirrFichero(CArchive& ar)
{
    ar << base << altura << area;
}

void Word_Calculo::LeerFichero(CArchive& ar)
{
	NuevosObjDatos();
    ar >> base >> altura >> area;
}

CString Word_Calculo::Accion()
{
	area = (base * altura) / 2; 
	// int  decimal, sign;  // No nos sirven para nada en este caso.
	char Sarea[30];
	_gcvt( area, 10, Sarea );	
 	CString stemp = "Area Calculada: " + CString(Sarea); 	
 	Mensaje( stemp );
 	return (CString)"";
}

BOOL Word_Calculo::RecibirDatosEntrada(const Word_ComIniciales* pE)
{
	if ((pE->base < 0)||(pE->altura < 0)) return false;
	base = pE->base;
	altura = pE->altura;
	CambiaEstado(CORRECTO);
	return true;
}

void Word_Calculo::EnviarDatosSalida(Word_ComSalidas* pS)
{
	pS->area = area;
}


BOOL Word_Calculo::PropUsuario()
{
	CBloqueFunc::PropUsuario();
	return false; // No actualizar el registro tiempo.
}



// Implementación de Word_Resultados

IMPLEMENTAR_BLOQUE_FUNCIONAL(Word_Resultados, CBloqueFunc, 1)

IMPLEMENTAR_COM_ENTRADA(Word_ComSalidas, Word_Resultados)
IMPLEMENTAR_COM_SALIDA(Word_ComSalidas, Word_Resultados)


Word_Resultados::Word_Resultados()
{
}

Word_Resultados::~Word_Resultados()
{
}


void Word_Resultados::IniciarDatos()
{
	area = 0;
	RedefAyuda((CString)"Salida de resultados");
	CambiaEstado(CORRECTO);  // Para poder retroanotar.
}


BOOL Word_Resultados::NuevosObjDatos()
{
	ejemplo = new CFontDialog;  // Para probar si la creación/destrucción se hace en el orden correcto
	Consola("Creado objeto ejemplo");
	TRACE("Creado objeto ejemplo\n");
	return true;
}


void Word_Resultados::DestObjDatos()
{
	Consola("Destruido objeto ejemplo");
	TRACE("Destruido objeto ejemplo\n");
	delete ejemplo;
}


void Word_Resultados::RecibirrFichero(CArchive& ar)
{
    ar << area;
}

void Word_Resultados::LeerFichero(CArchive& ar)
{
	NuevosObjDatos();
    ar >> area;
}


CString Word_Resultados::Accion()
{
	char st[30];
	CString Sarea = _gcvt( area, 10, st );		
	
	COleAutomation OLEWord;
    
    TRY
    {	
		if (!OLEWord.CreateDispatch( "Word.Basic" ))
		{   
			//Mensaje((CString)"Fallido enlace OLE con Word");
 		    AfxThrowOleDispatchException( (WORD)0, "Fallido enlace OLE con Word");    	
		}

        OLEWord.Proc("ApMostrar");  // Si no se ejecutó Word antes, entonces está oculto, este comando lo saca a la luz.

		if (!AccionOLEItem("Wordp2", OLEIVERB_OPEN))  
		{  // No está embebido en el documento o no tiene este nombre.
		
			int numVent;
			numVent = (short)OLEWord.Func("ContarVentanas");
			BOOL res = false;
			for (long i = 1; i<=numVent; i++)
			{
				CString	nombre = (const char*)OLEWord.Func("NombreVentana",(long) i);
			    nombre.MakeUpper();	
			    if (nombre.Find("WORDP2.DOC") >= 0)
			    { 
			    	res = true; break;
			    }  // El fichero ya ha sido cargado de alguna forma (a mano, por OLE, por el propio programa etc.)
			} 
			
			if (res) OLEWord.Proc("ListaVentana", (long) i); // Así aseguramos que es la ventana activa, para recibir los comandos de WordBasic.		
			else
			{		
	        	// No ha sido cargado el documento, se carga y se pone activo.
	        	// Si ya estuviera abierto, es también forma de hacerlo activo (recargarlo), pero no es aconsejable si fue cargado a través de un objeto OLE embebido o linkado,
	        	// pues supone que el fichero ha sido cargado (y bloqueado) por una aplicación diferente y hace una copia y se hace un lio.
	        	OLEWord.Proc("ArchivoAbrir","T:\\JOSEMA\\PROYECTO\\PROYDL~1\\DLLDIAG\\WORDP2.DOC");  
			}
		}

		// Para obtener el contenido de una marca que engloba una celda, no usaremos "getMarcador" pues nos devuelve el contenido de la fila entera y además caracteres de formato de la tabla. 
		
		OLEWord.Proc("EdiciónIrA", "AREA");  // Esta acción selecciona toda la celda al caer sobre ella.

		OLEWord.Proc("Insertar","");	// Es una forma de pasar de la selección de toda la celda a la selección de sólo el contenido textual.	Eludimos los caracteres de formato.

		OLEWord.Proc("Insertar",(const char *)Sarea  );	// Introducimos el nuevo valor del área que sustituye la selección actual.

		OLEWord.Proc("EdiciónIrA", "AREA");  // Esta acción selecciona toda la celda al caer sobre ella.

		OLEWord.Proc("Insertar","");	// Es una forma de pasar de la selección de toda la celda a la selección de sólo el contenido textual.	Eludimos los caracteres de formato.
                                                                                                                  
		CString SArea = (const char *)OLEWord.Func("Selección");  // Devuelve el texto seleccionado (el contenido de la celda).		
		
		OLEWord.Proc("EdiciónIrA", "FECHA");  // Esta acción selecciona toda la celda de la fecha al caer sobre ella. No podemos directamente insertar la fecha, no es lo mismo la celda seleccionada que el texto del mismo.

		OLEWord.Proc("Insertar","");	// Es una forma de pasar de la selección de toda la celda a la selección de sólo el contenido textual.	

		OLEWord.Proc("InsertarFechaHora","dddd, d 'de' MMMM 'de' aaaa, H.mm",(short) 0);	// Funciona cuando es texto lo que sustituye, pero no funcionaría si lo seleccionado fuera la celda completa.		
        
        OLEWord.Proc("ArchivoRecibirr");

		CString stemp = "Área del triángulo calculada: " + SArea;
		Mensaje( stemp ); // Mostrar ahora el resultado para que el usuario no cambie de documento activo.		

		// Prueba de como podemos crear y ejecutar una macro temporal y eliminarla
		// a fin de apoyarnos en las macros de WordBasic, con código almacenado en el bloque:
        // Documentar esto como ejemplo del posible uso de getMacro() y DefMacro()
        
		CString macrotemp = "Sub MAIN\n Insertar \"Hola\" \nEnd Sub";   // Ejemplo de macro escrita en una cadena de caracteres
        // Puede usarse la macro de getMacro() introducida por el diálogo de propiedades.
		
		OLEWord.Proc("HerramMacro", "ProyTemporalMacro", (int)false, (int)true , (int)1 );  // Si no existe se crea la macro
		OLEWord.Proc("EdiciónSeleccionarTodo");  //  Por si acaso no se hubiera borrado en una ejecución anterior.
		OLEWord.Proc("Insertar","");   // Lo borramos todo y quitamos la selección  
		OLEWord.Proc("Insertar",(const char *)getMacro());  // Código de la macro  
		OLEWord.Proc("ArchivoCerrar",(long)1);        // Cierre de la ventana de grabado de la macro.
		OLEWord.Proc("HerramMacro", "ProyTemporalMacro", true);  // Ejecuta la macro
		OLEWord.Proc("HerramMacro", "ProyTemporalMacro", (int)false, (int)false, (int)false, true );  // Eliminamos la macro temporal

		OLEWord.ReleaseDispatch();

	}
	CATCH_ALL(e)
	{
		OLEWord.ReleaseDispatch();	
		COleDispatchException* et = (COleDispatchException*)e;
		CString stemp = "Excepción OLE utilizando " + et->m_strSource + " en la función " + OLEWord.FuncUltima + "\nDescripción: " + et->m_strDescription;
		Mensaje(stemp);
	}
	END_CATCH_ALL;
	
 	return (CString)"";
}



BOOL Word_Resultados::RecibirDatosEntrada(const Word_ComSalidas* pE)
{
	if (pE->area < 0) return false;
	area = pE->area;	
	CambiaEstado(CORRECTO);
	return true;
}



void Word_Resultados::EnviarDatosSalida(Word_ComSalidas* pS)
{
	pS->area = area;
}


BOOL Word_Resultados::PropUsuario()
{
	CBloqueFunc::PropUsuario();
	return false; // No actualizar el registro tiempo.
}



*/

