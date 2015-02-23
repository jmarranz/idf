// ConectVistasDis.cpp: implementation of the CConectVistasDis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "ConectVistasDis.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\Conect.h"
#include "..\..\model\des\ConectDis.h"


#include "DibConectDis.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConectVistasDis::CConectVistasDis()
{
}

CConectVistasDis::~CConectVistasDis()
{

}

CDibConect* CConectVistasDis::CrearObjDibConect()
{
	return new CDibConectDis();
}

