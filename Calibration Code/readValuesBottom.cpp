// #include <Arduino.h>
// #include <SPI.h>
// int information;
// int inputType = 0;
// int ballAngle, netAngle, ballDistance, robotAngle;
// float desiredBallAngleDegrees = 0.00, currentBallAngleDegrees = 0.00;

// int unpackData(int value, int type) {
//     int info = -1;
//     if(type == 1) {
//         // info = map(value, 0, 250, 0, 360);
//         info = value;
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

// void setup() {
//     Serial.begin(9600);
//     Serial2.begin(9600);
// }

// void loop() {
//     // if(Serial2.available() > 0){
//     //     information = Serial2.read();
//     //     switch (inputType) {
//     //     case 0:
//     //         if(information == 255){inputType++;}
//     //         break;
//     //     case 1:
//     //         robotAngle = information;
//     //         inputType++;
//     //         break;
//     //     case 2:
//     //         ballDistance = information;
//     //         inputType++;
//     //         break;
//     //     case 3:
//     //         ballAngle = information;
//     //         inputType++;
//     //         break;
//     //     case 4:
//     //         netAngle = information;
//     //         inputType = 0;
//     //         break;
//     //     }
//     // }

//      if(Serial2.available() > 0) {
//         information = Serial2.read();
//         switch (inputType) {
//         case 0:
//             if(information == 255) inputType++;
//             break;
//         case 1:
//             robotAngle = unpackData(information, 1);
//             inputType++;
//             break;
//         case 2:
//             ballDistance = unpackData(information,2);
//             inputType++;
//             break;
//         case 3:
//             ballAngle = unpackData(information,3);
//             inputType++;
//             break;
//         case 4:
//             netAngle = unpackData(information,4);
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