//actuators.cpp
#include "actuators.h"
//config

static const uint8_t PUMP_PIN = 7;//change when hardware
static const bool PUMP_ACTIVE_HIGH = true;

//internal state
static bool pumpState = false;

void actuatorsInit(){
    pinMode(PUMP_PIN, OUTPUT);
    pumpOff(); //fail safe
}

void pumpOn() {
    digitalWrite(PUMP_PIN, PUMP_ACTIVE_HIGH ? HIGH : LOW);
    pumpState = true
}

void pumpOff() {
    digitalWrite(PUMP_PIN, PUMP_ACTIVE_HIGH ? HIGH : LOW);
    pumpState = false;
}

bool isPumpOn() {
    return pumpState;
}