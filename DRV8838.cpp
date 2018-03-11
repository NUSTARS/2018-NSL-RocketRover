#include "DRV8838.h"
//for nosecone deployment

void drive(int phase,int enable,int nsleep){
    analogWrite(phase, 0);
    analogWrite(enable, 255);
    analogWrite(nsleep, 1);
}

void reverse(int phase,int enable,int nsleep){
    analogWrite(phase, 1);
    analogWrite(enable, 255);
    analogWrite(nsleep, 1);
}
void brake(int phase,int enable,int nsleep){
    analogWrite(phase, 0);
    analogWrite(enable, 0);
    analogWrite(nsleep, 1);
}

void coast(int phase,int enable,int nsleep){
    analogWrite(phase, 0);
    analogWrite(enable, 0);
    analogWrite(nsleep, 0);
}
