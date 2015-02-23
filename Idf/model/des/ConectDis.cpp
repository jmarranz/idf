
/////////////////////////////////////////////////////////////////////////////
// conecdis.cpp


#include "stdafx.h"
#include "..\..\Idf.h"
#include "ConectDis.h"

#include "DiagDis.h"
#include "..\Bloque.h"
#include "..\Conect.h"
#include "..\ConectInicio.h"
#include "..\ConectFin.h"

#include "..\..\view\des\ConectVistasDis.h"
#include "..\..\view\des\DibConectDis.h"
#include "..\..\view\des\DiagramaVistasDis.h"

#include "..\ConectorException.h"


IMPLEMENT_SERIAL(CConectDis, CConectModo, 1)

CConectDis::CConectDis()
{
	m_gravedad = false;
}

CConectDis::~CConectDis()
{
}

void CConectDis::CrearNuevo( const Instante& t )
{

}

void CConectDis::CrearDeFichero()
{
	ActualizaEstado();
}

CComponenteDiagVistas* CConectDis::CrearObjVistas()
{
	return new CConectVistasDis();
}


void CConectDis::AsociarBloque(CDiagDisView* view, CBloque* blq, CDlgBloque* dlgblq, CPoint point)
{
	// Los conectores de retroanotación no tienen ninguna limitación
	// en el tipo de bloques a los que se asocian.
	// Los funcionales sólo pueden conectarse a bloques funcionales
	
	CDiagDis* pDiagDis = p_conect->getDiagDis();
	if ((ASOCIABLQINI == pDiagDis->m_estadoEdic) || (ASOCIABLQFIN == pDiagDis->m_estadoEdic))
	{
	    if ( (!p_conect->EsRetroanotador()) &&  blq->EsRetroanotador() ) // Test de si es válida la asociación del conector funcional
	    {
			pDiagDis->m_estadoEdic = NULO; // Fin de la edición
    		pDiagDis->p_conect = NULL;  

			throw new ConectorException(p_conect,"Un conector funcional no puede ser asociado a un bloque de retroanotación. Elija un bloque funcional");
 		}	    

		try
		{
			if (ASOCIABLQINI == pDiagDis->m_estadoEdic)
			{
				p_conect->setInicio( blq );
			}

			if (ASOCIABLQFIN == pDiagDis->m_estadoEdic)
			{
				p_conect->setFin( blq );
			}
		}
		catch(Exception* ex)
		{
			pDiagDis->m_estadoEdic = NULO; // Fin de la edición
    		pDiagDis->p_conect = NULL;  
			throw ex;
		}

		if (m_gravedad)
		{
			CDibConectDis* pDibConTarget = p_conect->getVistas()->getDibConect()->getDis();
			pDibConTarget->MoverConGravedad(view, dlgblq,point); 
			m_gravedad = false;
		}
		pDiagDis->m_estadoEdic = NULO; // Fin de la edición
    	pDiagDis->p_conect = NULL;        

	    // Asociación Correcta
		ActualizaEstado();
		pDiagDis->FlagModificado();
		pDiagDis->getVistas()->Actualizar();
	}
}


void CConectDis::ActualizaEstado()
{
	// Cambia el color y estado (si es necesario) en el diseño visual a partir de si está conectado o no: 
    EstadosConector EstadoTemp = p_conect->getEstado();

    if ((p_conect->getInicio() != NULL) || (p_conect->getFin() != NULL)) // Alguno definido.
	{	    
		// Sólo si todas las propiedades están definidas (no sólo conexiones)
		// damos el atributo de correcto diseño (CRICULA)
		if (p_conect->CComponenteDiag::PropiedadesCorrectas())  p_conect->setEstado(CIRCULA); // Todo bien definido 
		else p_conect->setEstado(FALLIDO);  // Indica incompleto, falta un enlace o algún parámetro.
    }
    else // Ninguna asociación definida (como si fuera nuevo).
    {
     	p_conect->setEstado(NOCIRCULA);
    }
}

