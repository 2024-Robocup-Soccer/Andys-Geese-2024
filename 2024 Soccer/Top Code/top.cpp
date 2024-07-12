//Adding Libraries
#include <Arduino.h>
#include <Adafruit_BNO08x.h>
#include <RunningMedian.h>
#include <Math.h>
#include "irSensorV3.h"
#include "Compass.h"

IRSensor irSensor;
Compass compass;


//setup
void setup()
{

    Serial.begin(9600);
    Serial7.begin(9600);
    compass.init();
    compass.resetCheckPrint();
    compass.setReports();
    //delay(100);
}

 
void loop()
{
    int val = pulseIn(10, HIGH, 1000);
    int compassAngle = compass.getBotAngle();
    int ballAngle = irSensor.getBallAngle();
    int intensity = irSensor.getIntensity(ballAngle);
    int distance = irSensor.findSensorDistance(ballAngle, intensity);

    Serial7.write(255);
    Serial7.write(compassAngle);
    Serial7.write(distance);
    Serial7.write(ballAngle);

    // 0 = no info from the camera
    // 1-250 = angle value of goal relative to robot
    // 500 = no goal found
    if (val>0){ Serial7.write(val);}
    else{
        Serial7.write(-1);}//No Info from Camera
}
