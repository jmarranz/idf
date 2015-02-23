class Neuronal_Bloq_Neurona : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_Neurona) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(Neuronal_Com_Dato) 
	virtual  BOOL RecibirDatosEntrada(Neuronal_Com_Dato* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(Neuronal_Com_Dato) 
	virtual  void EnviarDatosSalida(Neuronal_Com_Dato* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	void IniciarFuncion();

	static double sigmoidea(double x);
	static double sigmoidea_derivada(double x);

	static double identidad(double x);
	static double identidad_derivada(double x);

	static double rampa(double x);
	static double rampa_derivada(double x);

	static double lineal(double x);
	static double lineal_derivada(double x);


protected:
	double (*g)(double x);
	double (*dg)(double x);
	CMap<CString,const char*,double,double&> m_Entradas;
	double m_Entrada;
	double m_Activacion;
}; 

