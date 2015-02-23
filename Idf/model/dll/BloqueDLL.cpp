// BloqueDLL.cpp: implementation of the CBloqueDLL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\..\Idf.h"
#include "BloqueDLL.h"

#include "..\DiagBase.h"
#include "..\BloqueException.h"

#include "exe\BloqueDLLExe.h"
#include "des\BloqueDLLDis.h"

#include "..\..\view\dll\BloqueDLLVistas.h"

#include "..\..\xmlutil\XMLUtil.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString CBloqueDLL::S_TIPO_DLL = "dll";

IMPLEMENT_SERIAL(CBloqueDLL,CBloque,1)

CBloqueDLL::CBloqueDLL()
{
	m_macro = "Escribir aquí la macro o datos asociados a la funcionalidad del bloque, se salvarán junto al diagrama";
	m_usaDLLDiag = false;
}

CBloqueDLL::~CBloqueDLL()
{

}

void CBloqueDLL::Construir(CDiagBase* p)
{
	if (!p->EsDiagDiseno()) p_modo = new CBloqueDLLExe;
	else p_modo = new CBloqueDLLDis;

	p_modo->Construir(this);

	CBloque::Construir(p);
}

CComponenteDiagVistas* CBloqueDLL::CrearObjVistas()
{
	return new CBloqueDLLVistas();
}

CString& CBloqueDLL::getMacro()
{
	return m_macro;
}

void CBloqueDLL::setMacro(const CString& macro)
{
	m_macro = macro; 
}

void CBloqueDLL::LeerDatosLDD(DOMElement* bloque,DOMTreeWalker* walker)
{
	CBloque::LeerDatosLDD(bloque,walker);

	DOMElement* dllBloque = (DOMElement*)walker->nextSibling();
	setDLLBloque( XMLUtil::getTexto(dllBloque) );

	DOMElement* claseBloque = (DOMElement*)walker->nextSibling();
	m_claseDatosBloque = XMLUtil::getTexto(claseBloque);

	DOMElement* anexo = (DOMElement*)walker->nextSibling();
	m_macro = XMLUtil::getTexto(anexo);

	getModo()->ActualizaEstado();
}


void CBloqueDLL::EscribirDatosLDD(DOMElement* bloque)
{
    CBloque::EscribirDatosLDD( bloque );

	DOMElement* dllBloque = XMLUtil::appendElement(bloque,"dllBloque");
	if (m_usaDLLDiag)
		XMLUtil::setTexto(dllBloque,"");
	else
		XMLUtil::setTexto(dllBloque,m_DLLBloque);

	DOMElement* claseBloque = XMLUtil::appendElement(bloque,"claseBloque");
	XMLUtil::setTexto(claseBloque,m_claseDatosBloque);

	DOMElement* anexo = XMLUtil::appendElement(bloque,"anexo");
	XMLUtil::setTexto(anexo,m_macro);
}

void CBloqueDLL::Serialize(CArchive& ar)
{
	CBloque::Serialize(ar); 
		
	if (ar.IsStoring())
	{
		ar << getDLLBloque();
	 	ar << m_usaDLLDiag;	
		ar << m_claseDatosBloque;
		ar << m_macro;

		p_modo->Serialize(ar);
	}
	else
	{
		ar >> m_DLLBloque;
		ar >> m_usaDLLDiag;	
		ar >> m_claseDatosBloque;
		ar >> m_macro;

		CrearDeFichero();

		p_modo->Serialize(ar);
	}	
} 

BOOL CBloqueDLL::PropiedadesCorrectas(CString& mensaje)
{
	// Redefinida de CBloque
	// En este nivel verificamos las variables que son específicas de CBloqueDLLExe
	// Devuelve false si hay algo mal y si todo está bien el valor devuelto del nivel superior

	BOOL OK = CBloque::PropiedadesCorrectas(mensaje);

	if ( (!m_usaDLLDiag) && m_DLLBloque == "")
	{
		OK = false;
		mensaje += "No usa el DLL común al diagrama y no tiene definido DLL propio\r\n";
	}
	if ( (m_usaDLLDiag) && (getDiag()->getDLLDiag() == ""))
	{
		OK = false;
		mensaje += "Especificado el uso del DLL común al diagrama, pero dicho DLL no ha sido definido todavía\r\n";
	}	
	if ( m_claseDatosBloque == "")
	{
		OK = false;
		mensaje += "No se ha definido el nombre de la clase del objeto en el DLL\r\n";
	}

	return OK;
}

void CBloqueDLL::setDLLBloque(const CString& dllbloque)
{
	if (dllbloque == "")
	{
		if ( getDiag()->getDLLDiag() == "" )
		{
			throw new BloqueException(this,"No definido un DLL genérico de diagrama, y el bloque no tiene DLL propio");
		}
		m_usaDLLDiag = true;   // Usa el nombre del DLL común al diagrama, pero lo carga de nuevo el bloque por sencillez.
		m_DLLBloque = "";
	}
	else
	{
		m_usaDLLDiag = false;  // Usa un DLL propio.
		m_DLLBloque = dllbloque;
		getDiag()->ChequearNombreValido(m_DLLBloque);
	}
}

CString CBloqueDLL::getDLLBloque()
{
	if (m_usaDLLDiag) return getDiag()->getDLLDiag();
	else return m_DLLBloque;
}


BOOL CBloqueDLL::getUsaDLLDiag()
{
	return m_usaDLLDiag;
}

