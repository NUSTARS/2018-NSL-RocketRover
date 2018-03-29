#include "payloadEject.h"


void deployRover(int nsleep,int PH, int EN){
    //Forwards
    analogWrite(nsleep, 255); 
    analogWrite(PH, 255); 
    analogWrite(EN, 159); 
}
void retractRover(int nsleep,int PH, int EN){
    //Back
    analogWrite(nsleep, 255); 
    analogWrite(PH, 0); 
    analogWrite(EN, 159); 
}

void holdRover(int nsleep, int PH, int EN) {
  //No Movement
  analogWrite(nsleep, 255);
  analogWrite(PH, 0);
  analogWrite(EN, 0);
}


