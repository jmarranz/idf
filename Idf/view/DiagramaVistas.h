// DiagramaVistas.h: interface for the CDiagramaVistas class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIAGRAMAVISTAS_H__E3778C5E_C621_4AA1_8F23_F36BF55DE98E__INCLUDED_)
#define AFX_DIAGRAMAVISTAS_H__E3778C5E_C621_4AA1_8F23_F36BF55DE98E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DIN A4 visto verticalmente
#define DINA4_H  210
#define DINA4_V  297


class CDiagBase;
class CBaseView;
class CDibDiagrama;
class ListaBloques;
class ListaConectores;
class ListaComponentes;
class Exception;


class CDiagramaVistas : public CObject  
{
public:
	CDiagramaVistas();
	virtual ~CDiagramaVistas();

	virtual void Construir(CDiagBase* pdiag);
	CDiagBase* getDiag()
	{
		return p_diag;
	}

	virtual CDibDiagrama* CrearObjDibDiagrama() = 0;
	CDibDiagrama* getDibDiagrama();

	virtual void Serialize(CArchive& ar);
	virtual void LeerDatosLDD(DOMElement* vistas);
	virtual void EscribirDatosLDD(DOMElement* vistas);

	virtual void addView(CBaseView* view);
	virtual void addView(ListaComponentes* plista,CBaseView* view);

	virtual void removeView(CBaseView* view);  // Destruye todos los diálogos de una vista (pues puede haber varias vistas).
	virtual void removeView(ListaComponentes* plista,CBaseView* view);
	
	virtual void Actualizar();
	virtual void Actualizar(CBaseView* view);
	virtual void Actualizar(ListaComponentes* plista,CBaseView* view);
	virtual void ActualizarExcepto(CBaseView* view);

	virtual BOOL Propiedades();

	virtual void AnalizarDll();
	virtual void GenerarCodigoDiagrama();

	virtual void setNombreDiagrama( const char* nombre ) = 0;	

	virtual BOOL getNuevoNombreDLL(CString& FileName);
	virtual BOOL getNuevoNombreFichero(BOOL Abrir,CString& FileName, CString Tipo = "", CString Ext = "");

	virtual void Mensaje(const CString& men);
	virtual void Mensaje(const char* men);	
	virtual void Mensaje(Exception* ex);
	virtual BOOL Confirm(const CString& men);
	virtual BOOL Confirm(const char* men);

	virtual CSize getDiagSize(CBaseView* view);
	virtual CSize getDiagSize();
	BOOL ValidarX_A4(int valor);
	BOOL ValidarY_A4(int valor);
	BOOL ValidarXY_A4(const CPoint& p);  // Para diseño interactivo, no muestra error.
	BOOL ValidarRect_A4(const CRect& r);
	
	void PonerVertical();
	void PonerHorizontal();
	BOOL EsPosHorizontal();

public:
	CObList m_views;

protected:
	CDiagBase* p_diag;
	CDibDiagrama* p_dibDiagrama;

	CSize m_sizeDoc;  // Area del diagrama, es fijo (DIN A4 en decimas de milimetro)

};

#endif // !defined(AFX_DIAGRAMAVISTAS_H__E3778C5E_C621_4AA1_8F23_F36BF55DE98E__INCLUDED_)
