// CDLLDiagrama.h: interface for the CDLLDiagrama class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CDLLDiagrama_H__B79334B5_03F3_46A1_90E9_98F4DA9CD34E__INCLUDED_)
#define AFX_CDLLDiagrama_H__B79334B5_03F3_46A1_90E9_98F4DA9CD34E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDLLDiagrama : public CObject  
{
public:
	CDLLDiagrama();
	virtual ~CDLLDiagrama();

	void Cargar(const CString& path);
	void Descargar();

	BOOL Cargado();

	HINSTANCE getHandler();

	static CString MensajeErrorNoDLL(const CString& path);
	static CString MensajeErrorNoDLLDiag(const CString& path);

private:
	CString m_path;
	CString m_path_interno;  // Probablemente no lo usemos 

	HINSTANCE m_hinstDLL; 

	BOOL ( *p_iniciarDLLDiagrama)(HINSTANCE hInstance, HWND hwin);
	void ( *p_liberarDLLDiagrama)();
};

#endif // !defined(AFX_CDLLDiagrama_H__B79334B5_03F3_46A1_90E9_98F4DA9CD34E__INCLUDED_)
