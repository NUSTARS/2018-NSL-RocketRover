#include "roverWheels.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
int sleepPin = 7;
int left1 = 5;
int left2 = 6;
int right1 = 9;
int right2 = 10;
int adrPin = A0;
Adafruit_BNO055 bno = Adafruit_BNO055(55);
bool gotAvg = false;
const float adjustmentAngle = 5;
const float backMovementAmount = 1000; 
const float turnMovementAmount = 1000;
const float pauseTime = 500;
float startAngle = 0;
float totalTurnAngle = 90;
float startMillis;
bool calibrated = false;
bool inRange = false;
bool atEnd = false;
#define BNO055_SAMPLERATE_DELAY_MS (100)

void setup()
{
  delay(1000);
  pinMode(adrPin, OUTPUT);
  digitalWrite(adrPin, HIGH); //if using zero
  Serial.begin(9600);
  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");
  Serial.println(BNO055_SAMPLERATE_DELAY_MS /1000.0);
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  /* Display the current temperature */
  int8_t temp = bno.getTemp();
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");

  bno.setExtCrystalUse(true);

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  digitalWrite(sleepPin, HIGH);
 delay(5000);
  
  
}
void loop()
{
 
  if (!calibrated) {
   sensors_event_t event;
   bno.getEvent(&event);
   startAngle = event.orientation.x;
   if (360-totalTurnAngle < startAngle && startAngle < 360) 
      inRange = true;
   startMillis = millis();
   calibrated = true;
   }
  
  
  else if (!atEnd){
   sensors_event_t event;
   bno.getEvent(&event);
   float angle = event.orientation.x;
   if (inRange && !(360-totalTurnAngle < angle && angle < 360)) {
      angle = angle +360;
   }
   float displacementAngle = angle - startAngle;
   Serial.println(displacementAngle);
   if (displacementAngle < totalTurnAngle  && millis()-startMillis < 300000)
    {
      //TURN by adjustmentAngle HERE
      turnCW(left1, left2, right1, right2);
      delay(turnMovementAmount);
      digitalWrite(sleepPin, LOW);
      delay(pauseTime);
      digitalWrite(sleepPin, HIGH);
      //MOVE BACK 
      backwards(left1, left2, right1, right2, 0);
      delay(backMovementAmount);
      digitalWrite(sleepPin, LOW);
      delay(pauseTime);
      digitalWrite(sleepPin, HIGH);
    }
    else {
      digitalWrite(sleepPin, HIGH);
      forwards(left1, left2, right1, right2, 0);
      atEnd = true;
      Serial.println("DONE");
    }
  }
  if (atEnd) {
    //Do Nothing
  }
  
 

  
}





