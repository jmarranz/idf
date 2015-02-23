// BloqueVistasModo.cpp: implementation of the CBloqueVistasModo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "BloqueVistasModo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueVistasModo::CBloqueVistasModo()
{
	p_vistas = NULL;
}

CBloqueVistasModo::~CBloqueVistasModo()
{
	
}

void CBloqueVistasModo::Construir(CBloqueVistas* pvistas)
{
	p_vistas = pvistas;
}

