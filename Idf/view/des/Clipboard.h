// Clipboard.h: interface for the CClipboard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIPBOARD_H__C6C1A964_935B_4098_9A35_C22BA079E346__INCLUDED_)
#define AFX_CLIPBOARD_H__C6C1A964_935B_4098_9A35_C22BA079E346__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\model\ListaConectores.h"
#include "..\..\model\ListaBloques.h"

class CDiagBase;


class CClipboard : public CObject  
{
public:
	CClipboard(CDiagBase* pdiag,CWnd* pview);
	virtual ~CClipboard();

	static void registrar();

	static BOOL hayDatos(CWnd* view);

	static void copiar(BYTE* buff,DWORD len,CWnd* view);

	void CopiarSeleccion();
	void CopiarSeleccion(ListaBloques* plistaFrom,ListaBloques* plistaTarget);
	void CopiarSeleccion(ListaConectores* plistaFrom,ListaConectores* plistaTarget);

	void PegarSeleccion();  // Pega desde el portapapeles la selección de elementos en el diagrama
	void PegarSeleccion(ListaBloques* plistaFrom,ListaBloques* plistaTarget);
	void PegarSeleccion(ListaConectores* plistaFrom,ListaConectores* plistaTarget);

protected:	
	CDiagBase* p_diag;
	CWnd* p_view;

	ListaBloques m_copiadoListaBloq;  // Para manejo temporal de bloques copiados del portapapeles.
    ListaConectores m_copiadoListaConect;  // Idem conectores
	ListaBloques m_copiadoListaBloqRetro;  // Idem bloques retro.
    ListaConectores m_copiadoListaConectRetro;   // Idem conectores retro.

	static DWORD m_formatoClipbrd;  // Número de formato para el portapapeles de copia de bloques y conectores en diseño.
};

#endif // !defined(AFX_CLIPBOARD_H__C6C1A964_935B_4098_9A35_C22BA079E346__INCLUDED_)
