/*
 * Elevator_project.c
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

#include "Elevator_project.h"
#include "Elevator_project_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Elevator_proje_event_Open_doors (6)
#define Elevator_projec_event_Emergency (5)
#define Elevator_project_IN_Door       ((uint8_T)1U)
#define Elevator_project_IN_Down       ((uint8_T)2U)
#define Elevator_project_IN_Emergency  ((uint8_T)3U)
#define Elevator_project_IN_Idle_state ((uint8_T)4U)
#define Elevator_project_IN_Up         ((uint8_T)5U)
#define Elevator_project_event_floor0  (0)
#define Elevator_project_event_floor1  (1)
#define Elevator_project_event_floor2  (2)
#define Elevator_project_event_floor3  (3)
#define Elevator_project_event_floor4  (4)
#define Elevator_project_event_tic     (7)

/* Block signals (default storage) */
B_Elevator_project_T Elevator_project_B;

/* Block states (default storage) */
DW_Elevator_project_T Elevator_project_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Elevator_project_T Elevator_project_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_Elevator_project_T Elevator_project_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Elevator_project_T Elevator_project_Y;

/* Real-time model */
RT_MODEL_Elevator_project_T Elevator_project_M_;
RT_MODEL_Elevator_project_T *const Elevator_project_M = &Elevator_project_M_;

/* Forward declaration for local functions */
static void Elevator_project_Error_check(void);
static void Elevator_project_floor_check(void);
static real_T Elevator_project_current_floor(void);
static real_T Elevator_project_floor_check_g(void);
static void E_chartstep_c3_Elevator_project(void);

/* Function for Chart: '<Root>/Chart' */
static void Elevator_project_Error_check(void)
{
  /* Inport: '<Root>/position' incorporates:
   *  Outport: '<Root>/DoorLamp'
   *  Outport: '<Root>/Speed'
   */
  if ((Elevator_project_U.position > 4.1) && (Elevator_project_U.position < 0.0))
  {
    /* Outport: '<Root>/Speed' */
    Elevator_project_Y.Speed = 0.0;
  } else if ((Elevator_project_U.position + 0.5 == Elevator_project_U.position) ||
             (Elevator_project_U.position - 0.5 == Elevator_project_U.position))
  {
    /* Outport: '<Root>/Speed' */
    Elevator_project_Y.Speed = 0.0;
  } else {
    if (((Elevator_project_Y.Speed > 0.0) || (Elevator_project_Y.Speed < 0.0)) &&
        (Elevator_project_Y.DoorLamp == 1.0)) {
      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;

      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 0.0;
    }
  }

  /* End of Inport: '<Root>/position' */
}

/* Function for Chart: '<Root>/Chart' */
static void Elevator_project_floor_check(void)
{
  if (Elevator_project_DW.dir > 0.0) {
    if ((Elevator_project_B.queue[1] != 0.0) && (Elevator_project_U.position <
         1.0)) {
      Elevator_project_DW.dest = 2.0;
    } else if ((Elevator_project_B.queue[2] != 0.0) &&
               (Elevator_project_U.position < 2.0)) {
      Elevator_project_DW.dest = 3.0;
    } else if ((Elevator_project_B.queue[3] != 0.0) &&
               (Elevator_project_U.position < 3.0)) {
      Elevator_project_DW.dest = 4.0;
    } else if ((Elevator_project_B.queue[4] != 0.0) &&
               (Elevator_project_U.position != 4.0)) {
      Elevator_project_DW.dest = 5.0;
    } else {
      Elevator_project_DW.dir = 0.0;
    }
  } else if (Elevator_project_DW.dir < 0.0) {
    if ((Elevator_project_B.queue[3] != 0.0) && (Elevator_project_U.position >
         3.0)) {
      Elevator_project_DW.dest = 4.0;
    } else if ((Elevator_project_B.queue[2] != 0.0) &&
               (Elevator_project_U.position > 2.0)) {
      Elevator_project_DW.dest = 3.0;
    } else if ((Elevator_project_B.queue[1] != 0.0) &&
               (Elevator_project_U.position > 1.0)) {
      Elevator_project_DW.dest = 2.0;
    } else if ((Elevator_project_B.queue[0] != 0.0) &&
               (Elevator_project_U.position != 0.0)) {
      Elevator_project_DW.dest = 1.0;
    } else {
      Elevator_project_DW.dir = 0.0;
    }
  } else if ((Elevator_project_B.queue[0] != 0.0) &&
             (Elevator_project_U.position != 0.0)) {
    Elevator_project_DW.dest = 1.0;
  } else if (Elevator_project_B.queue[1] != 0.0) {
    /* Inport: '<Root>/position' */
    if (Elevator_project_U.position > 1.0) {
      Elevator_project_DW.dest = 2.0;
    } else if (Elevator_project_U.position < 1.0) {
      Elevator_project_DW.dest = 2.0;
    } else {
      Elevator_project_DW.dir = 0.0;
    }
  } else if (Elevator_project_B.queue[2] != 0.0) {
    /* Inport: '<Root>/position' */
    if (Elevator_project_U.position > 2.0) {
      Elevator_project_DW.dest = 3.0;
    } else if (Elevator_project_U.position < 2.0) {
      Elevator_project_DW.dest = 3.0;
    } else {
      Elevator_project_DW.dir = 0.0;
    }
  } else if (Elevator_project_B.queue[3] != 0.0) {
    /* Inport: '<Root>/position' */
    if (Elevator_project_U.position > 3.0) {
      Elevator_project_DW.dest = 4.0;
    } else if (Elevator_project_U.position < 3.0) {
      Elevator_project_DW.dest = 4.0;
    } else {
      Elevator_project_DW.dir = 0.0;
    }
  } else if ((Elevator_project_B.queue[4] != 0.0) &&
             (Elevator_project_U.position != 4.0)) {
    Elevator_project_DW.dest = 5.0;
  } else {
    Elevator_project_DW.dir = 0.0;
  }
}

/* Function for Chart: '<Root>/Chart' */
static real_T Elevator_project_current_floor(void)
{
  real_T o;
  if (Elevator_project_DW.dir == 0.0) {
    if ((Elevator_project_B.queue[0] != 0.0) && (Elevator_project_B.queue[1] ==
         0.0) && (Elevator_project_B.queue[2] == 0.0) &&
        (Elevator_project_B.queue[3] == 0.0) && (Elevator_project_B.queue[4] ==
         0.0) && ((Elevator_project_U.position < 1.0) &&
                  (Elevator_project_U.position >= 0.0))) {
      o = 1.0;
      Elevator_project_DW.dest = 1.0;
    } else if ((Elevator_project_B.queue[0] == 0.0) &&
               (Elevator_project_B.queue[1] != 0.0) &&
               (Elevator_project_B.queue[2] == 0.0) &&
               (Elevator_project_B.queue[3] == 0.0) &&
               (Elevator_project_B.queue[4] == 0.0) &&
               ((Elevator_project_U.position < 2.0) &&
                (Elevator_project_U.position >= 1.0))) {
      o = 1.0;
      Elevator_project_DW.dest = 2.0;
    } else if ((Elevator_project_B.queue[0] == 0.0) &&
               (Elevator_project_B.queue[1] == 0.0) &&
               (Elevator_project_B.queue[2] != 0.0) &&
               (Elevator_project_B.queue[3] == 0.0) &&
               (Elevator_project_B.queue[4] == 0.0) &&
               ((Elevator_project_U.position < 3.0) &&
                (Elevator_project_U.position >= 2.0))) {
      o = 1.0;
      Elevator_project_DW.dest = 3.0;
    } else if ((Elevator_project_B.queue[0] == 0.0) &&
               (Elevator_project_B.queue[1] == 0.0) &&
               (Elevator_project_B.queue[2] == 0.0) &&
               (Elevator_project_B.queue[3] != 0.0) &&
               (Elevator_project_B.queue[4] == 0.0) &&
               ((Elevator_project_U.position < 4.0) &&
                (Elevator_project_U.position >= 3.0))) {
      o = 1.0;
      Elevator_project_DW.dest = 4.0;
    } else if ((Elevator_project_B.queue[0] == 0.0) &&
               (Elevator_project_B.queue[1] == 0.0) &&
               (Elevator_project_B.queue[2] == 0.0) &&
               (Elevator_project_B.queue[3] == 0.0) &&
               (Elevator_project_B.queue[4] != 0.0) &&
               (Elevator_project_U.position >= 4.0)) {
      o = 1.0;
      Elevator_project_DW.dest = 5.0;
    } else {
      o = 0.0;
    }
  } else {
    o = 0.0;
  }

  return o;
}

/* Function for Chart: '<Root>/Chart' */
static real_T Elevator_project_floor_check_g(void)
{
  real_T out;
  if (Elevator_project_DW.dir > 0.0) {
    if ((Elevator_project_B.queue[1] != 0.0) && (Elevator_project_U.position <
         1.0)) {
      Elevator_project_DW.dest = 2.0;
      out = 1.0;
    } else if ((Elevator_project_B.queue[2] != 0.0) &&
               (Elevator_project_U.position < 2.0)) {
      Elevator_project_DW.dest = 3.0;
      out = 1.0;
    } else if ((Elevator_project_B.queue[3] != 0.0) &&
               (Elevator_project_U.position < 3.0)) {
      Elevator_project_DW.dest = 4.0;
      out = 1.0;
    } else if ((Elevator_project_B.queue[4] != 0.0) &&
               (Elevator_project_U.position != 4.0)) {
      Elevator_project_DW.dest = 5.0;
      out = 1.0;
    } else {
      Elevator_project_DW.dir = 0.0;
      out = -1.0;
    }
  } else if (Elevator_project_DW.dir < 0.0) {
    if ((Elevator_project_B.queue[3] != 0.0) && (Elevator_project_U.position >
         3.0)) {
      Elevator_project_DW.dest = 4.0;
      out = 0.0;
    } else if ((Elevator_project_B.queue[2] != 0.0) &&
               (Elevator_project_U.position > 2.0)) {
      Elevator_project_DW.dest = 3.0;
      out = 0.0;
    } else if ((Elevator_project_B.queue[1] != 0.0) &&
               (Elevator_project_U.position > 1.0)) {
      Elevator_project_DW.dest = 2.0;
      out = 0.0;
    } else if ((Elevator_project_B.queue[0] != 0.0) &&
               (Elevator_project_U.position != 0.0)) {
      Elevator_project_DW.dest = 1.0;
      out = 0.0;
    } else {
      Elevator_project_DW.dir = 0.0;
      out = -1.0;
    }
  } else if ((Elevator_project_B.queue[0] != 0.0) &&
             (Elevator_project_U.position != 0.0)) {
    Elevator_project_DW.dest = 1.0;
    out = 0.0;
  } else if (Elevator_project_B.queue[1] != 0.0) {
    /* Inport: '<Root>/position' */
    if (Elevator_project_U.position > 1.0) {
      Elevator_project_DW.dest = 2.0;
      out = 0.0;
    } else if (Elevator_project_U.position < 1.0) {
      Elevator_project_DW.dest = 2.0;
      out = 1.0;
    } else {
      out = -1.0;
      Elevator_project_DW.dir = 0.0;
    }
  } else if (Elevator_project_B.queue[2] != 0.0) {
    /* Inport: '<Root>/position' */
    if (Elevator_project_U.position > 2.0) {
      Elevator_project_DW.dest = 3.0;
      out = 0.0;
    } else if (Elevator_project_U.position < 2.0) {
      Elevator_project_DW.dest = 3.0;
      out = 1.0;
    } else {
      out = -1.0;
      Elevator_project_DW.dir = 0.0;
    }
  } else if (Elevator_project_B.queue[3] != 0.0) {
    /* Inport: '<Root>/position' */
    if (Elevator_project_U.position > 3.0) {
      Elevator_project_DW.dest = 4.0;
      out = 0.0;
    } else if (Elevator_project_U.position < 3.0) {
      Elevator_project_DW.dest = 4.0;
      out = 1.0;
    } else {
      out = -1.0;
      Elevator_project_DW.dir = 0.0;
    }
  } else if ((Elevator_project_B.queue[4] != 0.0) &&
             (Elevator_project_U.position != 4.0)) {
    Elevator_project_DW.dest = 5.0;
    out = 1.0;
  } else {
    out = -1.0;
    Elevator_project_DW.dir = 0.0;
  }

  return out;
}

/* Function for Chart: '<Root>/Chart' */
static void E_chartstep_c3_Elevator_project(void)
{
  if (Elevator_project_DW.sfEvent == Elevator_project_event_floor0) {
    Elevator_project_B.queue[0] = 1.0;
  }

  if (Elevator_project_DW.sfEvent == Elevator_project_event_floor1) {
    Elevator_project_B.queue[1] = 1.0;
  }

  if (Elevator_project_DW.sfEvent == Elevator_project_event_floor2) {
    Elevator_project_B.queue[2] = 1.0;
  }

  if (Elevator_project_DW.sfEvent == Elevator_project_event_floor3) {
    Elevator_project_B.queue[3] = 1.0;
  }

  if (Elevator_project_DW.sfEvent == Elevator_project_event_floor4) {
    Elevator_project_B.queue[4] = 1.0;
  }

  if (Elevator_project_DW.sfEvent == Elevator_proje_event_Open_doors) {
    Elevator_project_DW.open_door = 1.0;
  }

  Elevator_project_Error_check();
  switch (Elevator_project_DW.is_Init) {
   case Elevator_project_IN_Door:
    if (Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) {
      Elevator_project_DW.do_d = 1.0;

      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 1.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Emergency;

      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;
    } else if (Elevator_project_DW.open_door == 1.0) {
      Elevator_project_DW.open_door = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Door;
      Elevator_project_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 1.0;
      Elevator_project_B.queue[(int32_T)Elevator_project_DW.dest - 1] = 0.0;
    } else if (Elevator_project_DW.temporalCounter_i1 >= 5) {
      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Idle_state;
    } else {
      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 1.0;
      Elevator_project_B.queue[(int32_T)Elevator_project_DW.dest - 1] = 0.0;
    }
    break;

   case Elevator_project_IN_Down:
    /* Inport: '<Root>/position' */
    if (Elevator_project_U.position <= Elevator_project_DW.dest - 0.98) {
      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Door;
      Elevator_project_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 1.0;
      Elevator_project_B.queue[(int32_T)Elevator_project_DW.dest - 1] = 0.0;
    } else if (Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) {
      Elevator_project_DW.d = 1.0;

      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 1.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Emergency;

      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;
    } else {
      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = -0.2;
      Elevator_project_DW.dir = -1.0;
      Elevator_project_floor_check();
    }

    /* End of Inport: '<Root>/position' */
    break;

   case Elevator_project_IN_Emergency:
    if ((Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) &&
        (Elevator_project_DW.i == 1.0)) {
      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 0.0;
      Elevator_project_DW.i = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Idle_state;
    } else if ((Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) &&
               (Elevator_project_DW.u == 1.0)) {
      Elevator_project_DW.u = 0.0;

      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Up;

      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.2;
      Elevator_project_DW.dir = 1.0;
      Elevator_project_floor_check();
    } else if ((Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) &&
               (Elevator_project_DW.do_d == 1.0)) {
      Elevator_project_DW.do_d = 0.0;

      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Door;
      Elevator_project_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 1.0;
      Elevator_project_B.queue[(int32_T)Elevator_project_DW.dest - 1] = 0.0;
    } else if ((Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) &&
               (Elevator_project_DW.d == 1.0)) {
      Elevator_project_DW.d = 0.0;

      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Down;

      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = -0.2;
      Elevator_project_DW.dir = -1.0;
      Elevator_project_floor_check();
    } else {
      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;
    }
    break;

   case Elevator_project_IN_Idle_state:
    if (Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) {
      Elevator_project_DW.i = 1.0;

      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 1.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Emergency;

      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;
    } else if ((Elevator_project_current_floor() == 1.0) ||
               ((Elevator_project_DW.open_door == 1.0) &&
                (Elevator_project_Y.Speed == 0.0))) {
      Elevator_project_DW.open_door = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Door;
      Elevator_project_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 1.0;
      Elevator_project_B.queue[(int32_T)Elevator_project_DW.dest - 1] = 0.0;
    } else if (Elevator_project_floor_check_g() == 1.0) {
      Elevator_project_DW.is_Init = Elevator_project_IN_Up;

      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.2;
      Elevator_project_DW.dir = 1.0;
      Elevator_project_floor_check();
    } else {
      if (Elevator_project_floor_check_g() == 0.0) {
        Elevator_project_DW.is_Init = Elevator_project_IN_Down;

        /* Outport: '<Root>/Speed' */
        Elevator_project_Y.Speed = -0.2;
        Elevator_project_DW.dir = -1.0;
        Elevator_project_floor_check();
      }
    }
    break;

   default:
    /* case IN_Up: */
    if (Elevator_project_DW.sfEvent == Elevator_projec_event_Emergency) {
      Elevator_project_DW.u = 1.0;

      /* Outport: '<Root>/ELamp' */
      Elevator_project_Y.ELamp = 1.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Emergency;

      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;
    } else if (Elevator_project_U.position >= Elevator_project_DW.dest - 1.0) {
      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.0;
      Elevator_project_DW.is_Init = Elevator_project_IN_Door;
      Elevator_project_DW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/DoorLamp' */
      Elevator_project_Y.DoorLamp = 1.0;
      Elevator_project_B.queue[(int32_T)Elevator_project_DW.dest - 1] = 0.0;
    } else {
      /* Outport: '<Root>/Speed' */
      Elevator_project_Y.Speed = 0.2;
      Elevator_project_DW.dir = 1.0;
      Elevator_project_floor_check();
    }
    break;
  }
}

/* Model step function */
void Elevator_project_step(void)
{
  ZCEventType zcEvent[8];
  int8_T rtb_inputevents[8];
  int32_T i;
  boolean_T zcEvent_0;

  /* Chart: '<Root>/Chart' incorporates:
   *  TriggerPort: '<S1>/input events'
   */
  /* Inport: '<Root>/Floor0' */
  zcEvent[0] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[0],
                        (Elevator_project_U.Floor0));

  /* Inport: '<Root>/Floor1' */
  zcEvent[1] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[1],
                        (Elevator_project_U.Floor1));

  /* Inport: '<Root>/Floor2' */
  zcEvent[2] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[2],
                        (Elevator_project_U.Floor2));

  /* Inport: '<Root>/Floor3' */
  zcEvent[3] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[3],
                        (Elevator_project_U.Floor3));

  /* Inport: '<Root>/Floor4' */
  zcEvent[4] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[4],
                        (Elevator_project_U.Floor4));

  /* Inport: '<Root>/E' */
  zcEvent[5] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[5],
                        (Elevator_project_U.E));

  /* Inport: '<Root>/Open_door' */
  zcEvent[6] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[6],
                        (Elevator_project_U.Open_door));

  /* Inport: '<Root>/tic' */
  zcEvent[7] = rt_ZCFcn(RISING_ZERO_CROSSING,
                        &Elevator_project_PrevZCX.Chart_Trig_ZCE[7],
                        (Elevator_project_U.tic));
  zcEvent_0 = false;
  for (i = 0; i < 8; i++) {
    zcEvent_0 = (zcEvent_0 || (zcEvent[i] != NO_ZCEVENT));
  }

  if (zcEvent_0) {
    for (i = 0; i < 8; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    if (rtb_inputevents[0U] == 1) {
      Elevator_project_DW.sfEvent = Elevator_project_event_floor0;
      E_chartstep_c3_Elevator_project();
    }

    if (rtb_inputevents[1U] == 1) {
      Elevator_project_DW.sfEvent = Elevator_project_event_floor1;
      E_chartstep_c3_Elevator_project();
    }

    if (rtb_inputevents[2U] == 1) {
      Elevator_project_DW.sfEvent = Elevator_project_event_floor2;
      E_chartstep_c3_Elevator_project();
    }

    if (rtb_inputevents[3U] == 1) {
      Elevator_project_DW.sfEvent = Elevator_project_event_floor3;
      E_chartstep_c3_Elevator_project();
    }

    if (rtb_inputevents[4U] == 1) {
      Elevator_project_DW.sfEvent = Elevator_project_event_floor4;
      E_chartstep_c3_Elevator_project();
    }

    if (rtb_inputevents[5U] == 1) {
      Elevator_project_DW.sfEvent = Elevator_projec_event_Emergency;
      E_chartstep_c3_Elevator_project();
    }

    if (rtb_inputevents[6U] == 1) {
      Elevator_project_DW.sfEvent = Elevator_proje_event_Open_doors;
      E_chartstep_c3_Elevator_project();
    }

    if (rtb_inputevents[7U] == 1) {
      if (Elevator_project_DW.temporalCounter_i1 < 7U) {
        Elevator_project_DW.temporalCounter_i1++;
      }

      Elevator_project_DW.sfEvent = Elevator_project_event_tic;
      E_chartstep_c3_Elevator_project();
    }
  }

  /* Outport: '<Root>/queue0' */
  Elevator_project_Y.queue0 = Elevator_project_B.queue[0];

  /* Outport: '<Root>/queue1' */
  Elevator_project_Y.queue1 = Elevator_project_B.queue[1];

  /* Outport: '<Root>/queue2' */
  Elevator_project_Y.queue2 = Elevator_project_B.queue[2];

  /* Outport: '<Root>/queue3' */
  Elevator_project_Y.queue3 = Elevator_project_B.queue[3];

  /* Outport: '<Root>/queue4' */
  Elevator_project_Y.queue4 = Elevator_project_B.queue[4];
}

/* Model initialize function */
void Elevator_project_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Elevator_project_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Elevator_project_B), 0,
                sizeof(B_Elevator_project_T));

  /* states (dwork) */
  (void) memset((void *)&Elevator_project_DW, 0,
                sizeof(DW_Elevator_project_T));

  /* external inputs */
  (void)memset(&Elevator_project_U, 0, sizeof(ExtU_Elevator_project_T));

  /* external outputs */
  (void) memset((void *)&Elevator_project_Y, 0,
                sizeof(ExtY_Elevator_project_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Elevator_project_PrevZCX.Chart_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }
  }

  /* SystemInitialize for Chart: '<Root>/Chart' */
  Elevator_project_DW.temporalCounter_i1 = 0U;

  /* Chart: '<Root>/Chart' */
  Elevator_project_DW.open_door = 0.0;
  Elevator_project_DW.dest = 1.0;

  /* Outport: '<Root>/Speed' incorporates:
   *  Chart: '<Root>/Chart'
   * */
  Elevator_project_Y.Speed = 0.0;

  /* Chart: '<Root>/Chart' */
  Elevator_project_B.queue[0] = 0.0;

  /* Outport: '<Root>/ELamp' incorporates:
   *  Chart: '<Root>/Chart'
   * */
  Elevator_project_Y.ELamp = 0.0;

  /* Chart: '<Root>/Chart' */
  Elevator_project_DW.dir = 0.0;
  Elevator_project_DW.i = 0.0;
  Elevator_project_DW.u = 0.0;
  Elevator_project_DW.d = 0.0;
  Elevator_project_DW.do_d = 0.0;
  Elevator_project_DW.is_Init = Elevator_project_IN_Idle_state;
}

/* Model terminate function */
void Elevator_project_terminate(void)
{
  /* (no terminate code required) */
}
