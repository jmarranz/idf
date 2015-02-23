// PropiedadesBloque.h: interface for the PropiedadesBloque class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPIEDADESBLOQUE_H__F7AD800E_89B7_4C68_97DD_B940E83A7ACB__INCLUDED_)
#define AFX_PROPIEDADESBLOQUE_H__F7AD800E_89B7_4C68_97DD_B940E83A7ACB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBloque;
class BloqueException;

class CPropiedadesBloque : public CPropertySheet  
{
public:
	CPropiedadesBloque(CBloque* pBlq,UINT pagina = 0);
	virtual ~CPropiedadesBloque();

	virtual CPropertyPage* PropGenerales(CPropertyPage* pdlg);
	virtual CPropertyPage* PropEspecificas(CPropertyPage* pdlg) throw (BloqueException) = 0;
	virtual CPropertyPage* PropListaConectores(CPropertyPage* pdlg);
	virtual CPropertyPage* PropInformacion(CPropertyPage* pdlg);

	virtual int DoModal(); 

protected:
	CBloque* p_bloque;
};

#endif // !defined(AFX_PROPIEDADESBLOQUE_H__F7AD800E_89B7_4C68_97DD_B940E83A7ACB__INCLUDED_)
