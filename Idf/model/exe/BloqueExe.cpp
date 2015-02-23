// BloqueExe.cpp: implementation of the CBloqueExe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\idf.h"
#include "BloqueExe.h"

#include "DiagExe.h"
#include "ConectExe.h"
#include "Comunicacion.h"

#include "..\Conect.h"
#include "..\ConectInicio.h"
#include "..\ConectFin.h"
#include "ConectInicioExe.h"
#include "ConectFinExe.h"

#include "..\Bloque.h"

#include "..\..\view\BloqueVistas.h"
#include "..\..\view\exe\BloqueVistasExe.h"
#include "..\..\view\DibBloque.h"
#include "..\..\view\exe\DiagramaVistasExe.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CBloqueExe,CBloqueModo)


CBloqueExe::CBloqueExe()
{
	IniciarVarEstado();     // Var de estado
}

CBloqueExe::~CBloqueExe()
{

}

void CBloqueExe::IniciarVarEstado()    // Llamada en creaci�n, carga e inicializaci�n expl�cita. S�lo variables de entorno.
{
	m_inicioAuto = false;  
    m_contAuto = 0;
	m_haPasadoRetro = false;
}


void CBloqueExe::IniciarExplicito(const Instante& t)  
{
	// Se ejecuta a trav�s de men� por el usuario, inicializa ciertas variables funcionales a sus valores por defecto.

	IniciarVarEstado();
}

CString CBloqueExe::Ejecutar(CBaseView *view)
{
	return Ejecutar(NULL,view);
}

CString CBloqueExe::Ejecutar(CConect* con,CBaseView* view)
{
	CBloque* pbloque = getBloque();
	CDiagExe* pdiag = pbloque->getDiagExe();

	if (pbloque->getAE())
	{
		if (!ProcesarEntradaDeDatos(con,(CString)""))
		{
			// Ha habido un fallo en la comunicaci�n se para el modo auto
			if (pdiag->m_modoAuto) pdiag->m_modoAuto = false;
			return (CString)"";    // SALIR
		}		
	}
    
	Consola("Ejecut�ndose");	

	m_etiqContinuar = Accion(view);

	Consola("Termin� ejecuci�n");
	
	if (pbloque->getAS())
	{
		if (!ProcesarSalidaDeDatos(view, m_etiqContinuar))
		{
			// Ha habido un fallo en la comunicaci�n se para el modo auto
			if (pdiag->m_modoAuto) pdiag->m_modoAuto = false;  // Se para el flujo de ejecuci�n
			return (CString) "";  // SALIR
		}
	}
    else  
	{ 
		pdiag->p_bloqUltimo = pbloque;   // Ultimo bloque que recibe datos (o �ltimo ejecutado).

		pbloque->getVistas()->getExe()->CentrarBloque(view); 
	}
    
	return m_etiqContinuar;
}


void CBloqueExe::ComienzoEjecucion(CBaseView *view)
{
	if (!p_bloque->EsRetroanotador())
	{
		Ejecutar(view);

		CDiagBase* pdiag = p_bloque->getDiag();
   		pdiag->getVistas()->Actualizar();	 	
	}
	else
	{
		// Retroanotar a todos los bloques conectados.
		Retroanotar((CString)"",false);	
	}
}

void CBloqueExe::ComienzoEjecucionAuto(CBaseView *view)
{
	if (!p_bloque->EsRetroanotador())
	{
		CDiagExe* pdiag = p_bloque->getDiagExe();

		pdiag->ComienzoEjecucionAuto(p_bloque,view);

   		pdiag->getVistas()->Actualizar();	
	}
	else
	{
		// Retroanotar en cascada a todos los bloques conectados.
		Retroanotar((CString)"",true);
	}
}

void CBloqueExe::Consola(CString& mensaje, int origen)
{
	mensaje = p_bloque->getEtiqueta() + ": " + mensaje; 

	CDiagExe* pdiag = p_bloque->getDiagExe();
	pdiag->Consola(mensaje, origen);
}

void CBloqueExe::Consola(const char* mensaje, int origen)
{
	Consola((CString&)CString(mensaje),origen); // El cast es extra�o pero necesario sino se llama recursivamente
}


BOOL CBloqueExe::Retroanotar(CString& EtiqConector, BOOL EnviarCascadaRetro)
{
    // Env�a al objeto de retroanotaci�n conectado a �ste por el conector argumento (si es "" el primero que encuentre).
    
	CString stemp;
	stemp = "Solicitando enviar retroanotaci�n a trav�s del conector de etiqueta: \"" + EtiqConector + "\"";
   	Consola(stemp);
   	
 	if (!ProcesarSalidaDeDatos(NULL, EtiqConector, true, EnviarCascadaRetro))
	{
 		CString stemp = "Fin de retroanotaci�n NO correcta por el conector de etiqueta: \"" + EtiqConector + "\"";
		Consola(stemp);
		p_bloque->getDiag()->getVistas()->Actualizar();
		return false;	
	}

 	stemp = "Fin de retroanotaci�n por el conector de etiqueta: \"" + EtiqConector + "\"";
	Consola(stemp);
	    
    p_bloque->getDiag()->getVistas()->Actualizar();
    return true;
}


BOOL CBloqueExe::RecibirRetroanotacion(CString& EtiqConector)
{
    POSITION pos = NULL;
	CString stemp;

   	stemp = "Solicitando datos de retroanotaci�n por el conector de etiqueta: \"" + EtiqConector + "\"";
	Consola(stemp);	    

	BOOL res = ProcesarEntradaDeDatos(NULL,EtiqConector, true);

  	if (res)
  	{
		stemp = "Datos de retroanotaci�n recibidos correctamente a trav�s del conector de etiqueta: \"" + EtiqConector + "\"";
		Consola(stemp);  	
  	}
	else
	{
		stemp = "Datos de retroanotaci�n NO recibidos correctamente a trav�s del conector de etiqueta: \"" + EtiqConector + "\"";
		Consola(stemp); 
	}

	p_bloque->getDiag()->getVistas()->Actualizar();	
	return res;
}


BOOL CBloqueExe::ProcesarEntradaDeDatos(CConect* con,CString& etiq, BOOL Retroanotar)
{
	// S�lo leeremos de un solo conector, el primero que encontremos

	// Si estamos en ejecuci�n autom�tica, el conector "con", si est� definido,
	// indica por qu� conector (funcional) se ha llegado a este bloque.
	// Por �l entonces habr� de recibirse la informaci�n en el caso de ser el bloque
	// activo en entrada. Esto resuelve la ambiguedad de un bloque con varios conectores de entrada
	// que es activo en entrada por lo memos en modo auto.

	CBloque* pBAnt;
	if (con)
	{
		// Es modo autom�tico, entonces elegimos el bloque anterior ejecutado
		// a trav�s del conector por el que ha llegado el flujo a este bloque
		pBAnt = con->getInicio()->getBloque();
	}
	else
	{
		// No estamos en modo auto o era el iniciador del flujo o lo que sea
		// Elegimos el primer conector que tengamos.
		POSITION posinut;
		
		pBAnt = p_bloque->getExe()->BuscaBloqueIni(etiq, posinut, con, Retroanotar); // Si es para recibir datos de un bloque de retro. se busca entre ellos.
		if (NULL == pBAnt)  // Si es nulo es que puede ser un bloque no conectado en entrada.
		{
			CString stemp;

			if (!Retroanotar) stemp = "No existe un bloque previo conectado por el conector especificado o no existe tal conector de etiqueta \"" + etiq + "\"";
			else stemp = "No existe bloque previo conectado en retroanotaci�n por el conector especificado o no existe tal conector de etiqueta \"" + etiq + "\"";

			Consola(stemp);
 			return true; // Es algo normal que no haya un bloque anterior 
		}
	}

	if (pBAnt != NULL) 
	{
		CString stemp = "Solicitando datos a: " + pBAnt->getEtiqueta();
		Consola(stemp);
		CComunicacion* pComS = pBAnt->getExe()->DevolverDatos(con);   // Devuelve el puntero a CCom del DLL. � OJO es !
		if (pComS == NULL) return false;  // Es incompleto etc. el bloque anterior. No se ha creado objeto.

		BOOL res = AceptarDatos( NULL, con, pComS );	  // Lo pasa al DLL como 
		
		if (!res) return false; // Fallo de comunicaci�n, los datos pueden no haber sido aceptados
	}
	
	return true;
}

            
BOOL CBloqueExe::ProcesarSalidaDeDatos(CBaseView* view, CString& etiq, BOOL Retroanotar, BOOL EnviarCascadaRetro)
{

	// Ahora procesamos los conectores del bloque en el propio diagrama

	POSITION pos;
    CConect* con;
	CBloque* pBPost;
	
	pBPost = p_bloque->getExe()->BuscaBloqueFin(etiq, pos, con, Retroanotar);    
	if (NULL == pBPost)  // Si es nulo es que puede ser un bloque no conectado en salida.
	{
		if (!p_bloque->EsMultiDiag())  // No hay ning�n bloque posterior posible
		{
			CString stemp;
			if (!Retroanotar) stemp = "No existe un bloque siguiente conectado por el conector especificado o no existe tal conector de etiqueta \"" + etiq + "\"";
			else stemp = "No existe bloque siguiente conectado en retroanotaci�n por el conector especificado o no existe tal conector de etiqueta \"" + etiq + "\"";
			
			Consola(stemp);
 			return true;  // Es normal que no haya m�s bloques, no es un fallo de comunicaci�n
		}	
	}


	// Si acept� los datos y es retroanotaci�n en cascada es posible que pBPost a su vez env�e datos

	// Antes de emitir en cascada hacemos un chequeo de si ha pasado antes por aqu�
	// en un proceso de retroanotaci�n en cascada
	// con el fin de evitar un bucle infinito. Si ya ha pasado por aqu�
	// paramos el proceso de retroanotaci�n antes de enviar datos al siguiente

	if (Retroanotar && EnviarCascadaRetro && m_haPasadoRetro)
	{
		// S�lo enviamos el mensaje por la consola y no por un di�logo
		// de mensaje pues no es un error grave, es m�s cuando se usan
		// bloques de retroanotaci�n puede ser inevitable y conveniente
		// pues un bloque funcional puede estar conectado para enviar y recibir 
		// a un bloque de retroanotaci�n, si env�a en cascada (lo normal) se produce un bucle infinito.
		
		CString mensaje = "Se ha detectado un bucle infinito de retroanotaci�n en cascada en el bloque: \"" + p_bloque->getEtiqueta() + "\", se parar� la retroanotaci�n";
		Consola(mensaje);

		return true;
	}

    // Iteramos por todos los bloques conectados al final, pasando la informaci�n por aquellos conectores salientes que contengan
    // como etiqueta el valor devuelto por el bloque "etiq" o bien si etiq == "" por todos los conectores indep. de su etiqueta.   
    // Se permite as� multicomunicaci�n con varios bloques conectados en la salida.

	while ( pBPost != NULL ) 
	{
		CComunicacion* pComS = DevolverDatos(con); // Devuelve el puntero al objeto de comunicaci�n del DLL. � OJO es !. Si es NULL no se ha creado el objeto.
		if (pComS == NULL)  return false;	// Es posible que el estado del bloque no sea CORRECTO

		BOOL res = pBPost->getExe()->AceptarDatos(view, con, pComS);

		if (!res) return false; // Se para el flujo al haber sido rechazado los datos

		if (res)  // Si acept� los datos y es retroanotaci�n en cascada es posible que pBPost a su vez env�e datos
		{
			if (Retroanotar && EnviarCascadaRetro)
			{
				m_haPasadoRetro = true;  // Se�alamos que ya ha pasado por aqu� en retroanotaci�n en cascada,si pasa de nuevo ser�a error.
				pBPost->getExe()->ProcesarSalidaDeDatos(view,etiq,true,true);  // Llamada recursiva
				m_haPasadoRetro = false;	// Puede pasar de nuevo
			}
		}

		// Genera un "pBPost" y un "con" nuevos
	    pBPost = p_bloque->getExe()->BuscaBloqueFinSgte(etiq, pos, con, Retroanotar); // Siguiente bloque.
	}	

	return true;
}
                     
CComunicacion* CBloqueExe::DevolverDatos(CConect* con)
{
	if (!EstadoValido()) return NULL;  // No se crea objeto de comunic.	
    return con->getInicio()->getExe()->DevolverDatos();
}


BOOL CBloqueExe::AceptarDatos(CBaseView* view, CConect* con, CComunicacion * pE)
{
	BOOL res = con->getFin()->getExe()->AceptarDatos(pE);  // Lo pasa al DLL como .

	CDiagExe* pdiag = p_bloque->getDiagExe();
	pdiag->p_bloqUltimo = p_bloque;   // Ultimo bloque que recibe datos (o �ltimo ejecutado).
	
	// Sean aceptados o rechazados los datos, el �ltimo bloque involucrado es este
	p_bloque->getVistas()->getExe()->CentrarBloque(view);   // La pantalla se centra en el bloque destino de la informaci�n.

	if (res)  
	{
		// El poner SetModifiedFlag aqu� es importante sobre todo en el caso de que la informaci�n llegue por un bloque de un diagrama padre en multidiagrama. El diagrama hijo puede quedar modificado sin ser ejecutado nig�n bloque.
		if (NUEVO == getEstadoInt())
		{
			CambiaEstado(INCOMPLETO);
		}	

		p_bloque->getDiag()->FlagModificado();	

		return true;
	}	
	else
	{
		EnError(RECHAZODATOS, p_bloque); 
		return false;
	}
} 

BOOL CBloqueExe::EstadoValido()
{
 	// S�lo comprueba la validez del estado para poder seguir la ejecuci�n etc.
	if (CORRECTO == getEstadoUsr()) return true;
	CString stemp = "El estado del bloque \"" + p_bloque->getEtiqueta() + "\" no es CORRECTO, los datos devueltos en dicho estado pueden no ser v�lidos.� Continuar ?";
	BOOL res = p_bloque->getDiag()->getVistas()->Confirm( stemp );
	if (res) stemp += ": SI";
	else stemp += ": NO";
	Consola( stemp );  // Tambi�n por la consola la respuesta
	return res;
}

CBloque* CBloqueExe::BuscaBloqueIni(CString& conetiq, POSITION& pos,CConect*& con, BOOL Retroanota)
{
	// Llamada s�lo en ejecuci�n del algoritmo
	// Iterar los conectores buscando el que apunta a "blq" en su
 	// puntero a bloque final y etiqueta "conetiq". Si "conetiq" es nula
	// entonces no considerar esta condici�n. Devuelve el puntero a
	// bloque del comienzo del conector.
	// La variable pos no es entrada de datos sino salida (por eso es referencia) tal que obtengamos la
	// posici�n del primer conector que se encontr� que cumple lo impuesto. 
	// CConect*& con es igualmente un valor de salida para devolver el conector que conecta con el bloque inicial encontrado.
	// por eso es un puntero referencia.
	    
	for ( pos = getBloque()->getPrimerConectEntradaPos(Retroanota); pos != NULL  ; )
	{
		con = getBloque()->getSigConectEntrada(pos,Retroanota);
		if ((conetiq == "") || ( con->getEtiqueta() == conetiq )) 
			return con->getFin()->getBloque();		
	}

	return NULL;	
}


CBloque* CBloqueExe::BuscaBloqueFin(CString& conetiq,POSITION& pos,CConect*& con, BOOL Retroanota)
{
	// Llamada s�lo en ejecuci�n del algoritmo
	// Iterar los conectores buscando el que apunta a "blq" en su
 	// puntero a bloque inicial y etiqueta "conetiq". Si "conetiq" es nula
	// entonces no considerar esta condici�n. Devuelve el puntero a
	// bloque del final del conector.
	// La variable pos no es entrada de datos sino salida (por eso es referencia) tal que obtengamos la
	// posici�n del primer conector que se encontr� que cumple lo impuesto. Es para usar despu�s
	// BuscaBloqueFinSgte .
	// Ver la explicaci�n de "CConect *& con" en BuscaBloqueIni .

	pos = getBloque()->getPrimerConectSalidaPos(Retroanota);
	return BuscaBloqueFinSgte(conetiq,pos,con,Retroanota);
}


CBloque* CBloqueExe::BuscaBloqueFinSgte(CString& conetiq,POSITION& pos,CConect*& con, BOOL Retroanota)
{
	// Llamada s�lo en ejecuci�n del algoritmo	
	// Iterar al conector siguiente a "pos" hasta el final (actualizando a la nueva
 	// posici�n) buscando el que apunta a "blq" en su puntero a bloque
 	// inicial (no considerar etiqueta). Si "conetiq" es nula
	// entonces no considerar esta condici�n.
	// Devuelve el puntero a bloque del final del conector.

    while (pos != NULL)
	{
        con = getBloque()->getSigConectSalida(pos,Retroanota);
		if (("" == conetiq) || ( con->getEtiqueta() == conetiq )) 
			return con->getFin()->getBloque();
	}

	return NULL;
}



