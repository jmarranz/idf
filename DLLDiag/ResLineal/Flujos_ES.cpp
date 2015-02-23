//******************************************************************
//
//	Flujos_ES.cpp
//
//  Contiene las funciones de la clase Flujos_ES.
//	
//	fecha: 11/03/99
//
//  Modifications----->	
//	Date		By		Commets
//	
//******************************************************************
#include "stdafx.h"

#include "Flujos_ES.h"

/*
flujo::flujo (tipo_flujo tipo,int nivel_detalle, CString nombre_fichero) : 
	f_consola(stdout),
	dc_consola (&f_consola),
	dc_fichero (&mi_fichero)
{
	switch(tipo){
	case CONSOLA:
		{
			dc_consola.SetDepth(nivel_detalle);
		};
		break;
	case FICHERO:
		{
			if( !mi_fichero.Open( nombre_fichero , CFile::modeCreate | CFile::modeWrite ) ) {
			afxDump << "Unable to open file" << "\n";
			exit( 1 );
	}

			dc_fichero.SetDepth(nivel_detalle);};
		break;
	case DEBUGGER:
		{
			afxDump.SetDepth(nivel_detalle);
		};
	};
}

flujo::~flujo(void)
{
	// Aquí habría que cerrar la variable "mi_fichero", pero no es
	// necesario, puesto que al destruir la clase, la propia "CFile"
	// lo cierra. Además, como cabe la posibilidad de que hayamos
	// trabajado con otro tipo de flujos y que nunca hayamos abierto
	// un fichero, al intentar cerrarlo nos daría un error de memoria.
	// Por tanto, lo mejor es dejar que lo gestione la clase "CFile"
}
*/


flujo::flujo (int nivel_detalle, CString nombre_fichero): 
	f_consola (stdout),
	dc_consola (&f_consola),
	dc_fichero (&mi_fichero)
{

	if( !mi_fichero.Open( nombre_fichero , CFile::modeCreate | CFile::modeWrite ) ) 
	{
		afxDump << "Unable to open file" << "\n";
		exit( 1 );
	}

	set_nivel_detalle (nivel_detalle);
}

flujo::~flujo(void)
{
	mi_fichero.Close();
}

void flujo::set_nivel_detalle (int nivel_detalle)
{
	dc_consola.SetDepth(nivel_detalle);
	dc_fichero.SetDepth(nivel_detalle);
	afxDump.SetDepth(nivel_detalle);
}