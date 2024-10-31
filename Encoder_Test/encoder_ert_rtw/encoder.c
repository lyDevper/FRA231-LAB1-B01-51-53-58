/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoder.c
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

#include "encoder.h"
#include "encoder_types.h"
#include "encoder_private.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"

/* Block signals (default storage) */
B_encoder_T encoder_B;

/* Block states (default storage) */
DW_encoder_T encoder_DW;

/* Real-time model */
static RT_MODEL_encoder_T encoder_M_;
RT_MODEL_encoder_T *const encoder_M = &encoder_M_;

/* Forward declaration for local functions */
static void encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void encoder_SystemCore_setup_c(stm32cube_blocks_EncoderBlock_T *obj);
static void encoder_SystemCore_setup_ck(stm32cube_blocks_EncoderBlock_T *obj);

/* System initialize for atomic system: */
void encoder_DigitalPortRead_Init(DW_DigitalPortRead_encoder_T *localDW)
{
  /* Start for MATLABSystem: '<S20>/Digital Port Read' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void encoder_DigitalPortRead(B_DigitalPortRead_encoder_T *localB)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S20>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S20>/Digital Port Read' */
  localB->DigitalPortRead = ((pinReadLoc & 8192U) != 0U);
}

static void encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void encoder_SystemCore_setup_c(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void encoder_SystemCore_setup_ck(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void encoder_step(void)
{
  real_T tmp;
  uint32_T timerCounts;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T tmp_0;

  /* MATLABSystem: '<Root>/Encoder' */
  timerCounts = getTimerCounterValueForG4(encoder_DW.obj_p.TimerHandle, false,
    NULL);
  encoder_DigitalPortRead(&encoder_B.DigitalPortRead_f);

  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S13>/Compare'
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)
    encoder_B.DigitalPortRead_f.DigitalPortRead > (int32_T)
    encoder_DW.DelayInput1_DSTATE);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLABSystem: '<Root>/Encoder'
   */
  if (rtb_FixPtRelationalOperator) {
    encoder_DW.pulse_k = 0.0;
  }

  if (timerCounts > encoder_DW.lastpulse_j) {
    if ((real_T)timerCounts - encoder_DW.lastpulse_j > 100.0) {
      encoder_DW.pulse_k -= 65520.0 - (real_T)timerCounts;
    } else {
      encoder_DW.pulse_k += (real_T)timerCounts - encoder_DW.lastpulse_j;
    }
  } else if (timerCounts < encoder_DW.lastpulse_j) {
    if (encoder_DW.lastpulse_j - (real_T)timerCounts > 100.0) {
      encoder_DW.pulse_k += (real_T)timerCounts;
    } else {
      encoder_DW.pulse_k -= encoder_DW.lastpulse_j - (real_T)timerCounts;
    }
  }

  encoder_B.plu_f = encoder_DW.pulse_k;
  encoder_B.out_c = encoder_DW.pulse_k * 0.26179938779914941;
  encoder_B.v_k = (encoder_DW.pulse_k * 0.26179938779914941 -
                   encoder_DW.lastrad_i) / 0.1;
  encoder_DW.lastpulse_j = timerCounts;
  encoder_DW.lastrad_i = encoder_B.out_c;

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  /* MATLABSystem: '<Root>/Encoder1' */
  timerCounts = getTimerCounterValueForG4(encoder_DW.obj_h.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Encoder1'
   */
  if (rtb_FixPtRelationalOperator) {
    encoder_DW.pulse = 0.0;
  }

  if (timerCounts > encoder_DW.lastpulse) {
    tmp = (real_T)timerCounts - encoder_DW.lastpulse;
    if (tmp > 100.0) {
      encoder_DW.pulse -= 65520.0 - (real_T)timerCounts;
    } else {
      encoder_DW.pulse += tmp;
    }
  } else if (timerCounts < encoder_DW.lastpulse) {
    tmp = encoder_DW.lastpulse - (real_T)timerCounts;
    if (tmp > 100.0) {
      encoder_DW.pulse += (real_T)timerCounts;
    } else {
      encoder_DW.pulse -= tmp;
    }
  }

  encoder_B.plu = encoder_DW.pulse;
  encoder_B.out = encoder_DW.pulse * 0.1308996938995747;
  encoder_B.v = (encoder_DW.pulse * 0.1308996938995747 - encoder_DW.lastrad) /
    0.1;
  encoder_DW.lastpulse = timerCounts;
  encoder_DW.lastrad = encoder_B.out;

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */
  /* MATLABSystem: '<Root>/Encoder2' */
  timerCounts = getTimerCounterValueForG4(encoder_DW.obj.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<Root>/Encoder2'
   */
  if (rtb_FixPtRelationalOperator) {
    encoder_DW.pulse_g = 0.0;
  }

  if (timerCounts > encoder_DW.lastpulse_m) {
    tmp = (real_T)timerCounts - encoder_DW.lastpulse_m;
    if (tmp > 100.0) {
      encoder_DW.pulse_g -= 65520.0 - (real_T)timerCounts;
    } else {
      encoder_DW.pulse_g += tmp;
    }
  } else if (timerCounts < encoder_DW.lastpulse_m) {
    tmp = encoder_DW.lastpulse_m - (real_T)timerCounts;
    if (tmp > 100.0) {
      encoder_DW.pulse_g += (real_T)timerCounts;
    } else {
      encoder_DW.pulse_g -= tmp;
    }
  }

  encoder_B.plu_n = encoder_DW.pulse_g;
  encoder_B.out_h = encoder_DW.pulse_g * 0.065449846949787352;
  encoder_B.v_f = (encoder_DW.pulse_g * 0.065449846949787352 -
                   encoder_DW.lastrad_i3) / 0.1;
  encoder_DW.lastpulse_m = timerCounts;
  encoder_DW.lastrad_i3 = encoder_B.out_h;

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */
  encoder_DigitalPortRead(&encoder_B.DigitalPortRead_pq);

  /* RelationalOperator: '<S2>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S14>/Compare'
   *  UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)
    encoder_B.DigitalPortRead_pq.DigitalPortRead > (int32_T)
    encoder_DW.DelayInput1_DSTATE_l);

  /* MATLABSystem: '<S16>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S16>/Digital Port Read' */
  encoder_B.DigitalPortRead_k = ((timerCounts & 16U) != 0U);

  /* MATLABSystem: '<S18>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S18>/Digital Port Read' */
  encoder_B.DigitalPortRead = ((timerCounts & 32U) != 0U);

  /* MATLAB Function: '<Root>/x1' incorporates:
   *  MATLAB Function: '<Root>/x2'
   *  MATLAB Function: '<Root>/x4'
   */
  if (rtb_FixPtRelationalOperator) {
    encoder_DW.c_n = 0.0;
  }

  tmp_0 = !encoder_B.DigitalPortRead_k;
  if (tmp_0 && (encoder_DW.stageA_a == 1.0)) {
    encoder_DW.stageA_a = 0.0;
    if (encoder_B.DigitalPortRead) {
      encoder_DW.c_n++;
    } else {
      encoder_DW.c_n--;
    }
  } else if (encoder_B.DigitalPortRead_k) {
    encoder_DW.stageA_a = 1.0;
  }

  encoder_B.y_h = encoder_DW.c_n;

  /* End of MATLAB Function: '<Root>/x1' */
  /* MATLAB Function: '<Root>/x2' */
  if (rtb_FixPtRelationalOperator) {
    encoder_DW.c_f = 0.0;
  }

  if (tmp_0 && (encoder_DW.stageA_g == 1.0)) {
    encoder_DW.stageA_g = 0.0;
    if (encoder_B.DigitalPortRead) {
      encoder_DW.c_f++;
    } else {
      encoder_DW.c_f--;
    }
  } else if (encoder_B.DigitalPortRead_k && (encoder_DW.stageA_g == 0.0)) {
    encoder_DW.stageA_g = 1.0;
    if (!encoder_B.DigitalPortRead) {
      encoder_DW.c_f++;
    } else {
      encoder_DW.c_f--;
    }
  }

  encoder_B.y_m = encoder_DW.c_f;

  /* MATLAB Function: '<Root>/x4' */
  if (rtb_FixPtRelationalOperator) {
    encoder_DW.c = 0.0;
  }

  if (tmp_0 && (encoder_DW.stageA == 1.0)) {
    encoder_DW.stageA = 0.0;
    if (encoder_B.DigitalPortRead) {
      encoder_DW.c++;
    } else {
      encoder_DW.c--;
    }
  } else if (encoder_B.DigitalPortRead_k && (encoder_DW.stageA == 0.0)) {
    encoder_DW.stageA = 1.0;
    if (!encoder_B.DigitalPortRead) {
      encoder_DW.c++;
    } else {
      encoder_DW.c--;
    }
  }

  if ((!encoder_B.DigitalPortRead) && (encoder_DW.stageB == 1.0)) {
    encoder_DW.stageB = 0.0;
    if (!encoder_B.DigitalPortRead_k) {
      encoder_DW.c++;
    } else {
      encoder_DW.c--;
    }
  } else if (encoder_B.DigitalPortRead && (encoder_DW.stageB == 0.0)) {
    encoder_DW.stageB = 1.0;
    if (encoder_B.DigitalPortRead_k) {
      encoder_DW.c++;
    } else {
      encoder_DW.c--;
    }
  }

  encoder_B.y = encoder_DW.c;

  /* Update for UnitDelay: '<S1>/Delay Input1' incorporates:
   *  RelationalOperator: '<S13>/Compare'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  encoder_DW.DelayInput1_DSTATE = encoder_B.DigitalPortRead_f.DigitalPortRead;

  /* Update for UnitDelay: '<S2>/Delay Input1' incorporates:
   *  RelationalOperator: '<S14>/Compare'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  encoder_DW.DelayInput1_DSTATE_l = encoder_B.DigitalPortRead_pq.DigitalPortRead;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  encoder_M->Timing.taskTime0 =
    ((time_T)(++encoder_M->Timing.clockTick0)) * encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void encoder_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(encoder_M, 50.0);
  encoder_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  encoder_M->Sizes.checksums[0] = (3231597889U);
  encoder_M->Sizes.checksums[1] = (3119241717U);
  encoder_M->Sizes.checksums[2] = (2535174306U);
  encoder_M->Sizes.checksums[3] = (649521294U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
    encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(encoder_M->extModeInfo,
      &encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(encoder_M->extModeInfo, encoder_M->Sizes.checksums);
    rteiSetTPtr(encoder_M->extModeInfo, rtmGetTPtr(encoder_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/x1' */
  encoder_DW.stageA_a = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x2' */
  encoder_DW.stageA_g = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x4' */
  encoder_DW.stageA = 1.0;
  encoder_DW.stageB = 1.0;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  encoder_DW.obj_p.isInitialized = 0;
  encoder_DW.obj_p.matlabCodegenIsDeleted = false;
  encoder_SystemCore_setup(&encoder_DW.obj_p);
  encoder_DigitalPortRead_Init(&encoder_DW.DigitalPortRead_f);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  encoder_DW.obj_h.isInitialized = 0;
  encoder_DW.obj_h.matlabCodegenIsDeleted = false;
  encoder_SystemCore_setup_c(&encoder_DW.obj_h);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  encoder_DW.obj.isInitialized = 0;
  encoder_DW.obj.matlabCodegenIsDeleted = false;
  encoder_SystemCore_setup_ck(&encoder_DW.obj);
  encoder_DigitalPortRead_Init(&encoder_DW.DigitalPortRead_pq);
}

/* Model terminate function */
void encoder_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!encoder_DW.obj_p.matlabCodegenIsDeleted) {
    encoder_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((encoder_DW.obj_p.isInitialized == 1) &&
        encoder_DW.obj_p.isSetupComplete) {
      disableCounter(encoder_DW.obj_p.TimerHandle);
      disableTimerInterrupts(encoder_DW.obj_p.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(encoder_DW.obj_p.TimerHandle, ChannelInfo);
      disableTimerChannel2(encoder_DW.obj_p.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!encoder_DW.obj_h.matlabCodegenIsDeleted) {
    encoder_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((encoder_DW.obj_h.isInitialized == 1) &&
        encoder_DW.obj_h.isSetupComplete) {
      disableCounter(encoder_DW.obj_h.TimerHandle);
      disableTimerInterrupts(encoder_DW.obj_h.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(encoder_DW.obj_h.TimerHandle, ChannelInfo);
      disableTimerChannel2(encoder_DW.obj_h.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!encoder_DW.obj.matlabCodegenIsDeleted) {
    encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((encoder_DW.obj.isInitialized == 1) && encoder_DW.obj.isSetupComplete) {
      disableCounter(encoder_DW.obj.TimerHandle);
      disableTimerInterrupts(encoder_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(encoder_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(encoder_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
