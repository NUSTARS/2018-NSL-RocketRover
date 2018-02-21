#include "noseCone.h"


void openCone(int nsleep,int PH, int EN){
    //Reverse
    analogWrite(nsleep, 255); 
    analogWrite(PH, 255); 
    analogWrite(EN, 255); 
}
void closeCone(int nsleep,int PH, int EN){
    //Reverse
    analogWrite(nsleep, 255); 
    analogWrite(PH, 0); 
    analogWrite(EN, 255); 
}


