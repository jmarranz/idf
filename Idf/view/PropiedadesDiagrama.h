// PropiedadesDiagrama.h: interface for the CPropiedadesDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPIEDADESDIAGRAMA_H__E43C977C_F070_4157_92A7_C075E4252B04__INCLUDED_)
#define AFX_PROPIEDADESDIAGRAMA_H__E43C977C_F070_4157_92A7_C075E4252B04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPropiedadesDiagrama : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropiedadesDiagrama)

public:
	CPropiedadesDiagrama(CDiagBase* pdiag);
	virtual ~CPropiedadesDiagrama();

	virtual int DoModal();

	virtual CPropertyPage* PropDiagrama(CPropertyPage* pdlg); 
	virtual CPropertyPage* PropComponentes(CPropertyPage* pdlg);
	virtual CPropertyPage* PropInformacion(CPropertyPage* pdlg);

	virtual CPropertyPage* PropMultiDiag(CPropertyPage* pdlg); 

protected:
	CDiagBase* p_diag;

};

#endif // !defined(AFX_PROPIEDADESDIAGRAMA_H__E43C977C_F070_4157_92A7_C075E4252B04__INCLUDED_)
