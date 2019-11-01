
#include "hannahSchwartz.h"

void hannahSchwartz::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in mitScene1.h
    //parameters.add(param.set("param", 5, 0, 100));

    parameters.add(speed.set("speed", 200, -600, 600));
    parameters.add(color.set("color", 10, 0, 100));
    
    setAuthor("Hannah Lienhard");
    setOriginalArtist("Lillian Schwartz");

    loadCode("scenes/hannahSchwartz/exampleCode.cpp");
}

void hannahSchwartz::update(){
    
}

void hannahSchwartz::draw(){
    ofBackground(0);
    int frameCount = ofGetElapsedTimef()*10;
    float time = ofGetElapsedTimef();
    
    if (color < 10){
        ofBackground(6,28,209,150);
    }
    if (color > 20 && color < 40){
        ofBackground(193,155,232);
    }
    if (color > 40 && color < 60){
        ofBackground(115,168,219);
    }
    if (color > 60 && color < 80){
        ofBackground(255);
    }
    if (color > 80 && color < 100){
        ofBackground(193,155,232);
    }
    ofPushMatrix();
    ofTranslate(350,350);
    ofRotate(speed*time);
    if (frameCount%5 ==0 | frameCount%3 ==0 | (frameCount > 50 && frameCount < 150) ){
        ofSetColor(234,229,178,200);
        if ((frameCount > 150 && frameCount < 200)){
            ofSetColor(0);
        }
    }
    
    else {
        ofSetColor(6, 28, 209, 2000);
    }
    ofSetCircleResolution(100);
    ofDrawEllipse(0,100,240,200);
    ofDrawEllipse(0,100,300,200);
    if (frameCount%7 ==0 | frameCount%5 ==0){
        ofSetColor(6,28,209,150);
    }
    else {
        ofSetColor(209,16,6,200);
    }
    ofRotate(-2*speed*time);
    ofDrawEllipse(0,-100,240,200);
    ofDrawEllipse(0,-100,300,200);
    ofPopMatrix();
}
