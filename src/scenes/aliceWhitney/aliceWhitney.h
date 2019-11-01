#pragma once

#include "ofMain.h"
#include "baseScene.h"

class aliceWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> xAngleParam;
     ofParameter<float> yAngleParam;
};
