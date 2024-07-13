#include <Arduino.h>
#include <Wire.h>
#include <RunningMedian.h>
#include <Math.h>
#include "colorSensorV3.h"

//starts at 7, 6, ... 9, 8 for all 16 s 
int sensorValues[16];

const int numberSamples = 100;
const int differenceBetweenGreenAndWhite = 2;
RunningMedian greenValues[16] = {RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), 
    RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), 
    RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), RunningMedian(numberSamples), 
    RunningMedian(numberSamples), RunningMedian(numberSamples)};

int maximum = 0;

float percentageIncrease = 1.05;

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

void ColorSensor::analyzeSensorValues() {
    for (int i = 0; i < 16; i++) {
        sensorValues[i] = readSensor(i);
        if(sensorValues[i] < greenValues[i].getMedian() * percentageIncrease) greenValues[i].add(sensorValues[i]);
        else Serial.print("bad ");
        Serial.print(greenValues[i].getMedian());
        Serial.print(" ");
        Serial.print(sensorValues[i]);
        Serial.print(" ");
    }
    Serial.println();
}

float ColorSensor::calculateDirection() {
    analyzeSensorValues();

    float sumCos = 0;
    float sumSin = 0;
    for(int i = 0; i < 16; i++) {
        sumCos += cos(sensorValues[i] * (((2 * PI) / 16) * i));
        sumSin += sin(sensorValues[i] * (((2 * PI) / 16) * i));
    }

    return atan2(sumCos / 16, sumSin / 16);
}

void ColorSensor::visualize(){
    analyzeSensorValues();
    for(int i = 0; i < 16; i++) {
        if(sensorValues[i] > int(greenValues[i].getMedian() * percentageIncrease)) Serial.print("_");
        else Serial.print("*");
	}
    Serial.println("");
}

// input is 0 (sensor 12), 1 (sensor 1), ... 11 (sensor 11)
bool ColorSensor::detectColor(int sensor){
    sensorValues[sensor] = readSensor(sensor);
    if(sensorValues[sensor] > greenValues[sensor].getMedian() * percentageIncrease) return true;
    else return false;
} 


