#include <Arduino.h>
#include <Adafruit_BNO08x.h>

#include <RunningMedian.h>
#include <Math.h>
#include "motorControlV2.h"
#include "irSensorV3.h"

IRSensor irSensor;
Motor motor;

bool isForward = false, inAdj = false;


// For SPI mode, we need a CS pin
#define BNO08X_CS 10
#define BNO08X_INT 9

// For SPI mode, we also need a RESET
// #define BNO08X_RESET 5
// but not for I2C or UART
#define BNO08X_RESET -1

Adafruit_BNO08x bno08x(BNO08X_RESET);
sh2_SensorValue_t sensorValue;

void setReports(void)
{
    Serial.println("Setting desired reports");
    if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR))
    {
        Serial.println("Could not enable game vector");
    }
}

float getBotAngle()
{
    return sensorValue.un.gameRotationVector.k;
}

void setup()
{

    Serial.begin(9600);
    Serial7.begin(9600);
    // Serial8.begin(9600);

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

void pointNorth(float compassAngle)
{
    if (compassAngle <= 0.20 && compassAngle >= -0.20)
    {
        if (inAdj)
            Serial7.write(7);
        inAdj = false;
    }
    else if (compassAngle > 0.20)
    {
        Serial7.write(6);
        inAdj = true;
    }
    else if (compassAngle < -0.20)
    {
        Serial7.write(5);
        inAdj = true;
    }
}

void movement(int angle)
{
    if (!inAdj)
    {
        if (isForward)
        {
            if (!(angle == 330 || angle == 360 || angle == 30))
            {
                isForward = false;
            }
            else
            {
                Serial7.write(1);
            }
        }

        if (angle == 360)
        {
            isForward = true;
        }
        else if (angle <= 60)
        {
            Serial7.write(2);
        }
        else if (angle >= 300)
        {
            Serial7.write(3);
        }
        else if (angle >= 180 && angle < 300)
        {
            Serial7.write(4);
        }
        else if (angle >= 60 && angle < 180)
        {
            Serial7.write(4);
        }
    }
}

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

// int n = 0;
// int avg[3];

// avg[0] = irSensor.findBallDirection();
// avg[1] = irSensor.findBallDirection();
// avg[2] = irSensor.findBallDirection();


void loop()
{
    // n++;
    // int read = irSensor.findBallDirection();
    // avg[n % 3] = read;
    // int angle = (avg[0] + avg[1] + avg[2]) / 3;

    float compassAngle;
    int angle = irSensor.findBallDirection();

    compassInit();
   
    compassAngle = getBotAngle();

    pointNorth(compassAngle);

    Serial.println(angle);
    Serial.println(compassAngle);

    movement(angle);

    delay(10);
}
