#include "irSensorV3.h"
#include <RunningMedian.h>

IRSensor::IRSensor() 
: s1Distance(sensorReadCount), s2Distance(sensorReadCount), s3Distance(sensorReadCount), s4Distance(sensorReadCount), s5Distance(sensorReadCount), s6Distance(sensorReadCount), s7Distance(sensorReadCount), s8Distance(sensorReadCount), s9Distance(sensorReadCount), s10Distance(sensorReadCount), s11Distance(sensorReadCount), s12Distance(sensorReadCount) {
}


const int numberMedianValues = 25;
RunningMedian sDistances[12] = {RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), 
RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues),RunningMedian(numberMedianValues), 
RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), 
RunningMedian(numberMedianValues)};


int lowestPin[numberMedianValues];
int IR_PINS[12] = {A11, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10};
//12, 1, 2, 3 ... 11
int sensorValues[12];


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

  
float IRSensor::findSensorDistance(int sensor, int intensity) {
    float distance = -1;
    switch (sensor) {
        case 0:
             //distance = ; //Bot 1
             distance = 1.9214*intensity - 81.673;//Bot 2
             //distance = ;//Bot 3
            break;
        case 1:
            //distance = ;//Bot 1
            distance = 1.6369*intensity - 72.97;//Bot 2
            //distance = ;//Bot 3
            break;
        case 2:
            //distance = ;//Bot 1   
            distance = 1.5889*intensity - 65.907;//Bot 2
            //distance = ;//Bot 3
            break;
        case 3:
            //distance = ;//Bot 1
            distance = 1.8732*intensity - 78.922;//Bot 2
            //distance = ;//Bot 3
            break;
        case 4:
            //distance = ;//Bot 1
            distance = 2.1074*intensity - 86.835;//Bot 2
            //distance = ;//Bot 3
            break;

        case 5:
            //distance = ;//Bot 1
           distance = 1.9093*intensity - 80.002;//Bot 2
           //distance = ;//Bot 3
           break;
        case 6:
            //distance = ;//Bot 1
           distance = 1.6892*intensity - 71.084;//Bot 2
           //distance = ;//Bot 3
           break;
        case 7:
            //distance = ;//Bot 1
            distance = 1.7187*intensity - 73.411;//Bot 2
            //distance = ;//Bot 3
           break;
        case 8:
            //distance = ;//Bot 1
           distance = 1.7463*intensity - 76.2;//Bot 2
           //distance = ;//Bot 3
           break;
        case 9:
            //distance = ;//Bot 1
            distance = 1.6595*intensity - 68.838;//Bot 2
            //distance = ;//Bot 3
            break;
        case 10:
            //distance = ;//Bot 1
            distance = 1.7076*intensity - 71.065;//Bot 2
            //distance = ;//Bot 3
            break;        
        case 11:
            //distance = ;//Bot 1
            distance = 1.626*intensity - 67.416;//Bot 2
            //distance = ;//Bot 3
            break;
    }
    return distance;
}


//returns the which sensor the ball is closest to
int IRSensor::getBallAngle(){
    int lowestSensor =100000;
    int sensor;
    for(int i=0; i<12;i++){
        int intensity = analogRead(IR_PINS[i]);
        int distance = findSensorDistance(i,intensity);
        if(distance < lowestSensor){
            lowestSensor = distance;
            sensor = i;
        }
    }
    return sensor;
}


//puts raw data into curve then takes median
void IRSensor::readCalibratedSensors() {
    int min;
    int minIndex;
    for(int i = 0; i < numberMedianValues; i++) {
        min = 1e8;
        minIndex = -1;
        for(int j = 0; j < 12; j++) {
            sensorValues[j] = analogRead(IR_PINS[j]);
            sDistances[j].add(findSensorDistance(j, sensorValues[j]));
            if(sensorValues[j] < min) {
                minIndex = j;
                min = sensorValues[j];
            }
        }
        if(minIndex != -1) lowestPin[i] = (minIndex);
    }
}


//Works by adding the compenents of the angle of the sensor as if it was a unit circle
//then diving by the number of sensor values
float IRSensor::calculateCircularAverage() {
    float sinSum = 0.0;
    float cosSum = 0.0;
    float radiansPerValue = (2.0 * 3.14) / 12.0;

    for(int i = 0; i < numberMedianValues; i++) {
        float angle = sensorValues[i] * radiansPerValue;
        sinSum += sin(angle);
        cosSum += cos(angle);
    }

    float avgAngle = atan2(sinSum / numberMedianValues, cosSum / numberMedianValues);

    if (avgAngle < 0) {
        avgAngle += 2.0 * 3.14;
    }

    float averageValue = avgAngle / radiansPerValue;
    return averageValue;
}


float IRSensor::calculateSensorError(int desiredSensor, int actualSensor) {
    int error = desiredSensor - actualSensor;
    
    if (error > 11) {
        error -= 11;
    } else if (error < 0) {
        error += 11;
    }

    return error;
}

int IRSensor::getIntensity(int ballAngle){
    return analogRead(IR_PINS[ballAngle]);
}

