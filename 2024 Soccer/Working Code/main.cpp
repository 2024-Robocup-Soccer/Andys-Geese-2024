// //Adding Libraries
// #include <Arduino.h>
// #include <Adafruit_BNO08x.h>
// #include <RunningMedian.h>
// #include <Math.h>
// #include "irSensorV3.h"


// IRSensor irSensor;

// #define BNO08X_CS 10
// #define BNO08X_INT 9
// #define BNO08X_RESET -1
// Adafruit_BNO08x bno08x(BNO08X_RESET);
// sh2_SensorValue_t sensorValue;


// //Used for setting up the compass
// void setReports(void)
// {
//     // Serial.println("Setting desired reports");
//     if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR))
//     {
//         // Serial.println("Could not enable game vector");
//     }
// }

// //returns the compass angle
// float getBotAngle()
// {
//     return sensorValue.un.gameRotationVector.k;
// }

// //setup
// void setup(){

//     // Serial.begin(9600);
//     Serial7.begin(20000000);
//     if (!bno08x.begin_UART(&Serial1))
//     {
//         //Serial.println("Failed to find BNO08x chip");
//         while (1)
//         {
//             delay(10);
//         }
//     }
//     setReports();
//     delay(100);
// }

// //Initialize the Compass
// void compassInit() {
//      if (bno08x.wasReset())
//     {
//         //Serial.print("sensor was reset ");
//         setReports();
//     }

//     if (!bno08x.getSensorEvent(&sensorValue))
//     {
//         return;
//     }
// }
// //type 1 = compass, 2 = ball distance, 3 = ball angle, 4 = net angle
// int pack(int value, int type) {
//     int info = -1;
//     switch(type) {
//     case 1: 
//         info = map(value, -99, 99, 0, 250);
//         break;
//     case 2:
//         info = map(value, 0, 1557, 0, 250);
//         break;
//     case 3:
//         info = map(value, 0, 11, 0, 250);
//         break;
//     case 4: 
//         info = info;
//         break;
//     }
//     return info;
// }


// void loop() {
//     compassInit();
    
//     u_int8_t compassAngle = pack(getBotAngle()*100, 1);
//     u_int8_t ballAngle = pack(irSensor.getBallAngle(), 3);
//     u_int8_t intensity = irSensor.getIntensity(ballAngle);
//     u_int8_t distance = pack(irSensor.findSensorDistance(ballAngle, intensity), 2);

//     int val = pulseIn(10, HIGH, 600);
//     if (val > 0) {
//         if(val > 250) {
//             val = 253;
//         }
//     }
//     else {
//         val = 0;
//     }
    

//     u_int8_t information[5] = { 255, compassAngle, distance, ballAngle, u_int8_t(val) };
//     Serial7.write(information, 5);
//     // Serial7.write(pack(compassAngle, 1));
//     // Serial7.write(pack(distance, 2));
//     // Serial7.write(pack(ballAngle, 3));
//     // 0 = no info from the camera
//     // 1-250 = angle value of goal relative to robot
//     // 500 = no goal found
//     // if (val>0){ Serial7.write(pack(val,4));}
//     // else{Serial7.write(-1);}//No Info from Camera


//     Serial.print("compass angle: ");
//     Serial.print(information[1]);
//     Serial.print(" ball distance: ");
//     Serial.print(information[2]);
//     Serial.print(" ball angle: ");
//     Serial.print(information[3]);
//     Serial.print(" net angle: ");
//     Serial.println(information[4]);
// }