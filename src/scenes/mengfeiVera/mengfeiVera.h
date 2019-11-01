#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mengfeiVera : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofParameter <float> color;
    ofParameter <int> seed;
    ofParameter <int> vertexnumber;
    
//    ofParameter<float> param;
};
