#define ROVER_A1      1
#define ROVER_A2      2
#define ROVER_B1      4
#define ROVER_B2      3
#define ROVER_SLEEP   5


void setup() {
  Serial.begin(9600);
  pinMode(ROVER_A1, OUTPUT);
  pinMode(ROVER_A2, OUTPUT);
  pinMode(ROVER_B1, OUTPUT);
  pinMode(ROVER_B2, OUTPUT);
  pinMode(ROVER_SLEEP, OUTPUT);
  digitalWrite(ROVER_SLEEP, HIGH);
}

void loop() {
  analogWrite(ROVER_A1, 255);
  analogWrite(ROVER_A1, 0);
  analogWrite(ROVER_B1, 255);
  analogWrite(ROVER_B2, 0);
}
