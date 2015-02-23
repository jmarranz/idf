// CAnalisisClasesDLL.h: interface for the CAnalisisClasesDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAnalisisClasesDLL_H__577AC81B_BF8D_418F_BE85_3F9C9AD9C395__INCLUDED_)
#define AFX_CAnalisisClasesDLL_H__577AC81B_BF8D_418F_BE85_3F9C9AD9C395__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDiagBase;
class CInfoBloque;
class CInfoCom;
class CInfoComES;


class CAnalisisClasesDLL : public CObject  
{
public:
	CAnalisisClasesDLL(CDiagBase* pdiag);
	virtual ~CAnalisisClasesDLL();

	CDiagBase* getDiag() 
	{ 
		return p_diag; 
	}

	virtual void Construir() = 0;

	void DestruirListaBloques(CMapStringToPtr& lista);
	void DestruirListaCom(CMapStringToPtr& lista);

	virtual BOOL ConDLL() = 0; 

	virtual BOOL EsValido() { return true; }

	static BOOL EsClaseComPredefinida(const CString& claseCom);
	static BOOL EsClaseComNULO(const CString& claseCom);


	void ListarBloques( CComboBox* lista, int tipo );
	void ListarObjCom( CComboBox* lista );

	CInfoBloque* BuscarBloque(const CString& claseBloque);
	CInfoBloque* BuscarBloque(const CString& claseBloque, int tipo);
	CInfoCom* BuscarObjCom(const CString& claseCom);


	virtual POSITION  PrimerBloquePos(int tipo);
	virtual CInfoBloque*  SiguienteBloque(POSITION& pos,int tipo);

	virtual POSITION  PrimerComPos();
	virtual CInfoCom*  SiguienteCom(POSITION& pos);

	virtual POSITION  PrimerComESPos(CInfoBloque* pInfo,int tipo);
	virtual CInfoComES*  SiguienteComES(POSITION& pos,CInfoBloque* pInfo,int tipo);


// Variables
public:

	// Listas con las clases diferentes definidas en el diagrama en memoria
	CMapStringToPtr m_listaBloquesAmbos;
	CMapStringToPtr m_listaBloquesFunc;
	CMapStringToPtr m_listaBloquesRetro;
	CMapStringToPtr m_listaCom;

protected:
	CDiagBase* p_diag;
};

#endif // !defined(AFX_CAnalisisClasesDLL_H__577AC81B_BF8D_418F_BE85_3F9C9AD9C395__INCLUDED_)
