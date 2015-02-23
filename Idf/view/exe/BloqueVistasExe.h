// BloqueVistasExe.h: interface for the CBloqueVistasExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASEXE_H__585A1D1F_C5BE_44EF_B4D1_04DCCBC39668__INCLUDED_)
#define AFX_BLOQUEVISTASEXE_H__585A1D1F_C5BE_44EF_B4D1_04DCCBC39668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\view\BloqueVistasModo.h"

class CBloqueVistasExe;
class CBaseView;


class CBloqueVistasExe : public CBloqueVistasModo  
{
public:
	CBloqueVistasExe();
	virtual ~CBloqueVistasExe();

	virtual void CentrarBloque(CBaseView* view);   // Sitúa la ventana tal que el bloque esté en el centro de la pantalla

	virtual void DlgOperaciones();
};

#endif // !defined(AFX_BLOQUEVISTASEXE_H__585A1D1F_C5BE_44EF_B4D1_04DCCBC39668__INCLUDED_)
