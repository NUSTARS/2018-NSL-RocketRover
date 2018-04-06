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
Adafruit_BNO055 bno = Adafruit_BNO055();
bool gotAvg = false;
bool calibrated = false;
const float adjustmentAngle = 5;
const float backMovementAmount = 1000; 
const float turnMovementAmount = 1000;
const float pauseTime = 500;
float startAngle = 0;
float totalTurnAngle = 90;
float startMillis;
void setup()
{
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
  pinMode(adrPin, OUTPUT);
  digitalWrite(adrPin, HIGH); //if using zero
  digitalWrite(sleepPin, HIGH);
  
}
void loop()
{
 uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  if (!calibrated && (gyro != 3 || accel != 3 || mag != 3))  {
    Serial.print("calibrating:");
    if (gyro !=3)
      Serial.print("G");
    if (accel !=3)
      Serial.print("A");
    if (mag != 3)
     Serial.print("M");
   Serial.println(" ");

  }
  else if (!calibrated) {
    calibrated = true;
    Serial.println("SET DOWN!");
    delay(5000);
   sensors_event_t event;
   bno.getEvent(&event);
   startAngle = event.orientation.y;
   startMillis = millis();
  }
  
  
  if (calibrated) {
   sensors_event_t event;
   bno.getEvent(&event);
   angle = event.orientation.y; 
   displacementAngle = angle - startAngle;
   if (displacementAngle < totalTurnAngle && millis()-startMillis < 300000)
    {
      //TURN by adjustmentAngle HERE
      turnRight(left, left2, right1, right2);
      delay(turnMovementAmount);
      digitalWrite(sleepPin, HIGH);
      delay(pauseTime);
      //MOVE BACK 
      backwards(left1, left2, right1, right2, 0);
      delay(backMovementAmount);
      digitalWrite(sleepPin, HIGH);
      delay(pauseTime);
    }
    else {
      forward(left1, left2, right1, right2);
    }
  }
 

  
}





