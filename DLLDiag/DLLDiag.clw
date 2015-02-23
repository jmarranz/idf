; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgNewton
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dlldiag.h"
LastPage=0

ClassCount=7
Class1=CDLLActivo
Class2=CDLLDiagApp
Class3=CDNewton
Class4=CDNewtonIni
Class5=CDlgRetro

ResourceCount=17
Resource1=IDD_NEWTONINI (English (U.S.))
Resource2=IDD_NEWTONRETRO (English (U.S.))
Resource3=IDD_CIEMAT_PARAMIRRADEXT (English (U.S.))
Resource4=IDD_CIEMAT_RESIRRAD_EXTERNA (English (U.S.))
Resource5=IDD_CIEMAT_RESIRRAD_EXT_INT (English (U.S.))
Resource6=IDD_DLLACTIVO (English (U.S.))
Resource7=IDD_CIEMAT_VER_E (English (U.S.))
Resource8=IDD_CIEMAT_VER_2E (English (U.S.))
Resource9=IDD_CIEMAT_SEDIMENTACION (English (U.S.))
Resource10=IDD_CTRLADAP_X (English (U.S.))
Resource11=IDD_CTRLADAP_R (English (U.S.))
Resource12=IDD_CTRLADAP_LEY (English (U.S.))
Resource13=IDD_SISTEXPERT_LEY (English (U.S.))
Resource14=IDD_CTRLADAP_AJUSTE (English (U.S.))
Resource15=IDD_NEURONAL_X (Spanish (Castilian))
Class6=CDlgNeuronalX
Resource16=IDD_NEURONAL_X
Class7=CDlgNewton
Resource17=IDD_NEWTON (English (U.S.))

[CLS:CDLLActivo]
Type=0
BaseClass=CDialog
HeaderFile=DLLACTIV.H
ImplementationFile=DLLACTIV.CPP

[CLS:CDLLDiagApp]
Type=0
BaseClass=CWinApp
HeaderFile=DLLDiag.h
ImplementationFile=DLLDiag.cpp
Filter=N
VirtualFilter=AC
LastObject=CDLLDiagApp

[CLS:CDNewton]
Type=0
BaseClass=CDialog
HeaderFile=Newton.h
ImplementationFile=Newton.cpp

[CLS:CDNewtonIni]
Type=0
BaseClass=CDialog
HeaderFile=Newton.h
ImplementationFile=Newton.cpp

[CLS:CDlgRetro]
Type=0
BaseClass=CDialog
HeaderFile=Newton.h
ImplementationFile=Newton.cpp
LastObject=CDlgRetro

[DLG:IDD_NEWTON]
Type=1
Class=CDNewton

[DLG:IDD_NEWTONINI]
Type=1
Class=CDNewtonIni

[DLG:IDD_NEWTONRETRO]
Type=1
Class=CDlgRetro

[DLG:IDD_NEURONAL_X]
Type=1
Class=CDlgNeuronalX
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_X,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_X1,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_X2,edit,1350631552

[DLG:IDD_DLLACTIVO (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_NOMDLL,static,1342308353

[DLG:IDD_NEWTON (English (U.S.))]
Type=1
Class=CDlgNewton
ControlCount=9
Control1=IDOK,button,1342373889
Control2=IDC_TEXTOMEN,static,1342308353
Control3=IDCANCEL,button,1342242816
Control4=IDC_EDITX,edit,1350631552
Control5=IDC_EDITERROR,edit,1350631552
Control6=IDC_EDITFX,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[DLG:IDD_NEWTONINI (English (U.S.))]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342373889
Control2=IDC_TEXTOMEN,static,1342308353
Control3=IDCANCEL,button,1342242816
Control4=IDC_EDITX0,edit,1350631552
Control5=IDC_EDITEMAX,edit,1350631552
Control6=IDC_EDITH,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[DLG:IDD_NEWTONRETRO (English (U.S.))]
Type=1
Class=?
ControlCount=5
Control1=IDOK,button,1342373889
Control2=IDC_EDITEMAX,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDITH,edit,1350631552
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_CIEMAT_PARAMIRRADEXT (English (U.S.))]
Type=1
Class=?
ControlCount=44
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_DESINTEGRACION,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_DF_AIRE_GAMMA,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_DF_SUELO_GAMMA,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_DF_AIRE_BETA,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_DF_SUELO_BETA,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_DF_AGUA_GAMMA,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_DF_AGUA_BETA,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_CONC_AGUA,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_TASA_ATMOSFERA,edit,1350631552
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,button,1342177287
Control24=IDC_STATIC,static,1342308352
Control25=IDC_FBLINDAJE_GAMMA,edit,1350631552
Control26=IDC_STATIC,static,1342308352
Control27=IDC_FBLINDAJE_BETA,edit,1350631552
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_FOCUPACION_EXT,edit,1350631552
Control31=IDC_FOCUPACION_INT,edit,1350631552
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_FOCUPACION_AGUA,edit,1350631552
Control35=IDC_FOCUPACION_ORILLA,edit,1350631552
Control36=IDC_STATIC,static,1342308352
Control37=IDC_DURACION_VERTIDO,edit,1350631552
Control38=IDC_STATIC,static,1342308352
Control39=IDC_FPOND_PIEL,edit,1350631552
Control40=IDC_STATIC,static,1342308352
Control41=IDC_CONC_AIRE,edit,1350631552
Control42=IDC_STATIC,button,1342177287
Control43=IDC_CONC_ORILLA,edit,1350631552
Control44=IDC_STATIC,static,1342308352

[DLG:IDD_CIEMAT_RESIRRAD_EXTERNA (English (U.S.))]
Type=1
Class=?
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STIRRADIACION_EXTERNA,button,1342177287
Control4=IDC_STINMERSION_AIRE,static,1342308352
Control5=IDC_STIRRADIACION_SUELO,static,1342308352
Control6=IDC_STINMERSION_BANO,static,1342308352
Control7=IDC_STIRRADIACION_ORILLA,static,1342308352
Control8=IDC_INMERSION_AIRE,edit,1350631552
Control9=IDC_IRRADIACION_SUELO,edit,1350631552
Control10=IDC_INMERSION_BANO,edit,1350631552
Control11=IDC_IRRADIACION_ORILLA,edit,1350631552

[DLG:IDD_CIEMAT_RESIRRAD_EXT_INT (English (U.S.))]
Type=1
Class=?
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STIRRADIACION_EXTERNA,button,1342177287
Control4=IDC_STINMERSION_AIRE,static,1342308352
Control5=IDC_STIRRADIACION_SUELO,static,1342308352
Control6=IDC_STINMERSION_BANO,static,1342308352
Control7=IDC_STIRRADIACION_ORILLA,static,1342308352
Control8=IDC_INMERSION_AIRE,edit,1350633600
Control9=IDC_IRRADIACION_SUELO,edit,1350633600
Control10=IDC_INMERSION_BANO,edit,1350633600
Control11=IDC_IRRADIACION_ORILLA,edit,1350633600
Control12=IDC_STIRRADIACION_INTERNA,button,1342177287
Control13=IDC_STINCORPORACION_ALIMENTOS,static,1342308352
Control14=IDC_STINCORPORACION_AGUA,static,1342308352
Control15=IDC_STINCORPORACION_INHALACION,static,1342308352
Control16=IDC_INCORPORACION_ALIMENTOS,edit,1350633600
Control17=IDC_INCORPORACION_AGUA,edit,1350633600
Control18=IDC_INCORPORACION_INHALACION,edit,1350633600

[DLG:IDD_CIEMAT_VER_E (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ETIQ_E,static,1342308352
Control4=IDC_VALOR_E,edit,1350631552

[DLG:IDD_CIEMAT_VER_2E (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ETIQ_E,static,1342308352
Control4=IDC_VALOR_E,edit,1350631552
Control5=IDC_ETIQ_E2,static,1342308352
Control6=IDC_VALOR_E2,edit,1350631552

[DLG:IDD_CIEMAT_SEDIMENTACION (English (U.S.))]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SEDIM_S,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SEDIM_FONDO,edit,1350631552
Control8=IDC_SEDIM_SUSP,edit,1350631552

[DLG:IDD_CTRLADAP_X (English (U.S.))]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342373889
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_X,edit,1350631552
Control4=IDC_EDIT_K,edit,1350631552
Control5=IDC_EDIT_T,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_CTRLADAP_R (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342373889
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_KR,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_CTRLADAP_LEY (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342373889
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_TAU,edit,1350631552
Control5=IDC_EDIT_ME,edit,1350631552
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_SISTEXPERT_LEY (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342373889
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ME,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_CTRLADAP_AJUSTE (English (U.S.))]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342373889
Control2=IDCANCEL,button,1342242816
Control3=IDC_AJUSTE,button,1342242819

[CLS:CDlgNeuronalX]
Type=0
HeaderFile=RedNeuronal\DlgNeuronalX.h
ImplementationFile=RedNeuronal\DlgNeuronalX.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgNeuronalX

[DLG:IDD_NEURONAL_X (Spanish (Castilian))]
Type=1
Class=CDlgNeuronalX
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_X,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_X1,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_X2,edit,1350631552

[CLS:CDlgNewton]
Type=0
HeaderFile=Newton\DlgNewton.h
ImplementationFile=Newton\DlgNewton.cpp
BaseClass=CDialog

