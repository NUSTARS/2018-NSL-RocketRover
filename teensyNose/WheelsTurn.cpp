#include "WheelsTurn.h"


void goStraight(int in1a,int in2a, int in1b,int in2b){
    analogWrite(in1a, 255);
    analogWrite(in1b, 0);
    analogWrite(in2a, 255);
    analogWrite(in2b, 0);
}

void turnLeft(int in1a,int in2a, int in1b,int in2b){
    analogWrite(in1a, 255);
    analogWrite(in1b, 0);
    analogWrite(in2a, 0);
    analogWrite(in2b, 255);
}

void turnRight(int in1a,int in2a, int in1b,int in2b){
    analogWrite(in1a, 0);
    analogWrite(in1b, 255);
    analogWrite(in2a, 255);
    analogWrite(in2b, 0);
}
void goBackward(int in1a,int in2a, int in1b,int in2b){
    analogWrite(in1a, 0);
    analogWrite(in1b, 255);
    analogWrite(in2a, 0);
    analogWrite(in2b, 255);
}
void doBrake(int in1a,int in2a, int in1b,int in2b){
    analogWrite(in1a, 255);
    analogWrite(in1b, 255);
    analogWrite(in2a, 255);
    analogWrite(in2b, 255);
}

void doCoast(int in1a,int in2a, int in1b,int in2b){
    analogWrite(in1a, 0);
    analogWrite(in1b, 0);
    analogWrite(in2a, 0);
    analogWrite(in2b, 0);
}
