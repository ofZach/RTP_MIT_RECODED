#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mengfeiLillian : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter <int> r;
    ofParameter <int> gap;
    ofParameter <int> noise1;
    ofParameter <int> noise2;
    
//    ofParameter<float> param;
};
