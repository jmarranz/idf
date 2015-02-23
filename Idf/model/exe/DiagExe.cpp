// DiagExe.cpp : implementation file
//

#include "stdafx.h" 
#include "..\..\Idf.h"
#include "DiagExe.h"

#include "DiagExeDoc.h"


#include "..\Bloque.h"
#include "..\exe\BloqueExe.h"
#include "..\Conect.h"
#include "..\exe\ConectExe.h"


#include "..\..\view\exe\DiagramaVistasExe.h"
#include "..\..\view\exe\DiagExeView.h"
#include "..\..\view\exe\DlgCancelAuto.h"
#include "..\..\view\BloqueVistas.h"
     


IMPLEMENT_SERIAL(CDiagExe, CObject, 1)   // CDiagBase es pura, no se pone.

CDiagExe::CDiagExe()
{
	p_bloqUltimo = NULL;

	m_modoAuto = false;
}

CDiagExe::~CDiagExe()
{
}


void CDiagExe::IniciarExplicito()
{
    // Se llama para inicializar los datos del diagrama sin haberlo destruirlo.
    // Llama en cadena a las funciones idem de los bloques del diagrama.
	IniciarBloquesExplicito();    
	IniciarConectoresExplicito();

	FlagModificado();  // El hecho de inicializar cambia lo que estuviera antes, previene de salvar accidentalmente.
}


void CDiagExe::Destruir()  // Es llamada por el destructor o por el documento. 
{
	CDiagBase::Destruir();

	getVistas()->DestruirLog();
}


void CDiagExe::CrearNuevo()
{
	CDiagBase::CrearNuevo();

	// Creamos pronto la consola para que los bloques al crearse puedan acceder a ella
	getVistas()->CrearLog();

	IniciarDatosBloques();   // Ojo, desde aquí el usuario ya puede llamar a funciones que actúan sobre el diagrama.

	POSITION pos = m_listaBloq.GetStartPosition(); 
	if (pos != NULL)
	{
		CString id;
		m_listaBloq.GetNextAssoc(pos,id,p_bloqUltimo);   // Para inicializarlo.	
	}
}                          


void CDiagExe::CrearDesdeFichero()         
{
	CDiagBase::CrearDesdeFichero();
}

CDiagramaVistas* CDiagExe::CrearObjDiagramaVistas()
{
	return new CDiagramaVistasExe();
}


void CDiagExe::Serialize(CArchive& ar)
{
	CDiagBase::Serialize(ar);

	if (ar.IsStoring())
	{
		CString ultimobloque;
        if (p_bloqUltimo) ultimobloque = p_bloqUltimo->getId();

		ar << ultimobloque; 
    }
    else
    {
		CString ultimobloque;
		ar >> ultimobloque;
		
		p_bloqUltimo = m_listaBloq.BuscaPorClave(ultimobloque); 		
		
        CrearDesdeFichero();
    } 
}

void CDiagExe::IniciarBloquesExplicito()
{
	Instante t; // Instante actual

	IniciarBloquesExplicito(&m_listaBloq,t);
	IniciarBloquesExplicito(&m_listaBloqRetro,t);
}

void CDiagExe::IniciarBloquesExplicito(ListaBloques* plista,const Instante& t)
{
	for( POSITION pos = plista->GetStartPosition() ; pos != NULL ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);
		blq->getExe()->IniciarExplicito(t);
	} 
}

void CDiagExe::IniciarConectoresExplicito()
{
	IniciarConectoresExplicito(&m_listaConect);
	IniciarConectoresExplicito(&m_listaConectRetro);

    // No iteramos por los de retroanotación pues no son bloque-diagrama.
    FlagModificado();  	// El hecho de inicializar cambia lo que estuviera antes, previene de salvar accidentalmente.

	getVistas()->Actualizar();
}

void CDiagExe::IniciarConectoresExplicito(ListaConectores* plista)
{
	for(POSITION pos = plista->GetStartPosition(); pos != NULL ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con);			
		con->getExe()->IniciarExplicito();
	} 
}


BOOL CDiagExe::IniciarDatosBloques()  // Una vez ya creados y enlazados inicializamos los bloques por las funciones del usuario. Sólo para diagrama nuevo.
{
	if (!IniciarDatosBloques(&m_listaBloq)) return false;
	if (!IniciarDatosBloques(&m_listaBloqRetro)) return false;
	return true;
}

BOOL CDiagExe::IniciarDatosBloques(ListaBloques* plista)
{
	for( POSITION pos = plista->GetStartPosition() ; pos != NULL ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);			
		if (!blq->getExe()->IniciarDatosBloque())  // Ha fallado la creación de los objetos dinámicos del usuario.
		{
			return false;		
		}
	} 

	return true;
}




CPoint CDiagExe::CambiaSigno(CPoint& pto)  const
{
	// Existe alguna operación que necesita que las dimensiones sean positivas.
	// Esta función cambia el signo a la dimensión "y" del elemento que está en dimensiones
	// lógicas para el sistema de MM_LOMETRIC. Después de usado, despreciar el resultado.
 	CPoint p(pto.x, - pto.y);
	return p;
}

CRect CDiagExe::CambiaSigno(CRect& rect)   const
{
	// Idem para un CRect
	CPoint p1, p2;
	p1 = CambiaSigno(rect.TopLeft());
	p2 = CambiaSigno(rect.BottomRight());
	CRect r(p1.x, p1.y, p2.x, p2.y);
	return r;
}

void CDiagExe::Consola(CString& mensaje, int origen)
{
	getVistas()->Consola(mensaje, origen);
}

void CDiagExe::AvisoCambioCarga()
{
	getVistas()->Mensaje("AVISO: Los efectos de este cambio sólo se manifestarán tras salvar y cargar de nuevo el diagrama");
}


void CDiagExe::ComienzoEjecucionAuto(CBloque* pBlqStart,CBaseView* view)
{
	m_modoAuto = true;

	pBlqStart->getExe()->m_inicioAuto = true;
	pBlqStart->getExe()->Consola((CString)"Entrada en modo AUTO");

	CDlgCancelAuto dlgcancel;
	dlgcancel.Crear(this);


	CBloque* pBlq = pBlqStart;

	CConect* con = NULL;

	while(pBlq != NULL)
	{
		CString etiq = pBlq->getExe()->Ejecutar(con,view);
   		getVistas()->Actualizar();	 	

		if (pBlq->getExe()->m_inicioAuto)  // Inició el modo Auto
		{
   			if (pBlq->m_salidaAuto != "")  // Es un bloque de decisión
			{			
	   			if (pBlq->m_salidaAuto == etiq)  // Verifica si es condición de salida
				{
					m_modoAuto = false;   // Finalizará el modo Auto poco después.
				}
			}
		}

		if (!m_modoAuto)   // Ojo, también puede haberse modificado desde un punto diferente ej. con el diálogo de cancelar modo auto.
		{
			pBlq->getExe()->Consola("Verificada condición de salida de modo AUTO. Saliendo ...");
			break;  // Abandonar modo Auto.
		}
    
		pBlq->getExe()->m_contAuto++;
		if ((pBlq->m_autoContMax >= 0) && (pBlq->getExe()->m_contAuto > pBlq->m_autoContMax))
		{ 
	  		// Diálogo de superado máximo número de iteraciones o pasos sobre el mismo bloque
			// Puede funcionar mal y puede ser que sea que el stack choca con el heap más que incompatibilidades en el manejo de cadenas.
			// Es preciso estudiar como solucionar esto.Una forma es minimizar al máximo el uso del stack.
			// Se ha preferido usar CString y new en vez de matrices de caracteres para usar al mínimo el stack.
			
			char si[10];
			sprintf(si,"%d",pBlq->m_autoContMax);
			CString s = "Superado el máximo de iteraciones ("+ CString(si) + ") en modo automático";
			pBlq->getVistas()->Mensaje(s);
			break;
		}

		POSITION pos = NULL;
        
		pBlq = pBlq->getExe()->BuscaBloqueFin(etiq, pos, con, false);    
	}

	m_modoAuto = false;

	// Iniciar el contador de iteraciones de los bloques
	for( POSITION pos = m_listaBloq.GetStartPosition( ); pos != NULL ; )
	{
		CString id; 
		m_listaBloq.GetNextAssoc( pos,id,pBlq );		
		pBlq->getExe()->m_contAuto = 0;
	}     	

	pBlqStart->getExe()->Consola("Salida de modo AUTO");
	pBlqStart->getExe()->m_inicioAuto = false;
}




