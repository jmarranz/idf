// PropiedadesBloqueDLL.h: interface for the CPropiedadesBloqueDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPIEDADESBLOQUEDLL_H__4C2EC8E2_21D8_4558_A37C_67B99480C327__INCLUDED_)
#define AFX_PROPIEDADESBLOQUEDLL_H__4C2EC8E2_21D8_4558_A37C_67B99480C327__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\PropiedadesBloque.h"


class CPropiedadesBloqueDLL : public CPropiedadesBloque
{
public:
	CPropiedadesBloqueDLL(CBloque* pblq,UINT pagina);
	virtual ~CPropiedadesBloqueDLL();

	virtual CPropertyPage* PropEspecificas(CPropertyPage* pdlg) throw (BloqueException);
};

#endif // !defined(AFX_PROPIEDADESBLOQUEDLL_H__4C2EC8E2_21D8_4558_A37C_67B99480C327__INCLUDED_)
