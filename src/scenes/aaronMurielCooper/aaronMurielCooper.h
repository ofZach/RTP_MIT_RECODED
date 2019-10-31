#pragma once

#include "ofMain.h"
#include "baseScene.h"

class aaronMurielCooper : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont caslonBold10;
    ofTrueTypeFont caslonRegular10;
    ofTrueTypeFont caslonRegular06;
    
    ofParameter<int> numberRows;
    ofParameter<float> depth;
    ofParameter<float> strokeWidth;
};
