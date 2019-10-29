#pragma once

#include "ofMain.h"
#include "baseScene.h"

class ethanWhitneyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    vector<ofVec2f> points;
    vector<ofColor> colors;
    
    ofParameter < float > circleSize;
    ofParameter < float > speed;
    ofParameter < float > radius;
};
