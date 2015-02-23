// BloqueVistasModo.h: interface for the CBloqueVistasModo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEVISTASMODO_H__0D8874A7_4549_4AF9_BB6C_CE7997463B2B__INCLUDED_)
#define AFX_BLOQUEVISTASMODO_H__0D8874A7_4549_4AF9_BB6C_CE7997463B2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBloqueVistas;

class CBloqueVistasModo : public CObject  
{
public:
	CBloqueVistasModo();
	virtual ~CBloqueVistasModo();

	virtual void Construir(CBloqueVistas* pvistas);

	CBloqueVistas* getVistas()
	{
		return p_vistas;
	}

	virtual void PropUsuario() {  }
	
protected:
	CBloqueVistas* p_vistas;
};

#endif // !defined(AFX_BLOQUEVISTASMODO_H__0D8874A7_4549_4AF9_BB6C_CE7997463B2B__INCLUDED_)
