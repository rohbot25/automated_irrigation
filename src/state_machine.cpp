// state_machine.cpp

#include "state_machine.h"
#include "sensors.h" //readMoisture()
#include "actuators.h" // pumpOn(), pumpOff()

//Constants
const int MOISTURE_THRESHOLD = 370;
const unsigned long MEASURE_INTERVAL = 5000; //5 sec between measures
const unsigned long MAX_PUMP_TIME = 10000;  //10 max WATERING

//Internal state variables
static SystemState currentState;
static unsigned long lastMeasureTime = 0;
static unsigned long pumpStartTime = 0;

void stateMachineInit() {
    currentState = INIT;
    lastMeasureTime = millis();
    pumpStartTime = 0;

    //make sure pump is off
    pumpOff();
}

const char* getCurrentStateName() {
    switch(currentState) {
        case INIT: return "INIT";
        case IDLE: return "IDLE";
        case MEASURE: return "MEASURE";
        case WATERING: return "WATERING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void stateMachineUpdate(unsigned long currentMillis) {
    switch(currentState) {
        
        case INIT:
            //startup complete
            currentState = IDLE;
            break;
        
        case IDLE:
            //wait for measurement interval
            if(currentMillis - lastMeasureTime >= MEASURE_INTERVAL) {
                currentState = MEASURE;
            }
            break;
        
        case MEASURE:
            lastMeasureTime = currentMillis; //reset measure timer

            if (readMoisture() < MOISTURE_THRESHOLD) {
                //start the pump
                pumpOn();
                pumpStartTime = currentMillis;
                currentState = WATERING
            } else {
                currentState = IDLE;
            }
            break;
        
        case WATERING:
            //check if soil is moist
            if(readMoisture() >= MOISTURE_THRESHOLD){
                pumpOff();
                currentState = IDLE;
            }
            //catch if pump is running too long
            else if (currentMillis - pumpStartTime >= MAX_PUMP_TIME) {
                pumpOff();
                currentState = ERROR;
            }
            break;
        
        case ERROR:
            pumpOff();
            //TODO maybe add a reset?
            break;
        
    }
}