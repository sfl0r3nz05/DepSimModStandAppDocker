#include "Modelo_Simulink_2021b.h"
#include "rtwtypes.h"
#include "Modelo_Simulink_2021b_private.h"
#include "rt_logging_mmi.h"
#include "Modelo_Simulink_2021b_capi.h"
#include "Modelo_Simulink_2021b_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.5 (R2022a) 13-Nov-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . daihuh10tl [ 0 ] = 0.0 ; rtX
. daihuh10tl [ 1 ] = 0.0 ; rtX . lwuql0euwl = rtP .
PI_InitialConditionForIntegrator ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Mux" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Mux" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"Modelo_Simulink_2021b/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Mux" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 2 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . h1wyeztedo . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "9b3cb5f7-f69a-4342-9db2-aef1a8e6ef01" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . h1wyeztedo . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . h1wyeztedo . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . h1wyeztedo . AQHandles , "0.01" , 0.01
, ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . h1wyeztedo . AQHandles
, 0.0 ) ; sdiSetRunStartTime ( rtDW . h1wyeztedo . AQHandles , ssGetTaskTime
( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . h1wyeztedo .
AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . h1wyeztedo .
AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . h1wyeztedo . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Results" ) ; sdiRegisterWksVariable ( rtDW . h1wyeztedo . AQHandles ,
varName , "array2D" ) ; sdiFreeLabel ( varName ) ; } } } } } MdlInitialize (
) ; } void MdlOutputs ( int_T tid ) { real_T j0n0q3ll5d [ 2 ] ; real_T
ndwnxfqw5b ; real_T tmp ; rtB . g0wcnx5ged = ssGetT ( rtS ) ; j0n0q3ll5d [ 1
] = rtP . num / rtP . den [ 0 ] ; rtB . p2uloukdff = 0.0 * rtX . daihuh10tl [
0 ] ; rtB . p2uloukdff += j0n0q3ll5d [ 1 ] * rtX . daihuh10tl [ 1 ] ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { j0n0q3ll5d [ 0 ] = rtB . g0wcnx5ged ;
j0n0q3ll5d [ 1 ] = rtB . p2uloukdff ; { if ( rtDW . h1wyeztedo . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . h1wyeztedo . AQHandles ,
ssGetTaskTime ( rtS , 2 ) , ( char * ) & j0n0q3ll5d [ 0 ] + 0 ) ; } } } if (
ssGetTaskTime ( rtS , 0 ) < rtP . Ref_Time ) { tmp = rtP . Ref_Y0 ; } else {
tmp = rtP . Ref_YFinal ; } ndwnxfqw5b = tmp - rtB . p2uloukdff ; if (
ssGetTaskTime ( rtS , 0 ) < rtP . Dist_Time ) { tmp = rtP . Dist_Y0 ; } else
{ tmp = rtP . Dist_YFinal ; } rtB . cuz5efqmro = ( ndwnxfqw5b + rtX .
lwuql0euwl ) * rtP . PI_P + tmp ; rtB . aqkmzl0xyo = rtP . PI_I * ndwnxfqw5b
; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> daihuh10tl [ 0 ] = -
rtP . den [ 1 ] / rtP . den [ 0 ] * rtX . daihuh10tl [ 0 ] ; _rtXdot ->
daihuh10tl [ 0 ] += - rtP . den [ 2 ] / rtP . den [ 0 ] * rtX . daihuh10tl [
1 ] ; _rtXdot -> daihuh10tl [ 1 ] = rtX . daihuh10tl [ 0 ] ; _rtXdot ->
daihuh10tl [ 0 ] += rtB . cuz5efqmro ; _rtXdot -> lwuql0euwl = rtB .
aqkmzl0xyo ; } void MdlProjection ( void ) { } void MdlTerminate ( void ) { {
if ( rtDW . h1wyeztedo . AQHandles ) { sdiTerminateStreaming ( & rtDW .
h1wyeztedo . AQHandles ) ; } } } static void
mr_Modelo_Simulink_2021b_cacheDataAsMxArray ( mxArray * destArray , mwIndex i
, int j , const void * srcData , size_t numBytes ) ; static void
mr_Modelo_Simulink_2021b_cacheDataAsMxArray ( mxArray * destArray , mwIndex i
, int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Modelo_Simulink_2021b_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_Modelo_Simulink_2021b_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy (
( uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_Modelo_Simulink_2021b_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) ; static void
mr_Modelo_Simulink_2021b_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j
, mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_Modelo_Simulink_2021b_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_Modelo_Simulink_2021b_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = (
uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return
varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_Modelo_Simulink_2021b_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_Modelo_Simulink_2021b_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Modelo_Simulink_2021b_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) ; static void
mr_Modelo_Simulink_2021b_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_Modelo_Simulink_2021b_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_Modelo_Simulink_2021b_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_Modelo_Simulink_2021b_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_Modelo_Simulink_2021b_extractBitFieldFromCellArrayWithOffset
( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T
numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_Modelo_Simulink_2021b_GetDWork ( ) {
static const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Modelo_Simulink_2021b_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * )
& ( rtB ) , sizeof ( rtB ) ) ; return ssDW ; } void
mr_Modelo_Simulink_2021b_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_Modelo_Simulink_2021b_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW
, 0 , 0 , sizeof ( rtB ) ) ; } mxArray *
mr_Modelo_Simulink_2021b_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ;
} void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 3 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 12 ) ; ssSetNumBlockIO ( rtS , 4 ) ;
ssSetNumBlockParams ( rtS , 13 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0001 ) ;
ssSetSampleTime ( rtS , 2 , 0.01 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2347854535U ) ;
ssSetChecksumVal ( rtS , 1 , 1319019983U ) ; ssSetChecksumVal ( rtS , 2 ,
3572340520U ) ; ssSetChecksumVal ( rtS , 3 , 2545580025U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 22 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
Modelo_Simulink_2021b_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Modelo_Simulink_2021b" ) ; ssSetPath ( rtS , "Modelo_Simulink_2021b" ) ;
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 2.0 ) ; ssSetStepSize ( rtS ,
0.0001 ) ; ssSetFixedStepSize ( rtS , 0.0001 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 2 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 2 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"Modelo_Simulink_2021b/System" ,
"Modelo_Simulink_2021b/PI/Integrator/Continuous/Integrator" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . daihuh10tl [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . lwuql0euwl ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 3 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode4" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 2347854535U ) ; ssSetChecksumVal ( rtS , 1 ,
1319019983U ) ; ssSetChecksumVal ( rtS , 2 , 3572340520U ) ; ssSetChecksumVal
( rtS , 3 , 2545580025U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Modelo_Simulink_2021b_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_Modelo_Simulink_2021b_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_Modelo_Simulink_2021b_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
