#pragma once

#include "ofMain.h"
#include "baseScene.h"

class liangVasulka : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    
    int flipper = 0;
    int time= 0;
    int speed= 0;
    int magicNumber = 0;
    ofParameter < int> magicNum;
    ofParameter < int> spd;
    
//    ofParameter<float> param;
};
