#pragma once

#include "ofMain.h"
#include "baseScene.h"

class manaswiKenKnowlton : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;

	ofParameter<int> rectScale;
	ofParameter<int> units;

	ofVideoPlayer vid;

};