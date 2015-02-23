// BloqueDiag.h: interface for the CBloqueDiag class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEDIAG_H__93C19994_1591_4319_B2F5_F343F12750BA__INCLUDED_)
#define AFX_BLOQUEDIAG_H__93C19994_1591_4319_B2F5_F343F12750BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Bloque.h"

class BloqueException;
class CBaseDoc;
class CBloqueDiagExe;
class CBloqueDiagDis;
class CBloqueDiagVistas;
class CComponenteDiagVistas;

enum OrdenBloqueDiag { INICIODIAG, FINDIAG };


class CBloqueDiag : public CBloque  
{
	DECLARE_SERIAL(CBloqueDiag)
public:
	CBloqueDiag();
	virtual ~CBloqueDiag();

	virtual const char* getTipo() 
	{ 
		return S_TIPO_DIAG; 
	}

    // Redefinidas de CBloque:
	virtual void Construir(CDiagBase* p);
	virtual void Destruir(); 

    virtual void CrearNuevo( const Instante& t );
    virtual void CrearDeFichero();

	virtual CComponenteDiagVistas* CrearObjVistas();

	CBloqueDiagVistas* getVistas()
	{
		return (CBloqueDiagVistas*)p_vistas;
	}

	CBloqueDiagExe* getExe()
	{
		return (CBloqueDiagExe*)p_modo;
	}

	CBloqueDiagDis* getDis()
	{
		return (CBloqueDiagDis*)p_modo;
	}

	virtual CBloque* getBloqueInicio()
	{
		return p_bloqIni;
	}

	virtual CBloque* getBloqueFin()
	{
		return p_bloqFin;
	}

	virtual CBaseDoc* getSubdiagrama()
	{
		return p_docHijo;
	}


	virtual void LeerDatosLDD(DOMElement* bloque,DOMTreeWalker* walker);
	virtual void EscribirDatosLDD(DOMElement* bloque);	
	virtual void Serialize(CArchive& ar);

	virtual BOOL EsBloqueDiag() { return true; }

	virtual CBloque* getBloque(OrdenBloqueDiag tipo);
	virtual CString getClaveBloque(OrdenBloqueDiag tipo);

	virtual void setBloque(OrdenBloqueDiag tipo, CBloque* blq);
	virtual void setBloque(OrdenBloqueDiag tipo,const CString& idBloque);

	virtual void ConectarSubdiagrama();

	virtual BOOL PropiedadesCorrectas(CString& mensaje);  // Devuelve true si las propiedades obligatorias del bloque están bien definidas

	virtual void setFich( CString& fich );    // Se llama desde el hijo cuando el éste se salva para dar el nombre de fichero dex último guardado.

	virtual void CargaSubdiagrama();	
	virtual void CerrarSubdiagrama(BOOL cerradoAuto);


	virtual CString getEtiqDiagHijo();

// Variables
public:
    CBaseDoc* p_docHijo;

	BOOL m_esLDD;
	CString m_fichDiag;  // Contiene el nombre del LDD del diagrama hijo.
    
	static CString S_TIPO_DIAG; 

protected:
    CString m_bloqIni; // Identificador interno del bloque del diagrama hijo que se conecta como inicial.
    CString m_bloqFin; // Idem bloque final.

	CBloque* p_bloqIni;    // Bloque inicio del diagrama hijo.
    CBloque* p_bloqFin;    // Idem final

};

#endif // !defined(AFX_BLOQUEDIAG_H__93C19994_1591_4319_B2F5_F343F12750BA__INCLUDED_)
