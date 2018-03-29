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
  
}

void loop() {
  forwards(left1, left2, right1, right2, 0);
  delay(10000);
  backwards(left1, left2, right1, right2, 0);
  delay(10000);
  forwards(left1, left2, right1, right2, 255);
  delay(5000);
  forwards(left1, left2, right1, right2, -255);
  delay(5000);
  backwards(left1, left2, right1, right2, 255);
  delay(5000);
  backwards(left1, left2, right1, right2, -255);
  delay(5000);
  
}
