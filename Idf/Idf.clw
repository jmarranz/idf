; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiagExeView
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "idf.h"
LastPage=0

ClassCount=38
Class1=CBaseView
Class2=CPropBlqDiag
Class3=CCambiaTxt
Class4=CDiagDisView
Class5=CDlgBloqueDis
Class6=CDlgNudoCon
Class7=CPropRejilla
Class8=CBotonTabla
Class9=CTablaDis
Class10=CDlgPropBloqueConectores
Class11=CDlgPropDiagComponentes
Class12=CDlgPropDiagInform
Class13=CDlgPropDiagrama
Class14=CDlgGeneracionCodigoConDLL
Class15=CDlgGeneracionCodigoSinDLL
Class16=CDlgPropiedadesClasesConDLL
Class17=CDlgPropiedadesClasesSinDLL
Class18=CPropBlqDLL
Class19=CDMensaje
Class20=CDConfirm
Class21=CDiagExeView
Class22=CDlgBloqueExe
Class23=CDlgCancelAuto
Class24=CDlgLog
Class25=COperacBloque
Class26=COperacBRetro
Class27=CInPlaceFrame
Class28=CPropMultiDiag
Class29=CIdfFrame
Class30=CMainFrame
Class31=CMensajeLargo
Class32=CPropBloque
Class33=CPropBloqueInform
Class34=CPropConect
Class35=CPropConectInform
Class36=CPropiedadesConector

ResourceCount=44
Resource1=IDD_MULTIDIAG (English (U.S.))
Resource2=IDD_CONFIRM (English (U.S.))
Resource3=IDR_PROY_DISENO (English (U.S.))
Resource4=IDR_PROYTYPE (English (U.S.))
Resource5=IDD_ANALISIS_DLL (English (U.S.))
Resource6=IDD_PROP_CONECT_FIN_DLL (English (U.S.))
Resource7=IDR_MENU_BLOQUE_DIS_DCHO (English (U.S.))
Resource8=IDD_PROP_DIAG_COMPONENTES (English (U.S.))
Resource9=IDR_PROYTYPE_CNTR_IP (English (U.S.))
Resource10=IDR_MENU_CONSOLA (English (U.S.))
Resource11=IDR_PROYTYPE_SRVR_EMB (English (U.S.))
Resource12=IDD_PROP_CONECT (English (U.S.))
Resource13=IDD_NUEVOTXT (English (U.S.))
Resource14=IDD_ANALISIS_CLASE (English (U.S.))
Resource15=IDD_PROP_CLASES_CON_DLL (English (U.S.))
Resource16=IDD_TABLADISENO (English (U.S.))
Resource17=IDD_PROP_BLOQUE_DLL (English (U.S.))
Resource18=IDR_MAINFRAME (English (U.S.))
Resource19=IDD_PROP_CLASES_SIN_DLL (English (U.S.))
Resource20=IDR_MENU_CLASEDLL_POPUP (English (U.S.))
Resource21=IDD_PROP_DIAG_INFORM (English (U.S.))
Resource22=IDD_PROP_DIAG (English (U.S.))
Resource23=IDD_PROP_BLOQUE_INFORM (English (U.S.))
Resource24=IDD_PROP_CONECT_INICIO_DLL (English (U.S.))
Resource25=IDD_MENSAJE (English (U.S.))
Resource26=ID_OBJECT_POPUP_MENU (English (U.S.))
Resource27=IDD_OPERAC_BLOQUE (English (U.S.))
Resource28=IDD_MENSAJE_EXT (English (U.S.))
Resource29=IDD_NUDOCON (English (U.S.))
Resource30=IDR_MENU_COMPONENTE_PROP_POPUP (English (U.S.))
Resource31=IDD_OPERAC_BRETRO (English (U.S.))
Resource32=IDD_PROP_BLOQUE (English (U.S.))
Resource33=IDD_BLOQUE (English (U.S.))
Resource34=IDD_PROP_REJILLA (English (U.S.))
Resource35=IDD_PROP_BLOQUE_CONECTORES (English (U.S.))
Resource36=IDR_MENU_CONEC_DCHO (English (U.S.))
Resource37=IDD_CANCEL_AUTO (English (U.S.))
Resource38=IDD_PROP_BLOQUE_DIAG (English (U.S.))
Resource39=IDD_PROP_CONECT_INFORM (English (U.S.))
Resource40=IDD_LOGDIAG (English (U.S.))
Resource41=IDD_ABOUTBOX (English (U.S.))
Resource42=IDR_MENU_BLOQUE_FUNC_DCHO (English (U.S.))
Class37=CDlgPropConectInicioDLL
Class38=CDlgPropConectFinDLL
Resource43=IDD_BLOQUEDIS (English (U.S.))
Resource44=IDR_PROYTYPE_SRVR_IP (English (U.S.))

[CLS:CBaseView]
Type=0
BaseClass=CScrollView
HeaderFile=view\BaseView.h
ImplementationFile=view\BaseView.cpp
LastObject=CBaseView
Filter=C
VirtualFilter=VWC

[CLS:CPropBlqDiag]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\bdiag\PropBlqDiag.h
ImplementationFile=view\bdiag\PropBlqDiag.cpp
LastObject=CPropBlqDiag
Filter=D
VirtualFilter=idWC

[CLS:CCambiaTxt]
Type=0
BaseClass=CDialog
HeaderFile=view\CambiaTxt.h
ImplementationFile=view\CambiaTxt.cpp

[CLS:CDiagDisView]
Type=0
BaseClass=CBaseView
HeaderFile=view\des\DiagDisView.h
ImplementationFile=view\des\DiagDisView.cpp
LastObject=CDiagDisView
Filter=C
VirtualFilter=VWC

[CLS:CDlgBloqueDis]
Type=0
BaseClass=CDlgBloque
HeaderFile=view\des\DlgBloqueDis.h
ImplementationFile=view\des\DlgBloqueDis.cpp
LastObject=CDlgBloqueDis
Filter=D
VirtualFilter=dWC

[CLS:CDlgNudoCon]
Type=0
BaseClass=CDialog
HeaderFile=view\des\DlgNudoCon.h
ImplementationFile=view\des\DlgNudoCon.cpp

[CLS:CPropRejilla]
Type=0
BaseClass=CDialog
HeaderFile=view\des\PropRejilla.h
ImplementationFile=view\des\PropRejilla.cpp

[CLS:CBotonTabla]
Type=0
BaseClass=CButton
HeaderFile=view\des\TablaDis.h
ImplementationFile=view\des\TablaDis.cpp

[CLS:CTablaDis]
Type=0
BaseClass=CDialogBar
HeaderFile=view\des\TablaDis.h
ImplementationFile=view\des\TablaDis.cpp

[CLS:CDlgPropBloqueConectores]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\DlgPropBloqueConectores.h
ImplementationFile=view\DlgPropBloqueConectores.cpp
LastObject=CDlgPropBloqueConectores
Filter=D
VirtualFilter=idWC

[CLS:CDlgPropDiagComponentes]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\DlgPropDiagComponentes.h
ImplementationFile=view\DlgPropDiagComponentes.cpp
Filter=D
VirtualFilter=idWC

[CLS:CDlgPropDiagInform]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\DlgPropDiagInform.h
ImplementationFile=view\DlgPropDiagInform.cpp

[CLS:CDlgPropDiagrama]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\DlgPropDiagrama.h
ImplementationFile=view\DlgPropDiagrama.cpp

[CLS:CDlgGeneracionCodigoConDLL]
Type=0
BaseClass=CDialog
HeaderFile=view\dll\DlgGeneracionCodigoConDLL.h
ImplementationFile=view\dll\DlgGeneracionCodigoConDLL.cpp

[CLS:CDlgGeneracionCodigoSinDLL]
Type=0
BaseClass=CDialog
HeaderFile=view\dll\DlgGeneracionCodigoSinDLL.h
ImplementationFile=view\dll\DlgGeneracionCodigoSinDLL.cpp

[CLS:CDlgPropiedadesClasesConDLL]
Type=0
BaseClass=CDialog
HeaderFile=view\dll\DlgPropiedadesClasesConDLL.h
ImplementationFile=view\dll\DlgPropiedadesClasesConDLL.cpp
Filter=D
VirtualFilter=dWC

[CLS:CDlgPropiedadesClasesSinDLL]
Type=0
BaseClass=CDialog
HeaderFile=view\dll\DlgPropiedadesClasesSinDLL.h
ImplementationFile=view\dll\DlgPropiedadesClasesSinDLL.cpp
Filter=D
VirtualFilter=dWC

[CLS:CPropBlqDLL]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\dll\PropBlqDLL.h
ImplementationFile=view\dll\PropBlqDLL.cpp

[CLS:CDMensaje]
Type=0
BaseClass=CDialog
HeaderFile=view\DMensaje.h
ImplementationFile=view\DMensaje.cpp

[CLS:CDConfirm]
Type=0
BaseClass=CDialog
HeaderFile=view\DMensaje.h
ImplementationFile=view\DMensaje.cpp

[CLS:CDiagExeView]
Type=0
BaseClass=CBaseView
HeaderFile=view\exe\DiagExeView.h
ImplementationFile=view\exe\DiagExeView.cpp
LastObject=CDiagExeView
Filter=C
VirtualFilter=VWC

[CLS:CDlgBloqueExe]
Type=0
BaseClass=CDialog
HeaderFile=view\exe\DlgBloqueExe.h
ImplementationFile=view\exe\DlgBloqueExe.cpp

[CLS:CDlgCancelAuto]
Type=0
BaseClass=CDialog
HeaderFile=view\exe\DlgCancelAuto.h
ImplementationFile=view\exe\DlgCancelAuto.cpp

[CLS:CDlgLog]
Type=0
BaseClass=CDialog
HeaderFile=view\exe\DlgLog.h
ImplementationFile=view\exe\DlgLog.cpp

[CLS:COperacBloque]
Type=0
BaseClass=CDialog
HeaderFile=view\exe\DlgOperacBloque.h
ImplementationFile=view\exe\DlgOperacBloque.cpp

[CLS:COperacBRetro]
Type=0
BaseClass=CDialog
HeaderFile=view\exe\DlgOperacBRetro.h
ImplementationFile=view\exe\DlgOperacBRetro.cpp

[CLS:CInPlaceFrame]
Type=0
BaseClass=COleIPFrameWnd
HeaderFile=view\exe\InPlaceFrame.h
ImplementationFile=view\exe\InPlaceFrame.cpp

[CLS:CPropMultiDiag]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\exe\PropMultiDiag.h
ImplementationFile=view\exe\PropMultiDiag.cpp

[CLS:CIdfFrame]
Type=0
BaseClass=CMDIChildWnd
HeaderFile=view\IdfFrame.h
ImplementationFile=view\IdfFrame.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CMDIFrameWnd
HeaderFile=view\MainFrame.h
ImplementationFile=view\MainFrame.cpp

[CLS:CMensajeLargo]
Type=0
BaseClass=CDialog
HeaderFile=view\MensajeLargo.h
ImplementationFile=view\MensajeLargo.cpp

[CLS:CPropBloque]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\PropBloque.h
ImplementationFile=view\PropBloque.cpp
LastObject=CPropBloque
Filter=D
VirtualFilter=idWC

[CLS:CPropBloqueInform]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\PropBloqueInform.h
ImplementationFile=view\PropBloqueInform.cpp
LastObject=CPropBloqueInform

[CLS:CPropConect]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\PropConect.h
ImplementationFile=view\PropConect.cpp

[CLS:CPropConectInform]
Type=0
BaseClass=CPropertyPage
HeaderFile=view\PropConectInform.h
ImplementationFile=view\PropConectInform.cpp

[CLS:CPropiedadesConector]
Type=0
BaseClass=CPropertySheet
HeaderFile=view\PropiedadesConector.h
ImplementationFile=view\PropiedadesConector.cpp

[DLG:IDD_PROPBLOQUE_DIAG]
Type=1
Class=CPropBlqDiag

[DLG:IDD_NUEVOTXT]
Type=1
Class=CCambiaTxt

[DLG:IDD_BLOQUEDIS]
Type=1
Class=CDlgBloqueDis

[DLG:IDD_NUDOCON]
Type=1
Class=CDlgNudoCon

[DLG:IDD_PROPREJILLA]
Type=1
Class=CPropRejilla

[DLG:IDD_TABLADISENO]
Type=1
Class=CTablaDis

[DLG:IDD_PROPBLOQUE_CONECTORES]
Type=1
Class=CDlgPropBloqueConectores

[DLG:IDD_PROPDIAG_COMPONENTES]
Type=1
Class=CDlgPropDiagComponentes

[DLG:IDD_PROPDIAG_INFORM]
Type=1
Class=CDlgPropDiagInform

[DLG:IDD_PROPDIAG]
Type=1
Class=CDlgPropDiagrama

[DLG:IDD_ANALISIS_DLL]
Type=1
Class=CDlgGeneracionCodigoConDLL

[DLG:IDD_PROP_CLASES_CON_DLL]
Type=1
Class=CDlgPropiedadesClasesConDLL

[DLG:IDD_PROP_CLASES_SIN_DLL]
Type=1
Class=CDlgPropiedadesClasesSinDLL

[DLG:IDD_PROPBLOQUE_DLL]
Type=1
Class=CPropBlqDLL

[DLG:IDD_MENSAJE]
Type=1
Class=CDMensaje

[DLG:IDD_CONFIRM]
Type=1
Class=CDConfirm

[DLG:IDD_BLOQUE]
Type=1
Class=CDlgBloque

[DLG:IDD_CANCEL_AUTO]
Type=1
Class=CDlgCancelAuto

[DLG:IDD_LOGDIAG]
Type=1
Class=CDlgLog

[DLG:IDD_OPERAC_BLOQUE]
Type=1
Class=COperacBloque

[DLG:IDD_OPERAC_BRETRO]
Type=1
Class=COperacBRetro

[DLG:IDD_MULTIDIAG]
Type=1
Class=CPropMultiDiag

[DLG:IDD_MENSAJE_EXT]
Type=1
Class=CMensajeLargo

[DLG:IDD_PROPBLOQUE]
Type=1
Class=CPropBloque

[DLG:IDD_PROPBLOQUE_INFORM]
Type=1
Class=CPropBloqueInform

[DLG:IDD_PROP_CONECT]
Type=1
Class=CPropConect

[DLG:IDD_PROP_CONECT_INFORM]
Type=1
Class=CPropConectInform

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CLEAR
Command9=ID_EDIT_CUT
Command10=ID_CANCEL_EDIT
Command11=ID_HELP
Command12=ID_CONTEXT_HELP
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_EDIT_CUT
Command18=ID_EDIT_UNDO
CommandCount=18

[ACL:IDR_PROYTYPE_CNTR_IP (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT
Command4=ID_FILE_SAVE
Command5=ID_CANCEL_EDIT
Command6=ID_HELP
Command7=ID_CONTEXT_HELP
Command8=ID_NEXT_PANE
Command9=ID_PREV_PANE
CommandCount=9

[ACL:IDR_PROYTYPE_SRVR_EMB (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_OLE_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_UPDATE
Command6=ID_EDIT_OLE_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_CANCEL_EDIT
Command10=ID_HELP
Command11=ID_CONTEXT_HELP
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_EDIT_OLE_CUT
Command17=ID_EDIT_UNDO
CommandCount=17

[ACL:IDR_PROYTYPE_SRVR_IP (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_OLE_COPY
Command2=ID_EDIT_OLE_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_HELP
Command6=ID_CONTEXT_HELP
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_OLE_CUT
Command10=ID_EDIT_UNDO
CommandCount=10

[ACL:IDR_PROYTYPE (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_OLE_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_OLE_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CLEAR
Command9=ID_CANCEL_EDIT
Command10=ID_HELP
Command11=ID_CONTEXT_HELP
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_EDIT_OLE_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[DLG:IDD_BLOQUE (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_ETIQ,static,1342374017

[DLG:IDD_BLOQUEDIS (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_ETIQ,static,1342374017

[DLG:IDD_CANCEL_AUTO (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDCANCEL,button,1342242816

[DLG:IDD_CONFIRM (English (U.S.))]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342373889
Control2=IDC_TEXTOMEN,static,1342308353
Control3=IDCANCEL,button,1342373888

[DLG:IDD_LOGDIAG (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_LISTA_CON,listbox,1353779200

[DLG:IDD_MENSAJE (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342373889
Control2=IDC_TEXTOMEN,static,1342308353

[DLG:IDD_MENSAJE_EXT (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342373889
Control2=IDC_TEXTO,edit,1352734724

[DLG:IDD_MULTIDIAG (English (U.S.))]
Type=1
Class=?
ControlCount=14
Control1=IDC_DIAG_PADRE,edit,1350633600
Control2=IDC_STATIC,button,1342177287
Control3=IDC_PROP_DIAGPADRE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BLOQUE_INICIO,edit,1350633600
Control7=IDC_BLOQUE_FIN,edit,1350633600
Control8=IDC_STATIC,button,1342177287
Control9=IDC_PROP_INICIO,button,1342242816
Control10=IDC_PROP_FIN,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_BLOQUE_DIAGRAMA,edit,1350633600
Control13=IDC_STATIC,static,1342308352
Control14=IDC_PROP_BLOQUEDIAG,button,1342242816

[DLG:IDD_NUDOCON (English (U.S.))]
Type=1
Class=?
ControlCount=0

[DLG:IDD_NUEVOTXT (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TEXTO,edit,1350631552
Control4=IDC_TITULO,static,1342308353

[DLG:IDD_OPERAC_BLOQUE (English (U.S.))]
Type=1
Class=?
ControlCount=10
Control1=IDC_ACEPTAR_DATOS,button,1342242816
Control2=IDC_DEVOLVER_DATOS,button,1342242816
Control3=IDC_RETROANOTA,button,1342242816
Control4=IDC_ENVIAR_RETROANO,button,1342242816
Control5=IDC_RECIBIR_RETROANO,button,1342242816
Control6=IDC_CONECTOR_ETIQ,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDCANCEL,button,1342242817
Control9=IDC_STATIC,button,1342177287
Control10=IDC_ACCION,button,1342242816

[DLG:IDD_OPERAC_BRETRO (English (U.S.))]
Type=1
Class=?
ControlCount=7
Control1=IDC_RETROANOTA,button,1342242816
Control2=IDC_ENVIAR_RETROANO,button,1342242816
Control3=IDC_RECIBIR_RETROANO,button,1342242816
Control4=IDC_CONECTOR_ETIQ,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDCANCEL,button,1342242817
Control7=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_CONECT (English (U.S.))]
Type=1
Class=?
ControlCount=24
Control1=IDC_ETIQ,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BLOQUE_INICIAL,edit,1350633600
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PROPBLOQ_INI,button,1342242816
Control8=IDC_BLOQUE_FIN,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_PROPBLOQ_FIN,button,1342242816
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_VISIBLE,button,1342242819
Control14=IDC_GROSOR,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,button,1342177287
Control18=IDC_LISTAR_CLASES,button,1342242816
Control19=IDC_CLASE_COM,combobox,1344340226
Control20=IDC_INSPECCION_CODIGO,button,1342242816
Control21=IDC_GENERACION_CODIGO,button,1342242816
Control22=IDC_ALTURAFLECHA,edit,1350631552
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,button,1342177287

[DLG:IDD_TABLADISENO (English (U.S.))]
Type=1
Class=?
ControlCount=8
Control1=IDC_INS_BLQFUNC_DIAG,button,1342242816
Control2=IDC_INS_BLQFUNC_DLL,button,1342242817
Control3=IDC_INS_BLQ_RETRO,button,1342242816
Control4=IDC_INS_CONECT,button,1342242816
Control5=IDC_INS_CONECT_RETRO,button,1342242816
Control6=IDC_CPOSETIQDIAG,button,1342242816
Control7=IDC_CANCELAR_EDIC,button,1342242816
Control8=IDC_MOVGRUPOSEL,button,1342242816

[DLG:IDD_PROP_CONECT_INFORM (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDC_TEXTO_AYUDA,edit,1353781444
Control2=65535,static,1342308352

[DLG:IDD_ANALISIS_DLL (English (U.S.))]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DLLDIAGRAMA,edit,1484849280
Control4=IDC_EDIT_IMPLEMENTACION,edit,1353781444
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_CABECERAS,edit,1353781444
Control7=IDC_STATIC,static,1342308352
Control8=IDC_SALVAR_H,button,1342242816
Control9=IDC_SALVAR_CPP,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_CLASES_CON_DLL (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_PROP_DLL_ARBOL,SysTreeView32,1350631431
Control2=IDC_DLLDIAGRAMA,edit,1350631552
Control3=IDC_CAMBIA_DLL,button,1342242816
Control4=IDC_GENERAR_CODIGO,button,1342242816

[DLG:IDD_PROP_CLASES_SIN_DLL (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDC_PROP_DLL_ARBOL,SysTreeView32,1350631431
Control2=IDC_GENERAR_CODIGO,button,1342242816

[MNU:ID_OBJECT_POPUP_MENU (English (U.S.))]
Type=1
Class=?
Command1=ID_OLEITEM_BLOQUEAR
Command2=ID_OBJECT_DISPLAYCONTENT
Command3=ID_OBJECT_DISPLAYASICON
Command4=ID_OLE_EDIT_CHANGE_ICON
Command5=ID_OBJECT_RESETSIZE
Command6=ID_NOMBRE_ITEM
Command7=ID_EDIT_OLE_CUT
Command8=ID_EDIT_OLE_COPY
Command9=ID_EDIT_CLEAR
Command10=ID_OLE_VERB_FIRST
CommandCount=10

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_HELP_INDEX
Command9=ID_HELP_USING
Command10=ID_APP_ABOUT
CommandCount=10

[MNU:IDR_MENU_CONEC_DCHO (English (U.S.))]
Type=1
Class=?
Command1=ID_PROPIEDADES
Command2=ID_LIBERAR_RATON
Command3=ID_IRALNUDOSIG
Command4=ID_IRALNUDOPREV
Command5=ID_ANYADIRNUDOANT
Command6=ID_ANYADIRNUDOPOST
Command7=ID_CAMBIAPOSETIQ
Command8=ID_ASOCIAR_BLQINI
Command9=ID_ASOCIAR_BLQFIN
Command10=ID_GRAVASOCIAR_BLQINI
Command11=ID_GRAVASOCIAR_BLQFIN
Command12=ID_SELEC_NUDO
Command13=ID_SELEC_CONECTOR
Command14=ID_ELIMINARNUDO
Command15=ID_ELIMINAR_CONEC
CommandCount=15

[MNU:IDR_PROY_DISENO (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_SELECC_TODO
Command16=ID_ANULARSELECC
Command17=ID_SELECC_RECT
Command18=ID_DESELECC_RECT
Command19=ID_SELECC_ELIMINAR
Command20=ID_INS_BLQFUNC_DLL
Command21=ID_INS_BLQFUNC_DIAG
Command22=ID_INS_BLQ_RETRO
Command23=ID_INS_CONECT
Command24=ID_INS_CONECT_RETRO
Command25=ID_CPOSETIQDIAG
Command26=ID_MOVERGRUPO
Command27=ID_CANCELAR_EDIC
Command28=ID_PROP_DIAG
Command29=ID_PROP_REJILLA
Command30=ID_ANALIZAR_DLL
Command31=ID_CLASES_USADAS_SIN_DLL
Command32=ID_EJECUTAR_DIAG
Command33=ID_GENERAR_LDDORIGEN
Command34=ID_GENERAR_LDD
Command35=ID_GENERAR_METAFILE
Command36=ID_OPERAC_ZOOM
Command37=ID_AJUSTAR_VENTANA
Command38=ID_ZOOM_RESTAURAR
Command39=ID_ZOOM_ACERCAR
Command40=ID_ZOOM_ALEJAR
Command41=ID_VER_TODO
Command42=ID_VIEW_TOOLBAR
Command43=ID_VIEW_STATUS_BAR
Command44=ID_VER_TABLADIAG
Command45=ID_WINDOW_NEW
Command46=ID_WINDOW_CASCADE
Command47=ID_WINDOW_TILE_HORZ
Command48=ID_WINDOW_ARRANGE
Command49=ID_HELP_INDEX
Command50=ID_HELP_USING
Command51=ID_APP_ABOUT
CommandCount=51

[MNU:IDR_PROYTYPE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_COPIARDIAG
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_PROP_DIAG
Command16=ID_ANALIZAR_DLL
Command17=ID_CLASES_USADAS_SIN_DLL
Command18=ID_EDITAR_DIAG
Command19=ID_INICIALIZAR_DIAGRAMA
Command20=ID_INICIAR_CONECT
Command21=ID_GENERAR_LDDORIGEN
Command22=ID_GENERAR_LDD
Command23=ID_GENERAR_METAFILE
Command24=ID_CONSOLA_MOSTRAR
Command25=ID_CONSOLA_MOSTRAR_USUARIO
Command26=ID_CONSOLA_MOSTRAR_SISTEMA
Command27=ID_CONSOLA_SALVAR_CON_DIAGRAMA
Command28=ID_SCROLL_AUTO
Command29=ID_OPERAC_ZOOM
Command30=ID_AJUSTAR_VENTANA
Command31=ID_ZOOM_RESTAURAR
Command32=ID_ZOOM_ACERCAR
Command33=ID_ZOOM_ALEJAR
Command34=ID_VER_TODO
Command35=ID_WINDOW_NEW
Command36=ID_WINDOW_CASCADE
Command37=ID_WINDOW_TILE_HORZ
Command38=ID_WINDOW_ARRANGE
Command39=ID_HELP_INDEX
Command40=ID_HELP_USING
Command41=ID_APP_ABOUT
CommandCount=41

[MNU:IDR_PROYTYPE_CNTR_IP (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_WINDOW_NEW
Command12=ID_WINDOW_CASCADE
Command13=ID_WINDOW_TILE_HORZ
Command14=ID_WINDOW_ARRANGE
CommandCount=14

[MNU:IDR_PROYTYPE_SRVR_EMB (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_UPDATE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_COPIARDIAG
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_PROP_DIAG
Command16=ID_ANALIZAR_DLL
Command17=ID_CLASES_USADAS_SIN_DLL
Command18=ID_EDITAR_DIAG
Command19=ID_INICIALIZAR_DIAGRAMA
Command20=ID_INICIAR_CONECT
Command21=ID_GENERAR_LDDORIGEN
Command22=ID_GENERAR_LDD
Command23=ID_GENERAR_METAFILE
Command24=ID_CONSOLA_MOSTRAR
Command25=ID_CONSOLA_MOSTRAR_USUARIO
Command26=ID_CONSOLA_MOSTRAR_SISTEMA
Command27=ID_CONSOLA_SALVAR_CON_DIAGRAMA
Command28=ID_SCROLL_AUTO
Command29=ID_OPERAC_ZOOM
Command30=ID_AJUSTAR_VENTANA
Command31=ID_ZOOM_RESTAURAR
Command32=ID_ZOOM_ACERCAR
Command33=ID_ZOOM_ALEJAR
Command34=ID_VER_TODO
Command35=ID_WINDOW_NEW
Command36=ID_WINDOW_CASCADE
Command37=ID_WINDOW_TILE_HORZ
Command38=ID_WINDOW_ARRANGE
Command39=ID_HELP_INDEX
Command40=ID_HELP_USING
Command41=ID_APP_ABOUT
CommandCount=41

[MNU:IDR_PROYTYPE_SRVR_IP (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_COPIARDIAG
Command3=ID_EDIT_OLE_CUT
Command4=ID_EDIT_OLE_COPY
Command5=ID_EDIT_OLE_PASTE
Command6=ID_EDIT_PASTE_SPECIAL
Command7=ID_EDIT_PASTE_LINK
Command8=ID_EDIT_CLONE
Command9=ID_EDIT_CLEAR
Command10=ID_EDIT_CLEAR_ALL
Command11=ID_OLE_INSERT_NEW
Command12=ID_OLE_EDIT_LINKS
Command13=ID_OLE_VERB_FIRST
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_PROP_DIAG
Command17=ID_ANALIZAR_DLL
Command18=ID_CLASES_USADAS_SIN_DLL
Command19=ID_EDITAR_DIAG
Command20=ID_INICIALIZAR_DIAGRAMA
Command21=ID_INICIAR_CONECT
Command22=ID_GENERAR_LDDORIGEN
Command23=ID_GENERAR_LDD
Command24=ID_GENERAR_METAFILE
Command25=ID_CONSOLA_MOSTRAR
Command26=ID_CONSOLA_MOSTRAR_USUARIO
Command27=ID_CONSOLA_MOSTRAR_SISTEMA
Command28=ID_CONSOLA_SALVAR_CON_DIAGRAMA
Command29=ID_SCROLL_AUTO
Command30=ID_OPERAC_ZOOM
Command31=ID_AJUSTAR_VENTANA
Command32=ID_ZOOM_RESTAURAR
Command33=ID_ZOOM_ACERCAR
Command34=ID_ZOOM_ALEJAR
Command35=ID_VER_TODO
Command36=ID_HELP_INDEX
Command37=ID_HELP_USING
Command38=ID_APP_ABOUT
CommandCount=38

[MNU:IDR_MENU_CONSOLA (English (U.S.))]
Type=1
Class=?
Command1=ID_CONSOLA_SALVA
Command2=ID_CONSOLA_SALIDA
Command3=ID_CONSOLA_CORTAR
Command4=ID_CONSOLA_COPIAR
Command5=ID_CONSOLA_LIMPIAR
CommandCount=5

[MNU:IDR_MENU_CLASEDLL_POPUP (English (U.S.))]
Type=1
Class=?
Command1=ID_CLASEDLL_GENERAR_CODIGO
CommandCount=1

[MNU:IDR_MENU_COMPONENTE_PROP_POPUP (English (U.S.))]
Type=1
Class=?
Command1=ID_MENU_COMPONENTE_PROP
CommandCount=1

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
CommandCount=9

[TB:IDR_PROYTYPE_SRVR_IP (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_APP_ABOUT
Command5=ID_CONTEXT_HELP
CommandCount=5

[CLS:CDlgPropConectInicioDLL]
Type=0
HeaderFile=view\dll\dlgpropconectiniciodll.h
ImplementationFile=view\dll\dlgpropconectiniciodll.cpp
BaseClass=CDlgPropConectExtremoDLL
Filter=D
VirtualFilter=dWC

[CLS:CDlgPropConectFinDLL]
Type=0
HeaderFile=view\dll\dlgpropconectfindll.h
ImplementationFile=view\dll\dlgpropconectfindll.cpp
BaseClass=CDlgPropConectExtremoDLL
LastObject=CDlgPropConectFinDLL
Filter=D
VirtualFilter=dWC

[DLG:IDD_PROP_BLOQUE (English (U.S.))]
Type=1
Class=?
ControlCount=29
Control1=IDC_ESTADOUSUARIO,combobox,1344340227
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ETIQUETA,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ACTIVO_ENTRADA,button,1342242819
Control6=IDC_ACTIVO_SALIDA,button,1342242819
Control7=IDC_STATIC,static,1342308352
Control8=IDC_ESTADOINTERNO,edit,1350633600
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_SALIDA_AUTO,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_MAXITER_AUTO,edit,1350631552
Control16=IDC_STATIC,button,1342177287
Control17=IDC_ID,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,button,1342177287
Control21=IDC_TIPO_BLOQUE,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_TIPO_DIBUJO,combobox,1344340227
Control24=IDC_STATIC,button,1342177287
Control25=IDC_VISIBLE,button,1342242819
Control26=IDC_OPERACIONES,button,1342242816
Control27=IDC_GROSOR,edit,1350631552
Control28=IDC_STATIC,static,1342308352
Control29=IDC_ORDEN_BLOQUE,edit,1350633600

[DLG:IDD_PROP_DIAG (English (U.S.))]
Type=1
Class=?
ControlCount=21
Control1=IDC_TITULO,edit,1350631552
Control2=IDC_STATIC,button,1342177287
Control3=IDC_FICHLDD,edit,1350631552
Control4=IDC_CAMBIA_LDD,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_FICHBIN,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_DLLDIAG,edit,1350631552
Control11=IDC_CAMBIA_DLLDIAG,button,1342242816
Control12=IDC_USADLL,button,1342242819
Control13=IDC_STATIC,button,1342177287
Control14=IDC_FECHA,edit,1350633600
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,button,1342177287
Control18=IDC_DIR_LIBRERIAS,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,button,1342177287
Control21=IDC_POSHORIZONTAL,button,1342242819

[DLG:IDD_PROP_BLOQUE_DIAG (English (U.S.))]
Type=1
Class=CPropBlqDiag
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DIAG_HIJO,edit,1350633600
Control4=IDC_HIJOTIPOFICH,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_PROP_INICIO,button,1342242816
Control9=IDC_PROP_FIN,button,1342242816
Control10=IDC_PROP_DIAGHIJO,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_FICH_HIJO,edit,1350631552
Control13=IDC_CAMBIA_HIJO,button,1342242816
Control14=IDC_FECHA,edit,1350633600
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_VENT_HIJO,combobox,1344339971
Control18=IDC_BLOQUE_INICIO,combobox,1344340226
Control19=IDC_BLOQUE_FIN,combobox,1344340226

[DLG:IDD_PROP_BLOQUE_DLL (English (U.S.))]
Type=1
Class=?
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DLLBLOQUE,edit,1350631552
Control4=IDC_CAMBIA_DLL,button,1342242816
Control5=IDC_USADLLDIAG,button,1342242819
Control6=IDC_STATIC,button,1342177287
Control7=IDC_FECHA,edit,1350633600
Control8=IDC_STATIC,static,1342308352
Control9=IDC_MACRO,edit,1353781444
Control10=IDC_STATIC,static,1342308352
Control11=IDC_PROP_USUARIO,button,1342242816
Control12=IDC_CLASE_BLOQUE,combobox,1344340226
Control13=IDC_LISTAR_CLASES,button,1342242816
Control14=IDC_INSPECCION_CODIGO,button,1342242816
Control15=IDC_GENERACION_CODIGO,button,1342242816

[DLG:IDD_PROP_REJILLA (English (U.S.))]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_INCX,edit,1350631552
Control4=IDC_INCY,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_FORZCOOR,button,1342242819
Control8=IDC_VERREJILLA,button,1342242819
Control9=ID_AYUDA,button,1342242816

[DLG:IDD_PROP_BLOQUE_INFORM (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDC_AYUDA,edit,1353781444
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_DIAG_INFORM (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDC_AYUDA,edit,1353781444
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_DIAG_COMPONENTES (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_DIAG_ARBOL,SysTreeView32,1350631431

[DLG:IDD_PROP_BLOQUE_CONECTORES (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_BLOQUE_ARBOL,SysTreeView32,1350631431

[DLG:IDD_ANALISIS_CLASE (English (U.S.))]
Type=1
Class=CDlgGeneracionCodigoSinDLL
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_EDIT_IMPLEMENTACION,edit,1353781444
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_CABECERAS,edit,1353781444
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SALVAR_H,button,1342242816
Control7=IDC_SALVAR_CPP,button,1342242816

[DLG:IDD_PROP_CONECT_INICIO_DLL (English (U.S.))]
Type=1
Class=CDlgPropConectInicioDLL
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,button,1342177287
Control3=IDC_LISTAR_CLASES,button,1342242816
Control4=IDC_CLASE_COM,combobox,1344340226
Control5=IDC_INSPECCION_CODIGO,button,1342242816
Control6=IDC_GENERACION_CODIGO,button,1342242816

[DLG:IDD_PROP_CONECT_FIN_DLL (English (U.S.))]
Type=1
Class=CDlgPropConectFinDLL
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,button,1342177287
Control3=IDC_LISTAR_CLASES,button,1342242816
Control4=IDC_CLASE_COM,combobox,1344340226
Control5=IDC_INSPECCION_CODIGO,button,1342242816
Control6=IDC_GENERACION_CODIGO,button,1342242816

[MNU:IDR_MENU_BLOQUE_FUNC_DCHO (English (U.S.))]
Type=1
Class=?
Command1=ID_PROP_GEN
Command2=ID_PROP_ESPEC
Command3=ID_PROP_LISTACONECT
Command4=ID_PROP_INFORM
Command5=ID_PROP_DLL
Command6=ID_OPERACIONES
CommandCount=6

[MNU:IDR_MENU_BLOQUE_DIS_DCHO (English (U.S.))]
Type=1
Class=?
Command1=ID_PROP_GEN
Command2=ID_PROP_ESPEC
Command3=ID_PROP_LISTACONECT
Command4=ID_PROP_INFORM
Command5=ID_SELEC_BLOQUE
Command6=ID_CARGAR_SUBDIAGRAMA
Command7=ID_ELIMINAR_BLOQUE
CommandCount=7

