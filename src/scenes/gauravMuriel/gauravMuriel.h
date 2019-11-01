#pragma once

#include "ofMain.h"
#include "baseScene.h"

class gauravMuriel : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    
    
    int w = 20;
    int h = 100;
    //    float scaleB = 1.2;   // range 0.5-1.3
    //    float scaleS = 0.3;   // range 0.2-0.8
    ofParameter < float > scaleB;
    ofParameter < float > scaleS;
    
    float theta = 0;
    
};
