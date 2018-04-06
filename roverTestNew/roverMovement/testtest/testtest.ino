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

  delay(15000);

}

void loop() {
  
 forwards(left1, left2, right1, right2, 0);
 delay(3000);
 digitalWrite(sleepPin, LOW);
 delay(1000);
 digitalWrite(sleepPin, HIGH);
 backwards(left1, left2, right1, right2, 0);
 delay(3000);
 digitalWrite(sleepPin, LOW);
 delay(1000);
 digitalWrite(sleepPin, HIGH);
 turnCW(left1, left2, right1, right2);
  delay(3000);
 digitalWrite(sleepPin, LOW);
 delay(1000);
 digitalWrite(sleepPin, HIGH);
 turnCCW(left1, left2, right1, right2);
  delay(3000);
 digitalWrite(sleepPin, LOW);
 delay(1000);
 digitalWrite(sleepPin, HIGH);
  

}
