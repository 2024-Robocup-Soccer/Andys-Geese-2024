#include <Arduino.h>
#include <SPI.h>


void setup() {
    Serial.begin(9600);
    Serial7.begin(9600);
}

int compassAngle = 0;
int distance = 0;
int ballAngle = 0;
int val = 1;

void loop() {
    
    Serial7.write(255);
    Serial7.write(compassAngle);
    Serial7.write(distance);
    Serial7.write(ballAngle);
    // 0 = no info from the camera
    // 1-250 = angle value of goal relative to robot
    // 500 = no goal found
    if (val>0){ Serial7.write(val);}
    else{Serial7.write(-1);}//No Info from Camera
}