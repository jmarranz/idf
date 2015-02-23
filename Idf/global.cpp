// global.cpp

// Implementación de funciones globlales de utilidad.

#include "stdafx.h"
#include "Idf.h"
#include "global.h"

#include "view\MensajeLargo.h"



BOOL EsValidaVentana(CWnd* pwin)
{
    if (NULL != pwin->GetSafeHwnd())
    {
		// En ocasiones no funciona bien GetSafeHwnd en caso de fallo
		LONG hres = GetWindowLong(pwin->GetSafeHwnd(),GWL_HWNDPARENT);
		if (hres) return true;
	}
	return false;
}


HINSTANCE CGlobal::m_DLLhinstance = NULL;  // Instancia de Idf.dll

CBloqueDiag*	CGlobal::p_bloqPadre = NULL;
BOOL CGlobal::m_nuevoDesdeDiseno = false;
CString CGlobal::m_fichero;
BOOL CGlobal::m_esLDD = true;
CMultiDocTemplate* CGlobal::p_docTemplateExe = NULL;
CMultiDocTemplate* CGlobal::p_docTemplateDis = NULL;


void CGlobal::setDLLInfo(HINSTANCE hins)
{
	m_DLLhinstance = hins;
}


CDocument* CGlobal::NuevoDiagSinPrompt(BOOL diseno)
{
	if (!diseno) return p_docTemplateExe->OpenDocumentFile(NULL);
	else return p_docTemplateDis->OpenDocumentFile(NULL);  // No usamos OnFileNew() pues como hay varias plantillas sale un diálogo pidiendo elegir una y no nos interesa
}


CDocument*  CGlobal::AbrirDiagSinPrompt(LPCSTR lpszFileName,BOOL diseno)  
{
	if (!diseno) return p_docTemplateExe->OpenDocumentFile( lpszFileName );
	else return p_docTemplateDis->OpenDocumentFile( lpszFileName );
}

void CGlobal::Mensaje(const char * men)
{
	Mensaje(CString(men));
}

void CGlobal::Mensaje(const CString& men)
{
	// Determinamos que tipo de diálogo mostrar para que el texto
	// pueda caber y no tenga limitaciones o que simplemente quede mejor si es largo
	BOOL es_corto = true;
	int longitud = men.GetLength();
	if ( longitud < 200)
	{	
		es_corto = true; // Es mensaje corto (por ahora)
		// Aunque sea pequeño en longitud si tiene más de 4 líneas ( más de 3 CR/LF ) no nos vale 
		int cont = 0;
		for  (int pos = 0 ; pos < longitud; pos++ )
		{
			if (men[pos] == '\n') cont++;  // Contador de fines de línea
			if (cont >= 4) break; // No hace falta seguir
		}
		if (cont >= 4) es_corto = false; // Es mensaje largo
	}
	else es_corto = false; // Es mensaje largo
	
	if (es_corto)
	{	
		CMDIFrameWnd* pmainfrm = (CMDIFrameWnd*)AfxGetMainWnd();
		if (pmainfrm != NULL) pmainfrm->MessageBox(men,"Mensaje:",MB_OK|MB_ICONWARNING);
		else AfxMessageBox(men, MB_OK|MB_ICONWARNING);
	}
	else
	{
		CMensajeLargo msg;
		msg.Mensaje(men);
		msg.DoModal();		
	}
}

BOOL CGlobal::Confirm(const CString& men)
{
	int res;
	CMDIFrameWnd* pmainfrm = (CMDIFrameWnd*)AfxGetMainWnd();
	if (pmainfrm != NULL) res = pmainfrm->MessageBox(men,"Confirmar:",MB_YESNO|MB_ICONQUESTION);
	else res = AfxMessageBox(men, MB_YESNO|MB_ICONQUESTION);

	if (res == IDYES)  return true;
	else return false;
}


