// state machine.h

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <Arduino.h>

// State definitions

enum SystemState {
    INIT,
    IDLE, 
    MEASURE,
    WATERING,
    ERROR
};

// Public functions
void stateMachineInit();
void stateMachineUpdate(unsigned long currentMillis);
const char* getCurrentStateName();

#endif
