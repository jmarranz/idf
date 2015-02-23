// Instante.h: interface for the Instante class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INSTANTE_H__F1A9867C_DC47_4BB4_BE2A_73633D2D1631__INCLUDED_)
#define AFX_INSTANTE_H__F1A9867C_DC47_4BB4_BE2A_73633D2D1631__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Instante : public CObject  
{
public:
	Instante();
	Instante(const Instante& t);
	Instante(const CTime& seg);
	Instante(const CTime& seg, int miliseg);
	virtual ~Instante();
	
	void Iniciar();

	void Serialize(CArchive& ar);

	CTime getSegundos() const;
	int getMiliseg() const;

	void set(const Instante& t);
	void set(const CTime& seg, int miliseg);

	int Compara(const Instante& t);
	CString ConvertirAString();

private:
	CTime m_segundos; 
	int m_miliseg; 
};

#endif // !defined(AFX_INSTANTE_H__F1A9867C_DC47_4BB4_BE2A_73633D2D1631__INCLUDED_)
