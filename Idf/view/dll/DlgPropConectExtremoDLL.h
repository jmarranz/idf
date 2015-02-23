// DlgPropConectExtremoDLL.h: interface for the CDlgPropConectExtremoDLL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGPROPCONECTEXTREMODLL_H__C2F7A5E0_B053_4BF5_AA8A_B1395AA28EDE__INCLUDED_)
#define AFX_DLGPROPCONECTEXTREMODLL_H__C2F7A5E0_B053_4BF5_AA8A_B1395AA28EDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CConectExtremo;

class CDlgPropConectExtremoDLL : public CPropertyPage  
{
	DECLARE_DYNAMIC(CDlgPropConectExtremoDLL)
public:
	CDlgPropConectExtremoDLL(UINT nIDTemplate);
	virtual ~CDlgPropConectExtremoDLL();
	virtual void setExtremo(CConectExtremo* extremo);

	virtual CString getClaseCom() = 0;
	virtual void setClaseCom(const CString& claseCom) = 0;

	virtual CComboBox* getListaClaseCom() = 0;

	void killFocusClaseCom();
	void listarClases();
	void generacionCodigo();
	void inspeccionCodigo();

protected:
	CConectExtremo* p_extremo;
};

#endif // !defined(AFX_DLGPROPCONECTEXTREMODLL_H__C2F7A5E0_B053_4BF5_AA8A_B1395AA28EDE__INCLUDED_)
