#include <Arduino.h>

#include <RunningMedian.h>
#include <Math.h>
#include "motorControlV2.h"
#include "irSensorV3.h"
#include <Adafruit_BNO08x.h>

int speed = 100;

bool isForward = false;


IRSensor irSensor;
Motor motor;

void setup()
{
    Serial.begin(9600);
    Serial2.begin(9600);
    // Serial8.begin(9600);

    // pinMode(A0, OUTPUT);
    // pinMode(A1, OUTPUT);
    // pinMode(A2, OUTPUT);
    // pinMode(A3, OUTPUT);
    // pinMode(A4, OUTPUT);

    motor.initMotors();
}
int instructions;

void loop()
{
//     digitalWrite(A0, HIGH);
//     digitalWrite(A1, LOW);
//     digitalWrite(A2, HIGH);
//     digitalWrite(A3, HIGH);
//     digitalWrite(A4, LOW);
//     digitalWrite(A6, LOW);
//     int reading = analogRead(A5);
    if(Serial2.available() > 0) {
        instructions = Serial2.read();
    }
    /*
    1 Forward
    2 Left Strafe
    3 Right Strafe
    4 Backwards
    5 Left Turn
    6 Right Turn
    7 Stop
    */
    Serial.println(instructions);
    if(instructions == 1) {
        motor.forward(speed);
    }
    else if(instructions == 2) {
        motor.left(speed);
    }
    else if(instructions == 3) {
        motor.right(speed);
    }
    else if(instructions == 4) {
        motor.backward(speed);
    }
    else if(instructions == 5) {
        motor.leftTurn(speed);
    }
    else if(instructions == 6) {
        motor.rightTurn(speed);
    }
    else if(instructions == 7) {
        motor.stop();
    }

    delay(10);
}
