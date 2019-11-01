#pragma once

#include "ofMain.h"
#include "baseScene.h"

class manaswiJohnWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<int> lineCount;
	ofParameter<float> slow;

	int x1, x2, y1, y2;
	float s1, s2, s3, s4;
};