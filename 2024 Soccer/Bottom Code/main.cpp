#include "motorControlV3.h"
#include "colorSensorV3.h"


Motor motorController;

//information from top
float robotAngle, ballDistance, ballAngle, netAngle;
//prev info from top
float pastNetAng;



//-------------------------PID-----------------------------------
//time for PID
int millisZero, currentMillis, pastMillis;
//final motor values
int motorValues[4];

//MOVEMENT PID
//movement pid constants --- CHANGE TO MAKE GOOD MOVEMENT (generally keep all between 0.00 - 1.00)
float kPMovement[4] = {0.8, 0.8, 0.8, 0.8}, kIMovement[4] = {0.2, 0.2, 0.2, 0.2}, kDMovement[4] = {0.05, 0.05, 0.05, 0.05};
//previous ball error values
int pastBallErrors[4] = {0, 0, 0, 0};
//movmement error sum 
int iMovementErrors[4];

//ANGLE PID 
//angle pid constants --- CHANGE TO MAKE GOOD MOVEMENT (generally keep all between 0.00 - 1.00)
float kPAngle = 0.8, kIAngle = 0.1, kDAngle = 0.05;
//previous ball error value
int pastAngleError = 0;
//angle error sum
int iAngleError = 0;
//previous error type
bool seesCamera;

//------------------------------------------------------------
//MOVEMENT
bool isRotatingClockwise;


//COMMUNICATION
byte information[5];
//Allows the top and bottom boards to recieve info properly
//Needs to be run at top of communication in loop
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

    // if (shift > 0) {
    //     shift -= 1;
    // }

    for (int i=0; i<shift; i++) {
        Serial2.read();
    }

}

//if type == 1 (robot angle), type == 2 (ir ball)
//Finds the error when you are using an angle
//Makes up from the edge case from 0 - 360
int calculateAngleError(int desiredDegrees, int actualDegrees, int type) {
    int error = desiredDegrees - actualDegrees;

    switch(type) {
    case 1:
        if (error > 180) {
            error -= 360;
        } 
        else if (error < -180) {
            error += 360;
        }
    case 2:
        if (error > 360) {
            error -= 360;
        } 
        else if (error < 0) {
            error += 360;
        }
    }

    return error;
}

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
        info = map(value, 0, 250, 0, 360);
    }
    else if(type == 4) {
        if(value != 253) {
            pastNetAng = netAngle;
            value = 0;
        }
        else if (value == 0) {
            value = pastNetAng;
        }

        info = map(value, 1, 250, -50, 50);
    }
    return info;
}

//Full PID code for movement
//motor is the motor 1...4 that is speed is being set, isMovingClockwise tells if you want to move clockwise or counter around the ball
// speed is the max speed, or amplitude of the sine wave, ballAngle is the direction in which the ball is facing from the bot 

int movementPID(int motor, bool isMovingClockwise, int speed, float ballAngle) {
    float ballError = calculateAngleError(0, ballAngle, 1);
    
    int motorValue = motorController.movementSineFunction(motor, ballAngle, isMovingClockwise, speed);

    //Add movement error to sum
    iMovementErrors[motor] += ballError * (currentMillis - pastMillis);
    int pMovementValue = kPMovement[motor] * ballError;
    int iMovementValue = kIMovement[motor] * iMovementErrors[motor];
    int dMovementValue = kDMovement[motor] * ((ballError - pastBallErrors[motor])/(currentMillis - pastMillis));
    int pidValue = pMovementValue + iMovementValue + dMovementValue;

    motorValue *= pidValue;

    //SHOULD NOT BE USED FOR NOW
    // if(motorValue > 0 && motorValue < 30) {
    //     motorValue += 30;
    // }
    // else if(motorValue < 0 && motorValue > -30) {
    //     motorValue -= 30;
    // }

    //sets past angle errors to current errors
    pastBallErrors[motor] = ballError;
    return motorValue;
}

//camera == true means that it sees the camera 
//returns the motor values to allow the robot to be in middle of net (if net is seen), or face forward
//float angle is the angle of the net (-50 - 50) or bot angle (-180 - 180)
int anglePID(float angle, bool camera) {
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
    iAngleError += angleError * currentMillis;
    int pAngleValue = kPAngle * angleError;
    int iAngleValue = kIAngle * iAngleError;
    int dAngleValue = kDAngle * ((angleError - pastAngleError)/(currentMillis - pastMillis));
    int pidValue = pAngleValue + iAngleValue + dAngleValue;

    return pidValue;
}

// int rotationPID(int motor, )

void setup() {
    Serial.begin(20000000);
    Serial2.begin(20000000);

    // colourSensor.init();
    motorController.init();
    millisZero = millis();
    currentMillis = millisZero;
}


void loop() {
    //communication
    sync();

    if(Serial2.available() > 4) {
        Serial2.readBytes(information, 5);
    }

    robotAngle = unpackData(information[1], 1);
    ballDistance = unpackData(information[2], 2);
    ballAngle = unpackData(information[3], 3);
    netAngle = unpackData(information[4], 4);
    
    Serial.println(ballAngle);

    //movement
    pastMillis = currentMillis;
    currentMillis = millis();
    // isRotatingClockwise = true;
    for(int i = 0; i < 4; i++) {
        motorValues[i] = movementPID(i+1, false, 50, ballAngle);
    }

    motorController.moveRobot(motorValues[0], motorValues[1], motorValues[2], motorValues[3]);
    // motorController.moveRobot(100, 100, -100, -100);
    // for(int i = 0; i < 4; i++) {
    //     Serial.print(" ");
    //     Serial.print(i);
    //     Serial.print(": ");
    //     Serial.print(motorValues[i]);
    // }
    // Serial.println();
}   