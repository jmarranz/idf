
/////////////////////////////////////////////////////////////////////////////
// bloqdll.cpp


#include "stdafx.h" 
#include "..\..\..\Idf.h"
#include "BloqueDLLExe.h"

#include "..\..\BloqueException.h"
#include "..\BloqueDLL.h"
#include "..\..\exe\DiagExe.h"
#include "..\..\exe\Comunicacion.h"

#include "..\..\..\view\DiagramaVistas.h"

#include "..\..\..\view\dll\BloqueDLLVistas.h"
#include "..\..\..\view\dll\exe\BloqueDLLVistasExe.h"

                
IMPLEMENT_SERIAL(CBloqueDLLExe, CBloqueExe,1)    

CBloqueDLLExe::CBloqueDLLExe()  // Se ejecuta en carga por serialización.
{
	p_bloqueEnDLL = NULL;
	m_objDatosCreado = false;
	m_objUsuarioCreado = false;
}

CBloqueDLLExe::~CBloqueDLLExe() 
{
}


void CBloqueDLLExe::CrearNuevo( const Instante& t )  
{
	CBloqueUnidadExe::CrearNuevo(t);

	CargayEnlazadoDLLBloque();

	CrearNuevoObjBloqueEnDLL();

	(*pDefineBloque)(p_bloqueEnDLL, (CBloqueDLL*)p_bloque);
}


void CBloqueDLLExe::CrearDeFichero()
{
	CargayEnlazadoDLLBloque();
	
 	try
	{
		CrearObjBloqueEnDLL();
	}
	catch(Exception* ex)
	{ 
		DescargaDLLBloque();
		throw ex;     	
	}
	   
   	(*pDefineBloque)(p_bloqueEnDLL,(CBloqueDLL*)p_bloque);  // Es necesario definir pronto antes de llamar al DLL pues si hay error necesita acceder a mEtiq 
}    


void CBloqueDLLExe::Destruir()
{
	DestObjBloqueFunc();
	DescargaDLLBloque();
}


BOOL CBloqueDLLExe::IniciarDatosBloque()
{
	m_objUsuarioCreado = (*pIniciarDatosBloque)(p_bloqueEnDLL);	

	return m_objUsuarioCreado;
}


void CBloqueDLLExe::IniciarExplicito(const Instante& t)  
{
	CBloqueUnidadExe::IniciarExplicito(t);

	(*pIniciarExplicito)(p_bloqueEnDLL);
}


void CBloqueDLLExe::CargaDLLBloque()
{
	CBloqueDLL* pbloque = getBloque();

	CDiagBase* pdiag = pbloque->getDiag();

 
	// Aunque un bloque use el DLL común al diagrama lo carga también.
	// Luego lo que toma el bloque es el nombre del DLL común pero lo carga de nuevo
	// aunque lo haya cargado el diagrama
	SetErrorMode(SEM_NOOPENFILEERRORBOX);
	CString nombreDLLAbs = pdiag->FormarPathAbsoluto(pbloque->getDLLBloque());

	try
	{
   		m_DLLDiagrama.Cargar(nombreDLLAbs);
	}
	catch(Exception* ex)
	{
		m_DLLDiagrama.Descargar(); // Por si acaso

		pdiag->getVistas()->Mensaje(ex);
		delete ex;

		pbloque->getVistas()->Mensaje("Especifique de nuevo el nombre y localización del módulo DLL");

		CString dllBloque;
		if (!pdiag->getVistas()->getNuevoNombreDLL(dllBloque)) 
		{
			throw new BloqueException(pbloque,"Debe especificarse un archivo DLL"); 
		}
		pbloque->setDLLBloque(dllBloque);
		pdiag->FlagModificado();

		CargaDLLBloque(); // recursiva
		// No capturamos porque si ocurre es que no hay solución
	}

}


void CBloqueDLLExe::CargayEnlazadoDLLBloque()
{
	CBloqueDLL* pbloque = getBloque();

	try
	{
		CargaDLLBloque();
		EnlazadoDLLBloque();
	}
	catch(Exception* ex)
	{
		DescargaDLLBloque();
		throw ex;
	}
}


void CBloqueDLLExe::EnlazadoDLLBloque()
{	
	// Enlazado dinámico de la API exportada por el DLL (ya sea el común al diagrama o el del bloque).
	HINSTANCE hinstDLLBloque = m_DLLDiagrama.getHandler();

	psetNuevoBloqueEnDLL = (BOOL ( *)(void * pBloqueEnDLL)) GetProcAddress(hinstDLLBloque, "Bloque_setNuevo");
    if (psetNuevoBloqueEnDLL == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}

	pDefineBloque = (void ( *)(void * pBloqueEnDLL,CBloqueDLL* bloque)) GetProcAddress(hinstDLLBloque, "Bloque_DefineBloque");	
    if (pDefineBloque == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}

	pAccion = (const char  * ( *)(void  *pBloqueEnDLL)) GetProcAddress(hinstDLLBloque, "Bloque_Accion"); 
    if (pAccion == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}

	pSerializar = (BOOL ( *)(void  *pBloqueEnDLL,LPSTREAM stream, UINT modo)) GetProcAddress(hinstDLLBloque, "Bloque_Serializar"); 
    if (pSerializar == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}

	pDestObjBloqueFunc = (void ( *)(void * pBloqueEnDLL, BOOL ObjUsuarioCreado)) GetProcAddress(hinstDLLBloque, "Bloque_DestObjBloqueFunc"); 	
    if (pDestObjBloqueFunc == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}

	pIniciarExplicito = (void ( *)(void  *pBloqueEnDLL)) GetProcAddress(hinstDLLBloque, "Bloque_IniciarExplicito");
	if (pIniciarExplicito == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}

	pIniciarDatosBloque = (BOOL ( *)(void  *pBloqueEnDLL)) GetProcAddress(hinstDLLBloque, "Bloque_IniciarDatosBloque");	
    if (pIniciarDatosBloque == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}

	pEnError = (void ( *)(void  *pBloqueEnDLL, int TipoError, const char * EtiqPost)) GetProcAddress(hinstDLLBloque, "Bloque_EnError");
    if (pEnError == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}    

	pPropUsuario = (BOOL ( *)(void  *pBloqueEnDLL)) GetProcAddress(hinstDLLBloque, "Bloque_PropUsuario");
    if (pPropUsuario == NULL)
    {
		throw new BloqueException(getBloque(),ErrorEnlaceDLL());
	}  		
}


void CBloqueDLLExe::DescargaDLLBloque()
{
	m_DLLDiagrama.Descargar();
}

CString CBloqueDLLExe::ErrorEnlaceDLL()
{
	CBloqueDLL* pbloque = getBloque();
	return CDLLDiagrama::MensajeErrorNoDLLDiag(pbloque->getDLLBloque());   // Nos vale el mismo mensaje que en la clase CDiagExe.	
}


void CBloqueDLLExe::DestObjBloqueFunc()
{
	if (m_objDatosCreado) 
	{
		(*pDestObjBloqueFunc)(p_bloqueEnDLL, m_objUsuarioCreado);   // Borra el objeto creado tanto como diagrama nuevo, como creado por leer de fichero.
		m_objDatosCreado = false;
	}
}


void CBloqueDLLExe::CrearObjBloqueEnDLL()   // Crea un objeto CBloqueFunc o CBloqueRetro en el DLLdel tipo derivado dado.
{
	HINSTANCE hinstDLLBloque = m_DLLDiagrama.getHandler();

	CBloqueDLL* pbloque = getBloque();
	CDiagBase* pdiag = pbloque->getDiag();

	BOOL OK = false;
	while ( !OK )
	{	
		void  * ( *pCrearBloqueEnDLL)();	
		CString STemp;

		// Test de si admite el bloque inicio el objeto de salida especificado en el LDD.

		STemp = "CrearBloqueEnDLL"+ pbloque->m_claseDatosBloque;
		pCrearBloqueEnDLL = (void  * ( *)()) GetProcAddress(hinstDLLBloque, STemp);
    	if (pCrearBloqueEnDLL == NULL)
		{
			m_objDatosCreado = false;
			CString men = "No está definido el tipo de objeto de bloque \"" + pbloque->m_claseDatosBloque + "\" en el DLL:\r\n" + pbloque->getDLLBloque();
			pbloque->getVistas()->Mensaje(men); 
			
			if (pbloque->getVistas()->getExe()->nuevoNombreClaseEnDLL())
				continue;
			else 
				throw new BloqueException(pbloque,"Debe especificarse un nombre de clase");
		}	
	
		p_bloqueEnDLL = (*pCrearBloqueEnDLL)();
		if (p_bloqueEnDLL == NULL)
		{
			// Error de no definida la clase en la lista (no registrada).    
			m_objDatosCreado = false;

			CString men = "No ha podido crearse el bloque en el DLL asociado:\r\n" + pbloque->getDLLBloque();
			pbloque->getVistas()->Mensaje(men); 

			if (pbloque->getVistas()->getExe()->nuevoNombreClaseEnDLL())
				continue;
			else 
				throw new BloqueException(pbloque,"Debe especificarse un nombre de clase");
		}
		OK = true;
	}	

	m_objDatosCreado = true;
}


void CBloqueDLLExe::CrearNuevoObjBloqueEnDLL()  // Crea e inicializa un objeto CBloqueFunc del tipo derivado dado y lo inicializa.
{
	CBloqueDLL* pbloque = getBloque();

	try
	{
		CrearObjBloqueEnDLL();
	}
	catch(Exception* ex)
	{ 
		DescargaDLLBloque();
		throw ex;     	
	}

	if ( !(*psetNuevoBloqueEnDLL)(p_bloqueEnDLL) ) // Necesitamos registrar el tipo de objeto de comunicaciones (salida)	e iniciar en general el objeto. 
	{
		DescargaDLLBloque();

		// Error de no definida la clase en la lista (no registrada).    
		CString men = "Error en el bloque asociado en el DLL:\r\n" + pbloque->getDLLBloque();
		throw new BloqueException(pbloque,men); 
	}	
}


CString CBloqueDLLExe::Accion(CBaseView* view)
{
	CBloqueDLL* pbloque = getBloque();
	CDiagBase* pdiag = pbloque->getDiag();

	if (NUEVO == m_estadoInterno)
	{
		CambiaEstado(INCOMPLETO);
	}         
	m_instante.Iniciar(); // Instante actual

	pdiag->FlagModificado();  // Documento modificado desde la última vez salvado.

	return (CString)(*pAccion)(p_bloqueEnDLL);  // Funcion que el programador ha de reescribir en una clase derivada de CBloqueFunc
}


void CBloqueDLLExe::Serialize(CArchive& ar)
{
	CBloqueUnidadExe::Serialize(ar);

	SerializarDLL(ar);
} 


void CBloqueDLLExe::SerializarDLL(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar.Flush();  // Por si acaso pues al pasar al DLL se va a hacer escritura con el mismo manejador, para evitar posible mezcla.
		COleStreamFile *file = (COleStreamFile*)ar.GetFile();		
		file->Flush();

//		HFILE hfile = file->m_hFile;   No se usa en un COleStreamFile como es el caso.

       	LPSTREAM stream = file->Detach();

		if (!(*pSerializar)(p_bloqueEnDLL, stream, CArchive::store)) AfxThrowArchiveException(CArchiveException::badIndex);  //El DLL ha escrito mal

		file->Attach(stream);	
 	}
 	else
 	{
 		COleStreamFile *file = (COleStreamFile*)ar.GetFile();		
       	ar.Flush();
        file->Flush();
 //		HFILE hfile = file->m_hFile;    No se usa en un COleStreamFile como es el caso.
        LPSTREAM stream = file->Detach();

		if (!(*pSerializar)(p_bloqueEnDLL, stream, CArchive::load)) AfxThrowArchiveException(CArchiveException::badIndex);  //El DLL ha leído mal

		file->Attach(stream);
		m_objUsuarioCreado = true;  // Suponemos que los objetos de usuario han sido creados explícitamente por el usuario. Necesario para destruir. Si hay error no pasa por aquí la aserción luego es false el valor.
 	}
}


HINSTANCE CBloqueDLLExe::getHinstDLL()
{
	return m_DLLDiagrama.getHandler(); 
}


void CBloqueDLLExe::EnError(int TipoError, CBloque* bloque)
{
	(*pEnError)(p_bloqueEnDLL, TipoError, (const char  *)bloque->getEtiqueta() );
}


