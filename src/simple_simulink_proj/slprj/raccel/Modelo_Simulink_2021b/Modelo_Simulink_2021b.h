#ifndef RTW_HEADER_Modelo_Simulink_2021b_h_
#define RTW_HEADER_Modelo_Simulink_2021b_h_
#ifndef Modelo_Simulink_2021b_COMMON_INCLUDES_
#define Modelo_Simulink_2021b_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Modelo_Simulink_2021b_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Modelo_Simulink_2021b
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (4) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T g0wcnx5ged ; real_T p2uloukdff ; real_T cuz5efqmro ;
real_T aqkmzl0xyo ; } B ; typedef struct { struct { void * AQHandles ; }
h1wyeztedo ; } DW ; typedef struct { real_T daihuh10tl [ 2 ] ; real_T
lwuql0euwl ; } X ; typedef struct { real_T daihuh10tl [ 2 ] ; real_T
lwuql0euwl ; } XDot ; typedef struct { boolean_T daihuh10tl [ 2 ] ; boolean_T
lwuql0euwl ; } XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T den [ 3 ] ; real_T num ; real_T PI_I ;
real_T PI_InitialConditionForIntegrator ; real_T PI_P ; real_T Ref_Time ;
real_T Ref_Y0 ; real_T Ref_YFinal ; real_T Dist_Time ; real_T Dist_Y0 ;
real_T Dist_YFinal ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern mxArray
* mr_Modelo_Simulink_2021b_GetDWork ( ) ; extern void
mr_Modelo_Simulink_2021b_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_Modelo_Simulink_2021b_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Modelo_Simulink_2021b_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
