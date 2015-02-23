// ConectExtremoModo.h: interface for the CConectExtremoModo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONECTEXTREMOMODO_H__E2EA03C5_BDEC_4443_9BB3_B69BB1A2CF6F__INCLUDED_)
#define AFX_CONECTEXTREMOMODO_H__E2EA03C5_BDEC_4443_9BB3_B69BB1A2CF6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CConectExtremo;


class CConectExtremoModo : public CObject  
{
public:
	CConectExtremoModo();
	virtual ~CConectExtremoModo();

	virtual void Construir(CConectExtremo* ext);

	CConectExtremo* getExtremo()
	{
		return p_extremo;
	}

protected:
	CConectExtremo* p_extremo;
};

#endif // !defined(AFX_CONECTEXTREMOMODO_H__E2EA03C5_BDEC_4443_9BB3_B69BB1A2CF6F__INCLUDED_)
