#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hannahMuriel : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> speed;
    
//    ofParameter<float> param;
};
