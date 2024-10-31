/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoder.h
 *
 * Code generated for Simulink model 'encoder'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Oct 28 19:40:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef encoder_h_
#define encoder_h_
#ifndef encoder_COMMON_INCLUDES_
#define encoder_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* encoder_COMMON_INCLUDES_ */

#include "encoder_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S20>/Digital Port Read' */
typedef struct {
  boolean_T DigitalPortRead;           /* '<S20>/Digital Port Read' */
} B_DigitalPortRead_encoder_T;

/* Block states (default storage) for system '<S20>/Digital Port Read' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S20>/Digital Port Read' */
  boolean_T objisempty;                /* '<S20>/Digital Port Read' */
} DW_DigitalPortRead_encoder_T;

/* Block signals (default storage) */
typedef struct {
  real_T y;                            /* '<Root>/x4' */
  real_T y_m;                          /* '<Root>/x2' */
  real_T y_h;                          /* '<Root>/x1' */
  real_T out;                          /* '<Root>/MATLAB Function3' */
  real_T v;                            /* '<Root>/MATLAB Function3' */
  real_T plu;                          /* '<Root>/MATLAB Function3' */
  real_T out_c;                        /* '<Root>/MATLAB Function2' */
  real_T v_k;                          /* '<Root>/MATLAB Function2' */
  real_T plu_f;                        /* '<Root>/MATLAB Function2' */
  real_T out_h;                        /* '<Root>/MATLAB Function1' */
  real_T v_f;                          /* '<Root>/MATLAB Function1' */
  real_T plu_n;                        /* '<Root>/MATLAB Function1' */
  boolean_T DigitalPortRead;           /* '<S18>/Digital Port Read' */
  boolean_T DigitalPortRead_k;         /* '<S16>/Digital Port Read' */
  B_DigitalPortRead_encoder_T DigitalPortRead_pq;/* '<S20>/Digital Port Read' */
  B_DigitalPortRead_encoder_T DigitalPortRead_f;/* '<S20>/Digital Port Read' */
} B_encoder_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_h;/* '<Root>/Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_p;/* '<Root>/Encoder' */
  real_T c;                            /* '<Root>/x4' */
  real_T stageA;                       /* '<Root>/x4' */
  real_T stageB;                       /* '<Root>/x4' */
  real_T c_f;                          /* '<Root>/x2' */
  real_T stageA_g;                     /* '<Root>/x2' */
  real_T c_n;                          /* '<Root>/x1' */
  real_T stageA_a;                     /* '<Root>/x1' */
  real_T pulse;                        /* '<Root>/MATLAB Function3' */
  real_T lastpulse;                    /* '<Root>/MATLAB Function3' */
  real_T lastrad;                      /* '<Root>/MATLAB Function3' */
  real_T pulse_k;                      /* '<Root>/MATLAB Function2' */
  real_T lastpulse_j;                  /* '<Root>/MATLAB Function2' */
  real_T lastrad_i;                    /* '<Root>/MATLAB Function2' */
  real_T pulse_g;                      /* '<Root>/MATLAB Function1' */
  real_T lastpulse_m;                  /* '<Root>/MATLAB Function1' */
  real_T lastrad_i3;                   /* '<Root>/MATLAB Function1' */
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S2>/Delay Input1' */
  DW_DigitalPortRead_encoder_T DigitalPortRead_pq;/* '<S20>/Digital Port Read' */
  DW_DigitalPortRead_encoder_T DigitalPortRead_f;/* '<S20>/Digital Port Read' */
} DW_encoder_T;

/* Real-time Model Data Structure */
struct tag_RTM_encoder_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_encoder_T encoder_B;

/* Block states (default storage) */
extern DW_encoder_T encoder_DW;

/* Model entry point functions */
extern void encoder_initialize(void);
extern void encoder_step(void);
extern void encoder_terminate(void);

/* Real-time Model object */
extern RT_MODEL_encoder_T *const encoder_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'encoder'
 * '<S1>'   : 'encoder/Detect Rise Positive'
 * '<S2>'   : 'encoder/Detect Rise Positive1'
 * '<S3>'   : 'encoder/Digital Port Read'
 * '<S4>'   : 'encoder/Digital Port Read1'
 * '<S5>'   : 'encoder/Digital Port Read2'
 * '<S6>'   : 'encoder/Digital Port Read3'
 * '<S7>'   : 'encoder/MATLAB Function1'
 * '<S8>'   : 'encoder/MATLAB Function2'
 * '<S9>'   : 'encoder/MATLAB Function3'
 * '<S10>'  : 'encoder/x1'
 * '<S11>'  : 'encoder/x2'
 * '<S12>'  : 'encoder/x4'
 * '<S13>'  : 'encoder/Detect Rise Positive/Positive'
 * '<S14>'  : 'encoder/Detect Rise Positive1/Positive'
 * '<S15>'  : 'encoder/Digital Port Read/ECSoC'
 * '<S16>'  : 'encoder/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S17>'  : 'encoder/Digital Port Read1/ECSoC'
 * '<S18>'  : 'encoder/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S19>'  : 'encoder/Digital Port Read2/ECSoC'
 * '<S20>'  : 'encoder/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S21>'  : 'encoder/Digital Port Read3/ECSoC'
 * '<S22>'  : 'encoder/Digital Port Read3/ECSoC/ECSimCodegen'
 */
#endif                                 /* encoder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
