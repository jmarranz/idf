// DiagramaVistas.cpp: implementation of the CDiagramaVistas class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "DiagramaVistas.h"

#include <direct.h> 

#include "BaseView.h"

#include "DibDiagrama.h"
#include "BloqueVistas.h"
#include "ConectVistas.h"

#include "PropiedadesDiagrama.h"
#include "dll\DlgPropiedadesClasesConDLL.h"
#include "dll\DlgPropiedadesClasesSinDLL.h"

#include "..\model\DiagBase.h"
#include "..\model\Bloque.h"
#include "..\model\Conect.h"

#include "..\Exception.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDiagramaVistas::CDiagramaVistas()
{
	p_diag = NULL;
	p_dibDiagrama = NULL;

	PonerVertical();
}

CDiagramaVistas::~CDiagramaVistas()
{
	delete p_dibDiagrama;
}

void CDiagramaVistas::Construir(CDiagBase* pdiag)
{
	p_diag = pdiag;

	p_dibDiagrama = CrearObjDibDiagrama();
	p_dibDiagrama->Construir(this);
}


CDibDiagrama* CDiagramaVistas::getDibDiagrama()
{
	return p_dibDiagrama;
}

void CDiagramaVistas::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_sizeDoc;
	}
	else
	{
		ar >> m_sizeDoc;
	}

	p_dibDiagrama->Serialize(ar);
}


void CDiagramaVistas::LeerDatosLDD(DOMElement* vistas)
{
	p_dibDiagrama->LeerDatosLDD(vistas);
}


void CDiagramaVistas::EscribirDatosLDD(DOMElement* vistas)
{
	p_dibDiagrama->EscribirDatosLDD(vistas);
}

void CDiagramaVistas::addView(CBaseView* view)
{
	m_views.AddTail(view);

	addView(&p_diag->m_listaBloq,view);
	addView(&p_diag->m_listaBloqRetro,view);
	addView(&p_diag->m_listaConect,view);
	addView(&p_diag->m_listaConectRetro,view);
}

void CDiagramaVistas::addView(ListaComponentes* plista,CBaseView* view)
{
	for ( POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CComponenteDiag* comp;
		CString id;
		plista->GetNextAssoc(pos,id,comp);
		comp->getVistas()->addView(view);			
	}
}

void CDiagramaVistas::removeView(CBaseView* view)
{
	POSITION pos = m_views.Find(view);
	m_views.RemoveAt(pos);

	removeView(&p_diag->m_listaBloq,view);
	removeView(&p_diag->m_listaBloqRetro,view);	
	removeView(&p_diag->m_listaConect,view);
	removeView(&p_diag->m_listaConectRetro,view);	
}

void CDiagramaVistas::removeView(ListaComponentes* plista,CBaseView* view)
{
	for ( POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CComponenteDiag* comp;
		CString id;
		plista->GetNextAssoc(pos,id,comp);
		comp->getVistas()->removeView(view);			
	}
}

void CDiagramaVistas::Actualizar()
{
	for(POSITION pos = m_views.GetHeadPosition(); pos != NULL; )
	{
		CBaseView* view = (CBaseView*)m_views.GetNext(pos);
		Actualizar(view);
	}
}

void CDiagramaVistas::Actualizar(ListaComponentes* plista,CBaseView* view)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CComponenteDiag* comp;
		CString id;
		plista->GetNextAssoc(pos,id,comp);
		comp->getVistas()->Actualizar(view);			
	}
}

void CDiagramaVistas::Actualizar(CBaseView* view)
{
	view->RedrawWindow();

	Actualizar(&p_diag->m_listaBloq,view);
	Actualizar(&p_diag->m_listaBloqRetro,view);	
	Actualizar(&p_diag->m_listaConect,view);
	Actualizar(&p_diag->m_listaConectRetro,view);
}

void CDiagramaVistas::ActualizarExcepto(CBaseView* view)
{
	for(POSITION pos = m_views.GetHeadPosition(); pos != NULL; )
	{
		CBaseView* viewCurr = (CBaseView*)m_views.GetNext(pos);
		if (viewCurr != view) Actualizar(view);
	}
}

BOOL CDiagramaVistas::Propiedades()
{
	CPropiedadesDiagrama dlgProp(p_diag);

	BOOL res = (IDOK == dlgProp.DoModal());
	if (res) Actualizar();	
	return res;
}

void CDiagramaVistas::AnalizarDll()
{
	CDlgPropiedadesClasesConDLL dlgPropDLL(p_diag);
	dlgPropDLL.DoModal();
}

void CDiagramaVistas::GenerarCodigoDiagrama()
{
	CDlgPropiedadesClasesSinDLL dlgPropClases(p_diag);
	dlgPropClases.DoModal();
}

BOOL CDiagramaVistas::getNuevoNombreDLL(CString& FileName)  // Lo usa también CBloque
{
	FileName = "*.dll";
	CString Tipo = "Módulo DLL (*.dll)";
	CString Ext = "dll";
    BOOL OK = false;
	while (!OK)  // Iterar hasta especificar un nombre válido.
	{		
		if (!getNuevoNombreFichero(true, FileName, Tipo, Ext)) return false;
		try
		{
			getDiag()->ChequearNombreValido(FileName);
			OK = true;
		}
		catch(Exception* ex)
		{
			Mensaje(ex);
			delete ex;
			// continuar
		}
	}

	return true;
}


BOOL CDiagramaVistas::getNuevoNombreFichero(BOOL Abrir, CString& FileName, CString Tipo /* ="" */, CString Ext /* ="" */)  // Lo usa también CBloque
{
	CString FileNameTmp = FileName; 
	if (FileNameTmp == "") FileNameTmp = "*." + Ext; // Para que salga la lista de los ficheros de esa extensión en el disco duro
	else
	{
		if (!Abrir) 
		{
			// Quitamos la extensión pues por defecto se añade al nombre que pongas
			int len = FileNameTmp.GetLength();
			if ((FileNameTmp[0] != '*') && (FileNameTmp[len - 4] == '.')) // Tiene extensión de 3 letras y no es un grupo (tipo *.ext)
			{
				FileNameTmp = FileNameTmp.Left(len- 4);  // Quitamos la extensión
			}
		}
	}

	CString szFilter;
	if (Tipo != "")
	{	
		szFilter = Tipo + " | *." + Ext + " | Todos los Ficheros (*.*) | *.* ||";
	}
	else
	{
		szFilter = "Todos los Ficheros (*.*) | *.* ||";
	}
	
	DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER | OFN_ENABLEHOOK;

	if (!getDiag()->m_dirTrabajo.IsEmpty()) _chdir( getDiag()->m_dirTrabajo );
	CFileDialog FileDiag(Abrir,(LPCSTR)Ext,(LPCSTR)FileNameTmp, dwFlags,(LPCSTR)szFilter, NULL );
	int a = FileDiag.DoModal();
	if (!getDiag()->m_dirTrabajo.IsEmpty()) _chdir( getDiag()->m_dirTrabajo );  // Para recuperar el directorio actual original.
    
	if (( a == IDCANCEL )||( a != IDOK )) return false;
    
	FileName = FileDiag.GetPathName();

	return true;
}


void CDiagramaVistas::Mensaje(const CString& men)
{
	CString stemp;
	if (getDiag()->m_nombreDiag != "")
	{
		stemp = getDiag()->m_nombreDiag + " : " + men;
	}
	else stemp = men;
	
	CGlobal::Mensaje(men);
}

void CDiagramaVistas::Mensaje(const char* men)
{
	Mensaje(CString(men));
}

void CDiagramaVistas::Mensaje(Exception* ex)
{
	CGlobal::Mensaje(ex->getMessage());
}

BOOL CDiagramaVistas::Confirm(const CString& men)
{
	return CGlobal::Confirm(men);
}

BOOL CDiagramaVistas::Confirm(const char* men)
{
	CString stemp(men);
	return Confirm(stemp);
}


CSize CDiagramaVistas::getDiagSize()
{
	// OJO, no cambiamos el tamaño del documento (m_sizeDoc), para imprimir en impresora bien en DIN A4.
	return m_sizeDoc;
} 

CSize CDiagramaVistas::getDiagSize(CBaseView* view)
{
	// OJO, no cambiamos el tamaño del documento (m_sizeDoc), para imprimir en impresora bien en DIN A4.
	return view->EscalaVisual(m_sizeDoc);
} 

void CDiagramaVistas::PonerVertical()
{
	// DIN A4 en dimensiones para MM_LOMETRIC, recordando que es 0.1 mm , tal que las dimensiones finales es multiplicar CSize por 0.1 = mm
	m_sizeDoc = CSize(DINA4_H * 10,DINA4_V * 10); // 2100,2970
}

void CDiagramaVistas::PonerHorizontal()
{
	m_sizeDoc = CSize(DINA4_V * 10,DINA4_H * 10);
}

BOOL CDiagramaVistas::EsPosHorizontal()
{
	if (m_sizeDoc.cx > m_sizeDoc.cy) return true;
	return false;
}

BOOL CDiagramaVistas::ValidarX_A4(int valor)
{
	int max_x = getDiagSize().cx / 10;

	if ((valor < 0)||(valor >= max_x))
	{
		return false;
	}
	return true;
}

BOOL CDiagramaVistas::ValidarY_A4(int valor)
{
	int max_y = getDiagSize().cy / 10;

	if ((valor < 0)||(valor >= max_y))
	{
		return false;
	}		
	return true;
}


BOOL CDiagramaVistas::ValidarXY_A4(const CPoint& p)
{
	if (!ValidarX_A4(p.x)) return false;
	if (!ValidarY_A4(p.y)) return false;
	return true;
}

BOOL CDiagramaVistas::ValidarRect_A4(const CRect& r)
{
	if (!ValidarXY_A4(r.TopLeft())) return false;
	if (!ValidarXY_A4(r.BottomRight())) return false;
	return true;
}


