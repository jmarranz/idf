// conect.cpp

#include "stdafx.h"
#include "..\..\Idf.h"
#include "ConectExe.h"

#include "..\Conect.h"
#include "DiagExe.h"

#include "ConectInicioExe.h"
#include "ConectFinExe.h"


#include "..\ConectInicio.h"
#include "..\ConectFin.h"


#include "..\..\view\exe\ConectVistasExe.h"


// Clase CConectExe


IMPLEMENT_SERIAL(CConectExe, CConectModo, 1)

CConectExe::CConectExe()
{
}

CConectExe::~CConectExe()
{
}

CComponenteDiagVistas* CConectExe::CrearObjVistas()
{
	return new CConectVistasExe();
}


// TestConexBloques: Testea si las conexiones entre bloques son compatibles en cuanto al objeto de
// de salida que genera el bloque anterior si es uno de los objetos que puede recibir el siguiente
// en cada conector. 
// Por último se encarga de conectar con la función de CBloqueFunc preparada para recibir el objeto
// de comunicación.

void CConectExe::IniciarExplicito()
{
	// Por ahora sólo esto.
	p_conect->setEstado( NOCIRCULA );
}

