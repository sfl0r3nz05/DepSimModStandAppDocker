# Copyright 1994-2021 The MathWorks, Inc.
#
# File    : ert_unix.tmf   
#
# Abstract:
#       Template makefile for building a UNIX-based stand-alone embedded 
#       real-time version of Simulink model using generated C code.
#
#       This makefile attempts to conform to the guidelines specified in the
#       IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPT_OPTS       - Optimization options. Default is -O.
#         CPP_OPTS       - C++ compiler options.	
#         OPTS           - User specific compile options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc


#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = /home/usuario/MATLAB/bin/glnxa64/gmake
HOST            = UNIX
BUILD           = yes
SYS_TARGET_FILE = any

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = ["Clang v3.1 | gmake (64-bit Mac)", \
             "GNU gcc/g++ | gmake (64-bit Linux)"]

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link. 
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  MODELREFS           - List of referenced models
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead 
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules 
#                            and do not build an executable

MODEL                   = Modelo_Simulink_2021b
MODULES                 = rt_logging_simtarget.c Modelo_Simulink_2021b.c Modelo_Simulink_2021b_capi.c Modelo_Simulink_2021b_data.c Modelo_Simulink_2021b_tgtconn.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rt_logging_mmi_simtarget.c rtw_modelmap_utils_simtarget.c raccel_main.c raccel_sup.c raccel_mat.c simulink_solver_api.c raccel_utils.c common_utils.c ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c rtiostream_utils.c
PRODUCT                 = Modelo_Simulink_2021b
MAKEFILE                = Modelo_Simulink_2021b.mk
MATLAB_ROOT             = /home/usuario/MATLAB
ALT_MATLAB_ROOT         = /home/usuario/MATLAB
START_DIR               = /home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj
S_FUNCTIONS_LIB         = 
NUMST                   = 3
NCSTATES                = 3
COMPUTER                = GLNXA64
BUILDARGS               =  RSIM_SOLVER_SELECTION=2 PCMATLABROOT="/home/usuario/MATLAB" EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 RSIM_PARAMETER_LOADING=1 OPTS="-DTGTCONN -DIS_SIM_TARGET -DNRT -DRSIM_PARAMETER_LOADING -DRSIM_WITH_SL_SOLVER -DENABLE_SLEXEC_SSBRIDGE=1 -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=1"
MULTITASKING            = 0
INTEGER_CODE            = 0
MAT_FILE                = 1
ALLOCATIONFCN           = 0
ONESTEPFCN              = 0
TERMFCN                 = 1
ENABLE_SLEXEC_SSBRIDGE  = 1
MULTI_INSTANCE_CODE     = 0
CLASSIC_INTERFACE       = 1
MODELREFS               = 
GEN_SAMPLE_MAIN         = 0
TARGET_LANG_EXT         = c
SHRLIBTARGET            = 0
MAKEFILEBUILDER_TGT     = 0
STANDALONE_SUPPRESS_EXE = 0
OPTIMIZATION_FLAGS      = -O0
ADDITIONAL_LDFLAGS      =  -Wl,--allow-shlib-undefined
INTERLEAVED_COMPLEX_FLAGS = -R2018a
DEFINES_CUSTOM          = -DEXT_MODE -DIS_RAPID_ACCEL -DisSimStruct64FeatureOn=1 
DEFINES_OTHER           = -DHAVESTDIO
COMPILE_FLAGS_OTHER     = -mcmodel=medium -msse2
SYSTEM_LIBS             = -L"/home/usuario/MATLAB/bin/glnxa64" -lmwipp -lut -lmx -lmex -lmat -lmwmathutil -lmwslsa_sim -lmwslexec_simbridge -lmwsl_fileio -lmwsigstream -lmwsl_AsyncioQueue -lmwsl_services -lmwsdi_raccel -lmwi18n -lmwcoder_target_services -lmwcoder_ParamTuningTgtAppSvc -lmwslpointerutil -lmwsl_simtarget_instrumentation -lfixedpoint -lmwslexec_simlog -lmwstringutil -lm -lpthread -ldl
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE


#-- For gcc, link model reference libraries as a group to resolve circular references ---
#   (NOTE: Clang does not recognize these switches but it already resolves circular references)
MODELREF_LINK_LIBS_GROUP = 
ifeq ($(COMPUTER),GLNXA64)
  MODELREF_LINK_LIBS_GROUP = -Wl,--start-group  -Wl,--end-group
endif

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

#--------------------------- Tool Specifications -------------------------------

include $(MATLAB_ROOT)/rtw/c/tools/unixtools.mk

#------------------------------ Include Path -----------------------------------

# Additional includes 
ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/slprj/raccel/Modelo_Simulink_2021b \
	-I$(MATLAB_ROOT)/rtw/c/src/rapid \
	-I$(MATLAB_ROOT)/rtw/c/raccel \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils \


INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES) $(ADD_INCLUDES)

#-------------------------------- C Flags --------------------------------------

# Optimization Options
ifndef OPT_OPTS
OPT_OPTS = $(DEFAULT_OPT_OPTS)
endif

# General User Options
ifeq ($(DEBUG_BUILD),0)
DBG_FLAG =
else
#   Set OPTS=-g and any additional flags for debugging
DBG_FLAG = -g
LDFLAGS += -g
endif

# Defines
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DUNIX \
                  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE) \
		  -DALLOCATIONFCN=$(ALLOCATIONFCN)

ifeq ($(MODELREF_TARGET_TYPE),SIM)
ifneq ($(ENABLE_SLEXEC_SSBRIDGE), 0)
CPP_REQ_DEFINES += -DENABLE_SLEXEC_SSBRIDGE=$(ENABLE_SLEXEC_SSBRIDGE)
endif
else
CPP_REQ_DEFINES += -DMT=$(MULTITASKING)
endif

CPP_REQ_DEFINES += -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=$(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS)

ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPT_OPTS)
endif

DEFINES = $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(DEFINES_OTHER)
CFLAGS = $(ANSI_OPTS) $(DBG_FLAG) $(CC_OPTS) $(DEFINES) $(INCLUDES)
CPPFLAGS = $(CPP_ANSI_OPTS) $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(DEFINES) $(INCLUDES)

#-------------------------- Additional Libraries ------------------------------

SYSTEM_LIBS += -lm

LIBS =
 
LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

#----------------------------- Source Files ------------------------------------
ADD_SRCS =

SRCS = $(ADD_SRCS) $(MODULES)

USER_SRCS =

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

ADDITIONAL_LDFLAGS += $(ARCH_SPECIFIC_LDFLAGS)

#--------------------------------- Rules ---------------------------------------
BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(PRODUCT)
BUILD_PRODUCT_TYPE = "executable"
ifeq ($(MODELREF_TARGET_TYPE),NONE)
  ifeq ($(SHRLIBTARGET), 1)
    BIN_SETTING        = $(LD) $(ADDITIONAL_LDFLAGS) $(SHRLIBLDFLAGS)$(MODEL).def -o $(PRODUCT)
    BUILD_PRODUCT_TYPE = "shared object"	
    ifeq ($(GEN_SAMPLE_MAIN), 1)
      PRODUCT := $(notdir $(PRODUCT))
$(MODEL) : $(PRODUCT) ert_main.o
	$(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(MODEL) ert_main.o $(PRODUCT) $(SYSTEM_LIBS)
	@mv $(PRODUCT) $(RELATIVE_PATH_TO_ANCHOR)/
	@mv $(MODEL) $(RELATIVE_PATH_TO_ANCHOR)/
	@echo "### Created executable: $@"
    endif
  endif
  ifeq ($(MAKEFILEBUILDER_TGT), 1)
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELLIB) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELLIB) $(MODELREF_LINK_LIBS_GROUP) $(LIBS)  $(SYSTEM_LIBS)
	@echo "### Created executable: $@"
  else
    ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
.PHONY: $(PRODUCT)
$(PRODUCT) : $(OBJS) $(LIBS)
	@echo "### Created object modules: $@"
    else
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS_GROUP) $(LIBS)  $(SYSTEM_LIBS)
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"
    endif
  endif
else
  $(PRODUCT) : $(OBJS)
	@rm -f $(MODELLIB)
	$(AR) ruvs $(MODELLIB) $(LINK_OBJS)
	@echo "### Created $(MODELLIB)"
	@echo "### Created library: $@"
endif

#-------------------------- Support for building modules ----------------------

%.o : %.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : %.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

rt_logging_simtarget.o : $(MATLAB_ROOT)/rtw/c/src/rt_logging_simtarget.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/rt_logging_simtarget.c

raccel_main.o : $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c

raccel_sup.o : $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c

raccel_mat.o : $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c

simulink_solver_api.o : $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c

raccel_utils.o : $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c

common_utils.o : $(MATLAB_ROOT)/rtw/c/src/rapid/common_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/rapid/common_utils.c

ext_svr.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c

updown.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c

ext_work.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c

rtiostream_interface.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c

rtiostream_tcpip.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c

rtiostream_utils.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c



%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"



#------------------------------- Libraries -------------------------------------





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

