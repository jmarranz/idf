// BloqueModo.cpp: implementation of the CBloqueModo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "BloqueModo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CBloqueModo,CObject)

CBloqueModo::CBloqueModo()
{
	p_bloque = NULL;
}

CBloqueModo::~CBloqueModo()
{

}

void CBloqueModo::Construir(CBloque* pbloque)
{
	p_bloque = pbloque;
}

void CBloqueModo::Serialize(CArchive& ar)
{
	CObject::Serialize(ar); 
	
	if (ar.IsStoring())
	{
	}
	else
	{
	}	
} 
