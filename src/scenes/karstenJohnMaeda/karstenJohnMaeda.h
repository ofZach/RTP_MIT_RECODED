#pragma once

#include "ofMain.h"
#include "baseScene.h"

class karstenJohnMaeda : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    
    ofTrueTypeFont fff;
    
    ofParameter < float > freq;
    ofParameter < float > amp;
    ofParameter < float > noiseFactor;
    ofParameter < float > rot;
};
