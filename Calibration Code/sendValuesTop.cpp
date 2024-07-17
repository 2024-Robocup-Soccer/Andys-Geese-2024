#include <Arduino.h>
#include <SPI.h>


void setup() {
    Serial.begin(9600);
    Serial7.begin(20000000);
}

 u_int8_t compassAngle = 100;
    u_int8_t ballAngle = 100;
    u_int8_t intensity = 100;
    u_int8_t distance = 100;

void loop() {
    //---------------Setting up Variables---------------
    u_int8_t compassAngle = 100;
    u_int8_t ballAngle = 100;
    u_int8_t intensity = 100;
    u_int8_t distance = 100;
    int cameraValue = 100;
    
    //Putting all the data into a array to send down
    u_int8_t information[5] = { 255, compassAngle, distance, ballAngle, u_int8_t(cameraValue) };

    
    //Sending down the Data down
    Serial7.write(information, 5);

    //--------DeBug/Read Data-----------
    Serial.print("compass angle: ");
    Serial.print(information[1]);
    Serial.print(" ballgit distance: ");
    Serial.print(information[2]);
    Serial.print(" ball angle: ");
    Serial.print(information[3]);
    Serial.print(" net angle: ");
    Serial.println(information[4]);
}
