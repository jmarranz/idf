class CtrlAdap_BloqRet_Estimador : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(CtrlAdap_BloqRet_Estimador) 

	// Declaraci�n de clases de comunicaci�n de Entrada : 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 

	// Declaraci�n de clases de comunicaci�n de Salida : 
	DECLARAR_COM_SALIDA(CtrlAdap_Com_Estim_Ley) 
	virtual  void EnviarDatosSalida(CtrlAdap_Com_Estim_Ley* pS); 

	// Funciones est�ndar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual BOOL PropiedadesBloque(); 

	BOOL EstimarSistema();

private:
	double Yk;
	double Yk1; // Y(k-1)
	double Yk2; // Y(k-2)
	double Yk3; // ...
	
	double Uk;
	double Uk1; // U(k-1)
	double Uk2;

	// Coeficientes calculados por aproximaci�n lineal
	double a1;
	double a2;
	double NivelY; // El nivel al que se calcul� la �ltima estimaci�n
}; 

