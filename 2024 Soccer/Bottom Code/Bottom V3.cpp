#include "motorControlV3.h"
#include <RunningMedian.h>

const float pi = PI;



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
void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);
    timeZero = millis();

    motorController.initMotors();
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

int angleValue;
int pKRobotAngle = 1.00, iKRobotAngle = 0.0, dKRobotAngle = 0.0;
int robotDesiredAngle = 0;
int robotAngleError = 0;
int pastRobotAngleError;
int iRobotAngleError;
int dRobotAngleError;

boolean isMovingCounterClockwise = true; 
// Runs the movementSineFunction keeping the ball in front with PID controller
// Desired position can be changed into a parameter but only if you don't want
// the ball in front of the bot
void loop() {
        if(Serial2.available() > 0){
        information = Serial2.read();
        switch (inputType) {
        case 0:
            inputType++;
            break;
        case 1:
            robotAngle = information;
            inputType++;
            break;
        case 2:
            currentBallAngleDegrees = information * 360/12;
            inputType++;
            break;
        case 3:
            ballAngle = information;
            inputType++;
            break;
        case 4:
            netAngle = information;
            inputType = 0;
            break;
        }
    }
    else {
        // Serial.println("N/A");
    }
    // Serial.print("angle: ");
    // Serial.print(robotAngle);
    // Serial.print(" ball distance: ");
    // Serial.print(ballDistance);
    // Serial.print(" ball angle: ");
    Serial.println(ballAngle);
    // Serial.print(" net angle: ");
    // Serial.println(netAngle);

    ballAngles.add(ballAngle * 360/12);
    currentBallAngleDegrees = ballAngles.getMedian();
    pastBallAngleError = currentBallAngleError;
    currentBallAngleError = calculateAngleError(desiredBallAngleDegrees, currentBallAngleDegrees);

    //setting current and past time for integration and differenciation
    pastMillis = currentMillis;
    currentMillis = millis() - timeZero;

    //calculating integral
    ballAngleErrorSum += currentBallAngleError * (currentMillis - pastMillis);

    //calculating derivative
    ballAngleErrorChange = (currentBallAngleError - pastBallAngleError) / (currentMillis - pastMillis);
    speed = 200;
    
    if(currentBallAngleDegrees == 0) {
        motorValues[0] = -255;
        motorValues[1] = -255;
        motorValues[2] = 255;
        motorValues[3] = 255;
    }
    else {
        if(currentBallAngleDegrees > 180) isMovingCounterClockwise = true;
        else isMovingCounterClockwise = false;
        for(int i = 0; i < 4; i++) {
            motorValues[i] = motorController.movementSineFunction(i+1, currentBallAngleDegrees, isMovingCounterClockwise, speed);
            Serial.print(motorValues[i]);
            Serial.print(" ");
            // Serial.print(currentBallAngleDegrees);
            // Serial.print(" ");
            // Serial.print(isMovingCounterClockwise);
            // Serial.print(" ");
            // Serial.println(speed);
        }
    }
    

    pastRobotAngleError = robotAngleError;
    robotAngleError = calculateAngleError(robotDesiredAngle, robotAngle);

    pastMillis = currentMillis;
    currentMillis = millis() - timeZero;
    iRobotAngleError += robotAngleError * (currentMillis - pastMillis);
    dRobotAngleError = (robotAngleError - pastRobotAngleError)/(currentMillis - pastMillis);
    // motorValue = pK*angleError;
    for(int i = 0; i < 4; i++) {
        motorValues[i] += pKRobotAngle*robotAngleError + iKRobotAngle*iRobotAngleError + dKRobotAngle*dRobotAngleError;
    }  
    Serial.println("");
    motorController.moveRobot(motorValues[0], motorValues[1], motorValues[2], motorValues[3]);
    // motorController.moveRobot(speed, speed, -1 * speed, -1 * speed);

}
