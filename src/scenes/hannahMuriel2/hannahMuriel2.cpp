
#include "hannahMuriel2.h"

void hannahMuriel2::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in mitScene1.h
    //parameters.add(param.set("param", 5, 0, 100));

    parameters.add(red.set("red", 6, 0, 100));
    parameters.add(blue.set("blue", 4, 0, 100));
    
    setAuthor("Hannah Lienhard");
    setOriginalArtist("Muriel Cooper");

    loadCode("scenes/hannahMuriel2/exampleCode.cpp");
}

void hannahMuriel2::update(){
    
}

void hannahMuriel2::draw(){
    ofBackground(48,91,216);
    float red1 = red*0.001;
    float blue1 = blue*0.001;
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(250,30,30);
    float w = 30;
    
    ofSeedRandom(ofGetSeconds() * 1000);

    for (int j = 0; j < 8; j=j+1){
        ofSetColor(250,30,30);
        ofDrawRectangle(300, 300, 540-(j-j*red1)*59, 540-(j-j*red1)*59);
        ofSetColor(48,91,216);
        ofDrawRectangle(300, 300, 500-(j-j*blue1)*60, 500-(j-j*blue1)*60);

    }
    ofSetColor(250,30,30);
    ofDrawRectangle(300, 300, 140, 140);
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(300,300);
    ofRotate(45);
    ofDrawRectangle(0,0,150,5);
    ofRotate(-90);
    ofDrawRectangle(0,0,150,5);
    ofPopMatrix();
    
}
