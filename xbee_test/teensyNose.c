#include "noseCone.h";

int noseConeNsleepPin,noseConePH,noseConeEN;
int closeNoseCone;
void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  Serial.begin(19200);
  int noseConeNsleepPin = A0;
  int noseConePH = A1;
  int noseConeEN = A2;
  int closeNoseCone = A3;
  int IMUsensor = A4;

}

void loop()
{
    if(analogRead(closeNoseCone)){
        closeCone(noseConeNsleepPin,noseConePH, noseConeEN);
    }
    if(analogRead(IMUsensor)){
        openCone(noseConeNsleepPin,noseConePH, noseConeEN);
    }
  //If data comes in from XBee, send it out to serial monitor
  float sensorValue = analogRead(A0);
  Serial.println(sensorValue/1023*3.3);
}