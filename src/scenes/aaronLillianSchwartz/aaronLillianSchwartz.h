#pragma once

#include "ofMain.h"
#include "baseScene.h"

class aaronLillianSchwartz : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> speedParticles;
    ofParameter<float> speedColor;
    
    ofShader shader;
    
};
