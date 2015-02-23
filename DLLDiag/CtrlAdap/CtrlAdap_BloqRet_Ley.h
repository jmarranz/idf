class CtrlAdap_BloqRet_Ley : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(CtrlAdap_BloqRet_Ley) 

	// Declaraci�n de clases de comunicaci�n de Entrada : 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Estim_Ley) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Estim_Ley* pE); 

	// Declaraci�n de clases de comunicaci�n de Salida : 
	DECLARAR_COM_SALIDA(CtrlAdap_Com_Ley_R) 
	virtual  void EnviarDatosSalida(CtrlAdap_Com_Ley_R* pS); 

	// Funciones est�ndar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual BOOL PropiedadesBloque(); 

	BOOL CalcularRegulador();

private:
	// Ley de control:
	BOOL RegValido; // Si el regulador actual es v�lido (ej. inicializaci�n)
	BOOL EstimacionValida;  // Si los parametros estimaci�n del sistema son v�lidos

	// Datos de entrada
	double Ek;   // ek
	double Ek1;  // ek-1
	double Ek2;  // ek-2

	double X; // Ha de ser constante en al menos 3 pulsos

	double T; // Tiempo de muestreo

	double Yk1;
	double Yk;

	// Coeficientes
	// Coeficientes del sistema calculados por aproximaci�n lineal
	double a1;
	double a2;
	double a3;

	double Tau; // Constante de tiempo de convergencia
	double MaxE; // M�ximo error permitido en reg permanente (%)	

	// Ganancia del regulador resultante
	double Kr;
}; 

