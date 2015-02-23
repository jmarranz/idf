// InfoDiagrama.h: interface for the CInfoDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFODIAGRAMA_H__ACE7E23F_C628_45B3_AD1F_5F9369854946__INCLUDED_)
#define AFX_INFODIAGRAMA_H__ACE7E23F_C628_45B3_AD1F_5F9369854946__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInfoDiagrama : public CObject  
{
public:
	CInfoDiagrama();
	virtual ~CInfoDiagrama();

	virtual void DestruirListaInfo(CMapStringToPtr& lista);
	virtual void RegistrarBloque(const char* nombreclase, const char* nombreclasebase, const char* verserial, int tipo);
	virtual void RegistrarBloque(CInfoBloque* pinfo);
	virtual void RegistrarCom(const char* nombreclase, const char* nombreclasebase, const char* verserial);
	virtual void RegistrarCom(CInfoCom* pinfo);
	virtual void RegistrarComES(const char* nombreclase, const char* nombreclasebloque, int tipo);
	virtual void RegistrarComES(CInfoComES* pinfo);

public:	
	CMapStringToPtr ListaBloquesFunc;
	CMapStringToPtr ListaBloquesRetro;
	CMapStringToPtr ListaBloquesAmbos;
	CMapStringToPtr ListaCom;
	CMapStringToPtr ListaComEntrada;
	CMapStringToPtr ListaComSalida;
};



#endif // !defined(AFX_INFODIAGRAMA_H__ACE7E23F_C628_45B3_AD1F_5F9369854946__INCLUDED_)
