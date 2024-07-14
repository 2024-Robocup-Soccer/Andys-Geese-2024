    //bottom
#include <Arduino.h>
#include "motorControlV3.h"

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

    for (int i=0; i<shift; i++) {
        Serial2.read();
    }

}

//types include 1 (robot angle), 2 (robot x), 3 (robot y), 4 (ball distance), 5 (ball angle), 6 (mis)
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
    Serial2.begin(20000000);
    timeZero = millis();

    motorController.initMotors();
}

int angleValue;
int pK = 1.5, iK = 0.5, dK = 0.5;
int desiredAngle = 0;
int angleError = 0;
int pastAngleError;
int iAngleError;
int dAngleError;

int motorValue;

int currentMillis = timeZero;
int pastMillis;

byte information[5];
int robotAngle, ballDistance, ballAngle, netAngle;
void loop() {
    sync();

    //0 == robotAngle, 1 == ballDistance, 2 == ballAngle, 3 == netAngle

    if(Serial2.available() > 4) {
        Serial2.readBytes(information, 5);
    }

    robotAngle = unpackData(information[1], 1);
    ballDistance = unpackData(information[2], 2);
    ballAngle = unpackData(information[3], 3);

    
    // netAngle = unpackData(information[4], 4);
 
    if(information[4] != 0 && information[4] != 253){
        netAngle = unpackData(information[4],4);
    }
    else if(information[4] == 253 != 0){
        netAngle = 255;
    }

    angleValue = netAngle;

    // robotAngle = information[1];
    // ballDistance = information[2];
    // ballAngle= information[3];
    // netAngle = information[4];
    pastAngleError = angleError;
    angleError = calculateAngleError(desiredAngle, angleValue);

    pastMillis = currentMillis;
    currentMillis = millis() - timeZero;
    iAngleError += angleError * (currentMillis - pastMillis);
    dAngleError = (angleError - pastAngleError)/(currentMillis - pastMillis);
    // motorValue = pK*angleError;
    motorValue = pK*angleError + iK*iAngleError + dK*dAngleError;
    if(netAngle == 255) {
        motorValue = 0;
    }
    motorController.moveRobot(motorValue, motorValue, motorValue, motorValue);

    // motorController.moveRobot(200, 200, 200, 200);
    Serial.print("Angle: ");
    Serial.print(netAngle);
    Serial.print(" Angle Error: ");
    Serial.print(angleError);
    Serial.print(" Motor Value: ");
    Serial.println(motorValue);

    
    // Serial.print("Robot Angle: ");
    // Serial.print(robotAngle);
    // Serial.print(" Ball Distance: ");
    // Serial.print(ballDistance);
    // Serial.print(" Ball Angle: ");
    // Serial.print(ballAngle);
    // Serial.print(" Net Angle: ");
    // Serial.println(netAngle);

    // for(int i=0; i<5; i++) {
    //     Serial.print(information[i]);
    // }
  


}


















