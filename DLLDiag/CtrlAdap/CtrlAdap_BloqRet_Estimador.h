class CtrlAdap_BloqRet_Estimador : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(CtrlAdap_BloqRet_Estimador) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(CtrlAdap_Com_Estim_Ley) 
	virtual  void EnviarDatosSalida(CtrlAdap_Com_Estim_Ley* pS); 

	// Funciones estándar a implementar
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

	// Coeficientes calculados por aproximación lineal
	double a1;
	double a2;
	double NivelY; // El nivel al que se calculó la última estimación
}; 

