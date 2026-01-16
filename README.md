Automated Irrigation System
Author: Evan Rohan
Language: C++ (Arduino)
PLatform: Arduino MEGA 2560

OVERVIEW
This project is an automated soil watering system for my houseplants using:
- Moisture sensor(analog input)
- Pump
- Arduino
- State machine for watering and fault detection

Features:
- Measure soil moisture regularly
- Waters the soil when below a certain threshold
- Includes fault detection for pump and sensors
- Modular design with sensor and actuator abstraction

Hardware:
- Arduino MEGA
- Analog soil moisture sensor
- Small water pump
- breadboard, jumper wires, power source

Calibration:
This system is calibrated using the following readings

Soil condition      ADC reading
In direct water     204
Moist Soil          265
In air              457

Due to wanting the plant to dry out and then get rewatered I am using a moisture threshold of 300