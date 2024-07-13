#include "motorControlV3.h"
#include <RunningMedian.h>
#include <SPI.h>
#include <Arduino.h>

const float pi = PI;

int movementSineFunction(int motor, float ballAngleDegrees, boolean isCounter, int amplitude) {
    float motorValue;
    float ballAngle = PI/180 * ballAngleDegrees;
    switch (motor) {
        case 1:
            motorValue = amplitude * sin(ballAngle + PI / 4);
            // motorValue = amplitude * sin(ballAngle);
            break;
        case 2:
            motorValue = amplitude * sin(ballAngle - PI / 4);
            // motorValue = amplitude * sin(ballAngle - PI/2);
            break;
        case 3:
            motorValue = amplitude * sin(ballAngle - 3 * PI / 4);
            // motorValue = amplitude * -1 * sin(ballAngle - PI/2);
            break;
        case 4:
            motorValue = amplitude * sin(ballAngle + 3 * PI / 4);
            // motorValue = amplitude * -1 * sin(ballAngle - PI/2);
            break;
        default: motorValue = 0;
    }

    if (isCounter) {
        motorValue *= -1;
    }

    return motorValue;
}



int calculateAngleError(int desiredDegrees, int actualDegrees) {
    int error = desiredDegrees - actualDegrees;

    if (error > 180) {
        error -= 360;
    } else if (error < -180) {
        error += 360;
    }

    return error;
}

int timeZero, currentMillis, pastMillis;
float ballAngleErrorSum = 0.00, currentBallAngleError = 0.00, pastBallAngleError, ballAngleErrorChange;

Motor motorController;


void sync() {
    byte check[5];
    int shift=0;
    if(Serial2.available() > 4) {
        Serial2.readBytes(check, 5);
    }

    for (int i=0; i<5; i++) {
        if (check[i] == 255) {
            shift = i;
        }
    }

    if (shift > 0) {
        shift -= 1;
    }

    for (int i=0; i<shift; i++) {
        Serial2.read();
    }

}


void setup() {
    Serial.begin(9600);
    Serial2.begin(20000000);

    timeZero = millis();

    motorController.initMotors();
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

//variables needed for PID
float kPBall[4] = {1.00, 1.00, 1.00, 1.00};
float kIBall[4] = {1.00, 1.00, 1.00, 1.00};
float kDBall[4] = {1.00, 1.00, 1.00, 1.00};

float desiredBallAngleDegrees = 0.00, currentBallAngleDegrees = 0.00;

int motorValues[4];

int information;
int i =0;
boolean calibrated = false;
int ballAngle, netAngle, ballDistance, robotAngle;
int inputType = 0;

RunningMedian ballAngles = RunningMedian(5);
int speed;


//Orbit PID
int angleValue;
int pKRobotAngle = 1.00, iKRobotAngle = 0.0, dKRobotAngle = 0.0;
int robotDesiredAngle = 0;
int robotAngleError = 0;
int pastRobotAngleError;
int iRobotAngleError;
int dRobotAngleError;


//CAMERA PID
int angleValue2;
int pK = 2.0, iK = 0.2, dK = 1.0;
int desiredAngle2 = 0;
int angleError2 = 0;
int pastAngleError2;
int iAngleError2;
int dAngleError2;
int motorValue2;
int currentMillis2 = timeZero;
int pastMillis2;

boolean isMovingCounterClockwise = true; 
// Runs the movementSineFunction keeping the ball in front with PID controller
// Desired position can be changed into a parameter but only if you don't want
// the ball in front of the bot
void loop() {
    // if(Serial2.available() > 0) {
    //     information = Serial2.read();
    //     switch (inputType) {
    //     case 0:
    //         if(information == 255) {inputType++;}
    //         Serial.println("Case 0");
    //         break;
    //     case 1:
    //         robotAngle = unpackData(information, 1);
    //         Serial.println("Case 1");
    //         inputType++;
    //         break;
    //     case 2:
    //         ballDistance = unpackData(information,2);
    //         Serial.println("Case 2");
    //         inputType++;
    //         break;
    //     case 3:
    //         ballAngle = unpackData(information,3);
    //         Serial.println("Case 3");
    //         inputType++;
    //         break;
    //     case 4:
    //         netAngle = unpackData(information,4);
    //         Serial.println("Case 4");
    //         inputType = 0;
    //         break;
    //     }
    // }

    // Serial.print("Robot Angle: ");
    // Serial.print(robotAngle);
    // Serial.print(" Ball Distance: ");
    // Serial.print(ballDistance);
    // Serial.print(" Ball Angle: ");
    // Serial.print(ballAngle);
    // Serial.print(" Net Angle: ");
    // Serial.print(netAngle);

    // ballAngles.add(ballAngle * 360/12);
    // currentBallAngleDegrees = ballAngles.getMedian();
    // pastBallAngleError = currentBallAngleError;
    // currentBallAngleError = calculateAngleError(desiredBallAngleDegrees, currentBallAngleDegrees);

    // //setting current and past time for integration and differenciation
    // pastMillis = currentMillis;
    // currentMillis = millis() - timeZero;

    // //calculating integral
    // ballAngleErrorSum += currentBallAngleError * (currentMillis - pastMillis);

    // //calculating derivative
    // ballAngleErrorChange = (currentBallAngleError - pastBallAngleError) / (currentMillis - pastMillis);
    // speed = 200;
    

    // angleValue2 = netAngle;
    // pastAngleError2 = angleError2;
    // angleError2 = calculateAngleError(desiredAngle2, angleValue2);

    // pastMillis2 = currentMillis2;
    // currentMillis2 = millis() - timeZero;
    // iAngleError2 += angleError2* (currentMillis2 - pastMillis2);
    // dAngleError2 = (angleError2 - pastAngleError2)/(currentMillis2 - pastMillis2);
    // // motorValue = pK*angleError;
    // motorValue2 = pK*angleError2 + iK*iAngleError2 + dK*dAngleError2;

    // if(currentBallAngleDegrees == 0) {
    //     motorValues[0] = -255;
    //     motorValues[1] = -255;
    //     motorValues[2] = 255;
    //     motorValues[3] = 255;
    // }
    // else {
    //     if(currentBallAngleDegrees > 180) isMovingCounterClockwise = true;
    //     else isMovingCounterClockwise = false;
    //     for(int i = 0; i < 4; i++) {
    //         motorValues[i] = movementSineFunction(i+1, currentBallAngleDegrees, isMovingCounterClockwise, speed);
           
    //         // Serial.print(currentBallAngleDegrees);
    //         // Serial.print(" ");
    //         // Serial.print(isMovingCounterClockwise);
    //         // Serial.print(" ");
    //         // Serial.println(speed);
    //     }
    // }
    
    // pastRobotAngleError = robotAngleError;
    // robotAngleError = calculateAngleError(robotDesiredAngle, robotAngle);

    // pastMillis = currentMillis;
    // currentMillis = millis() - timeZero;
    // iRobotAngleError += robotAngleError * (currentMillis - pastMillis);
    // dRobotAngleError = (robotAngleError - pastRobotAngleError)/(currentMillis - pastMillis);
    // // motorValue = pK*angleError;
    // for(int i = 0; i < 4; i++) {
    //     motorValues[i] += pKRobotAngle*robotAngleError + iKRobotAngle*iRobotAngleError + dKRobotAngle*dRobotAngleError;
    // }  
    // Serial.println("");
    
    // //motorController.moveRobot(motorValue2, motorValue2, motorValue2, motorValue2);

    // int newMotorValues1, newMotorValues2, newMotorValues3, newMotorValues4;
    
    //     newMotorValues1 = (motorValues[0] + motorValue2)/2;
    //     newMotorValues2 = (motorValues[1] + motorValue2)/2;
    //     newMotorValues3 = (motorValues[2] + motorValue2)/2;
    //     newMotorValues4 = (motorValues[3] + motorValue2)/2;
        
    //     // motorController.moveRobot(motorValues[0], motorValues[1], motorValues[2], motorValues[3]);

    // // if(ballAngle = 0){
    // //     motorController.moveRobot(motorValue2, motorValue2, motorValue2, motorValue2);
    // //     //  Serial.print(motorValue2);
    // //     //     Serial.print(" ");
    // // }
    // // else{
    // //        motorController.moveRobot(motorValues[0], motorValues[1], motorValues[2], motorValues[3]);
    // //         for (int i =0; i<4;i++){
    // //             // Serial.print(motorValues[i]);
    // //             // Serial.print(" ");
    // //         }      
    // // }
    // // motorController.moveRobot(newMotorValue1, newMotorValues2, newMotorValues3, newMotorValues4);
    sync();

    byte hello[5];
    if(Serial2.available() > 4) {
        Serial2.readBytes(hello, 5);
        for(int i = 0; i < 5; i++) {
            Serial.print(hello[i]);
            Serial.print(" ");
        }
        Serial.println();
    }
}
