#include "Modelo_Simulink_2021b_capi_host.h"
static Modelo_Simulink_2021b_host_DataMapInfo_T root;
static int initialized = 0;
rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Modelo_Simulink_2021b_host_InitializeDataMapInfo(&(root), "Modelo_Simulink_2021b");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
