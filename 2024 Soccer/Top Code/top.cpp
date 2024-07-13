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

    Serial.begin(9600);
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
    // }

    if (!bno08x.getSensorEvent(&sensorValue))
    {
        return;
    }
}
//type 1 = compass, 2 = ball distance, 3 = ball angle, 4 = net angle
int pack(int value, int type) {
    int info = -1;
    switch(type) {
    case 1: 
        info = map(value, -99, 99, 0, 360);
        break;
    case 2:
        info = map(value, 0, 1557, 0, 250);
        break;
    case 3:
        info = map(value, 0, 11, 0, 250);
        break;
    case 4: 
        info = info;
        break;
    }
    return info;
}


void loop() {
    compassInit();
    int val = pulseIn(10, HIGH, 1000);
    int compassAngle = getBotAngle()*100;
    int ballAngle = irSensor.getBallAngle();
    int intensity = irSensor.getIntensity(ballAngle);
    int distance = irSensor.findSensorDistance(ballAngle, intensity);

    Serial7.write(255);
    Serial7.write(pack(compassAngle, 1));
    Serial7.write(pack(distance, 2));
    Serial7.write(pack(ballAngle, 3));
    // 0 = no info from the camera
    // 1-250 = angle value of goal relative to robot
    // 500 = no goal found
    if (val>0){ Serial7.write(pack(val,4));}
    else{Serial7.write(-1);}//No Info from Camera


    
    // Serial.print("compass angle: ");
    // Serial.println(pack(compassAngle, 1));
    // Serial.print(" ball distance: ");
    // Serial.println(distance);
    // Serial.print(" ball angle: ");
    // Serial.println(ballAngle);
    // Serial.print(" net angle: ");
    // Serial.println(val);
}
