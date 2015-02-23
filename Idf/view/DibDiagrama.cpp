// DibDiagrama.cpp: implementation of the CDibDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "DibDiagrama.h"

#include "BloqueVistas.h"
#include "BaseView.h"
#include "DibBloque.h"
#include "ConectVistas.h"
#include "DibConect.h"
#include "DiagramaVistas.h"

#include "..\model\BaseDoc.h"
#include "..\model\DiagBase.h"
#include "..\model\Bloque.h"
#include "..\model\Conect.h"

#include "..\xmlutil\XMLUtil.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CDibDiagrama,CObject,1)


CDibDiagrama::CDibDiagrama()
{
	m_iPtSize = TAMFONTDIAG;
	m_nomfont = FONTDIAG; 

	m_colEtiq = RGB(0,0,0);  
    m_pInsEtiq = CPoint(20,20);  // Por poner un lugar por defecto (en mm)

    m_scrollAuto = true;
    m_operZoom = true;

	p_vistas = NULL;
	p_diag = NULL;
}

CDibDiagrama::~CDibDiagrama()
{

}

void CDibDiagrama::Construir(CDiagramaVistas* pvistas)
{
	p_vistas = pvistas;
	p_diag = pvistas->getDiag();
}

void CDibDiagrama::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_pInsEtiq;
		ar << m_colEtiq;    	
    	ar << m_scrollAuto;
		ar << m_operZoom;
	}
	else
	{
		ar >> m_pInsEtiq;
		ar >> m_colEtiq;
		ar >> m_scrollAuto;
		ar >> m_operZoom;
	}
}


void CDibDiagrama::LeerDatosLDD(DOMElement* vistas)
{
	DOMTreeWalker* walker = XMLUtil::crearWalker(vistas);

	DOMElement* xInsEtiq = (DOMElement*)walker->firstChild();
	int XInsEtiq = XMLUtil::getEntero(xInsEtiq);

	DOMElement* yInsEtiq = (DOMElement*)walker->nextSibling();
	int YInsEtiq = XMLUtil::getEntero(yInsEtiq);

	m_pInsEtiq = CPoint( XInsEtiq, YInsEtiq );


	DOMElement* rgbEtiq = (DOMElement*)walker->nextSibling();
	
	m_colEtiq.LeerDatosLDD(rgbEtiq);
}


void CDibDiagrama::EscribirDatosLDD(DOMElement* vistas)
{
	DOMElement* xInsEtiq = XMLUtil::appendElement(vistas,"xInsEtiq");
	XMLUtil::setEntero(xInsEtiq,m_pInsEtiq.x);

	DOMElement* yInsEtiq = XMLUtil::appendElement(vistas,"yInsEtiq");
	XMLUtil::setEntero(yInsEtiq,m_pInsEtiq.y);

	DOMElement* rgbEtiq = XMLUtil::appendElement(vistas,"rgbEtiq");

	m_colEtiq.EscribirDatosLDD(rgbEtiq);	
}

void CDibDiagrama::Dibujar(CDC* pDC, CBaseView* view)
{
	if (p_diag->m_etiqueta != "")
	{	
        pDC->SetBkColor(RGB(255,255,255));
		pDC->SetTextColor( m_colEtiq.getColor() );
       
		CPoint fontsize = Escala(CPoint(0, m_iPtSize), view);
        CFont NEAR FuenteEtiq;
		if (!FuenteEtiq.CreateFont(fontsize.y , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, PROOF_QUALITY, 0, m_nomfont)) return; 
		CFont* fvieja = pDC->SelectObject( &FuenteEtiq );
	
 		CPoint p = m_pInsEtiq;
		
		CSize size = getVistas()->getDiagSize();
		int size_x = size.cx / 10;
		int size_y = size.cy / 10;

        CSize s(size_x - p.x, size_y);  // DIN A4 en mm. El rectángulo es sólo para establecer sus límites. El valor y da igual (la altura de letra).
        CRect r = Escala(CRect( p, s ), view);
        
		if (view)
		{
        	pDC->SetTextAlign(TA_NOUPDATECP);
        	pDC->DrawText( (LPCSTR)p_diag->m_etiqueta,p_diag->m_etiqueta.GetLength(),r ,DT_LEFT|DT_SINGLELINE);
		}		
		else
		{	// Si es METAFILE (OLE) DrawText no vale.	
			pDC->SetTextAlign(TA_LEFT | TA_BOTTOM | TA_NOUPDATECP);
			CPoint pt =  r.TopLeft();
			if (!pDC->ExtTextOut( pt.x, pt.y, 0 , &r, (LPCSTR)p_diag->m_etiqueta, p_diag->m_etiqueta.GetLength(), NULL ))
				AfxMessageBox("No puedo dibujar texto"); 		
 		}
		if (view) pDC->SelectObject(fvieja);  // Si view == NULL es OLE y pDC es un Metafile, no hace falta y si se hace el comportamiento es impredecible.
	}
	
	// Conectores y Bloques funcionales
	Dibujar(&p_diag->m_listaConect,pDC,view);
	Dibujar(&p_diag->m_listaBloq,pDC,view);

	// Conectores y Bloques de Retroanotación:
	Dibujar(&p_diag->m_listaConectRetro,pDC,view);
	Dibujar(&p_diag->m_listaBloqRetro,pDC,view);
}

void CDibDiagrama::Dibujar(ListaBloques* plista,CDC* pDC, CBaseView* view)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		plista->GetNextAssoc(pos,id,blq);
		blq->getVistas()->getDibBloque()->Dibujar(pDC, view);			
	}
}

void CDibDiagrama::Dibujar(ListaConectores* plista,CDC* pDC, CBaseView* view)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CConect* con;
		CString id;
		plista->GetNextAssoc(pos,id,con);
		con->getVistas()->getDibConect()->Dibujar(pDC, view);
	}
}


CPoint CDibDiagrama::Escala(CPoint& pto, CBaseView* view)
{
	// Transforma las dimensiones de un pto en mm (introducido por ej con un fichero L.D.D.) para 
	// adaptarlo al mapa de MM_LOMETRIC de 0.1 mm .	
	// Se multiplican por 10 y la coordenada y cambia de signo.
	// El usuario debe entrar sus datos en el L.D.D. pensando en un DIN A4 con origen en la esquina sup.
	// izda. y en milímetros. 	
 	CPoint p;
	if (view)
	{
	 	p = CPoint(pto.x * 10, - pto.y *10);
	 	p = view->EscalaVisual( p );   // Escala para visualización en pantalla, depende de la ventana.
	}	
	else // Generación de la imagen como metafichero (ej. OLE servidor como item embebido en otra aplicación).
	{
	 	p = CPoint(pto.x * 10, + pto.y *10);	 	
	}
	
	return p;
}
                            
CRect CDibDiagrama::Escala(CRect& rect, CBaseView* view)
{
	CPoint p1, p2;
	p1 = Escala(rect.TopLeft(), view);
	p2 = Escala(rect.BottomRight(), view);
	CRect r(p1.x, p1.y, p2.x, p2.y);
	return r;
}


CPoint CDibDiagrama::EscalaInversa(CPoint& pto, CBaseView* view)
{
	// Transforma las dimensiones de un pto en coordenadas lógicas (MM_LOMETRIC de 0.1 mm) 
	// en mm y direcciones positivas.	
	// Se multiplican por 10 y la coordenada y cambia de signo.
	// El usuario debe entrar sus datos en el L.D.D. pensando en un DIN A4 con origen en la esquina sup.
	// izda. y en milímetros. 	
 	CPoint p;
	if (view)
	{
	 	p = CPoint(pto.x / 10, - pto.y / 10);  // Un nuevo cambio de signo lo hace positivo
	 	p = view->EscalaVisualInversa( p );   // Escala para visualización en pantalla, depende de la ventana.
	}	
	else // Generación de la imagen como metafichero (ej. OLE servidor como item embebido en otra aplicación).
	{   // En diseño no creo que se pase nunca por aquí al generar un metafichero.
	 	p = CPoint(pto.x * 10, + pto.y *10);	 	
	}
	
	return p;
}


CRect CDibDiagrama::EscalaInversa(CRect& rect, CBaseView* view )
{
	CPoint p1, p2;
	p1 = EscalaInversa(rect.TopLeft(), view);
	p2 = EscalaInversa(rect.BottomRight(), view);
	CRect r(p1.x, p1.y, p2.x, p2.y);
	return r;
}

void CDibDiagrama::GenerarMetafile()
{
	// TODO: Add your command handler code here
	CString FileName;

	BOOL enhanced = false;

	if (getVistas()->Confirm("¿Generar Metafichero Mejorado?"))  enhanced = true;
	
	CMetaFileDC dc;	

	CSize sizeDoc = getVistas()->getDiagSize();

	if (enhanced)
	{
		FileName = "*.emf";
		if (!p_vistas->getNuevoNombreFichero( false, FileName, (CString)"Enhanced Windows Metafile (*.emf)",(CString)"emf"))
			return;	

		CRect DinA4(CPoint(0,0),CSize(sizeDoc.cx * 10,sizeDoc.cy * 10));   // En HIMETRICS (0.01 mm)
		CString descmeta = "Integrador de Diagramas de Flujo\0Diagrama WMF\0\0";

		dc.CreateEnhanced(NULL,FileName, NULL /* (LPCRECT)DinA4*/,descmeta);
	}
	else
	{
		FileName = "*.wmf";
		if (!p_vistas->getNuevoNombreFichero( false, FileName, (CString)"Windows Metafile (*.wmf)",(CString)"wmf"))
			return;
		dc.Create(FileName);
	}

	AfxGetApp()->DoWaitCursor( 1 );	
	
	dc.SetMapMode(MM_ANISOTROPIC);   // MM_LOMETRIC da problemas, hacemos una pirula
	if (!enhanced)
	{
		dc.SetWindowOrg(0,0);
		dc.SetWindowExt(sizeDoc.cx,sizeDoc.cx);
	}

	Dibujar(&dc,NULL);

	if (enhanced)
	{
		HENHMETAFILE hmf = dc.CloseEnhanced();  
		::DeleteEnhMetaFile(hmf);
	}
	else
	{
		HMETAFILE hmf = dc.Close();

		/* En 16 bits era necesario, pero en Win32 al parecer no

		// Hasta aquí es el viejo formato MetaFile pero que no es compatible con programas actuales por ejemplo OFFICE
		// No contiene información de cual es la extensión por lo que sería preciso un programa procesador de imágenes
		// que lo convirtiera al formato con cabecera (Placeable Metafile) que sí entiende OFFICE.
		// Hacemos la conversión pues no es más que añadir una cabecera.

		METAFILEHEADER  head;   // Está definida la estructura en DiagExeDoc.h

		head.key = 0x9AC6CDD7L;
		head.hmf = 0;
		head.bbox = CRect(0,0,2100,2970);
		head.inch = 254;	    // 254 mm = 1 inch Luego al insertar el metafile por defecto se verá en un DINA4
		head.reserved = 0;

		WORD suma = 0;
		WORD* p = (WORD*)&head;
		
		for (int i=0; i<10; i++)
		{
			suma = *(p+i) ^ suma;	
		}

		head.checksum = suma;  // Cabecera completada.
			
		UINT memtam = (UINT)GlobalSize(hmf);  // 64k para un MetaFile es un mogollón.
    
		CFile fs;
		fs.Open((const char*)FileName,CFile::modeCreate | CFile::modeWrite);

		fs.Write( &head, sizeof(head) );  // Escritura de la cabecera.

		char * pmf = (char *)GlobalLock(hmf);

		fs.Write(pmf,memtam);
    
		fs.Close();
    
		GlobalUnlock(hmf);
		*/

  		::DeleteMetaFile(hmf);
	}

	CString stemp = "  Metafichero (Windows MetaFile) generado correctamente.\r\n";
	stemp += "  El formato metafichero (normal o mejorado) de Windows permite almacenar información gráfica en fichero de forma altamente eficiente ocupando un espacio mínimo ";
	stemp += "al almacenar los comandos de dibujo y no el dibujo mismo.\r\n";
	stemp += "  El metafichero del diagrama generado, por defecto ocupa la extensión de un DINA4, pero no por ello se guarda en disco ";
	stemp += "la información correspondiente a un bitmap del mismo tamaño en pantalla pixel a pixel.\r\n";
	stemp += "  A través de ciertos programas es posible cambiar los componentes del metafichero individualmente (líneas, texto etc.) al editar la imagen ";
	stemp += "y volver a salvar de nuevo como un metafichero el conjunto, pudiendo así retocar los componentes del dibujo del diagrama con fines documentales.";

	AfxGetApp()->DoWaitCursor( -1 );	
	getVistas()->Mensaje(stemp);

	ShellExecute(NULL,"open", FileName, NULL, NULL, SW_SHOWNORMAL);
}
