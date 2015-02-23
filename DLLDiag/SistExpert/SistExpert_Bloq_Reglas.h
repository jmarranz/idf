
#include "Sist_Expert_Trapecios_Fuzzy.h"

class SistExpert_Bloq_Reglas : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(SistExpert_Bloq_Reglas) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(SistExpert_Com_Coefs) 
	virtual  BOOL RecibirDatosEntrada(SistExpert_Com_Coefs* pE); 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(SistExpert_Com_Ley_R) 
	virtual  void EnviarDatosSalida(SistExpert_Com_Ley_R* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual BOOL PropiedadesBloque(); 

	BOOL Calc_Kr();

private:

	// Entradas
	double X;
	double Ek;
	double Ek1;
	double T;

	// Salidas
	double Kr;

	// Valores internos
	double Uk1;
	double Uk;

	// Cálculo
	enum_valdifuso reglas[5][5]; // [reglas e][reglas de]
	 
	Trapecios_var trs_e;
	Trapecios_var trs_de;
	Trapecios_var trs_du;

	BOOL Ajustar;
}; 

