#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Modelo_Simulink_2021b_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "Modelo_Simulink_2021b.h"
#include "Modelo_Simulink_2021b_capi.h"
#include "Modelo_Simulink_2021b_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Modelo_Simulink_2021b/Clock1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 1 , 0 , TARGET_STRING ( "Modelo_Simulink_2021b/Add1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"Modelo_Simulink_2021b/System" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 3 , 0 , TARGET_STRING (
"Modelo_Simulink_2021b/PI/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 4 , TARGET_STRING ( "Modelo_Simulink_2021b/PI" )
, TARGET_STRING ( "P" ) , 0 , 0 , 0 } , { 5 , TARGET_STRING (
"Modelo_Simulink_2021b/PI" ) , TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 6 ,
TARGET_STRING ( "Modelo_Simulink_2021b/PI" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 7 , TARGET_STRING (
"Modelo_Simulink_2021b/Dist" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 8
, TARGET_STRING ( "Modelo_Simulink_2021b/Dist" ) , TARGET_STRING ( "Before" )
, 0 , 0 , 0 } , { 9 , TARGET_STRING ( "Modelo_Simulink_2021b/Dist" ) ,
TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 10 , TARGET_STRING (
"Modelo_Simulink_2021b/Ref" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 11
, TARGET_STRING ( "Modelo_Simulink_2021b/Ref" ) , TARGET_STRING ( "Before" )
, 0 , 0 , 0 } , { 12 , TARGET_STRING ( "Modelo_Simulink_2021b/Ref" ) ,
TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 13 , TARGET_STRING (
"den" ) , 0 , 1 , 0 } , { 14 , TARGET_STRING ( "num" ) , 0 , 0 , 0 } , { 0 ,
( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . g0wcnx5ged , & rtB . cuz5efqmro ,
& rtB . p2uloukdff , & rtB . aqkmzl0xyo , & rtP . PI_P , & rtP . PI_I , & rtP
. PI_InitialConditionForIntegrator , & rtP . Dist_Time , & rtP . Dist_Y0 , &
rtP . Dist_YFinal , & rtP . Ref_Time , & rtP . Ref_Y0 , & rtP . Ref_YFinal ,
& rtP . den [ 0 ] , & rtP . num , } ; static int32_T * rtVarDimsAddrMap [ ] =
{ ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 1 , 3 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0
} , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 4 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 9 ,
rtModelParameters , 2 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2347854535U , 1319019983U , 3572340520U , 2545580025U } , ( NULL ) , 0 ,
( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * Modelo_Simulink_2021b_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Modelo_Simulink_2021b_InitializeDataMapInfo ( void ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Modelo_Simulink_2021b_host_InitializeDataMapInfo (
Modelo_Simulink_2021b_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
