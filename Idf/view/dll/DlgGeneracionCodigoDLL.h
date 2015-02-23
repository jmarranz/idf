// DlgGeneracionCodigo.h: interface for the CDlgGeneracionCodigoDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGGENERACIONCODIGO_H__681171A2_717C_4320_8477_2F63982DA86E__INCLUDED_)
#define AFX_DLGGENERACIONCODIGO_H__681171A2_717C_4320_8477_2F63982DA86E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDiagBase;
class CAnalisisClasesDLL;
class CInfoBloque;
class CInfoCom;
class CInfoComES;


class CDlgGeneracionCodigoDLL : public CDialog  
{
public:
	CDlgGeneracionCodigoDLL(CDiagBase* pdiag,UINT nIDTemplate, CWnd* pParentWnd = NULL);
	virtual ~CDlgGeneracionCodigoDLL();

	virtual void SetCabeceras(const CString& codigo) = 0;
	virtual void SetImplementacion(const CString& codigo) = 0;

	void Analizar();
	void AnalizarBloque(CInfoBloque* pBloque);
	void AnalizarObjCom(CInfoCom* pCom);
	void AnalizarObjComES(CInfoComES* pComES);

	BOOL SalvarTexto(CString Texto,const CString& NombreTipo,const CString& Ext,BOOL Add = false);

protected:
	CAnalisisClasesDLL* p_Analizador;
	CDiagBase* p_diag;
};

#endif // !defined(AFX_DLGGENERACIONCODIGO_H__681171A2_717C_4320_8477_2F63982DA86E__INCLUDED_)
