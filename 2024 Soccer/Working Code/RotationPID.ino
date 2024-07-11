// // // //top

// // // Basic demo for readings from Adafruit BNO08x
// #include <Adafruit_BNO08x.h>

// // For SPI mode, we need a CS pin
// #define BNO08X_CS 10
// #define BNO08X_INT 9


// #define BNO08X_RESET -1

// Adafruit_BNO08x  bno08x(BNO08X_RESET);
// sh2_SensorValue_t sensorValue;

// void setup(void) {
//     Serial.begin(9600);
// 	// Serial7.begin(9600);
// 	if (!bno08x.begin_UART(&Serial1)) {  // Requires a device with > 300 byte UART buffer!
// 		while (1) { delay(10); }
// 	}

// 	setReports();
// 	delay(100);
// }

// // Here is where you define the sensor outputs you want to receive
// void setReports() {
// 	if (! bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
// 	}
// }

// int angleValue;
// int sensorInformation;
// void loop() {
// 	delay(10);
// 	if (bno08x.wasReset()) {
// 		setReports();
// 	}
// 	if (! bno08x.getSensorEvent(&sensorValue)) {
// 		return;
// 	}
// 	angleValue = sensorValue.un.gameRotationVector.k * 100;
// 	sensorInformation = map(angleValue, -100, 100, 1, 250);
// 	// Serial7.write(sensorInformation);
//     Serial.println(sensorValue.un.gameRotationVector.k);
// }

//bottom

#include "motorControlV3.h"

Motor motorController;

//types include 1 (robot angle), 2 (robot x), 3 (robot y), 4 (ball distance), 5 (ball angle), 6 (mis)
int unpackData(int value, int type) {
    int info = -1;
    if(type == 1) {
        info = map(value, 1, 250, -180, 180);
    }
    return info;
}


int calculateAngleError(int desiredDegrees, int actualDegrees) {
    int error = desiredDegrees - actualDegrees;
    
    if (error > 180) {
        error -= 360;
    } else if (error < -180) {
        error += 360;
    }

    return error;
}




int timeZero;
void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);
    timeZero = millis();

    motorController.initMotors();
}

int angleValue;
int pK = 1.00, iK = 0.0, dK = 0.0;
int desiredAngle = -10;
int angleError = 0;
int pastAngleError;
int iAngleError;
int dAngleError;

int motorValue;

int currentMillis = timeZero;
int pastMillis;


void loop() {
    if(Serial2.available() > 0) {
        angleValue = unpackData(Serial2.read(), 1);
    }

        pastAngleError = angleError;
        angleError = calculateAngleError(desiredAngle, angleValue);

        pastMillis = currentMillis;
        currentMillis = millis() - timeZero;
        iAngleError += angleError * (currentMillis - pastMillis);
        dAngleError = (angleError - pastAngleError)/(currentMillis - pastMillis);
        // motorValue = pK*angleError;
        motorValue = pK*angleError + iK*iAngleError + dK*dAngleError;

    motorController.moveRobot(motorValue, motorValue, motorValue, motorValue);

    // motorController.moveRobot(200, 200, 200, 200);
    Serial.print("Angle: ");
    Serial.print(angleValue);
    Serial.print(" Angle Error: ");
    Serial.print(angleError);
    Serial.print(" Motor Value: ");
    Serial.println(motorValue);


}



















