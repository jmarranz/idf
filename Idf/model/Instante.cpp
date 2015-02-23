// Instante.cpp: implementation of the Instante class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "Instante.h"

#include <time.h>
#include <sys/timeb.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Instante::Instante()
{
	Iniciar();
}

Instante::Instante(const Instante& t)
{
	set(t);
}

Instante::Instante(const CTime& seg)
{
	set(seg,0);
}

Instante::Instante(const CTime& seg, int miliseg)
{
	set(seg,miliseg);
}


Instante::~Instante()
{

}

void Instante::Iniciar()
{
	m_segundos = CTime::GetCurrentTime();

   struct _timeb timebuffer;

   _ftime( &timebuffer );
	
	m_miliseg = timebuffer.millitm;
}

CTime Instante::getSegundos() const
{
	return m_segundos;
}

int Instante::getMiliseg() const
{
	return m_miliseg;
}

void Instante::set(const Instante& t)
{
	m_segundos = t.getSegundos();
	m_miliseg = t.getMiliseg();
}

void Instante::set(const CTime& seg, int miliseg)
{
	m_segundos = seg;
	m_miliseg = miliseg;
}

void Instante::Serialize(CArchive& ar) 
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
	    ar << m_segundos;
		ar << m_miliseg;
	}
	else
	{
        ar >> m_segundos;  
		ar >> m_miliseg;
	}	
}

int Instante::Compara(const Instante& t)
{
	if (m_segundos > t.getSegundos()) return 1; // Mayor
	else if (m_segundos < t.getSegundos()) return -1; // Menor
	else if (m_miliseg == t.getMiliseg()) return 0; // Igual 
		 else if (m_miliseg > t.getMiliseg()) return 1; // Mayor
		 else return -1; // Menor
}

CString Instante::ConvertirAString()
{
	// CAMBIAR por CTime::Format()

	time_t t = m_segundos.GetTime();
	CString Fecha = (CString) ctime( &t );  
	Fecha.SetAt(Fecha.GetLength()-1,' ');  // Quitamos un \n molesto por un espacio.
	//char buffer[20];
	//sprintf(buffer,"%d",m_miliseg);
	//Fecha += buffer;
	return Fecha;
}
