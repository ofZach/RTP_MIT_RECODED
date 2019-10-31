#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hannahSchwartz : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> speed;
    ofParameter<float> color;
    
//    ofParameter<float> param;
};
