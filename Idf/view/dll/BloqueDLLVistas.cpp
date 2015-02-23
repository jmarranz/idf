// BloqueDLLVistas.cpp: implementation of the CBloqueDLLVistas class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "BloqueDLLVistas.h"

#include "PropiedadesBloqueDLL.h"

#include "..\BloqueVistas.h"
#include "exe\BloqueDLLVistasExe.h"
#include "des\BloqueDLLVistasDis.h"

#include "..\..\model\BloqueModo.h"
#include "..\..\model\dll\BloqueDLL.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBloqueDLLVistas::CBloqueDLLVistas()
{

}

CBloqueDLLVistas::~CBloqueDLLVistas()
{

}

void CBloqueDLLVistas::Construir(CComponenteDiag* comp)
{
	CBloqueVistas::Construir(comp);

	if (!comp->EsModoDiseno())
		p_modo = new CBloqueDLLVistasExe();
	else 
		p_modo = new CBloqueDLLVistasDis();

	p_modo->Construir(this);
}

BOOL CBloqueDLLVistas::Propiedades(UINT pagina /* = 0 */)
{
	CPropiedadesBloqueDLL dlgProp(getBloque(),pagina);

	BOOL res = (IDOK == dlgProp.DoModal());
	if (res) 
	{
		getBloque()->getModo()->ActualizaEstado();  
		Actualizar();	
	}

	return res;
}

