
// #include "motorControlV3.h"
// #include <RunningMedian.h>
// #include <SPI.h>
// #include <Arduino.h>

// const float pi = PI;

// void sync() {
//     byte check[5];
//     int shift=0;
//     if(Serial2.available() > 4) {
//         Serial2.readBytes(check, 5);
//     }

//     for (int i=0; i<5; i++) {
//         if (check[i] == 255) {
//             shift = i;
//         }
//     }

//     for (int i=0; i<shift; i++) {
//         Serial2.read();
//     }

// }

// int movementSineFunction(int motor, float ballAngleDegrees, boolean isCounter, int amplitude) {
//     float motorValue;
//     float ballAngle = PI/180 * ballAngleDegrees;
//     switch (motor) {
//         case 1:
//             motorValue = amplitude * sin(ballAngle + PI / 4);
//             // motorValue = amplitude * sin(ballAngle);
//             break;
//         case 2:
//             motorValue = amplitude * sin(ballAngle - PI / 4);
//             // motorValue = amplitude * sin(ballAngle - PI/2);
//             break;
//         case 3:
//             motorValue = amplitude * sin(ballAngle - 3 * PI / 4);
//             // motorValue = amplitude * -1 * sin(ballAngle - PI/2);
//             break;
//         case 4:
//             motorValue = amplitude * sin(ballAngle + 3 * PI / 4);
//             // motorValue = amplitude * -1 * sin(ballAngle - PI/2);
//             break;
//         default: motorValue = 0;
//     }

//     if (isCounter) {
//         motorValue *= -1;
//     }

//     return motorValue;
// }



// int calculateAngleError(int desiredDegrees, int actualDegrees) {
//     int error = desiredDegrees - actualDegrees;

//     if (error > 180) {
//         error -= 360;
//     } else if (error < -180) {
//         error += 360;
//     }

//     return error;
// }

// float ballAngleErrorSum = 0.00, currentBallAngleError = 0.00, pastBallAngleError, ballAngleErrorChange;

// int timeZero;



// Motor motorController;
// void setup() {
//     Serial.begin(2000000);
//     Serial2.begin(20000000);
//     timeZero = millis();

//     motorController.initMotors();
// }


// int unpackData(int value, int type) {
//     int info = -1;
//     if(type == 1) {
//          info = map(value, 0, 250, -180, 180);
//         // info = value;
//     }
//     //not done
//     else if(type == 2) {
//         info = value;
//     }
//     else if(type == 3) {
//          info = map(value, 0, 250, 0, 360);
//         //info = value;
//     }
//     else if(type == 4) {
//         info = map(value, 0, 250, -50, 50);
//     }
//     return info;
// }


// byte information[5] = { 0, 0, 0, 0, 0 };

// int pK = 1.00, iK = 0.50, dK = 0.80;
// int desiredAngle = -10;
// int netAngleError = 0;
// int pastNetAngleError;
// int iNetAngleError;
// int dNetAngleError;

// int motorValue;

// int currentMillis = timeZero;
// int pastMillis; 

// int robotAngle, ballDistance, ballAngle, netAngle;

// void loop() {
//     sync();

//     //0 == robotAngle, 1 == ballDistance, 2 == ballAngle, 3 == netAngle

//     if(Serial2.available() > 4) {
//         Serial2.readBytes(information, 5);
//     }

//     robotAngle = unpackData(information[1], 1);
//     ballDistance = unpackData(information[2], 2);
//     ballAngle = unpackData(information[3], 3);
//     if(information[4] != 253) {
//         netAngle = unpackData(information[4], 4);
//     }
//     else {
//         netAngle = -1;
//     }


//     Serial.print("Robot Angle: ");
//     Serial.print(robotAngle);
//     Serial.print(" Ball Distance: ");
//     Serial.print(ballDistance);
//     Serial.print(" Ball Angle: ");
//     Serial.print(ballAngle);
//     Serial.print(" Net Angle: ");
//     Serial.println(netAngle);

//     pastNetAngleError = netAngleError;
//     netAngleError = calculateAngleError(desiredAngle, ballAngle);

//     pastMillis = currentMillis;
//     currentMillis = millis() - timeZero;
//     iNetAngleError += netAngleError * currentMillis;
//     dNetAngleError = (netAngleError - pastNetAngleError)/(currentMillis - pastMillis);
//     // motorValue = pK*angleError;
//     motorValue = pK*netAngleError + iK*iNetAngleError + dK*dNetAngleError;

//     motorController.moveRobot(motorValue, motorValue, motorValue, motorValue);

//     // motorController.moveRobot(200, 200, 200, 200);
//     // Serial.print("Angle: ");
//     // Serial.print(netAngle);
//     // Serial.print(" Angle Error: ");
//     // Serial.print(netAngleError);
//     // Serial.print(" Motor Value: ");
//     // Serial.println(motorValue);

// }
