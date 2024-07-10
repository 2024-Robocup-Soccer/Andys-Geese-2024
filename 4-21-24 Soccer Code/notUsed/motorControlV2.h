#ifndef MOTOR_CONTROL_V2_H
#define MOTOR_CONTROL_V2_H

class Motor {
public:
  static void initMotors();
  static void setMotor(int motor, int dir, int pwm);
  static void moveRobot(int dir1, int dir2, int dir3, int dir4, int speed, char move);
  static void left(int speed);
  static void right(int speed);
  static void forward(int speed);
  static void backward(int speed);
  static void leftTurn(int speed);
  static void rightTurn(int speed);
  static void stop();
};

#endif
