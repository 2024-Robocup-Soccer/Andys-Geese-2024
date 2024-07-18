    #include "motorControlV3.h"
    #include <RunningMedian.h>
    #include <SPI.h>
    #include <Arduino.h>
    #include "colorSensorV3.h"


    const float pi = PI;

    int information, robotAngle, ballDistance, ballAngle, netAngle, motorValue, inputType;
    bool inAdj = false;
    bool onGreen = false; 
    int speed = 150;

    ColorSensor colourSensor;
    Motor motorController;

    int timeZero;
    void setup() {
        Serial.begin(1152000);
        Serial2.begin(1152000);
        timeZero = millis();

        motorController.initMotors();
        colourSensor.init();
    }
    void sync() {
        byte check[5];
        int shift=0;
        if(Serial2.available() > 4) {
            Serial2.readBytes(check, 5);
        }

        for (int i=0; i<5; i++) {
            if (check[i] == 255) {
                shift = i;
            }
        }

        for (int i=0; i<shift; i++) {
            Serial2.read();
        }

    }
    int unpackData(int value, int type) {
        int info = -1;
        if(type == 1) {
             info = map(value, 0, 250, -180, 180);
            // info = value;
        }
        //not done
        else if(type == 2) {
            info = value;
        }
        else if(type == 3) {
             info = map(value, 0, 250, 0, 360);
            //info = value;
        }
        else if(type == 4) {
            info = map(value, 0, 250, -50, 50);
        }
        return info;
    }

    void behindBall(int ballAngle, int motorValue){

        if(!inAdj){
            if(ballAngle == 0){

                // motorController.moveRobot(-forwardSpeed*0.7, -forwardSpeed*0.7, + forwardSpeed, + forwardSpeed);

                motorController.moveRobot(-motorValue*0.7, -motorValue*0.7, + motorValue, + motorValue);
                

                Serial.println("Behind Ball Code");
            }
            else if (ballAngle == 33){
                motorController.moveRobot(0, -motorValue, 0, motorValue);
                Serial.println("Behind Ball Code");
            }
            else if (ballAngle == 360){
                motorController.moveRobot(-motorValue, 0, motorValue, 0);
                Serial.println("Behind Ball Code");
            }
            else if (ballAngle == 131 || ballAngle == 98 || ballAngle == 262 || ballAngle == 295){
                motorController.moveRobot(motorValue, motorValue*0.7, -motorValue, -motorValue);
                Serial.println("Behind Ball Code");
            }
            else if(ballAngle < 327 && ballAngle >164) {
                motorController.moveRobot(motorValue, 0, -motorValue, 0);
                Serial.println("Behind Ball Code");
            }
            else if(ballAngle <=164 && ballAngle >131){
                motorController.moveRobot(0, motorValue, 0, -motorValue);
                Serial.println("Behind Ball Code");
            }
            else if (ballAngle == 65 || ballAngle == 196) {
                motorController.moveRobot(motorValue, -motorValue*1.25, -motorValue, motorValue);
            }
            else if (ballAngle == 327) {
                motorController.moveRobot(-motorValue, motorValue*1.25, motorValue, -motorValue);
            }
        }
    }

    void pointNorth(float compassAngle){
        int motorValue = 50;
        if (compassAngle <= 20 && compassAngle >= -20) {
            if (inAdj){
                inAdj = false;
                Serial.println("Point North Code");
            }
        }
        else if (compassAngle < -20) {
            motorController.moveRobot(motorValue, motorValue, motorValue, motorValue);
            Serial.println("Point North Code");
            inAdj = true;
        }
        else if (compassAngle > 20) {
            motorController.moveRobot(-motorValue, -motorValue, -motorValue, -motorValue);
            inAdj = true;
            Serial.println("Point North Code");
        }
    }
    int moveDir() {
        int averageCount = 5;
        float newVal=0;
        float val = colourSensor.calculateDirection();
        for(int i=0;i<averageCount;i++){
            newVal += colourSensor.calculateDirection();
        }
        newVal = newVal/averageCount;
        if (newVal > 1.91) {
            return 0;
        }
        else if (newVal >= -0.8 && newVal <= -0.1) {
            return 180;
        }
        else if(newVal >=0.7 && newVal <= 1.2) {
            return 270;
        }
        else if(newVal>=-2.6 && newVal <-1.7){
            return 90;
        }
        else if(newVal == 0){
            return -1;
        }
        else{
            return -255;
        }
    }

    void avoidWhite(int motorValues){
        int curval = moveDir();
        int time = 2000;
        Serial.println(curval);

        if(curval == 255){

            onGreen = false;
        }
        else if(curval == 0){
            //move back
            onGreen = false;
            int startmillis = millis();
            // for (int i=0; i<time; i++) {
                motorController.moveRobot(motorValues*0.7, motorValues*0.7, -motorValues*1.2, -motorValues*1.2);
            // }
            Serial.print("Move Backward");

        }
        else if(curval == 90){
            //move left
            onGreen = false;
            int startmillis = millis();
            // for (int i=0; i<time; i++) {
                motorController.moveRobot(motorValues, -motorValues, -motorValues, motorValues);
            // }
            Serial.print("Move Left");

        }
        else if(curval == 180){
            //move forward
            onGreen = false;
            int startmillis = millis();
            // for (int i=0; i<time; i++) {
                motorController.moveRobot(-motorValues, -motorValues, motorValues, motorValues);
            // }
            Serial.print("Move Forward");

        }
        else if(curval == 270){
            //move right
            onGreen = false;
            int startmillis = millis();
            // for (int i=0; i<time; i++) {
                motorController.moveRobot(-motorValues, motorValues, motorValues, -motorValues);
            // }
            Serial.print("Move Right");
    
        }
        else if(curval == -1){
            //on green
            onGreen = true;
            motorController.moveRobot(0, 0, 0, 0);
            Serial.print("Green");
        }
        else{}
        // sync();
    }

    void loop() {

        if(Serial2.available() > 0) {
            information = Serial2.read();
            switch (inputType) {
            case 0:
                if(information == 255) {inputType++;}
                // Serial.println("Case 0");
                break;
            case 1:
                robotAngle = unpackData(information, 1);
                // Serial.println("Case 1");
                inputType++;
                break;
            case 2:
                ballDistance = unpackData(information,2);
                // Serial.println("Case 2");
                inputType++;
                break;
            case 3:
                ballAngle = unpackData(information,3);
                // Serial.println("Case 3");
                inputType++;
                break;
            case 4:
                netAngle = unpackData(information,4);
                // Serial.println("Case 4");
                inputType = 0;
                break;
            }
            Serial2.flush();
        }

        Serial.print("Robot Angle: ");
        Serial.print(robotAngle);
        Serial.print(" Ball Distance: ");
        Serial.print(ballDistance);
        Serial.print(" Ball Angle: ");
        Serial.print(ballAngle);
        Serial.print(" Net Angle: ");
        Serial.print(netAngle);
        // Serial.print(" Green Direction: ");
        
        // avoidWhite(speed);

        // if(onGreen == true){
        //     pointNorth(robotAngle);
        //     behindBall(ballAngle, speed);
        // }
        // Serial.print(colourSensor.calculateDirection());
        // Serial.print(colourSensor.moveDir());

        // motorController.moveRobot(200, 200, -200, -200);

        Serial.println("");
    }
