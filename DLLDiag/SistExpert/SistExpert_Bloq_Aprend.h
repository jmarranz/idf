class SistExpert_Bloq_Aprend : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(SistExpert_Bloq_Aprend) 

	// Declaraci�n de clases de comunicaci�n de Entrada : 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 

	// Declaraci�n de clases de comunicaci�n de Salida : 
	DECLARAR_COM_SALIDA(SistExpert_Com_Coefs) 
	virtual  void EnviarDatosSalida(SistExpert_Com_Coefs* pS); 

	// Funciones est�ndar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual BOOL PropiedadesBloque(); 

	BOOL AjustarReglas();
	BOOL Ajuste_E();
	BOOL Ajuste_dE();
	BOOL Ajuste_dU();

private:
	double X;
	double Ek1;
	double Ek;
	double dEk1;
	double dEk;
	double T;
	double Uk3;
	double Uk2;
	double Uk1; // Siempre se recibir� un intervalo anterior a Ek

	double MaxE; // Max error permitido (%)

	// Coefs de ajuste. Deben de ser cero excepto en plena retroanotaci�n. Car�cter temporal
	double ce;
	double cde;
	double cdu;
}; 

