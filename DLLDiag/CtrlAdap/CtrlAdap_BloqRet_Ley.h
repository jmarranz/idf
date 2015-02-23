class CtrlAdap_BloqRet_Ley : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(CtrlAdap_BloqRet_Ley) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Estim_Ley) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Estim_Ley* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(CtrlAdap_Com_Ley_R) 
	virtual  void EnviarDatosSalida(CtrlAdap_Com_Ley_R* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual BOOL PropiedadesBloque(); 

	BOOL CalcularRegulador();

private:
	// Ley de control:
	BOOL RegValido; // Si el regulador actual es válido (ej. inicialización)
	BOOL EstimacionValida;  // Si los parametros estimación del sistema son válidos

	// Datos de entrada
	double Ek;   // ek
	double Ek1;  // ek-1
	double Ek2;  // ek-2

	double X; // Ha de ser constante en al menos 3 pulsos

	double T; // Tiempo de muestreo

	double Yk1;
	double Yk;

	// Coeficientes
	// Coeficientes del sistema calculados por aproximación lineal
	double a1;
	double a2;
	double a3;

	double Tau; // Constante de tiempo de convergencia
	double MaxE; // Máximo error permitido en reg permanente (%)	

	// Ganancia del regulador resultante
	double Kr;
}; 

