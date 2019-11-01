#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mengfeiKen : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofVideoGrabber grabber;
    ofTrueTypeFont font;
    ofVideoPlayer player;
    ofParameter <int> gap;
    ofParameter <int> threshold;
    
//    ofParameter<float> param;
};
