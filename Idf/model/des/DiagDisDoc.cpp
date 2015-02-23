// diagdoc.cpp : implementation of the CDiagDisDoc class
//

#include "stdafx.h"
#include "..\..\Idf.h"
#include "DiagDisDoc.h"

#include "DiagDis.h"


/////////////////////////////////////////////////////////////////////////////
// CDiagDisDoc

IMPLEMENT_DYNCREATE(CDiagDisDoc, CBaseDoc)

BEGIN_MESSAGE_MAP(CDiagDisDoc, CBaseDoc)
	//{{AFX_MSG_MAP(CDiagDisDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagDisDoc construction/destruction



CDiagDisDoc::CDiagDisDoc()
{
}

CDiagDisDoc::~CDiagDisDoc()
{

}


/////////////////////////////////////////////////////////////////////////////
// CDiagDisDoc serialization

void CDiagDisDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		CBaseDoc::Serialize(ar);

		p_diag->Serialize(ar);	
	}
	else
	{
		// TODO: add loading code here
		TRY
		{
			CBaseDoc::Serialize(ar);

			p_diag = CrearObjDiag();
			p_diag->Serialize(ar);  // Aquí dentro también se producen aserciones
		}		
		CATCH_ALL(e)
		{		
			DestruirDiag();  // Idem que se hace en DeleteContents pero es necesario hacerlo aquí explícitamente, pues no se llama en fallo de carga.

            THROW_LAST();  // Llama a la del sistema que se encargará de cerrar el fichero.
		}
        END_CATCH_ALL
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDiagDisDoc diagnostics

#ifdef _DEBUG
void CDiagDisDoc::AssertValid() const     
{
	CBaseDoc::AssertValid();
}

void CDiagDisDoc::Dump(CDumpContext& dc) const
{
	CBaseDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiagDisDoc commands

CDiagBase* CDiagDisDoc::CrearObjDiag()
{
    CDiagBase* pdiag = new CDiagDis();
	pdiag->Construir(this);
	return pdiag;
}



