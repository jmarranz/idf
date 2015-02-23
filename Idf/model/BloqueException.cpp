// BloqueException.cpp: implementation of the BloqueException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\idf.h"
#include "BloqueException.h"

#include "Bloque.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BloqueException::BloqueException(CBloque* pbloque,const char* message)
: ComponenteDiagException(pbloque,message)
{
}

BloqueException::~BloqueException()
{

}

