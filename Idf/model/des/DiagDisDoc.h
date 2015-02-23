// diagdoc.h : interface of the CDiagDisDoc class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef CDIAGDISDOC
#define CDIAGDISDOC

#include "..\BaseDoc.h"

class CDiagDis;

class CDiagDisDoc : public CBaseDoc
{
protected: // create from serialization only
	CDiagDisDoc();
	DECLARE_DYNCREATE(CDiagDisDoc)

// Attributes
public:
// Operations

public:

// Implementation
public:
	virtual ~CDiagDisDoc();

	CDiagDis* getDiag()	// No hacerla virtual 
	{
    	return (CDiagDis*)p_diag;
	}

	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	virtual CDiagBase* CrearObjDiag();


#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// Generated message map functions
protected:
	//{{AFX_MSG(CDiagDisDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Variables
public:
	
};

#endif


/////////////////////////////////////////////////////////////////////////////
