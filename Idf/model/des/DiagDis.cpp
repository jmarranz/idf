
// diagdis.cpp

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagDis.h"

#include "ConectDis.h"

#include "..\BaseDoc.h"
#include "..\Conect.h"
#include "..\ConectorException.h"


#include "..\bdiag\BloqueDiag.h"
#include "..\bdiag\des\BloqueDiagDis.h"

#include "..\dll\BloqueDLL.h" 
#include "..\dll\des\BloqueDLLDis.h" 

#include "..\..\view\BloqueVistas.h"
#include "..\..\view\des\ConectVistasDis.h"
#include "..\..\view\des\DibConectDis.h"

#include "..\..\view\des\DiagramaVistasDis.h"

#include "..\..\Exception.h"


IMPLEMENT_SERIAL(CDiagDis, CObject, 1)  // No poner CDiagBase porque es virtual pura

CDiagDis::CDiagDis()
{
	m_estadoEdic = NULO;
	p_conect = NULL;
}


CDiagDis::~CDiagDis()
{
}

void CDiagDis::CrearNuevo()
{
	CDiagBase::CrearNuevo();

	CDiagramaVistasDis* pVistas = getVistas();
	pVistas->CrearTablaDis(m_nombreDiag);
}

void CDiagDis::CrearDesdeFichero()
{
	CDiagBase::CrearDesdeFichero();

	getVistas()->CrearTablaDis(m_nombreDiag);
}

CDiagramaVistas* CDiagDis::CrearObjDiagramaVistas()
{
	return new CDiagramaVistasDis();
}

void CDiagDis::Destruir()
{
	CDiagBase::Destruir();

	getVistas()->DestruirTablaDis();
}   

void CDiagDis::Serialize(CArchive& ar)
{
	CDiagBase::Serialize(ar);

	if (ar.IsStoring())
	{
	}
	else
	{
        CrearDesdeFichero();
	}
} 


CBloqueDLL* CDiagDis::NuevoBloqueDLLFunc()
{
	CBloqueDLL* blq = (CBloqueDLL*)crearBloqueDLL();
	NuevoBloque(blq,"BlqDLLFunc",false);
   	
	return blq;
}	

CBloqueDiag* CDiagDis::NuevoBloqueDiag()
{
	CBloqueDiag* blq = (CBloqueDiag*)crearBloqueDiag();  
	NuevoBloque(blq,"BlqDiagFunc",false);

	return blq;
}


CBloqueDLL* CDiagDis::NuevoBloqueDLLRetro()
{
	CBloqueDLL* blq = (CBloqueDLL*)crearBloqueDLL();
	NuevoBloque(blq,"BlqDLLRetro",true);

	return blq;
}	

void CDiagDis::NuevoBloque(CBloque* blq,const char* idRaiz,BOOL retro)
{
	// Lo común de la creación de nuevos bloques.
 	CString id = getClaveNueva(idRaiz);
	try
	{
		blq->setId(id);
		blq->m_retroanotador = retro;

		blq->setEtiqueta(blq->getId());  // Idem.

		Instante t;
		blq->CrearNuevo(t);
	}
	catch(Exception* ex)
	{
		blq->Destruir();
		throw ex;	
	}

	addBloque(blq);

    // Los valores por defecto dados en el constructor nos sirven la mayoría.
    
	// Creamos un nuevo diálogo en todas las vistas del documento abiertas:    

	blq->getVistas()->CrearNuevo();
}

CConect* CDiagDis::NuevoConectFunc(CPoint pmm)
{
	CConect* con = crearConector(); 
	NuevoConect( con, "ConFunc", false,pmm);
   	
	return con;
}	

CConect* CDiagDis::NuevoConectRetro(CPoint pmm)
{
	CConect* con = crearConector(); 
	NuevoConect( con, "ConRetro", true,pmm);

	return con;
}	

void CDiagDis::NuevoConect(CConect* con,const char* idRaiz,BOOL retro, CPoint pmm)
{
	CString id = getClaveNueva(idRaiz);

	try
	{
		con->setId(id);
		con->m_retroanotador = retro;
		Instante t;
		con->CrearNuevo(t);
	}
	catch(Exception* ex)
	{
		con->Destruir();
		throw ex;	
	}

	addConector(con);

	con->getVistas()->CrearNuevo();

	// La mayoría de los valores iniciales valen con los dados en el constructor.
	CDibConect* pDibCon = con->getVistas()->getDibConect();

	pDibCon->AnyadeNudoFinal(pmm);   // Nodo de índice 0. El comienzo del conductor siempre
    
    CPoint pfinal = CPoint(pmm.x + 50, pmm.y);
	pDibCon->AnyadeNudoFinal(pfinal);  // El final del conector. 

	pDibCon->m_ptoInsEtiq = pmm;  // Podrá cambiarse.

    CFlecha* flecha = pDibCon->getpFlecha();
	flecha->Iniciar(pfinal, ALTURAFLECHA, pDibCon->m_ancho,ESTE ); 
}



void CDiagDis::EliminarBloque(CBloque* pBloque)
{
	ListaBloques* plista;
	if (!pBloque->EsRetroanotador()) plista = &m_listaBloq;
	else plista = &m_listaBloqRetro;

	CString idBloque = pBloque->getId();

	pBloque->Destruir();  // Desconecta y actualiza también los conectores asociados

	plista->RemoveKey(idBloque);

	FlagModificado();
}
 

void CDiagDis::EliminarConector(CConect* pConect)
{
	ListaConectores* plista;
	if (!pConect->EsRetroanotador()) plista = &m_listaConect;
	else plista = &m_listaConectRetro;

	CString idConect = pConect->getId();

   	pConect->Destruir();

	plista->RemoveKey( idConect );  
	FlagModificado();
}

void CDiagDis::comienzoAsociarBloque(EstadosDiseno extremo,CConect* con)
{
	if (m_estadoEdic == NULO)
	{
		// Comprobamos antes si podemos asociar
		// Si es funcional, al menos debe de haber uno funcional
		// Si es retroanotador debe existir o uno funcional o de retroanotación
		if (!con->EsRetroanotador())  // Funcional
		{
			if (m_listaBloq.IsEmpty())
			{
		   		p_conect = NULL;
				throw new ConectorException(con,"No hay ningún bloque funcional definido, crear uno antes de asociar el conector");
			}
		}
		else if (con->EsRetroanotador())  // Retroanotador
		{
			if (m_listaBloq.IsEmpty() && m_listaBloqRetro.IsEmpty())
			{
                p_conect = NULL;
				throw new ConectorException(con,"No hay ningún bloque funcional ni retroanotador definido, crear uno antes de asociar el conector retroanotador");
			}
		}

		p_conect = con;
		m_estadoEdic = extremo;

		// OJO, NO se captura el ratón para la vista, pues tenemos que pulsar un bloque para asociarlo.
	}
}

void CDiagDis::comienzoAsociarBloqueIni(CConect* con)
{
	comienzoAsociarBloque(ASOCIABLQINI,con);
}

void CDiagDis::comienzoAsociarBloqueFin(CConect* con)
{
	comienzoAsociarBloque(ASOCIABLQFIN,con);
}
