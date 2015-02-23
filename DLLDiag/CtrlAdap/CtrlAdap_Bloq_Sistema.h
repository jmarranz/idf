class CtrlAdap_Bloq_Sistema : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(CtrlAdap_Bloq_Sistema) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(CtrlAdap_Com_Var) 
	virtual  void EnviarDatosSalida(CtrlAdap_Com_Var* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque();

private:
	double Yk;
	double Yk1; // Y(k-1)
	double Uk;
	double Uk1;
	double T;

	// Variables de definición de la ecuación
	// del modelo
	double c1; // Constante: 2*PI*tan(30) : Area superior partido por h
	double c2; // Constante sqrt(2*g)
	double a; // Constante: área de la boca de salida
}; 

