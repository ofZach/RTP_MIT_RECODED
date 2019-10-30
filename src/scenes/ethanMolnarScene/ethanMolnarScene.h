#pragma once

#include "ofMain.h"
#include "baseScene.h"

class ethanMolnarScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    deque<ofPolyline> lines;
    deque<int> lineSizes;
    
    ofParameter < float > density;
    ofParameter < float > side_length;
    ofParameter < int > random;
    ofParameter < float > inc;
    
    int x_counter;
    int y_counter;
};
