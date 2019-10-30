
#include "aaronVeraMolnar.h"

int sizeX;
int sizeY;

void aaronVeraMolnar::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in aaronVeraMolnar.h
    
    parameters.add(padding.set("padding", 0.1, 0.0, 1.0));
    parameters.add(howManyInside.set("howManyInside", 10, 1, 20));
    parameters.add(howManyXY.set("howManyXY", 5, 1, 5));
    parameters.add(rotation.set("rotation", 0, -10, 10));
    
    setAuthor("aaron montoya-moraga");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/aaronVeraMolnar/exampleCode.cpp");
}

void aaronVeraMolnar::update(){
    
    sizeX = dimensions.getWidth() / howManyXY;
    sizeY = dimensions.getHeight() / howManyXY;
    
}

void aaronVeraMolnar::draw(){
    
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofNoFill();
    
    // iterate on x,y
    for (int j = 0; j < howManyXY; j++) {
        for (int i = 0; i < howManyXY; i++) {
            
            // create a point p
            glm::vec3 p;
            // set x and y for center
            p.x = sizeX/2 + i*sizeX;
            p.y = sizeY/2 + j*sizeY;
            
            ofPushMatrix();
            
            // iterate on repetitions
            for (int rep = 0; rep < howManyInside; rep++) {
                
                // repetition percentage
                float repetitionFactor = float(howManyInside - rep) / howManyInside;
                
                // padding percentage
                float paddingFactor = 1.0 - padding;
                
                // color dependent on x,y,repetition
                ofSetColor(float(p.x/dimensions.getWidth())*(255), float(p.y/dimensions.getHeight())*(255), repetitionFactor*(255));
                
                ofRotateDeg(rotation);
                
                // draw rectangle
                ofDrawRectangle(p, sizeX * repetitionFactor * paddingFactor, sizeY * repetitionFactor * paddingFactor);
                
            }
            
            ofPopMatrix();
        }
    }
    
    ofPopStyle();

}
