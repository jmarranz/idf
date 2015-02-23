// InfoClases.h: interface for the CInfoClases class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFOCLASES_H__C38706B7_D1CF_4DAA_A6D3_19FCABBBDEF7__INCLUDED_)
#define AFX_INFOCLASES_H__C38706B7_D1CF_4DAA_A6D3_19FCABBBDEF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CInfoComponenteDiag : public CObject 
{
};

class CInfoClaseComponenteDiag : public CInfoComponenteDiag 
{
public:
	CInfoClaseComponenteDiag(const char* nombreclase, const char* nombreclasebase, const char* verserial);
	virtual ~CInfoClaseComponenteDiag();

public:
	CString m_nombreClase;
	CString m_nombreClaseBase;
	CString m_verSerial;
};


class CInfoBloque : public CInfoClaseComponenteDiag
{
	DECLARE_DYNAMIC(CInfoBloque)

public:
	CInfoBloque(const char* nombreclase, const char* nombreclasebase, const char* verserial, int tipo);
	virtual ~CInfoBloque();
	void DestruirListaComES(CMapStringToOb& lista);

	int getTipo() { return m_tipo; }

public: 
	CMapStringToOb m_listaComEntrada;
	CMapStringToOb m_listaComSalida;

protected:
	int m_tipo; // 0 = ambos tipos, 1 = sólo funcional, 2 = sólo retroanotación
};


class CInfoCom : public CInfoClaseComponenteDiag
{
	DECLARE_DYNAMIC(CInfoCom)

public:
	CInfoCom(const char* nombreclase, const char* nombreclasebase,const char* verserial);
};


class CInfoComES : public CInfoComponenteDiag
{
	DECLARE_DYNAMIC(CInfoComES)

public:
	CInfoComES(const char* nombreclase, const char* nombreclasebloque, int tipo);

	int getTipo() { return m_tipo; }

public:
	int m_tipo; // 0 = entrada, 1 = salida
	CString m_nombreClase;
	CString m_nombreClaseBloque;
};


#endif // !defined(AFX_INFOCLASES_H__C38706B7_D1CF_4DAA_A6D3_19FCABBBDEF7__INCLUDED_)
