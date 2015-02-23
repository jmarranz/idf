// Exception.h: interface for the Exception class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXCEPTION_H__7B841080_8B09_45EA_9FCB_80BE7D0D83C9__INCLUDED_)
#define AFX_EXCEPTION_H__7B841080_8B09_45EA_9FCB_80BE7D0D83C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Exception : public CObject  
{
public:
	Exception();
	Exception(const char* message);
	Exception(const CString& message);
	virtual ~Exception();

	virtual CString getMessage();
protected:
	CString m_message;
};

#endif // !defined(AFX_EXCEPTION_H__7B841080_8B09_45EA_9FCB_80BE7D0D83C9__INCLUDED_)
