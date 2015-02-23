
// wordp.h

// Prueba de comunicación con Word 7.0 y OLE 2

// Clase Word_Iniciales de comunicación

class Word_ComIniciales : public CCom
{
public:
  	DECLARAR_COMUNICACION(Word_ComIniciales)
	
	double base;
	double altura;

};


// Clase Word_Salidas de comunicación

class Word_ComSalidas : public CCom
{
public:  	
  	DECLARAR_COMUNICACION(Word_ComSalidas)

	double area;
};


// Clase Word_Entrada

class Word_Entrada : public CBloqueFunc  
{
 
public:
	DECLARAR_BLOQUE_FUNCIONAL(Word_Entrada)

	DECLARAR_COM_ENTRADA(Word_ComIniciales) // En el caso de multidiagrama sirve.
	DECLARAR_COM_SALIDA(Word_ComIniciales)

  	Word_Entrada();
  	~Word_Entrada();

	virtual void IniciarDatos();  
  	virtual BOOL NuevosObjDatos();
  	virtual void DestObjDatos();
  	virtual void LeerFichero(CArchive& ar);
  	virtual void RecibirrFichero(CArchive& ar);
  	virtual BOOL RecibirDatosEntrada(const Word_ComIniciales* pE);
  	virtual void EnviarDatosSalida(Word_ComIniciales* pS);
 
  	virtual CString Accion();
  
  	virtual BOOL PropUsuario();  

	double base;
	double altura;
  
  	CFontDialog* ejemplo;
};



class Word_Calculo : public CBloqueFunc  
{
 
public:
	DECLARAR_BLOQUE_FUNCIONAL(Word_Calculo)

	DECLARAR_COM_ENTRADA(Word_ComIniciales) 
	DECLARAR_COM_SALIDA(Word_ComSalidas)

  	Word_Calculo();
  	~Word_Calculo();

	virtual void IniciarDatos();  
  	virtual BOOL NuevosObjDatos();
  	virtual void DestObjDatos();
  	virtual void LeerFichero(CArchive& ar);
  	virtual void RecibirrFichero(CArchive& ar);
  	virtual BOOL RecibirDatosEntrada(const Word_ComIniciales* pE);
  	virtual void EnviarDatosSalida(Word_ComSalidas* pS);

  	virtual CString Accion();
  
  	virtual BOOL PropUsuario();  

	double base;
	double altura;
	double area;
  
  	CFontDialog* ejemplo;
};

class Word_Resultados : public CBloqueFunc  
{
 
public:
	DECLARAR_BLOQUE_FUNCIONAL(Word_Resultados)    

	DECLARAR_COM_ENTRADA(Word_ComSalidas)
	DECLARAR_COM_SALIDA(Word_ComSalidas)   // En el caso de multidiagrama sirve.

  	Word_Resultados();
  	~Word_Resultados();

	virtual void IniciarDatos();  
  	virtual BOOL NuevosObjDatos();
  	virtual void DestObjDatos();
  	virtual void LeerFichero(CArchive& ar);
  	virtual void RecibirrFichero(CArchive& ar);
  	virtual BOOL RecibirDatosEntrada(const Word_ComSalidas* pE);
  	virtual void EnviarDatosSalida(Word_ComSalidas* pS);

  	virtual CString Accion();
  
  	virtual BOOL PropUsuario();  

	double area;  
  	CFontDialog* ejemplo;
};


