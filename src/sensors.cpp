//sensors.cpp

#include "sensors.h"

#define ADC_MIN 230 //fully wet 
#define ADC_MAX 460 //fully dry

MoistureSensor::MoistureSensor(uint8_t pin)
: analogPin(pin), lastRaw(0) {}

void MoistureSensor::init() {
    pinMode(analogPin, INPUT);
}

int MoistureSensor::readRaw() {
    lastRaw = analogRead(analogPin);
    return lastRaw;
}

int MoistureSensor::readPercent() {
    int raw = readRaw();

    // Clamp
    raw = constrain(raw, ADC_MIN, ADC_MAX);

    // Map dry->wet to 0–100
    return map(raw, ADC_MAX, ADC_MIN, 0, 100);
}

bool MoistureSensor::isValid() {
    // Catch disconnected sensor or short TODO fix these numbers
    return (lastRaw > 50 && lastRaw < 1000);
}


