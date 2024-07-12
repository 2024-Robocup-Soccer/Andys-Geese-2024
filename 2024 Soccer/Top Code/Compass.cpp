#include <Arduino.h>
#include <Adafruit_BNO08x.h>
#include "Compass.h"

// For SPI mode, we need a CS pin
#define BNO08X_CS 10
#define BNO08X_INT 9

// For SPI mode, we also need a RESET
// #define BNO08X_RESET 5
// but not for I2C or UART
#define BNO08X_RESET -1

Adafruit_BNO08x bno08x(BNO08X_RESET);
sh2_SensorValue_t sensorValue;


Compass::Compass() {
}

void Compass::setReports(void) {
    Serial.println("Setting desired reports");
    if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
        Serial.println("Could not enable game vector");
    }
}

void Compass::init() {
    if (!bno08x.begin_UART(&Serial1)) {
        while (1) {
            delay(10);
        }
    }
    if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
    }
}

void Compass::initPrint() {
    if (!bno08x.begin_UART(&Serial1)) {
        Serial.println("Failed to find BNO08x chip");
        while (1) {
            delay(10);
        }
    }
    Serial.println("Setting desired reports");
    if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
        Serial.println("Could not enable game vector");
    }
}

void Compass::resetCheck() {
   if (bno08x.wasReset()) {
        if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
        }
    }

    if (!bno08x.getSensorEvent(&sensorValue)) {
        return;
    } 
}

void Compass::resetCheckPrint() {
    if (bno08x.wasReset()) {
        Serial.print("sensor was reset ");
        Serial.println("Setting desired reports");
        if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
            Serial.println("Could not enable game vector");
        }
    }

    if (!bno08x.getSensorEvent(&sensorValue)) {
        return;
    }
}

float Compass::getBotAngle() {
    return sensorValue.un.gameRotationVector.k;
}
