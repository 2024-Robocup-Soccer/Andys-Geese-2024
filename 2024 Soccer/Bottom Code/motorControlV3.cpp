
#include <Arduino.h>
#include "motorControlV3.h"

const int DIR_PINS[] = { 3, 1, 5, 37 };
const int PWM_PINS[] = { 2, 0, 4, 36 };


void Motor::initMotors() {
  for (int i = 0; i < 4; i++) {
    pinMode(DIR_PINS[i], OUTPUT);
    pinMode(PWM_PINS[i], OUTPUT);
  }
}
void Motor::setMotor(int motor, int dir, int pwm) {
  digitalWrite(DIR_PINS[motor], dir);
  analogWrite(PWM_PINS[motor], pwm);
}

void Motor::moveRobot(int speed1, int speed2, int speed3, int speed4) {
    if(speed1 > 0) {
        setMotor(0, 1, speed1);
    }
    else if(speed1 < 0) {
        setMotor(0, 0, speed1*-1);
    }
    else {
        setMotor(0, 0, 0);
    }

    if(speed2 > 0) {
        setMotor(1, 1, speed2);
    }
    else if(speed2 < 0) {
        setMotor(1, 0, speed2*-1);
    }
    else {
        setMotor(1, 0, 0);
    }

    if(speed3 > 0) {
        setMotor(2, 1, speed3);
    }
    else if(speed3 < 0) {
        setMotor(2, 0, speed3*-1);
    }
    else {
        setMotor(2, 0, 0);
    }

    if(speed4 > 0) {
        setMotor(3, 1, speed4);
    }
    else if(speed4 < 0) {
        setMotor(3, 0, speed4*-1);
    }
    else {
        setMotor(3, 0, 0);
    }

}

// Returns motor value according to trig function associated with the ball angle.
int movementSineFunction(int motor, float ballAngleDegrees, boolean isCounter, int amplitude) {
    float motorValue;
    float ballAngle = pi/180 * ballAngleDegrees;
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



    
