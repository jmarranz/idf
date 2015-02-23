// ConectExtremoExe.h: interface for the CConectExtremoExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTEXTREMOEXE_H__B08E58D4_37E0_4D3D_894F_7CCEF7E0150C__INCLUDED_)
#define AFX_CONECTEXTREMOEXE_H__B08E58D4_37E0_4D3D_894F_7CCEF7E0150C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ConectExtremoModo.h"

class CConectExtremoExe : public CConectExtremoModo  
{
public:
	CConectExtremoExe();
	virtual ~CConectExtremoExe();

	virtual void ConexyTestBloque() = 0; // Testea si son compatibles los bloques conectados en DLLs y enlaza lo referente a la comunicación
};

#endif // !defined(AFX_CONECTEXTREMOEXE_H__B08E58D4_37E0_4D3D_894F_7CCEF7E0150C__INCLUDED_)
