#include "roverWheels.h"


void forwards(int leftA, int leftB, int rightA, int rightB, int diff) {
  if (diff >= 0) {
    analogWrite(leftA, 0.5*(255));
    analogWrite(leftB, 0);
    analogWrite(rightA, max(0.5*(255-diff), 0));
    analogWrite(rightB, min(0.5*(255-diff), 0));
  }
  else {
    analogWrite(rightA, 0.5*255);
    analogWrite(rightB, 0);
    analogWrite(leftA, max(0.5*(255+diff), 0));
    analogWrite(leftB, min(0.5*(255+diff), 0));
  }
}



void backwards(int leftA, int leftB, int rightA, int rightB, int diff){ 

  if (diff >= 0) {
    analogWrite(leftA, 0);
    analogWrite(leftB, 0.5*255);
    analogWrite(rightA, min(0.5*(255-diff), 0));
    analogWrite(rightB, max(0.5*(255-diff), 0));
  }
  else {
    analogWrite(rightA, 0);
    analogWrite(rightB, 0.5*(255));
    analogWrite(leftA, min(0.5*(255+diff), 0));
    analogWrite(leftB, max(0.5*(255+diff), 0));
  }
  

  
}

