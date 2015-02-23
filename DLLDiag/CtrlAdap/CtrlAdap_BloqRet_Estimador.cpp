

#include "stdafx.h"

#include "..\ResLineal\Ecuacion_Lineal.h"

#include "..\DLLDiag.h"

#include "CtrlAdap_Com_Var.h"
#include "CtrlAdap_Com_Estim_Ley.h"
#include "CtrlAdap_BloqRet_Estimador.h"


IMPLEMENTAR_BLOQUE_RETROANOTACION(CtrlAdap_BloqRet_Estimador,CBloqueRetro,1) 

// Implementación de clases de comunicación de Entrada del bloque: CtrlAdap_BloqRet_Estimador
IMPLEMENTAR_COM_ENTRADA(CtrlAdap_Com_Var,CtrlAdap_BloqRet_Estimador) 
BOOL CtrlAdap_BloqRet_Estimador::RecibirDatosEntrada(CtrlAdap_Com_Var* pE) 
{ 
	if (pE->getNombreInternoConector() == "Con_Uk")
	{
		Uk2 = Uk1;
		Uk1 = Uk;
		Uk = pE->Var;
	}
	else  
	{
		Yk3 = Yk2;
		Yk2 = Yk1;
		Yk1 = Yk;
		Yk = pE->Var;
	
		if ( abs(100 * (NivelY-Yk) / Yk) >= 10)  // Un 10% de variación : recalcular el sistema
		{
			EstimarSistema();
			NivelY = Yk;

			EnviarDatosRetroanotacion("");
		}
	}

	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: CtrlAdap_BloqRet_Estimador
IMPLEMENTAR_COM_SALIDA(CtrlAdap_Com_Estim_Ley,CtrlAdap_BloqRet_Estimador) 
void CtrlAdap_BloqRet_Estimador::EnviarDatosSalida(CtrlAdap_Com_Estim_Ley* pS) 
{ 
	pS->a1 = a1;
	pS->a2 = a2;
} 

void CtrlAdap_BloqRet_Estimador::IniciarDatos() 
{ 
	Yk = 7;
	Yk1 = 7; // Y(k-1)
	Yk2 = 7; // Y(k-2)
	Yk3 = 7;

	Uk = 1;
	Uk1 = 1;
	Uk2 = 1;

	a1 = 1;
	a2 = 1;
	NivelY = 7;
	
	CambiaEstado(CORRECTO); 
}
 
BOOL CtrlAdap_BloqRet_Estimador::NuevosObjDatos() 
{ 
	return true; 
} 
void CtrlAdap_BloqRet_Estimador::DestObjDatos() 
{ 
 
} 
void CtrlAdap_BloqRet_Estimador::GuardarFichero(CArchive& ar) 
{ 
	ar << Yk << Yk1 << Yk2 << Yk3;
	ar << Uk << Uk1 << Uk2;
	ar << a1 << a2 << NivelY;
} 
void CtrlAdap_BloqRet_Estimador::LeerFichero(CArchive& ar) 
{ 
	ar >> Yk >> Yk1 >> Yk2 >> Yk3;
	ar >> Uk >> Uk1 >> Uk2;
	ar >> a1 >> a2 >> NivelY;
} 

BOOL CtrlAdap_BloqRet_Estimador::PropiedadesBloque() 
{ 
	return true; 
} 

BOOL CtrlAdap_BloqRet_Estimador::EstimarSistema()
{
	int numero_ecuaciones = 2; //orden

	// Matriz de coeficientes
	DMatrizMath<double> A(numero_ecuaciones);

	A[1][1] = Yk - Yk1;  // Derivada primera
	A[1][2] = Yk - 2*Yk1 + Yk2; // Derivada segunda

	A[2][1] = Yk1 - Yk2;
	A[2][2] = Yk1 - 2*Yk2 + Yk3;

	//cout << "A:" << endl;
	//cout << A;

	// Vector de términos independientes
	DVectorMath<double> c(numero_ecuaciones);

	c[1] = Uk-Uk1;
	c[2] = Uk1-Uk2;

	//cout << "c:" << endl;
	//cout << c;

	// Ecuación lineal
	Ecuacion_Lineal mi_ecuacion(numero_ecuaciones);

	// x es el vector incógnita

	try
	{
		DVectorMath<double> x = mi_ecuacion.resolver(A, c);

		a1 = x[1];
		a2 = x[2];

		CString Mensaje;
		Mensaje.Format("(%f, %f)",a1,a2);
		Mensaje = "Estimación Sistema: (a1,a2)=" + Mensaje;
		AfxMessageBox(Mensaje);

		//cout << "\nx:" << endl;
		//cout << x;	
	}
	catch(...)
	{
		AfxMessageBox("FALLO: No se puede estimar el sistema");
	}

	return true;
}


