#include "motorControlV3.h"
#include "colorSensorV3.h"


Motor motorController;

//information from top
float robotAngle, ballDistance, ballAngle, netAngle;
//Running Median of ball values
// RunningMedian ballAngleMedian = RunningMedian(5);
//prev info from top
float pastNetAng;



//-------------------------PID-----------------------------------
//time for PID
int millisZero, currentMillis, pastMillis;
double changeTime;
//final motor values
int motorValues[4];


//MOVEMENT PID
//movement pid constants --- CHANGE TO MAKE GOOD MOVEMENT (generally keep all between 0.00 - 1.00)
float kPMovement[4] = {0.06, 0.04, 0.08, 0.06}, kIMovement[4] = {0.002, 0.002, 0.002, 0.002}, kDMovement[4] = {0.005, 0.005, 0.009, 0.009}; //0.005
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
float kPAngle = 0.002, kIAngle = 0.00002, kDAngle = 0.0;
//previous ball error value
float pastAngleError = 0;
//angle error sum
float iAngleError = 0;
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
float calculateAngleError(float desiredDegrees, float actualDegrees, int type) {
    float error = desiredDegrees - actualDegrees;

    switch(type) {
    //this is the case where we are using the camera pid which is the normal case
    //zero is straight in front and counter-clockwise is positive
    case 1:
        if (error > 180) {
            error -= 360;
        } 
        else if (error < -180) {
            error += 360;
        }
    //this is the other case when the bot can no longer see the net
    //it now needs to find the error of robot angle which follows same
    //pattern as net, counter-clockwise (+) to 0 to clockwise (-)
    case 2:
        error *= (360/12);
        if (error > 180) {
            error -= 360;
        } 
        else if (error < -180) {
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
        info = map(value, 0, 250, 0, 11);
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

float movementPID(int motor, bool isMovingClockwise, int speed, float ballAngle) {
    float motorValue = motorController.movementSineFunction(motor, ballAngle, isMovingClockwise, speed);

    // Serial.print("Sine calc: ");
    // Serial.println(motorValue);

    motorValue *= kPMovement[motor] * ballError + kIMovement[motor] * iMovementError + kDMovement[motor] * dMovementError;

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

//camera == true means that it sees the camera 
//returns the motor values to allow the robot to be in middle of net (if net is seen), or face forward
//float angle is the angle of the net (-50 - 50) or bot angle (-180 - 180)
float anglePID(float angle, bool camera, int speed) {
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
    iAngleError += angleError * (changeTime/100000);
    Serial.print("ANGLE ERROR: ");
    Serial.println(angleError);
    Serial.print("I ERROR: ");
    Serial.println(iAngleError);
    float pAngleValue = kPAngle * angleError;
    Serial.print("pAngleValue: ");
    Serial.println(pAngleValue);
    float iAngleValue = kIAngle * iAngleError;
    Serial.print("iAngleValue: ");
    Serial.println(iAngleValue);
    float dAngleValue = kDAngle * ((angleError - pastAngleError)/changeTime);
    Serial.print("dAValue: ");
    Serial.println(dAngleValue);
    float pidValue = pAngleValue + iAngleValue + dAngleValue;

    return pidValue * speed;
}

// int rotationPID(int motor, )

void setup() {
    // Serial.begin(20000000);
    Serial2.begin(20000000);

    // colourSensor.init();
    motorController.init();
    millisZero = micros();
    currentMillis = millisZero;
}

int loops = 0;


void loop() {
    //communication
    // loops++;
    // if(loops > 2) {
    //     return;
    // }
    sync();

    if(Serial2.available() > 4) {
        Serial2.readBytes(information, 5);
    }

    robotAngle = unpackData(information[1], 1);
    ballDistance = unpackData(information[2], 2);
    ballAngle = unpackData(information[3], 3);
    netAngle = unpackData(information[4], 4);
    
    // Serial.println(ballAngle);

    //movement
    pastMillis = currentMillis;
    currentMillis = micros();
    if(ballAngle > 5) {
        isRotatingClockwise = false;
    }
    else {
        isRotatingClockwise = true;
    }

    ballError = calculateAngleError(0, ballAngle, 2);
    changeTime = (double) (currentMillis - pastMillis) / (double) 1000000;
    // Serial.print("Change Time: ");
    // Serial.println(changeTime);
    

    iMovementError += ballError * changeTime;
    // Serial.print("I Error: ");
    // Serial.println(iMovementError);

    dMovementError = (double) (ballError - pastBallError)/changeTime;
    // Serial.print("D Error: ");
    // Serial.println(dMovementError);
    // Serial.print("Ball Error - past Error: ");
    // Serial.println(ballError - pastBallError);
    // Serial.print("Ball Error");
    // Serial.println(ballError);
    // Serial.print("change time: ");
    // Serial.println(changeTime);

    for(int i = 0; i < 4; i++) {
        motorValues[i] = anglePID(robotAngle, false, 1); //movementPID(i+1, isRotatingClockwise, 100, ballAngle)* (3/4) + 
    }

    // motorController.moveRobot(motorValues[0], motorValues[1], motorValues[2], motorValues[3]);
    Serial.println(robotAngle);
    // motorController.moveRobot(100, 100, -100, -100);
    // for(int i = 0; i < 4; i++) {
    //     Serial.print(" ");
    //     Serial.print(i);
    //     Serial.print(": ");
    //     Serial.print(motorValues[i]);
    // }
    // Serial.println();

    // pastBallError = ballError;
    // delay(100); // ball Error refreshes too fast to see without this
}   
