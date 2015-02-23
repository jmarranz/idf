// dlglog.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DlgLog.h"

#include "..\..\model\exe\DiagExe.h"

#include "DiagramaVistasExe.h"


/////////////////////////////////////////////////////////////////////////////
// CDlgLog dialog


CDlgLog::CDlgLog(CDiagExe* diag,CWnd* pParent /*=NULL*/)    // No se usa, es no modal
	: CDialog(CDlgLog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLog)
	//}}AFX_DATA_INIT
	p_diag = diag;
	p_vistas = p_diag->getVistas();
}


BOOL CDlgLog::Crear()
{
    if (!CDialog::Create(IDD, NULL))   // Se engancha a la ventana principal del programa 
		return false; // Raro		

	m_CtrlLista.SetHorizontalExtent( 1000 );  // Pixels aprox. de una SuperVGA
	m_contador = 0;
	return true;
}


void CDlgLog::ActualizaTitulo(const char* titulo)   // Se llama cuando se guarda a fichero el diagrama (pues puede cambiar el nombre) y al crear
{ 
	if (EsValidaVentana(this))  // Existe la ventana creada.
	{	
		SetWindowText( titulo);
	}
}	

void CDlgLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLog)
	DDX_Control(pDX, IDC_LISTA_CON, m_CtrlLista);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLog, CDialog)
	//{{AFX_MSG_MAP(CDlgLog)
	ON_WM_SIZE()
	ON_COMMAND(ID_CONSOLA_COPIAR, OnConsolaCopiar)
	ON_COMMAND(ID_CONSOLA_CORTAR, OnConsolaCortar)
	ON_COMMAND(ID_CONSOLA_LIMPIAR, OnConsolaLimpiar)
	ON_COMMAND(ID_CONSOLA_SALIDA, OnConsolaSalida)
	ON_COMMAND(ID_CONSOLA_SALVA, OnConsolaSalva)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgLog message handlers
                              

void CDlgLog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here

    CRect Trect;
    GetClientRect( &Trect );  // Rectángulo actual del diálogo en coordenadas de dispositivo.

	CRect RTexto( Trect );   // Recordar que son operaciones enteras, dividir lo último.

	m_CtrlLista.MoveWindow(RTexto);	    // Se adapta al nuevo tamaño.

}

void CDlgLog::Anyadir( CString mensaje)
{
	if (EsValidaVentana(this))  // Existe la ventana creada.
	{
		m_contador++;
		char sn[20];
		sprintf(sn,"%d",m_contador);
		mensaje = CString(sn) + " " + mensaje;
		m_CtrlLista.AddString( mensaje );
		m_CtrlLista.SetTopIndex( m_CtrlLista.GetCount()-10 );  // Scroll tal que vemos las 10 últimas líneas.
		if (m_contador >= 32000)
		{ 
			m_contador--;
			m_CtrlLista.DeleteString(0);   // Añade una pero se borra la primera al llegar cerca del límite max.
		}
	}
}	


void CDlgLog::BorrarTexto()
{
	if (EsValidaVentana(this))  // Existe la ventana creada.
	{
		m_CtrlLista.ResetContent();
	}	
}


void CDlgLog::Serializar(CArchive& ar)
{
	if (ar.IsStoring())
	{		
		if (EsValidaVentana(this))  // Existe la ventana creada.
		{
			/*
			CDConfirm Salvar;
			Salvar.Mensaje((CString)"¿Salvar el contenido de la consola junto al diagrama?");	
			if (IDOK != Salvar.DoModal())
			{
				m_CtrlLista.ResetContent();	 // Se salvará una consola vacía.		
			}
			*/
			if (!p_vistas->m_salvarConsola) m_CtrlLista.ResetContent();	 // Se salvará una consola vacía.	
		}
		int imax = 0;
		if (EsValidaVentana(this))	imax = m_CtrlLista.GetCount();
		ar << imax;
		for ( int i = 0; i < imax ; i++ )
		{
		 	CString str;
		 	if (EsValidaVentana(this)) m_CtrlLista.GetText( i, str ); 
			ar << str;
		}
	}
	else
	{
		if (p_vistas->m_mostrarConsola) Crear();  // Crear consola.

		int imax;
		ar >> imax;
		for ( int i = 0; i < imax ; i++ )
		{
			CString str;
			ar >> str;
			if (EsValidaVentana(this))  m_CtrlLista.AddString( str );
		}
		m_contador = imax;  // Para que la siguiente línea siga el ordinal de la última sesión de trabajo
	}
}

void CDlgLog::OnConsolaCopiar()
{
	// TODO: Add your command handler code here

    CString texto;
    int nlin = getTextoSelec(texto);
	if (nlin)
	{
		CopiarEnPortapapeles(this,texto);
	}	
}

void CDlgLog::OnConsolaCortar()
{
	// TODO: Add your command handler code here
     
    CString texto;
    int nlin = getTextoSelec(texto, true); 
	if (nlin)
	{
		CopiarEnPortapapeles(this,texto);
	}	
}


void CDlgLog::OnConsolaLimpiar()
{
	// TODO: Add your command handler code here
	BorrarTexto();		
}

void CDlgLog::OnConsolaSalida()
{
	// TODO: Add your command handler code here
	ConsolaSalir();
}

void CDlgLog::OnConsolaSalva()
{
	// TODO: Add your command handler code here
	CString NombreDefecto = p_diag->m_nombreDiag;
	
	int len = NombreDefecto.GetLength();
	if ( NombreDefecto.GetAt(len-4) == '.' )
    {
		NombreDefecto.SetAt( len-1, 't' );
		NombreDefecto.SetAt( len-2, 'x' );
		NombreDefecto.SetAt( len-3, 't' );
	}
	else NombreDefecto += ".txt";

	SalvarTextoLista(NombreDefecto);
}

void CDlgLog::ConsolaSalir()  // Es llamada también por CDiagExeBaseDoc
{
	p_vistas->m_mostrarConsola = false;
	CString mensaje("¿Salvar el contenido a fichero?");
	if (p_diag->getVistas()->Confirm(mensaje)) OnConsolaSalva();
	DestroyWindow();	
}

void CDlgLog::OnClose()  // Cerrado manual de la consola.
{
	// TODO: Add your message handler code here and/or call default

	ConsolaSalir();
	
	CDialog::OnClose();  // Llama a  DestroyWindow de nuevo pero no pasa nada.
}

BOOL CDlgLog::SalvarTextoLista(CString& NombreFichero)
{
	
	char szFilter[] = "Texto (*.txt) | *.txt | Todos los Ficheros (*.*) | *.* ||";   
	DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;    
	
	CFileDialog FileCon(false,(LPCSTR)"txt",(LPCSTR)NombreFichero, dwFlags, szFilter, NULL );
	int a = FileCon.DoModal();

   	if (( a == IDCANCEL )||( a != IDOK ))
   	{
	 	return false;
   	}
   	NombreFichero = FileCon.GetPathName();	

	CStdioFile FichStd( NombreFichero, CFile::modeCreate|CFile::modeWrite|CFile::typeText);

	int imax = m_CtrlLista.GetCount();

	for ( int i = 0; i < imax ; i++ )
	{
	 	CString str;
	 	m_CtrlLista.GetText( i, str ); 
		str += "\r\n";
		FichStd.WriteString( (const char *)str ); 
	}
	FichStd.Close();
	
	return true;
}



int CDlgLog::getTextoSelec(CString& texto, BOOL borrar)
{
	int i = 0;

	int nmax = m_CtrlLista.GetSelCount( );
	
	if (!nmax) return 0;
	
	int  * matind = new int[nmax];
	m_CtrlLista.GetSelItems( nmax, matind );  // Los índices van de menor a mayor en la matriz.
	
	for ( i = 0; i < nmax ; i++ )
	{
		CString str;
	 	m_CtrlLista.GetText( matind[i], str ); 
		texto += str + "\r\n";
		if (texto.GetLength() > 32000) break;     // Límite de aprox. 32K
	}
	if (borrar)
	{
		for ( int i = 0; i < nmax ; i++ )
		{
         	m_CtrlLista.DeleteString( matind[i]-i );  // Restamos i porque al borrar los índices reales cambian (uno menos cada borrado)
		}
	}

	delete [] matind;

	return i;  // Devuelve el número de líneas copiado.
}


void CDlgLog::CopiarEnPortapapeles(CWnd* pWnd,CString& texto)
{
    if (texto.GetLength())
	{
		HGLOBAL clipbrd = GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE |GMEM_DISCARDABLE , texto.GetLength()); 
		char * lpBuffer;
		lpBuffer = (char *)GlobalLock(clipbrd);
    	strcpy(lpBuffer,(const char *)texto);
		GlobalUnlock(clipbrd);
		
    	pWnd->OpenClipboard();
		EmptyClipboard();
		HANDLE nuevo = SetClipboardData(CF_TEXT , clipbrd); 
		// Parece ser que el handle y la memoria los maneja el clipboard tras SetClipboardData, nos despreocupamos del valor de clipbrd desde ahora. Si la líberáramos o modificáramos el objeto podríamos provocar un error.
		CloseClipboard();
    }
}


