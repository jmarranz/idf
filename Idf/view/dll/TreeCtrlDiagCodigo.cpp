// TreeCtrlDiagCodigo.cpp: implementation of the CTreeCtrlDiagCodigo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "TreeCtrlDiagCodigo.h"

#include "..\..\model\dll\AnalisisClasesConDLL.h"
#include "..\..\model\dll\AnalisisClasesSinDLL.h"
#include "..\..\model\dll\InfoClases.h"
#include "..\..\model\DiagBase.h"

#include "DlgGeneracionCodigoConDLL.h"
#include "DlgGeneracionCodigoSinDLL.h"
#include "..\DiagramaVistas.h"

#include "..\..\Exception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CTreeCtrlDiagCodigo::CTreeCtrlDiagCodigo()
{
	p_TreeCtrl = NULL;
	p_clasesDiag = NULL;
}

CTreeCtrlDiagCodigo::~CTreeCtrlDiagCodigo()
{

}

void CTreeCtrlDiagCodigo::Construir(CTreeCtrl* treeCtrl)
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

void CTreeCtrlDiagCodigo::InsertarDiagrama(CAnalisisClasesDLL* clasesDiag)
{
	p_clasesDiag = clasesDiag;
	
	// Bloques
	HTREEITEM itemDiagFuncRetroBloques = InsertarItem("Clases Bloques Funcionales/Retroanotación",0,m_IconBloques,TVI_ROOT);
	InsertarBloques(0,itemDiagFuncRetroBloques);

	HTREEITEM itemDiagFuncBloques = InsertarItem("Clases Bloques Funcionales",0,m_IconBloques,TVI_ROOT);
	InsertarBloques(1,itemDiagFuncBloques);

	HTREEITEM itemDiagRetroBloques = InsertarItem("Clases Bloques Retroanotación",0,m_IconBloques,TVI_ROOT);
	InsertarBloques(2,itemDiagRetroBloques);

	// Conectores
	HTREEITEM itemDiagConectores = InsertarItem("Clases Conectores",0,m_IconConectores,TVI_ROOT);
	InsertarConectores(itemDiagConectores);
}

void CTreeCtrlDiagCodigo::InsertarBloques(int tipo,HTREEITEM parent) 
{
	for (POSITION pos = p_clasesDiag->PrimerBloquePos( tipo ); pos != NULL  ; )
	{
		CInfoBloque* pDatos = p_clasesDiag->SiguienteBloque( pos, tipo );
		InsertarBloque(pDatos,parent);
	}
}

void CTreeCtrlDiagCodigo::InsertarBloque(CInfoBloque* pBloque,HTREEITEM parent) 
{
	HTREEITEM itemBloque = InsertarItem(pBloque->m_nombreClase,(long)pBloque,m_IconBloque,parent);

	InsertarBloqueConectores(pBloque,itemBloque);
}

void CTreeCtrlDiagCodigo::InsertarBloqueConectores(CInfoBloque* pBloque,HTREEITEM parent) 
{
	HTREEITEM itemConEntrada = InsertarItem("Clases Conectores Entrada",0,m_IconConectores,parent);
	InsertarConectES(&pBloque->m_listaComEntrada,itemConEntrada);

	HTREEITEM itemConSalida = InsertarItem("Clases Conectores Salida",0,m_IconConectores,parent);
	InsertarConectES(&pBloque->m_listaComSalida,itemConSalida);
}

void CTreeCtrlDiagCodigo::InsertarConectES(CMapStringToOb* pLista,HTREEITEM parent) 
{
	for (POSITION pos = pLista->GetStartPosition( ); pos != NULL  ; )
	{
		CInfoComES* pComES = NULL;
		CString claveinutil;
		pLista->GetNextAssoc(pos,claveinutil,(CObject*&)pComES);
		HTREEITEM itemConect = InsertarItem(pComES->m_nombreClase,(long)pComES,m_IconConector,parent);
	}
}


void CTreeCtrlDiagCodigo::InsertarConectores(HTREEITEM parent) 
{
	for (POSITION pos = p_clasesDiag->m_listaCom.GetStartPosition( ); pos != NULL  ; )
	{
		CInfoCom* pCom = NULL;
		CString claveinutil;
		p_clasesDiag->m_listaCom.GetNextAssoc(pos,claveinutil,(void*&)pCom);
		HTREEITEM itemConect = InsertarItem(pCom->m_nombreClase,(long)pCom,m_IconConector,parent);
	}
}



HTREEITEM CTreeCtrlDiagCodigo::InsertarItem(const CString& etiq,long lParam, int img, HTREEITEM parent)
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

void CTreeCtrlDiagCodigo::GenerarCodigo() 
{
	// TODO: Add your control notification handler code here
	HTREEITEM selected = p_TreeCtrl->GetSelectedItem( );

	CObject* pObj = (CObject*)p_TreeCtrl->GetItemData(selected);
	if (pObj != NULL)
	{
		CDlgGeneracionCodigoDLL* pdlg;

		CDiagBase* pDiag = p_clasesDiag->getDiag();

		if (p_clasesDiag->ConDLL())
		{
			CString dllDiag = ((CAnalisisClasesConDLL*)p_clasesDiag)->getDLLDiag();
			pdlg = new CDlgGeneracionCodigoConDLL(pDiag,dllDiag);
			
		}
		else
		{
			pdlg = new CDlgGeneracionCodigoSinDLL(pDiag);
		}

		CRuntimeClass* pRtc = pObj->GetRuntimeClass();
		if (pRtc->IsDerivedFrom(RUNTIME_CLASS( CInfoBloque )))
		{
			CInfoBloque* pBlq = (CInfoBloque*)pObj;

			try
			{
				pdlg->CDlgGeneracionCodigoDLL::AnalizarBloque(pBlq);
				pdlg->DoModal();
			}
			catch(Exception* ex)
			{
				pDiag->getVistas()->Mensaje(ex);		
				delete ex;
			}
		}
		else if (pRtc->IsDerivedFrom(RUNTIME_CLASS( CInfoCom )))
		{
			CInfoCom* pCom = (CInfoCom*)pObj;
			try
			{
				pdlg->CDlgGeneracionCodigoDLL::AnalizarObjCom(pCom);
				pdlg->DoModal();
			}
			catch(Exception* ex)
			{
				pDiag->getVistas()->Mensaje(ex);
				delete ex;
			}
		}
		else if (pRtc->IsDerivedFrom(RUNTIME_CLASS( CInfoComES )))
		{
			CInfoComES* pComES = (CInfoComES*)pObj;

			try
			{
				pdlg->AnalizarObjComES(pComES);
				pdlg->DoModal();
			}
			catch(Exception* ex)
			{
				pDiag->getVistas()->Mensaje(ex);
				delete ex;
			}
		}

		delete pdlg;
	}
}

void CTreeCtrlDiagCodigo::MenuPopUp() 
{
	HTREEITEM selected = p_TreeCtrl->GetSelectedItem( );

	CObject* pObj = (CObject*)p_TreeCtrl->GetItemData(selected);
	if (pObj == NULL) return;	
	
	CRect itemRect;
	p_TreeCtrl->GetItemRect(selected,&itemRect,true);

	CPoint point = itemRect.BottomRight();

	CMenu bar;
	if (bar.LoadMenu(IDR_MENU_CLASEDLL_POPUP))
	{
		CMenu& popup = *bar.GetSubMenu(0);
		ASSERT(popup.m_hMenu != NULL);

		p_TreeCtrl->ClientToScreen(&point);
		popup.TrackPopupMenu(TPM_RIGHTBUTTON,point.x, point.y, p_TreeCtrl->GetParent() );
	}	
}

