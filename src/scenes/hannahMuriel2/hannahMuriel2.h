#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hannahMuriel2 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> red;
    ofParameter<float> blue;
//    ofParameter<float> param;
};
