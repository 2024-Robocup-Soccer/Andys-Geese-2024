#include "RunningMedian.h"
RunningMedian sensorValues[12] = {RunningMedian(255), RunningMedian(255), RunningMedian(255), RunningMedian(255), RunningMedian(255), RunningMedian(255), RunningMedian(255), 
    RunningMedian(255), RunningMedian(255), RunningMedian(255), RunningMedian(255), RunningMedian(255)};
int OUTPUT_PINS[12] = {A11, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10};

int sensorValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int i = 0;
int distance = 0;
int sensorAngle = 0;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.readStringUntil('\n').equals("'")) {
    for(int i = 0; i < 25; i++) {
        for(int i = 0; i < 255; i++) {
            for(int j = 0; j < 12; j++) {
                sensorValue = analogRead(OUTPUT_PINS[j]);
                sensorValues[j].add(sensorValue); 
            }
        }
        for(int i = 0; i < 12; i++) {
            Serial.print(sensorValues[i].getAverage());
            Serial.print(", ");
        }
        Serial.print(sensorAngle);
        Serial.print(", ");
        Serial.print(distance);
        Serial.println("");
        }
        
    }

    // sensorValue = pulseIn(OUTPUT_PIN, HIGH, 500);
    // Serial.println(sensorValue);


}
