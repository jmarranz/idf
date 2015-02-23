// BloqueDiagVistas.h: interface for the CBloqueDiagVistas class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASDIAG_H__2F53CB61_9780_44B6_A83D_213C4D88A0DC__INCLUDED_)
#define AFX_BLOQUEVISTASDIAG_H__2F53CB61_9780_44B6_A83D_213C4D88A0DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\BloqueVistas.h"

class CBloqueDiag;
class CBloqueDiagVistasExe;
class CBloqueDiagVistasDis;

#define N_ESTADOS_VENTANA  4

#define S_MAXIMIZAR   "MAXIMIZAR"
#define S_ACTIVAR     "ACTIVAR"
#define S_NO_ACTIVAR  "NO ACTIVAR"
#define S_MINIMIZAR   "MINIMIZAR"

#define M_MAXIMIZAR   SW_MAXIMIZE
#define M_ACTIVAR     SW_SHOWNORMAL
#define M_NO_ACTIVAR  SW_SHOWNA
#define M_MINIMIZAR   SW_MINIMIZE


class CBloqueDiagVistas : public CBloqueVistas  
{
public:
	CBloqueDiagVistas();
	virtual ~CBloqueDiagVistas();
	virtual void Construir(CComponenteDiag* comp);
	virtual void Serialize(CArchive& ar);

	CBloqueDiag* getBloque()
	{
		return (CBloqueDiag*)p_comp;
	}

	CBloqueDiagVistasExe* getExe()
	{
		return (CBloqueDiagVistasExe*)p_modo;
	}

	CBloqueDiagVistasDis* getDis()
	{
		return (CBloqueDiagVistasDis*)p_modo;
	}

	virtual void LeerDatosLDD( DOMElement* vistas,DOMTreeWalker* walker );
	virtual void EscribirDatosLDD( DOMElement* vistas );

	virtual void setMostrarHijo(int mostrar);
	virtual int getMostrarHijo();
	virtual int listaMostrarHijo(int index,CString& texto);

	virtual BOOL Propiedades(UINT pagina = 0);

	static int getEstado(CMDIChildWnd* frame);

	CMDIChildWnd* getFrameSubDiagrama();
	CBaseView* getViewSubDiagrama();
	void ActivarFrameSubDiagrama(CMDIChildWnd* frame);

public:
    int m_mostrarHijo;  // Flag de como mostrar la ventana del hijo al ejecutarse el bloque.
};

#endif // !defined(AFX_BLOQUEVISTASDIAG_H__2F53CB61_9780_44B6_A83D_213C4D88A0DC__INCLUDED_)
