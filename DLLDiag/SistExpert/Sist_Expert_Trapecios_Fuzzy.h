// Sist_Expert_Trapecios_Fuzzy.h: interface for the Sist_Expert_Trapecios_Fuzzy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIST_EXPERT_TRAPECIOS_FUZZY_H__BDE02693_3790_11D3_82B5_00609796AC40__INCLUDED_)
#define AFX_SIST_EXPERT_TRAPECIOS_FUZZY_H__BDE02693_3790_11D3_82B5_00609796AC40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


typedef enum { MN=0, N, Z, P, MP } enum_valdifuso;


class Trapecio_Fuzzy
{
public:
	Trapecio_Fuzzy();
	Trapecio_Fuzzy(Trapecio_Fuzzy& tr);
	Trapecio_Fuzzy(double p1, double p2, double p3, double p4);
	void operator=(Trapecio_Fuzzy& tr); 
	double GetNivelEncaje() { return NivelEncaje; };
	void SetNivelEncaje(double nivel) { NivelEncaje = nivel; };
	void CalcNivelEncaje(double vp);

	// Relacionados con el cálculo del centro de gravedad	
	double CalcNivelConFactorEncaje(double vp);
	double SumaNiveles(double intervalo);
	double Longitud();

	void Ajustar(double coef);
	int Signo(double var);

	void GuardarFichero(CArchive& ar); 
	void LeerFichero(CArchive& ar); 

private:
	// Todos los parámetros deben estar entre -1 y 1
	double P1;
	double P2;
	double P3;
	double P4;

	// Valores resultados de cálculo
	double NivelEncaje;
};


class Trapecios_var
{
public:
	void SetNivelEncaje(int tr, double nivel);
	void CalcNivelEncajes(double var);
	double GetNivelEncaje(int tr);
	// Relacionadas con el centro de gravedad
	double CalcCentroGravedad();
	double CalcAreaNivel(double pos);
	double LongMinTrapecios();

	void Ajustar(double coef);


	void GuardarFichero(CArchive& ar); 
	void LeerFichero(CArchive& ar); 

public:
	Trapecio_Fuzzy Trap[5];
};




#endif // !defined(AFX_SIST_EXPERT_TRAPECIOS_FUZZY_H__BDE02693_3790_11D3_82B5_00609796AC40__INCLUDED_)
