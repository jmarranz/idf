// DlgGeneracionCodigo.cpp: implementation of the CDlgGeneracionCodigoDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgGeneracionCodigoDLL.h"

#include "..\DiagramaVistas.h"

#include "..\..\model\DiagBase.h"

#include "..\..\model\dll\GeneracionCodigoDLL.h"

#include "..\..\model\dll\AnalisisClasesDLL.h"

#include "..\..\model\dll\InfoClases.h"

#include "..\..\Exception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDlgGeneracionCodigoDLL::CDlgGeneracionCodigoDLL(CDiagBase* pdiag,UINT nIDTemplate, CWnd* pParentWnd)
	: CDialog(nIDTemplate, pParentWnd)
{
	p_diag = pdiag;

	p_Analizador = NULL;
}

CDlgGeneracionCodigoDLL::~CDlgGeneracionCodigoDLL()
{

}

void CDlgGeneracionCodigoDLL::Analizar()
{
	CWaitCursor cursor_espera;

	CGeneracionCodigoDLL codigo(p_Analizador);
	codigo.GenerarCodigo();	

	SetCabeceras(codigo.m_cabeceras);
	SetImplementacion(codigo.m_implementacion);
}

void CDlgGeneracionCodigoDLL::AnalizarBloque(CInfoBloque* pBloque)
{
	// TODO: Add your control notification handler code here
	CWaitCursor cursor_espera;

	// Es llamada antes del DoModal, no hace falta el UpdateData()
	// UpdateData(true);

	SetCabeceras("");
	SetImplementacion("");

	CGeneracionCodigoDLL codigo(p_Analizador);
	codigo.GenerarCodigoBloque(pBloque);

	SetCabeceras(codigo.m_cabeceras);
	SetImplementacion(codigo.m_implementacion);

	// UpdateData(false);
}


void CDlgGeneracionCodigoDLL::AnalizarObjCom(CInfoCom* pdatos)
{
	// TODO: Add your control notification handler code here
	CWaitCursor cursor_espera;

	// Es llamada antes del DoModal, no hace falta el UpdateData()
	// UpdateData(true);

	SetCabeceras("");
	SetImplementacion("");

	CGeneracionCodigoDLL codigo(p_Analizador);

	try
	{
		codigo.GenerarCodigoObjCom(pdatos);
		SetCabeceras(codigo.m_cabeceras);
		SetImplementacion(codigo.m_implementacion);
	}
	catch(Exception* ex)
	{
		p_diag->getVistas()->Mensaje(ex);
		delete ex;
	}

	// UpdateData(false);
}

void CDlgGeneracionCodigoDLL::AnalizarObjComES(CInfoComES* pdatos)
{
	// TODO: Add your control notification handler code here
	CWaitCursor cursor_espera;

	// Es llamada antes del DoModal, no hace falta el UpdateData()
	// UpdateData(true);

	SetCabeceras("");
	SetImplementacion("");

	CGeneracionCodigoDLL codigo(p_Analizador);
	try
	{
		codigo.GenerarCodigoObjComES(pdatos);
		SetCabeceras(codigo.m_cabeceras);
		SetImplementacion(codigo.m_implementacion);
	}
	catch(Exception* ex)
	{
		p_diag->getVistas()->Mensaje(ex);
		delete ex;
	}
	
	// UpdateData(false);
}

BOOL CDlgGeneracionCodigoDLL::SalvarTexto(CString Texto,const CString& NombreTipo,const CString& Ext,BOOL Add)
{
	CString comdinExt = "*."+ Ext;
	CString szFilter = NombreTipo + " (" + comdinExt + ") | " + comdinExt + " | Todos los Ficheros (*.*) | *.* ||";
	DWORD dwFlags;
	if (Add)  dwFlags = OFN_HIDEREADONLY;   
	else  dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT; 

	CFileDialog FileCon(false,Ext,comdinExt, dwFlags, szFilter, NULL );
	int a = FileCon.DoModal();

   	if (( a == IDCANCEL )||( a != IDOK ))
   	{
	 	return false;
   	}
   	CString NombreFichero = FileCon.GetPathName();	

	char fname[_MAX_FNAME]; // Nombre del fichero sin camino y sin extensión
	char ext[_MAX_EXT];    // Extensión
	_splitpath( NombreFichero, NULL, NULL, fname, ext );

	UINT parametros;
	if (Add)  
	{
		// Añadir al final del fichero
		parametros = CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite;
	}
	else  
	{
		// Si se genera un fichero nuevo
		// Añadimos al principio el nombre del fichero si es un fichero de código C++
		CString Sext = ext;
		Sext.MakeUpper(); // En mayúsculas para reducir el num. de comparaciones
		if ((Sext == ".H")||(Sext == ".HH")||(Sext == ".CPP")||(Sext == ".CC"))
		{
			// Es un fichero de código c++
			CString	nomfichsinpath = CString(fname) + CString(ext);
			Texto = "\r\n// " + nomfichsinpath + "\r\n\r\n" + Texto;
		}

		parametros = CFile::modeCreate|CFile::modeWrite;
	}

	CFile Fich( NombreFichero, parametros);

	if (Add) Fich.SeekToEnd();

	Fich.Write( Texto , Texto.GetLength());

	Fich.Close();
	
	return true;
}

