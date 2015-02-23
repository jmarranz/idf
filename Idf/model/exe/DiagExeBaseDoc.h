// DiagExeBaseDoc.h : interface of the CDiagExeBaseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef CDIAGEXEBASEDOC
#define CDIAGEXEBASEDOC

#include "..\BaseDoc.h"

class CDiagExe;
class CBaseView;
class CDiagSrvrItem;

// Se implementa todo lo que no tiene que ver directamente con OLE (servidor), 
// La parte OLE está en la clase CDiagExeDoc 


class CDiagExeBaseDoc : public CBaseDoc
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CDiagExeBaseDoc)

// Attributes
public:

// Operations
public:

// Implementation
public:
	CDiagExeBaseDoc();
	virtual ~CDiagExeBaseDoc();

	CDiagExe* getDiag()	// No hacerla virtual 
	{
    	return (CDiagExe*)p_diag;
	}

	virtual CDiagBase* CrearObjDiag();

	virtual void Serialize(CArchive& ar);	// overridden for document i/o


#ifdef _DEBUG
	virtual	void AssertValid() const;
	virtual	void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CDiagExeBaseDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
	// Variables:
public:
	// Variables a fichero
	
	// Variables temporales:
	

};

#endif

/////////////////////////////////////////////////////////////////////////////
