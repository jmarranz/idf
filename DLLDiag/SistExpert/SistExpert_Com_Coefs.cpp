

#include "stdafx.h"

#include "..\DLLDiag.h"


#include "..\CtrlAdap\CtrlAdap_Com_Var.h"

#include "SistExpert_Com_Coefs.h"


IMPLEMENTAR_COMUNICACION(SistExpert_Com_Coefs,CCom,1) 

IMPLEMENTAR_VARIABLE_COM(SistExpert_Com_Coefs, double, ce)
IMPLEMENTAR_VARIABLE_COM(SistExpert_Com_Coefs, double, cde)
IMPLEMENTAR_VARIABLE_COM(SistExpert_Com_Coefs, double, cdu)
