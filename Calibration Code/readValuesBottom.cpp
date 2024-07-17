#include <Arduino.h>
#include <SPI.h>

int inputType = 0;
int ballAngle =- 1, netAngle, ballDistance, robotAngle, pastNetAng;
float desiredBallAngleDegrees = 0.00, currentBallAngleDegrees = 0.00;

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

    if (shift > 0) {
        shift -= 1;
    }

    for (int i=0; i<shift; i++) {
        Serial2.read();
    }

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


void setup() {
    Serial.begin(9600);
    Serial2.begin(20000000);
    Serial.println("Geood");
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

    Serial.print("angle: ");
    Serial.print(robotAngle);
    Serial.print(" ball distance: ");
    Serial.print(ballDistance);
    Serial.print(" ball angle: ");
    Serial.print(ballAngle);
    Serial.print(" net angle: ");
    Serial.println(netAngle);

}
