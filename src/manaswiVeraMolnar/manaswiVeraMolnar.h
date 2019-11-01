#pragma once

#include "ofMain.h"
#include "baseScene.h"

class manaswiVeraMolnar : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

	void computeVertices();
    
//    ofParameter<float> param;

	ofParameter<int> variance;
	ofParameter<float> speed; 
	ofParameter<int> space;
	ofParameter<float> spaghetti;

	ofVec2f vertexArray[6][6][32];
	int colorArray[6][6];
	int colorID[7] = { 0xA81703,0x769EE6,0x3B6728,0xAC9600,0x7265BD,0x8A55A5,0xAEBCC9};
	int gridSize = 6;

	int startX, finishX, startY;
	int sideLength;
	int offSet = 50;
};