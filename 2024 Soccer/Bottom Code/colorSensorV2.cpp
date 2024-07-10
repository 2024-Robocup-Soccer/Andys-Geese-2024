#include <Arduino.h>
#include <Wire.h>
#include <RunningMedian.h>
#include <Math.h>
//#include "motorControlV2.h"
//#include "irSensorV3.h"
//#include <Adafruit_BNO08x.h>
#include "colorSensorV2.h"

//starts at 7, 6, ... 9, 8 for all 16 s 

int lineDetectedInt[16];

int whiteValuesBot[16] = {108, 111, 115, 113, 110, 112, 119, 113, 112, 111, 117, 116, 110, 113, 106, 104}; //Bot 1
//int whiteValuesBot[16] = {92, 98, 106, 108, 106, 107, 107, 108, 110, 107, 113, 112, 107, 104, 96, 92}; //Bot 2
//int whiteValuesBot[16] = {105, 110, 113, 110, 108, 112, 111, 110, 111, 108, 112, 113, 109, 105, 101, 101}; //Bot 3 

//int greenValues[16]//Bot 1
int greenValues[16] = {83, 85, 89, 91, 91, 92, 92, 94, 96, 93, 94, 92, 92, 90, 85, 83}; //Bot 2
//int greenValues[16]//Bot 3

int maximum = 0;
int colsensorValue;
int adjustmentValue = 4;

ColorSensor::ColorSensor(){
}

void ColorSensor::calibrateSensors() {
    const int numSensors = 16;
    const int numReadings = 10; // Number of readings per sensor for averaging
    const int margin = 10; // Margin above the green average for the white threshold
    int greenValues[numSensors][numReadings];
    int whiteValues[numSensors][numReadings];
    int greenAverage[numSensors] = {0};
    int whiteReadCount[numSensors] = {0};

    Serial.println("Place the robot on the green surface and press a key to start calibration for green values.");
    while (!Serial.available()); // Wait for user input
    Serial.read(); // Clear the input buffer

    Serial.println("Calibrating green values...");
    for (int i = 0; i < numReadings; i++) {
        for (int j = 0; j < numSensors; j++) {
            greenValues[j][i] = readSensor(j);
        }
        delay(50); // Adjust delay as needed
    }

    for (int i = 0; i < numSensors; i++) {
        int sum = 0;
        for (int j = 0; j < numReadings; j++) {
            sum += greenValues[i][j];
        }
        greenAverage[i] = sum / numReadings;
        whiteThreshold[i] = greenAverage[i] + margin; // Set individual threshold for each sensor
    }

    Serial.println("Calculated white thresholds:");
    for (int i = 0; i < numSensors; i++) {
        Serial.print(whiteThreshold[i]);
        if (i < numSensors - 1) {
            Serial.print(", ");
        }
    }
    Serial.println("");

    Serial.println("Move the robot over the white lines and press a key to start calibration for white values.");
    while (!Serial.available()); // Wait for user input
    Serial.read(); // Clear the input buffer

    Serial.println("Calibrating white values...");

    while (true) {
        bool allSensorsCalibrated = true;

        for (int j = 0; j < numSensors; j++) {
            if (whiteReadCount[j] < numReadings) {
                int sensorValue = readSensor(j);
                if (sensorValue > whiteThreshold[j]) {
                    whiteValues[j][whiteReadCount[j]] = sensorValue;
                    whiteReadCount[j]++;
                }
            }
            if (whiteReadCount[j] < numReadings) {
                allSensorsCalibrated = false;
            }
        }

        // Print the status of sensors that are not yet calibrated
        Serial.print("Sensors not yet calibrated: ");
        for (int j = 0; j < numSensors; j++) {
            if (whiteReadCount[j] < numReadings) {
                Serial.print(j);
                Serial.print(" ");
            }
        }
        Serial.println("");

        if (allSensorsCalibrated) {
            break;
        }

        delay(50); // Adjust delay as needed
    }

    Serial.println("White calibration complete.");
    // Output the white values for each sensor
    Serial.println("White Values:");
    for (int i = 0; i < numSensors; i++) {
        int sum = 0;
        for (int j = 0; j < whiteReadCount[i]; j++) {
            sum += whiteValues[i][j];
        }
        int average = sum / whiteReadCount[i];
        Serial.print(average);
        if (i < numSensors - 1) {
            Serial.print(", ");
        }
    }
    Serial.println("");
}

void ColorSensor::readSensors(int sensorValues[]) {
    const int numSensors = 16;
    for (int i = 0; i < numSensors; i++) {
        sensorValues[i] = readSensor(i);
    }
}
 
float ColorSensor::calculateDirection(int sensorValues[]) {
    const int numSensors = 16;

    // Initialize angles for each sensor starting from 225 degrees
    float sensorAngles[numSensors];
    float startAngle = 225.0;
    for (int i = 0; i < numSensors; i++) {
        sensorAngles[i] = startAngle + i * 22.5;
        if (sensorAngles[i] >= 360.0) {
            sensorAngles[i] -= 360.0; // Wrap around if it exceeds 360 degrees
        }
    }

    int activeSensors[numSensors] = {0};
    for (int i = 0; i < numSensors; i++) {
        if (sensorValues[i] > whiteValuesBot[i]-adjustmentValue) {
            activeSensors[i] = 1;
        }
    }
    

    float weightedSum = 0;
    float totalWeight = 0;
    for (int i = 0; i < numSensors; i++) {
        if (detectColor(i)) {
            weightedSum += sensorAngles[i] * sensorValues[i];
            totalWeight += sensorValues[i];
        }
    }

    float direction = 0;
    if (totalWeight > 0) {
        direction = weightedSum / totalWeight;
    }

    return direction;
}

//sensor is different than pcb
//sensor starts at front (0) increases clockwise to 15 (looking from bottom)
int ColorSensor::readSensor(int sensor) {
    switch(sensor){
        case 0:   
            digitalWrite(A0, HIGH);
            digitalWrite(A1, HIGH);
            digitalWrite(A2, HIGH);
            digitalWrite(A3, LOW);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
        case 1:
            digitalWrite(A0, LOW);
            digitalWrite(A1, HIGH);
            digitalWrite(A2, HIGH);
            digitalWrite(A3, LOW);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
        case 2:
            digitalWrite(A0, HIGH);
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(A3, LOW);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW); 
            break;       
        case 3: 
            digitalWrite(A0, LOW);
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(A3, LOW);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
        case 4:
          digitalWrite(A0, HIGH);
          digitalWrite(A1, HIGH);
          digitalWrite(A2, LOW);
          digitalWrite(A3, LOW);
          digitalWrite(A4, LOW);
          digitalWrite(A6, LOW);
          break;
        case 5:
          digitalWrite(A0, LOW);
          digitalWrite(A1, HIGH);
          digitalWrite(A2, LOW);
          digitalWrite(A3, LOW);
          digitalWrite(A4, LOW);
          digitalWrite(A6, LOW);
          break;
        case 6:
          digitalWrite(A0, HIGH);
          digitalWrite(A1, LOW);
          digitalWrite(A2, LOW);
          digitalWrite(A3, LOW);
          digitalWrite(A4, LOW);
          digitalWrite(A6, LOW);
          break;
        case 7:
        	digitalWrite(A0, LOW);
          digitalWrite(A1, LOW);
          digitalWrite(A2, LOW);
          digitalWrite(A3, LOW);
          digitalWrite(A4, LOW);
          digitalWrite(A6, LOW);
          break;
        case 8:
          digitalWrite(A0, HIGH);
          digitalWrite(A1, HIGH);
          digitalWrite(A2, HIGH);
          digitalWrite(A3, HIGH);
          digitalWrite(A4, LOW);
          digitalWrite(A6, LOW);
          break;
        case 9:
          digitalWrite(A0, LOW);
          digitalWrite(A1, HIGH);
          digitalWrite(A2, HIGH);
          digitalWrite(A3, HIGH);
          digitalWrite(A4, LOW);
          digitalWrite(A6, LOW);
          break;
        case 10:
            digitalWrite(A0, HIGH);
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(A3, HIGH);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
        case 11:
            digitalWrite(A0, LOW);
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(A3, HIGH);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
        case 12:
            digitalWrite(A0, HIGH);
            digitalWrite(A1, HIGH);
            digitalWrite(A2, LOW);
            digitalWrite(A3, HIGH);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
        case 13:
            digitalWrite(A0, LOW);
            digitalWrite(A1, HIGH);
            digitalWrite(A2, LOW);
            digitalWrite(A3, HIGH);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
        case 14:
            digitalWrite(A0, HIGH);
            digitalWrite(A1, LOW);
            digitalWrite(A2, LOW);
            digitalWrite(A3, HIGH);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
        case 15:
            digitalWrite(A0, LOW);
            digitalWrite(A1, LOW);
            digitalWrite(A2, LOW);
            digitalWrite(A3, HIGH);
            digitalWrite(A4, LOW);
            digitalWrite(A6, LOW);
            break;
    }
	return analogRead(A5);
}

void ColorSensor::colourSensorInit() {
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
}

void ColorSensor::readSensors(){
    for(int i = 0; i < 16; i++) {
        colsensorValue = readSensor(i);
        lineDetectedInt[i] = colsensorValue;
        Serial.print(lineDetectedInt[i]);
		Serial.print(", ");
    }
    Serial.println("");
}

void ColorSensor::visualize(){
    for(int i = 0; i < 16; i++) {
        colsensorValue = readSensor(i);
        lineDetectedInt[i] = colsensorValue;
       if (lineDetectedInt[i]>(whiteValuesBot[i]-adjustmentValue)) Serial.print("_");
        else Serial.print("*");
	}
    Serial.println("");
}

bool ColorSensor::detectColor(int sensor){
    colsensorValue = readSensor(sensor);
    lineDetectedInt[sensor] = colsensorValue;
    if(lineDetectedInt[sensor]>(whiteValuesBot[sensor]-adjustmentValue)) return true;
    else return false;
} 



