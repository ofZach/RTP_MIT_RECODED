#pragma once

#include "ofMain.h"
#include "baseScene.h"

class aaronRosaMenkman : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> sweepSpeed;
    ofParameter<int> glitchFlavor;
    
    ofImage original;
    ofImage newImage;
};
