#include "payloadEject.h"

#define EJECTION_TRIGGER_TIME 5000
#define SETUP_TRIGGER_TIME 7500
#define EXTEND_TIME 75000
#define RETRACT_TIME 60000


#define PIN_SLEEP 22
#define PIN_PHASE 21
#define PIN_ENABLE 20
#define PIN_COMMS 15
#define PIN_LED 13


int noseDirection;


void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  Serial.begin(19200);

  noseDirection = 0;
 

  pinMode(PIN_COMMS, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  attachInterrupt(PIN_COMMS, changeMode, LOW);

 
  digitalWrite(PIN_LED, HIGH); //PIN_LED is LED Stuff
  delay(100);
  digitalWrite(PIN_LED, LOW);
  delay(100);
  digitalWrite(PIN_LED, HIGH);
  delay(250);
  digitalWrite(PIN_LED, LOW);
}

void changeMode() {
  Serial.write("ITS WORKING\n");

  digitalWrite(PIN_LED, HIGH);

  int countTime = millis();

  while (digitalRead(PIN_COMMS) == LOW) { //LOW is on in this case (or touching)
    if (millis() - countTime < EJECTION_TRIGGER_TIME) {
      if (countTime%1000 < 500) {
        digitalWrite(PIN_LED, HIGH);
      }
      else {
        digitalWrite(PIN_LED, LOW);
      }
    } //change to be only one direction - opposite opening direction
    if (millis()-countTime > SETUP_TRIGGER_TIME) {
      if (noseDirection == 0) {
        deployRover(PIN_SLEEP, PIN_PHASE, PIN_ENABLE);
      }
      else {
        retractRover(PIN_SLEEP, PIN_PHASE, PIN_ENABLE);
      }
    }
  }

  if ((millis() - countTime) > SETUP_TRIGGER_TIME) {
     noseDirection = (noseDirection+1)%2;
  }


  if ((millis()- countTime) >= EJECTION_TRIGGER_TIME && (millis()-countTime) < SETUP_TRIGGER_TIME) {


    int startTime = millis();
    while (millis() - startTime < EXTEND_TIME) {
      deployRover(PIN_SLEEP, PIN_PHASE, PIN_ENABLE);
    }

    startTime = millis();
    while (millis() - startTime < RETRACT_TIME) {
      retractRover(PIN_SLEEP, PIN_PHASE, PIN_ENABLE);
    }
  }


  digitalWrite(PIN_LED, LOW);
  holdRover(PIN_SLEEP, PIN_PHASE, PIN_ENABLE);
}

void loop()
{
    holdRover(PIN_SLEEP, PIN_PHASE, PIN_ENABLE);
}
