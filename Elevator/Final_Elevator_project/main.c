/* Don't include anything else from simulation/ */
#include "simulation/elevator.h"
#include "ele_code/Elevator_project.h"

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    elevator_h e;
    Elevator_project_initialize();

    /* Before we start, we must initialise the simulation */
    int ret;
    if ((ret = start_elevator(&e))) {
        fprintf(stderr, "Failed to initialise elevator simulator: %d\n", ret);
        return 1;
    }

    /* This is an example that runs a fixed program. Replace this by hooking up
     * to your own elevator controller. */
  while(1){

    Elevator_project_U.position=get_cart_position(e);
    set_motor_speed(e,Elevator_project_Y.Speed);
    
    if(get_button_state(e) & BUTTON_STATE_FLOOR0)  Elevator_project_U.Floor0=1.0;
    if(get_button_state(e) & BUTTON_STATE_FLOOR1)  Elevator_project_U.Floor1=1.0;
    if(get_button_state(e) & BUTTON_STATE_FLOOR2)  Elevator_project_U.Floor2=1.0;
    if(get_button_state(e) & BUTTON_STATE_FLOOR3)  Elevator_project_U.Floor3=1.0;
    if(get_button_state(e) & BUTTON_STATE_FLOOR4)  Elevator_project_U.Floor4=1.0;
    if(get_button_state(e) & BUTTON_STATE_EMERGENCY)  Elevator_project_U.E=1.0;

    if(get_button_state(e) & BUTTON_STATE_DOOR)  Elevator_project_U.Open_door=1.0;
    Elevator_project_U.position=get_cart_position(e);
    set_motor_speed(e,Elevator_project_Y.Speed);

    Elevator_project_U.tic = 1;
    Elevator_project_step();
    Elevator_project_U.tic= 0;
    Elevator_project_step();
    lamp_state lamps=0;

    if (Elevator_project_Y.queue0) lamps |= LAMP_STATE_FLOOR0;
    if (Elevator_project_Y.queue1) lamps |= LAMP_STATE_FLOOR1;
    if (Elevator_project_Y.queue2) lamps |= LAMP_STATE_FLOOR2;
    if (Elevator_project_Y.queue3) lamps |= LAMP_STATE_FLOOR3;
    if (Elevator_project_Y.queue4) lamps |= LAMP_STATE_FLOOR4;
    if (Elevator_project_Y.ELamp) lamps |= LAMP_STATE_EMERGENCY;
    set_lamp_state(e,lamps);
   
    if (Elevator_project_Y.DoorLamp){
      sleep(1);
      set_doors_open(e,true);
    }
    if (Elevator_project_Y.DoorLamp==0.0){
      set_doors_open(e,false);
    }

    Elevator_project_U.position=get_cart_position(e);
    set_motor_speed(e,Elevator_project_Y.Speed);
    
    usleep(10000);
    Elevator_project_U.Floor0=0.0;
    Elevator_project_U.Floor1=0.0;
    Elevator_project_U.Floor2=0.0;
    Elevator_project_U.Floor3=0.0;
    Elevator_project_U.Floor4=0.0;
    Elevator_project_U.E=0.0;
    Elevator_project_U.Open_door=0.0;
    
  }
    
    /* If we decide to quit, for whatever reason, we should stop the
     * simulation. */
  Elevator_project_terminate();
  stop_elevator(e);
    
    return 0;
}
