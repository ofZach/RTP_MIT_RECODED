#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hannahVera : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> noise;
    ofParameter<float> space;
    
//    ofParameter<float> param;
};
