#ifndef COLORSENSORV2_H
#define COLORSENSORV2_H

#include <Arduino.h>
#include <RunningMedian.h>

class ColorSensor {
public:
    ColorSensor();
    int readSensor(int sensor);
    void colourSensorInit();
    void readSensors();
    void visualize();
    bool detectColor(int sensor);
    void calibrateSensors();
    float calculateDirection(int sensorValues[]);  // Updated method signature
    void readSensors(int sensorValues[]);  // Updated method signature
private:
    int whiteThreshold[16];  // Store individual thresholds for each sensor
};

#endif
