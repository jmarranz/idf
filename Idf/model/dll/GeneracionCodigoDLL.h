// GeneracionCodigoDLL.h: interface for the CGeneracionCodigoDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENERACIONCODIGODLL_H__3B84158F_128F_42D8_B2B5_3FB5ED0E2CF2__INCLUDED_)
#define AFX_GENERACIONCODIGODLL_H__3B84158F_128F_42D8_B2B5_3FB5ED0E2CF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInfoBloque;
class CAnalisisClasesDLL;
class CInfoCom;
class CInfoComES;


class CGeneracionCodigoDLL : public CObject  
{
public:
	CGeneracionCodigoDLL(CAnalisisClasesDLL* pClasesDiag);
	virtual ~CGeneracionCodigoDLL();

	void GenerarCodigo();
	void GenerarCodigoListaBloques(int tipo);
	void GenerarCodigoListaObjetosCom();

	void GenerarCodigoBloque(CInfoBloque* pdatos);
	void GenerarCodigoObjCom(CInfoCom* pdatos);
	void GenerarCodigoObjComES(CInfoComES* pdatos);

protected:
	void GenerarCodigoBloqueCabecera(CInfoBloque* pdatos);
	void GenerarCodigoBloqueCuerpo(CInfoBloque* pdatos);

	void GenerarCodigoObjComCabecera(CInfoCom* pdatos);
	void GenerarCodigoObjComCuerpo(CInfoCom* pdatos);

	void GenerarCodigoListaObjetosComES(CInfoBloque* pdatos,int tipo);

public:
	CString	m_cabeceras;
	CString	m_implementacion;

protected:
	CAnalisisClasesDLL* p_clasesDiag;
};

#endif // !defined(AFX_GENERACIONCODIGODLL_H__3B84158F_128F_42D8_B2B5_3FB5ED0E2CF2__INCLUDED_)
