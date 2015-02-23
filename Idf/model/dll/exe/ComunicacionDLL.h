// ComunicacionDLL.h: interface for the CComunicacionDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMUNICACIONDLL_H__FAAD511E_5645_4ADB_B927_B57F46C663D2__INCLUDED_)
#define AFX_COMUNICACIONDLL_H__FAAD511E_5645_4ADB_B927_B57F46C663D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\exe\Comunicacion.h"

class CComunicacionDLL : public CComunicacion  
{
public:
	CComunicacionDLL(void* pcom);
	CComunicacionDLL(void* pcom,Instante t);
	virtual ~CComunicacionDLL();

	void* getObjComDLL() { return p_comDLL; }
	void setObjComDLL(void* pcomdll) { p_comDLL = pcomdll; }

public:
	void* p_comDLL;

	DWORD m_len;
	BYTE* m_buff;
};

#endif // !defined(AFX_COMUNICACIONDLL_H__FAAD511E_5645_4ADB_B927_B57F46C663D2__INCLUDED_)
