// XMLUtil.h: interface for the XMLUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLUTIL_H__07D7B86A_AB19_4838_8AB0_5857C94CD524__INCLUDED_)
#define AFX_XMLUTIL_H__07D7B86A_AB19_4838_8AB0_5857C94CD524__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <xercesc/dom/DOM.hpp>


class XStr
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    XStr(const char* const toTranscode);
    ~XStr();

    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    const XMLCh* unicodeForm() const;

private:
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fUnicodeForm
    //      This is the Unicode XMLCh format of the string.
    // -----------------------------------------------------------------------
    XMLCh*   fUnicodeForm;
};

#define X(str) XStr(str).unicodeForm()

class DOMDocument;

class XMLUtil  
{
public:
	XMLUtil();
	virtual ~XMLUtil();

	static void Iniciar();
	static void Liberar();

	static DOMDocument* CrearDocumento(const char* root);
	static DOMDocument* CargarDocumento(const char* gXMLFile);
	static void SerializarDocumento(DOMDocument* doc,const char* archivo);

	static void LiberarDocumento(DOMDocument* doc);

	static DOMTreeWalker* crearWalker(DOMNode* nodo);

	static CString convert(const XMLCh* buff);

	static DOMElement* appendElement(DOMElement* parent,const char* tagName);

	static CString getTexto(DOMElement* pElem);
	static void setTexto(DOMElement* pElem,const char* valor);
	static int getEntero(DOMElement* pElem);
	static void setEntero(DOMElement* pElem,int valor);
	static BOOL getBoolean(DOMElement* pElem);
	static void setBoolean(DOMElement* pElem,BOOL valor);

	static CString getAttrTexto(DOMElement* pElem,const char* nombre,const char* def = "");
	static void setAttrTexto(DOMElement* pElem,const char* nombre,const char* valor);
	static int getAttrEntero(DOMElement* pElem,const char* nombre,int def = 0);
	static void setAttrEntero(DOMElement* pElem,const char* nombre,int valor);
	static BOOL getAttrBoolean(DOMElement* pElem,const char* nombre,BOOL def = false);
	static void setAttrBoolean(DOMElement* pElem,const char* nombre,BOOL valor);

protected: // Interno
	static void Embellecer(DOMNode* nodo,const CString& tabs = "");

protected:
	static CMapPtrToPtr m_parsers;
};

#endif // !defined(AFX_XMLUTIL_H__07D7B86A_AB19_4838_8AB0_5857C94CD524__INCLUDED_)
