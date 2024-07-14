#ifndef MOTOR_CONTROL_V3_H
#define MOTOR_CONTROL_V3_H

class Motor {
public:
  void init();
  void setMotor(int motor, int dir, int pwm);
  void moveRobot(int speed1, int speed2, int speed3, int speed4);
  int movementSineFunction(int motor, float ballAngleDegrees, boolean isCounter, int amplitude);
};

#endif
