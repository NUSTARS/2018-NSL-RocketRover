#include "noseCone.h"

int noseConeNsleepPin,noseConePH,noseConeEN;
int closeNoseCone;
bool isClosed;
int noseDirection;
int buttonPin;

void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  Serial.begin(19200);
  noseConeNsleepPin = 22;
  noseConePH = 21;
  noseConeEN = 20;
  noseDirection = 0;
  //closeNoseCone = A3;
  buttonPin = 15;
  isClosed = false;
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  attachInterrupt(buttonPin, changeMode, LOW);

 
  digitalWrite(13, HIGH); //13 is LED Stuff
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  

}

void changeMode() {
  Serial.write("ITS WORKING\n");

  
  digitalWrite(13, HIGH);
  int counter = 0; 
  while (digitalRead(buttonPin) == LOW && counter < 5000) { //LOW is on in this case (or touching)
    delay(1);
    counter++;
  }
  if (digitalRead(buttonPin) == LOW && counter == 5000) {
    noseDirection += 2;
    noseDirection = noseDirection%3 - 1;
    Serial.println(noseDirection);
    while (digitalRead(buttonPin) == LOW) {
      digitalWrite(13, HIGH);
      delay(250);
      digitalWrite(13, LOW);
      delay(250);
    }
  }
  else {
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(1000);
  }
}

void loop()
{
  delay(500);
  if (noseDirection == 1) {
    openCone(noseConeNsleepPin,noseConePH, noseConeEN);
    Serial.println("Open");
  }
  else if (noseDirection == -1) {
    closeCone(noseConeNsleepPin,noseConePH, noseConeEN);
    Serial.println("Close");

  }
  else {
    holdCone(noseConeNsleepPin, noseConePH, noseConeEN);
    Serial.println("Hold");

  }
//    if((analogRead(closeNoseCone) > 512) && !isClosed){
//        closeCone(noseConeNsleepPin,noseConePH, noseConeEN);
//        isClosed = !isClosed;
//    }
//    if((analogRead(closeNoseCone) > 512) && isClosed){
//        openCone(noseConeNsleepPin,noseConePH, noseConeEN);
//        isClosed = !isClosed;
//    }
}
