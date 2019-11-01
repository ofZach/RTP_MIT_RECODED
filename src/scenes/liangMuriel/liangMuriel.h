#pragma once

#include "ofMain.h"
#include "baseScene.h"

class liangMuriel : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    int flipper = 0;
    int time= 0;
    int speed= 0;
    // int magicNumber = 0;
    float magicNumber;
    ofParameter < int >  magicNum;
    //int k = 2;
    ofParameter < float > spd;
    ofParameter < int > colorFac;
    
    
//    ofParameter<float> param;
};
