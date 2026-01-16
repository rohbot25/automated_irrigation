/*Automated Irrigation System
*Made by EVAN ROHAN 01/15/2026
*/

#include "state_machine.h"
#include "sensors.h"
#include "actuators.h"

unsigned long currentMillis = 0;

void setup() {
    // Initialize serial monitor for debugging
    Serial.begin(9600);

    //Initialize sensors
    sensorsInit();

    //Initialize actuators
    actuatorsInit();

    //Initialize state machine
    stateMachineInit();

    Serial.println("Automated irrigation system started.");

}

void loop() {
    //pump testing
    //pumpOn();
    //delay(2000);
    //pumpOff();
    //delay(2000);
    // update current time
    currentMillis = millis();

    //u pdate state machine
    stateMachineUpdate(currentMillis);

    Serial.print("State: "); Serial.println(getCurrentStateName());
    Serial.print("Moisture: "); Serial.println(readMoisture());

    delay(100);

   }

