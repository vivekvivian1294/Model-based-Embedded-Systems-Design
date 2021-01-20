/*
 * Elevator_project.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Elevator_project".
 *
 * Model version              : 1.83
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Oct 28 15:59:33 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Elevator_project_h_
#define RTW_HEADER_Elevator_project_h_
#include <string.h>
#include <stddef.h>
#ifndef Elevator_project_COMMON_INCLUDES_
# define Elevator_project_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Elevator_project_COMMON_INCLUDES_ */

#include "Elevator_project_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T queue[5];                     /* '<Root>/Chart' */
} B_Elevator_project_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T dest;                         /* '<Root>/Chart' */
  real_T d;                            /* '<Root>/Chart' */
  real_T do_d;                         /* '<Root>/Chart' */
  real_T i;                            /* '<Root>/Chart' */
  real_T u;                            /* '<Root>/Chart' */
  real_T dir;                          /* '<Root>/Chart' */
  real_T open_door;                    /* '<Root>/Chart' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint8_T is_Init;                     /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_Elevator_project_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[8];        /* '<Root>/Chart' */
} PrevZCX_Elevator_project_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Floor0;                       /* '<Root>/Floor0' */
  real_T Floor1;                       /* '<Root>/Floor1' */
  real_T Floor2;                       /* '<Root>/Floor2' */
  real_T Floor3;                       /* '<Root>/Floor3' */
  real_T Floor4;                       /* '<Root>/Floor4' */
  real_T E;                            /* '<Root>/E' */
  real_T Open_door;                    /* '<Root>/Open_door' */
  real_T tic;                          /* '<Root>/tic' */
  real_T position;                     /* '<Root>/position' */
} ExtU_Elevator_project_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Speed;                        /* '<Root>/Speed' */
  real_T queue0;                       /* '<Root>/queue0' */
  real_T queue1;                       /* '<Root>/queue1' */
  real_T queue2;                       /* '<Root>/queue2' */
  real_T queue3;                       /* '<Root>/queue3' */
  real_T queue4;                       /* '<Root>/queue4' */
  real_T DoorLamp;                     /* '<Root>/DoorLamp' */
  real_T ELamp;                        /* '<Root>/ELamp' */
} ExtY_Elevator_project_T;

/* Real-time Model Data Structure */
struct tag_RTM_Elevator_project_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Elevator_project_T Elevator_project_B;

/* Block states (default storage) */
extern DW_Elevator_project_T Elevator_project_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Elevator_project_T Elevator_project_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_Elevator_project_T Elevator_project_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Elevator_project_T Elevator_project_Y;

/* Model entry point functions */
extern void Elevator_project_initialize(void);
extern void Elevator_project_step(void);
extern void Elevator_project_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Elevator_project_T *const Elevator_project_M;

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
 * '<Root>' : 'Elevator_project'
 * '<S1>'   : 'Elevator_project/Chart'
 */
#endif                                 /* RTW_HEADER_Elevator_project_h_ */
