//---------Libraries---------
#include <Arduino.h>
#include <Adafruit_BNO08x.h>
#include <RunningMedian.h>
#include <Math.h>
#include "irSensorV3.h"

//---------Compass Pins---------
#define BNO08X_CS 10
#define BNO08X_INT 9
#define BNO08X_RESET -1

//---------Initializing Libraries---------
IRSensor irSensor;
Adafruit_BNO08x bno08x(BNO08X_RESET);
sh2_SensorValue_t sensorValue;
RunningMedian ballAngleMedian = RunningMedian(5);

//REQUIRED FOR COMPASS SETUP
//Used for setting up the compass
void setReports(void) {
    Serial.println("Setting desired reports");
    if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {Serial.println("Could not enable game vector");}
}

//Initialize the Compass
void compassInit() {
    if (bno08x.wasReset()) {setReports();}
    if (!bno08x.getSensorEvent(&sensorValue)) {return;}
}


//Returns the a int from 0-11 for which sensor the ball is closest to. 
float getBotAngle() {return sensorValue.un.gameRotationVector.k;}

//Packs the data so it can be sent down
//type 1 = compass, 2 = ball distance, 3 = ball angle, 4 = net angle
int pack(int value, int type) {
    int info = -1;
    switch(type) {
    case 1: 
        info = map(value, -99, 99, 0, 250);
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

//setup
void setup(){
//--------Starting Serial-----------
    // Serial.begin(9600);
    Serial7.begin(1152000);

//-------Starting Compass UART-----------
    if (!bno08x.begin_UART(&Serial1)) {
        Serial.println("Failed to find BNO08x chip");
        while (1) {
            delay(10);
        }
    }
    setReports();
    delay(100);
}

void loop() {

    compassInit();//Compass
    
    //---------------Setting up Variables---------------
    u_int8_t compassAngle = pack(getBotAngle()*100, 1);
    u_int8_t ballAngle = pack(ballAngleMedian.getMedian(), 3);
    u_int8_t intensity = irSensor.getIntensity(ballAngle);
    u_int8_t distance = pack(irSensor.findSensorDistance(ballAngle, intensity), 2);

    //Getting the RunningMedian of the BallAngle
    ballAngleMedian.add(irSensor.getBallAngle());

    //Reading value from Camera
    int cameraValue = pulseIn(10, HIGH, 600);

    //If the camera sends down anything above 0. It means that it is getting valid data from Camera
    //If camera sends anything above 250. It means that it cannot see the net and will set it to 253. 
    if (cameraValue > 0) {if(cameraValue > 250) {cameraValue = 253;}}
    else {cameraValue = 0;}


    
    //Putting all the data into a array to send down
    u_int8_t information[5] = { 255, compassAngle, distance, ballAngle, u_int8_t(cameraValue) };
    
    //Sending down the Data down
    Serial7.write(information, 5);

    //--------DeBug/Read Data-----------
    Serial.print("compass angle: ");
    Serial.print(information[1]);
    Serial.print(" ballgit distance: ");
    Serial.print(information[2]);
    Serial.print(" ball angle: ");
    Serial.print(information[3]);
    Serial.print(" net angle: ");
    Serial.println(information[4]);
}
