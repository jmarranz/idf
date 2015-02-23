// RGB.cpp: implementation of the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "Rgb.h"

// En vez de incluir el d3dtypes.h del Direct3D copiamos la macros y punto 
// ftp://ftp.physik.hu-berlin.de/pub/useful/dx7asdk/DXF/include/d3dtypes.h
// #include "d3dtypes.h"
#define RGB_GETRED(rgb)         (((rgb) >> 16) & 0xff)
#define RGB_GETGREEN(rgb)       (((rgb) >> 8) & 0xff)
#define RGB_GETBLUE(rgb)        ((rgb) & 0xff)


#include "..\xmlutil\XMLUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void operator << (CArchive& ar,CRgb& rgb)
{
	ar << rgb.getColor();
}

void operator >> (CArchive& ar,CRgb& rgb)
{
	COLORREF color;
	ar >> color;

	rgb = color;
}


CRgb::CRgb()
{
	m_color = RGB(0,0,0);
}

CRgb::~CRgb()
{

}

COLORREF CRgb::getColor()
{
	return m_color;
}

CRgb& CRgb::operator = (COLORREF color)
{
	m_color = color;
	return *this;
}


void CRgb::LeerDatosLDD(DOMElement* rgbEtiq)
{
	DOMTreeWalker* walker = XMLUtil::crearWalker(rgbEtiq);

	DOMElement* red = (DOMElement*)walker->firstChild();
	int redVal = XMLUtil::getEntero(red);

	DOMElement* green = (DOMElement*)walker->nextSibling();
	int greenVal = XMLUtil::getEntero(red);

	DOMElement* blue = (DOMElement*)walker->nextSibling();
	int blueVal = XMLUtil::getEntero(blue);

	m_color = RGB(redVal,greenVal,blueVal);
}

void CRgb::EscribirDatosLDD(DOMElement* rgbEtiq)
{
	DOMElement* red = XMLUtil::appendElement(rgbEtiq,"red");
	XMLUtil::setEntero(red,RGB_GETRED(m_color));

	DOMElement* green = XMLUtil::appendElement(rgbEtiq,"green");
	XMLUtil::setEntero(green,RGB_GETGREEN(m_color));	

	DOMElement* blue = XMLUtil::appendElement(rgbEtiq,"blue");
	XMLUtil::setEntero(blue,RGB_GETBLUE(m_color));	
}
