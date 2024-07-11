//Adding Libraries
#include <Arduino.h>
#include <Adafruit_BNO08x.h>
#include <RunningMedian.h>
#include <Math.h>
#include "irSensorV3.h"

IRSensor irSensor;

bool isForward = false, inAdj = false;

#define BNO08X_CS 10
#define BNO08X_INT 9
#define BNO08X_RESET -1

Adafruit_BNO08x bno08x(BNO08X_RESET);
sh2_SensorValue_t sensorValue;


const int numberMedianValues = 25;
RunningMedian sDistances[12] = {RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), 
RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues),RunningMedian(numberMedianValues), 
RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), RunningMedian(numberMedianValues), 
RunningMedian(numberMedianValues)};

int lowestPin[numberMedianValues];

int IR_PINS[12] = {A11, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10};
//12, 1, 2, 3 ... 11
int sensorValues[12];

//Works by adding the compenents of the angle of the sensor as if it was a unit circle
//then diving by the number of sensor values
float calculateCircularAverage() {
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

float calculateSensorError(int desiredSensor, int actualSensor) {
    int error = desiredSensor - actualSensor;
    
    if (error > 11) {
        error -= 11;
    } else if (error < 0) {
        error += 11;
    }

    return error;
}

float findSensorDistance(int sensor, int intensity) {
    float distance = -1;
    switch (sensor) {
        case 0:
             distance = 1.4418*intensity - 53.772;
            break;
        case 1:
            distance = 1.9891*intensity - 79.985;
            break;
        case 2:
            distance = 1.9976*intensity - 76.34;
            break;
        case 3:
            distance = 1.9396*intensity - 88.854;
            break;
        case 4:
            distance = 2.07*intensity - 85.765;
            break;

        case 5:
           distance = 1.513*intensity - 64.132;
           break;
        case 6:
           distance = 0.9862*intensity - 22.478;
           break;
        case 7:
            distance = 1.7396*intensity - 67.194;
           break;
        case 8:
           distance = 1.6171*intensity - 59.931;
           break;
        case 9:
            distance = 1.7683*intensity - 71.653;
            break;
        case 10:
            distance = 2.2502*intensity - 96.351;
            break;        
        case 11:
            distance = 1.9891*intensity - 79.985;
            break;
    }
    return distance;
}

//puts raw data into curve then takes median
void readPreCalibratedSensors() {
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

// int findBallAngle() {
//     int low = -1;
//     readPreCalibratedSensors();
//     for(int i = 0; i < numberMedianValues; i++) {
//         if(lowestPin[i] < low) low = lowestPin[i];
//     }
//     for(int i = 0; i < numberMedianValues; i++) {
//         lowestPin[i] = lowestPin[i] - 12 + high;
//         if(lowestPin[i] < 0) {
//             lowestPin[i] += 11;
//         }
//     }
// }


//returns the which sensor the ball is closest to
int getBallAngle(){
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

//Used for setting up the compass
void setReports(void)
{
    Serial.println("Setting desired reports");
    if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR))
    {
        Serial.println("Could not enable game vector");
    }
}

//returns the compass angle
float getBotAngle()
{
    return sensorValue.un.gameRotationVector.k;
}

//setup
void setup()
{

    Serial.begin(9600);
    //Serial7.begin(9600);

    if (!bno08x.begin_UART(&Serial1))
    {
        Serial.println("Failed to find BNO08x chip");
        while (1)
        {
            delay(10);
        }
    }
    setReports();
    delay(100);
}

//Initialize the Compass
void compassInit() {
     if (bno08x.wasReset())
    {
        Serial.print("sensor was reset ");
        setReports();
    }

    if (!bno08x.getSensorEvent(&sensorValue))
    {
        return;
    }
}



void loop()
{
    int compassAngle;
    int angle = irSensor.findBallDirection();

    int val = pulseIn(10, HIGH, 1000);


    compassInit();
   
    compassAngle = getBotAngle()*100;

    int ballAngle = getBallAngle();

    int intensity = analogRead(IR_PINS[getBallAngle()]);
    int distance = findSensorDistance(ballAngle, intensity);

    Serial7.write(255);
    Serial7.write(compassAngle);
    Serial7.write(distance);
    Serial7.write(ballAngle);
    // 0 = no info from the camera
    // 1-250 = angle value of goal relative to robot
    // 500 = no goal found
    if (val>0){ //check if info from camera
        Serial7.write(val);   
        //Serial.println(val);
    }
    else{
        Serial7.write(-1); //no info from camera, send -1
        //Serial.println("No info");
    }

    Serial.println(val);
   
    //delay(10);
}
