
// // Basic demo for readings from Adafruit BNO08x
// #include <Adafruit_BNO08x.h>

// // For SPI mode, we need a CS pin
// #define BNO08X_CS 10
// #define BNO08X_INT 9

// // For SPI mode, we also need a RESET
// //#define BNO08X_RESET 5
// // but not for I2C or UART
// #define BNO08X_RESET -1

// Adafruit_BNO08x bno08x(BNO08X_RESET);
// sh2_SensorValue_t sensorValue;
// //top pcb
// void setup() {
//     Serial.begin(9600);
//     Serial7.begin(9600);
//     Serial.println("Serial communication between boards test: top");
//     // if (!bno08x.begin_UART(&Serial1)) {  // Requires a device with > 300 byte
//     // // Serial.println("Failed to find BNO08x chip");
//     // while (1) {
//     //   delay(10);
//     // }
// //   }
// }

// void loop() {
//     Serial7.write(255);
//     Serial7.write(4);
//     Serial7.write(200);
//     Serial7.write(40);
// }

//bottom pcb
void setup() {
  Serial.begin(9600);
  Serial2.begin(20000000);
  Serial.println("Serial communication between boards test: bottom");
}
byte information[5];
int i =0;
boolean calibrated = false;
int angle;
int x;
int y;
int inputType = 1;
void loop() {
    if(Serial2.available() > 0){
        Serial2.read();
        // Serial2.flush();
        switch (inputType) {
            case 0:
                if(information[0] == 255){
                    inputType++;
                Serial.print("Calibrated ");
                } 
                break;
            case 1:
                angle = information[0];
                inputType=0;
                Serial.print("Angle: ");
                Serial.println(angle);
                break;
            case 2:
                x = information;
                inputType++;
                Serial.print(" X: ");
                Serial.print(x);
                break;
            case 3:
                y = information;
                inputType = 0;
                Serial.print(" Y: ");
                Serial.println(y);
                break;
        }
        
    }
    else {
        // Serial.println("N/A");
    }
    
}
