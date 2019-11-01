
#include "manaswiKenKnowlton.h"

void manaswiKenKnowlton::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in manaswiKenKnowlton.h
    //parameters.add(param.set("param", 5, 0, 100));

	parameters.add(rectScale.set("Rectangle Scale", 25, 2, 32));
	parameters.add(units.set("Density", 20, 10, 100));

    setAuthor("Manaswi Mishra  (feat. Shia Labeouf)");
    setOriginalArtist("Ken Knowlton");

	vid.load("scenes/manaswiKenKnowlton/Shia.mp4");
	vid.play();
	vid.setVolume(0);

    loadCode("scenes/manaswiKenKnowlton/exampleCode.cpp");
	
}

void manaswiKenKnowlton::update(){
	vid.setVolume(0);
	vid.update();
}

void manaswiKenKnowlton::draw(){
	//vid.draw(0,0,dimensions.width, dimensions.height);

	for (int i = 0; i < vid.getHeight(); i+=units) {
		for (int j = 0; j < vid.getWidth(); j+=units) {
			
			ofColor col = vid.getPixels().getColor(i,j);
			int brightness = col.getBrightness();
			int w = ofMap(brightness, 0, 255, 0, rectScale);

			ofPushMatrix();
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofTranslate(i * dimensions.height / vid.getHeight() , j* dimensions.width / vid.getWidth());
			
			ofFill();
			ofSetColor(ofMap(sin(ofGetFrameNum()/50 + 20), -1, 1,0, 255), ofMap(sin((ofGetFrameNum())/50), -1, 1, 0, 255), ofMap((sin(ofGetFrameNum()/10) * 5), -1, 1, 0, 255));
			ofDrawRectangle(0, 0, w, w);

			ofNoFill();
			ofSetColor(255, 255, 255);
			ofDrawRectangle(0, 0, w, w);
			ofPopMatrix();

			//ofDrawCircle(i, j, ofMap(brightness, 0, 255, 0, 10));
		}
	}
	vid.update();
}