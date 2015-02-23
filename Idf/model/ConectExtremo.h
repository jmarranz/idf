// ConectExtremo.h: interface for the CConectExtremo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTEXTREMO_H__5978BE52_B8D7_4052_B9D7_CED279817AA4__INCLUDED_)
#define AFX_CONECTEXTREMO_H__5978BE52_B8D7_4052_B9D7_CED279817AA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBloque;
class CBloqueUnidad;
class CConect;
class CConectExtremoModo;
class CConectExtremoExe;
class CConectExtremoDis;
enum OrdenBloqueDiag;

typedef enum
 	{ CON_INICIO, CON_FIN } ExtremoConector;


class CConectExtremo : public CObject  
{
public:
	CConectExtremo();
	virtual ~CConectExtremo();
	virtual void Construir(CConect* con,CBloque* pblq);
	virtual void Destruir();

	static CConectExtremo* crear(ExtremoConector extremo, const CString& idBloque, CConect* pcon);
	static CConectExtremo* crear(ExtremoConector extremo, CBloque* pblq, CConect* pcon);

	static CBloque* buscarBloque(ExtremoConector extremo, const CString& idBloque,CConect* pcon);

	static CBloqueUnidad* getBloqueUnidad(CBloque* pbloque,OrdenBloqueDiag tipo);


	CConect* getConect()
	{
		return p_conect;
	}

	CConectExtremoExe* getExe()
	{
		return (CConectExtremoExe*)p_modo;
	}

	CConectExtremoDis* getDis()
	{
		return (CConectExtremoDis*)p_modo;
	}

	virtual BOOL EsInicio() { return false; }
	virtual BOOL EsFin() { return false; }

	virtual void Serialize(CArchive& ar);

	virtual CBloque* getBloque();
	virtual void setBloque(CBloque* bloq) = 0;
	virtual CString getClaveBloque();

protected:
	CBloque* p_bloque;
	CConect* p_conect;
	CConectExtremoModo* p_modo;

public:
	//CString m_claseDatosComunic;
};

#endif // !defined(AFX_CONECTEXTREMO_H__5978BE52_B8D7_4052_B9D7_CED279817AA4__INCLUDED_)
