#include "roverWheels.h"
int sleepPin = 7;
int left1 = 5;
int left2 = 6;
int right1 = 9;
int right2 = 10;

void setup() {
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  digitalWrite(sleepPin, HIGH);
  delay(30000);
  
}

void loop() {
  analogWrite(left1, 255);
  analogWrite(left2, 0);
  analogWrite(right1, 255);
  analogWrite(right2, 0);
}
