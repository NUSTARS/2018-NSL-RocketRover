
#include "pinDeclarations.h"
//#include "assemblyScript.h"

/*
#include "timings.h"
#include "ejectScript.h"

#include "roverScript.h"
*/


//=======CONSTANT DECLARATIONS=======
#define BUFF_SIZE 80



//=======VARIABLE DECLARATIONS=======

//used for XBee communications buffers
char buf[BUFF_SIZE];
int bufLength;
String message;


void setup() {
  //don't need serial, but its nice for debug
  Serial.begin(19200);

  //Serial1 is the XBee Serial
  Serial1.begin(19200);
  initializePins();



}

void loop() {
  //Lets not do anything while this is
  while (!Serial1.available()) {
  }

  readXBee();

  Serial.println(message);

  //PING command.
  if (message == "NUStars! ping") {
    Serial1.write("pong\n");
  }
  //FULL EJECT command
  else if (message == "NUStars! eject") {

    if (verifyTransmission(message)) {
      //TODO: Actually eject thingy
      Serial1.write("Ejecting\n");
      digitalWrite(NOSE_PIN, LOW);
      delay(5500);
      Serial1.write("Stage 1. Complete\n");
      digitalWrite(NOSE_PIN, HIGH);
      delay(5000);
      digitalWrite(PAY_PIN, LOW);
      delay(5500);
      digitalWrite(PAY_PIN, HIGH);

      Serial1.write("Ejection Initiated\");
      
    }

  }
  //NOSECONE UNLOCK ONLY command
  else if (message == "NUStars! manual nosecone unlock") {
    if (verifyTransmission(message)) {
      //hold it for 20 seconds?
      Serial1.write("pretend nosecone unlock only\n");
    }
  }
  //ROVER DISENGAGE ONLY command
  else if (message == "NUStars! manual rover disengage\n") {
    if (verifyTransmission(message)) {
      //yeah these dont work yet rolf
      Serial1.write("pretend rover disengages here\n");
    }
  }
  else if (message == "NUStars! manual deploy") {
    if (verifyTransmission(message)) {
      Serial1.write("pretend manual deployment happens\n");
    }
  }
  else if (message == "NUStars! GO GO GO THE LITTLE ROVER THAT COULD!") {
    if (verifyTransmission(message)) {
      Serial1.write("HAHAHAHAHAHAHAHAHAHA rip\n");
    }
  }
  else if (message == "NUStars! engage nosecone lock") {
    if (verifyTransmission(message)) {
      Serial1.write("Engaging. Send any command to stop\n");
      digitalWrite(NOSE_PIN, LOW);
      delay(7500);
      while (!Serial1.available()) {
      }
      digitalWrite(NOSE_PIN, HIGH);
      Serial1.println("Stopped");
      readXBee();
    }

  }
  else if (message == "NUStars! engage deployment") {
     if (verifyTransmission(message)) {
      Serial1.write("Engaging. Send any command to stop\n");
      digitalWrite(PAY_PIN, LOW);
      delay(7500);
      while (!Serial1.available()) {
      }
      digitalWrite(PAY_PIN, HIGH);
      Serial1.println("Stopped");
      readXBee();
    }

  }
  else {
    Serial1.write("err: invalid command\n");
  }

}

//========HELPER FUNCTIONS=======

void initializePins() {
    pinMode(NOSE_PIN, OUTPUT);
    pinMode(PAY_PIN, OUTPUT);
    pinMode(RNGFNDR, INPUT);
    pinMode(ROVER_SLP, OUTPUT);
    pinMode(LEFT_1, OUTPUT);
    pinMode(LEFT_2, OUTPUT);
    pinMode(RIGHT_1, OUTPUT);
    pinMode(RIGHT_2, OUTPUT);

    digitalWrite(PAY_PIN, HIGH);
    digitalWrite(NOSE_PIN, HIGH);
}

void readXBee() {
  //0x0D happens to be the XCTU return carriage value. Read up to that.
  bufLength = Serial1.readBytesUntil(0x0D, buf, 80);

  //get the message into a string cause it so much less painful
  message = buf;
  message = message.substring(0, bufLength);

}

bool verifyTransmission(String str) {
  String out = "Command " + str + " received.\nVerify within 10 sec.\n";
  Serial1.print(out);
  int timer = millis();
  while (!Serial1.available() && millis() - timer <= 10000) {
  }
  if (Serial1.available()) {
    readXBee();
  }
  else {
    Serial1.write("No Verification Received\n");
    Serial.write("err: verification\n");
    return false;
  }

  if (message == str) {
    Serial1.write("Verified\n");
    Serial.write("verified\n");
    return true;
  }
  Serial1.write("Verification Error\n");
  Serial.write("err: verification\n");
  return false;
}



