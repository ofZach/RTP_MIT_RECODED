#pragma once

#include "ofMain.h"
#include "baseScene.h"

class lizVera : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter < float > randomness;
    ofParameter < int > color;
    ofParameter < int > randomSeed;
    
//    ofParameter<float> param;
};
