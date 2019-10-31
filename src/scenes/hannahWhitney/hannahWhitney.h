#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hannahWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> speed;
    ofParameter<float> noise;
    
//    ofParameter<float> param;
};
