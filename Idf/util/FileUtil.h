// FileUtil.h: interface for the CFileUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEUTIL_H__0D531DEA_54CE_4A2F_8065_4E85ECF49F61__INCLUDED_)
#define AFX_FILEUTIL_H__0D531DEA_54CE_4A2F_8065_4E85ECF49F61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFileUtil  
{
public:
	CFileUtil();
	virtual ~CFileUtil();

	static CString DirectorioActual();
	static CString FormarPathAbsoluto(const CString& PathRel, const CString& NombreFich);
	static BOOL ExisteDirectorio(const CString& Directorio);
};

#endif // !defined(AFX_FILEUTIL_H__0D531DEA_54CE_4A2F_8065_4E85ECF49F61__INCLUDED_)
