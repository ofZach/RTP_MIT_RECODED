#pragma once

#include "ofMain.h"
#include "baseScene.h"

class karstenKenKnowlton : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    ofVideoPlayer player;
    ofParameter < float > cellSize;
    ofParameter < float > threshold;
    ofParameter < float > weight;
    float scaleFactor;
};
