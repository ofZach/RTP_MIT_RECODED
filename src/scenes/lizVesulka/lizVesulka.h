#pragma once

#include "ofMain.h"
#include "baseScene.h"

class lizVesulka : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofBoxPrimitive box;
    ofVideoPlayer TransitMovie;
    
    ofParameter < float > rotate;
    ofParameter < float > rotate2;
    ofParameter < int > size;
    
//    ofParameter<float> param;
};
