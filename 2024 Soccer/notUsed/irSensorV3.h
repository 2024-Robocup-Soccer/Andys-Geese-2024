#ifndef IRSENSORV3_H
#define IRSENSORV3_H

#include <Arduino.h>
#include <RunningMedian.h>

class IRSensor {
public:
    IRSensor();
    void readSensors();
    int findMinSensor();
    int findBallDirection();
    void printBallDirection();
    void debugValues();
    void debugComponents();

private:
    static const int sensorReadCount = 25;
    RunningMedian s1Distance, s2Distance, s3Distance, s4Distance, s5Distance, s6Distance, s7Distance, s8Distance, s9Distance, s10Distance, s11Distance, s12Distance;
    int sensorValues[12];
};

#endif
