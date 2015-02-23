// DiagramaVistasDis.h: interface for the CDiagramaVistasDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIAGRAMAVISTASDIS_H__54FAC52B_8B85_4831_9CEF_64D6ED326FED__INCLUDED_)
#define AFX_DIAGRAMAVISTASDIS_H__54FAC52B_8B85_4831_9CEF_64D6ED326FED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\DiagramaVistas.h"

class CTablaDis;
class CDibDiagramaDis;


class CDiagramaVistasDis : public CDiagramaVistas  
{
public:
	CDiagramaVistasDis();
	virtual ~CDiagramaVistasDis();

	CDibDiagramaDis* getDibDiagrama()
	{
		return (CDibDiagramaDis*)p_dibDiagrama;
	}

	virtual CDibDiagrama* CrearObjDibDiagrama();

	virtual void PropRejilla();

	virtual void CrearTablaDis(CString& titulo);
	virtual void DestruirTablaDis();
	virtual void CambiaVerTablaDis();
	virtual BOOL SincronizarEstadoTablaDis();

	virtual void setNombreDiagrama( const char* nombre );	


public:
	CTablaDis* p_dlgTabla;
	BOOL m_verDlgTablaDis;
};

#endif // !defined(AFX_DIAGRAMAVISTASDIS_H__54FAC52B_8B85_4831_9CEF_64D6ED326FED__INCLUDED_)
