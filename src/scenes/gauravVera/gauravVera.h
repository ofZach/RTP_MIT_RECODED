#pragma once

#include "ofMain.h"
#include "baseScene.h"

class gauravVera : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<int> vr;
    ofParameter<int> hr;
    ofParameter<int> d;
    ofParameter<int> s;
    
    
//    int vr = 20;  //vertical random range (range 0-50)
//    int hr = 20;  //horizontal random range (range 0-50)
//    int d = 60;  //rect base size (range 40-120)
//    int s = 100;  //spacing between rectangles (range 50-150)
//    
    int instances = 3;
    
//    ofParameter<float> param;
};
