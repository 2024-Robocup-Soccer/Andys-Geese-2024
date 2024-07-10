#ifndef COMPASS_H
#define COMPASS_H

#include <Arduino.h>

class Compass {
public: 
    Compass();
    void init();
    void initPrint();
    void resetCheck();
    void resetCheckPrint();
    float getBallAngle();
    
private:
    void setReports();
};

#endif