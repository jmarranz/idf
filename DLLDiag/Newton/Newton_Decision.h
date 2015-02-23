// Newton_Decision.h: interface for the Newton_Decision class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_DECISION_H__48E08C89_7E73_4D1E_888A_D351ACFBF0F3__INCLUDED_)
#define AFX_NEWTON_DECISION_H__48E08C89_7E73_4D1E_888A_D351ACFBF0F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Newton_SalidaDatos;
class Newton_ComRetro;

// Clase Newton_Decision

class Newton_Decision : public CBloqueFunc
{
public:
  	DECLARAR_BLOQUE_FUNCIONAL(Newton_Decision)

	DECLARAR_COM_ENTRADA(Newton_SalidaDatos)
	DECLARAR_COM_ENTRADA(Newton_ComRetro)		
	DECLARAR_COM_ENTRADA(CComSerial)

	DECLARAR_COM_SALIDA(Newton_SalidaDatos)
	DECLARAR_COM_SALIDA(CComSerial)
  	

	virtual void IniciarDatos(); 
  	virtual void LeerFichero(CArchive& ar);
  	virtual void GuardarFichero(CArchive& ar);
	
	virtual BOOL RecibirDatosEntrada(Newton_SalidaDatos* pE);
	virtual BOOL RecibirDatosEntrada(Newton_ComRetro* pE);
	virtual BOOL RecibirDatosEntrada(CComSerial* pE);

	virtual void EnviarDatosSalida(Newton_SalidaDatos* pS);
	virtual void EnviarDatosSalida(CComSerial* pS);

	
	virtual CString Accion();

private:
  
	double x,e, emax;
};



#endif // !defined(AFX_NEWTON_DECISION_H__48E08C89_7E73_4D1E_888A_D351ACFBF0F3__INCLUDED_)
