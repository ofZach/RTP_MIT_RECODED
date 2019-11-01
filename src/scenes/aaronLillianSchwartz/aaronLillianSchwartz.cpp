
#include "aaronLillianSchwartz.h"

void aaronLillianSchwartz::setup(){
  
    // setup parameters
    parameters.add(speedParticles.set("speedParticles", 1.5, 0.0, 3.0));
    parameters.add(speedColor.set("speedColor", 1.5, 0.0, 3.0));

    setAuthor("aaron montoya-moraga");
    setOriginalArtist("Lillian F. Schwartz");

    loadCode("scenes/aaronLillianSchwartz/exampleCode.cpp");
    
    shader.load("", "scenes/aaronLillianSchwartz/shader.frag");
    
}

void aaronLillianSchwartz::update(){
    
    // reload shader file every sixty frames
    // helpful for doing live changes on the shader file
    if (ofGetFrameNum() % 60) {
        shader.load("", "scenes/aaronLillianSchwartz/shader.frag");
    };
    
}

void aaronLillianSchwartz::draw(){
    
    ofPushStyle();
    
    ofSetColor(255);
    
    shader.begin();
    
    shader.setUniform2f("u_resolution", dimensions.getWidth(), dimensions.getHeight());
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform1f("u_speedParticles", speedParticles);
    shader.setUniform1f("u_speedColor", speedColor);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    shader.end();
    
    ofPopStyle();
    
}
