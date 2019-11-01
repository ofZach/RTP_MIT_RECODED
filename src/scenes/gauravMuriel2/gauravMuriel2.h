#pragma once

#include "ofMain.h"
#include "baseScene.h"

class gauravMuriel2 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofParameter < float > e;
    
    float theta = 0;

    
//    ofParameter<float> param;
};
