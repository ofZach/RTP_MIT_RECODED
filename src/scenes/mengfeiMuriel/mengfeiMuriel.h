#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mengfeiMuriel : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofTrueTypeFont font;
    
    ofParameter <float> para;
    ofParameter <int> r;
    
//    ofParameter<float> param;
};
