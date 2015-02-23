// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__2C27D0FB_2414_4A51_988D_9595D48BB135__INCLUDED_)
#define AFX_RGB_H__2C27D0FB_2414_4A51_988D_9595D48BB135__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DOMElement;

class CRgb  
{
public:
	CRgb();
	virtual ~CRgb();

	CRgb& operator = (COLORREF color);
	COLORREF getColor();
	virtual void LeerDatosLDD(DOMElement* vistas);
	virtual void EscribirDatosLDD(DOMElement* vistas);

private:
	COLORREF m_color;
};

void operator << (CArchive& ar,CRgb& rgb);
void operator >> (CArchive& ar,CRgb& rgb);


#endif // !defined(AFX_RGB_H__2C27D0FB_2414_4A51_988D_9595D48BB135__INCLUDED_)
