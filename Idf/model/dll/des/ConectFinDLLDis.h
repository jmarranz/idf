// ConectFinDLLDis.h: interface for the CConectFinDLLDis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTFINDLLDIS_H__6AF82E2F_9A7A_450D_988D_3CD85B98475B__INCLUDED_)
#define AFX_CONECTFINDLLDIS_H__6AF82E2F_9A7A_450D_988D_3CD85B98475B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\DES\ConectFinDis.h"
#include "ConectExtremoDLLDis.h"


class CConectFinDLLDis : public CConectFinDis,CConectExtremoDLLDis  
{
public:
	CConectFinDLLDis();
	virtual ~CConectFinDLLDis();

};

#endif // !defined(AFX_CONECTFINDLLDIS_H__6AF82E2F_9A7A_450D_988D_3CD85B98475B__INCLUDED_)
