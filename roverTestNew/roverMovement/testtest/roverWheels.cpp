#include "roverWheels.h"

float leftMod = .85;
void backwards(int leftB, int leftA, int rightA, int rightB, int diff) {
  if (diff >= 0) {
    analogWrite(leftA, leftMod*1*(255));
    analogWrite(leftB, leftMod*0);
    analogWrite(rightA, max(1*(255-diff), 0));
    analogWrite(rightB, min(1*(255-diff), 0));
  }
  else {
    analogWrite(rightA, 1*255);
    analogWrite(rightB, 0);
    analogWrite(leftA, leftMod*max(1*(255+diff), 0));
    analogWrite(leftB, leftMod*min(1*(255+diff), 0));
  }
}



void forwards(int leftB, int leftA, int rightA, int rightB, int diff){ 

  if (diff >= 0) {
    analogWrite(leftA, leftMod*0);
    analogWrite(leftB, leftMod*1*255);
    analogWrite(rightA, min(1*(255-diff), 0));
    analogWrite(rightB, max(1*(255-diff), 0));
  }
  else {
    analogWrite(rightA, 0);
    analogWrite(rightB, 1*(255));
    analogWrite(leftA, leftMod*min(1*(255+diff), 0));
    analogWrite(leftB, leftMod*max(1*(255+diff), 0));
  }
  

  
}

void turnCW(int leftB, int leftA, int rightA, int rightB) {
    analogWrite(leftA, leftMod*255);
    analogWrite(leftB, leftMod*0);
    analogWrite(rightA, 0);
    analogWrite(rightB, 255);
}

void turnCCW(int leftB, int leftA, int rightA, int rightB) {
    analogWrite(leftA, leftMod*0);
    analogWrite(leftB, leftMod*255);
    analogWrite(rightA, 255);
    analogWrite(rightB, 0);
}

