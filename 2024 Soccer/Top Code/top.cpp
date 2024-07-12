//Adding Libraries
#include <Arduino.h>
#include <Adafruit_BNO08x.h>
#include <RunningMedian.h>
#include <Math.h>
#include "irSensorV3.h"


IRSensor irSensor;

#define BNO08X_CS 10
#define BNO08X_INT 9
#define BNO08X_RESET -1
Adafruit_BNO08x bno08x(BNO08X_RESET);
sh2_SensorValue_t sensorValue;


//Used for setting up the compass
void setReports(void)
{
    Serial.println("Setting desired reports");
    if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR))
    {
        Serial.println("Could not enable game vector");
    }
}

//returns the compass angle
float getBotAngle()
{
    return sensorValue.un.gameRotationVector.k;
}

//setup
void setup(){

    //Serial.begin(9600);
    Serial7.begin(9600);
    if (!bno08x.begin_UART(&Serial1))
    {
        //Serial.println("Failed to find BNO08x chip");
        while (1)
        {
            delay(10);
        }
    }
    setReports();
    delay(100);
}

//Initialize the Compass
void compassInit() {
     if (bno08x.wasReset())
    {
        //Serial.print("sensor was reset ");
        setReports();
    }

    if (!bno08x.getSensorEvent(&sensorValue))
    {
        return;
    }
}

void loop() {
    compassInit();
    int val = pulseIn(10, HIGH, 1000);
    int compassAngle = getBotAngle()*100;
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
    else{Serial7.write(-1);}//No Info from Camera

    Serial.print("compass angle: ");
    Serial.print(compassAngle);
    Serial.print(" ball distance: ");
    Serial.print(distance);
    Serial.print(" ball angle: ");
    Serial.print(ballAngle);
    Serial.print(" net angle: ");
    Serial.println(val);
}
