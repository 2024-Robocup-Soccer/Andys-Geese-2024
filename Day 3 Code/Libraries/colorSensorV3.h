#ifndef COLORSENSORV3_H
#define COLORSENSORV3_H

#include <Arduino.h>
#include <RunningMedian.h>

class ColorSensor {
public:
    ColorSensor();
    void init();
    int readSensor(int sensor);
    void readSensors();
    void fillMedians();
    float calculateDirection(); 
    void visualize();
    bool detectColor(int sensor);
    void calibrateSensors();
};

#endif
