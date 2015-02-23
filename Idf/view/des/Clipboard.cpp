// Clipboard.cpp: implementation of the CClipboard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "Clipboard.h"

#include "..\..\model\DiagBase.h"
#include "..\..\model\BaseDoc.h"
#include "..\..\model\Bloque.h"
#include "..\..\model\Conect.h"
#include "..\..\model\ConectInicio.h"
#include "..\..\model\ConectFin.h"


#include "..\BloqueVistas.h"
#include "..\DiagramaVistas.h"

#include "..\des\ConectVistasDis.h"
#include "DibBloqueDis.h"
#include "DibConectDis.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DWORD CClipboard::m_formatoClipbrd = 0;


CClipboard::CClipboard(CDiagBase* pdiag,CWnd* pview)
{
	p_diag = pdiag;
	p_view = pview;
}

CClipboard::~CClipboard()
{

}

void CClipboard::registrar()
{
	// Registramos el formato para copia de bloques y conect. al portapapeles en diseño.
	m_formatoClipbrd = RegisterClipboardFormat("IDFDiagSeleccion"); 
}

BOOL CClipboard::hayDatos(CWnd* view)
{
   	view->OpenClipboard();
	HGLOBAL clipbrd = GetClipboardData(m_formatoClipbrd);
	CloseClipboard();
	return (NULL != clipbrd);
}

void CClipboard::copiar(BYTE* buff,DWORD len,CWnd* view)
{
	HGLOBAL clipbrd;
	clipbrd = GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE | GMEM_DISCARDABLE , len); 
	char * lpBufferclipbrd;
	lpBufferclipbrd = (char *)GlobalLock(clipbrd);

	memcpy( lpBufferclipbrd, buff, len );
	
	GlobalUnlock(clipbrd);

   	view->OpenClipboard();
	EmptyClipboard();
	SetClipboardData( m_formatoClipbrd , clipbrd); 
	// Parece ser que el handle y la memoria los maneja el clipboard tras SetClipboardData, nos despreocupamos del valor de clipbrd desde ahora. Si la líberáramos o modificáramos el objeto podríamos provocar un error.
	CloseClipboard();
}


void CClipboard::CopiarSeleccion()
{
	// Tras copiar al portapapeles anulamos la selección para que
	// al pegar quede seleccionado el nuevo pero no el original
	// y así podemos moverlo de sitio

	// Conectores funcionales
	CopiarSeleccion(&p_diag->m_listaConect,&m_copiadoListaConect);

	// Bloques funcionales
	CopiarSeleccion(&p_diag->m_listaBloq,&m_copiadoListaBloq);

	// Conectores de Retroanotación:
	CopiarSeleccion(&p_diag->m_listaConectRetro,&m_copiadoListaConectRetro);

	// Bloques de retroanotación
	CopiarSeleccion(&p_diag->m_listaBloqRetro,&m_copiadoListaBloqRetro);

	CMemFile f_out;
	CArchive ar_output( &f_out, CArchive::store );

	m_copiadoListaBloq.Serialize(ar_output);
    m_copiadoListaConect.Serialize(ar_output);
	m_copiadoListaBloqRetro.Serialize(ar_output);
    m_copiadoListaConectRetro.Serialize(ar_output);

	ar_output.Close();

	ULONGLONG len = f_out.GetLength();
	BYTE* buff = f_out.Detach();

	copiar(buff,len,p_view);

	// Inicializamos las listas para nuevas copias.
	m_copiadoListaBloq.RemoveAll();
    m_copiadoListaConect.RemoveAll();
	m_copiadoListaBloqRetro.RemoveAll();
    m_copiadoListaConectRetro.RemoveAll();

	p_diag->getVistas()->Actualizar();
}


void CClipboard::CopiarSeleccion(ListaBloques* plistaFrom,ListaBloques* plistaTarget)
{
	for (POSITION pos = plistaFrom->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plistaFrom->GetNextAssoc(pos,id,blq);

		CDibBloqueDis* pDibBloque = blq->getVistas()->getDibBloqueDis();
		if (pDibBloque->EsSeleccionado())
		{
			plistaTarget->SetAt(id,blq);
			pDibBloque->Seleccionar(false);
		}
	}
}

void CClipboard::CopiarSeleccion(ListaConectores* plistaFrom,ListaConectores* plistaTarget)
{
	for (POSITION pos = plistaFrom->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plistaFrom->GetNextAssoc(pos,id,con);
		CDibConectDis* pDibCon = con->getVistas()->getDibConect()->getDis();

		if (pDibCon->EsSeleccionado()) 
		{
			plistaTarget->SetAt(id,con);

			pDibCon->Seleccionar(false);
		}
	}
}


void CClipboard::PegarSeleccion()
{
   	p_view->OpenClipboard();
	HGLOBAL clipbrd = GetClipboardData(m_formatoClipbrd);
	if (NULL == clipbrd)
	{
		CloseClipboard();
		return;  // No hay información de nuestro tipo
	}

	DWORD len = GlobalSize(clipbrd);
	BYTE* buff = (BYTE*)GlobalLock(clipbrd);

	CMemFile f_in(buff,len);
	CArchive ar_input( &f_in, CArchive::load );

	ar_input.m_pDocument = p_diag->getDoc();

	m_copiadoListaBloq.Serialize(ar_input);
    m_copiadoListaConect.Serialize(ar_input);
	m_copiadoListaBloqRetro.Serialize(ar_input);
    m_copiadoListaConectRetro.Serialize(ar_input);

	ar_input.Close();
	f_in.Detach();

	GlobalUnlock(clipbrd);	
	CloseClipboard();
	
	// Es necesario que primero se procesen los conectores y después los bloques
	// pues las claves de los conectores y enlaces con bloques se han de actualizar a nuevos
	// nombres antes de que se inserten los nuevos bloques

	// Bloques funcionales
	PegarSeleccion(&m_copiadoListaBloq,&p_diag->m_listaBloq);

	// Bloques de retroanotación
	PegarSeleccion(&m_copiadoListaBloqRetro,&p_diag->m_listaBloqRetro);

	// Conectores funcionales
	PegarSeleccion(&m_copiadoListaConect,&p_diag->m_listaConect);

	// Conectores de Retroanotación:
	PegarSeleccion(&m_copiadoListaConectRetro,&p_diag->m_listaConect);

	// Reconectar el conjunto (definir punteros, y listas de relación). 
	p_diag->FlagModificado();

	
	// Inicializamos las listas para nuevas copias.
	m_copiadoListaBloq.RemoveAll();
    m_copiadoListaConect.RemoveAll();
	m_copiadoListaBloqRetro.RemoveAll();
    m_copiadoListaConectRetro.RemoveAll();

}

void CClipboard::PegarSeleccion(ListaBloques* plistaFrom,ListaBloques* plistaTarget)
{
	for (POSITION pos = plistaFrom->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plistaFrom->GetNextAssoc(pos,id,blq);

		// Antes de insertar
		CString idOriginal = id;
		if (p_diag->ExisteClave(id)) 
		{
			id = p_diag->getClaveNueva(idOriginal);
			blq->m_id = id;
		}
		plistaTarget->SetAt(id,blq);

		CDibBloqueDis* pDibBloque = blq->getVistas()->getDibBloqueDis();

		pDibBloque->m_seleccionado = true;
		pDibBloque->m_rect.OffsetRect(5,5);

		blq->getVistas()->CrearNuevo();
	}
}

void CClipboard::PegarSeleccion(ListaConectores* plistaFrom,ListaConectores* plistaTarget)
{
	for (POSITION pos = plistaFrom->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plistaFrom->GetNextAssoc(pos,id,con);

		CString idOriginal = id;
		if (p_diag->ExisteClave(idOriginal)) 
		{
			id = p_diag->getClaveNueva(idOriginal);
			con->m_id = id;
		}
		plistaTarget->SetAt(id,con);

		CDibConectDis* pDibCon = con->getVistas()->getDibConect()->getDis();

		pDibCon->Seleccionar();
		pDibCon->OffsetConector(5,5);

		con->getVistas()->CrearNuevo();
	}
}


