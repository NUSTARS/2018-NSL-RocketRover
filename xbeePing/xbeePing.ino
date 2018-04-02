char buf[80];
int codeLength;

void setup() {
  //initialize serial ports. Serial1 handles XBee
  Serial.begin(19200);
  Serial1.begin(19200);

}

void loop() {
  //whenever Xbee recieves a Ping, send back a Pong
  String message;
  if (Serial1.available()) {
    codeLength = Serial1.readBytesUntil(0x0D, buf, 80);

    message = buf;
    message = message.substring(0, codeLength);
    Serial.println(message);
    if (message == "ping") {
      Serial1.write("pong\n");
    }
  }


}
