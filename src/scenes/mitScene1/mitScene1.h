#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mitScene1 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> radius;
    
//    ofParameter<float> param;
};
