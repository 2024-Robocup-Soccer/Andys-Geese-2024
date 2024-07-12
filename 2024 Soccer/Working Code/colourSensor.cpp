#include "colorSensorV2.h"
#include <Arduino.h>

ColorSensor colourSensor;

void setup() {
    Serial.begin(9600);
    colourSensor.init();
    colourSensor.fillMedians();
}

void loop() {
    colourSensor.readSensors();
    delay(100);
}
