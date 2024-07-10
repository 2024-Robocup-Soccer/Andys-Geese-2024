#include <Wire.h>


void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = pulseIn(10, HIGH, 1000);
  if (val>0){
    Serial.println(val);
  }
}
