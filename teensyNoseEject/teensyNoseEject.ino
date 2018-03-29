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
  int countTime = millis();
  while (digitalRead(buttonPin) == LOW) { //LOW is on in this case (or touching)
    if (countTime > 5000) {
      if (countTime%1000 < 500) {
        digitalWrite(13, HIGH);
      }
      else {
        digitalWrite(13, LOW);
      }
    }
    else if (countTime > 7500) {
      if (noseDirection == 0) {
        openCone(noseConeNsleepPin, noseConePH, noseConeEN);
      }
      else {
        closeCone(noseConeNsleepPin, noseConePH, noseConeEN);
      }
    }
  }
 noseDirection = (noseDirection++)%2;
  if (countTime <= 5000 && countTime < 7500) {

    Serial.println(noseDirection);
    int startTime = millis();
    while (millis() - startTime < 5000) {
      openCone(noseConeNsleepPin, noseConePH, noseConeEN);
    }
    startTime = millis();
    while (millis() - startTime < 90000) {
      holdCone(noseConeNsleepPin, noseConePH, noseConeEN);
    }
    startTime = millis();
    while (millis() - startTime < 90000) {
      openCone(noseConeNsleepPin, noseConePH, noseConeEN);
    }
    
  }
  digitalWrite(13, LOW);
  holdCone(noseConeNsleepPin, noseConePH, noseConeEN);
}

void loop()
{
 
    holdCone(noseConeNsleepPin, noseConePH, noseConeEN);


  
//    if((analogRead(closeNoseCone) > 512) && !isClosed){
//        closeCone(noseConeNsleepPin,noseConePH, noseConeEN);
//        isClosed = !isClosed;
//    }
//    if((analogRead(closeNoseCone) > 512) && isClosed){
//        openCone(noseConeNsleepPin,noseConePH, noseConeEN);
//        isClosed = !isClosed;
//    }
}
