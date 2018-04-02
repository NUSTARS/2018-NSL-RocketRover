#include "WheelsTurn.cpp"
#include "DRV8838.cpp"



/*****************************************************************
  XBee_Serial_Passthrough.ino

  Set up a software serial port to pass data between an XBee Shield
  and the serial monitor.

  Hardware Hookup:
  The XBee Shield makes all of the connections you'll need
  between Arduino and XBee. If you have the shield make
  sure the SWITCH IS IN THE "DLINE" POSITION. That will connect
  the XBee's DOUT and DIN pins to Arduino pins 2 and 3.

*****************************************************************/
// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>
// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX

void setup()
{
  // Set up both ports at 19200 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(19200);
  Serial.begin(19200);
  
  //initialize/put into standby anything (motors/drivers whatever)
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);
}

void loop()
{
  if (Serial.available())
  { // If data comes in from serial monitor, send it out to XBee
    XBee.write(Serial.read());
  }

  if (XBee.available())
  { // If data comes in from XBee, send it out to serial monitor
    char c = Xbee.read();
    switch (c) {

      case 'e':   //E for eject
      case 'E':
        XBee.write('Nosecone Eject Protocol Begin');
        ejectNosecone();
        XBee.write('Rover Drive Protocol Begin');
        rover();
        break;

    }


  }
}




void ejectNosecone() {
  //turns pin A3 to low for 5 seconds
  //delay 5? seconds
  //turns pin A4 to low for 5 seconds
  //delay 5? seconds
  //turns pin A3 to low for 5 seconds
  
  digitalWrite(A3, LOW);
  delay(5000);
  digitalWrite(A3, HIGH);
  
  digitalWrite(A4, LOW);
  delay(5000);
  digitalWrite(A4, HIGH);

  digitalWrite(A3, LOW);
  delay(5000);
  digitalWrite(A3, HIGH);
}

void rover() {
  bool quit = 0;
  while (quit == 0) {

    if (Serial.available())
    { // If data comes in from serial monitor, send it out to XBee
      XBee.write(Serial.read());
    }

    if (XBee.available())
    { // If data comes in from XBee, send it out to serial monitor
      Serial.write(XBee.read());
      char x = Xbee.read();
      switch (x) {
        case 'q':   //Q for quit
        case 'Q':
          quit = 1;
          break;
      }


    }

    //ROVER CONTROL INSTRUCTIONS HERE
    //1st roll back off sled
    //next turn 90 degrees away from sled (using IMU maybe)
    
    //drive forward, avoid obstacles loop
        //set threshold for voltage of IR sensor
            //every so often poll this sensor, if below threshold, stop, go back a lil
            // turn 30 degrees (using IMU maybe) and restart loop

  }
  Xbee.write('Rover protocol quit');
}

