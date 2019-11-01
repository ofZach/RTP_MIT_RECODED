#pragma once

#include "ofMain.h"
#include "baseScene.h"

class karstenVeraMolnar : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    ofParameter < int > numSquares;
    ofParameter < float > rotation;
    ofParameter < float > offAmount;
    ofParameter < float > margin;
    
    int squareSize = 0;
    int windowSize = 0;
};
