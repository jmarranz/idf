// BloqueDLL.h: interface for the CBloqueDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEDLL_H__FBE564B3_6926_47BE_846F_FEA2AC88C23A__INCLUDED_)
#define AFX_BLOQUEDLL_H__FBE564B3_6926_47BE_846F_FEA2AC88C23A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\BloqueUnidad.h"

class CBloqueDLLDis;
class CBloqueDLLExe;
class CBloqueDLLVistas;


class CBloqueDLL : public CBloqueUnidad 
{
	DECLARE_SERIAL(CBloqueDLL)
public:
	CBloqueDLL();
	virtual ~CBloqueDLL();

	virtual void Construir(CDiagBase* p);

	virtual const char* getTipo() 
	{ 
		return S_TIPO_DLL; 
	}

	virtual CComponenteDiagVistas* CrearObjVistas();

	CBloqueDLLVistas* getVistas()
	{
		return (CBloqueDLLVistas*)p_vistas;
	}

	CBloqueDLLExe* getExe()
	{
		return (CBloqueDLLExe*)p_modo;
	}

	CBloqueDLLDis* getDis()
	{
		return (CBloqueDLLDis*)p_modo;
	}

	// Redefinidas de CBloque:
	
	virtual void LeerDatosLDD(DOMElement* bloque,DOMTreeWalker* walker);
	virtual void EscribirDatosLDD(DOMElement* bloque);	
	virtual void Serialize(CArchive& ar);

	virtual BOOL EsBloqueDLL() { return true; }

	virtual CString& getMacro();
	virtual void setMacro( const CString& macro );  

	virtual BOOL PropiedadesCorrectas(CString& mensaje);  // Devuelve true si las propiedades obligatorias del bloque están bien definidas

	virtual void setDLLBloque(const CString& dllbloque);
	virtual CString getDLLBloque();

	virtual BOOL getUsaDLLDiag();


	// Variables que se guardan en fichero

	// Útiles sólo en tiempo de creación nuevo y carga de fichero:
public:
	static CString S_TIPO_DLL; 

	CString m_macro;

	CString m_claseDatosBloque;   // Clase derivada de la clase CBloqueFunc que usa el bloque. 


protected:
	CString m_DLLBloque;        // Nombre del DLL del diagrama o del propio del bloque si tiene.
    BOOL m_usaDLLDiag;          // true si no tiene DLL propio el bloque.

};

#endif // !defined(AFX_BLOQUEDLL_H__FBE564B3_6926_47BE_846F_FEA2AC88C23A__INCLUDED_)
