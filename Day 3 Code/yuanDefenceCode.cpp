/*
    Defense Code
    Face Net / Face Forward
    If its on green go back until white lone
    move according to the ball.
*/

#include "motorControlV3.h"
#include <RunningMedian.h>
#include <SPI.h>
#include <Arduino.h>
#include "colorSensorV3.h"

const float pi = PI;
int information, robotAngle, ballDistance, ballAngle, netAngle, inputType;
bool onGreen, goalPID, faceDirection, backLine = false;
bool inAdj = true;
int timeZero, colourVal;
int motorValue =100;
const int BUTTON_PIN = 13;


ColorSensor colourSensor;
Motor motorController;

void sync() {
    byte check[5];
    int shift=0;
    if(Serial2.available() > 4) {Serial2.readBytes(check, 5);}
    for (int i=0; i<5; i++) {if (check[i] == 255) {shift = i;}}
    for (int i=0; i<shift; i++) {Serial2.read();}
}

int unpackData(int value, int type) {
    int info = -1;
    if(type == 1) {info = map(value, 0, 250, -180, 180);}
    else if(type == 2) {info = value;}
    else if(type == 3) {info = map(value, 0, 250, 0, 360);}
    else if(type == 4) {info = map(value, 1, 250, -50, 50);}
    return info;
}

void pointNorth(){
    int motorValue = 50;
    if (robotAngle <= 20 && robotAngle >= -20) {
        if (inAdj){
            inAdj = false;
            faceDirection = true;
        }
    }
    else if (robotAngle < -20) {
        motorController.moveRobot(motorValue, motorValue, motorValue, motorValue);
        inAdj = true;
        faceDirection = false;
    }
    else if (robotAngle > 20) {
        motorController.moveRobot(-motorValue, -motorValue, -motorValue, -motorValue);
        inAdj = true;
        faceDirection = false;
    }
}

int moveDir() {
    int averageCount = 5;
    float newVal=0;
    for(int i=0;i<averageCount;i++){newVal += colourSensor.calculateDirection();}
    newVal = newVal/averageCount;
    if (newVal > 1.91) {return 0;}
    else if (newVal >= -0.8 && newVal <= -0.1) {return 180;}
    else if(newVal >=0.7 && newVal <= 1.2) {return 270;}
    else if(newVal>=-2.6 && newVal <-1.7){return 90;}
    else if(newVal == 0){return -1;}
    else{return -255;}
}

void followBall(){
    int goalieSpeed = 80;
    if(!inAdj){
        if(ballAngle == 0){
            motorController.moveRobot(0, 0, 0, 0);//Stop
        }
        else if (ballAngle>30 && ballAngle<100){ //Angle 33, 65, 98
            motorController.moveRobot(goalieSpeed,-goalieSpeed,-goalieSpeed,goalieSpeed);//Left
        }
        else if (ballAngle>290 && ballAngle<365){//Angle 295, 327, 360
            motorController.moveRobot(-goalieSpeed,+goalieSpeed,+goalieSpeed,-goalieSpeed);//Right
        }
        else if(ballAngle>125 && ballAngle<200){//Angle 131, 164, 196
            motorController.moveRobot(-goalieSpeed,+goalieSpeed,+goalieSpeed,-goalieSpeed);//Right
        }
        else if(ballAngle>225 && ballAngle<270){//Angle 229, 262
            motorController.moveRobot(-goalieSpeed,+goalieSpeed,+goalieSpeed,-goalieSpeed);//Right
        }
    }
}

void setup() {
    Serial.begin(20000000);
    Serial2.begin(20000000);
    timeZero = millis();

    pinMode(BUTTON_PIN, INPUT);

    motorController.initMotors();
    colourSensor.init();
}

void loop(){

    if(Serial2.available() > 0) {
        information = Serial2.read();
        switch (inputType) {
        case 0:
            if(information == 255) {inputType++;}
            // Serial.println("Case 0");
            break;
        case 1:
            robotAngle = unpackData(information, 1);
            // Serial.println("Case 1");
            inputType++;
            break;
        case 2:
            ballDistance = unpackData(information,2);
            // Serial.println("Case 2");
            inputType++;
            break;
        case 3:
            ballAngle = unpackData(information,3);
            // Serial.println("Case 3");
            inputType++;
            break;
        case 4:
            netAngle = unpackData(information,4);
            // Serial.println("Case 4");
            inputType = 0;
            break;
        }
        Serial2.flush();
    }


    // Serial.print("Robot Angle: ");
    // Serial.print(robotAngle);
    // Serial.print(" Ball Distance: ");
    // Serial.print(ballDistance);
    // Serial.print(" Ball Angle: ");
    // Serial.print(ballAngle);
    // Serial.print(" Net Angle: ");
    // Serial.print(netAngle);

    colourVal = moveDir();
    if(colourVal != -1){onGreen = false;}

    if(digitalRead(BUTTON_PIN) == HIGH){
        Serial.print("Button On");
        if(!backLine){
            Serial.print(" Not Back Line");
            if(onGreen == true){
                Serial.print(" On Green");
                if(inAdj == false){
                    Serial.print(" Direction True");
                    Serial.print(robotAngle);
                    pointNorth();
                    //Move Backwards
                    motorController.moveRobot(motorValue, motorValue, - motorValue, - motorValue);
                }
                else {
                    Serial.print(" Direction False");
                    if(netAngle == 51 || netAngle == -50){ //DOUBLE CHECK VALUES
                        pointNorth();
                    }
                    else{
                        netPID();
                    }
                }
            }
            else{
                Serial.print(" Off Green");
                if(colourVal == 255){
                    onGreen = false;
                }
                else if(colourVal == 90){
                    //Move Forward
                    onGreen = false;
                    motorController.moveRobot(-motorValue*0.7, -motorValue*0.7, + motorValue, + motorValue);

                }
                else if(colourVal == 180){
                    backLine = true;
                    motorController.moveRobot(0, 0, 0, 0);
                    //Dont Move
                }
                else if(colourVal == 270){
                    //Move Forward
                    onGreen = false;
                    motorController.moveRobot(-motorValue*0.7, -motorValue*0.7, + motorValue, + motorValue);
                }
                else if(colourVal == -1){
                    onGreen = true;
                    motorController.moveRobot(0, 0, 0, 0);
                    //Dont Move
                }
            }
        }
        else{
            Serial.print(" On Back Line");
            followBall();
            if(colourVal == -1){backLine = true;}
        }
    }
    else{
        Serial.print("Button OFF");
        motorController.moveRobot(0, 0, 0, 0);
    }
    Serial.println("");
}



