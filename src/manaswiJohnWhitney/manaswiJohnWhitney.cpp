
#include "manaswiJohnWhitney.h"

void manaswiJohnWhitney::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in manaswiJohnWhitney.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Manaswi Mishra");
    setOriginalArtist("John Whitney Sr.");


	parameters.add(lineCount.set("Line count", 30, 10, 500));
	parameters.add(slow.set("Sloth-ness", 50, 10, 100));
	ofSetFrameRate(100);

	loadCode("scenes/manaswiJohnWhitney/exampleCode.cpp");
}

void manaswiJohnWhitney::update(){
    
}

void manaswiJohnWhitney::draw(){
	ofBackground(0);
	//float count = int(ofGetElapsedTimef());
	float count = ofGetFrameNum();
	float speed = slow;

	for (int i = 0; i < lineCount; i++) {

		s1 = sin((count + (3 * i)) / speed);
		s2 = cos((count + (5 * i)) / speed);
		s3 = sin(((count + i) / 2) / speed);
		s4 = cos(((count + i) * 3) / speed);

		x1 = ofMap(s1, -1, 1, dimensions.width*0.1, dimensions.width*0.9);
		y1 = ofMap(s2, -1, 1, dimensions.height*0.1, dimensions.height*0.9);
		x2 = ofMap(s3, -1, 1, dimensions.width*0.1, dimensions.width*0.9);
		y2 = ofMap(s4, -1, 1, dimensions.height*0.1, dimensions.height*0.9);

		ofSetColor(ofMap(s1,-1,1,0,255), ofMap(s2, -1,1,0,255), ofMap(s3, -1,1,0,255));
		ofNoFill();
		ofDrawLine(x1, y1, 0, x2, y2, 0);
		ofFill();
		ofDrawCircle(x1, y1, 0, 2);

	}
}