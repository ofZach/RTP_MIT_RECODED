#pragma once

#include "ofMain.h"
#include "baseScene.h"

class gauravWhitney2 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofParameter < float > scaleV;
    
    //float scaleV = 1; // vertical scale (0.5-2.0)
    float scaleH;
    
    ofParameter < float > d;
    ofParameter < float > res;
    
    //float d = 300;   //diameter (200-500)
    //float res = 50;  //resoultion (50-150)
    float theta1 = 0;

};
