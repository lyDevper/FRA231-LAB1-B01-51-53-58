/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoder_private.h
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

#ifndef encoder_private_h_
#define encoder_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "encoder.h"
#include "encoder_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void encoder_DigitalPortRead_Init(DW_DigitalPortRead_encoder_T *localDW);
extern void encoder_DigitalPortRead(B_DigitalPortRead_encoder_T *localB);

#endif                                 /* encoder_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
