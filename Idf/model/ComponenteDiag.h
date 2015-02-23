// ComponenteDiag.h: interface for the CComponenteDiag class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTEDIAG_H__F65C0947_CEDC_47F7_8230_371152B789E9__INCLUDED_)
#define AFX_COMPONENTEDIAG_H__F65C0947_CEDC_47F7_8230_371152B789E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDiagBase;
class CDiagExe;
class CDiagDis;
class CComponenteDiagVistas;
class DOMElement;


class CComponenteDiag : public CObject  
{
	DECLARE_DYNAMIC(CComponenteDiag)

public:
	CComponenteDiag();
	virtual ~CComponenteDiag();

	virtual void Construir(CDiagBase* p);
	virtual void Destruir();

	virtual void Serialize(CArchive& ar);	
	virtual void LeerDatosLDD( DOMElement* componente,DOMTreeWalker* walker);
	virtual void EscribirDatosLDD(DOMElement* componente);

	virtual CComponenteDiagVistas* CrearObjVistas() = 0;

	CComponenteDiagVistas* getVistas()
	{
		return p_vistas;
	}

	CDiagBase* getDiag()  // No debe ser virtual
	{
		return p_diag;
	}

	CDiagExe* getDiagExe()  // No debe ser virtual
	{
		return (CDiagExe*)p_diag;
	}

	CDiagDis* getDiagDis()  // No debe ser virtual
	{
		return (CDiagDis*)p_diag;
	}

	virtual BOOL esBloque() 
	{ 
		return false; 
	}

	virtual BOOL esConector() 
	{ 
		return false; 
	}

	virtual BOOL EsModoDiseno();

	virtual const CString& getId();
	virtual void setId(const CString& id);

	virtual const CString& getEtiqueta();
	virtual void setEtiqueta(const CString& etiq);

	virtual const CString& getAyuda();
	virtual void setAyuda( const CString& ayuda ); 

	virtual BOOL EsRetroanotador() { return m_retroanotador; };  // Si es retroanotador la derivada devolverá true

	virtual BOOL PropiedadesCorrectas();  // Devuelve true si las propiedades obligatorias del bloque están bien definidas
	virtual BOOL PropiedadesCorrectas(CString& mensaje);  // Devuelve true si las propiedades obligatorias del bloque están bien definidas

protected:
	CComponenteDiagVistas* p_vistas;

	CDiagBase* p_diag;    // Puntero al diagrama padre.

public:
	CString m_id;  
	BOOL m_retroanotador;

protected:
	CString m_etiqueta;
	CString m_ayuda;  

};

#endif // !defined(AFX_COMPONENTEDIAG_H__F65C0947_CEDC_47F7_8230_371152B789E9__INCLUDED_)
