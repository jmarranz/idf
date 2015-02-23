// Comunicacion.cpp: implementation of the CComunicacion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "Comunicacion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComunicacion::CComunicacion()
{

}

CComunicacion::CComunicacion(Instante t)
{
	m_Instante.set(t);
}


CComunicacion::~CComunicacion()
{

}
