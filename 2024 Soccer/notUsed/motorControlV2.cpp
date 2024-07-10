#include <Arduino.h>
#include "motorControlV2.h"

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

void Motor::moveRobot(int dir1, int dir2, int dir3, int dir4, int speed, char move) {
  int s1, s2, s3, s4;
  if(move == 'f') {
    s1 = speed * 1.28;
    s2 = speed * 1.28;
    s3 -= speed * 0.04;
    s4 -= speed * 0.04;
  }

  else if(move == 'b') {
    s1 = speed;
    s2 = speed;
    s3 -= speed * 0.04;
    s4 -= speed * 0.04;
  }

  else if(move == 'r') {
    s1 -= speed * 0.08;
    s2 = speed;
    s3 = speed;
    s4 = speed;
  }
  else if(move == 'x') {
    s1 = speed*0.5;
    s2 = speed*0.5;
    s3 = speed*0.5;
    s4 = speed*0.5;
  }
  else if(move == 'y') {
    s1 = speed*0.5;
    s2 = speed*0.5;
    s3 = speed*0.5;
    s4 = speed*0.5;
  }
  else if(move == 'r') {
    s1 -= speed * 0.08;
    s2 = speed;
    s3 = speed;
    s4 = speed;
  }

  else {
    s1 = speed;
    s2 = speed;
    s3 = speed;
    s4 = speed;

  }

  
  setMotor(0, dir1, s1);
  setMotor(1, dir2, s2);
  setMotor(2, dir3, s3);
  setMotor(3, dir4, s4);
}



void Motor::forward(int speed) {
  moveRobot(0, 0, 1, 1, speed, 'f');
  
}

void Motor::backward(int speed) {
  moveRobot(1, 1, 0, 0, speed, 'b');
}

void Motor::leftTurn(int speed) {
  moveRobot(1, 1, 1, 1, speed, 'x');
}

void Motor::rightTurn(int speed) {
  moveRobot(0, 0, 0, 0, speed, 'y');
}
void Motor::right(int speed) {
  moveRobot(0, 1, 1, 0, speed, 'r');
}

void Motor::left(int speed) {
  moveRobot(1, 0, 0, 1, speed, 'l');
}

void Motor::stop() {
  moveRobot(0, 0, 0, 0, 0, 's');
}

