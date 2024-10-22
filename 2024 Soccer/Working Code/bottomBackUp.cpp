#include "motorControlV3.h"
#include <RunningMedian.h>
#include <SPI.h>
#include <Arduino.h>
#include "colorSensorV3.h"


const float pi = PI;

int information, robotAngle, ballDistance, ballAngle, netAngle, motorValue, inputType;
bool inAdj = false;
bool onGreen = false; 
int speed = 160;

ColorSensor colourSensor;
Motor motorController;

int timeZero;
void setup() {
    Serial.begin(9600);
    Serial2.begin(20000000);
    timeZero = millis();

    motorController.initMotors();
    colourSensor.init();
}

int unpackData(int value, int type) {
    int info = -1;
    if(type == 1) {
         info = map(value, 0, 250, -180, 180);
        // info = value;
    }
    //not done
    else if(type == 2) {
        info = value;
    }
    else if(type == 3) {
         info = map(value, 0, 250, 0, 360);
        //info = value;
    }
    else if(type == 4) {
        info = map(value, 0, 250, -50, 50);
    }
    return info;
}

void behindBall(int ballAngle, int motorValue){
    if(!inAdj){
        if(ballAngle == 0){
            motorController.moveRobot(-motorValue*0.7, -motorValue*0.7, + motorValue, + motorValue);
            Serial.println("Behind Ball Code");
        }
        else if (ballAngle == 33){
            motorController.moveRobot(0, -motorValue, 0, motorValue);
            Serial.println("Behind Ball Code");
        }
        else if (ballAngle == 360){
            motorController.moveRobot(-motorValue, 0, motorValue, 0);
            Serial.println("Behind Ball Code");
        }
        else if (ballAngle == 131 || ballAngle == 98 || ballAngle == 65 || ballAngle == 262 || ballAngle == 295 || ballAngle == 327){
            motorController.moveRobot(motorValue, motorValue*0.7, -motorValue, -motorValue);
            Serial.println("Behind Ball Code");
        }
        else if(ballAngle < 327 && ballAngle >=164) {
            motorController.moveRobot(motorValue, 0, -motorValue, 0);
            Serial.println("Behind Ball Code");
        }
        else if(ballAngle <=164 && ballAngle > 196){
            motorController.moveRobot(0, motorValue, 0, -motorValue);
            Serial.println("Behind Ball Code");
        }
    }
}

void pointNorth(float compassAngle){
    int motorValue = 60;
    if (compassAngle <= 15 && compassAngle >= -15) {
        if (inAdj){
            inAdj = false;
            Serial.println("Point North Code");
        }
    }
    else if (compassAngle < -15) {
        motorController.moveRobot(motorValue, motorValue, motorValue, motorValue);
        Serial.println("Point North Code");
        inAdj = true;
    }
    else if (compassAngle > 15) {
        motorController.moveRobot(-motorValue, -motorValue, -motorValue, -motorValue);
        inAdj = true;
        Serial.println("Point North Code");
    }
}

void avoidWhite(int motorValue){

    int val = colourSensor.moveDir();
    int lastValue = val;
    int time = 2000;

    if(val == 255){
        val = lastValue;
        onGreen = false;
    }
    else if(val == 0){
        //move back
        onGreen = false;
        int startmillis = millis();
        // for (int i=0; i<time; i++) {
            motorController.moveRobot(motorValue*0.7, motorValue*0.7, -motorValue*1.2, -motorValue*1.2);
        // }
        Serial.print("Move Backward");

    }
    else if(val == 90){
        //move left
        onGreen = false;
        int startmillis = millis();
        // for (int i=0; i<time; i++) {
            motorController.moveRobot(motorValue, -motorValue, -motorValue, motorValue);
        // }
        Serial.print("Move Left");

    }
    else if(val == 180){
        //move forward
        onGreen = false;
        int startmillis = millis();
        // for (int i=0; i<time; i++) {
            motorController.moveRobot(-motorValue, -motorValue, motorValue, motorValue);
        // }
        Serial.print("Move Forward");

    }
    else if(val == 270){
        //move right
        onGreen = false;
        int startmillis = millis();
        // for (int i=0; i<time; i++) {
            motorController.moveRobot(-motorValue, motorValue, motorValue, -motorValue);
        // }
        Serial.print("Move Right");
        
    }
    else if(val == -1){
        //on green
        onGreen = true;
        motorController.moveRobot(0, 0, 0, 0);
        Serial.print("Green");
        

    }
}

void loop() {

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
    }



    Serial.print("Robot Angle: ");
    Serial.print(robotAngle);
    Serial.print(" Ball Distance: ");
    Serial.print(ballDistance);
    Serial.print(" Ball Angle: ");
    Serial.print(ballAngle);
    Serial.print(" Net Angle: ");
    Serial.print(netAngle);
    // Serial.print(" Green Direction: ");
    
    // avoidWhite(speed);
    // if(onGreen = true){
        pointNorth(robotAngle);
        behindBall(ballAngle, speed);
    // }
    // Serial.print(colourSensor.calculateDirection());
    // Serial.print(colourSensor.moveDir());
    // delay(10);
    Serial.println("");
}
