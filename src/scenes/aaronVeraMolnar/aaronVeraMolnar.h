#pragma once

#include "ofMain.h"
#include "baseScene.h"

class aaronVeraMolnar : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    ofParameter<float> padding;
    ofParameter<int> howManyInside;
    ofParameter<int> howManyXY;
    ofParameter<float> rotation;
};
