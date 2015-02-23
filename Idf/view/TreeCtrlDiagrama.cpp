// TreeCtrlDiagrama.cpp: implementation of the CTreeCtrlDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "TreeCtrlDiagrama.h"

#include "ConectVistas.h"
#include "BloqueVistas.h"

#include "..\model\Conect.h"
#include "..\model\ConectInicio.h"
#include "..\model\ConectFin.h"

#include "..\model\Bloque.h"
#include "..\model\DiagBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTreeCtrlDiagrama::CTreeCtrlDiagrama()
{
	p_TreeCtrl = NULL;
}

CTreeCtrlDiagrama::~CTreeCtrlDiagrama()
{

}

void CTreeCtrlDiagrama::Construir(CTreeCtrl* treeCtrl)
{
	p_TreeCtrl = treeCtrl;

	m_ImgList.Create(20,20,ILC_COLOR | ILC_MASK,1,1);

	m_IconDiagrama = m_ImgList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_IconBloques = m_ImgList.Add(AfxGetApp()->LoadIcon(IDI_BLOQUES));
	m_IconConectores = m_ImgList.Add(AfxGetApp()->LoadIcon(IDI_CONECTORES));
	m_IconBloque = m_ImgList.Add(AfxGetApp()->LoadIcon(IDI_BLOQUE));
	m_IconConector = m_ImgList.Add(AfxGetApp()->LoadIcon(IDI_CONECTOR));

	p_TreeCtrl->SetImageList(&m_ImgList,TVSIL_NORMAL);
}

void CTreeCtrlDiagrama::InsertarDiagrama(CDiagBase* pDiag)
{
	// Diagrama funcional
	HTREEITEM itemDiagFunc = InsertarItem("Diagrama Funcional",0,m_IconDiagrama,TVI_ROOT);

	HTREEITEM itemDiagFuncBloques = InsertarItem("Bloques",0,m_IconBloques,itemDiagFunc);
	InsertarBloques(&pDiag->m_listaBloq,itemDiagFuncBloques);

	HTREEITEM itemDiagFuncConectores = InsertarItem("Conectores",0,m_IconConectores,itemDiagFunc);
	InsertarConectores(&pDiag->m_listaConect,itemDiagFuncConectores,true);

	// Diagrama retroanotacíón
	HTREEITEM itemDiagRetro = InsertarItem("Diagrama Retroanotador",0,m_IconDiagrama,TVI_ROOT);

	HTREEITEM itemDiagRetroBloques = InsertarItem("Bloques",0,m_IconBloques,itemDiagRetro);
	InsertarBloques(&pDiag->m_listaBloqRetro,itemDiagRetroBloques);

	HTREEITEM itemDiagRetroConectores = InsertarItem("Conectores",0,m_IconConectores,itemDiagRetro);
	InsertarConectores(&pDiag->m_listaConectRetro,itemDiagRetroConectores,true);
}

void CTreeCtrlDiagrama::InsertarBloques(ListaBloques* lista,HTREEITEM parent) 
{
	for (POSITION pos = lista->GetStartPosition( ); pos != NULL  ; )
	{
		CBloque* pBlq;
		CString id;
		lista->GetNextAssoc(pos,id,pBlq);
		InsertarBloque(pBlq,parent);
	}
}

void CTreeCtrlDiagrama::InsertarBloque(CBloque* pBlq,HTREEITEM parent) 
{
	HTREEITEM itemBloque = InsertarItem("[" + pBlq->getId() + "] " + pBlq->getEtiqueta(),(long)pBlq,m_IconBloque,parent);

	InsertarBloqueConectores(pBlq,itemBloque);
}

void CTreeCtrlDiagrama::InsertarBloqueConectores(CBloque* pBlq,HTREEITEM parent) 
{
	HTREEITEM itemConEntradaFunc = InsertarItem("Conectores Entrada Funcionales",0,m_IconConectores,parent);
	InsertarConectores(&pBlq->m_listaConectEntrada,itemConEntradaFunc,false);

	HTREEITEM itemConSalidaFunc = InsertarItem("Conectores Salida Funcionales",0,m_IconConectores,parent);
	InsertarConectores(&pBlq->m_listaConectSalida,itemConSalidaFunc,false);

	HTREEITEM itemConEntradaRetro = InsertarItem("Conectores Entrada Retroanotación",0,m_IconConectores,parent);
	InsertarConectores(&pBlq->m_listaConectEntradaRetro,itemConEntradaRetro,false);

	HTREEITEM itemConSalidaRetro = InsertarItem("Conectores Salida Retroanotación",0,m_IconConectores,parent);
	InsertarConectores(&pBlq->m_listaConectSalidaRetro,itemConSalidaRetro,false);
}


void CTreeCtrlDiagrama::InsertarConectores(ListaConectores* lista,HTREEITEM parent, BOOL mostrarBloques) 
{
	for (POSITION pos = lista->GetStartPosition( ); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		lista->GetNextAssoc( pos,id,con );
		HTREEITEM itemConect = InsertarItem("[" + con->getId() + "] " + con->getEtiqueta(),(long)con,m_IconConector,parent);
		if (mostrarBloques)
		{
			CConectExtremo* conIni = con->getInicio();
			if (conIni != NULL)
			{
				CBloque* pBlqIni = conIni->getBloque();
				InsertarBloque(pBlqIni,itemConect);
			}

			CConectExtremo* conFin = con->getFin();
			if (conFin != NULL)
			{
				CBloque* pBlqFin = conFin->getBloque();
				InsertarBloque(pBlqFin,itemConect);
			}
		}
	}
}

HTREEITEM CTreeCtrlDiagrama::InsertarItem(const CString& etiq,long lParam, int img, HTREEITEM parent)
{
	TVINSERTSTRUCT datosIns;
	datosIns.hParent = parent;
	datosIns.hInsertAfter = TVI_SORT;

	TVITEM datosItem;
	datosItem.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE; 
	datosItem.pszText = (LPTSTR)(LPCTSTR)etiq; 
	datosItem.lParam = (long)lParam;
	datosItem.iImage = img;
	datosItem.iSelectedImage = img;

	datosIns.item = datosItem;

	return p_TreeCtrl->InsertItem(&datosIns);
}

void CTreeCtrlDiagrama::Propiedades() 
{
	// TODO: Add your control notification handler code here
	HTREEITEM selected = p_TreeCtrl->GetSelectedItem( );

	CObject* pObj = (CObject*)p_TreeCtrl->GetItemData(selected);
	if (pObj != NULL)
	{
		CRuntimeClass* pRtc = pObj->GetRuntimeClass();
		if (pRtc->IsDerivedFrom(RUNTIME_CLASS( CBloque )))
		{
			CBloque* pBlq = (CBloque*)pObj;
			if (pBlq->getVistas()->Propiedades())
			{
				// Por si hubiera cambiado
				p_TreeCtrl->SetItemText(selected,"[" + pBlq->getId() + "] " + pBlq->getEtiqueta());
			}
		}
		else if (pRtc->IsDerivedFrom(RUNTIME_CLASS( CConect )))
		{
			CConect* pCon = (CConect*)pObj;
			if (pCon->getVistas()->Propiedades())
			{
				// Por si hubiera cambiado
				p_TreeCtrl->SetItemText(selected,"[" + pCon->getId() + "] " + pCon->getEtiqueta());
			}
		}
	}
}

void CTreeCtrlDiagrama::MenuPopUp() 
{
	HTREEITEM selected = p_TreeCtrl->GetSelectedItem( );

	CObject* pObj = (CObject*)p_TreeCtrl->GetItemData(selected);
	if (pObj == NULL) return;	
	
	CRect itemRect;
	p_TreeCtrl->GetItemRect(selected,&itemRect,true);

	CPoint point = itemRect.BottomRight();

	CMenu bar;
	if (bar.LoadMenu(IDR_MENU_COMPONENTE_PROP_POPUP))
	{
		CMenu& popup = *bar.GetSubMenu(0);
		ASSERT(popup.m_hMenu != NULL);

		p_TreeCtrl->ClientToScreen(&point);
		popup.TrackPopupMenu(TPM_RIGHTBUTTON,point.x, point.y, p_TreeCtrl->GetParent() );
	}	
}



