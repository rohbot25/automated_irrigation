//sensors.h

#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class MoistureSensor {
    public:
        MoistureSensor(uint8_t pin);

        void init();
        int readRaw();
        int readPercent();
        bool isValid();

    private:
        uint8_t analogPin;
        int lastRaw;
};

#endif
