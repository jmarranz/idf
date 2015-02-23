// ComSerial.h: interface for the CComSerial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMSERIAL_H__C4307E08_A73F_4D96_B991_F76533B46C9D__INCLUDED_)
#define AFX_COMSERIAL_H__C4307E08_A73F_4D96_B991_F76533B46C9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Com.h"

class CComSerial : public CCom  
{
public:
	DECLARAR_COMUNICACION(CComSerial)

	CComSerial();
	virtual ~CComSerial();

	virtual void GuardarDatos(CArchive& ar);
	virtual void LeerDatos(CArchive& ar);

	virtual void PrepararParaRecibirDatos();
	virtual void PostRecibirDatos();
	virtual void PrepararParaDevolverDatos();
	virtual void PostDevolverDatos();



	CArchive& getArchive();

	void Liberar(BOOL liberarBuffer);

protected:
	CMemFile* p_f;
	CArchive* p_ar;

	UINT m_len;
	BYTE* p_buff;
};

#endif // !defined(AFX_COMSERIAL_H__C4307E08_A73F_4D96_B991_F76533B46C9D__INCLUDED_)
