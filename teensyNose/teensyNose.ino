#include "noseCone.h"

int noseConeNsleepPin,noseConePH,noseConeEN;
int closeNoseCone;
bool isClosed;
void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  Serial.begin(19200);
  noseConeNsleepPin = 22;
  noseConePH = 21;
  noseConeEN = 20;
  //closeNoseCone = A3;
  isClosed = false;

}

void loop()
{
  openCone(noseConeNsleepPin,noseConePH, noseConeEN);
  delay(5000);
  closeCone(noseConeNsleepPin,noseConePH, noseConeEN);
  delay(5000);
//    if((analogRead(closeNoseCone) > 512) && !isClosed){
//        closeCone(noseConeNsleepPin,noseConePH, noseConeEN);
//        isClosed = !isClosed;
//    }
//    if((analogRead(closeNoseCone) > 512) && isClosed){
//        openCone(noseConeNsleepPin,noseConePH, noseConeEN);
//        isClosed = !isClosed;
//    }
}
