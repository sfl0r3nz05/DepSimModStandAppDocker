
#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME DN_PROCESS

#include "simstruc.h"

#include <malloc.h>
#include <math.h>

#include "DN_PROCESS.h"      //Definiciones del proceso y del modelo.


//***************FUNCION DE CHEQUEO DE PARAMETROS DE ENTRADA DE LA S-FUNCTION****************
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
static void mdlCheckParameters(SimStruct *S)
{
	int_T i;

   	for (i=0;i<NUMPARAM_SFUNCT;i++)
	{
		real_T *pr;
		int_T el;
		int_T nEls;

		if ( mxIsEmpty(ssGetSFcnParam(S,i)) || mxIsSparse(ssGetSFcnParam(S,i))	
			|| mxIsComplex(ssGetSFcnParam(S,i)) || !mxIsNumeric(ssGetSFcnParam(S,i)) )
		{ ssSetErrorStatus (S,"Error en los Parametros del Bloque"); return; }
		
		pr = mxGetPr(ssGetSFcnParam(S,i));
		nEls = mxGetNumberOfElements(ssGetSFcnParam(S,i));
		for (el=0;el<nEls;el++)
		{ if (!mxIsFinite(pr[el])) { ssSetErrorStatus (S,"Los Parametros del Bloque han de ser finitos"); return; } }
	}

	if (mxGetNumberOfElements(PARAM_ESTEQ(S)) != DIMPARAMESTEQ)
	{ ssSetErrorStatus (S,"Vector de Params erroneo");	return;	}

	if (mxGetNumberOfElements(CINETICS(S)) != DIMCINETICOS)
	{ ssSetErrorStatus (S,"Vector de Cineticos erroneo");	return;	}

	if (mxGetNumberOfElements(ARRHEN(S)) != DIMARRHENIUS)
	{ ssSetErrorStatus (S,"Vector de Arrhenius erroneo");	return;	}

	if (mxGetM(ESTEQUIOM(S)) != NUMFILESTEQ || mxGetN(ESTEQUIOM(S)) != NUMCOLESTEQ)
	{ ssSetErrorStatus (S,"Matriz de Estequiometrias erronea");	return;	}

	if (mxGetNumberOfElements(PARAMS_D(S)) != DIMPARAMS_D)
	{ ssSetErrorStatus (S,"Vector de Parámetros erroneo en Tanque D"); return; }

	if (mxGetNumberOfElements(PARAMS_N(S)) != DIMPARAMS_N)
	{
		ssSetErrorStatus(S, "Vector de Parámetros erroneo en Tanque N"); return;
	}
	
	if (mxGetNumberOfElements(INICIALES(S)) != (DIMINICIALES))
	{ ssSetErrorStatus (S,"Vector de Estados Iniciales erroneo"); return; }


}
#endif // MDL_CHECK_PARAMETERS



//*******************FUNCION DE INICIALIZACION DEL BLOQUE S-FUNCTION***********************

static void mdlInitializeSizes(SimStruct *S)
{	                              
	void **PWork = ssGetPWork(S);                     //Returns the pointer work vector used by the block 
	
	ssSetNumSFcnParams(S, NUMPARAM_SFUNCT);           // Number of expected parameters  

    #if defined (MATLAB_MEX_FILE)
		if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) 
		{
		    mdlCheckParameters(S);                          // Chequear que los parámetros son correctos
			if (ssGetErrorStatus(S) != NULL) {return;}
		}
		else return;	
	#endif	

	// AQUÍ LA INICIALIZACIÓN
	// Lectura de Parametros de la S-Function
	ssSetNumPWork(S, NUMPWORKS);  //Specify the size of a block's pointer work vector
	ssSetNumRWork(S, NUMRWORKS);  //Specify the size of a block's real work vector
	
	ssSetNumContStates(S, NUMESTADOSCONTINUOS);				//Especifica el numero de estados continuos de S-function 
    ssSetNumDiscStates(S, NUMESTADOSDISCRETOS);  


    if (!ssSetNumInputPorts(S, NUMPUERTOSENTRADA)) {return;}
    ssSetInputPortWidth(S, IP_INFLUX, ANCHURAPUERTO1ENTRADA); ssSetInputPortDirectFeedThrough(S, IP_INFLUX, 1);
    ssSetInputPortWidth(S, IP_CONSIGNAS_CTRL, ANCHURAPUERTO2ENTRADA); ssSetInputPortDirectFeedThrough(S, IP_CONSIGNAS_CTRL, 1);
	ssSetInputPortWidth(S, IP_ENVIRONMENT, ANCHURAPUERTO3ENTRADA); ssSetInputPortDirectFeedThrough(S, IP_ENVIRONMENT, 1);
	ssSetInputPortWidth(S, IP_SETTLER, ANCHURAPUERTO4ENTRADA); ssSetInputPortDirectFeedThrough(S, IP_SETTLER, 1);

    if (!ssSetNumOutputPorts(S, NUMPUERTOSSALIDA)) {return;}
    ssSetOutputPortWidth(S,OP_SENSORES_D,ANCHURAPUERTO1SALIDA);
	ssSetOutputPortWidth(S, OP_SENSORES_N, ANCHURAPUERTO2SALIDA);
	ssSetOutputPortWidth(S,OP_EFF_STREAM,ANCHURAPUERTO3SALIDA);
	ssSetOutputPortWidth(S, OP_WASTE_STREAM, ANCHURAPUERTO4SALIDA);


    // Intervalos de Muestro
	ssSetNumSampleTimes(S, 1);    //Tiene 1 tiempos de muestreo
	ssSetNumModes(S, 0);          //Specify the size of the block's mode vector
    ssSetNumNonsampledZCs(S, 0);  //Specify the number of states for which a block detects 
	                              //zero crossings that occur between sample points
    ssSetOptions(S, 0);

}



//*******************FUNCION DE INICIALIZACION DEL TIEMPO DE MUESTREO***********************

static void mdlInitializeSampleTimes(SimStruct *S)
{
    	
	ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);

    //ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    //ssSetSampleTime(S, 1, PERIODO); 
}



//******************************FUNCION DE INICIALIZACION************************************

#define MDL_INITIALIZE_CONDITIONS                    /* Change to #undef to remove function */
#if defined(MDL_INITIALIZE_CONDITIONS)
static void mdlInitializeConditions(SimStruct *S)
{	
	int_T i;
	void **PWork = ssGetPWork(S);                     //Returns the pointer work vector used by the block
	real_T* RWork = ssGetRWork(S);
	
	real_T *xC = ssGetContStates(S);                  //to get the real_T continuous state vector
	real_T *xD = ssGetRealDiscStates(S);              //to get the real_T discrete state vector
	double DOsat(double);
	
	for (i=0;i<NUMPARAM_SFUNCT;i++) { PWork[i] = mxGetPr(ssGetSFcnParam(S,i)); }

	for (i=0;i<NUMESTADOSCONTINUOS;i++)	{xC[i] = x0[i];}  //Se carga en el vector "xC" los valores iniciales                                                        

	PWork[7] = (real_T *)malloc(sizeof(real_T)*(NUMCOEFCINETICOS));

	// Asignar Memoria para Estados Adicionales
	PWork[8] = (real_T **)malloc(sizeof(real_T *)*(NUM_ESTADOSADIC));

	((real_T **)PWork[8])[0] = (real_T*)malloc(sizeof(real_T) * (NUM_EASENSORES_D));
	((real_T **)PWork[8])[1] = (real_T*)malloc(sizeof(real_T) * (NUM_EASENSORES_N));
	((real_T **)PWork[8])[2] = (real_T*)malloc(sizeof(real_T) * (NUM_EA_REC_SETTLER));
	((real_T **)PWork[8])[3] = (real_T*)malloc(sizeof(real_T) * (NUM_EA_EFF_SETTLER));

	CROSS_AREA_N = V_N / H_TANK_N;
	NUM_DIFF = (DENS_DIFFUSERS / AREA_DIFFUSER) * CROSS_AREA_N;

	DO_SAT_20 = DOsat(20);

}

#endif /* MDL_INITIALIZE_CONDITIONS */



//*************************************FUNCION DE START******************************************


#define MDL_START                          /* Change to #undef to remove function */
#if defined(MDL_START) 
static void mdlStart(SimStruct *S)
{

}
#endif /*  MDL_START */


/****************************FUNCION DE GENERACION DE SALIDAS****************************
/* Function: mdlOutputs
    In this function, you compute the outputs of your S-function
    block. Generally outputs are placed in the output vector, ssGetY(S). */

static void mdlOutputs(SimStruct *S, int_T tid)
{
	int i;
	real_T *y;	// Puntero a los puertos de salida	
	real_T *xC = ssGetContStates(S);
	void **PWork = ssGetPWork(S);
	real_T *RWork = ssGetRWork(S);
	InputRealPtrsType uPtrs0 = ssGetInputPortRealSignalPtrs(S, IP_INFLUX);				/* Influx (kg/d) */
	InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S, IP_CONSIGNAS_CTRL);		/* Consignas */
	InputRealPtrsType uPtrs2 = ssGetInputPortRealSignalPtrs(S, IP_ENVIRONMENT);
	InputRealPtrsType uPtrs3 = ssGetInputPortRealSignalPtrs(S, IP_SETTLER);
	void CalcularEstadosAlgebraicos(SimStruct *);

	real_T *Sensores_D, *Sensores_N;
	real_T *Estados_Eff_Settler;

	Sensores_D = EA_SENSORES_D;
	Sensores_N = EA_SENSORES_N;

	Estados_Eff_Settler = EA_EFF_SETTLER;

	CalcularEstadosAlgebraicos(S);

	// SENSORES D
	//========================CALCULO DEL CAUDAL DE ENTRADA=================
	NO3_D = SNO_D;
	NH4_D = SNH_D;
	Temp_D = Temp_DN;

	// SENSORES N
	//========================CALCULO DEL CAUDAL DE ENTRADA=================
	NO3_N = SNO_N;
	NH4_N = SNH_N;
	DO_N = SO_N;	
	Temp_N = Temp_DN;

	N_DIFF = NUM_DIFF;
	DO_SAT = DO_SAT_T_N;


	//	SALIDA de SENSORS_D
	y = ssGetOutputPortRealSignal(S,OP_SENSORES_D); 
	for (i=0;i<ANCHURAPUERTO1SALIDA ;i++) { y[i] = Sensores_D[i];}

	//	SALIDA de SENSORS_N
	y = ssGetOutputPortRealSignal(S, OP_SENSORES_N);
	for (i = 0; i < ANCHURAPUERTO2SALIDA; i++) { y[i] = Sensores_N[i]; }
	
	// EFFLUENT
	y = ssGetOutputPortRealSignal(S,OP_EFF_STREAM);
	y[0] = Q_INF - QW_INP;
	for (i=0;i<NUMESTADOSMODASM1;i++) { y[i+1] = Estados_Eff_Settler[i];}

	// WASTE
	y = ssGetOutputPortRealSignal(S, OP_WASTE_STREAM);
	y[0] = QW_INP;
	for (i = 0; i < NUMESTADOSMODASM1; i++) { y[i + 1] = xC[POSINIEST(N_UNIT) + i]; }

}



/************************FUNCION DE ACTUALIZACION DE ESTADOS=====================

#define MDL_UPDATE                    /* Change to #undef to remove function */
#if defined(MDL_UPDATE)
static void mdlUpdate(SimStruct *S, int_T tid)
{


}
#endif /* MDL_UPDATE */


//**********************FUNCION QUE CALCULA LAS DERIVADAS********************

#define MDL_DERIVATIVES                /* Change to #undef to remove function */
#if defined(MDL_DERIVATIVES)
static void mdlDerivatives(SimStruct *S)
{
	int i;
	real_T *xC = ssGetContStates(S), *dX = ssGetdX(S);
	void **PWork = ssGetPWork(S);
	real_T *RWork = ssGetRWork(S);
	InputRealPtrsType uPtrs0 = ssGetInputPortRealSignalPtrs(S, IP_INFLUX);				/* Influx (kg/d) */
	InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S, IP_CONSIGNAS_CTRL);		/* Consignas */
	InputRealPtrsType uPtrs2 = ssGetInputPortRealSignalPtrs(S, IP_ENVIRONMENT);
	InputRealPtrsType uPtrs3 = ssGetInputPortRealSignalPtrs(S, IP_SETTLER);

	void CalcularEstadosAlgebraicos(SimStruct *);
	void CalcularDerivFisicas(real_T *, SimStruct *);
	double CalcConversionTerm(real_T *, real_T *, SimStruct *);
	real_T *Sensores_D, *Sensores_N;
	
	Sensores_D = EA_SENSORES_D;
	Sensores_N = EA_SENSORES_N;
	

	CalcularEstadosAlgebraicos(S);

	//==================================CALCULO DERIVADA BIOLOGICA======================
	for (i=0;i<NUMESTADOSCONTINUOS;i++){dX[i]=0;} 
	
	CalcularDerivFisicas(dX, S);
	
	OUR_D = CalcConversionTerm(&dX[POSINIEST(D_UNIT)], &xC[POSINIEST(D_UNIT)], S);
	OUR_N = CalcConversionTerm(&dX[POSINIEST(N_UNIT)], &xC[POSINIEST(N_UNIT)], S);

	dX[POSINIEST(D_UNIT) + EST_SO] += KLa_D * (DO_SAT_T_D - SO_D);
	dX[POSINIEST(N_UNIT) + EST_SO] += KLa_N * (DO_SAT_T_N - SO_N);

	
}
#endif /* MDL_DERIVATIVES */



/************************************FUNCION QUE TERMINA EL PROCESO*************************/

static void mdlTerminate(SimStruct *S)
{  
	int i;
	void **PWork = ssGetPWork(S); 

	if (CINETICOS_T != NULL) {free(CINETICOS_T);}

	// Memoria para estados adicionales
	for (i=0;i<NUM_ESTADOSADIC;i++) 
		if (ESTADOSADIC[i] != NULL) {free(ESTADOSADIC[i]);}
	
	if (ESTADOSADIC != NULL) {free(ESTADOSADIC);}
}


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


// ==============Funcion que calcula las derivadas=================== 
void CalcularDerivFisicas(real_T *dX, SimStruct *S) // Difusiones y attachment-detachment
{
	int idcEstado;
	real_T	*xC = ssGetContStates(S);
	void **PWork = ssGetPWork(S);
	real_T* RWork = ssGetRWork(S);
	InputRealPtrsType uPtrs0 = ssGetInputPortRealSignalPtrs(S,0);
	InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S,1);
	real_T *Estados_Rec_Settler;

	Estados_Rec_Settler = EA_REC_SETTLER;

	// Hidráulica Entrada-salida tanque
	for (idcEstado=0;idcEstado<NUMESTADOSMODASM1;idcEstado++)
	{ dX[POSINIEST(D_UNIT)+idcEstado] =  (Q_INF* (*uPtrs0[idcEstado + 1]) + QRE_REAL* Estados_Rec_Settler[idcEstado] + QRI_INP* xC[POSINIEST(N_UNIT) + idcEstado]
												- (Q_INF + QRE_REAL + QRI_INP) * xC[POSINIEST(D_UNIT) + idcEstado]) / V_D; }


	for (idcEstado = 0; idcEstado < NUMESTADOSMODASM1; idcEstado++)
	{
		dX[POSINIEST(N_UNIT) + idcEstado] = (Q_INF + QRE_REAL + QRI_INP) * (xC[POSINIEST(D_UNIT) + idcEstado] - xC[POSINIEST(N_UNIT) + idcEstado]) / V_N;
	}

}


double CalcConversionTerm(real_T *dX, real_T *xC, SimStruct *S)
{	
	void **PWork = ssGetPWork(S);
	real_T* RWork = ssGetRWork(S);

	double EstXS, EstXBH, EstXBA;
	double Rho1,Rho2,Rho3,Rho4,Rho5,Rho6,Rho7,Rho8, Rho9;
	double MonodSS, MonodSNH, SubMonodXS, MonodXS, SwitzeSOhet;
	double SwitchSOhet, SwitchSOaut, SwitchSNHhet, SwitchSNHaut, SwitchSNOhet;
	double OUR;
	
	// __________________________________________________________________________	
	// MONOD Y SWITCHING FUNCTIONS
	MonodSS=xC[EST_SS]/(kS+xC[EST_SS]);
	MonodSNH=xC[EST_SNH]/(kNH+xC[EST_SNH]);
	EstXS=xC[EST_XS]; EstXBH=xC[EST_XBH]; EstXBA=xC[EST_XBA];
	
	if(EstXS==0.0 || EstXBH==0.0) { MonodXS=0.0; }
	else { SubMonodXS=EstXS/EstXBH; MonodXS=SubMonodXS/(kX+SubMonodXS); }

	SwitzeSOhet=kOH/(kOH+xC[EST_SO]);
	SwitchSOhet=xC[EST_SO]/(kOH+xC[EST_SO]);
	SwitchSOaut=xC[EST_SO]/(kOA+xC[EST_SO]);

	SwitchSNHhet=xC[EST_SNH]/(kNHG+xC[EST_SNH]);
	SwitchSNHaut=xC[EST_SNH]/(kNH+xC[EST_SNH]);
	SwitchSNOhet=xC[EST_SNO]/(kNO+xC[EST_SNO]);

	// __________________________________________________________________________	
	// CINETICAS
	
	Rho1 = muH*MonodSS*SwitchSOhet*SwitchSNHhet*EstXBH;
	Rho2= muH*nuG*MonodSS*SwitzeSOhet*SwitchSNOhet*SwitchSNHhet*EstXBH;
	//Rho2 = muH*nuG*MonodSS*SwitzeSOhet*SwitchSNOhet*EstXBH;
	Rho3 = muA*SwitchSNHaut*SwitchSOaut*EstXBA;
	Rho4 = bH*EstXBH;
	Rho5 = bA*EstXBA;
	Rho6 = kA*xC[EST_SND]*EstXBH;
	Rho7 = kH*MonodXS*(SwitchSOhet+nuH*SwitzeSOhet*SwitchSNOhet)*EstXBH;
	Rho8 = Rho7*xC[EST_XND]/EstXS;
	Rho9 = 0; 

	OUR = -(ESTEQ_SO_R1 * Rho1 + ESTEQ_SO_R3 * Rho3 + ESTEQ_SO_R9 * Rho9);

	dX[EST_SS]+=ESTEQ_SS_R1*(Rho1+Rho2)+Rho7;
	dX[EST_SO] -= OUR;
	dX[EST_SNO]+=ESTEQ_SNO_R2*Rho2+ESTEQ_SNO_R3*Rho3;
	dX[EST_SNH]+=ESTEQ_SNH_R1*(Rho1+Rho2)+ESTEQ_SNH_R3*Rho3+ESTEQ_SNH_R6*Rho6;
	dX[EST_SND]+=Rho8-Rho6;
	dX[EST_SALK]+=ESTEQ_SALK_R1*Rho1+ESTEQ_SALK_R2*Rho2+ESTEQ_SALK_R3*Rho3+ESTEQ_SALK_R6*Rho6;

	dX[EST_XS]+=ESTEQ_XS_R4*(Rho4+Rho5)-Rho7;
	dX[EST_XBH]+=Rho1+Rho2-Rho4;
	dX[EST_XBA]+=Rho3-Rho5;
	dX[EST_XP]+=ESTEQ_XP_R4*(Rho4+Rho5);
	dX[EST_XND]+=ESTEQ_XND_R4*(Rho4+Rho5)-Rho8;

	return OUR;

}


void CalcularEstadosAlgebraicos(SimStruct *S)
{
	int i;
	real_T* xC = ssGetContStates(S);
	void** PWork = ssGetPWork(S);
	real_T* RWork = ssGetRWork(S);
	InputRealPtrsType uPtrs0 = ssGetInputPortRealSignalPtrs(S, IP_INFLUX);				/* Influx (kg/d) */
	InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S, IP_CONSIGNAS_CTRL);		/* Consignas */
	InputRealPtrsType uPtrs2 = ssGetInputPortRealSignalPtrs(S, IP_ENVIRONMENT);
	InputRealPtrsType uPtrs3 = ssGetInputPortRealSignalPtrs(S, IP_SETTLER);
	double DOsat(double), DO_sat_T, Qin_settler;

	real_T *Estados_Rec_Settler, *Estados_Eff_Settler;
	real_T *Sensores_D, *Sensores_N;

	Sensores_D = EA_SENSORES_D;
	Sensores_N = EA_SENSORES_N;

	Estados_Rec_Settler = EA_REC_SETTLER;
	Estados_Eff_Settler = EA_EFF_SETTLER;

	// Settler
	QRE_REAL = fmax(QRE_INP, 0.);
	Qin_settler = Q_INF - QW_INP + QRE_REAL;
	
	for (i = 0; i < NUMESTADOSDISUELT; i++) { Estados_Rec_Settler[i] = xC[POSINIEST(N_UNIT) + i]; }
	for (i = NUMESTADOSDISUELT; i < NUMESTADOSMODASM1; i++)
	{
		if (QRE_REAL == 0) {
			Estados_Rec_Settler[i] = 0.;
		}
		else { Estados_Rec_Settler[i] = (Qin_settler * (1 - FSETTLER_INP) + QRE_REAL * FSETTLER_INP) * (xC[POSINIEST(N_UNIT) + i]) / QRE_REAL; }
	}

	for (i = 0; i < NUMESTADOSDISUELT; i++) { Estados_Eff_Settler[i] = xC[POSINIEST(N_UNIT) + i]; }
	for (i = NUMESTADOSDISUELT; i < NUMESTADOSMODASM1; i++) { Estados_Eff_Settler[i] = FSETTLER_INP * xC[POSINIEST(N_UNIT) + i]; }


	Q_in_D = Q_INF + QRI_INP + QRE_REAL - QW_INP;
	Q_out_D = Q_in_D;

	Q_in_N = Q_out_D;
	Q_w_N = QW_INP;
	Q_out_N = Q_in_N - Q_w_N;


	Temp_DN = TEMP_ML_INP;

	RHO_W = 999.842594 + 6.793052E-2 * Temp_DN - 9.095290E-3 * pow(Temp_DN, 2) + 1.001685E-4 * pow(Temp_DN, 3)
		- 1.120083E-6 * pow(Temp_DN, 4) + 6.536332E-9 * pow(Temp_DN, 5);

	PV_TL = CNST_PAMB_N * exp(11.8571 - (3840.70 / (273.15 + Temp_DN)) - (216961 / pow(273.15 + Temp_DN, 2)));
	DO_sat_T = DOsat(Temp_DN);
	


	// Tanque D
	MLSS_D = iVSS_XB * (XBH_D + XBA_D) + iVSS_XI * (XI_D + XP_D) + iVSS_XS * XS_D + XIN_D;

	DELTA_D = (CNST_PAMB_N - PV_TL + RHO_W * CNST_GRAVITY * DE_TANK_D * H_TANK_D) / (CNST_PAMB_N - PV_TL);
	OMEGA_D = (PAMB_INP - PV_TL + RHO_W * CNST_GRAVITY * DE_TANK_D * H_TANK_D) / (CNST_PAMB_N - PV_TL + RHO_W * CNST_GRAVITY * DE_TANK_D * H_TANK_D);
	DO_SAT_T_D = OMEGA_D * BETA_FCT_D * DELTA_D * DO_sat_T;


	// Tanque N
	MLSS_N = iVSS_XB * (XBH_N + XBA_N) + iVSS_XI * (XI_N + XP_N) + iVSS_XS * XS_N + XIN_N;

	Q_AIR_DIFF = (QAIR_INP / NUM_DIFF) / 24.;

	OTE_N = (OTE_A_coeff + OTE_B_coeff * Q_AIR_DIFF + OTE_C_coeff * pow(Q_AIR_DIFF, 2)
		+ OTE_E_coeff * DENS_DIFFUSERS + OTE_F_coeff * pow(DENS_DIFFUSERS, 2)
		+ OTE_K_coeff * H_TANK_N + OTE_M_coeff * Q_AIR_DIFF * DENS_DIFFUSERS +
		+OTE_N_coeff * Q_AIR_DIFF * H_TANK_N + OTE_P_coeff * DENS_DIFFUSERS * H_TANK_N) / 100;

	EFF_DEPTH_N = DE_TANK_N * H_TANK_N;
	DELTA_N = (CNST_PAMB_N - PV_TL + RHO_W * CNST_GRAVITY * EFF_DEPTH_N) / (CNST_PAMB_N - PV_TL);
	OMEGA_N = (PAMB_INP - PV_TL + RHO_W * CNST_GRAVITY * EFF_DEPTH_N) / (CNST_PAMB_N - PV_TL + RHO_W * CNST_GRAVITY * EFF_DEPTH_N);

	DO_SAT_T_N = OMEGA_N * BETA_FCT_N * DELTA_N * DO_sat_T;

	KLa_N = (ALPHA_KLA_FCT * pow(THETA_KLA_COEFF, Temp_DN - 20) * OTE_N * CNST_MO2_AIR / (V_N * DELTA_N * DO_SAT_20)) * QAIR_INP;

	// Actualización de los coeficientes cinéticos
	for (i=0;i<NUMCOEFCINETICOS;i++) {CINETICOS_T[i] = CINETICOS_20[i]*pow(ARRHENIUS[i], Temp_DN - 20.);}

}


double DOsat(double Temp)
{
	return exp(-139.34411 + (157570.1 / (273.15 + Temp)) - (66423080 / pow(273.15 + Temp, 2)) + (12438000000 / pow(273.15 + Temp, 3)) - (862194900000 / pow(273.15 + Temp, 4)));
}


