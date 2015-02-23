# Microsoft Developer Studio Project File - Name="Idf" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Idf - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Idf.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Idf.mak" CFG="Idf - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Idf - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Idf - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/LABI/proyec_fin/jmarranz/Proyecto32/Proy", ZHQBAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Idf - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Idf - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fr /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 xerces-c_2.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Idf - Win32 Release"
# Name "Idf - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Exception.cpp
# End Source File
# Begin Source File

SOURCE=.\global.cpp
# End Source File
# Begin Source File

SOURCE=.\Idf.cpp
# End Source File
# Begin Source File

SOURCE=.\Idf.odl
# End Source File
# Begin Source File

SOURCE=.\Idf.rc
# End Source File
# Begin Source File

SOURCE=.\OleTemplateServerIdf.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ASOCFIN.CUR
# End Source File
# Begin Source File

SOURCE=.\res\ASOCINI.CUR
# End Source File
# Begin Source File

SOURCE=.\res\BFNCDIAG.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BFUNCDLL.BMP
# End Source File
# Begin Source File

SOURCE=.\Res\bloque.ico
# End Source File
# Begin Source File

SOURCE=.\Res\bloques.ico
# End Source File
# Begin Source File

SOURCE=.\res\BLQFUNC.CUR
# End Source File
# Begin Source File

SOURCE=.\res\BLQRETRO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BLQRETRO.CUR
# End Source File
# Begin Source File

SOURCE=.\res\CANCELAR.BMP
# End Source File
# Begin Source File

SOURCE=.\res\CIRCULO.BMP
# End Source File
# Begin Source File

SOURCE=.\Res\conector.ico
# End Source File
# Begin Source File

SOURCE=.\res\CONFUNC_.BMP
# End Source File
# Begin Source File

SOURCE=.\res\CONRETRO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\CPOSETIQ.BMP
# End Source File
# Begin Source File

SOURCE=.\res\EDICTXT.CUR
# End Source File
# Begin Source File

SOURCE=.\Res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\IDF.ICO
# End Source File
# Begin Source File

SOURCE=.\res\Idf.rc2
# End Source File
# Begin Source File

SOURCE=.\res\IDFDIS.ICO
# End Source File
# Begin Source File

SOURCE=.\res\IDFDOC.ICO
# End Source File
# Begin Source File

SOURCE=.\res\INSCONEC.CUR
# End Source File
# Begin Source File

SOURCE=.\res\INSCONR.CUR
# End Source File
# Begin Source File

SOURCE=.\res\ITOOLBAR.BMP
# End Source File
# Begin Source File

SOURCE=.\res\MOVER.CUR
# End Source File
# Begin Source File

SOURCE=.\res\MOVGRPD.CUR
# End Source File
# Begin Source File

SOURCE=.\res\MOVGRPO.CUR
# End Source File
# Begin Source File

SOURCE=.\res\MOVGRUPO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\PROHIBID.CUR
# End Source File
# Begin Source File

SOURCE=.\res\RECDESEL.CUR
# End Source File
# Begin Source File

SOURCE=.\res\RECTANG.BMP
# End Source File
# Begin Source File

SOURCE=.\res\RECTSEL.CUR
# End Source File
# Begin Source File

SOURCE=.\res\ROMBO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\TOOLBAR.BMP
# End Source File
# Begin Source File

SOURCE=.\res\ZOOM.CUR
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Exception.h
# End Source File
# Begin Source File

SOURCE=.\global.h
# End Source File
# Begin Source File

SOURCE=.\Idf.h
# End Source File
# Begin Source File

SOURCE=.\OleTemplateServerIdf.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "model"

# PROP Default_Filter ""
# Begin Group "bdiag"

# PROP Default_Filter ""
# Begin Group "exe No. 3"

# PROP Default_Filter ""
# Begin Group "exe Sources No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\bdiag\exe\BloqueDiagExe.cpp
# End Source File
# End Group
# Begin Group "exe Headers No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\bdiag\exe\BloqueDiagExe.h
# End Source File
# Begin Source File

SOURCE=.\model\bdiag\exe\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "des No. 3"

# PROP Default_Filter ""
# Begin Group "des Sources No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\bdiag\des\BloqueDiagDis.cpp
# End Source File
# End Group
# Begin Group "des Headers No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\bdiag\des\BloqueDiagDis.h
# End Source File
# Begin Source File

SOURCE=.\model\bdiag\des\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "bdiag Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\bdiag\BloqueDiag.cpp
# End Source File
# End Group
# Begin Group "bdiag Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\bdiag\BloqueDiag.h
# End Source File
# Begin Source File

SOURCE=.\model\bdiag\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "dll"

# PROP Default_Filter ""
# Begin Group "exe"

# PROP Default_Filter ""
# Begin Group "exe Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\dll\exe\BloqueDLL_enlaces.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\BloqueDLLExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ComunicacionDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectDLL_enlaces.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectExtremoDLLExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectFinDLLExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectInicioDLLExe.cpp
# End Source File
# End Group
# Begin Group "exe Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\dll\exe\BloqueDLL_enlaces.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\BloqueDLLExe.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ComunicacionDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectDLL_enlaces.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectExtremoDLLExe.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectFinDLLExe.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\ConectInicioDLLExe.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\exe\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "des"

# PROP Default_Filter ""
# Begin Group "des Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\dll\des\BloqueDLLDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\des\ConectExtremoDLLDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\des\ConectFinDLLDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\des\ConectInicioDLLDis.cpp
# End Source File
# End Group
# Begin Group "des Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\dll\des\BloqueDLLDis.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\des\ConectExtremoDLLDis.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\des\ConectFinDLLDis.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\des\ConectInicioDLLDis.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\des\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "dll Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\dll\AnalisisClasesConDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\AnalisisClasesDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\AnalisisClasesSinDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\BloqueDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\ConectFinDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\ConectInicioDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\DLLDiagrama.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\GeneracionCodigoDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\InfoClases.cpp
# End Source File
# Begin Source File

SOURCE=.\model\dll\WinSpawn.cpp
# End Source File
# End Group
# Begin Group "dll Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\dll\AnalisisClasesConDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\AnalisisClasesDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\AnalisisClasesSinDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\BloqueDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\ConectFinDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\ConectInicioDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\DLLDiagrama.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\GeneracionCodigoDLL.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\InfoClases.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\model\dll\WinSpawn.h
# End Source File
# End Group
# End Group
# Begin Group "exe No. 1"

# PROP Default_Filter ""
# Begin Group "exe Sources No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\exe\BloqueExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\BloqueUnidadExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\Comunicacion.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectExtremoExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectFinExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectInicioExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\DiagExe.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\DiagExeBaseDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\model\exe\DiagExeDoc.cpp
# End Source File
# End Group
# Begin Group "exe Headers No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\exe\BloqueExe.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\BloqueUnidadExe.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\Comunicacion.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectExe.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectExtremoExe.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectFinExe.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\ConectInicioExe.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\DiagExe.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\DiagExeBaseDoc.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\DiagExeDoc.h
# End Source File
# Begin Source File

SOURCE=.\model\exe\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "des No. 1"

# PROP Default_Filter ""
# Begin Group "des Sources No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\des\BloqueDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\des\BloqueUnidadDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectExtremoDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectFinDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectInicioDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\des\DiagDis.cpp
# End Source File
# Begin Source File

SOURCE=.\model\des\DiagDisDoc.cpp
# End Source File
# End Group
# Begin Group "des Headers No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\des\BloqueDis.h
# End Source File
# Begin Source File

SOURCE=.\model\des\BloqueUnidadDis.h
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectDis.h
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectExtremoDis.h
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectFinDis.h
# End Source File
# Begin Source File

SOURCE=.\model\des\ConectInicioDis.h
# End Source File
# Begin Source File

SOURCE=.\model\des\DiagDis.h
# End Source File
# Begin Source File

SOURCE=.\model\des\DiagDisDoc.h
# End Source File
# Begin Source File

SOURCE=.\model\des\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "model Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\BaseDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\model\Bloque.cpp
# End Source File
# Begin Source File

SOURCE=.\model\BloqueException.cpp
# End Source File
# Begin Source File

SOURCE=.\model\BloqueModo.cpp
# End Source File
# Begin Source File

SOURCE=.\model\BloqueUnidad.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ComponenteDiag.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ComponenteDiagException.cpp
# End Source File
# Begin Source File

SOURCE=.\model\Conect.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ConectExtremo.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ConectExtremoModo.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ConectFin.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ConectInicio.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ConectModo.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ConectorException.cpp
# End Source File
# Begin Source File

SOURCE=.\model\DiagBase.cpp
# End Source File
# Begin Source File

SOURCE=.\model\DiagramaException.cpp
# End Source File
# Begin Source File

SOURCE=.\model\Instante.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ListaBloques.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ListaComponentes.cpp
# End Source File
# Begin Source File

SOURCE=.\model\ListaConectores.cpp
# End Source File
# End Group
# Begin Group "model Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\model\BaseDoc.h
# End Source File
# Begin Source File

SOURCE=.\model\Bloque.h
# End Source File
# Begin Source File

SOURCE=.\model\BloqueException.h
# End Source File
# Begin Source File

SOURCE=.\model\BloqueModo.h
# End Source File
# Begin Source File

SOURCE=.\model\BloqueUnidad.h
# End Source File
# Begin Source File

SOURCE=.\model\ComponenteDiag.h
# End Source File
# Begin Source File

SOURCE=.\model\ComponenteDiagException.h
# End Source File
# Begin Source File

SOURCE=.\model\Conect.h
# End Source File
# Begin Source File

SOURCE=.\model\ConectExtremo.h
# End Source File
# Begin Source File

SOURCE=.\model\ConectExtremoModo.h
# End Source File
# Begin Source File

SOURCE=.\model\ConectFin.h
# End Source File
# Begin Source File

SOURCE=.\model\ConectInicio.h
# End Source File
# Begin Source File

SOURCE=.\model\ConectModo.h
# End Source File
# Begin Source File

SOURCE=.\model\ConectorException.h
# End Source File
# Begin Source File

SOURCE=.\model\DiagBase.h
# End Source File
# Begin Source File

SOURCE=.\model\DiagramaException.h
# End Source File
# Begin Source File

SOURCE=.\model\Instante.h
# End Source File
# Begin Source File

SOURCE=.\model\ListaBloques.h
# End Source File
# Begin Source File

SOURCE=.\model\ListaComponentes.h
# End Source File
# Begin Source File

SOURCE=.\model\ListaConectores.h
# End Source File
# Begin Source File

SOURCE=.\model\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "view"

# PROP Default_Filter ""
# Begin Group "bdiag No. 1"

# PROP Default_Filter ""
# Begin Group "exe No. 2"

# PROP Default_Filter ""
# Begin Group "exe Sources No. 3"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\bdiag\exe\BloqueDiagVistasExe.cpp
# End Source File
# End Group
# Begin Group "exe Headers No. 3"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\bdiag\exe\BloqueDiagVistasExe.h
# End Source File
# Begin Source File

SOURCE=.\view\bdiag\exe\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "des No. 2"

# PROP Default_Filter ""
# Begin Group "des Sources No. 3"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\bdiag\des\BloqueDiagVistasDis.cpp
# End Source File
# End Group
# Begin Group "des Headers No. 3"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\bdiag\des\BloqueDiagVistasDis.h
# End Source File
# Begin Source File

SOURCE=.\view\bdiag\des\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "bdiag Sources No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\bdiag\BloqueDiagVistas.cpp
# End Source File
# Begin Source File

SOURCE=.\view\bdiag\PropBlqDiag.cpp
# End Source File
# Begin Source File

SOURCE=.\view\bdiag\PropiedadesBloqueDiag.cpp
# End Source File
# End Group
# Begin Group "bdiag Headers No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\bdiag\BloqueDiagVistas.h
# End Source File
# Begin Source File

SOURCE=.\view\bdiag\PropBlqDiag.h
# End Source File
# Begin Source File

SOURCE=.\view\bdiag\PropiedadesBloqueDiag.h
# End Source File
# Begin Source File

SOURCE=.\view\bdiag\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "dll No. 1"

# PROP Default_Filter ""
# Begin Group "exe No. 4"

# PROP Default_Filter ""
# Begin Group "exe Sources No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\dll\exe\BloqueDLLVistasExe.cpp
# End Source File
# End Group
# Begin Group "exe Headers No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\dll\exe\BloqueDLLVistasExe.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\exe\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "des No. 4"

# PROP Default_Filter ""
# Begin Group "des Sources No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\dll\des\BloqueDLLVistasDis.cpp
# End Source File
# End Group
# Begin Group "des Headers No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\dll\des\BloqueDLLVistasDis.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\des\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "dll Sources No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\dll\BloqueDLLVistas.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgGeneracionCodigoConDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgGeneracionCodigoDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgGeneracionCodigoSinDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropConectExtremoDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropConectFinDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropConectInicioDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropiedadesClasesConDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropiedadesClasesSinDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\PropBlqDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\PropiedadesBloqueDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\view\dll\TreeCtrlDiagCodigo.cpp
# End Source File
# End Group
# Begin Group "dll Headers No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\dll\BloqueDLLVistas.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgGeneracionCodigoConDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgGeneracionCodigoDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgGeneracionCodigoSinDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropConectExtremoDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropConectFinDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropConectInicioDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropiedadesClasesConDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\DlgPropiedadesClasesSinDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\PropBlqDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\PropiedadesBloqueDLL.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\view\dll\TreeCtrlDiagCodigo.h
# End Source File
# End Group
# End Group
# Begin Group "exe No. 5"

# PROP Default_Filter ""
# Begin Group "exe Sources No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\exe\BloqueUnidadVistasExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\BloqueVistasExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\ConectorNudoExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\ConectVistasExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DiagExeView.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DiagramaVistasExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DiagSrvrItem.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DibBloqueExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DibConectExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DibDiagramaExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgBloqueExe.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgCancelAuto.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgLog.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgOperacBloque.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgOperacBRetro.cpp
# End Source File
# Begin Source File

SOURCE=.\view\exe\InPlaceFrame.cpp
# End Source File
# End Group
# Begin Group "exe Headers No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\exe\BloqueUnidadVistasExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\BloqueVistasExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\ConectorNudoExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\ConectVistasExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DiagExeView.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DiagramaVistasExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DiagSrvrItem.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DibBloqueExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DibConectExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DibDiagramaExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgBloqueExe.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgCancelAuto.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgLog.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgOperacBloque.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\DlgOperacBRetro.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\InPlaceFrame.h
# End Source File
# Begin Source File

SOURCE=.\view\exe\stdafx.h
# End Source File
# End Group
# End Group
# Begin Group "des No. 5"

# PROP Default_Filter ""
# Begin Group "des Sources No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\des\BloqueUnidadVistasDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\BloqueVistasDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\Clipboard.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\ConectorNudoDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\ConectVistasDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\DiagDisView.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\DiagramaVistasDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\DibBloqueDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\DibConectDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\DibDiagramaDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\DlgBloqueDis.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\DlgNudoCon.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\PropRejilla.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\Rejilla.cpp
# End Source File
# Begin Source File

SOURCE=.\view\des\TablaDis.cpp
# End Source File
# End Group
# Begin Group "des Headers No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\des\BloqueUnidadVistasDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\BloqueVistasDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\Clipboard.h
# End Source File
# Begin Source File

SOURCE=.\view\des\ConectorNudoDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\ConectVistasDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\DiagDisView.h
# End Source File
# Begin Source File

SOURCE=.\view\des\DiagramaVistasDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\DibBloqueDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\DibConectDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\DibDiagramaDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\DlgBloqueDis.h
# End Source File
# Begin Source File

SOURCE=.\view\des\DlgNudoCon.h
# End Source File
# Begin Source File

SOURCE=.\view\des\PropRejilla.h
# End Source File
# Begin Source File

SOURCE=.\view\des\Rejilla.h
# End Source File
# Begin Source File

SOURCE=.\view\des\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\view\des\TablaDis.h
# End Source File
# End Group
# End Group
# Begin Group "view Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\AboutDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\view\BaseView.cpp
# End Source File
# Begin Source File

SOURCE=.\view\BloqueUnidadVistas.cpp
# End Source File
# Begin Source File

SOURCE=.\view\BloqueVistas.cpp
# End Source File
# Begin Source File

SOURCE=.\view\BloqueVistasModo.cpp
# End Source File
# Begin Source File

SOURCE=.\view\CambiaTxt.cpp
# End Source File
# Begin Source File

SOURCE=.\view\ComponenteDiagVistas.cpp
# End Source File
# Begin Source File

SOURCE=.\view\ConectNudo.cpp
# End Source File
# Begin Source File

SOURCE=.\view\ConectVistas.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DiagFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DiagramaVistas.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DibBloque.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DibConect.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DibDiagrama.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DlgBloque.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropBloqueConectores.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropDiagComponentes.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropDiagInform.cpp
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropDiagrama.cpp
# End Source File
# Begin Source File

SOURCE=.\view\Flecha.cpp
# End Source File
# Begin Source File

SOURCE=.\view\MainFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\view\MensajeLargo.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropBloque.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropBloqueInform.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropConect.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropConectInform.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropiedadesBloque.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropiedadesConector.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropiedadesDiagrama.cpp
# End Source File
# Begin Source File

SOURCE=.\view\PropMultiDiag.cpp
# End Source File
# Begin Source File

SOURCE=.\view\RGB.cpp
# End Source File
# Begin Source File

SOURCE=.\view\TreeCtrlDiagrama.cpp
# End Source File
# End Group
# Begin Group "view Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\view\AboutDialog.h
# End Source File
# Begin Source File

SOURCE=.\view\BaseView.h
# End Source File
# Begin Source File

SOURCE=.\view\BloqueUnidadVistas.h
# End Source File
# Begin Source File

SOURCE=.\view\BloqueVistas.h
# End Source File
# Begin Source File

SOURCE=.\view\BloqueVistasModo.h
# End Source File
# Begin Source File

SOURCE=.\view\CambiaTxt.h
# End Source File
# Begin Source File

SOURCE=.\view\ComponenteDiagVistas.h
# End Source File
# Begin Source File

SOURCE=.\view\ConectNudo.h
# End Source File
# Begin Source File

SOURCE=.\view\ConectVistas.h
# End Source File
# Begin Source File

SOURCE=.\view\DiagFrame.h
# End Source File
# Begin Source File

SOURCE=.\view\DiagramaVistas.h
# End Source File
# Begin Source File

SOURCE=.\view\DibBloque.h
# End Source File
# Begin Source File

SOURCE=.\view\DibConect.h
# End Source File
# Begin Source File

SOURCE=.\view\DibDiagrama.h
# End Source File
# Begin Source File

SOURCE=.\view\DlgBloque.h
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropBloqueConectores.h
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropDiagComponentes.h
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropDiagInform.h
# End Source File
# Begin Source File

SOURCE=.\view\DlgPropDiagrama.h
# End Source File
# Begin Source File

SOURCE=.\view\Flecha.h
# End Source File
# Begin Source File

SOURCE=.\view\MainFrame.h
# End Source File
# Begin Source File

SOURCE=.\view\MensajeLargo.h
# End Source File
# Begin Source File

SOURCE=.\view\PropBloque.h
# End Source File
# Begin Source File

SOURCE=.\view\PropBloqueInform.h
# End Source File
# Begin Source File

SOURCE=.\view\PropConect.h
# End Source File
# Begin Source File

SOURCE=.\view\PropConectInform.h
# End Source File
# Begin Source File

SOURCE=.\view\PropiedadesBloque.h
# End Source File
# Begin Source File

SOURCE=.\view\PropiedadesConector.h
# End Source File
# Begin Source File

SOURCE=.\view\PropiedadesDiagrama.h
# End Source File
# Begin Source File

SOURCE=.\view\PropMultiDiag.h
# End Source File
# Begin Source File

SOURCE=.\view\RGB.h
# End Source File
# Begin Source File

SOURCE=.\view\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\view\TreeCtrlDiagrama.h
# End Source File
# End Group
# End Group
# Begin Group "util"

# PROP Default_Filter ""
# Begin Group "util Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\util\FileUtil.cpp
# End Source File
# End Group
# Begin Group "util Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\util\FileUtil.h
# End Source File
# End Group
# End Group
# Begin Group "xmlutil"

# PROP Default_Filter ""
# Begin Group "xmlutil Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\xmlutil\DOMPrintErrorHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\xmlutil\DOMTreeErrorReporter.cpp
# End Source File
# Begin Source File

SOURCE=.\xmlutil\XMLUtil.cpp
# End Source File
# End Group
# Begin Group "xmlutil Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\xmlutil\DOMPrintErrorHandler.h
# End Source File
# Begin Source File

SOURCE=.\xmlutil\DOMTreeErrorReporter.h
# End Source File
# Begin Source File

SOURCE=.\xmlutil\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\xmlutil\XMLUtil.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
