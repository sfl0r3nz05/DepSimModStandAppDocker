

// Parametros del modelo nº 1
#include "ModN1.h"

// CARACTERISTICAS DE LA PLANTA
#define NUMREACTORES				2
#define D_UNIT						0
#define N_UNIT						1

#define NUMESTADOSCONTINUOS			(NUMESTADOSMODASM1*NUMREACTORES)
#define NUMESTADOSDISCRETOS			0


// CARACTERISTICAS DEL BLOQUE
// _____________________________________________________________________

#define NUMPUERTOSENTRADA			4
#define IP_INFLUX					0			// (QINF, STATES)
#define IP_CONSIGNAS_CTRL			1			// (QRI, QW, QAIR)
#define IP_ENVIRONMENT				2			// (P, TEMP)
#define IP_SETTLER					3			// (F_NS, QRE)


#define ANCHURAPUERTO1ENTRADA		(1+NUMESTADOSMODASM1)		// Caudal + concentraciones entrada            
#define ANCHURAPUERTO2ENTRADA		3							// (QRI, QW, QAIR)
#define ANCHURAPUERTO3ENTRADA		2							// (P_AMB + TEMP)
#define ANCHURAPUERTO4ENTRADA		2							// (F_NS, QRE)


#define NUMPUERTOSSALIDA			4 
#define OP_SENSORES_D				0
#define OP_SENSORES_N				1
#define OP_EFF_STREAM				2
#define OP_WASTE_STREAM				3


#define ANCHURAPUERTO1SALIDA		NUM_EASENSORES_D				// Sensores Tanque D
#define ANCHURAPUERTO2SALIDA		NUM_EASENSORES_N				// Sensores Tanque N
#define ANCHURAPUERTO3SALIDA		(1+NUMESTADOSMODASM1)
#define ANCHURAPUERTO4SALIDA		(1+NUMESTADOSMODASM1)



// _____________________________________________________________________

// PARAMETROS DE LA S-FUNCTION
#define NUMPARAM_SFUNCT		7
#define PARAM_ESTEQ(S)		ssGetSFcnParam(S,0)
#define CINETICS(S)			ssGetSFcnParam(S,1)
#define ARRHEN(S)			ssGetSFcnParam(S,2)
#define ESTEQUIOM(S)		ssGetSFcnParam(S,3)
#define PARAMS_D(S)			ssGetSFcnParam(S,4)
#define PARAMS_N(S)			ssGetSFcnParam(S,5)
#define INICIALES(S)		ssGetSFcnParam(S,6)


// Dimensiones de los Vectores de Parametros
#define DIMPARAMESTEQ		NUMCOEFESTEQ
#define DIMCINETICOS		NUMCOEFCINETICOS
#define DIMARRHENIUS		NUMCOEFCINETICOS
#define NUMFILESTEQ			NUMREACCIONESBIOL
#define NUMCOLESTEQ			NUMESTADOSMODASM1      
#define DIMPARAMS_D			5
#define DIMPARAMS_N			17
#define DIMINICIALES		(NUMESTADOSCONTINUOS + NUMESTADOSDISCRETOS)


// _____________________________________________________________________
////////////////////////////////////////////////////////////////////////
// ASIGNACION DE VECTORES DE TRABAJO
////////////////////////////////////////////////////////////////////////
#define NUMRWORKS					18
#define RHO_W						RWork[0]
#define PV_TL						RWork[1]
#define DO_SAT_20					RWork[2]
#define Temp_DN						RWork[3]

#define EFF_DEPTH_D					RWork[4]
#define DELTA_D						RWork[5]
#define OMEGA_D						RWork[6]
#define DO_SAT_T_D					RWork[7]

#define EFF_DEPTH_N					RWork[8]
#define DELTA_N						RWork[9]
#define OMEGA_N						RWork[10]
#define DO_SAT_T_N					RWork[11]
#define H_TOTAL_N					RWork[12]
#define CROSS_AREA_N				RWork[13]
#define PERIM_TANK_N				RWork[14]
#define NUM_DIFF					RWork[15]
#define Q_AIR_DIFF					RWork[16]
#define QRE_REAL					RWork[17]		


// Vectores de TRABAJO
#define NUMPWORKS						9
#define PARAM_ESTEQUIOM					((real_T *)PWork[0])
#define CINETICOS_20					((real_T *)PWork[1])
#define ARRHENIUS						((real_T *)PWork[2])
#define ESTEQU							((real_T *)PWork[3])
#define PARAM_D							((real_T *)PWork[4])
#define PARAM_N							((real_T *)PWork[5])
#define x0								((real_T *)PWork[6])		// Estados iniciales
#define CINETICOS_T						((real_T *)PWork[7])					// VECTOR DE PARAMETROS CINETICOS A TEMPERATURA T
#define ESTADOSADIC						((real_T **)PWork[8])					//


// Parámetros
#define V_D					PARAM_D[0]			// m3
#define DE_TANK_D			PARAM_D[1]			// Effective depth in tanks (m)
#define H_TANK_D			PARAM_D[2]			// Water level in tanks (m)
#define BETA_FCT_D			PARAM_D[3]	
#define KLa_D				PARAM_D[4]	


#define V_N					PARAM_N[0]			// m3
#define DE_TANK_N			PARAM_N[1]			// Effective depth in tanks (m)
#define H_TANK_N			PARAM_N[2]			// Water level in tanks (m)

#define OTE_A_coeff			PARAM_N[3]
#define OTE_B_coeff			PARAM_N[4]
#define OTE_C_coeff			PARAM_N[5]

#define OTE_E_coeff			PARAM_N[6]
#define OTE_F_coeff			PARAM_N[7]
#define OTE_K_coeff			PARAM_N[8]

#define OTE_M_coeff			PARAM_N[9]
#define OTE_N_coeff			PARAM_N[10]
#define OTE_P_coeff			PARAM_N[11]

#define DENS_DIFFUSERS		PARAM_N[12]		// area diffussers/cross area
#define AREA_DIFFUSER		PARAM_N[13]		// Effective area of diffusser (m2)

#define ALPHA_KLA_FCT		PARAM_N[14]		// Alpha factor for KLa
#define BETA_FCT_N			PARAM_N[15]		// Beta factor for DO sat
#define THETA_KLA_COEFF		PARAM_N[16]		// --



// ESTADOS ADICIONALES DEl SISTEMA (estados adicionales a los del modelo) 
// TODAVÍA SIN DEFINIR
#define NUM_ESTADOSADIC				4
#define EA_SENSORES_D				((real_T **)PWork[8])[0]
#define EA_SENSORES_N				((real_T **)PWork[8])[1]
#define EA_REC_SETTLER				((real_T **)PWork[8])[2]
#define EA_EFF_SETTLER				((real_T **)PWork[8])[3]


#define NUM_EASENSORES_D			8
#define NUM_EASENSORES_N			13
#define NUM_EA_REC_SETTLER			(1+NUMESTADOSMODASM1)
#define NUM_EA_EFF_SETTLER			(1+NUMESTADOSMODASM1)


// Elementos del vector SENSORES D
#define Q_in_D					Sensores_D[0]
#define Q_out_D					Sensores_D[1]
#define NO3_D					Sensores_D[2]
#define NH4_D					Sensores_D[3]
#define DO_D					Sensores_D[4]
#define MLSS_D					Sensores_D[5]
#define Temp_D					Sensores_D[6]
#define OUR_D					Sensores_D[7]


// Elementos del vector SENSORES N
#define Q_in_N					Sensores_N[0]
#define Q_w_N					Sensores_N[1]
#define Q_out_N					Sensores_N[2]
#define NO3_N					Sensores_N[3]
#define NH4_N					Sensores_N[4]
#define DO_N					Sensores_N[5]
#define MLSS_N					Sensores_N[6]
#define KLa_N					Sensores_N[7]
#define Temp_N					Sensores_N[8]
#define OUR_N					Sensores_N[9]
#define OTE_N					Sensores_N[10]
#define N_DIFF					Sensores_N[11]
#define DO_SAT					Sensores_N[12]




// _____________________________________________________________________

// PUERTOS DE ENTRADAS
#define Q_INF				(*uPtrs0[0])
#define SS_INF				(*uPtrs0[1])
#define SO_INF				(*uPtrs0[2])
#define SI_INF				(*uPtrs0[3])
#define SNO_INF				(*uPtrs0[4])
#define SNH_INF				(*uPtrs0[5])
#define SND_INF				(*uPtrs0[6])
#define SALK_INF			(*uPtrs0[7])
#define XI_INF				(*uPtrs0[8])
#define XS_INF				(*uPtrs0[9])
#define XBH_INF				(*uPtrs0[10])
#define XBA_INF				(*uPtrs0[11])
#define XP_INF				(*uPtrs0[12])
#define XND_INF				(*uPtrs0[13])
#define XIN_INF				(*uPtrs0[14])


#define QRI_INP				(*uPtrs1[0])
#define QW_INP				(*uPtrs1[1])
#define QAIR_INP			(*uPtrs1[2])

#define PAMB_INP			(*uPtrs2[0])
#define TEMP_ML_INP			(*uPtrs2[1])

#define FSETTLER_INP		(*uPtrs3[0])
#define QRE_INP				(*uPtrs3[1])


// Posicion INICIAL del Vector de ESTADOS de cada elemento
#define POSINIEST(reactor)				(reactor*NUMESTADOSMODASM1)

#define SS(reactor)					xC[POSINIEST(reactor)]
#define SO(reactor)					xC[POSINIEST(reactor) + 1]
#define SI(reactor)					xC[POSINIEST(reactor) + 2]
#define SNO(reactor)				xC[POSINIEST(reactor) + 3]
#define SNH(reactor)				xC[POSINIEST(reactor) + 4]
#define SND(reactor)				xC[POSINIEST(reactor) + 5]
#define SALK(reactor)				xC[POSINIEST(reactor) + 6]
#define XI(reactor)					xC[POSINIEST(reactor) + 7]
#define XS(reactor)					xC[POSINIEST(reactor) + 8]
#define XBH(reactor)				xC[POSINIEST(reactor) + 9]
#define XBA(reactor)				xC[POSINIEST(reactor) + 10]
#define XP(reactor)					xC[POSINIEST(reactor) + 11]
#define XND(reactor)				xC[POSINIEST(reactor) + 12]
#define XIN(reactor)				xC[POSINIEST(reactor) + 13]


// ESTADOS de cada Elemento de la Planta

// REACTOR ANOX
#define SS_D			xC[0]
#define SO_D			xC[1]
#define SI_D			xC[2]
#define SNO_D			xC[3]
#define SNH_D			xC[4]
#define SND_D			xC[5]
#define SALK_D			xC[6]
#define XI_D			xC[7]
#define XS_D			xC[8]
#define XBH_D			xC[9]
#define XBA_D			xC[10]
#define XP_D			xC[11]
#define XND_D			xC[12]
#define XIN_D			xC[13]

#define SS_N			xC[14]
#define SO_N			xC[15]
#define SI_N			xC[16]
#define SNO_N			xC[17]
#define SNH_N			xC[18]
#define SND_N			xC[19]
#define SALK_N			xC[20]
#define XI_N			xC[21]
#define XS_N			xC[22]
#define XBH_N			xC[23]
#define XBA_N			xC[24]
#define XP_N			xC[25]
#define XND_N			xC[26]
#define XIN_N			xC[27]



// CONSTS
#define CNST_PAMB_N		101325
#define CNST_GRAVITY	9.8			// Gravity constant (m/s2)
#define CNST_RHO_H20	1E6				// g/m3
#define CNST_MO2_AIR	278				// g O2/ Nm3 aire
#define CNST_PATM		101000			// Pa


