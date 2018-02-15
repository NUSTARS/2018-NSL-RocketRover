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
  bool isClosed = false;

}

void loop()
{
    if((analogRead(closeNoseCone) > 512) && !isClosed){
        closeCone(noseConeNsleepPin,noseConePH, noseConeEN);
    }
    if((analogRead(closeNoseCone) > 512) && isClosed){
        openCone(noseConeNsleepPin,noseConePH, noseConeEN);
    }
}