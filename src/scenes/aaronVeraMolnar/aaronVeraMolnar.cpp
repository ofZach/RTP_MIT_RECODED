
#include "aaronVeraMolnar.h"

int sizeX;
int sizeY;

void aaronVeraMolnar::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in aaronVeraMolnar.h
    
    parameters.add(padding.set("padding", 0.1, 0.0, 1.0));
    parameters.add(howManyRepetitions.set("howManyRepetitions", 10, 1, 20));
    parameters.add(howManyX.set("howManyX", 5, 1, 10));
    parameters.add(howManyY.set("howManyY", 5, 1, 10));
    parameters.add(rotationY.set("rotationY", 5, 1, 10));
    
    setAuthor("aaron montoya-moraga");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/aaronVeraMolnar/exampleCode.cpp");
}

void aaronVeraMolnar::update(){
    
    sizeX = dimensions.getWidth() / howManyX;
    sizeY = dimensions.getHeight() / howManyY;
    
}

void aaronVeraMolnar::draw(){
    
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofNoFill();
    
    // iterate on x,y
    for (int j = 0; j < howManyY; j++) {
        for (int i = 0; i < howManyX; i++) {
            
            // create a point p
            glm::vec3 p;
            // set x and y for center
            p.x = sizeX/2 + i*sizeX;
            p.y = sizeY/2 + j*sizeY;
            
            // iterate on repetitions
            for (int rep = 0; rep < howManyRepetitions; rep++) {
                // repetition percentage
                float repetitionFactor = float(howManyRepetitions - rep) / howManyRepetitions;
                // padding percentage
                float paddingFactor = 1.0 - padding;
                // color dependent on x,y,repetition
                ofSetColor(float(p.x/dimensions.getWidth())*(255), float(p.y/dimensions.getHeight())*(255), repetitionFactor*(255));
                
                ofPushMatrix();
                
                ofTranslate(repetitionFactor, rotationY*repetitionFactor);
                
                // draw rectangle
                ofDrawRectangle(p, sizeX * repetitionFactor * paddingFactor, sizeY * repetitionFactor * paddingFactor);
                
                ofPopMatrix();
            }
        }
    }
    
    
    ofPopStyle();
    
}
