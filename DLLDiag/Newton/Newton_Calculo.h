// Newton_Calculo.h: interface for the Newton_Calculo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_CALCULO_H__588E873F_17C8_42CD_8FCB_4798989F0661__INCLUDED_)
#define AFX_NEWTON_CALCULO_H__588E873F_17C8_42CD_8FCB_4798989F0661__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Newton_SalidaDatos;
class Newton_ComRetro;



// Clase Newton_Calculo , clase de cálculo de una iteraci¢n.

class Newton_Calculo : public CBloqueFunc
{
public:
	DECLARAR_BLOQUE_FUNCIONAL(Newton_Calculo)

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
  
  	double x, x2;
  	double e, h;
};


#endif // !defined(AFX_NEWTON_CALCULO_H__588E873F_17C8_42CD_8FCB_4798989F0661__INCLUDED_)
