

// CAnalisisClasesConDLL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnalisisClasesConDLL 

#include "DLLDiagrama.h"
#include "AnalisisClasesDLL.h"

class CInfoBloque;
class CInfoCom;
class CInfoComES;

class CAnalisisClasesConDLL : public CAnalisisClasesDLL
{
public:
	// Según porqué constructor se entre, funcionará en el modo de acceso
	// a DLL o en el modo de acceso al diagrama en memoria.
	
	CAnalisisClasesConDLL(CDiagBase* pdiag,const CString& DLLDiag);  // Modo de Acceso al DLL
	~CAnalisisClasesConDLL();

	const CString& getDLLDiag()
	{
		return m_DLLDiag;
	}

	virtual void Construir();

	virtual BOOL ConDLL() { return true; }

	void EnlazarConectores();
	void EnlazarBloques(CMapStringToPtr& lista,int tipo);
	void EnlazaListaComES(CInfoBloque* pdatos,int tipo);

	virtual BOOL EsValido();

private:
	CString m_DLLDiag;

	// Enlace con el DLL
	CDLLDiagrama m_DLLDiagrama;

	POSITION  (*pPrimerBloquePos)(int tipo);
	void  (*pSiguienteBloque)(POSITION& pos,int tipo, const char*& clase,const char*& claseBase,const char*& verSerial);

	POSITION  (*pPrimerComPos)();
	void  (*pSiguienteCom)(POSITION& pos,const char*& clase,const char*& claseBase,const char*& verSerial);

	BOOL (*pBuscarComES)(const char* clave,int tipo,const char*& clase,const char*& claseBloque);
};

