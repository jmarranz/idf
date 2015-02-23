// Rejilla.h: interface for the CRejilla class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REJILLA_H__56D58E61_D8A5_433E_B06E_58CC2D1E2805__INCLUDED_)
#define AFX_REJILLA_H__56D58E61_D8A5_433E_B06E_58CC2D1E2805__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDibDiagramaDis;
class CBaseView;

class CRejilla : public CObject  
{
public:
	CRejilla();
	virtual ~CRejilla();

	void setDibDiagrama(CDibDiagramaDis* pdigDiag);

	virtual void Serialize(CArchive& ar);

	virtual void Dibujar(CDC* pDC, CBaseView* view);

	virtual CPoint AdaptarPtoRejilla(const CPoint& pto);	

public:
	CDibDiagramaDis* p_dibDiag;

    BOOL m_forzCoor; // Forzar coordenadas a la rejilla
    BOOL m_verRejilla; // Ver rejilla.
	UINT m_incX;  // Rejilla inc. de X	
	UINT m_incY;  // Rejilla inc. de Y	
};

#endif // !defined(AFX_REJILLA_H__56D58E61_D8A5_433E_B06E_58CC2D1E2805__INCLUDED_)
