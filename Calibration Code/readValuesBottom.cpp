// #include <Arduino.h>
// #include <SPI.h>
// int information;
// int inputType = 0;
// int ballAngle, netAngle, ballDistance, robotAngle;
// float desiredBallAngleDegrees = 0.00, currentBallAngleDegrees = 0.00;



// void setup() {
//     Serial.begin(9600);
//     Serial2.begin(9600);
// }

// void loop() {
//     if(Serial2.available() > 0){
//         information = Serial2.read();
//         switch (inputType) {
//         case 0:
//             inputType++;
//             break;
//         case 1:
//             robotAngle = information;
//             inputType++;
//             break;
//         case 2:
//             ballDistance = information;
//             inputType++;
//             break;
//         case 3:
//             ballAngle = information;
//             inputType++;
//             break;
//         case 4:
//             netAngle = information;
//             inputType = 0;
//             break;
//         }
//     }
//     Serial.print("angle: ");
//     Serial.print(robotAngle);
//     Serial.print(" ball distance: ");
//     Serial.print(ballDistance);
//     Serial.print(" ball angle: ");
//     Serial.print(ballAngle);
//     Serial.print(" net angle: ");
//     Serial.println(netAngle);
// }