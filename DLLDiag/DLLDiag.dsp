# Microsoft Developer Studio Project File - Name="DLLDiag" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=DLLDiag - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DLLDiag.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DLLDiag.mak" CFG="DLLDiag - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DLLDiag - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "DLLDiag - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/LABI/proyec_fin/jmarranz/Proyecto32/DLLDiag", TGQBAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DLLDiag - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G5 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_USRDLL" /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "DLLDiag - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G6 /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /Fr /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "DLLDiag - Win32 Release"
# Name "DLLDiag - Win32 Debug"
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\DLLDiag.ico
# End Source File
# Begin Source File

SOURCE=.\res\DLLDiag.rc2
# End Source File
# End Group
# Begin Group "Ciemat"

# PROP Default_Filter ""
# Begin Group "Ciemat Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ciemat\Ciemat.h
# End Source File
# Begin Source File

SOURCE=.\Ciemat\DlgMostrar2E.h
# End Source File
# Begin Source File

SOURCE=.\Ciemat\dlgparamentradairradext.h
# End Source File
# Begin Source File

SOURCE=.\Ciemat\DlgResIrradExterna.h
# End Source File
# Begin Source File

SOURCE=.\Ciemat\DlgSedimentacion.h
# End Source File
# End Group
# Begin Group "Ciemat Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ciemat\Ciemat.cpp
# End Source File
# Begin Source File

SOURCE=.\Ciemat\DlgMostrar2E.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Ciemat\dlgparamentradairradext.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Ciemat\DlgResIrradExterna.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Ciemat\DlgSedimentacion.cpp
# ADD CPP /I ".."
# End Source File
# End Group
# End Group
# Begin Group "CtrlAdap"

# PROP Default_Filter ""
# Begin Group "Ctrl Adaptativo Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Inversor.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Plus.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Regulador.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Sistema.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_x.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_BloqRet_Estimador.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_BloqRet_Ley.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Com_Estim_Ley.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Com_Ley_R.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Com_Var.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\DlgCtrlAdap_Ajuste.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\DlgCtrlAdap_Ley.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\DlgCtrlAdap_R.h
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\dlgctrladap_x.h
# End Source File
# End Group
# Begin Group "Ctrl Adaptativo Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Inversor.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Plus.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Regulador.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_Sistema.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Bloq_x.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_BloqRet_Estimador.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_BloqRet_Ley.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Com_Estim_Ley.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Com_Ley_R.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\CtrlAdap_Com_Var.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\DlgCtrlAdap_Ajuste.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\DlgCtrlAdap_Ley.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\DlgCtrlAdap_R.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\CtrlAdap\dlgctrladap_x.cpp
# ADD CPP /I ".."
# End Source File
# End Group
# End Group
# Begin Group "Newton"

# PROP Default_Filter ""
# Begin Group "Newton Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ciemat\DlgMostrarE.h
# End Source File
# Begin Source File

SOURCE=.\Newton\DlgNewton.h
# End Source File
# Begin Source File

SOURCE=.\Newton\DlgNewtonIni.h
# End Source File
# Begin Source File

SOURCE=.\Newton\DlgNewtonRetro.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Actuales.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Calculo.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_ComRetro.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Configuracion.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Decision.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Entrada.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Funcion.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Resultados.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_SalidaDatos.h
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_SalidaInicio.h
# End Source File
# End Group
# Begin Group "Newton Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ciemat\DlgMostrarE.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Newton\DlgNewton.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\DlgNewtonIni.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\DlgNewtonRetro.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Actuales.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Calculo.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_ComRetro.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Configuracion.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Decision.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Entrada.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Funcion.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_Resultados.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_SalidaDatos.cpp
# End Source File
# Begin Source File

SOURCE=.\Newton\Newton_SalidaInicio.cpp
# End Source File
# End Group
# End Group
# Begin Group "RedNeuronal"

# PROP Default_Filter ""
# Begin Group "Red Neuronal Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RedNeuronal\DlgNeuronalX.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Comparacion.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_dW.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Inversion.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Neurona.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Sistema.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Suma.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_W.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_x.cpp
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Com_Dato.cpp
# End Source File
# End Group
# Begin Group "Red Neuronal Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RedNeuronal\DlgNeuronalX.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Comparacion.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_dW.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Inversion.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Neurona.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Sistema.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_Suma.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_W.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Bloq_x.h
# End Source File
# Begin Source File

SOURCE=.\RedNeuronal\Neuronal_Com_Dato.h
# End Source File
# End Group
# End Group
# Begin Group "ResLineal"

# PROP Default_Filter ""
# Begin Group "Ecuacion Lineal Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ResLineal\Definiciones.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\Dmatriz.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DMatrizMath.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DVector.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DVectorMath.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DVectorObj.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\Ecuacion_Lineal.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\Flujos_ES.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\LU.h
# End Source File
# Begin Source File

SOURCE=.\ResLineal\Utilidades.h
# End Source File
# End Group
# Begin Group "Ecuacion Lineal Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ResLineal\Dmatriz.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DMatrizMath.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DVector.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DVectorMath.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\DVectorObj.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\Ecuacion_Lineal.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\Flujos_ES.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\LU.cpp
# End Source File
# Begin Source File

SOURCE=.\ResLineal\Utilidades.cpp
# End Source File
# End Group
# End Group
# Begin Group "SistExpert"

# PROP Default_Filter ""
# Begin Group "Sist Experts Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SistExpert\DlgSistExpert_Ley.h
# End Source File
# Begin Source File

SOURCE=.\SistExpert\Sist_Expert_Trapecios_Fuzzy.h
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Bloq_Aprend.h
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Bloq_R.h
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Bloq_Reglas.h
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Com_Coefs.h
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Com_Ley_R.h
# End Source File
# End Group
# Begin Group "Sist Experts Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SistExpert\DlgSistExpert_Ley.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\SistExpert\Sist_Expert_Trapecios_Fuzzy.cpp
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Bloq_Aprend.cpp
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Bloq_R.cpp
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Bloq_Reglas.cpp
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Com_Coefs.cpp
# End Source File
# Begin Source File

SOURCE=.\SistExpert\SistExpert_Com_Ley_R.cpp
# End Source File
# End Group
# End Group
# Begin Group "WordOLE"

# PROP Default_Filter ""
# Begin Group "WordOLE Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\WordOLE\wordp.cpp
# End Source File
# End Group
# Begin Group "WordOLE Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\WordOLE\wordp.h
# End Source File
# End Group
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DLLDiag.cpp
# End Source File
# Begin Source File

SOURCE=.\DLLDiag.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DLLDiag.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
