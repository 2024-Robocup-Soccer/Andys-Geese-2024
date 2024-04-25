// #include <Arduino.h>
// #include <Adafruit_BNO08x.h>

// #include <RunningMedian.h>
// #include <Math.h>
// #include "motorControlV2.h"
// #include "compassV2.h"
// #include "irSensorV3.h"


// // Debug Code

// int sensorReadCount = 25;



// RunningMedian s1Distance = RunningMedian(sensorReadCount),
// s2Distance = RunningMedian(sensorReadCount),
// s3Distance = RunningMedian(sensorReadCount),
// s4Distance = RunningMedian(sensorReadCount),
// s5Distance = RunningMedian(sensorReadCount),
// s6Distance = RunningMedian(sensorReadCount),
// s7Distance = RunningMedian(sensorReadCount),
// s8Distance = RunningMedian(sensorReadCount),
// s9Distance = RunningMedian(sensorReadCount),
// s10Distance = RunningMedian(sensorReadCount),
// s11Distance = RunningMedian(sensorReadCount),
// s12Distance = RunningMedian(sensorReadCount);


// enum pins {
//   S1_PIN = A0,
//   S2_PIN = A1,
//   S3_PIN = A2,
//   S4_PIN = A3,
//   S5_PIN = A4,
//   S6_PIN = A5,
//   S7_PIN = A6,
//   S8_PIN = A7,
//   S9_PIN = A8,
//   S10_PIN = A9,
//   S11_PIN = A10,
//   S12_PIN = A11

// };

// int sensorValues[12];


// RunningMedian xDistanceOfBall = RunningMedian(sensorReadCount);
// RunningMedian yDistanceOfBall = RunningMedian(sensorReadCount);




// void setup() {


//   Serial.begin(9600);
//   Serial.println("Compiled!");
// }

// IRSensor irSensor;

// void loop() {

//   delay(100); //Time to open SM

//   irSensor.readSensors();
// //   Serial.println(irSensor.findBallDirection());
//   irSensor.debugValues();
//   // irSensor.debugComponents();

// }