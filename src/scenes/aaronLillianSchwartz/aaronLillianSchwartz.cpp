
#include "aaronLillianSchwartz.h"

void aaronLillianSchwartz::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in aaronLillianSchwartz.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("aaron montoya-moraga");
    setOriginalArtist("Lillian F. Schwartz");

    loadCode("scenes/aaronLillianSchwartz/exampleCode.cpp");
    
    shader.load("", "scenes/aaronLillianSchwartz/shader.frag");
    
}

void aaronLillianSchwartz::update(){
    
    if (ofGetFrameNum() % 60) {
        shader.load("", "scenes/aaronLillianSchwartz/shader.frag");
    };
    
}

void aaronLillianSchwartz::draw(){
    
    ofSetColor(255);
    
    shader.begin();
    
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("mouse", 60.0, 100.0);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    shader.end();
    
}
