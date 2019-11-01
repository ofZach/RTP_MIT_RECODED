#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mengfeiWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter <float> n;
    ofParameter <float> radiusX;
    ofParameter <float> radiusY;
    ofParameter <int> number;
    
//    ofParameter<float> param;
};
