// TreeCtrlDiagrama.h: interface for the CTreeCtrlDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREECTRLDIAGRAMA_H__B417728E_D214_4EA7_ABAA_9008D71A8EFF__INCLUDED_)
#define AFX_TREECTRLDIAGRAMA_H__B417728E_D214_4EA7_ABAA_9008D71A8EFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDiagBase;
class ListaBloques;
class ListaConectores;
class CBloque;


class CTreeCtrlDiagrama : public CObject  
{
public:
	CTreeCtrlDiagrama();
	virtual ~CTreeCtrlDiagrama();

	void Construir(CTreeCtrl* treeCtrl);

	void InsertarDiagrama(CDiagBase* pDiag);
	void InsertarBloques(ListaBloques* lista,HTREEITEM parent);
	void InsertarBloque(CBloque* pBlq,HTREEITEM parent);
	void InsertarBloqueConectores(CBloque* pBlq,HTREEITEM parent);

	void InsertarConectores(ListaConectores* lista,HTREEITEM parent,BOOL mostrarBloques);

	HTREEITEM InsertarItem(const CString& etiq,long lParam,int img,HTREEITEM parent);

	void MenuPopUp();
	void Propiedades();

protected:
	CTreeCtrl* p_TreeCtrl;

	CImageList m_ImgList;

	int m_IconDiagrama;
	int m_IconBloques;
	int m_IconConectores;
	int m_IconBloque;
	int m_IconConector;
};

#endif // !defined(AFX_TREECTRLDIAGRAMA_H__B417728E_D214_4EA7_ABAA_9008D71A8EFF__INCLUDED_)
