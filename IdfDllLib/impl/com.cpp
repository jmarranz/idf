
// DatosCom.cpp

#include "stdafx.h"
#include "IdfDllApp.h"

//#include "resource.h"

#include "com.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


IMPLEMENT_SERIAL(CCom,CObject,1)



CCom::CCom()
{

}


CCom::~CCom()   // Para creación dinámica y serialización
{

}

BOOL CCom::CrearDeFichero()
{
	return true;
}

void CCom::Mensaje(const char* mensaje)
{
	(*ObtpApp()->pConectorMensaje)(p_Conector,mensaje);
}


CString CCom::getEtiquetaConector()
{
	return (CString)(*ObtpApp()->pConectorGetEtiqueta)(p_Conector);
}

CString CCom::getNombreInternoConector()
{
	return (CString)(*ObtpApp()->pConectorGetNombreInterno)(p_Conector);
}

BOOL CCom::EsRetroAnotador()
{
	return (*ObtpApp()->pConectorEsRetroAnotador)(p_Conector);
}

void CCom::Serialize(CArchive& ar) 
{
	CObject::Serialize(ar);  // Llamada al padre para guardar el dato temporal y en general toda la cadena de CObject

	// Serializar aquí los datos internos de CCom
	if (ar.IsStoring())
	{
		GuardarDatos(ar);
	}
	else
	{
		LeerDatos(ar);

		CrearDeFichero();   // Inicializa variables no grabables.
	}	
}

void CCom::GuardarDatos(CArchive& ar)
{
	CRuntimeClass* prtm = GetRuntimeClass( );

	CString s = "Aviso: Se está usando la clase de comunicaciones \"" + CString(prtm->m_lpszClassName) + "\" para comunicar datos entre DLLs, necesita implementar la función GuardarDatos()";
	AfxMessageBox(s);
}

void CCom::LeerDatos(CArchive& ar)
{
	CRuntimeClass* prtm = GetRuntimeClass( );

	CString s = "Aviso: Se está usando la clase de comunicaciones \"" + CString(prtm->m_lpszClassName) + "\" para comunicar datos entre DLLs, necesita implementar la función LeerDatos()";
	AfxMessageBox(s);
}

