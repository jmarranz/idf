# Microsoft Developer Studio Project File - Name="IdfDllLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=IdfDllLib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "IdfDllLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "IdfDllLib.mak" CFG="IdfDllLib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IdfDllLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "IdfDllLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "IdfDllLib - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "IdfDllLib - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /G6 /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0xc0a /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "IdfDllLib - Win32 Release"
# Name "IdfDllLib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "impl"

# PROP Default_Filter ""
# Begin Group "Impl Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\impl\BLOQFUNC.CPP
# End Source File
# Begin Source File

SOURCE=.\impl\BLOQRETRO.CPP
# End Source File
# Begin Source File

SOURCE=.\impl\bloque.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\Bloque_enlaces.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\com.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\Com_enlaces.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\ComSerial.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\Diagrama_enlaces.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\IdfDllApp.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\InfoClases.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\InfoClases_enlaces.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\InfoDiagrama.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\NULO.cpp
# End Source File
# Begin Source File

SOURCE=.\impl\OLEAUTOM.CPP
# End Source File
# Begin Source File

SOURCE=.\impl\olevar.cpp
# End Source File
# End Group
# Begin Group "Impl Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\impl\BLOQFUNC.H
# End Source File
# Begin Source File

SOURCE=.\impl\BLOQRETRO.H
# End Source File
# Begin Source File

SOURCE=.\impl\bloque.h
# End Source File
# Begin Source File

SOURCE=.\impl\Bloque_enlaces.h
# End Source File
# Begin Source File

SOURCE=.\impl\com.h
# End Source File
# Begin Source File

SOURCE=.\impl\Com_enlaces.h
# End Source File
# Begin Source File

SOURCE=.\impl\ComSerial.h
# End Source File
# Begin Source File

SOURCE=.\impl\Diagrama_enlaces.h
# End Source File
# Begin Source File

SOURCE=.\impl\IdfDllApp.h
# End Source File
# Begin Source File

SOURCE=.\impl\InfoClases.h
# End Source File
# Begin Source File

SOURCE=.\impl\InfoClases_enlaces.h
# End Source File
# Begin Source File

SOURCE=.\impl\InfoDiagrama.h
# End Source File
# Begin Source File

SOURCE=.\impl\macros.h
# End Source File
# Begin Source File

SOURCE=.\impl\NULO.h
# End Source File
# Begin Source File

SOURCE=.\impl\OLEAUTOM.H
# End Source File
# Begin Source File

SOURCE=.\impl\olevar.h
# End Source File
# Begin Source File

SOURCE=.\impl\stdafx.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\Readme.txt
# End Source File
# End Target
# End Project
