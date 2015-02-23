
#include "stdafx.h"
#include "IdfDllApp.h"

#include "Com_enlaces.h"

#include <afxadv.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Enlazadas con CConectExe


BYTE*   _Com_SerializarGuardadoObjCom(CCom * pCom,DWORD& len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	TRY
	{
		CSharedFile f;

		CArchive ar(&f, CArchive::store);			

		pCom->Serialize(ar);

		ar.Flush();
		f.Flush();
		ar.Close();

		len = f.GetLength();
		BYTE* buff = (BYTE*)f.Detach();  

		return buff;
    }
	CATCH_ALL(e)
	{
        // No cerrar, pues lo hará la aplicación padre.
		return NULL; // Para indicar que se arroje una excepción en la aplicación padre.	
	}
	END_CATCH_ALL
}


BOOL   _Com_SerializarCargaObjCom(BYTE* buff,DWORD len,CCom* pCom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	TRY
	{
		CSharedFile f;
		f.SetHandle(buff);

		CArchive ar(&f, CArchive::load);			

		pCom->Serialize(ar);

		ar.Flush();
		f.Flush();
		ar.Close();

		f.Close();
		// buff = (BYTE*)f.Detach();  

		GlobalFree(buff);

		return true;
    }
	CATCH_ALL(e)
	{
        // No cerrar, pues lo hará la aplicación padre.
		return false; // Para indicar que se arroje una excepción en la aplicación padre.	
	}
	END_CATCH_ALL
}


void    _Com_DestObjDatosCom( CCom * pECCom )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	// Destruye objetos de comunicación temporales.
	delete pECCom;
}


