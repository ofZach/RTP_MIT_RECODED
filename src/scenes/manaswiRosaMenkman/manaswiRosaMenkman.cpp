
#include "manaswiRosaMenkman.h"

void manaswiRosaMenkman::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in manaswiRosaMenkman.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Manaswi Mishra (picture of Muriel Cooper and unidentified males at MIT, 1970s)");
    setOriginalArtist("Inspired by Rosa Menkman");

	parameters.add(skipLocation.set("Skip Location", 50, 10, dimensions.width));
	parameters.add(skipAmount.set("Skip Amount", 50, 10, dimensions.height));
	parameters.add(glitchSpeed.set("Glitch Speed", 5, 1, 20));

	back.loadImage("scenes/manaswiRosaMenkman/cooperBack.jpg");
	back.setImageType(OF_IMAGE_COLOR);

	front.loadImage("scenes/manaswiRosaMenkman/cooper.jpg");
	front.setImageType(OF_IMAGE_COLOR);

	w = front.getWidth();
	h = front.getHeight();

	myFont.loadFont("fonts/AlrightSans-Bold.otf", 18);

    loadCode("scenes/manaswiRosaMenkman/exampleCode.cpp");
}

void manaswiRosaMenkman::update(){

	ofBuffer buffer;
	ofSaveImage(back.getPixels(), buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);

	ofSeedRandom(0);
	float s = ofMap(sin(ofGetElapsedTimef()/100*glitchSpeed), -1, 1, 0, 1);
	int whereToSkip = ofMap(skipLocation * s, 0, dimensions.width, 0, buffer.size(), true);
	int left = buffer.size() - whereToSkip;
	int howMuchToSkip = ofMap(skipAmount, 0, dimensions.height, 0, left*0.5, true);
	ofBuffer buffer2;

	for (int i = 0; i < buffer.size(); i++) {
		if (i < whereToSkip ||
			i >(whereToSkip + howMuchToSkip)) {
			buffer2.append(buffer.getData() + i, 1);
		}
		else {
			char * data = new char[1];
			data[0] = ofRandom(0, 255);
			buffer2.append(data, 1);
			delete data;

		}
	}

	newBack.load(buffer2);

	
	if (ofGetFrameNum() % 100 > 50) {
		front.resize(front.getWidth() + ofRandom(-200, 200), front.getHeight() + ofRandom(-200, 200));
		front.resize(front.getWidth() + ofRandom(-200, 200), front.getHeight() + ofRandom(-200, 200));
		front.save("glitched.jpg", OF_IMAGE_QUALITY_BEST);
		front.load("glitched.jpg");
		front.resize(w, h);
	}



	if (ofGetFrameNum() % 100 == 0) {
		back.load("scenes/manaswiRosaMenkman/cooperBack.jpg");
		back.setImageType(OF_IMAGE_COLOR);

		front.load("scenes/manaswiRosaMenkman/cooper.jpg");
		front.setImageType(OF_IMAGE_COLOR);

	}
    
}

void manaswiRosaMenkman::draw(){
	ofSetColor(255, 255, 255, 255);
	newBack.draw(0, 0, dimensions.width, dimensions.height);
	ofSetColor(255, 255, 255, 150);
	front.draw(0, 0, dimensions.width, dimensions.height);
	
	ofSetColor(0, 0, 0, 255);
	myFont.drawString("Muriel Cooper and unidentified males \nat MIT, 1970s", dimensions.width / 5, dimensions.height / 8);

}

void manaswiRosaMenkman::keyPressed(int key) {

	back.load("scenes/manaswiRosaMenkman/cooperBack.jpg");
	back.setImageType(OF_IMAGE_COLOR);

}