// DibDiagramaExe.h: interface for the CDibDiagramaExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBDIAGRAMAEXE_H__A29C0B94_BEA0_4D6B_9509_97BF4BA34ACE__INCLUDED_)
#define AFX_DIBDIAGRAMAEXE_H__A29C0B94_BEA0_4D6B_9509_97BF4BA34ACE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\DibDiagrama.h"

class CDiagExe;
class CBloque;


class CDibDiagramaExe : public CDibDiagrama  
{
public:
	CDibDiagramaExe();
	virtual ~CDibDiagramaExe();

	CDiagExe* getDiag()
	{
		return (CDiagExe*)p_diag;
	}

	virtual void Dibujar(CDC* pDC, CBaseView* view);
	void CentrarBloque(CBloque* pbloque,CBaseView* view);
};

#endif // !defined(AFX_DIBDIAGRAMAEXE_H__A29C0B94_BEA0_4D6B_9509_97BF4BA34ACE__INCLUDED_)
