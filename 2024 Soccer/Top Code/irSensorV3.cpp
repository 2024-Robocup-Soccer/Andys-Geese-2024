#include "irSensorV3.h"

IRSensor::IRSensor() 
: s1Distance(sensorReadCount), s2Distance(sensorReadCount), s3Distance(sensorReadCount), s4Distance(sensorReadCount), s5Distance(sensorReadCount), s6Distance(sensorReadCount), s7Distance(sensorReadCount), s8Distance(sensorReadCount), s9Distance(sensorReadCount), s10Distance(sensorReadCount), s11Distance(sensorReadCount), s12Distance(sensorReadCount) {
}

void IRSensor::readSensors() {
    for (int i = 0; i < sensorReadCount; i++) {
        s1Distance.add(analogRead(A0));
        s2Distance.add(analogRead(A1));
        s3Distance.add(analogRead(A2));
        s4Distance.add(analogRead(A3));
        s5Distance.add(analogRead(A4));
        s6Distance.add(analogRead(A5));
        s7Distance.add(analogRead(A6));
        s8Distance.add(analogRead(A7));
        s9Distance.add(analogRead(A8));
        s10Distance.add(analogRead(A9));
        s11Distance.add(analogRead(A10));
        s12Distance.add(analogRead(A11));
    }

    sensorValues[0] = s1Distance.getMedian();
    sensorValues[1] = s2Distance.getMedian();
    sensorValues[2] = s3Distance.getMedian();
    sensorValues[3] = s4Distance.getMedian();
    sensorValues[4] = s5Distance.getMedian();
    sensorValues[5] = s6Distance.getMedian();
    sensorValues[6] = s7Distance.getMedian();
    sensorValues[7] = s8Distance.getMedian();
    sensorValues[8] = s9Distance.getMedian();
    sensorValues[9] = s10Distance.getMedian();
    sensorValues[10] = s11Distance.getMedian();
    sensorValues[11] = s12Distance.getMedian();
}

int IRSensor::findMinSensor() {
    readSensors();
    int min = 1e8;
    int minIndex = -1;
    for (int i = 0; i < 12; i++) {
        int cur = sensorValues[i];
        if (cur < min) {
            min = cur;
            minIndex = i;
        }
    }
    return minIndex;
}

int IRSensor::findBallDirection() {
    int closestSensor = findMinSensor();
    return (closestSensor + 1) * 30;
}

void IRSensor::printBallDirection() {
    Serial.print("Ball direction: ");
    Serial.println(findBallDirection());
}

void IRSensor::debugValues() {
    for(int i = 0; i < 12; i++) {
        Serial.print(i+1);
        Serial.print(": ");
        Serial.println(sensorValues[i]);
    }
}

  void IRSensor::debugComponents() {
    for(int i = 0; i < 12; i++) {
      Serial.print(i+1);
      Serial.print(": ");
      double angle = ((i+1) * 360.0) / 12.0; 
      double radians = angle * DEG_TO_RAD; 
      double x = sensorValues[i] * cos(radians);
      double y =  sensorValues[i] * sin(radians);
      Serial.print(x);
      Serial.print(" ");
      Serial.println(y);
    }
  }

