#pragma once

#include "ofMain.h"
#include "baseScene.h"

class karstenJohnWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    ofParameter < float > jStretch;
    ofParameter < float > xScale;
    ofParameter < float > yScale;
    
    float a = 0.0;
    float bgAlpha = 50;
    float xOrig = 0;
    float yOrig = 0;
    float lissRad = 250;
    float time = 0.0;
    int num = 5;
    
    ofColor pink;
};
