#include <Arduino.h>
#include <Wire.h>
#include <RunningMedian.h>
#include <Math.h>
#include "colorSensorV3.h"

//starts at 7, 6, ... 9, 8 for all 16 s 
int colourSensorValues[16];

const int numberSamples = 200;
const int differenceBetweenGreenAndWhite = 2;
RunningMedian greenValues[16] = {RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), 
    RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), 
    RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), 
    RunningMedian(numberSamples), RunningMedian(numberSamples)};

int maximum = 0;

float percentageIncrease = 1.20;

bool isFilled = false;


ColorSensor::ColorSensor(){
}

void ColorSensor::init() {
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    fillMedians();
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

void ColorSensor::fillMedians() {
    for(int i = 0; i < numberSamples; i++) {
        for(int i = 0; i < 16; i++) {
            greenValues[i].add(readSensor(i));
        }
    }
    isFilled = true;
}

void ColorSensor::readSensors() {
    for (int i = 0; i < 16; i++) {
        colourSensorValues[i] = readSensor(i);
        if(colourSensorValues[i] < greenValues[i].getAverage() * percentageIncrease) {
            greenValues[i].add(colourSensorValues[i]);
        }
        else {
            Serial.print("bad ");
        }
        // Serial.print(greenValues[i].getAverage());
        // Serial.print(" ");
        // Serial.print(colourSensorValues[i]);
        // Serial.print(" ");
    }
    // Serial.println();
}

float ColorSensor::calculateDirection() {
    // readSensors();

    float sumCos = 0;
    float sumSin = 0;
    int activeSensors = 0;

    for (int i = 0; i < 16; i++) {
         colourSensorValues[i] = readSensor(i);
        if (colourSensorValues[i] > greenValues[i].getMedian()*1.1) {
            float angle = ((2 * PI) / 16) * i;
            sumCos += cos(angle);
            sumSin += sin(angle);
            activeSensors++;
        }
    }

    if (activeSensors == 0) {
        // No line detected
        return 0; // or some invalid value to indicate no detection
    }

    float avgCos = sumCos / activeSensors;
    float avgSin = sumSin / activeSensors;

    return atan2(avgSin, avgCos);

    //360 clockwise
    //2.55 sensor 0
    //-2.16 90
    //-0.79 180
    //0.98 270
    //if negative between 90 and 180
    //if positive between 0 and 270

    //from 1.191 to above 2: move back
    //from-2.40 to -1.5: move left
    //from -0.7 to -1.18 move forward
    //from 0.8 to 0.98 move right

}




void ColorSensor::visualize(){
    readSensors();
    for(int i = 0; i < 16; i++) {
        if(colourSensorValues[i] > int(greenValues[i].getMedian() * percentageIncrease)) Serial.print("_");
        else Serial.print("*");
	}
    Serial.println("");
}

// input is 0 (sensor 12), 1 (sensor 1), ... 11 (sensor 11)
bool ColorSensor::detectColor(int sensor){
    colourSensorValues[sensor] = readSensor(sensor);
    if(colourSensorValues[sensor] > greenValues[sensor].getMedian() * percentageIncrease) return true;
    else return false;
} 


