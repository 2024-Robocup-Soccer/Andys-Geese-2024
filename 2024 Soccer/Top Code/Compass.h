#ifndef COMPASS_H
#define COMPASS_H

#include <Arduino.h>
#include <Adafruit_BNO08x.h>

class Compass {
public: 
    Compass();
    void init();
    void initPrint();
    void resetCheck();
    void resetCheckPrint();
    float getBotAngle();
    void setReports();


};

#endif
