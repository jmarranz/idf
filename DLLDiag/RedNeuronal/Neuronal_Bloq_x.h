class Neuronal_Bloq_x : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_x) 

	// Declaraci�n de clases de comunicaci�n de Entrada : 

	// Declaraci�n de clases de comunicaci�n de Salida : 
	DECLARAR_COM_SALIDA(Neuronal_Com_Dato) 
	virtual  void EnviarDatosSalida(Neuronal_Com_Dato* pS); 

	// Funciones est�ndar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	static double f(double t);

protected:
	double X;  // Instante K
	double X1; // X en el instante  K-1 
	double X2; // X en el instante  K-2
};

