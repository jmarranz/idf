// InfoClases.cpp: implementation of the InfoClases class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IdfDllApp.h"
#include "InfoClases.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInfoClaseComponenteDiag::CInfoClaseComponenteDiag(const char* nombreclase, const char* nombreclasebase, const char* verserial)
{
	NombreClase = nombreclase;
	NombreClaseBase = nombreclasebase;
	VerSerial = verserial;
}


CInfoBloque::CInfoBloque(const char* nombreclase, const char* nombreclasebase, const char* verserial, int tipo)
	: CInfoClaseComponenteDiag(nombreclase,nombreclasebase,verserial)
{
	Tipo = tipo; // 0 = ambos tipos, 1 = sólo funcional, 2 = sólo retroanotación

	CInfoDiagrama* pInfoDiag = CIdfDllApp::getInfoDiagrama();
	pInfoDiag->RegistrarBloque(this);
}

CInfoCom::CInfoCom(const char* nombreclase, const char* nombreclasebase, const char* verserial)
	: CInfoClaseComponenteDiag(nombreclase,nombreclasebase,verserial)
{
	CInfoDiagrama* pInfoDiag = CIdfDllApp::getInfoDiagrama();
	pInfoDiag->RegistrarCom(this);
}


CInfoComES::CInfoComES(const char* nombreclase, const char* nombreclasebloque, int tipo)
{
	Tipo = tipo; // 0 = entrada, 1 = salida
	NombreClase = nombreclase;
	NombreClaseBloque = nombreclasebloque;

	CInfoDiagrama* pInfoDiag = CIdfDllApp::getInfoDiagrama();
	pInfoDiag->RegistrarComES(this);
}


