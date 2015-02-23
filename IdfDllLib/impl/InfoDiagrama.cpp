// InfoDiagrama.cpp: implementation of the CInfoDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IdfDllApp.h"
#include "InfoDiagrama.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CInfoDiagrama::CInfoDiagrama()
{

}

CInfoDiagrama::~CInfoDiagrama()
{
	DestruirListaInfo(ListaBloquesFunc);
	DestruirListaInfo(ListaBloquesRetro);
	DestruirListaInfo(ListaBloquesAmbos);
	DestruirListaInfo(ListaCom);
	DestruirListaInfo(ListaComEntrada);
	DestruirListaInfo(ListaComSalida);
}

void CInfoDiagrama::RegistrarBloque(const char* nombreclase, const char* nombreclasebase, const char* verserial, int tipo)
{
	CInfoBloque* pinfo = new CInfoBloque(nombreclase,nombreclasebase,verserial,tipo);
	RegistrarBloque(pinfo);
}

void CInfoDiagrama::RegistrarBloque(CInfoBloque* pinfo)
{
	int tipo = pinfo->getTipo();
	CString clave = pinfo->NombreClase;
	switch(tipo)
	{
	case 0: 
		ListaBloquesAmbos.SetAt(clave , pinfo );
		break;
	case 1:
		ListaBloquesFunc.SetAt( clave, pinfo );
		break;
	case 2:
		ListaBloquesRetro.SetAt( clave, pinfo );
		break;
	}
}


void CInfoDiagrama::RegistrarCom(const char* nombreclase, const char* nombreclasebase, const char* verserial)
{
	CInfoCom* pinfo = new CInfoCom(nombreclase,nombreclasebase,verserial);
	RegistrarCom(pinfo);
}

void CInfoDiagrama::RegistrarCom(CInfoCom* pinfo)
{
	ListaCom.SetAt( pinfo->NombreClase, pinfo );
}

void CInfoDiagrama::RegistrarComES(const char* nombreclase, const char* nombreclasebloque, int tipo)
{
	CInfoComES* pinfo = new CInfoComES(nombreclase,nombreclasebloque,tipo);
	RegistrarComES(pinfo);
}

void CInfoDiagrama::RegistrarComES(CInfoComES* pinfo)
{
	CString clave = pinfo->NombreClaseBloque + "_" + pinfo->NombreClase;
	int tipo = pinfo->getTipo();
	switch(tipo)
	{
	case 0: // Entrada
		ListaComEntrada.SetAt( clave, pinfo );
		break;
	case 1: // Salida
		ListaComSalida.SetAt( clave, pinfo );
		break;
	}
}

void CInfoDiagrama::DestruirListaInfo(CMapStringToPtr& lista)
{
	for (POSITION pos = lista.GetStartPosition(); pos != NULL  ; )
	{
		CInfoComponenteDiag* pcmp;
		CString claveInutil;
		lista.GetNextAssoc(pos,claveInutil,(void*&)pcmp);
		// delete pcmp;
	}

	lista.RemoveAll();
}
