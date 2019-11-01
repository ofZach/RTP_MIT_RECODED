#pragma once

#include "ofMain.h"
#include "baseScene.h"

class manaswiRosaMenkman : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
	void keyPressed(int);
    
//    ofParameter<float> param;
	ofParameter<int> skipLocation;
	ofParameter<int> skipAmount;
	ofParameter<float> glitchSpeed;

	ofImage back, front, newBack;
	int w, h;
	ofTrueTypeFont myFont;
};