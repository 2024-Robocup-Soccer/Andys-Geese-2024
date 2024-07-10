#ifndef MOTOR_CONTROL_V3_H
#define MOTOR_CONTROL_V3_H

class Motor {
public:
  static void initMotors();
  static void setMotor(int motor, int dir, int pwm);
  static void moveRobot(int speed1, int speed2, int speed3, int speed4);                                
};

#endif
