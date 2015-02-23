// XMLUtil.cpp: implementation of the XMLUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XMLUtil.h"

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/util/PlatformUtils.hpp>


#include "DOMTreeErrorReporter.h"
#include "DOMPrintErrorHandler.h"


XStr::XStr(const char* const toTranscode)
{
    // Call the private transcoding method
    fUnicodeForm = XMLString::transcode(toTranscode);
}

XStr::~XStr()
{
    //delete [] fUnicodeForm;
	// delete fUnicodeForm;
}

const XMLCh* XStr::unicodeForm() const
{
    return fUnicodeForm;
}

////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMapPtrToPtr XMLUtil::m_parsers;

XMLUtil::XMLUtil()
{

}

XMLUtil::~XMLUtil()
{

}

void XMLUtil::Iniciar()
{
	XMLPlatformUtils::Initialize();
}

void XMLUtil::Liberar()
{
	XMLPlatformUtils::Terminate();
}

CString XMLUtil::convert(const XMLCh* buff)
{
	char* cadena = XMLString::transcode(buff);
	return cadena;
}

CString XMLUtil::getTexto(DOMElement* pElem)
{
	DOMText* pTexto = (DOMText*)pElem->getFirstChild();
	if (pTexto == NULL) return "";
	return XMLString::transcode(pTexto->getData());
}

void XMLUtil::setTexto(DOMElement* pElem,const char* valor)
{
	DOMText* nodoTexto = pElem->getOwnerDocument()->createTextNode(X(valor));
	pElem->appendChild(nodoTexto);
}

int XMLUtil::getEntero(DOMElement* pElem)
{
	DOMText* pTexto = (DOMText*)pElem->getFirstChild();
	if (pTexto == NULL) return 0;
	char* cadena = XMLString::transcode(pTexto->getData());
	return atoi(cadena);
}

void XMLUtil::setEntero(DOMElement* pElem,int valor)
{
	char buffer[40];
	itoa(valor,buffer,10);
	DOMText* nodoTexto = pElem->getOwnerDocument()->createTextNode(X(buffer));
	pElem->appendChild(nodoTexto);
}

BOOL XMLUtil::getBoolean(DOMElement* pElem)
{
	DOMText* pTexto = (DOMText*)pElem->getFirstChild();
	if (pTexto == NULL) return false;
	CString cadena = XMLString::transcode(pTexto->getData());
	if (cadena == "true") return true;
	else return false;
}

void XMLUtil::setBoolean(DOMElement* pElem,BOOL valor)
{
	CString svalor;
	if (valor) svalor = "true";
	else svalor = "false";
	DOMText* nodoTexto = pElem->getOwnerDocument()->createTextNode(X(svalor));
	pElem->appendChild(nodoTexto);
}

CString XMLUtil::getAttrTexto(DOMElement* pElem,const char* nombre,const char* def)
{
	DOMAttr* pAttr = pElem->getAttributeNode(X(nombre));
	if (pAttr == NULL) return def;
	char* cadena = XMLString::transcode(pAttr->getValue());
	return cadena;
}

void XMLUtil::setAttrTexto(DOMElement* pElem,const char* nombre,const char* valor)
{
	pElem->setAttribute(X(nombre),X(valor));
}

int XMLUtil::getAttrEntero(DOMElement* pElem,const char* nombre,int def)
{
	DOMAttr* pAttr = pElem->getAttributeNode(X(nombre));
	if (pAttr == NULL) return def;
	char* cadena = XMLString::transcode(pAttr->getValue());
	return atoi(cadena);
}

void XMLUtil::setAttrEntero(DOMElement* pElem,const char* nombre,int valor)
{
	char buffer[40];
	itoa(valor,buffer,10);
	pElem->setAttribute(X(nombre),X(buffer));
}

BOOL XMLUtil::getAttrBoolean(DOMElement* pElem,const char* nombre,BOOL def)
{
	DOMAttr* pAttr = pElem->getAttributeNode(X(nombre));
	if (pAttr == NULL) return def;
	CString cadena = XMLString::transcode(pAttr->getValue());
	if (cadena == "true") return true;
	return false;
}

void XMLUtil::setAttrBoolean(DOMElement* pElem,const char* nombre,BOOL valor)
{
	CString svalor;
	if (valor) svalor = "true";
	else svalor = "false";
	pElem->setAttribute(X(nombre),X(svalor));
}

DOMDocument* XMLUtil::CrearDocumento(const char* root)
{
    DOMImplementation* impl =  DOMImplementationRegistry::getDOMImplementation(X("Core"));

    DOMDocument* doc = impl->createDocument(
                NULL,            // root element namespace URI.
                X(root),         // root element name
                NULL);           // document type object (DTD).
	//doc->setEncoding(X("iso-8859-1")); // DOM-3 puede cambiar
	return doc;
}


void XMLUtil::LiberarDocumento(DOMDocument* doc)
{
	XercesDOMParser* parser = NULL;

	if (m_parsers.Lookup(doc,(void*&)parser))
	{
		delete parser;
		m_parsers.RemoveKey(doc);
	}
	else doc->release();
}

DOMDocument* XMLUtil::CargarDocumento(const char* gXmlFile)
{
	static bool                     gDoNamespaces          = false;
	static bool                     gDoSchema              = false;
	static bool                     gSchemaFullChecking    = false;
	static bool                     gDoCreate              = true;

	static XercesDOMParser::ValSchemes    gValScheme       = XercesDOMParser::Val_Auto;
   
	
	XercesDOMParser *parser = new XercesDOMParser;

    parser->setValidationScheme(gValScheme);
    parser->setDoNamespaces(gDoNamespaces);
    parser->setDoSchema(gDoSchema);
    parser->setValidationSchemaFullChecking(gSchemaFullChecking);
    parser->setCreateEntityReferenceNodes(gDoCreate);

    DOMTreeErrorReporter *errReporter = new DOMTreeErrorReporter();
    parser->setErrorHandler(errReporter);

    BOOL errorsOccured = false;
    try
    {
        parser->parse(gXmlFile);
    }
    catch (const XMLException& e)
    {
        std::cerr << "An error occurred during parsing\n   Message: "
             << StrX(e.getMessage()) << std::endl;
        errorsOccured = true;
    }
    catch (const DOMException& e)
    {
       std::cerr << "A DOM error occurred during parsing\n   DOMException code: "
             << e.code << std::endl;
        errorsOccured = true;
    }
    catch (...)
    {
        std::cerr << "An error occurred during parsing\n " << std::endl;
        errorsOccured = true;
    }

	DOMDocument* doc = NULL;

    // If the parse was successful, output the document data from the DOM tree
    if (!errorsOccured && !errReporter->getSawErrors())
	{
		doc = parser->getDocument();
		m_parsers.SetAt(doc,parser);
	}

    //delete parser;
	delete errReporter;

	return doc;
}


void XMLUtil::SerializarDocumento(DOMDocument* doc,const char* archivo)
{
	// options for DOMWriter's features
	static const XMLCh*   gOutputEncoding        = XMLString::transcode("iso-8859-1");
	static const XMLCh*   gMyEOLSequence         = XMLString::transcode("\r\n");

	static bool           gSplitCdataSections    = true;
	static bool           gDiscardDefaultContent = true;
	// static bool           gUseFilter             = false;
	static bool           gFormatPrettyPrint     = true;


    try
    {
		// get a serializer, an instance of DOMWriter
		XMLCh tempStr[100];
		XMLString::transcode("LS", tempStr, 99);
		DOMImplementation *impl          = DOMImplementationRegistry::getDOMImplementation(tempStr);
		DOMWriter         *theSerializer = ((DOMImplementationLS*)impl)->createDOMWriter();

		// set user specified end of line sequence and output encoding
		theSerializer->setNewLine(gMyEOLSequence);
		theSerializer->setEncoding(gOutputEncoding);

		// plug in user's own error handler
		DOMErrorHandler *myErrorHandler = new DOMPrintErrorHandler();
		theSerializer->setErrorHandler(myErrorHandler);

		// set feature if the serializer supports the feature/mode
		if (theSerializer->canSetFeature(XMLUni::fgDOMWRTSplitCdataSections, gSplitCdataSections))
			theSerializer->setFeature(XMLUni::fgDOMWRTSplitCdataSections, gSplitCdataSections);
		
		if (theSerializer->canSetFeature(XMLUni::fgDOMWRTDiscardDefaultContent, gDiscardDefaultContent))
			theSerializer->setFeature(XMLUni::fgDOMWRTDiscardDefaultContent, gDiscardDefaultContent);

		if (theSerializer->canSetFeature(XMLUni::fgDOMWRTFormatPrettyPrint, gFormatPrettyPrint))
			theSerializer->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, gFormatPrettyPrint);

		//
		// Plug in a format target to receive the resultant
		// XML stream from the serializer.
        //
		// StdOutFormatTarget prints the resultant XML stream
		// to stdout once it receives any thing from the serializer.
		//
		XMLFormatTarget *myFormTarget = new LocalFileFormatTarget(archivo);

		Embellecer(doc); // Es por culpa del pretty-print que no funciona bien
		//
		// do the serialization through DOMWriter::writeNode();
		//
		theSerializer->writeNode(myFormTarget,*doc);


		delete theSerializer;

        //
		// Filter, formatTarget and error handler
		// are NOT owned by the serializer.
		//
		delete myFormTarget;

		delete myErrorHandler;
	

    }
    catch (XMLException& e)
    {
        std::cerr << "An error occurred during creation of output transcoder. Msg is:"
            << std::endl
            << StrX(e.getMessage()) << std::endl;
    }

}

DOMTreeWalker* XMLUtil::crearWalker(DOMNode* nodo)
{
	return nodo->getOwnerDocument()->createTreeWalker(nodo,DOMNodeFilter::SHOW_ELEMENT,NULL,true);
}

void XMLUtil::Embellecer(DOMNode* nodo, const CString& tabs)
{
	if (nodo->getNodeType() == DOMNode::ELEMENT_NODE)
	{
		DOMNode* parent = nodo->getParentNode();
		if (parent != NULL)
		{
			if (parent->getNodeType() != DOMNode::DOCUMENT_NODE) 
			{
				DOMText* sep = nodo->getOwnerDocument()->createTextNode(X("\r\n" + tabs));
				parent->insertBefore(sep,nodo);
			}
		}
	}
    
	CString nuevoTabs = tabs + "  ";

	DOMNode *child = nodo->getFirstChild();
	DOMNode *childUltimo = child;
    while( child != NULL )
    {
        Embellecer(child,nuevoTabs);
        child = child->getNextSibling();
		if (child != NULL) childUltimo = child;
    }

	if ((childUltimo != NULL) && (childUltimo->getNodeType() == DOMNode::ELEMENT_NODE))
	{
		if (nodo->getNodeType() != DOMNode::DOCUMENT_NODE) 
		{
			DOMText* sep = nodo->getOwnerDocument()->createTextNode(X("\r\n" + tabs));
			nodo->appendChild(sep);
		}
	}

}

DOMElement* XMLUtil::appendElement(DOMElement* parent,const char* tagName)
{
	DOMDocument* pdoc = parent->getOwnerDocument();
	DOMElement* elem = pdoc->createElement(X(tagName));
	parent->appendChild(elem);
	return elem;
}



