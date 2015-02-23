
// diagbase.cpp

#include "stdafx.h" 
#include "..\Idf.h"
#include "DiagBase.h"


#include "Bloque.h"
#include "Conect.h"
#include "BaseDoc.h"

#include "DiagramaException.h"
#include "ConectorException.h"
#include "BloqueException.h"


#include "bdiag\BloqueDiag.h"

#include "dll\BloqueDLL.h"

#include "..\view\DiagramaVistas.h"
#include "..\xmlutil\XMLUtil.h"
#include "..\util\FileUtil.h"


IMPLEMENT_DYNAMIC(CDiagBase, CObject)


CDiagBase::CDiagBase() 
{
	m_etiqueta = "TITULO DEL DIAGRAMA";

	m_ayuda = "Introducir aquí el texto de ayuda general del diagrama, se salvará junto al diagrama"; // Se accede a través del diálogo de propiedades.
	
	p_vistas = NULL;
	p_doc = NULL;
}

CDiagBase::~CDiagBase()
{
	delete p_vistas;
}

void CDiagBase::Construir(CBaseDoc* p)
{
	p_doc = p;

	p_vistas = CrearObjDiagramaVistas();
	p_vistas->Construir(this);
}

void CDiagBase::CrearNuevo()
{
    CString fileName;
	
	if ( (CGlobal::p_bloqPadre == NULL) && (CGlobal::m_fichero == "") )
    {
		BOOL pedirXML = false;
		if (!EsDiagDiseno()) 
			pedirXML = true;
		else
			pedirXML = getVistas()->Confirm("¿Crear el diseño del diagrama a partir de un L.D.D.?");

		if (pedirXML)
		{
			fileName = "*.xml"; // Por defecto

			// El directorio actual pasa a ser el que alberga el LDD, pudiendose usar caminos relativos.
			if (!getVistas()->getNuevoNombreFichero(true,fileName,(CString)LDD_WILDCARD,(CString)LDD_EXT))
			{
	 			throw new DiagramaException(this,"Debe especificarse un archivo XML de definición de diagrama");
			}
			// Obtenemos a partir del LDD el directorio de trabajo, pues FileName es un path absoluto siempre.
		}
    }
    else
    {
		if (CGlobal::p_bloqPadre != NULL)
		{
			fileName = FormarPathAbsoluto(CGlobal::p_bloqPadre->m_fichDiag);
			CBaseDoc* pdoc = getDoc();
			pdoc->p_bloqPadre = CGlobal::p_bloqPadre;
		}
		else if ((CGlobal::m_fichero != "") && CGlobal::m_esLDD)
		{
			fileName = FormarPathAbsoluto(CGlobal::m_fichero);  // Generado desde un template de diseño.
		}
		else ASSERT(false); // No debe llegar aquí
		
	}

	m_nombreLDD = fileName;  // Se recoge tal y como se pasó de argumento
	
	
	if (m_nombreLDD != "")
	{
		FILE *fich = fopen( (const char *)m_nombreLDD, "rb" );
		if (fich == NULL)
		{
	 		throw new DiagramaException(this,"No existe o no se puede abrir el fichero:\r\n" + m_nombreLDD);
		}
		fclose(fich);

		Instante t; // Instante actual	
		DOMDocument* pdoc = XMLUtil::CargarDocumento(m_nombreLDD);

		try
		{
			LeerDatosLDD(pdoc, t);
		}
		catch(Exception* ex)
		{
			XMLUtil::LiberarDocumento(pdoc);
			throw ex;
		}

		XMLUtil::LiberarDocumento(pdoc);

		MemorizarLDDOriginal(m_nombreLDD);
	}
	
	setNombreDiagrama(NULL);	    

	FlagModificado();

	getVistas()->Actualizar();
}

void CDiagBase::CrearDesdeFichero()
{
	// Dir de librerías: Normalizamos y filtramos si no estuviera bien y pone el directorio actual en su caso.
	if (EsDiagDiseno()) SetDirTrabajo(m_dirTrabajo,false); // Si está mal no mostramos error ni corregimos
	else SetDirTrabajo(m_dirTrabajo,true);  // Se exige corregirlo si estuviera mal

	getVistas()->Actualizar();
}


CBaseDoc* CDiagBase::getDoc()
{
	return p_doc;
}

CDiagramaVistas* CDiagBase::getVistas()
{
	return p_vistas;
}

void CDiagBase::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	
	if (ar.IsStoring())
	{
		ar << m_etiqueta;
		ar << m_dirTrabajo;
		ar << m_nombreLDD;		
		ar << m_dllDiag;
    	ar << m_ayuda;

		ar << m_memoriaFicheroLDD;
	}
	else
	{
		ar >> m_etiqueta;
		ar >> m_dirTrabajo;
		ar >> m_nombreLDD;
		ar >> m_dllDiag;
		ar >> m_ayuda;

		ar >> m_memoriaFicheroLDD;
	}

	p_vistas->Serialize(ar);

	m_listaBloq.Serialize(ar);
	m_listaBloqRetro.Serialize(ar);

    m_listaConect.Serialize(ar);
    m_listaConectRetro.Serialize(ar);
}


void CDiagBase::LeerDatosLDDBloques(DOMElement* bloques, const Instante& t, BOOL Retroanotacion)
{	
	// bloques es el nodo <funcionales> o <retroanotacion>

	DOMTreeWalker* walker = XMLUtil::crearWalker(bloques);
	DOMElement* bloque = (DOMElement*)walker->firstChild();

	while(bloque != NULL)
	{
		LeerDatosLDDBloque( bloque, t, Retroanotacion);

		bloque = (DOMElement*)walker->nextSibling();
	}

}

void CDiagBase::EscribirDatosLDDBloques(DOMElement* bloques,ListaBloques* plista)
{
	for (POSITION pos = plista->GetStartPosition(); pos != NULL; )
	{
		CBloque* pblq;
		CString id;
		plista->GetNextAssoc(pos,id,pblq); 	

		DOMElement* bloque = XMLUtil::appendElement(bloques,"bloque");

		EscribirDatosLDDBloque(bloque, pblq);
	}
}


void CDiagBase::LeerDatosLDDBloque( DOMElement* bloque, const Instante& t, BOOL Retroanotacion)
{

	CString tipo = XMLUtil::getAttrTexto(bloque,"tipo");
	CBloque* blq = crearBloque(tipo);
	blq->m_retroanotador = Retroanotacion;	

	try
	{
		blq->LeerDatosLDD(bloque,XMLUtil::crearWalker(bloque));
		blq->CrearNuevo( t );
	}
	catch(Exception* ex)
	{
		blq->Destruir();
		throw ex;
	}

	addBloque(blq);
}

void CDiagBase::EscribirDatosLDDBloque(DOMElement* bloque, CBloque* pblq)
{
	XMLUtil::setAttrTexto(bloque,"tipo",pblq->getTipo());

	pblq->EscribirDatosLDD(bloque);
}

void CDiagBase::LeerDatosLDDConectores(DOMElement* conectores, BOOL Retroanotacion)
{
	DOMTreeWalker* walker = XMLUtil::crearWalker(conectores);
	DOMElement* conector = (DOMElement*)walker->firstChild();

	while(conector != NULL)
	{
		LeerDatosLDDConect( conector, Retroanotacion);

		conector = (DOMElement*)walker->nextSibling();
	}
}

void CDiagBase::EscribirDatosLDDConectores(DOMElement* conectores,ListaConectores* plista)
{
	POSITION pos = plista->GetStartPosition();
	while ( pos != NULL )
	{		
		CConect* pcon;
		CString id;
		plista->GetNextAssoc(pos,id,pcon);

		DOMElement* conector = XMLUtil::appendElement(conectores,"conector");

		EscribirDatosLDDConector(conector, pcon);
	}
}


void CDiagBase::LeerDatosLDDConect(DOMElement* conector,BOOL Retroanotacion )
{
	CConect* con = crearConector();
	con->m_retroanotador = Retroanotacion;

	try
	{
		con->LeerDatosLDD(conector,XMLUtil::crearWalker(conector));
		Instante t;
		con->CrearNuevo(t);
	}
	catch(Exception* ex)
	{
		con->Destruir();
		throw ex;
	}

	addConector(con);
}

void CDiagBase::EscribirDatosLDDConector(DOMElement* conector, CConect* pcon)
{
	pcon->EscribirDatosLDD(conector);
}


void CDiagBase::FlagModificado()
{
	p_doc->SetModifiedFlag();
	p_doc->UpdateAllItems(NULL);
}


BOOL CDiagBase::PropiedadesCorrectas(CString& mensaje)
{
	// Sólo es llamada tras modificar las propiedades del diagrama
	// a través de los diálogos de propiedades
	// Analiza los campos que
	// son obligatorios de especificar para que funcione el diagrama.
	// Si todos los campos son correctamente definidos entonces	devuelve true
	// En el argumento "mensaje" pasado se escribe aquellos fallos que se han encontrado.

	BOOL OK = true;

	if ( m_etiqueta == "")
	{
		OK = false;
		mensaje += "No se ha especificado una etiqueta para el diagrama\r\n";
	}

	if (!CFileUtil::ExisteDirectorio(m_dirTrabajo))
	{
		OK = false;
		mensaje += "El directorio de localización de módulos de librerías no es válido\r\n";
	}

	return OK;
}


BOOL CDiagBase::PropiedadesCorrectasDiagramaCompleto(CString& mensaje)
{
	BOOL res = true; // Por omisión es todo correcto hasta encontrar algo mal

	// Propiedades generales del diagrama
	if (!PropiedadesCorrectas(mensaje)) res = false;
	
	// Bloques funcionales
	if (!PropiedadesCorrectasDiagramaCompleto(&m_listaBloq,mensaje))
		res = false;

	// Bloques de retroanotación
	if (!PropiedadesCorrectasDiagramaCompleto(&m_listaBloqRetro,mensaje))
		res = false;

	// Conectores funcionales
	if (!PropiedadesCorrectasDiagramaCompleto(&m_listaConect,mensaje))
		res = false;

	// Conectores de retroanotación
	if (!PropiedadesCorrectasDiagramaCompleto(&m_listaConectRetro,mensaje))
		res = false;

	return res;
}

BOOL CDiagBase::PropiedadesCorrectasDiagramaCompleto(ListaComponentes* plista,CString& mensaje)
{
	BOOL res = true;
	for (POSITION pos = plista->GetStartPosition(); pos != NULL  ; )
	{
		CComponenteDiag* comp;
		CString id;
		plista->GetNextAssoc(pos,id,comp);
		if (!comp->PropiedadesCorrectas(mensaje)) res = false;
	}
	return res;
}

void CDiagBase::ChequearNombreValido(const CString& FileName)  // Excluye Idf.dll y variantes de nombres de DLL
{
	// Esto lo hacemos porque en caso de autocarga de un DLL así mismo se cuelga faltamente (no se puede bajar ya)
	CString FileNameTemp = FileName.Right( 8 );  // Para sacar el nombre del fichero del path completo
	if (!_stricmp( FileNameTemp, "Idf.dll"))  // La comparación es en minúsculas por lo que no valen todas las posibilidades de Idf.dll
	{
		throw new DiagramaException(this,"No es válido el nombre de fichero Idf.dll y todas sus versiones de mayúsculas/minúsculas");
	}
}

CString& CDiagBase::getAyuda()
{
	return m_ayuda; 
}

void CDiagBase::setAyuda( const CString& ayuda )
{
	m_ayuda = ayuda;
}   

void CDiagBase::Destruir()
{
	BorrarColecFunc();
	BorrarColecRetro();
}

void CDiagBase::BorrarColecFunc()
{
	m_listaBloq.Destruir();
	m_listaConect.Destruir();
}


void CDiagBase::BorrarColecRetro()
{
	m_listaBloqRetro.Destruir();
	m_listaConectRetro.Destruir();
}


Instante CDiagBase::getTiempo()   // Se usa en el diálogo de propiedades, sólo informativo. También llamada por un bloque diagrama padre.
{
	// Obtiene el tiempo más actual de todos los bloques.
	
	Instante tmax(CTime(0),0); // Iniciamos a cero para que sea el tiempo mínimo posible para iterar y comparar los demás.

	if (EsDiagDiseno())  // Es irrelevante, devolvemos el actual
	{
		return Instante();
	}
	
	for (POSITION pos = m_listaBloq.GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		m_listaBloq.GetNextAssoc(pos,id,blq);

		Instante& t = blq->getTiempo();
		if (t.Compara(tmax) > 0 ) tmax.set( t );
	}
	// Los bloques de retroanotación
	for (POSITION pos = m_listaBloqRetro.GetStartPosition(); pos != NULL  ; )
	{
		CBloque* blq;
		CString id;
		m_listaBloqRetro.GetNextAssoc(pos,id,blq);

		Instante& t = blq->getTiempo();
		if (t.Compara(tmax) > 0 ) tmax.set( t );		
	}	
	
	return tmax;
}


CString CDiagBase::CadenaTiempo()
{   
	// Se usa en el diálogo de propiedades, sólo informativo. También llamada por un bloque diagrama padre.

	return getTiempo().ConvertirAString();
}

void CDiagBase::GenerarLDD(CString& FichGenerado, BOOL EjecNotepad)
{
	CString men = "ERROR GENERANDO XML:\r\n";
	if (!PropiedadesCorrectasDiagramaCompleto(men)) 
	{
		throw new DiagramaException(this,men);
	}

	CString FileName = m_nombreLDD;
	if (!getVistas()->getNuevoNombreFichero(false, FileName, (CString)LDD_WILDCARD,(CString)LDD_EXT )) 
	{
		throw new DiagramaException(this,"Debe especificarse un nombre de archivo XML");
	}

	FILE *fich = fopen( (const char *)FileName, "rb" );

	if (fich) // Lo borramos en el caso de que existiera, pues con WritePrivateProfile se mezclaría la nueva información con la antigua.
	{
    	fclose(fich);
		int res = remove( FileName );	
		if (res)
		{
		 	throw new DiagramaException(this,"No ha podido eliminarse el fichero. Fichero de sólo lectura o nombre no válido");
		}
	}

	CWaitCursor wait;
	
	DOMDocument* pdoc = XMLUtil::CrearDocumento("diagrama");

	try
	{
		EscribirDatosLDD(pdoc);
	}
	catch(Exception* ex)
	{
		XMLUtil::LiberarDocumento(pdoc);
		throw ex;
	}

	XMLUtil::SerializarDocumento(pdoc,FileName);

	XMLUtil::LiberarDocumento(pdoc);
/*
	CFile fichLDD( FileName, CFile::modeCreate|CFile::modeWrite);
	fichLDD.Write( xml , xml.GetLength());
	fichLDD.Close();
*/

	FichGenerado = FileName;
	
	if (EjecNotepad)
	{
		CString stemp = "notepad " + FileName; 
		WinExec((const char*)stemp, SW_SHOW);
	}
}


void CDiagBase::LeerDatosLDD(DOMDocument* pdoc, const Instante& t)
{
    DOMElement* diagrama = pdoc->getDocumentElement();

	DOMTreeWalker* walker = XMLUtil::crearWalker(diagrama);
	DOMElement* datos = (DOMElement*)walker->firstChild();

	DOMElement* horizontal = (DOMElement*)walker->firstChild();

	BOOL horizontalVal = XMLUtil::getBoolean(horizontal);
	if (horizontalVal)
	{
		getVistas()->PonerHorizontal();
	}

	DOMElement* directorioLib = (DOMElement*)walker->nextSibling();
	CString directorioLibVal = XMLUtil::getTexto(directorioLib);

	if (EsDiagDiseno()) SetDirTrabajo(directorioLibVal,false); // Si está mal no mostramos error ni corregimos
	else SetDirTrabajo(directorioLibVal,true);  // Se exige corregirlo si estuviera mal

	DOMElement* dllDiag = (DOMElement*)walker->nextSibling();
	setDLLDiag( XMLUtil::getTexto(dllDiag) );

	DOMElement* etiqDiagrama = (DOMElement*)walker->nextSibling();
	m_etiqueta = XMLUtil::getTexto(etiqDiagrama);

	
	DOMElement* vistas = (DOMElement*)walker->nextSibling();

	p_vistas->LeerDatosLDD(vistas);

	DOMElement* ayuda = (DOMElement*)walker->nextSibling();
	m_ayuda = XMLUtil::getTexto(ayuda);

	// Creación de las listas de bloques y conectores
	datos = (DOMElement*)walker->parentNode();
	
	DOMElement* bloques = (DOMElement*)walker->nextSibling();

		DOMElement* bloques_funcionales = (DOMElement*)walker->firstChild();
		LeerDatosLDDBloques(bloques_funcionales, t, false); // Funcionales

		DOMElement* bloques_retroanotacion = (DOMElement*)walker->nextSibling();
		LeerDatosLDDBloques(bloques_retroanotacion, t, true);  // Retroanotacion

	bloques = (DOMElement*)walker->parentNode();
	
	DOMElement* conectores = (DOMElement*)walker->nextSibling();

		DOMElement* con_funcionales = (DOMElement*)walker->firstChild();
		LeerDatosLDDConectores(con_funcionales, false);  // Funcionales

		DOMElement* con_retroanotacion = (DOMElement*)walker->nextSibling();
		LeerDatosLDDConectores(con_retroanotacion, true);  // Retroanotacion
}

void CDiagBase::EscribirDatosLDD(DOMDocument* pdoc)
{
    DOMElement* diagrama = pdoc->getDocumentElement();

	DOMElement* datos = XMLUtil::appendElement(diagrama,"datos");

	DOMElement* horizontal = XMLUtil::appendElement(datos,"horizontal");
	XMLUtil::setBoolean(horizontal,getVistas()->EsPosHorizontal());

	DOMElement* directorioLib = XMLUtil::appendElement(datos,"directorioLib");
	XMLUtil::setTexto(directorioLib,m_dirTrabajo);

	DOMElement* dllDiag = XMLUtil::appendElement(datos,"dllDiag");
	XMLUtil::setTexto(dllDiag,m_dllDiag);

	DOMElement* etiqDiagrama = XMLUtil::appendElement(datos,"etiqDiagrama");
	XMLUtil::setTexto(etiqDiagrama,m_etiqueta);

	DOMElement* vistas = XMLUtil::appendElement(datos,"vistas");

	p_vistas->EscribirDatosLDD(vistas);

	DOMElement* ayuda = XMLUtil::appendElement(datos,"ayuda");
	XMLUtil::setTexto(ayuda,m_ayuda);

	DOMElement* bloques = XMLUtil::appendElement(diagrama,"bloques");

		DOMElement* bloques_funcionales = XMLUtil::appendElement(bloques,"funcionales");
		EscribirDatosLDDBloques(bloques_funcionales,&m_listaBloq); // Funcionales

		DOMElement* bloques_retroanotacion = XMLUtil::appendElement(bloques,"retroanotacion");
		EscribirDatosLDDBloques(bloques_retroanotacion,&m_listaBloqRetro); // Retroanotación

	DOMElement* conectores = XMLUtil::appendElement(diagrama,"conectores");

		DOMElement* con_funcionales = XMLUtil::appendElement(conectores,"funcionales");
		EscribirDatosLDDConectores(con_funcionales,&m_listaConect); // Funcionales

		DOMElement* con_retroanotacion = XMLUtil::appendElement(conectores,"retroanotacion");
		EscribirDatosLDDConectores(con_retroanotacion,&m_listaConectRetro); // Retroanotación
}


BOOL CDiagBase::SetDirTrabajo(const char* nomfich, BOOL Reintentar)
{
	if (strlen(nomfich) == 0) 
	{	
		m_dirTrabajo = CFileUtil::DirectorioActual() + "\\"; // _getcwd no pone barra al final
		
		// Como no se ha especificado se considera el directorio actual
		//CString mensaje = "AVISO: El directorio de localización por defecto de los módulos de librería no está especificado, se considera el directorio actual:\r\n" + DirTrabajo;
		//Mensaje(mensaje);
		FlagModificado();				
		return true;  // Es válido el directorio nulo: no hay directorio por defecto.
	}

   	CString dirTrabajoTemp = nomfich;

	if (!CFileUtil::ExisteDirectorio(dirTrabajoTemp))
	{
		if (!Reintentar) 
		{	
			// Se queda con el valor original incorrecto por voluntad de no corregir
			m_dirTrabajo = dirTrabajoTemp;
			FlagModificado();
			return false;
		}
		
// Nuevo
		m_dirTrabajo = CFileUtil::DirectorioActual() + "\\"; // _getcwd no pone barra al final
		
		//CString mensaje = "AVISO: El directorio de localización por defecto de los módulos de librería no está especificado, se considera el directorio actual:\r\n" + DirTrabajo;
		//Mensaje(mensaje);
		FlagModificado();
		return true;

// Fin nuevo

/*
		Mensaje("ERROR: El directorio de localización por defecto de los módulos de librería no es válido o no existe, se considera el directorio actual:\r\n");

		BOOL ok = false;
		while(!ok)
		{
			CCambiaTxt dlg;
			dlg.m_Titulo = "Introduce un nuevo nombre válido de directorio:";
			dlg.m_Texto = dirTrabajoTemp;
			if (IDOK == dlg.DoModal())
			{
				dirTrabajoTemp = dlg.m_Texto;
				ok = ExisteDirectorio(dirTrabajoTemp);
				if (!ok) Mensaje("ERROR: Directorio no válido, vuelve a intentarlo");
				// Al se ok true salimos 		
			}
			else
			{
				return SetDirTrabajo("",true); // De esta manera se toma el directorio actual como el de trabajo
			}
		}	
*/
	}

	// Normalizamos el nombre
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	_splitpath( dirTrabajoTemp, drive, dir, fname, NULL );	 	
   	dirTrabajoTemp = CString(drive) + CString(dir); // Así lo tenemos bien normalizado.
	if (strlen(fname) > 0)
	{
		// Si el directorio argumento no acababa en \ el último nombre lo considera un nombre de fichero
		// cuando debía ser un directorio, lo añadimos al directorio:
		dirTrabajoTemp += CString(fname) + "\\";
	}
	m_dirTrabajo = dirTrabajoTemp;  // El valor igualado aquí es necesariamente correcto y con \ al final
	FlagModificado();
	return true;
}



CString CDiagBase::FormarPathAbsoluto(const CString& NombreFich)
{
	return CFileUtil::FormarPathAbsoluto(m_dirTrabajo,NombreFich);  // Global
}


BOOL CDiagBase::ExisteClave(const CString& clave)
{
	// Bloques funcionales
	if (ExisteClave(&m_listaBloq,clave)) return true;

	// Bloques de retroanotación
	if (ExisteClave(&m_listaBloqRetro,clave)) return true;

	// Conectores funcionales
	if (ExisteClave(&m_listaConect,clave)) return true;

	// Conectores de retroanotación
	if (ExisteClave(&m_listaConectRetro,clave)) return true;

	return false;
}


BOOL CDiagBase::ExisteClave(ListaComponentes* plista,const CString& clave)
{
	CComponenteDiag* comp;
	if (plista->Lookup(clave,comp)) return true;
	return false;
}

CString CDiagBase::getClaveNueva(const CString& raiz)
{
	// Itera por todos los elementos  para comprobar que ninguno
	// usa esa raiz. Si es usada se genera una nueva clave añadiendo
	// un número que asegure que la cadena resultante no se usa
	// como clave de ningún elemento.
	// Es últil para el enlazado tras la carga de archivo o de XML.

	if (!ExisteClave(raiz)) return raiz;  // Es nueva

	CString nuevo;	
	
	// Iteramos para generar un nuevo nombre, si existe aumentamos el índice.

	for ( int num = 2;  ; num++ )
	{	
       	char s[20];
       	CString snum = CString(_itoa( num, s, 10)); 
       	nuevo = raiz + snum;

		if (!ExisteClave(nuevo)) return nuevo;  // Es nueva
	}
	return "";  // Nunca se llegará aquí.
}

BOOL CDiagBase::EsNuevaClaveValida(const CString& clave)
{
	if (clave == "") return false;
	if (ExisteClave(clave)) return false;  // Es nueva
	return true;
}

CBloqueDiag* CDiagBase::getBloqPadre()
{
	CBaseDoc* pdoc = (CBaseDoc*)getDoc();
	return pdoc->p_bloqPadre;
}

CBloque* CDiagBase::getMDiagBloqIni()
{
	// Devolverá un valor no NULL cuando el diagrama padre
	// haya terminado de crearse y enlazar con el hijo correctamente
	// Esto ocurre después de que el diagrama hijo esté creado totalmente
	// incluso habrá comunicación entre bloques antes de construirse el padre del todo
	// Pero no hay problema pues este valor devuelto se chequea su validez en todos los usos.
	return 	getBloqPadre()->getBloqueInicio();
}

CBloque* CDiagBase::getMDiagBloqFin()
{
	// Ver notas de getMDiagBloqIni()
	return getBloqPadre()->getBloqueFin();
}

BOOL CDiagBase::EsMultiDiag()
{
	return (getBloqPadre() != NULL);
}


CBloque* CDiagBase::crearBloque(const char* tipo)
{
	CString stipo = tipo;
	if (stipo == CBloqueDLL::S_TIPO_DLL)
		return crearBloqueDLL();
	else if (stipo == CBloqueDiag::S_TIPO_DIAG)
		return crearBloqueDiag();

	return NULL;
}

CBloque* CDiagBase::crearBloqueDLL()
{
	CBloque* pblq = new CBloqueDLL();
	pblq->Construir(this);
	return pblq;
}

CBloque* CDiagBase::crearBloqueDiag()
{
	CBloque* pblq = new CBloqueDiag();
	pblq->Construir(this);
	return pblq;
}

CConect* CDiagBase::crearConector()
{
	CConect* con = new CConect();
	con->Construir( this );  // En tiempo de inicialización lo necesita, aunque se podrían hacer todos a la vez.
	return con;
}

void CDiagBase::setNombreDiagrama( const char* pszPathName )
{
	BOOL esLDD;
	CString stemp;

    if ( pszPathName )                          
    {
		esLDD = false;
		stemp = CString( pszPathName );    
	}
	else   // Es nuevo a partir de LDD.
	{
		if (m_nombreLDD != "")
		{
			esLDD = true;		
			stemp = m_nombreLDD;	 // Es pszPathName == NULL  en este caso.
		}
		else esLDD = false;
	}
	
	if (stemp != "")
	{
		//int ind = stemp.ReverseFind( '\\' );
		//int len = stemp.GetLength();
		//stemp = stemp.Right(len- ind -1);   // Se extrae el nombre del fichero sin camino.	

		char fname[_MAX_FNAME]; // Nombre del fichero sin camino y sin extensión
		char ext[_MAX_EXT];    // Extensión

		_splitpath( (const char *)stemp, NULL, NULL, fname, ext );	 	
		stemp = CString(fname); 
		if (strlen(ext) > 0)  // Tiene extensión
		{
			stemp += CString(ext);  // ext incluye el '.'
		}

		if (esLDD)  // Si es nuevo desde LDD.
		{
			// Quitamos el .LDD, para que sea el nombre del LDD sin extensión para que el sistema añada la extensión
			int len = stemp.GetLength();
			stemp = stemp.Left(len- 4); 
			p_doc->SetTitle( (const char*) fname );  // Para quitar el NombreN por defecto del sistema.
		}	
		else
		{
			p_doc->SetTitle( stemp );

			// Esposible que  pszPathName == NULL en caso de ser objeto OLE embebido en otra aplicación
			if (pszPathName) p_doc->SetPathName( pszPathName );  // Cambio de nombre a guardar.
		}
	}

	if (stemp == "") 
		stemp = p_doc->GetTitle();

	m_nombreDiag = stemp;  // Nombre + extensión (si tiene)
	
	getVistas()->setNombreDiagrama(m_nombreDiag);
}


void CDiagBase::MemorizarLDDOriginal(CString& FileName)
{
	// En 16 bits char* stemp = new char[32765];  // Tamaño sobrado para un LDD entero.
	CString stemp;

	CStdioFile fich( FileName, CFile::modeRead|CFile::typeText); // Puede dar una aserción.
	m_memoriaFicheroLDD = "";
	while ( fich.ReadString( stemp ) )
	{
	    m_memoriaFicheroLDD += stemp + "\r\n";
	}
	fich.Close();		
}   

BOOL CDiagBase::GenerarLDDOriginal()
{
	// General el LDD original exactamente con el que fue creado el diagrama funcional
	
	CString FileName = m_nombreLDD;
	if (!getVistas()->getNuevoNombreFichero(false, FileName, (CString)LDD_WILDCARD,(CString)LDD_EXT )) return false;	

	CStdioFile fich( (const char*) FileName, CFile::modeCreate|CFile::modeWrite|CFile::typeText );
	fich.WriteString((const char*) m_memoriaFicheroLDD);
	fich.Close();	
	
	CString stemp = "notepad " + FileName; 
	WinExec((const char*)stemp, SW_SHOW);	

	return true;
}	

void CDiagBase::addBloque(CBloque* pblq)
{
   	if (!pblq->EsRetroanotador()) m_listaBloq.SetAt( pblq->getId(),pblq );
	else m_listaBloqRetro.SetAt( pblq->getId(),pblq );
}

void CDiagBase::addConector(CConect* pcon)
{
  	if (!pcon->EsRetroanotador()) m_listaConect.SetAt(pcon->getId(), pcon );
	else m_listaConectRetro.SetAt( pcon->getId(), pcon );
}

void CDiagBase::setDLLDiag(const CString& dllDiag)
{
	ChequearNombreValido(dllDiag);
	m_dllDiag = dllDiag;
}

CString CDiagBase::getDLLDiag()
{
	return m_dllDiag;
}

