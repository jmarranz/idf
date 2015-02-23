// TreeCtrlDiagCodigo.h: interface for the CTreeCtrlDiagCodigo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREECTRLDIAGCODIGO_H__66335558_C7EA_4639_9534_9487D5CB4DDB__INCLUDED_)
#define AFX_TREECTRLDIAGCODIGO_H__66335558_C7EA_4639_9534_9487D5CB4DDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDiagBase;

class CAnalisisClasesDLL;
class CInfoBloque;


class CTreeCtrlDiagCodigo : public CObject  
{
public:
	CTreeCtrlDiagCodigo();
	virtual ~CTreeCtrlDiagCodigo();

	void Construir(CTreeCtrl* treeCtrl);

	void InsertarDiagrama(CAnalisisClasesDLL* clasesDiag);
	void InsertarBloques(int tipo,HTREEITEM parent);
	void InsertarBloque(CInfoBloque* pBloque,HTREEITEM parent);
	void InsertarBloqueConectores(CInfoBloque* pBloque,HTREEITEM parent);

	void InsertarConectores(HTREEITEM parent);
	void InsertarConectES(CMapStringToOb* pLista,HTREEITEM parent);


	HTREEITEM InsertarItem(const CString& etiq,long lParam,int img,HTREEITEM parent);

	void GenerarCodigo();
	void MenuPopUp();

protected:
	CTreeCtrl* p_TreeCtrl;

	CAnalisisClasesDLL* p_clasesDiag;

	CImageList m_ImgList;

	int m_IconDiagrama;
	int m_IconBloques;
	int m_IconConectores;
	int m_IconBloque;
	int m_IconConector;
};


#endif // !defined(AFX_TREECTRLDIAGCODIGO_H__66335558_C7EA_4639_9534_9487D5CB4DDB__INCLUDED_)
