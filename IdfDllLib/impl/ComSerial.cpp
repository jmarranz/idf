// ComSerial.cpp: implementation of the CComSerial class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IdfDllApp.h"
#include "ComSerial.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENTAR_COMUNICACION(CComSerial, CCom,1)

/* Nota: el proceso de liberación de memoria es más complicado de
lo normal porque hay un memory leak que no consigo detectar */

CComSerial::CComSerial()
{
	p_f = NULL;
	p_ar = NULL;
	p_buff = NULL;
}

CComSerial::~CComSerial()
{
	Liberar(true);
}

CArchive& CComSerial::getArchive()
{
	return *p_ar;
}

void CComSerial::Liberar(BOOL liberarBuffer)
{
	if (p_f != NULL)
	{
		p_ar->Flush();
		p_f->Flush();
		p_ar->Close();
		// p_f->Close();

		m_len = p_f->GetLength();
		p_buff = p_f->Detach();

		delete p_ar;
		delete p_f;
		
		p_ar = NULL;
		p_f = NULL;
	}

	if (liberarBuffer && (p_buff != NULL)) 
	{
		free(p_buff);
		p_buff = NULL;
	}
}

void CComSerial::PrepararParaRecibirDatos()
{
	Liberar(true);

	p_f = new CMemFile();
	p_ar = new CArchive(p_f, CArchive::store);
}

void CComSerial::PostRecibirDatos()
{
	Liberar(false);
}

void CComSerial::PrepararParaDevolverDatos()
{
	p_f = new CMemFile(p_buff,m_len);
	p_ar = new CArchive(p_f, CArchive::load);
}

void CComSerial::PostDevolverDatos()
{
	Liberar(true);
}

void CComSerial::GuardarDatos(CArchive& ar)
{
	ar << m_len;

	ar.Write(p_buff,m_len);
	ar.Flush();
}

void CComSerial::LeerDatos(CArchive& ar)
{
	ar >> m_len;

	p_buff = new byte[m_len];
	ar.Read(p_buff,m_len);
}

