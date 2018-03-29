#include "roverWheels.h"


void forwards(int leftA, int leftB, int rightA, int rightB, int diff) {
  if (diff >= 0) {
    analogWrite(leftA, 255);
    analogWrite(leftB, 0);
    analogWrite(rightA, max(255-diff, 0));
    analogWrite(rightB, min(255-diff, 0));
  }
  else {
    analogWrite(rightA, 255);
    analogWrite(rightB, 0);
    analogWrite(leftA, max(255+diff, 0));
    analogWrite(leftB, min(255+diff, 0));
  }
}



void backwards(int leftA, int leftB, int rightA, int rightB, int diff){ 

  if (diff >= 0) {
    analogWrite(leftA, 0);
    analogWrite(leftB, 255);
    analogWrite(rightA, min(255-diff, 0));
    analogWrite(rightB, max(255-diff, 0));
  }
  else {
    analogWrite(rightA, 0);
    analogWrite(rightB, 255);
    analogWrite(leftA, min(255+diff, 0));
    analogWrite(leftB, max(255+diff, 0));
  }
  

  
}

