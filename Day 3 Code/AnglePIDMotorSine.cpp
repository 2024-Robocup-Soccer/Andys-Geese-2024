#include <Arduino.h>
#include "motorControlV3.h"
#include "RunningMedian.h"

Motor motorController;

//information from top
float robotAngle, ballDistance, ballAngle, netAngle;
//prev info from top
float pastNetAng;
//count if camera does not see
int cameraSeesCount;
//robot on green
bool onGreen = false;

//overall speed
int overallSpeed = 80;

//-------------------------PID-----------------------------------
//time for PID
int millisZero, currentMillis, pastMillis;
double changeTime;
//final motor values
int motorValues[4];


//MOVEMENT PID
//movement pid constants --- CHANGE TO MAKE GOOD MOVEMENT (generally keep all between 0.00 - 1.00)
float kPMovement[4] = {0.05, 0.05, 0.05, 0.05}, kIMovement[4] = {0.000, 0.000, 0.000, 0.000}, kDMovement[4] = {0.002, 0.002, 0.002, 0.002}; //0.005
//previous ball error values
float pastBallError = 0.0;
//movmement error sum 
float iMovementError = 0.0;
//current ball error
float ballError = 0.0;
//change of error for all motors
float dMovementError = 0.0;

//ANGLE PID 
//angle pid constants --- CHANGE TO MAKE GOOD MOVEMENT (generally keep all between 0.00 - 1.00)
float kPAngle = 0.9, kIAngle = 0.0, kDAngle = 0.000;
//previous ball error value
float pastAngleError = 0;
//angle error sum
float iAngleError = 0;
//previous error type
bool seesCamera;

//------------------------------------------------------------
//MOVEMENT
bool isRotatingClockwise;
//Switch between rotating and moving each loop
bool isRotating = false;


//COMMUNICATION
byte information[5];

const int BUTTON_PIN = 13;

//Allows the top and bottom boards to recieve info properly
//Needs to be run at top of communication in loop
void sync() {
    byte check[5];
    int shift=0;
    if(Serial2.available() > 4) {
        Serial2.readBytes(check, 5);
    }

    for (int i=1; i<6; i++) {
        if (check[i] == 255) {
            shift += i;
        }
        else {
            break;

        }
    }


    for (int i=0; i<shift; i++) {
        Serial2.read();
    }

}


//if type == 1 (robot angle), type == 2 (ir ball), type == 3 (colour +/- 90)
//Finds the error when you are using an angle
//Makes up from the edge case from 0 - 360
float calculateAngleError(float desiredDegrees, float actualDegrees, int type) {
    float error = desiredDegrees - actualDegrees;

    switch(type) {
    case 1:
        if (error > 180) {
            error -= 360;
        } 
        else if (error < -180) {
            error += 360;
        }
        break;
    case 2:
        if (error > 180) {
            error -= 360;
        } 
        else if (error < -180) {
            error += 360;
        }
        break;
    }

    return error;
}

//if type == 1 (robot angle), type == 2 (ir ball), type (colour +/- 90) with isColourChangePositive
//Finds the error when you are using an angle
//Makes up from the edge case from 0 - 360
// float calculateAngleError(float desiredDegrees, float actualDegrees, int type, bool isColourChangePositive) {
//     float error = desiredDegrees - actualDegrees;

//     if() {
//     }

//     return error;
// }

int unpackData(int value, int type) {
    int info = -1;
    if(type == 1) {
        info = map(value, 0, 250, -180, 180);
    }
    //not done
    else if(type == 2) {
        info = value;
    }
    else if(type == 3) {
        info = map(value, 0, 250, 0, 359);
    }
    else if(type == 4) {
        if(value != 253) {
            pastNetAng = netAngle;
            value = 0;
            cameraSeesCount = 0;
        }
        else if (value == 0) {
            value = pastNetAng;
            cameraSeesCount += 1;
        }

        info = value;//map(value, 1, 250, -50, 50);
    }
    return info;
}

//Full PID code for movement
//motor is the motor 1...4 that is speed is being set, isMovingClockwise tells if you want to move clockwise or counter around the ball
// speed is the max speed, or amplitude of the sine wave, ballAngle is the direction in which the ball is facing from the bot 

float movementPID(int motor, bool isMovingClockwise, int speed, float ballAngle) {
    float motorValue = motorController.movementSineFunction(motor, ballAngle, isMovingClockwise, speed);

    // Serial.print("Sine calc: ");
    // Serial.println(motorValue);

    // motorValue *= kPMovement[motor] * ballError + kIMovement[motor] * iMovementError + kDMovement[motor] * dMovementError;

    // Serial.print("Motor + PID: ");
    // Serial.println(motorValue);

    //SHOULD NOT BE USED FOR NOW
    // if(motorValue > 0 && motorValue < 30) {
    //     motorValue += 30;
    // }
    // else if(motorValue < 0 && motorValue > -30) {
    //     motorValue -= 30;
    // }

    return motorValue;
}

//This function is a "child" of movement sine but creates a vector of movement normal to line if it 
//is seen. The parameters are the same as movement sine with the addition of colourDirection which
//is -1.0 if line is not seen and 0.0-360.0 in the direction of the line
//Outputs -1 if not working 
int movementSineColour(int motor, float ballAngleDegrees, bool isCounter, float amplitude, float colourDirection) {
    int motorValue = -1;
    motorValue = motorController.movementSineFunction(motor, ballAngleDegrees, isCounter, amplitude);

    if(calculateAngleError() &&  )
    return motorValue;
}

//camera == true means that it sees the camera 
//returns the motor values to allow the robot to be in middle of net (if net is seen), or face forward
//float angle is the angle of the net (-50 - 50) or bot angle (-180 - 180)
float anglePID(float angle, bool camera) {
    float angleError;
    //The angle you wish to face
    float desiredAngle = 0;
    if(camera) {
        angleError = desiredAngle - angle;
    }
    else {
        angleError = calculateAngleError(desiredAngle, angle, 1);
    }

    //Add angle error to sum
    // iAngleError += angleError * (changeTime/100.0);
    // Serial.print("ANGLE ERROR: ");
    // Serial.println(angleError);
    // Serial.print("I ERROR: ");
    // Serial.println(iAngleError);
    float pAngleValue = kPAngle * angleError;
    // Serial.print("pAngleValue: ");
    // Serial.println(pAngleValue);
    // float iAngleValue = kIAngle * iAngleError;
    // // Serial.print("iAngleValue: ");
    // // Serial.println(iAngleValue);
    // float dAngleValue = kDAngle * ((angleError - pastAngleError)/(changeTime*10000000.0));
    // Serial.print("dAValue: ");
    // Serial.println(dAngleValue);
    float pidValue = pAngleValue;
    // Serial.print("PID VALUE: ");
    // Serial.println(pidValue);
    return pidValue;
}

void setup() {
    Serial2.begin(20000000); //115200 20000000
    sync();
    pinMode(BUTTON_PIN, INPUT);
    // colourSensor.init();
    motorController.init();
    millisZero = micros();
    currentMillis = millisZero; 
    // for (int i=0; i<1000; i++) { //100
    //     sync();  
    // }
}

int loops = 0;

void loop() {
    //communication
    // loops++;
    // if(loops > 2) {
    //     return;
    // }

    if (currentMillis % 100==0) {
        sync();
    }
    if(Serial2.available() > 4) {
        Serial2.readBytes(information, 5);
    }

    robotAngle = unpackData(information[1], 1);
    ballDistance = unpackData(information[2], 2);
    ballAngle = unpackData(information[3], 3);
    netAngle = unpackData(information[4], 4);

    if (cameraSeesCount >= 10) {
        seesCamera = false;
    }
    else {
        seesCamera = true;
    }


    pastMillis = currentMillis;
    currentMillis = micros();
    if(ballAngle > 5) {
        isRotatingClockwise = false;
    }
    else {
        isRotatingClockwise = true;
    }

    // Serial.print("D Error: ");
    // Serial.println(dMovementError);
    // Serial.print("Ball Error - past Error: ");
    // Serial.println(ballError - pastBallError);
    // Serial.print("Ball Error");s
    // Serial.println(ballError);
    // Serial.print("change time: ");
    // Serial.println(changeTime);
    if(digitalRead(BUTTON_PIN) == HIGH) {
     
        for(int i = 0; i < 4; i++) {
            motorValues[i] = anglePID(netAngle, true) + motorController.movementSineFunction(i+1, ballAngle, false, 100);
            // Serial.print(" Motor ");
            // Serial.print(i+1);
            // Serial.print(": ");
            // Serial.print(motorValues[i]);
            // Serial.print(" ");
        }
        motorController.moveRobot(motorValues[0], motorValues[1], motorValues[2], motorValues[3]);
    }
    Serial.println(netAngle);

}   
