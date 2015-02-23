
/////////////////////////////////////////////////////////////////////////////
// bloque.cpp

#include "stdafx.h" 
#include "..\Idf.h"
#include "Bloque.h"

#include "DiagBase.h"

#include "BloqueModo.h"
#include "Conect.h"
#include "ConectInicio.h"
#include "ConectFin.h"

#include "..\view\BloqueVistas.h"

#include "..\xmlutil\XMLUtil.h"


IMPLEMENT_DYNAMIC(CBloque,CComponenteDiag)                
// IMPLEMENT_SERIAL(CBloque, CObject,1)  NO VALE PUES ES CLASE PURA.

CBloque::CBloque()  // Para serialización
{
	p_vistas = NULL;
	p_modo = NULL;

	// Inicializamos las variables que se guardan a fichero para asegurar si es nuevo un valor correcto (no todas se leen del LDD) y también nos valen para diseño interactivo.

    // Un entero no vale para definir todos los colores, por lo que no vale la pena ponerlo en el fichero profile LDD
    // de todas formas, es mejor cambiarlo en el diagrama ya creado como una característica y de forma interactiva
    // Por ello inicialemente es necesario inicializar los colores.

	m_ae = false;
	m_as = false;

	m_autoContMax = -1;  // Por defecto, ilimitado número

	
	m_salidaAuto = "";  // Etiqueta del conductor de salida de bucle en el caso un proceso automático (para finalizar éste).
}


CBloque::~CBloque() 
{
	delete p_modo;
	delete p_vistas;
}

void CBloque::Construir(CDiagBase* p )
{
	CComponenteDiag::Construir(p);
}


void CBloque::CrearNuevo(const Instante& t)  
{
	p_modo->CrearNuevo(t);
}


void CBloque::CrearDeFichero()  // Se llama desde las derivadas.
{
	p_modo->CrearDeFichero();
}    


void CBloque::Destruir()
{
	CComponenteDiag::Destruir();

	p_modo->Destruir();

	delete this;
}


void CBloque::LeerDatosLDD( DOMElement* bloque,DOMTreeWalker* walker)
{
	CComponenteDiag::LeerDatosLDD(bloque,walker);

	DOMElement* etiqSalidaAuto = (DOMElement*)walker->nextSibling();
	m_salidaAuto = XMLUtil::getTexto(etiqSalidaAuto);

	DOMElement* activaEntrada = (DOMElement*)walker->nextSibling();
	m_ae = XMLUtil::getBoolean(activaEntrada);
	
	DOMElement* activaSalida = (DOMElement*)walker->nextSibling();
	m_as = XMLUtil::getBoolean(activaSalida);

	DOMElement* autoCiclosMaximo = (DOMElement*)walker->nextSibling();
	m_autoContMax = XMLUtil::getEntero(autoCiclosMaximo);

	DOMElement* vistas = (DOMElement*)walker->nextSibling();
	
	p_vistas->LeerDatosLDD(vistas,XMLUtil::crearWalker(vistas));
}


void CBloque::EscribirDatosLDD(DOMElement* bloque)
{
	CComponenteDiag::EscribirDatosLDD(bloque);

	DOMElement* etiqSalidaAuto = XMLUtil::appendElement(bloque,"etiqSalidaAuto");
	XMLUtil::setTexto(etiqSalidaAuto,m_salidaAuto);

	DOMElement* activaEntrada = XMLUtil::appendElement(bloque,"activaEntrada");
	XMLUtil::setBoolean(activaEntrada,m_ae);

	DOMElement* activaSalida = XMLUtil::appendElement(bloque,"activaSalida");
	XMLUtil::setBoolean(activaSalida,m_as);

	DOMElement* autoCiclosMaximo = XMLUtil::appendElement(bloque,"autoCiclosMaximo");
	XMLUtil::setEntero(autoCiclosMaximo,m_autoContMax);

	DOMElement* vistas = XMLUtil::appendElement(bloque,"vistas");

	p_vistas->EscribirDatosLDD(vistas);
}


BOOL CBloque::PropiedadesCorrectas(CString& mensaje) 
{
	// Sólo es llamada tras modificar las propiedades del bloque
	// a través de los diálogos de propiedades
	// Analiza los campos comunes (propiedades generales) a todos los tipos de bloques que
	// son obligatorios de especificar para que funcione el diagrama.
	// Si todos los campos son correctamente definidos entonces	devuelve true
	// En el argumento "mensaje" pasado se escribe aquellos fallos que se han encontrado.

	BOOL OK = CComponenteDiag::PropiedadesCorrectas(mensaje);

	if (getEtiqueta() == "")
	{
		OK = false;
		mensaje += "Etiqueta del bloque no definida\r\n";
	}

	return OK;
}

void CBloque::Serialize(CArchive& ar)
{
	CComponenteDiag::Serialize(ar);  
	
	if (ar.IsStoring())
	{
		ar << m_salidaAuto;
		ar << m_autoContMax; 
		ar << m_ae << m_as;
	}
	else
	{
		ar >> m_salidaAuto;
		ar >> m_autoContMax; 
		ar >> m_ae >> m_as;	
	}	

	p_vistas->Serialize(ar);

} 




const char * CBloque::getFicheroLDD()   //No usar CString como retorno pues necesitamos el puntero a la cadena en memoria para acceder por un DLL
{
	return (const char *)getDiag()->m_nombreLDD;
} 


void CBloque::CambiaEstado(CString& estado)
{
	TipoEstadoUsuario estadousr;
	if ("INCOMPLETO" == estado) estadousr = INCOMPLETO;
	if ("ERRONEO" == estado) estadousr = ERRONEO;
	if ("CORRECTO" == estado) estadousr = CORRECTO;	 
	CambiaEstado(estadousr);
}


CString CBloque::EstadoUsrAstring()
{
	CString SEstado;
	switch(getEstadoUsr())
	{
		case INCOMPLETO:
		{
			SEstado = S_INCOMPLETO;
			break;
		}
		case ERRONEO:
		{
			SEstado = S_ERRONEO;
			break;
		}
		case CORRECTO:
		{
			SEstado = S_CORRECTO;
			break;
		}						
		default:
		{
			SEstado = S_CORRECTO;
		}		
	}
	return SEstado;

}

CString CBloque::EstadoIntAstring()
{
	CString SEstado;
	switch(getEstadoInt())
	{
		case NUEVO:
		{
			SEstado = "NUEVO";
			break;
		}
		case MODIFICADO:
		{
			SEstado = "MODIFICADO";
			break;
		}
		default:
		{
			SEstado = "MODIFICADO";
		}		
	}

	return SEstado;
}


POSITION CBloque::getPrimerConectEntradaPos(BOOL Retroanota )
{
	if (!Retroanota) return m_listaConectEntrada.GetStartPosition();
	else return m_listaConectEntradaRetro.GetStartPosition();
}

CConect* CBloque::getSigConectEntrada(POSITION& pos, BOOL Retroanota )
{
	CConect* con;
	CString id;
	if (!Retroanota) m_listaConectEntrada.GetNextAssoc( pos,id,con );
	else  m_listaConectEntradaRetro.GetNextAssoc( pos,id,con );
	return con;
}

POSITION CBloque::getPrimerConectSalidaPos(BOOL Retroanota )
{
	if (!Retroanota) return m_listaConectSalida.GetStartPosition();
	else return m_listaConectSalidaRetro.GetStartPosition();
}

CConect* CBloque::getSigConectSalida(POSITION& pos, BOOL Retroanota )
{
	CConect* con;
	CString id;
	if (!Retroanota) m_listaConectSalida.GetNextAssoc( pos,id,con );
	else  m_listaConectSalidaRetro.GetNextAssoc( pos,id,con );
	return con;
}



BOOL CBloque::EsMultiDiag()
{
	return getDiag()->EsMultiDiag();
}

BOOL CBloque::CambiaEstado(TipoEstadoUsuario estado)
{  
	return p_modo->CambiaEstado(estado);
}

Instante CBloque::getTiempo()
{
	return p_modo->getTiempo();  
}

TipoEstadoUsuario CBloque::getEstadoUsr()
{
	return p_modo->getEstadoUsr();
}

int CBloque::listaEstadosUsuario(int index,CString& texto)
{
	switch(index)
	{
		case 0: texto = S_INCOMPLETO; return INCOMPLETO;
		case 1: texto = S_ERRONEO; return ERRONEO;
		case 2: texto = S_CORRECTO; return CORRECTO;
	}

	return -1; // MAL 
}


TipoEstadoInterno CBloque::getEstadoInt()
{
	return p_modo->getEstadoInt();   
}

void CBloque::setEstadoUsr(TipoEstadoUsuario estado)
{
	p_modo->setEstadoUsr(estado);
}

void CBloque::setEstadoInt(TipoEstadoInterno estado)
{
	p_modo->setEstadoInt(estado);
}

BOOL CBloque::EsNuevo()
{
	return p_modo->EsNuevo();   
}

CString CBloque::getOrden()
{
	if (EsMultiDiag())
	{
		CDiagBase* pdiag = getDiag();

		if (pdiag->getMDiagBloqIni() == this)  return (CString)"INICIO";
		if (pdiag->getMDiagBloqFin() == this)  return (CString)"FINAL";
        return (CString)"MEDIO";
	}

	return (CString)"";
}


