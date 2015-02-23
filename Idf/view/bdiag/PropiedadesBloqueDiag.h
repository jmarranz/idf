// PropiedadesBloqueDiag.h: interface for the CPropiedadesBloqueDiag class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPIEDADESBLOQUEDIAG_H__1D6B01BD_EA6D_49C3_95DC_88D7BAECEC4D__INCLUDED_)
#define AFX_PROPIEDADESBLOQUEDIAG_H__1D6B01BD_EA6D_49C3_95DC_88D7BAECEC4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "..\PropiedadesBloque.h"


class CPropiedadesBloqueDiag : public CPropiedadesBloque  
{
public:
	CPropiedadesBloqueDiag(CBloque* pblq,UINT pagina);
	virtual ~CPropiedadesBloqueDiag();

	virtual CPropertyPage* PropEspecificas(CPropertyPage* pdlg) throw (BloqueException);
};

#endif // !defined(AFX_PROPIEDADESBLOQUEDIAG_H__1D6B01BD_EA6D_49C3_95DC_88D7BAECEC4D__INCLUDED_)
