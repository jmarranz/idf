
// Conect_enlaces.cpp


#include "stdafx.h"
#include "..\..\..\Idf.h"
#include "ConectDLL_enlaces.h"

#include "..\..\Conect.h"
#include "..\..\..\view\ConectVistas.h"
                  

// EXPORTACIONES HACIA LOS DLL DE DIAGRAMAS Y BLOQUES PARA COMUNICACIÓN BIDIRECCIONAL


// Hacia el Conector

const char* ConectorDLL_GetNombreInterno(CConect* pCon)
{
	return pCon->getId();
}

const char* ConectorDLL_GetEtiqueta(CConect* pCon)
{
	return pCon->getEtiqueta();
}

BOOL ConectorDLL_EsRetroAnotador(CConect* pCon)
{
	return pCon->EsRetroanotador();
}	

void ConectorDLL_Mensaje(CConect* pCon, const char * mensaje)
{
	pCon->getVistas()->Mensaje(mensaje);
}

