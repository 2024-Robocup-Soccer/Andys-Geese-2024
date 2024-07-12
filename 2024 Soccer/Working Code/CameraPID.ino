//bottom

#include "motorControlV3.h"

Motor motorController;

//types include 1 (robot angle), 2 (ball distance), 3 (ball angle), 4 (camera)
int unpackData(int value, int type) {
    int info = -1;
    if(type == 1) {
        info = map(value, 1, 250, -180, 180);
    }
    //not done
    else if(type == 2) {
        info = value;
    }
    else if(type == 3) {
        info = map(value, 1, 250, -180, 180);
    }
    else if(type == 4) {
        info = map(value, 0, 250, -50, 50);
    }
    return info;
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




int timeZero;
void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);
    timeZero = millis();

    motorController.initMotors();
}

int angleValue;
int pK = 2.0, iK = 0.2, dK = 1.0;
int desiredAngle = 0;
int angleError = 0;
int pastAngleError;
int iAngleError;
int dAngleError;

int motorValue;

int currentMillis = timeZero;
int pastMillis;
int inputType = 0;
int information;
int robotAngle, ballDistance, ballAngle, netAngle;
void loop() {
    if(Serial2.available() > 0) {
        information = Serial2.read();
        switch (inputType) {
        case 0:
            if(information == 255) inputType++;
            break;
        case 1:
            robotAngle = unpackData(information, 1);
            inputType++;
            break;
        case 2:
            ballDistance = unpackData(information,2);
            inputType++;
            break;
        case 3:
            ballAngle = unpackData(information,3);
            inputType++;
            break;
        case 4:
            netAngle = unpackData(information,4);
            inputType = 0;
            break;
        }
    }
    angleValue = netAngle;
    pastAngleError = angleError;
    angleError = calculateAngleError(desiredAngle, angleValue);

    pastMillis = currentMillis;
    currentMillis = millis() - timeZero;
    iAngleError += angleError * (currentMillis - pastMillis);
    dAngleError = (angleError - pastAngleError)/(currentMillis - pastMillis);
    // motorValue = pK*angleError;
    motorValue = pK*angleError + iK*iAngleError + dK*dAngleError;

    motorController.moveRobot(motorValue, motorValue, motorValue, motorValue);

    Serial.print("Angle: ");
    Serial.print(angleValue);
    Serial.print(" Angle Error: ");
    Serial.print(angleError);
    Serial.print(" Motor Value: ");
    Serial.println(motorValue);

    // Serial.print(robotAngle);
    // Serial.print(" ");
    // Serial.print(ballDistance);
    // Serial.print(" ");
    // Serial.print(ballAngle);
    // Serial.print(" ");
    // Serial.println(netAngle);

}



















