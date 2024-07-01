#include <RunningMedian.h>

RunningMedian sensorValueMedian[] = { RunningMedian(100), RunningMedian(100), RunningMedian(100), RunningMedian(100),
  RunningMedian(100), RunningMedian(100), RunningMedian(100), RunningMedian(100), RunningMedian(100), RunningMedian(100),
  RunningMedian(100), RunningMedian(100) };
int TSSPs[] = { A0, A1, A2, A3, A4, A5, A6, A6, A7, A8, A9, A10, A11 };
int sensorValue;
// int highest[12];
// int lowest[12];

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() && Serial.readStringUntil('\n').equals("g")) {

    // for(int i = 0; i < 12; i++) {
    //   highest[i] = analogRead(TSSPs[i]);
    //   lowest[i] = analogRead(TSSPs[i]);
    // }

    for(int i = 0; i < 100; i++) {
      for(int j = 0; j < 12; j++) {
        sensorValue = analogRead(TSSPs[j]);
        // if(highest[i] < sensorValue) {
        //   highest[i] = sensorValue;
        // }
        // else if(lowest[i] > sensorValue) {
        //   lowest[i] = sensorValue;
        // }
        // Serial.println(sensorValue);
        sensorValueMedian[j].add(sensorValue);
      }
    }

    Serial.print(sensorValueMedian[0].getAverage());
    for(int i = 1; i < 12; i++) {
      Serial.print(" , ");
      Serial.print(sensorValueMedian[i].getAverage());
      // Serial.print("highest: ");
      // Serial.println(highest[i]);
      // Serial.print("lowest: ");
      // Serial.println(lowest[i]);
    }
    
  }

}

